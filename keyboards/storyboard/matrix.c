// Copyright 2023 Chris Babroski (@cbskii)
// SPDX-License-Identifier: GPL-2.0-or-later

#include "matrix.h"
#include "gpio.h"
#include "wait.h"
#include "action.h"
#include "config.h"
#include "EPD_3in7.h"
#include "GUI_Paint.h"
#include "storyboard_image.h"

#ifdef CONSOLE_ENABLE
#include "printf.h"
#endif

// FIXME: temporary display function using waveshare SDKs. Add
// quantum painter support with new display driver.
void display_init(void)
{
    if (DEV_Module_Init() != 0) {
        return;
    }

    EPD_3IN7_4Gray_Init();
    EPD_3IN7_4Gray_Clear();
    Paint_Clear(BLACK);

    Paint_NewImage(storyboard_image,
                   EPD_3IN7_WIDTH, EPD_3IN7_HEIGHT, 90, BLACK);
    Paint_SetScale(4);
    Paint_SelectImage(storyboard_image);
    EPD_3IN7_4Gray_Display(storyboard_image);

    EPD_3IN7_Sleep();
    DEV_Delay_ms(2000);
    DEV_Module_Exit();
}

void matrix_init_custom(void) {
    if (sizeof(matrix_row_t) != sizeof(uint16_t)) {
        return;
    }

    // FIXME: ideally display is only reinitialized when flashing new FW.
    // Display is currently cleared and reset on every boot because datasheet
    // recommends frequent clears.
    display_init();
    setPinOutput(NMATRIX_LD);
    setPinOutput(MATRIX_CLK);
    setPinOutput(MATRIX_SI);
    setPinInput(MATRIX_SO);
    wait_ms(INIT_DELAY_MS);
}

// Sets a given row index low and the others high
static void set_row_low(uint8_t row)
{
    uint8_t i = 0;

    if (row >= MATRIX_ROWS) {
        return;
    }

    // Shift values in starting from highest row number
    writePin(NMATRIX_LD, 1);
    for (i = NUM_ROW_BITS; i > 0; i--) {
        if (row == i - 1) {
            writePin(MATRIX_SI, 0);
        } else {
            writePin(MATRIX_SI, 1);
        }
        writePin(MATRIX_CLK, 0);
        writePin(MATRIX_CLK, 1);
    }

    // Load and store parallel column inputs
    writePin(NMATRIX_LD, 0);
    wait_ms(LD_DELAY_MS);
}

// Returns an unsigned integer where each bit is the state of a single column
static matrix_row_t get_col_vals(void)
{
    uint8_t val = 0;
    uint8_t col = 0;
    uint16_t valid_cols_mask = (1 << MATRIX_COLS) - 1;
    matrix_row_t col_vals = 0;

    // Clock values out starting from highest column number
    writePin(NMATRIX_LD, 1);
    for (col = NUM_COL_BITS; col > 0; col--) {
        writePin(MATRIX_CLK, 0);
        writePin(MATRIX_CLK, 1);

        // Columns are active low, but vals need to be set high when active
        val = readPin(MATRIX_SO);
        if (val) {
            col_vals &= (~(0x1 << (col - 1))) & 0xFFFF;
        } else {
            col_vals |= (0x1 << (col - 1));
        }
    }

    return col_vals & valid_cols_mask;
}

bool matrix_scan_custom(matrix_row_t current_matrix[MATRIX_ROWS]) {
    uint8_t row = 0;
    matrix_row_t col_vals = 0;
    bool matrix_has_changed = false;

    for (row = 0; row < MATRIX_ROWS; row++) {
        set_row_low(row);
        col_vals = get_col_vals();
        if (current_matrix[row] != col_vals) {
            current_matrix[row] = col_vals;
#ifdef CONSOLE_ENABLE
            printf("key press - row %d, cols: 0x%X)\n", row, col_vals);
#else
            matrix_has_changed = true;
#endif
        }
    }

    return matrix_has_changed;
}

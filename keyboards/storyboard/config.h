// Copyright 2023 Chris Babroski (@cbskii)
// SPDX-License-Identifier: GPL-2.0-or-later

#pragma once

// Board specific defines
#define NUM_ROW_BITS        (8)
#define NUM_COL_BITS        (16)
#define INIT_DELAY_MS       (5)
#define LD_DELAY_MS         (2)
#define NMATRIX_LD          (9)
#define MATRIX_CLK          (14)
#define MATRIX_SI           (15)
#define MATRIX_SO           (12)
#define NKEY_INT            (17)
#define DISPLAY_CS          (21)
#define DISPLAY_RST         (7)
#define DISPLAY_DC          (6)
#define DISPLAY_BUSY        (16)
#define DISPLAY_WIDTH       (240)
#define DISPLAY_HEIGHT      (360)
#define DISPLAY_SPI_DIV     (8)
#define DISPLAY_SPI_MODE    (0)

// SPI configuration
#define SPI_DRIVER SPID0
#define SPI_SCK_PIN GP22
#define SPI_MOSI_PIN GP23
#define SPI_MISO_PIN GP20
#define SPI_EPD_CS_PIN GP21
#define SPI_MATRIX_DIVISOR 16

// General QMK features
#define TAPPING_TOGGLE 2
#define DOUBLE_TAP_SHIFT_TURNS_ON_CAPS_WORD

// Enable RP2040 double tap reset bootloader entry
#define RP2040_BOOTLOADER_DOUBLE_TAP_RESET
#define RP2040_BOOTLOADER_DOUBLE_TAP_RESET_TIMEOUT 1000U

// Quantum painter config
#define QUANTUM_PAINTER_DISPLAY_TIMEOUT (0)
#define QUANTUM_PAINTER_NUM_IMAGES      (1)

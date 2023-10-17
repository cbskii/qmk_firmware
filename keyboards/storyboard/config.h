// Copyright 2023 Chris Babroski (@cbskii)
// SPDX-License-Identifier: GPL-2.0-or-later

#pragma once

/* Board specific defines */
#define NUM_ROW_BITS    (8)
#define NUM_COL_BITS    (16)
#define INIT_DELAY_MS   (5)
#define LD_DELAY_MS     (2)
#define NMATRIX_LD      (9)
#define MATRIX_CLK      (14)
#define MATRIX_SI       (15)
#define MATRIX_SO       (12)
#define NKEY_INT        (17)

/* Firmware Config */
#define TAPPING_TOGGLE 2
#define RP2040_BOOTLOADER_DOUBLE_TAP_RESET
#define RP2040_BOOTLOADER_DOUBLE_TAP_RESET_TIMEOUT 1000U

// Copyright 2023 Chris Babroski (@cbskii)
// SPDX-License-Identifier: GPL-3.0-or-later

#pragma once

#include_next <mcuconf.h>

#undef RP_SPI_USE_SPI0
#define RP_SPI_USE_SPI0 TRUE

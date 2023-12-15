/*****************************************************************************
* | File      	:   DEV_Config.c
* | Author      :   Waveshare team
* | Function    :   Hardware underlying interface
* | Info        :
*----------------
* |	This version:   V3.0
* | Date        :   2019-07-31
* | Info        :
#
# Permission is hereby granted, free of charge, to any person obtaining a copy
# of this software and associated documnetation files (the "Software"), to deal
# in the Software without restriction, including without limitation the rights
# to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
# copies of theex Software, and to permit persons to  whom the Software is
# furished to do so, subject to the following conditions:
#
# The above copyright notice and this permission notice shall be included in
# all copies or substantial portions of the Software.
#
# THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
# IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
# FITNESS OR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
# AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
# LIABILITY WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
# OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
# THE SOFTWARE.
#
******************************************************************************/
#include "DEV_Config.h"
#include "config.h"
#include "spi_master.h"
#include "gpio.h"
#include "wait.h"

int EPD_RST_PIN;
int EPD_DC_PIN;
int EPD_BUSY_PIN;
int EPD_PWR_PIN;

void DEV_Digital_Write(UWORD Pin, UBYTE Value)
{
    writePin(Pin, Value);
}

UBYTE DEV_Digital_Read(UWORD Pin)
{
    UBYTE Read_value = readPin(Pin);
    return Read_value;
}

void DEV_SPI_WriteByte(uint8_t Value)
{
    spi_start(SPI_EPD_CS_PIN, false, 0, SPI_MATRIX_DIVISOR);
    spi_write(Value);
    spi_stop();
}

void DEV_SPI_Write_nByte(uint8_t *pData, uint32_t Len)
{
    spi_start(SPI_EPD_CS_PIN, false, 0, SPI_MATRIX_DIVISOR);
    spi_transmit(pData, Len);
    spi_stop();
}

void DEV_GPIO_Mode(UWORD Pin, UWORD Mode)
{
    if (Mode == 0) {
        setPinInput(Pin);
    } else {
        setPinOutput(Pin);
    }
}

void DEV_Delay_ms(UDOUBLE xms)
{
    wait_ms(xms);
}

void DEV_GPIO_Init(void)
{
    EPD_RST_PIN = 7;
    EPD_DC_PIN = 6;
    EPD_BUSY_PIN = 16;

    DEV_GPIO_Mode(EPD_RST_PIN, 1);
    DEV_GPIO_Mode(EPD_DC_PIN, 1);
    DEV_GPIO_Mode(SPI_EPD_CS_PIN, 1);
    DEV_GPIO_Mode(EPD_BUSY_PIN, 0);

    DEV_Digital_Write(SPI_EPD_CS_PIN, 1);
}

UBYTE DEV_Module_Init(void)
{
    DEV_GPIO_Init();
    spi_init();
    return 0;
}

void DEV_Module_Exit(void)
{
    DEV_Digital_Write(SPI_EPD_CS_PIN, 0);
    DEV_Digital_Write(EPD_PWR_PIN, 0);
    DEV_Digital_Write(EPD_DC_PIN, 0);
    DEV_Digital_Write(EPD_RST_PIN, 0);
}

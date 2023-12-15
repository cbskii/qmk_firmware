BOOTLOADER = rp2040
CUSTOM_MATRIX = lite
CAPS_WORD_ENABLE = yes

QUANTUM_LIB_SRC += spi_master.c

SRC += matrix.c
SRC += DEV_Config.c
SRC += EPD_3in7.c
SRC += GUI_Paint.c

# Uncomment to enable debug logging and disable key presses
# CONSOLE_ENABLE = yes

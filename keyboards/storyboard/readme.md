# storyboard

![storyboard](imgur.com image replace me!)

The "Storyboard" is a 5x12 ortholinear keyboard with an E-INK display in the middle. More
information can be found on [Github](https://github.com/cbskii/storyboard-keyboard).

* Keyboard Maintainer: [Chris Babroski](https://github.com/cbskii)
* Hardware Supported: Storyboard Rev1.0 with MicroMod RP2040
* Hardware Availability: [Open source DIY](https://github.com/cbskii/storyboard-keyboard)

Build example for this keyboard (after setting up your build environment):
```
qmk compile -kb storyboard -km default
```

Flash example for this keyboard (once keyboard is in bootloader):
```
qmk flash --keyboard storyboard --keymap default
```

See the [build environment setup](https://docs.qmk.fm/#/getting_started_build_tools) and the [make instructions](https://docs.qmk.fm/#/getting_started_make_guide) for more information. Brand new to QMK? Start with our [Complete Newbs Guide](https://docs.qmk.fm/#/newbs).

## Bootloader

Methods for entering the bootloader:
* **Hold boot button**. Hold the BOOT button (right push button under display on top of PCB) while plugging in the keyboard to power.
* **Physical boot and reset button**. Press and hold the right push button (BOOT) underneath the display on the front of the PCB. Then at the same time press the push button directly to the left (RESET) once if the keyboard is already plugged into power.
* **Reset button double tap**. If the QMK firmware has already been installed once you can double
  tap the reset button (left push button on top of PCB under display) to enter the bootloader.

## Set Display Image
TODO

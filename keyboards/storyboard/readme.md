# storyboard

The "Storyboard" is a 5x12 ortholinear keyboard with an E-INK display in the middle. More
information can be found on [Github](https://github.com/cbskii/storyboard-keyboard).

* Keyboard Maintainer: [Chris Babroski](https://github.com/cbskii)
* Hardware Supported: Storyboard Rev1.0 with RP2040 MicroMod processor board
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
* **Use bootloader key combo**. By default there is a keymap enabled to put the device into bootloader mode. Check the keymap for more information.
* **Hold boot button**. Hold the BOOT button (right push button under display on top of PCB) while plugging in the keyboard to power.
* **Physical boot and reset button**. Press and hold the right push button (BOOT) underneath the display on the front of the PCB. Then at the same time press the push button directly to the left (RESET) once if the keyboard is already plugged into power.
* **Reset button double tap**. If the QMK firmware has already been installed once you can double tap the reset button (left push button on top of PCB under display) to enter the bootloader.

Note that the physical push buttons can be pressed if the display is removed or if some of the keycaps and switches to the left of the display are removed.

## Set Display Image

Only one image can currently be displayed and this image must be created before buliding the firmware. An image is converted into a C file that gets built into the Storyboard firmware and displayed on boot. Because this display is an E-Ink/e-Paper display the image will persist even when the keyboard is unplugged from power.

NOTE: Quantum painter support has not been added yet. For now generating an image header requires
third party tools and the code uses Waveshare SDKs directly (which can also be found on
their website for each display).

TODO: currently using Waveshare Image2LCD application from their website to create image, but working on adding reproducible steps using ImageMagick.

Image2Lcd instructions:
1. Preprocess image in software like Photoshop or Gimp if needed (scaling, dithering, cropping, etc.)
2. Select C array output
3. Select Vertical Scan mode
4. Select 4 color BitsPixel
5. Set dimensions to 480 width x 280 height
6. Make sure include header data is NOT checked
7. Reverse color (also may need to mirror/rotate image)
6. Edit generated image file:
   a. remove const declaration from array
   b. rename array to storyboard_image
   c. rename the file to storyboard_image.h in keyboards/storyboard/ QMK directory

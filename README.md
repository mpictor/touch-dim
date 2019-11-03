## touch-dim

A simple app using the capacitive touch library to turn a reading light on and off, and to adjust its brightness via pwm.

Short presses turn the light on and off, while long presses adjust the on brightness. Brightness is remembered over on/off cycles but not when the unit loses power.

### hardware

The hardware is a digispark, a tiny board in the arduino ecosystem which uses an ATTINY85, plugs directly into USB-A ports, and emulates USB protocols in software. Specifically, I used a Model B (only shipped to kickstarter supporters), which has an onboard LED connected to Pin 0. The code will still work fine on a Model A, the only difference being that the onboard LED won't light unless you change to pin 1.

#### porting

Nothing in the code should be specific to the digispark, other than pin numbers. Obviously, the digispark makefile will _not_ work with other boards - you'll want to change that dependency or just use the arduino ide. If you encounter trouble, verify that the cap sensing lib can work on your hardware and on the chosen pin, and that the output pin you chose supports pwm.

### qt creator

You may notice a .pro file in the repo. I used it as editor, and this file was to keep it (and its linters) happy. I do not use it to build/upload; that sounds possible but I didn't get around to making it work. Note that if you build from qt creator, it will create a Makefile in the repo root that would compile for your native arch, likely x86. This is not to be confused with the Makefile in src/, which is used to build for ATTINY85 and to upload.

## building

Uses the "arduino makefile for digispark", https://github.com/agusibrahim/Arduino-mk-Digispark . Known to work with rev 8876084013f1c.

You will need to have the appropriate toolchain installed; see instructions on its wiki. It might be possible to install/use that toolchain without the arduino ide installed, but I have not tried.

Once you have Arduino-mk-Digispark and the toolchain installed, edit src/Makefile to update paths as necessary. Then,

`cd src; make`

### yay

If all goes well, proceed to uploading.

### nay

If you encounter errors, first make sure things work with the arduino ide. If things don't work there, read through digistump's troubleshooting docs.

If the ide works, read through the voluminous docs in the Arduino-mk-Digispark Makefile.

## upload

As with the arduino ide, the upload process must intercept the digispark's boot process. Run the following with the board unplugged, then follow onscreen prompts to plug it in:

`cd src; make upload`

## I want to use the arduino ide

If you wish to use the arduino ide, rename main.cpp to something with a .ino extension. You might get away with creating a symlink instead of renaming, but no guarantees.

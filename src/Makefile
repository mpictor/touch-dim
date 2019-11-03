# Arduino Make file. Refer to https://github.com/sudar/Arduino-Makefile

ALTERNATE_CORE_PATH = /home/mark/.arduino15/packages/digistump/hardware/avr/1.6.7
ARDUINO_CORE_PATH = /home/mark/.arduino15/packages/digistump/hardware/avr/1.6.7/cores/tiny
ARDUINO_DIR = /home/mark/.arduino15/packages/digistump/hardware/avr/1.6.7

ARDUINO_LIBS = CapacitiveSensor DigisparkCDC
USER_LIB_PATH = /home/mark/Arduino/libraries
#AVR_TOOLS_DIR = /home/mark/.arduino15/packages/digistump/tools/avr-gcc/4.8.1-arduino5
AVR_TOOLS_DIR = /home/mark/.arduino15/packages/arduino/tools/avr-gcc/4.8.1-arduino5

BOARD_TAG = attiny
MCU = attiny85
ISP_PROG = micronucleus
F_CPU = 16500000L
#is this right??

pth := /home/mark/.arduino15/packages/digistump/tools/micronucleus/2.0a4/:$(PATH)
export PATH = $(pth)

include /home/mark/Arduino/Arduino-mk-Digispark/Arduino.mk

# NOTE qt creator is used as editor, not actually to build. Items in this file
# are merely to make qtcreator (and its linters) happy.
#
# Use make to build/upload.

TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
        src/main.cpp

DISTFILES += \
    src/Makefile

INCLUDEPATH += $(HOME)/.arduino15/packages/digistump/tools/avr-gcc/4.8.1-arduino5/avr/include \
               $(HOME)/.arduino15/packages/digistump/hardware/avr/1.6.7/cores/tiny \
               $(HOME)/.arduino15/packages/digistump/hardware/avr/1.6.7/variants/ \
               $(HOME)/Arduino/libraries/CapacitiveSensor \
               $(HOME)/.arduino15/packages/digistump/hardware/avr/1.6.7/libraries/DigisparkCDC

DEFINES += __AVR__ ARDUINO=100 uint8_t='unsigned char' __AVR_ATtinyX4__ UBRRH \
           F_CPU=16000000L __PROG_TYPES_COMPAT__

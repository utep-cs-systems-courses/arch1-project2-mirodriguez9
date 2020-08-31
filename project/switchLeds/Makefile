#makefile configuration
GCC_DIR = /opt/ti/msp430_gcc/bin
SUPPORT_FILE_DIRECTORY - /opt/ti/msp430_gcc/include

CPU       = msp430g2553
CFLAGS    = -I $(SUPPORT_FILE_DIRECTORY) -mcu = ${CPU} -I../h
LDFLAGS   = -L $(SUPPORT_FILE_DIRECTORY)

#switch the compiler (for the internal make rules)
CC        = $(GCC_DIR)/msp430-elf-gcc
AS        = $(GCC_DIR)/msp430-elf-as

all: switchLeds.elf

#includes dimLed from other directory
switchLeds.elf: main.o controlFlow.o ../dimLed/dimLed.o ../lib/libTimer.a
	${CC} ${CFLAGS} ${LDFLAGS} -o $@ $^

load: switchLeds.elf
	mspdebug rf2500 "prog switchLeds.elf"

clean:
	rm -f *.o *.elf

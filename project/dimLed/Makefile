#makefile configuration
GCC_DIR = /opt/ti/msp430_gcc/bin
SUPPORT_FILE_DIRECTORY = /opt/ti/msp430_gcc/include

CPU       = msp430g2553
CFLAGS    = -I $(SUPPORT_FILE_DIRECTORY) -mmcu=${CPU} -I../h
LDFLAGS   = -L $(SUPPORT_FILE_DIRECTORY)

#switch the compiler (for the internal make rules)
CC        = $(GCC_DIR)/msp430-elf-gcc
AS        = $(GCC_DIR)/msp430-elf-as

all: dimTest.elf

dimTest.elf: dimMain.o dimLed.o ../lib/libTimer.a
	${CC} ${CFLAGS} ${LDFLAGS} -o $@ $^

load: dimTest.elf
	mspdebug rf2500 "prog dimTest.elf"

clean: rm -f *.o *.elf

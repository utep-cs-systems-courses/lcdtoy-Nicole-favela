# makfile configuration
COMMON_OBJECTS  = 
CPU             = msp430g2553
CFLAGS          = -mmcu=${CPU} -I../h
LDFLAGS		= -L/opt/ti/msp430_gcc/include

#switch the compiler (for the internal make rules)
CC              = msp430-elf-gcc
AS              = msp430-elf-as

all: button.elf
libLcd.a: font-11x16.o font-5x7.o font-8x12.o lcdutils.o lcddraw.o
	$(AR) crs $@ $^
install: libLcd.a
	mkdir -p ../h ../lib
	mv $^ ../lib
	cp *.h ../h

#additional rules for files
button.elf: ${COMMON_OBJECTS} my_buzzer.o p2_interrupt_handler.o my_switches.o blinkMain.o stateMachines.o led.o wdInterruptHandler.o ../lib/libTimer.a select_button.s libLcd.a
	${CC} ${CFLAGS} ${LDFLAGS} -o $@ $^

load: button.elf
	msp430loader.sh button.elf

clean:
	rm -f *.o *.elf *~

led.o: led.c led.h

wdInterruptHandler.o: stateMachines.h

stateMachines.o: led.h stateMachines.h

my_buzzer.o: my_buzzer.h

blinkMain.o: my_buzzer.h

drawHexagon.elf: drawHexagon.o libLcd.a
	$(CC) $(CFLAGS) $^ -o $@ -lTimer
loadhex: drawHexagon.elf
	msp430loader.sh $^

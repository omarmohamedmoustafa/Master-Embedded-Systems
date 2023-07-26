#general makefile

CC=arm-none-eabi-
CFLAGS=-mcpu=arm926ej-s -g -I . -c
SRC=  $(wildcard *.c)
OBJS= $(SRC:.c=.o) 
ASM= $(wildcard *.s)
ASM_OBJ= $(ASM:.s=.o)
PROJECT_NAME=LAB1
all: LAB1.bin
	@echo "===========================Done==========================="

$(PROJECT_NAME).bin :$(PROJECT_NAME).elf
	$(CC)objcopy -O binary $< $@

startup.o: startup.s
	$(CC)as.exe $(CFLAGS) $< -o $@

%.o: %.c
	$(CC)gcc.exe $(CFLAGS) $< -o $@

	
$(PROJECT_NAME).elf : $(OBJS) $(ASM_OBJ)
	$(CC)ld.exe -T linker_script.ld startup.o app.o uart.o -o $@ -Map=Mapfile.map

clean:
	rm *.elf *.bin *.map
clean-all:
	rm *.o *.elf *.bin *.map
#general makefile
CC=arm-none-eabi-
CFLAGS= -mcpu=cortex-m3 -gdwarf-2 -I . -c -g
SRC=  $(wildcard *.c)
OBJS= $(SRC:.c=.o)  
ASM= $(wildcard *.s)
ASM_OBJ= $(ASM:.s=.o)
LNK_SCR=$(wildcard *.ld)
PROJECT_NAME=Term1
all: $(PROJECT_NAME).bin
	@echo "===========================Done==========================="

$(PROJECT_NAME).bin :$(PROJECT_NAME).elf
	$(CC)objcopy -O binary $< $@

%.o: %.c
	$(CC)gcc.exe $(CFLAGS) $< -o $@

	
$(PROJECT_NAME).elf : $(OBJS) 
	$(CC)ld.exe -T $(LNK_SCR)  $(OBJS) -o $@ -Map=Map_file.map

clean:
	rm *.elf *.bin *.map *.hex
clean-all:
	rm *.o *.elf *.bin *.map *.hex
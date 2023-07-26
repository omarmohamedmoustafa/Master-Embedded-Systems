#Simple makefile for LAB 1 without any generalization
LAB1.bin :LAB1.elf
	arm-none-eabi-objcopy -O binary LAB1.elf LAB1.bin

startup.o: startup.s
	arm-none-eabi-as.exe -c -g -I . -mcpu=arm926ej-s startup.s -o startup.o

app.o: app.c
	arm-none-eabi-gcc.exe -c -g -I . -mcpu=arm926ej-s app.c -o app.o

uart.o: uart.c
	arm-none-eabi-gcc.exe -c -g -I . -mcpu=arm926ej-s uart.c -o uart.o
LAB1.elf : uart.o app.o startup.o
	arm-none-eabi-ld.exe -T linker_script.ld startup.o app.o uart.o -o LAB1.elf -Map=Mapfile.map


clean:
	rm *.elf *.bin *.map
clean-all:
	rm *.o *.elf *.bin *.map
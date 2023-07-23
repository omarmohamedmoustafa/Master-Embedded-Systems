# The .c, .h, .s and linkerscript files before compiling :
![Screenshot_1](https://github.com/omarmohamedmoustafa/Master-Embedded-Systems/assets/93324483/1f804c0f-e5f6-43ee-9326-f95c4ff6715e)
# After these commands:
## next instruction to generate .o file from .s startup, compatible with Our board ARM Versatilepb
### arm-none-eabi-as -mcpu=arm926ej-s -g startup.s -o startup.o     
## next instruction to generate .o file from app.c, compatible with Our board ARM Versatilepb
### arm-none-eabi-gcc -c -I . -g -mcpu=arm926ej-s app.c -o app.o
## next instruction to generate .o file from uart.c, compatible with Our board ARM Versatilepb
### arm-none-eabi-gcc -c -I . -g -mcpu=arm926ej-s uart.c -o uart.o
## next instruction to generate .elf file and .map file from linking all obj files, compatible with Our board ARM Versatilepb
### arm-none-eabi-ld -T linker_script.ld startup.o app.o uart.o -o lab1.elf -Map=Map_File.map
## next instruction to generate .bin file and .elf file of our program
### arm-none-eabi-objcopy -O binary lab1.elf lab1.bin  

### qemu-system-arm -M versatilepb -m 128M -nographic -kernel lab1.bin 
![Screenshot_2](https://github.com/omarmohamedmoustafa/Master-Embedded-Systems/assets/93324483/92ad28f0-217c-42d3-b525-b728017f6416)

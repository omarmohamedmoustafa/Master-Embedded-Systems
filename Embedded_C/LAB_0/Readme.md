# Commands for static library linking:
## 1- create .o file for your driver.c file by using:
### gcc -c <driver_name.c> -o <driver_name.o>
## 2- create a static library from this .o file using binary utility <ar>
### ar rcs <lib_driver.a> <driver_name.o>
## 3- link the main.c and library.a through gcc
### gcc app.c lib_driver.a
#@copyright Mahmoud Elkot
CC=arm-none-eabi-
CFLAGS=-mcpu=cortex-m3  -gdwarf-2
INCS=-I . 
LIBS=
SRC = $(wildcard *.c)
OBJ = $(SRC:.c=.o)
AS = $(wildcard *.s)
ASOBJ = $(AS:.s=.o)
Project_Name=Learn-in-depth-first_term_project_1

all:$(Project_Name).bin
	@echo "       ======= Build done ======"
 
$(Project_Name).bin: $(Project_Name).elf
	$(CC)objcopy.exe -O binary $(Project_Name).elf $(Project_Name).bin

$(Project_Name).elf: $(OBJ) $(ASOBJ)
	$(CC)ld.exe -T linker_script.ld  $(OBJ) $(ASOBJ)  -o  $@   -Map=Map-file.map

%.o: %.s
	$(CC)as.exe   $(CFLAGS)   $< -o $@

%.o: %.c
	$(CC)gcc.exe $(CFLAGS) -c $(INCS)   $< -o  $@

clean:
	rm *.bin *.elf
clean-all:
	rm *.o *.bin *.elf *.map

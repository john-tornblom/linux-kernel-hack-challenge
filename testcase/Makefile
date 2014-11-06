CC      := powerpc-linux-gnu-gcc
CFLAGS  := -Wall -g -O0 -std=gnu99 -pedantic -I./inc
CFLAGS  += -fno-inline-functions-called-once -fno-guess-branch-probability
CFLAGS  += -fdump-rtl-expand -gdwarf-2 -mno-sdata -mno-toc -G0 -fno-common
CFLAGS  += -mcpu=8548 -mfloat-gprs=double -fno-builtin-memcpy -m32 -MMD
CFLAGS  += -Wmissing-declarations -Wmissing-prototypes
#CFLAGS  += -mspe -mabi=spe
LDFLAGS := -static
PROGRAM := case1
SOURCES := $(wildcard src/*.c)
OBJECTS := $(addprefix obj/, $(notdir $(SOURCES:.c=.o)))

all: obj $(PROGRAM)

obj:
	mkdir -p obj

$(PROGRAM): $(OBJECTS)
	$(CC) $(LDFLAGS) -o $@ $(OBJECTS)

obj/%.o: src/%.c
	$(CC) $(CFLAGS) -c -o $@ $<

clean:
	rm -rf obj
	rm -rf $(PROGRAM)

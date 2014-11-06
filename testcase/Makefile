CC      := powerpc-linux-gnu-gcc
CFLAGS  := -Wall -std=gnu99 -I./inc
CFLAGS  += -fno-inline-functions-called-once -fno-guess-branch-probability
CFLAGS  += -fdump-rtl-expand -g -gdwarf-2 -mno-sdata -mno-toc -G0 -fno-common -m32
CFLAGS  += -mcpu=8548 -mfloat-gprs=double -Wall -O1 -DBIG_ENDIAN -D_BIG_ENDIAN 
CFLAGS  += -fno-builtin-memcpy -Wmissing-declarations -Wmissing-prototypes -MMD -pedantic
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

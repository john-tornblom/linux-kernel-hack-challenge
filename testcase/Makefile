CC      ?= gcc
CFLAGS  := -Wall -std=gnu99 -I./inc
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

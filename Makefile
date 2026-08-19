CC      ?= gcc
CFLAGS  ?= -O3 -march=native -fPIC -flto -fvisibility=hidden
LDFLAGS ?= -shared -flto
LIBS    := -lz-ng

TARGET  := libklib.so
SRCDIR  := src
OBJDIR  := build
SOURCES := $(wildcard $(SRCDIR)/*.c)
OBJECTS := $(patsubst $(SRCDIR)/%.c,$(OBJDIR)/%.o,$(SOURCES))

.PHONY: all clean test

all: $(TARGET)

$(OBJDIR):
	mkdir -p $(OBJDIR)

$(OBJDIR)/%.o: $(SRCDIR)/%.c | $(OBJDIR)
	$(CC) $(CFLAGS) -c $< -o $@

$(TARGET): $(OBJECTS)
	$(CC) $(LDFLAGS) -o $@ $^ $(LIBS)

test: all
	$(CC) -O2 tests/test_compression.c -o tests/test_compression -L. -lklib $(LIBS)
	LD_LIBRARY_PATH=. ./tests/test_compression

clean:
	rm -rf $(OBJDIR) $(TARGET) tests/test_compression

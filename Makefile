##
# Project Title
#
# @file
# @version 0.1



UNAME_S = $(shell uname -s)

CC = clang
CFLAGS = -std=c11 -O3 -g -Wall -Wextra -Wpedantic -Wstrict-aliasing -fpack-struct
CFLAGS += -Wno-pointer-arith -Wno-newline-eof -Wno-unused-parameter -Wno-gnu-statement-expression
CFLAGS += -Wno-gnu-compound-literal-initializer -Wno-gnu-zero-variadic-macro-arguments
# CFLAGS +=  -Inuklear
LDFLAGS =

# GLFW required frameworks on OSX
# ifeq ($(UNAME_S), Darwin)
# 	LDFLAGS += -framework OpenGL -framework IOKit -framework CoreVideo -framework Cocoa
# endif

ifeq ($(UNAME_S), Linux)
	LDFLAGS += -ldl -lpthread
endif

SRC  = $(wildcard src/**/*.c) $(wildcard src/*.c) $(wildcard src/**/**/*.c) $(wildcard src/**/**/**/*.c)
OBJ  = $(SRC:.c=.o)
BIN = bin

.PHONY: all clean

all: dirs libs nn run

libs:
	# cd lib/cglm && cmake . -DCGLM_STATIC=ON && make
	# cd lib/glad && $(CC) -o src/glad.o -Iinclude -c src/glad.c
	# cd lib/glfw && cmake . && make
	# cd lib/noise && make

dirs:
	mkdir -p ./$(BIN)

run: all
	$(BIN)/nn

nn: $(OBJ)
	$(CC) -o $(BIN)/nn $^ $(LDFLAGS)

%.o: %.c
	$(CC) -o $@ -c $< $(CFLAGS)

clean:
	rm -rf $(OBJ)


# end

CXX = g++
FLAGS = -std=c++11
CFLAGS = -g -Wall
LDFLAGS = -lGL -lglfw

FILEPATH := $(realpath $(lastword $(MAKEFILE_LIST)))
CURDIR := $(shell cd $(dir $(FILEPATH));pwd)
GUI = $(CURDIR)/gui
INC = -I$(GUI)

RPATH = -Wl,-rpath=$(GUI) -L$(GUI) 
LIBS = -lwindow
BIN = pipe

all: $(BIN)

$(BIN): pipe.o
	$(CXX) pipe.o -o $(BIN) $(RPATH) $(LIBS) $(LDFLAGS)

.cpp.o:
	$(CXX) $(FLAGS) $(CFLAGS) $(INC) -c -o $@ $<

test: $(BIN)
	@./$(BIN)

clean:
	rm $(BIN) pipe.o

.PHONY: all test clean

CXX = g++
FLAGS = -std=c++11
CFLAGS = -g -Wall
LIBS = -lGL -lGLEW -lglfw

FILEPATH := $(realpath $(lastword $(MAKEFILE_LIST)))
CURDIR := $(shell cd $(dir $(FILEPATH));pwd)
GUI = $(CURDIR)/imgui
INC = -I$(GUI)

BIN = main

OBJ = main.o \
      $(GUI)/imgui_impl_glfw.o \
      $(GUI)/imgui_draw.o \
      $(GUI)/imgui.o

all: $(BIN)

$(BIN): $(OBJ)
	$(CXX) $(OBJ) -o $(BIN) $(LIBS)

.cpp.o:
	$(CXX) $(FLAGS) $(CFLAGS) $(INC) -c -o $@ $<

test: $(BIN)
	./$(BIN)

clean:
	rm $(OBJ) $(BIN)

.PHONY: all test clean

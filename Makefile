CXX = g++
FLAGS = -std=c++11
CFLAGS = -g -Wall
LIBS = -lGL -lglfw

FILEPATH := $(realpath $(lastword $(MAKEFILE_LIST)))
CURDIR := $(shell cd $(dir $(FILEPATH));pwd)
GUI = $(CURDIR)/gui
INC = -I$(GUI)

BIN = pipe

OBJ = pipe.o \
      $(GUI)/window.o \
      $(GUI)/imgui_impl_glfw.o \
      $(GUI)/imgui_draw.o \
      $(GUI)/imgui.o

all: $(BIN)

$(BIN): $(OBJ)
	$(CXX) $(OBJ) -o $(BIN) $(LIBS)

.cpp.o:
	$(CXX) $(FLAGS) $(CFLAGS) $(INC) -c -o $@ $<

test: $(BIN)
	@./$(BIN)

clean:
	rm $(OBJ) $(BIN)

.PHONY: all test clean

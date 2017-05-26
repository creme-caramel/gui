CXX = g++
FLAGS = -std=c++11
CFLAGS = -g -Wall -fPIC
LDFLAGS = -lGL -lglfw

FILEPATH := $(realpath $(lastword $(MAKEFILE_LIST)))
CURDIR := $(shell cd $(dir $(FILEPATH));pwd)
GUI = $(CURDIR)/gui
INC = -I$(GUI)

RPATH = -Wl,-rpath=$(GUI) -L$(GUI) 
LIBS = -lwindow
BIN = pipe

OBJ = pipe.o \
      $(GUI)/window.o \
      $(GUI)/imgui_impl_glfw.o \
      $(GUI)/imgui_draw.o \
      $(GUI)/imgui.o

all: window $(BIN)

window: $(GUI)/window.o $(GUI)/imgui_impl_glfw.o $(GUI)/imgui_draw.o $(GUI)/imgui.o
	$(CXX) -shared -o $(GUI)/libwindow.so $(GUI)/window.o $(GUI)/imgui_impl_glfw.o $(GUI)/imgui_draw.o $(GUI)/imgui.o
	
$(BIN): $(OBJ)
	$(CXX) $(OBJ) -o $(BIN) $(LDFLAGS)

.cpp.o:
	$(CXX) $(FLAGS) $(CFLAGS) $(INC) -c -o $@ $<

test: $(BIN)
	@./$(BIN)

clean:
	rm $(OBJ) $(BIN)

.PHONY: all test clean

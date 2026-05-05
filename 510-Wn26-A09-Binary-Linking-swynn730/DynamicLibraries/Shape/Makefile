CC=g++

DEBUG ?= 1

ifeq ($(DEBUG),1)
   OPTFLAGS=-g
else
   OPTFLAGS=-O3
endif

CFLAGS=-I. -I../../include -std=c++20 -Wall -Werror -fPIC $(OPTFLAGS)

PROJDIR := $(realpath $(CURDIR)/../..)
BUILDDIR := $(PROJDIR)/Output/DynamicLibraries/Shape

DIRS = DynamicLibraries/Shape
SOURCEDIRS = $(foreach dir, $(DIRS), $(addprefix $(PROJDIR)/, $(dir)))
TARGETDIRS = $(foreach dir, $(DIRS), $(addprefix $(BUILDDIR)/, $(dir))) $(PROJDIR)/bin
VPATH = $(SOURCEDIRS)
SOURCES = $(foreach dir, $(SOURCEDIRS), $(wildcard $(dir)/*.cpp))

OBJ := $(subst $(PROJDIR),$(BUILDDIR), $(SOURCES:.cpp=.o))

define generateRules
$(1)/%.o: %.cpp
	$(CC) -c -o $$@ $$< $$(CFLAGS)
endef

ifeq ($(OS),Windows_NT)

$(PROJDIR)/bin/libShape.dll: $(OBJ) directories
	g++ -shared -o $@ $(OBJ)

else

$(PROJDIR)/bin/libShape.so: $(OBJ) directories
	g++ -shared -o $@ $(OBJ)

endif

$(foreach targetdir, $(TARGETDIRS), $(eval $(call generateRules, $(targetdir))))

directories:
	mkdir -p $(TARGETDIRS)

ifeq ($(OS),Windows_NT)

all: directories $(PROJDIR)/bin/libShape.dll

else

all: directories $(PROJDIR)/bin/libShape.so

endif

clean:
	rm -rf $(TARGETDIRS)
	rm -rf $(BUILDDIR)

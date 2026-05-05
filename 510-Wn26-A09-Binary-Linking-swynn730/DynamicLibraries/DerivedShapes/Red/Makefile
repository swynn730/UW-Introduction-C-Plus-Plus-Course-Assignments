CC=g++

DEBUG ?= 1

ifeq ($(DEBUG),1)
   OPTFLAGS=-g
else
   OPTFLAGS=-O3
endif

CFLAGS=-I. -I../../../include -std=c++20 -Wall -Werror -fPIC $(OPTFLAGS)

PROJDIR := $(realpath $(CURDIR)/../../..)
BUILDDIR := $(PROJDIR)/Output/DynamicLibraries/DerivedShapes/Red

DIRS = DynamicLibraries/DerivedShapes/Red
SOURCEDIRS = $(foreach dir, $(DIRS), $(addprefix $(PROJDIR)/, $(dir)))
TARGETDIRS = $(foreach dir, $(DIRS), $(addprefix $(BUILDDIR)/, $(dir))) $(PROJDIR)/bin/Red
VPATH = $(SOURCEDIRS)
SOURCES = $(foreach dir, $(SOURCEDIRS), $(wildcard $(dir)/*.cpp))

OBJ := $(subst $(PROJDIR),$(BUILDDIR), $(SOURCES:.cpp=.o))

define generateRules
$(1)/%.o: %.cpp
	$(CC) -c -o $$@ $$< $$(CFLAGS)
endef

ifeq ($(OS),Windows_NT)

$(PROJDIR)/bin/Red/libDerivedShapes.dll: $(OBJ) directories $(PROJDIR)/bin/libShape.dll
	g++ -shared -L$(PROJDIR)/bin $(OBJ) -o $@ -lShape

$(PROJDIR)/bin/libShape.dll:
	$(MAKE) -j -C ../../Shape all

else

$(PROJDIR)/bin/Red/libDerivedShapes.so: $(OBJ) directories $(PROJDIR)/bin/libShape.so
	g++ -shared -L$(PROJDIR)/bin $(OBJ) -o $@ -lShape

$(PROJDIR)/bin/libShape.so:
	$(MAKE) -j -C ../../Shape all

endif

$(foreach targetdir, $(TARGETDIRS), $(eval $(call generateRules, $(targetdir))))

directories:
	mkdir -p $(TARGETDIRS)

ifeq ($(OS),Windows_NT)

all: directories $(PROJDIR)/bin/Red/libDerivedShapes.dll

else

all: directories $(PROJDIR)/bin/Red/libDerivedShapes.so

endif

clean:
	make -C ../../Shape clean
	rm -rf $(TARGETDIRS)
	rm -rf $(BUILDDIR)

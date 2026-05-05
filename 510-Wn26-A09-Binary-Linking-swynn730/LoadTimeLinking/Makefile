CC=g++

DEBUG ?= 1

ifeq ($(DEBUG),1)
   OPTFLAGS=-g
else
   OPTFLAGS=-O3
endif

CFLAGS=-I. -I../include -I../CppUnitLite -std=c++20 -Wall -Werror $(OPTFLAGS)

PROJDIR := $(realpath $(CURDIR)/..)
BUILDDIR := $(PROJDIR)/Output/LoadTimeLinking

DIRS = LoadTimeLinking
SOURCEDIRS = $(foreach dir, $(DIRS), $(addprefix $(PROJDIR)/, $(dir)))
TARGETDIRS = $(foreach dir, $(DIRS), $(addprefix $(BUILDDIR)/, $(dir))) ../bin
VPATH = $(SOURCEDIRS)
SOURCES = $(foreach dir, $(SOURCEDIRS), $(wildcard $(dir)/*.cpp))

OBJ := $(subst $(PROJDIR),$(BUILDDIR), $(SOURCES:.cpp=.o))

define generateRules
$(1)/%.o: %.cpp
	$(CC) -c -o $$@ $$< $$(CFLAGS)
endef

ifeq ($(OS),Windows_NT)

LoadTimeLinking: $(OBJ) directories $(PROJDIR)/bin/libShape.dll $(PROJDIR)/bin/Red/libDerivedShapes.dll ../lib/libCppUnitLite.a
	g++ -L../bin -L../bin/Red -L../lib $(OBJ) -o ../bin/LoadTimeLinking -lShape -lDerivedShapes -lCppUnitLite

LoadTimeLinking: $(OBJ) directories $(PROJDIR)/bin/libShape.dll $(PROJDIR)/bin/Blue/libDerivedShapes.dll ../lib/libCppUnitLite.a
	g++ -L../bin -L../bin/Blue -L../lib $(OBJ) -o ../bin/LoadTimeLinking -lShape -lDerivedShapes -lCppUnitLite

else

LoadTimeLinking: $(OBJ) directories $(PROJDIR)/bin/libShape.so $(PROJDIR)/bin/Red/libDerivedShapes.so ../lib/libCppUnitLite.a
	g++ -L../bin -L../bin/Red -L../lib $(OBJ) -o ../bin/LoadTimeLinking -lShape -lDerivedShapes -lCppUnitLite

LoadTimeLinking: $(OBJ) directories $(PROJDIR)/bin/libShape.so $(PROJDIR)/bin/Blue/libDerivedShapes.so ../lib/libCppUnitLite.a
	g++ -L../bin -L../bin/Blue -L../lib $(OBJ) -o ../bin/LoadTimeLinking -lShape -lDerivedShapes -lCppUnitLite

endif

../lib/libCppUnitLite.a:
	$(MAKE) -j -C ../CppUnitLite all

$(PROJDIR)/bin/libShape.so:
	$(MAKE) -j -C ../DynamicLibraries/Shape all

$(PROJDIR)/bin/Red/libDerivedShapes.so:
	$(MAKE) -j -C ../DynamicLibraries/DerivedShapes/Red all
	
$(PROJDIR)/bin/Blue/libDerivedShapes.so:
	$(MAKE) -j -C ../DynamicLibraries/DerivedShapes/Blue all

$(foreach targetdir, $(TARGETDIRS), $(eval $(call generateRules, $(targetdir))))

directories:
	mkdir -p $(TARGETDIRS)

ifeq ($(OS),Windows_NT)

all: directories LoadTimeLinking $(PROJDIR)/bin/Red/libDerivedShapes.dll
all: directories LoadTimeLinking $(PROJDIR)/bin/Blue/libDerivedShapes.dll

else

all: directories LoadTimeLinking $(PROJDIR)/bin/Red/libDerivedShapes.so
all: directories LoadTimeLinking $(PROJDIR)/bin/Blue/libDerivedShapes.so

endif

clean:
	$(MAKE) -j -C ../CppUnitLite clean
	$(MAKE) -j -C ../DynamicLibraries/Shape clean
	$(MAKE) -j -C ../DynamicLibraries/DerivedShapes/Red clean
	$(MAKE) -j -C ../DynamicLibraries/DerivedShapes/Blue clean
	rm -rf $(TARGETDIRS)
	rm -rf $(BUILDDIR)

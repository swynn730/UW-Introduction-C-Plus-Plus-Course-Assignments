DEBUG ?= 1

ifeq ($(DEBUG),1)
   OPTFLAGS=-g
else
   OPTFLAGS=-O3
endif

CFLAGS=-I. -I../include/ProjectCode -I../include/CppUnitLite -Wall -Werror $(OPTFLAGS)
CPPFLAGS=-std=c++20

PROJDIR := $(realpath $(CURDIR)/..)
BUILDDIR := $(PROJDIR)/Output

DIRS = UnitTestExe

SOURCEDIRS = $(foreach dir, $(DIRS), $(addprefix $(PROJDIR)/, $(dir)))
TARGETDIRS = $(foreach dir, $(DIRS), $(addprefix $(BUILDDIR)/, $(dir))) ../bin
VPATH = $(SOURCEDIRS)
SOURCES = $(foreach dir, $(SOURCEDIRS), $(wildcard $(dir)/*.cpp))

OBJ := $(subst $(PROJDIR),$(BUILDDIR), $(SOURCES:.cpp=.o))

define generateRules
$(1)/%.o: %.cpp
	$$(CXX) -c -o $$@ $$< $$(CFLAGS) $$(CPPFLAGS)
endef

all: directories ProjectCode CppUnitLite UnitTest

UnitTest: $(OBJ) directories ProjectCode CppUnitLite
	$(CXX) -L../bin -L../CppUnitLite $(OBJ) -o ../bin/UnitTest -lProjectCode -lCppUnitLite $(OPTFLAGS)

ProjectCode:
	$(MAKE) -j -C ../ProjectCode all

CppUnitLite:
	$(MAKE) -j -C ../CppUnitLite all

$(foreach targetdir, $(TARGETDIRS), $(eval $(call generateRules, $(targetdir))))

directories:
	mkdir -p $(TARGETDIRS)

clean:
	$(MAKE) -j -C ../ProjectCode clean
	$(MAKE) -j -C ../CppUnitLite clean
	rm -rf $(TARGETDIRS)
	rm -rf $(BUILDDIR)

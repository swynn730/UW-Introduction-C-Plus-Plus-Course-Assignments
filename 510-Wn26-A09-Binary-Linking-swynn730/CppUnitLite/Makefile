CC=g++
CFLAGS=-I. -std=c++20 -Wall -Werror

OBJ = Failure.o Test.o TestRegistry.o TestResult.o WFailure.o
%.o: %.cpp
	$(CC) -c -o $@ $< $(CFLAGS)

../lib/libCppUnitLite.a: $(OBJ)
	mkdir -p ../lib
	ar rcs $@ $(OBJ)
	ranlib $@

all: ../lib/libCppUnitLite.a

clean:
	rm -f ../lib/libCppUnitLite.a
	rm -f *.o

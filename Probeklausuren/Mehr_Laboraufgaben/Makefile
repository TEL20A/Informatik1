SOURCES = $(wildcard *.cpp)
BINARIES := $(patsubst %.cpp, %.exe, $(SOURCES))

.PHONY: $(SOURCES)

all: $(BINARIES)

% : %.cpp
	g++ -o $@.exe $^
	./$@.exe

%.exe : %.cpp
	g++ -o $@ $<
	$@

clean:
	del /q *.exe
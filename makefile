CXX = g++
CXXFLAGS = -Wall -std=c++17
TARGET = main
STKDIR = stack

SRCS = main.cpp \
		$(STKDIR)/stack.cpp

EXECUTABLE = a.out

all: $(EXECUTABLE)

$(EXECUTABLE): $(SRCS)
	$(CXX) $(CXXFLAGS) $^ -o $@

run: $(EXECUTABLE)
	./$(EXECUTABLE)

clean:
	rm -f $(EXECUTABLE)

.PHONY: all run clean
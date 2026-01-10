CXX := g++
CXXFLAGS := -std=c++17 -Wall -Wextra -g

SRC := $(shell find . -name "*.cpp")
OBJ := $(SRC:.cpp=.o)

TARGET := agenda_program

all: $(TARGET)

$(TARGET): $(OBJ)
	$(CXX) $(OBJ) -o $(TARGET)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ) $(TARGET)

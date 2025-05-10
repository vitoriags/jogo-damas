CXX = g++
CXXFLAGS = -Wall -std=c++11
LDFLAGS = -lGL -lGLU -lglut

INCLUDES = -Iinclude
SOURCES = $(wildcard src/*.cpp)
OBJECTS = $(SOURCES:.cpp=.o)
TARGET = damas

all: $(TARGET)

$(TARGET): $(SOURCES)
	$(CXX) $(CXXFLAGS) $(INCLUDES) -o $@ $^ $(LDFLAGS)

clean:
	rm -f $(TARGET) $(OBJECTS)

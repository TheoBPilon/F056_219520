CXX = g++
CXXFLAGS = -Wall -Wextra -std=c++17

LIB = libSimpleMET.so
TARGET = testMET

all: $(LIB) $(TARGET)

$(LIB): SimpleMET.cpp SimpleMET.h
	$(CXX) $(CXXFLAGS) -fPIC -shared SimpleMET.cpp -o $(LIB)

$(TARGET): testMET.cpp SimpleMET.h $(LIB)
	$(CXX) $(CXXFLAGS) testMET.cpp -L. -lSimpleMET -Wl,-rpath,'$$ORIGIN' -o $(TARGET)

clean:
	rm -f $(LIB) $(TARGET)
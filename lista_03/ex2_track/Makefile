CXX = g++
CXXFLAGS = -Wall -Wextra -std=c++17

LIBTRACK = libTrack.so
LIBSIMTRACK = libSimTrack.so
TARGET = testTrack

all: $(LIBTRACK) $(LIBSIMTRACK) $(TARGET)

# Biblioteca Track
$(LIBTRACK): Track.cpp Track.h
	$(CXX) $(CXXFLAGS) -fPIC -shared Track.cpp -o $(LIBTRACK)

# Biblioteca SimTrack, ligada contra libTrack
$(LIBSIMTRACK): SimTrack.cpp SimTrack.h Track.h $(LIBTRACK)
	$(CXX) $(CXXFLAGS) -fPIC -shared SimTrack.cpp -L. -lTrack -Wl,-rpath,'$$ORIGIN' -o $(LIBSIMTRACK)

# Programa de teste, ligado contra as duas bibliotecas
$(TARGET): testTrack.cpp Track.h SimTrack.h $(LIBTRACK) $(LIBSIMTRACK)
	$(CXX) $(CXXFLAGS) testTrack.cpp -L. -lSimTrack -lTrack -Wl,-rpath,'$$ORIGIN' -o $(TARGET)

clean:
	rm -f $(LIBTRACK) $(LIBSIMTRACK) $(TARGET)
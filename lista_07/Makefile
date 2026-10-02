# Compilador e Flags Padrão
CXX       := g++
CXXFLAGS  := -O2 -std=c++11 -pedantic -W -Wall -Wshadow -fPIC

# Coleta automatizada das flags do PYTHIA8 via script auxiliar
PYTHIA8_FLAGS := $(shell pythia8-config --cxxflags --libs)

# Executável do projeto
TARGET    := ttbar_pythia

# Regra principal: compila o executável
all: $(TARGET)

# Regra para compilar ttbar_pythia
$(TARGET): ttbar_pythia.cc
	$(CXX) ttbar_pythia.cc -o $(TARGET) $(CXXFLAGS) $(PYTHIA8_FLAGS)

# Regra de automação de execução
run: $(TARGET)
	./$(TARGET)

# Regra para limpar arquivos binários
clean:
	rm -f $(TARGET) *.o

.PHONY: all run clean

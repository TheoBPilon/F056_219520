CXX       := g++
CXXFLAGS  := -O2 -std=c++11 -pedantic -W -Wall -Wshadow -fPIC

# Coleta automatizada das flags do PYTHIA8 e ROOT via scripts auxiliares
PYTHIA8_FLAGS := $(shell pythia8-config --cxxflags --libs)
ROOT_FLAGS    := $(shell root-config --cflags --libs)

# Junta todas as flags de inclusão e bibliotecas
ALL_FLAGS     := $(CXXFLAGS) $(PYTHIA8_FLAGS) $(ROOT_FLAGS)

# Executáveis a serem gerados
TARGET_HIGGS  := main_higgs

# Regra principal (executada ao digitar apenas 'make')
all: $(TARGET_HIGGS)

# Regra para compilar o código do Higgs (Parte A)
$(TARGET_HIGGS): main_higgs.cc
	$(CXX) main_higgs.cc -o $(TARGET_HIGGS) $(ALL_FLAGS)

# Regra para limpar arquivos gerados
clean:
	rm -f $(TARGET_HIGGS) *.o higgs_mass.root *.root

.PHONY: all clean

# Compilador e Flags Padrão
CXX       := g++
CXXFLAGS  := -O2 -std=c++11 -pedantic -W -Wall -Wshadow -fPIC

# Coleta automatizada das flags do PYTHIA8 e ROOT via scripts auxiliares
PYTHIA8_FLAGS := $(shell pythia8-config --cxxflags --libs)
ROOT_FLAGS    := $(shell root-config --cflags --libs)

# Junta todas as flags de inclusão e bibliotecas
ALL_FLAGS     := $(CXXFLAGS) $(PYTHIA8_FLAGS) $(ROOT_FLAGS)

# Executáveis do projeto
TARGET_HIGGS  := main_higgs
TARGET_BKG    := main_bkg
TARGET_PLOT   := plot_higgs_vs_bkg

# Regra principal: compila todos os programas C++ do projeto
all: $(TARGET_HIGGS) $(TARGET_BKG) $(TARGET_PLOT)

# 1. Regra para compilar o Sinal do Higgs
$(TARGET_HIGGS): main_higgs.cc
	$(CXX) main_higgs.cc -o $(TARGET_HIGGS) $(ALL_FLAGS)

# 2. Regra para compilar o Gerador de Backgrounds (QCD, Z, ttbar)
$(TARGET_BKG): main_bkg.cc
	$(CXX) main_bkg.cc -o $(TARGET_BKG) $(ALL_FLAGS)

# 3. Regra para compilar o Gerador do Gráfico em ROOT
$(TARGET_PLOT): plot_higgs_vs_bkg.cc
	$(CXX) plot_higgs_vs_bkg.cc -o $(TARGET_PLOT) $(ROOT_FLAGS)


# Regras de Automação de Execução


# Gera todos os backgrounds de uma só vez sequencialmente
run-bkg: $(TARGET_BKG)
	./$(TARGET_BKG) qcd
	./$(TARGET_BKG) z
	./$(TARGET_BKG) ttbar

# Gera o sinal do Higgs e todos os backgrounds de uma só vez
run-all: $(TARGET_HIGGS) run-bkg
	./$(TARGET_HIGGS)

# Roda a macro do ROOT para gerar a figura final
plot: $(TARGET_PLOT)
	./$(TARGET_PLOT)

# Regra para limpar arquivos binários
clean:
	rm -f $(TARGET_HIGGS) $(TARGET_BKG) $(TARGET_PLOT) *.o 

.PHONY: all run-bkg run-all plot clean
# Exercício 05: Interface entre C++, ROOT e Python
Este repositório contém a resolução do **Exercício 05** de F056


## Parte 1 – Pergunta sobre `root-config`

* `root-config --cflags` retorna as flags de inclusão e compilação C++ (como caminhos de cabeçalhos `-I...` e diretivas do compilador) específicas da instalação do ROOT.

* `root-config --libs` retorna as opções de linkagem ( flags `-L...` de diretório de bibliotecas e `-lCore -lTree -lHist ...` para associar as bibliotecas dinâmicas `.so` do ROOT).

* O compilador C++ independente (`g++`) é um compilador genérico, portanto, eu preciso fornecer os includes durante o parsing e vincular os símbolos compilados dos objetos durante o linker. Isso nao acontece quando rodo diretamente no ambiente do ROOT já lá, é executado com seus dicionários C++ pré-carregados e integrados ao processo.


## Parte 2 – Pergunta sobre PyROOT

O PyROOT não reimplementa o ROOT em Python; ele funciona como uma ponte direta que conecta os comandos em Python às classes originais em C++ em tempo de execução. Enquanto a sintaxe se ajusta ao padrão do Python (dispensando a declaração de tipos, usando ponto em vez de -> para acessar atributos e adaptando palavras-chave), a execução real das tarefas continua acontecendo no código compilado em C++.


##  Parte 3 – Comparação entre as Três Versões


 

1. **Rapidez de escrita vs. Rapidez de execução:**
   * **Escrita:** O **PyROOT** foi a versão mais rápida de escrever devido à sintaxe limpa do Python
   * **Execução:** A versão em **C++ Compilado** (`./generate` e `./plot_and_fit`) foi a mais rápida de executar por ser traduzida diretamente em código binário de máquina otimizado .

2. **Mudanças estruturais no código:**
   * Ao passar de macro interpretado para **C++ compilado**, foi necessário adicionar a função ponto de entrada `int main()`, incluir manualmente todos os cabeçalhos (`.h`) do ROOT e configurar o `Makefile` para o linker.
   * Ao passar para o **PyROOT**, a tipagem passou a ser dinâmica e o acesso a membros mudou de `->` para `.`. Além disso, para a comunicação de endereços de memória em branches de `TTree` (`tree.Branch` e `tree.SetBranchAddress`), foi necessário usar estruturas mutáveis de buffer como `array.array('d', ...)`, garantindo que o C++ leia o endereço de memória correto fornecido pelo Python.

3. **Verificação de Tipos (Compile-time vs. Runtime):**
   * **Antes de rodar:** No **C++ compilado**. O `g++` verifica todos os tipos, assinaturas de métodos e declarações durante a compilação. Qualquer erro de sintaxe ou incompatibilidade de tipo aborta o build antes da criação do executável.
   * **Em tempo de execução (Runtime):** No **PyROOT** e no **Macro interpretado**. Como o Python é dinamicamente tipado, erros como passagem de tipos incompatíveis ou chamadas de métodos inexistentes só são detectados quando aquela linha específica de código é alcançada durante a execução.


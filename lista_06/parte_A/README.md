# Parte A – Simulação e Reconstrução do Bóson de Higgs no PYTHIA8

Este projeto consiste na simulação de $1.000$ eventos do bóson de Higgs ($m_H = 125\text{ GeV}$) a $\sqrt{s} = 13\text{ TeV}$ via PYTHIA8 e na reconstrução da massa invariante $m_H$ salva em um arquivo ROOT.

---

## 1. Configuração do PYTHIA8 (`main_higgs.cmnd`)
* **Canal de Produção (`HiggsSM:gg2H = on`):** Ativa a fusão de glúons ($gg \to H$), ($\sim 87\%$ da seção de choque em $13\text{ TeV}$).
* **Decaimento (`25:onMode = off`, `25:onIfMatch = 5 -5`):** queremos que ocorra só decaimento  em $H \to b\bar{b}$.
* **Funções de Estrutura (PDF):** Utilizou-se a `LHAPDF6:cteq6l1`. *(Caso indisponível, o PDF interno padrão do PYTHIA8 `NNPDF2.3 LO` é usado).*

---

## 2. Reconstrução da Massa Invariante (`main_higgs.cc`)
O código em C++ percorre a árvore de eventos (`pythia.event`), identifica as filhas diretas do Higgs (`mother1() == indexDoHiggs`) e calcula a massa do par $b\bar{b}$ somando os seus quadrimomentos:
$$m_H = \sqrt{(E_b + E_{\bar{b}})^2 - \vert{}\vec{p}_b + \vec{p}_{\bar{b}}\vert{}^2}$$
Os eventos válidos preenchem a `TTree` (`events`) com a ramificação `mH`, gravada no arquivo `higgs_mass.root`.


---

## 4. Como Compilar e Executar

```bash
make
./main_higgs

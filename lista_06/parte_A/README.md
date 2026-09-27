# Parte A – Simulação e Reconstrução do Bóson de Higgs no PYTHIA8

Este projeto consiste na simulação de $1.000$ eventos do bóson de Higgs ($m_H = 125\text{ GeV}$) a $\sqrt{s} =  





13\text{ TeV}$ via PYTHIA8 e na reconstrução da massa invariante $m_H$ salva em arquivo ROOT, juntamente com a análise dos principais  .

---

## 1. Configuração do PYTHIA8 e Justificativa Teórica (`main_higgs.cmnd`)

* **Canal de Produção (`HiggsSM:gg2H = on`):**   usei a **fusão de glúons ($gg \to H$)** por ser o mecanismo de produção dominante do Higgs no LHC ($\sim 87\%$ da seção de choque total a $\sqrt{s} = 13\text{ TeV}$) via loop de quarks pesados (predominantemente o quark top).
* **Canal de Decaimento (`25:onMode = off`, `25:onIfMatch = 5 -5`):** Todos os canais foram desativados para selecionar exclusivamente $H \to b\bar{b}$. Embora seja um canal desafiador experimentalmente devido ao grande fundo QCD, é o canal com a maior fração de ramificação (branching ratio) do Higgs no Modelo Padrão (~58%).
* **Função de Estrutura Partônica (PDF):**

  * Escolhi a PDF CTEQ6L1 porque ela descreve direito a fração de momento ($x$) que os glúons carregam no próton. Como o Higgs é produzido principalmente via fusão de glúons no LHC ($gg \to H$) nessa região de baixo $x$, essa escolha é importante pra ter um valor realista da seção de choque no gerador.
---

## 2. Reconstrução da Massa Invariante (`main_higgs.cc`)
O código em C++ percorre a árvore de eventos (`pythia.event`), identifica as filhas diretas do Higgs (`mother1() == indexDoHiggs`) e calcula a massa do par $b\bar{b}$ somando os seus quadrimomentos:
$$m_H = \sqrt{(E_b + E_{\bar{b}})^2 - \vert{}\vec{p}_b + \vec{p}_{\bar{b}}\vert{}^2}$$
Os eventos válidos preenchem a `TTree` (`events`) com as ramificações `mH` e `eventNumber`, gravadas no arquivo `higgs_mass.root`.

---

## 3. Backgrounds Simulados (`main_bkg.cc`)
Para comparação com o sinal $H \to b\bar{b}$, foram simulados três backgrounds do Modelo Padrão que produzem pares $b\bar{b}$ na mesma região de massa:
1. **QCD multijato ($b\bar{b}$ direto):** Ativado com `HardQCD:hardbbbar = on` e corte de $p_T^{\text{hat}} > 20\text{ GeV}$ (`PhaseSpace:pTHatMin = 20.`). É o fundo dominante do processo.
2. **$Z(\to b\bar{b}) + \text{jatos}$:** Ativado via `WeakSingleBoson:ffbar2gmZ = on` com decaimento forçado $Z \to b\bar{b}$, gerando uma ressonância próxima a $M_Z \simeq 91\text{ GeV}$.
3. **$t\bar{t}$ ($top-antitop$):** Ativado via `Top:gg2ttbar = on` e `Top:qqbar2ttbar = on`, cujos decaimentos contêm quarks $b$ no estado final.

---

## 4. Como Compilar e Executar

Coloquei algumas automações no `Makefile`  para compilar e gerar todas as amostras e gráficos:

```bash
# Compilar todos os códigos (main_higgs, main_bkg e plot_higgs_vs_bkg)
make

# Executar a simulação do Higgs e de todos os backgrounds
make run-all

# Gerar o gráfico com a sobreposição dos histogramas
make plot
```

Alternativamente, podemos rodar cada parte individualmente:

```bash
# Compilar o código do Higgs (Parte A)
make run-higgs

# Compilar o código dos 3 backgrounds (QCD, Z, ttbar)
make run-bkg

# Gerar o gráfico com a sobreposição dos histogramas
make plot
```

Ou, no caso do background, podemos rodar apenas o código de cada background:

```bash
make
./main_bkg qcd
./main_bkg z
./main_bkg ttbar
```

Para limpar:

```bash
make clean
```

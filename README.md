## Instruções:
Para executar as macros, basta rodar

```bash
root -l generate.C
.q # para sair do ambiente do root
root -l plot.C
```

e será gerado o arquivo png referente ao plot do histograma.

## Resultados do Ajuste e Análise
Os dados da `TTree` foram ajustados via Minuit2 usando a função pré-definida `"gaus"`. Os resultados encontrados foram:

$$
\sigma_{fit}  = 0.99 \pm 0.02 ~~~~~~~~ \mu_{fit} = 2.03\pm 0.03
$$

```bash
****************************************
Minimizer is Minuit2 / Migrad
Chi2                      =      38.6358
NDf                       =           39
Edm                       =  1.61467e-08
NCalls                    =           61
Constant                  =      54.0145   +/-   2.20025     
Mean                      =      2.03403   +/-   0.0329484   
Sigma                     =     0.999496   +/-   0.0259686       (limited)
Info in <TCanvas::Print>: png file histograma.png has been created
```


 O aviso `(limited)` serve apenas para sinalizar que o Minuit2 convergiu com sucesso para o mínimo global real, porém operando dentro de uma janela de segurança predefinida.

Os resultados estão bem compatíveis com os fornecidos inicialmente no macro `generate.C`

$$
\sigma_{entrada} = 1 ~~~~~~~ \mu_{entrada} = 2
$$

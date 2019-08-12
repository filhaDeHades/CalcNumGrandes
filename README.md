# Calculadora de Números Grandes
Trabalho da matéria Programação Estruturada. Uma calculadora para números inteiros grandes, bem maiores que long long, contendo soma, subtração, multiplicação e divisão.
## Objetivo:
Colocar em prática os ensinamentos da disciplina de Programação Estruturada cursada em 2018.2.
## Especificação:
Fazer a manipulação de listas por meio da implementação de uma biblioteca de inteiros gigantes.
Seu programa deve ser capaz de receber, enquanto qualquer usuário do sistema quiser, dois inteiros gigantes com sinal e realizar as quatro operações matemáticas básicas, a saber:
+ soma
+ subtração
+ multiplicação
+ divisão

## Informações importantes:
Os números serão lidos com o sinal. O sinal lido como o valor da variável _descritor_ e a entrada da calculadora é feita com uma lista duplamente encadeada com descritor.
O número **não é** armazenado inversamente.

O ponteiro anterior do primeiro algarismo aponta pra **NULL.**
O ponteiro proximo do último algarismo aponta pra **NULL.**
Ou seja, se a entrada for o número 1234, a lista será armazenada como:

> **x- 1 -> <- 2 -> <- 3 -> <- 4 -x**

se a entrada for 1, a lista será armazenada como:
> **x- 1 -x**

### ETD é o struct usado para a lista, ele contém o sinal e os algarismos.

Há uma função que retorna os algarismos invertidos, mas ela não está sendo usada.

## Quem fez o que?

#### Muzzi:
+ ETD* insereComeco(ETD* palavra, int num);
+ ETD* multiplica(ETD* num1, ETD* num2);
+ ETD* subtrai(ETD* num1, ETD* num2);

#### Nicole:
+ ETD* soma(ETD* num1, ETD* num2);
+ ETD* divide(ETD* num1, ETD* num2);
+ int maiorMagnitude(ETD* num1, ETD* num2);

#### Tamires:
+ Struct CRTR;
+ Struct ETD;
+ void tiraZero(ETD* num);
+ char operacao(void);
+ ETD* inicializacaoCarac(int n);
+ ETD* inicializaSinal(void);
+ ETD* criaCarac(ETD* palavra);
+ ETD* sinal(ETD* palavra);
+ CRTR* inicializaCarac(int n);
+ void validCarac(ETD* pal, CRTR* num, char car);
+ ETD* addCarac(ETD* palavra);
+ CRTR* andarFinal(CRTR* palavra);
+ CRTR* invC(CRTR* num);
+ CRTR* insC(CRTR* lista, int n);
+ void escreveCarac(ETD* palavra);
+ void escreveAlg(CRTR* lista);
+ void liberaCarac(ETD* palavra);
+ void liberaAlg(CRTR* lixo);
+ int maiorMagnitude(ETD* n1, ETD* n2); **(2ª versão)**
+ ETD* soma(ETD* num1, ETD* num2); **(2ª versão)**
+ ETD* subtrai(ETD* num1, ETD* num2); **(2ª versão)**
+ ETD* verifica(ETD* num1, ETD* num2, char oper);
+ ETD* multiplica(ETD* num1, ETD* num2); **(2ª versão)**
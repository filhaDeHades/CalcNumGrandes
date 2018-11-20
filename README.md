# CalcNumGrandes
Calculadora para números inteiros grandes, bem maiores que long long, contendo soma, subtração, multiplicação e divisão

## Entrada:
O número deverá ser lido com o sinal.
O sinal é o descritor.
A entrada da calculadora é feita com uma lista duplamente encadeada com descritor.
O número não é armazenado inversamente.

O ponteiro anterior do primeiro algarismo aponta pra null.
O ponteiro proximo do último algarismo aponta pra null.
Ou seja,
se a entrada for o número 1234, a lista será armazenada como:
### x- 1 -> <- 2 -> <- 3 -> <- 4 -x
se a entrada for 1, a lista será armazenada como:
### x- 1 -x

NG é um struct apenas com números que não precisa ser usado. Ele já foi apagado da main.
### ETD é o struct que é usado para lista que tera o sinal e os algarismos.

A alteração para que o 0 a esquerda fosse ignorado foi feita.

também vou fazer uma função que retorne os algarismos invertidos para facilitar em algumas equações.
obs: A função foi feita mas n esta sendo usada, possivelmente será excluida.

## Quem fez o que?

#### Agatha:

#### Nicole:

#### Tamires:
Struct CRTR; 
Struct ETD; 
char operacao(void);
ETD* inicializacaoCarac(int n);
ETD* inicializaSinal(void);
ETD* criaCarac(ETD* palavra);
ETD* sinal(ETD* palavra);
CRTR* inicializaCarac(int n);
void validCarac(ETD* pal, CRTR* num, char car);
ETD* addCarac(ETD* palavra);
CRTR* andarFinal(CRTR* palavra);
CRTR* invC(CRTR* num);
CRTR* insC(CRTR* lista, int n);
void escreveCarac(ETD* palavra);
void escreveAlg(CRTR* lista);
void liberaCarac(ETD* palavra);
void liberaAlg(CRTR* lixo);

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

NG é um struct apenas com números que não precisa ser usado.
ETD é o struct que é usado para lista que tera o sinal e os algarismos.

Falta dar algumas refinadas no código, ignorar o zero a esquerda, etc.
também vou fazer uma função que retorne os algarismos invertidos para facilitar em algumas equações.

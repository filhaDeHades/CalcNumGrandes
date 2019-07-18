#include "0. imports.h"

typedef struct caracteres{
	int car;
	struct caracteres *ant, *prox;
}CRTR;

typedef struct entrada{
	char valor;
	CRTR* ult;
	CRTR* prim;
}ETD;

//---------------------------------- Usando os caracteres de entrada -------------------------------------
//Tira os zeros a esquerda do número
void tiraZero(ETD* num);
//Menu do programa
char operacao(void);

//----------------------------------------- Funções de Suporte --------------------------------------------
//Retorna o último algarismo do número
CRTR* andarFinal(CRTR* palavra);

//inserir os números invertidos
CRTR* insC(CRTR* lista, int n);

//inverte os números
CRTR* invC(CRTR* num);

//Cria uma lista com os números já invertidos
ETD* insereComeco(ETD* palavra, int num);

//Copia um número
ETD* copia(ETD* num);

//------------------------------------------ Inicializadores ----------------------------------------------
//Inicializa a estrutura ETD
ETD* inicializaSinal(void);

//Inicializa a estrutura CRTR
CRTR* inicializaCarac(int n);

//Adiciona os valores a estrutura
ETD* inicializacaoCarac(int n);

//--------------------------------- Adicionando algarismos a estrutura ------------------------------------
//Adiciona o valor do sinal a estrutura
ETD* sinal(ETD* palavra);

//Valida o caracter que será adicionado na estrutura
void validCarac(ETD* pal, CRTR** num, char car);

//Adiciona o valor de número na estrutura
ETD* addCarac(ETD* palavra);

//Cria efetivamente o caracter
ETD* criaCarac(ETD* palavra);

//------------------------------------- Printando os números ----------------------------------------------
//Printando a estrutura principal
void escreveCarac(ETD* palavra);

//Printando os algarismos
void escreveAlg(CRTR* lista);

//------------------------------------------ Liberação ----------------------------------------------------
//Libera a estrutura toda
void liberaCarac(ETD* palavra);

//Libera apenas os caracteres
void liberaAlg(CRTR* lixo);

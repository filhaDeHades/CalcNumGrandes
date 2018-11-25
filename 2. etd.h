#include "0. imports.h"

typedef struct caracteres{
	int car;
	struct caracteres *ant, *prox;
}CRTR;

typedef struct entrada{
	char valor;
	CRTR* ult;
	CRTR* prox; //primeiro
}ETD;

char operacao(void);

ETD* inicializacaoCarac(int n);
ETD* inicializaSinal(void);
ETD* criaCarac(ETD* palavra);
ETD* sinal(ETD* palavra);
CRTR* inicializaCarac(int n);
void validCarac(ETD* pal, CRTR** num, char car);
ETD* addCarac(ETD* palavra);
CRTR* andarFinal(CRTR* palavra);
ETD* insereComeco(ETD* palavra, int num);
void tiraZero(ETD* num);
CRTR* invC(CRTR* num);
CRTR* insC(CRTR* lista, int n);
ETD* insereComeco(ETD* palavra, int num);

void escreveCarac(ETD* palavra);
void escreveAlg(CRTR* lista);

void liberaCarac(ETD* palavra);
void liberaAlg(CRTR* lixo);

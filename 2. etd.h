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
		ETD* addCarac(ETD* palavra);
			CRTR* andarFinal(CRTR* palavra);

CRTR* invC(CRTR* num);
	CRTR* insC(CRTR* lista, int n);

void escreveCarac(ETD* palavra);
void escreveAlg(CRTR* lista);

void liberaCarac(ETD* palavra);
void liberaAlg(CRTR* lixo);

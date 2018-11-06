#include "0. imports.h"

typedef struct caracteres{
	int car;
	struct caracteres *ant, *prox;
}CRTR;

typedef struct entrada{
	char valor;
	CRTR* prox;
}ETD;

ETD* inicializacaoCarac(int n);
	ETD* inicializaSinal(void);
	ETD* criaCarac(ETD* palavra);
		ETD* sinal(ETD* palavra);
		CRTR* inicializaCarac(int n);
		ETD* addCarac(ETD* palavra);
			CRTR* andarFinal(CRTR* palavra);

void escreveCarac(ETD* palavra);


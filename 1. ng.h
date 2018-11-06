#include "0. imports.h"

typedef struct numerosGrandes{
	int num;
	struct numerosGrandes *ant, *prox;
}NG;

NG* inicializaNum(void);

NG* insNum(NG* lista, int x);

NG* criaNum(NG* lista);

NG* inverteNum(NG* lista);

void escreveNum(NG* lista);

NG* inicializacao(NG* lista, int n);

void escreverNum(NG* lista, int n);

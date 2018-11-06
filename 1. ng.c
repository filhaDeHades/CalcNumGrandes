#include "1. ng.h"

//Apartir daq só mechemos com números;
NG* inicializaNum(void){
	return (NG*)NULL;
}

NG* insNum(NG* lista, int x){
	NG* novo = (NG*)malloc(sizeof(NG));
	novo->num = x;
	novo->ant = (NG*)NULL;
	novo->prox = lista;
	if(lista) lista->ant = novo;
	return novo;
}

NG* criaNum(NG* lista){
	int n;
	NG *p = lista;
	while(1){
		scanf("%d", &n);
		if(n < 0) break;
		lista = insNum(lista, n);
	}
	return lista;
}

NG* inverteNum(NG* lista){
	NG *p, *q;
	q = (NG*)malloc(sizeof(NG));
	q = inicializaNum();
	p = lista;
	while(p){
		q = insNum(q, p->num);
		p = p->prox;
	}
	return q;
}

void escreveNum(NG* lista){
	NG *p = lista;
	while(p){
		printf("%d ", p->num);
		p = p->prox;
	}
	printf("\n");
}

NG* inicializacao(NG* lista, int n){
	lista = (NG*)malloc(sizeof(NG));
	lista = inicializaNum();
	printf("\e[32mDigite o %dº número: \e[m", n);
	lista = criaNum(lista);
	printf("\n");
	return lista;
}

void escreverNum(NG* lista, int n){
	printf("Número %d: ", n);
	escreveNum(lista);
}

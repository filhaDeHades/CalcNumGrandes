#include "2. etd.h"

//mechendo com o caracter de entrada
	//andando até o final da lista de caracter
CRTR* andarFinal(CRTR* palavra){
	if(palavra)
		while(palavra->prox)
			palavra = palavra->prox;
	return palavra;
}

ETD* inicializaSinal(void){
	ETD* p = (ETD*)malloc(sizeof(ETD));
	//'\0' é o NULL do char
	p->valor = '\0';
	p->prox = (CRTR*) NULL;
	return p;
}

CRTR* inicializaCarac(int n){
	CRTR* q = (CRTR*)malloc(sizeof(CRTR));
	q->ant = (CRTR*) NULL;
	q->car = n-48;
	q->prox = (CRTR*) NULL;
	return q;
}

ETD* sinal(ETD* palavra){
	char n;
	while(1){
		scanf("%c", &n);
		if((n == '+')||(n == '-')){
			palavra->valor = n;
			palavra->prox = (CRTR*) NULL;
			break;
		}
		else {
			//repete o print duas vezes, n sei pq
			printf("Digite um valor válido para o sinal:\n");
		}
	}
	return palavra;
}

ETD* addCarac(ETD* palavra){
	CRTR *num, *aux;
	num = palavra->prox;
	char m;
	while(1){
		aux = (CRTR*) malloc(sizeof(CRTR));
		scanf("%c", &m);
		if((m >= 48)&&(m <= 57)){
			aux->car = m-48;
			aux->prox = (CRTR*) NULL;
			if(!num){
				aux->ant = (CRTR*) NULL;
				palavra->prox = num = aux;
			} else{
				CRTR *o;
				o = andarFinal(num);
				o->prox = aux;
				aux->ant = o;
			}
		}
		else if((m == 43)||(m == 45)){
			break;
		}
	}
	palavra->prox = num;
	return palavra;
}
	//cria efetivamente o caracter
ETD* criaCarac(ETD* palavra){
	//add o sinal do número
	printf("\nDigite o número com o sinal: \n");
	palavra = sinal(palavra);
	//add os caracteres do número
	palavra->prox = (CRTR*) NULL;
	
	palavra = addCarac(palavra);
	return palavra;
}

ETD* inicializacaoCarac(int n){
	ETD* palavra = inicializaSinal();
	printf("\e[32mDigite o %dº número: \e[m", n);
	palavra = criaCarac(palavra);
	printf("\n");
	return palavra;
}

	//printando o caracter
void escreveCarac(ETD* palavra){
	ETD *p = palavra;
	CRTR *q = palavra->prox;
	printf("%c", p->valor);
	while(q){
		printf("%d", q->car);
		q = q->prox;
	}
	printf("\n");

}

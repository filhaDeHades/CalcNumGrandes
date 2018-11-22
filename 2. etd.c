#include "2. etd.h"

#define oi printf("oi\n");

//mechendo com o caracter de entrada

char operacao(void){
	char op = '+';
	printf("\e[32mQual das operações abaixo você quer fazer com esses números: \n\e[m");
	printf("\e[33m+ ---------- Adição\n");
	printf("- ---------- Subtração\n");
	printf("* ---------- Multiplicação\n");
	printf("/ ---------- Divisão\n \e[m");
	while((op != '-')||(op != '+')||(op != '*')||(op != '/')){
		scanf(" %c", &op);
		if((op == '-')||(op == '+')||(op == '*')||(op == '/')) break;
		printf("\e[31mDigite um valor válido para a operação:\e[m\n");
	}
	return op;
}
	//andando até o final da lista de caracter
CRTR* andarFinal(CRTR* palavra){
	if(palavra)
		while(palavra->prox)
			palavra = palavra->prox;
	return palavra;
}

	//inserir números ao contrario
CRTR* insC(CRTR* lista, int n){
	CRTR* novo = (CRTR*)malloc(sizeof(CRTR));
	novo->car = n;
	novo->ant = (CRTR*) NULL;
	novo->prox = lista;
	if(lista) lista->ant = novo;
	return novo;
}
	//inverter os números
CRTR* invC(CRTR* num){
	CRTR *inv = (CRTR*) NULL;
	CRTR *fim = (CRTR*)malloc(sizeof(CRTR));
	fim = num;
	while(fim){
		inv = insC(inv, fim->car);
		fim = fim->prox;
	}
	return inv;
}

CRTR* inicializaCarac(int n){
	CRTR* q = (CRTR*)malloc(sizeof(CRTR));
	q->ant = (CRTR*) NULL;
	q->car = n-48;
	q->prox = (CRTR*) NULL;
	return q;
}

ETD* inicializaSinal(void){
	ETD* p = (ETD*)malloc(sizeof(ETD));
	//'\0' é o NULL do char
	p->valor = '\0';
	p->prox = (CRTR*) NULL;
	return p;
}

ETD* sinal(ETD* palavra){
	char n;
	while(1){
		scanf(" %c", &n);
		if((n == '+')||(n == '-')){
			palavra->valor = n;
			palavra->prox = (CRTR*) NULL;
			break;
		}
		else {
			//repete o print duas vezes, n sei pq
			printf("\e[31mDigite um valor válido para o sinal:\n\e[m");
		}
	}
	return palavra;
}
void validCarac(ETD* pal, CRTR** num, char carac){
	CRTR *aux = (CRTR*) malloc(sizeof(CRTR));
	aux->car = carac-48;
	aux->prox = (CRTR*) NULL;
	pal->ult = aux;
	if(!*num){
		aux->ant = (CRTR*) NULL;
		*num = aux;
	} else{
		CRTR *o;
		*num = andarFinal(*num);
		(*num)->prox = aux;
		aux->ant = *num;
	}
}
ETD* addCarac(ETD* palavra){
	CRTR *num, *aux;
	num = palavra->prox;
	char m;
	while(1){
		scanf("%c", &m);
		if(m == 48){
			if(num)
				validCarac(palavra, &num, m);
		}
		else if((m >= 49)&&(m <= 57)){
			validCarac(palavra, &num, m);
		}
		else if(m == '\n'){
			break;
		}
	}
	palavra->prox = num;
	return palavra;
}
	//cria efetivamente o caracter
ETD* criaCarac(ETD* palavra){
	//add o sinal do número
	printf("\n\e[33mDigite o número com o sinal: \e[m\n");
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

void escreveAlg(CRTR* lista){
	CRTR *p = lista;
	while(p){
		printf("%d", p->car);
		p = p->prox;
	}
	printf("\n");
}

void liberaCarac(ETD* lixo){
	CRTR *q, *p = lixo->prox;
	free(lixo);
	while(p){
		q = p->prox;
		free(p);
		p = q;
	}
}

void liberaAlg(CRTR* lixo){
	CRTR* q;
	while(lixo){
		q = lixo->prox;
		free(lixo);
		lixo = q;
	}
}

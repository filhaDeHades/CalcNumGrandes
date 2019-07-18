#include "2. etd.h"


//---------------------------------- Usando os caracteres de entrada -------------------------------------

//Tira os zeros a esquerda do número
void tiraZero(ETD* num){
	CRTR *p, *q = num->prim;
	while((q->car)&&(q->car == 0)){
		p = q;
		q = q->prox;
		num->prim = q;
		free(p);
	}
}

//Menu do programa
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

//---------------------------------------- Funções de Suporte --------------------------------------------
//Retorna o último algarismo do número
CRTR* andarFinal(CRTR* palavra){
	if(palavra)
		while(palavra->prox)
			palavra = palavra->prox;
	return palavra;
}

//inserir os números invertidos
CRTR* insC(CRTR* lista, int n){
	CRTR* novo = (CRTR*)malloc(sizeof(CRTR));
	novo->car = n;
	novo->ant = (CRTR*) NULL;
	novo->prox = lista;
	if(lista) lista->ant = novo;
	return novo;
}

//inverte os números
CRTR* invC(CRTR* num){
	CRTR *inv = (CRTR*) NULL;
	CRTR *fim = num;
	while(fim){
		inv = insC(inv, fim->car);
		fim = fim->prox;
	}
	return inv;
}

//Cria uma lista com os números já invertidos
ETD* insereComeco(ETD* palavra, int num){
	CRTR *novo = (CRTR*)malloc(sizeof(CRTR));
	novo->car = num;
	novo->ant = NULL;
	novo->prox = palavra->prim;
	if (palavra->prim)
		palavra->prim->ant = novo;
	else
		palavra->ult = novo;
	palavra->prim = novo;
}

//------------------------------------------ Inicializadores ----------------------------------------------
//Inicializa a estrutura ETD
ETD* inicializaSinal(void){
	ETD* p = (ETD*)malloc(sizeof(ETD));
	//'\0' é o NULL do char
	p->valor = '\0';
	p->prim = (CRTR*) NULL;
	return p;
}

//Inicializa a estrutura CRTR
CRTR* inicializaCarac(int n){
	CRTR* q = (CRTR*)malloc(sizeof(CRTR));
	q->ant = (CRTR*) NULL;
	q->car = n; //estamos lidando com int, não char, logo não há a necessidade de diminuir 48
	q->prox = (CRTR*) NULL;
	return q;
}

//Adiciona os valores a estrutura
ETD* inicializacaoCarac(int n){
	ETD* palavra = inicializaSinal();
	printf("\e[32mDigite o %dº número: \e[m", n);
	palavra = criaCarac(palavra);
	printf("\n");
	return palavra;
}
//--------------------------------- Adicionando algarismos a estrutura ------------------------------------
//Adiciona o valor do sinal a estrutura
ETD* sinal(ETD* palavra){
	char n;
	while(1){
		scanf(" %c", &n);
		if((n == '+')||(n == '-')){
			palavra->valor = n;
			palavra->prim = (CRTR*) NULL;
			break;
		}
		else {
			//repete o print duas vezes, n sei pq
			printf("\e[31mDigite um valor válido para o sinal:\n\e[m");
			continue;
		}
	}
	return palavra;
}

//Valida o caracter que será adicionado na estrutura
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
		o = andarFinal(*num);
		o->prox = aux;
		aux->ant = o;
	}
}

//Adiciona o valor de número na estrutura
ETD* addCarac(ETD* palavra){
	CRTR *num;
	num = palavra->prim;
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
	palavra->prim = num;
	return palavra;
}

//Cria efetivamente o caracter
ETD* criaCarac(ETD* palavra){
	//add o sinal do número
	printf("\n\e[33mDigite o número com o sinal: \e[m\n");
	palavra = sinal(palavra);

	//add os caracteres do número
	palavra->prim = (CRTR*) NULL;
	palavra = addCarac(palavra);
	if(palavra->prim == (CRTR*) NULL){
		CRTR* o = (CRTR*)malloc(sizeof(CRTR));
		o->car = 0;
		o->ant = (CRTR*) NULL;
		o->prox = (CRTR*) NULL;
		palavra->prim = o;
		palavra->ult = o;
	}
	return palavra;
}

//------------------------------------- Printando os números ----------------------------------------------
//Printando a estrutura principal
void escreveCarac(ETD* palavra){
	ETD *p = palavra;
	CRTR *q = palavra->prim;
	printf("%c", p->valor);
	while(q){
		printf("%d", q->car);
		q = q->prox;
	}
	printf("\n");

}

//Printando os algarismos
void escreveAlg(CRTR* lista){
	CRTR *p = lista;
	while(p){
		printf("%d", p->car);
		p = p->prox;
	}
	printf("\n");
}

//------------------------------------------ Liberação ----------------------------------------------------
//Libera a estrutura toda
void liberaCarac(ETD* lixo){
	CRTR *q, *p = lixo->prim;
	free(lixo);
	while(p){
		q = p->prox;
		free(p);
		p = q;
	}
}

//Libera apenas os caracteres
void liberaAlg(CRTR* lixo){
	CRTR* q = lixo, *p = lixo;
	while(q){
		p = q;
		q = p->prox;
		free(p);
	}
}

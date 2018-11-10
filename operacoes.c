#include "operacoes.h"
// #include "2. etd.h"

int maiorMagnitude(ETD* num1, ETD* num2){

	CRTR* n1 = num1->prox, *n2 = num2->prox;
	int maior=-1;


	while(1){
		if (n1->prox!=NULL && n2->prox==NULL){ //n1 possui mais caracteres
			maior = 1;
			return maior;
		}
		else if (n2->prox!=NULL && n1->prox==NULL){ //n2 possui mais caracteres
			maior = 2;
			return maior;
		}
		else if ((n2->prox==NULL && n1->prox==NULL) && (n1->car==n2->car)){
			return maior;
		}else{
			if (n1->car>n2->car) {
				maior = 1;
			}
			else if (n1->car<n2->car) maior = 2;
			else if (n1->car==n2->car){
				if (maior==-1) maior = 0;
			}
			if (n2->prox!=NULL && n1->prox!=NULL){
				n1 = n1->prox;
				n2 = n2->prox;
			} else return maior;
		}
		if (n1->prox!=NULL && n2->prox==NULL){ //n1 possui mais caracteres

		}
	}
}

ETD* divide(ETD* num1, ETD* num2){

	ETD* n1 = num1, *n2 = num2;
	ETD* resp = (ETD*)malloc(sizeof(ETD)); //criando lista que retorna o resultado
	ETD* contador = (ETD*)malloc(sizeof(ETD));
	contador->prox = insC(contador->prox, 0);
	contador->valor = '+';
	ETD* somar = (ETD*)malloc(sizeof(ETD));
	somar->prox = insC(somar->prox, 0);
	somar->valor = '+';
	ETD* somador = (ETD*)malloc(sizeof(ETD));
	somador->prox = insC(somador->prox, 1);
	somador->valor = '+';
	n1->valor = '+';
	n2->valor = '+';

	//sinal resposta
	if(num1->valor == '+' && num2->valor == '-') resp->valor = '-';
	else resp->valor = '+';

	//verificando qual numero é maior
	int maior = maiorMagnitude(n1, n2);
	if(maior==0 || maior==2){ 
		if (maior = 0) resp->prox = insC(resp->prox, 1);
		else resp->prox = insC(resp->prox, 0);
		return resp;
	}

	somar->prox = invC(somar->prox);
	do{
		somar = soma(somar, n2);
		somar->prox = invC(somar->prox);
		maior = maiorMagnitude(somar, n1);
		if (maior == 1)
			break;
		contador->prox = invC(contador->prox);
		contador = soma(contador, somador);

	}while(maior==2);

	resp->prox = contador->prox;

	return resp;
}

ETD* soma(ETD* num1, ETD* num2){
	
	ETD* resp = (ETD*)malloc(sizeof(ETD)); //criando lista que retorna o resultado
	
	if (num1->valor=='+' && num2->valor=='-'){
		// resp = subtrai(num1, num2);
		return resp;	
	} 
	else if(num1->valor='-' && num2->valor=='-') resp->valor = '-';
	else if(num1->valor='+' && num2->valor=='+') resp->valor = '+';
	else{
		// resp = subtrai(num2, num1);
		return resp;
	}

	int soma = 0, vaiProProximo = 0;

	CRTR* n1 = num1->prox, *n2 = num2->prox;
	int c=0, aux=-1;

	// n1 = andarFinal(n1);
	// n2 = andarFinal(n2);

	while(1){

		if(n1->prox==NULL && c==1 && aux!=1){
			soma = n2->car + vaiProProximo;
			if(soma>9){
				soma = soma - 10;
				vaiProProximo = 1;
			}
			else vaiProProximo = 0;
		}else if(n2->prox==NULL && c==1 && aux!=2){
			soma = n1->car + vaiProProximo;
			if(soma>9){
				soma = soma - 10;
				vaiProProximo = 1;
			}
			else vaiProProximo = 0;
		}
		else{
			soma = n1->car + n2->car + vaiProProximo;
			if(soma>9){
				soma = soma - 10;
				vaiProProximo = 1;
			}
			else vaiProProximo = 0;
		}

		if((n1->prox!=NULL) && (n2->prox==NULL)){ //n1 possui mais casas
			n1 = n1->prox;
			if(n1->prox==NULL) aux = 1;
			c = 1;
		}else if(n2->prox!=NULL && (n1->prox==NULL)){ //n2 possui mais casas
			n2 = n2->prox;
			if(n2->prox==NULL) aux = 2;
			c = 1;
		}else if(n1->prox!=NULL && n2->prox!=NULL){
			n1 = n1->prox;
			n2 = n2->prox;
		}else{
			resp->prox = insC(resp->prox, soma);
			break;
		}

		resp->prox = insC(resp->prox, soma);
		soma = 0;
	}

	if(vaiProProximo==1) resp->prox = insC(resp->prox, vaiProProximo);
	return resp;
}

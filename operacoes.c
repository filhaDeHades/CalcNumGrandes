#include "operacoes.h"
// #include "2. etd.h"

int maiorMagnitude(ETD* num1, ETD* num2){
	CRTR* n1 = num1->prox, *n2 = num2->prox;
	int maior;

	n1 = andarFinal(n1);
	n2 = andarFinal(n2);

	while(1){
		if (n1->ant!=NULL && n2->ant==NULL){ //n1 possui mais caracteres
			maior = 1;
			return maior;
		}
		else if (n2->ant!=NULL && n1->ant==NULL){ //n2 possui mais caracteres
			maior = 2;
			return maior;
		}
		else{
			if (n1->car>n2->car) maior = 1;
			else if (n1->car<n2->car) maior = 2;
			else maior = 0;
			if (n2->ant!=NULL && n1->ant!=NULL){
				n1 = n1->ant;
				n2 = n2->ant;
			} else return maior;
		}
	}
}

ETD* divide(ETD* num1, ETD* num2){
	ETD* n1 = num1, *n2 = num2;
	ETD* resp = (ETD*)malloc(sizeof(ETD)); //criando lista que retorna o resultado
	CRTR* contador = (CRTR*)malloc(sizeof(CRTR));
	contador = inicializaCarac(0);
	CRTR* somador = (CRTR*)malloc(sizeof(CRTR));
	somador = inicializaCarac(1);
	n2->valor = '+';
	n2->valor = '+';

	//sinal resposta
	if(num1->valor == '+' && num2->valor == '-') resp->valor = '-';
	else resp->valor = '+';

	//verificando qual numero é maior
	int maior = maiorMagnitude(n1, n2);
	if(maior==0 || maior==2){ 
		if (maior = 0) insC(resp->prox, '1');
		else insC(resp->prox, '0');
		return resp;
	}

	// while(maiorMagnitude(n1, n2)!=1){
		// n1 = subtrai(n1, n2);
		// contador = soma(contador, somador);
	// }

	resp->prox = contador;

	return resp;
}
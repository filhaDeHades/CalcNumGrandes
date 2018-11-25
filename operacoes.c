#include "operacoes.h"
// #include "2. etd.h"

int maiorMagnitude(ETD* num1, ETD* num2){

	if (num2->prox->car==0){
		if (num1->prox->car!=0)
			return 1;
		else return 0;
	}
	if(num1->prox->car==0){
		if (num2->prox->car!=0)
			return 2;
		else return 0;
	}

	CRTR* n1 = num1->ult, *n2 = num2->ult;
	int maior=-1;

	if (n1->ant==NULL && n2->ant==NULL && n1->car==n2->car){
		maior = 0;
	}

	while(1){
		if (n1->ant!=NULL && n2->ant==NULL){ //n1 possui mais caracteres
			maior = 1;
			return maior;
		}
		else if (n2->ant!=NULL && n1->ant==NULL){ //n2 possui mais caracteres
			maior = 2;
			return maior;
		}
		else if ((n2->ant==NULL && n1->ant==NULL) && (n1->car==n2->car)){
			return maior;
		}else{
			if (n1->car>n2->car) {
				maior = 1;
			}
			else if (n1->car<n2->car) maior = 2;
			else if (n1->car==n2->car){
				if (maior==-1) maior = 0;
			}
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
	resp->prox = NULL;
	ETD* contador = (ETD*)malloc(sizeof(ETD));
	contador->valor = '+';
	contador->prox = NULL;
	contador = insereComeco(contador, 0);
	ETD* somar = (ETD*)malloc(sizeof(ETD));
	somar->prox = NULL;
	somar = insereComeco(somar, 0);
	somar->valor = '+';
	ETD* somador = (ETD*)malloc(sizeof(ETD));
	somador->prox = NULL;
	somador = insereComeco(somador, 1);
	somador->valor = '+';

	//n1 é 0
	if (maiorMagnitude(somar, n1)==0){
		resp->valor = '+';
		resp = insereComeco(resp, 0);
		return resp;
	}

	if(num1->valor == '+' && num2->valor == '-') resp->valor = '-';
	else if (num1->valor == '-' && num2->valor == '+') resp->valor = '-';
	else resp->valor = '+';

	n1->valor = '+';
	n2->valor = '+';

	//verificando qual numero é maior
	int maior = maiorMagnitude(n1, n2);

	if(maior==0 || maior==2){
		if (maior == 0) resp = insereComeco(resp, 1);
		else resp = insereComeco(resp, 0);
		return resp;
	}


	do{
		somar = soma(somar, n2);
		maior = maiorMagnitude(somar, n1);
		if (maior==1) break;
		contador = soma(contador, somador);

	}while(maior==2);

	resp->prox = contador->prox;
	return resp;
}

ETD* soma(ETD* num1, ETD* num2){

	ETD* resp = (ETD*)malloc(sizeof(ETD)); //criando lista que retorna o resultado
	resp->prox = NULL;

	// if (maiorMagnitude(num1, num))

	if (num1->valor=='+' && num2->valor=='-'){
		num2->valor = '+';
		resp = subtrai(num1, num2);
		return resp;
	}
	else if(num1->valor=='-' && num2->valor=='-')
		resp->valor = '-';
	else if(num1->valor=='+' && num2->valor=='+')
		resp->valor = '+';
	else{
		num1->valor = '+';
		resp = subtrai(num2, num1);
		if(maiorMagnitude(num1, num2) == 1) resp->valor = '-';
		return resp;
	}

	int soma = 0, vaiProProximo = 0;

	CRTR* n1 = num1->ult, *n2 = num2->ult;
	int c=0, aux=-1;

	while(1){
		if(n1->ant==NULL && c==1 && aux!=1){ //quando n2 é maior que n1 e está no final
			soma = n2->car + vaiProProximo;
			if(soma>9){
				soma = soma - 10;
				vaiProProximo = 1;
			}
			else vaiProProximo = 0;
		}else if(n2->ant==NULL && c==1 && aux!=2){ //quando n1 é maior que n1 e está no final
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

		if((n1->ant!=NULL) && (n2->ant==NULL)){ //n1 possui mais casas
			n1 = n1->ant;
			if(n1->ant==NULL) aux = 1;
			c = 1;
		}else if(n2->ant!=NULL && (n1->ant==NULL)){ //n2 possui mais casas
			n2 = n2->ant;
			if(n2->ant==NULL) aux = 2;
			c = 1;
		}else if(n1->ant!=NULL && n2->ant!=NULL){
			n1 = n1->ant;
			n2 = n2->ant;
		}else{
			resp = insereComeco(resp, soma);
			break;
		}
		resp = insereComeco(resp, soma);
		soma = 0;
	}

	if(vaiProProximo==1) resp = insereComeco(resp, vaiProProximo);
	return resp;
}

ETD* subtrai(ETD* num1, ETD* num2){
	int maior =  maiorMagnitude(num1, num2), num = 0, emprest = 0;

	ETD* numb1 = num1, *numb2 = num2; // para não modificar os valores iniciais
	ETD* resp = (ETD*)malloc(sizeof(ETD)); //lista resultante
	resp->prox = NULL;
	resp->ult = NULL;

	if (maior == -1){
		printf("erro ao comparar magnitudes\n");
		return resp;
	}
	else if (maior == 0) { // são iguais
		resp->valor = '+';
		resp = insereComeco(resp, num); // resp é zero
		return resp;
	}
	// sinais
	if (((num1->valor == '+') && (num2->valor == '-')) || // num1 + num2
		((num1->valor == '-') && (num2->valor == '+'))){ // -(num1 + num2) ou -num1 -num2
		num2->valor = num1->valor;
		resp = soma(num1, num2);
		return resp;
	}
	else if (num2->valor == '-') num2->valor = '+';
	else if (num2->valor == '+') num2->valor = '-';

	if (maior == 1) resp->valor = num1->valor;
	else if (maior == 2){
		resp->valor = num2->valor;
		numb1 = num2;
		numb2 = num1;
	}

	CRTR* n1 = numb1->ult, *n2 = numb2->ult; //start pelo fim

	while ((n1 != NULL) && (n2 != NULL)){ // enquanto ambos tiverem caracteres
		if ((n1->car >= n2->car) && (emprest == 0)){ // só vai subtrair normalmente se não for necessário pegar emprestado
			num = n1->car - n2->car;
			resp = insereComeco(resp, num);
			n1 = n1->ant; // andando do menor significativo pro maior
			n2 = n2->ant;
		}
		else if ((n1->car > n2->car) && (emprest == 1)){
			n1->car -= 1; // subtrai do emprestimo feito
			emprest = 0;
			num = n1->car - n2->car;
			resp = insereComeco(resp, num);
			n1 = n1->ant;
			n2 = n2->ant;
		}
		else{ // n1->car < n2->car => pegar emprestado (n1 < n2) || (n1 <)
			if (n1->ant->car >= 1) n1->ant->car -= 1;
			else emprest = 1; // armazenar a informação de q em algum momento será preciso pegar emprestado de um número >= 1
			n1->car += 10;
			num = n1->car - n2->car;
			resp = insereComeco(resp, num);
			n1 = n1->ant;
			n2 = n2->ant;
		}
	}

	if ((n1) && (!n2)){ // quando não houver mais n2 (maior == 1)
		while (n1){
			if ((n1->car > 0) && (emprest == 1)){
				n1->car -= 1;
				emprest = 0;
			}
			num = n1->car;
			resp = insereComeco(resp, num);
			n1 = n1->ant;
		}
	}
	else if ((!n1) && (n2)){ // quando não houver mais n1 (maior == 2)
		while (n2){
			num = n2->car;
			resp = insereComeco(resp, num);
			n2 = n2->ant;
		}
	}

	return resp;
}

ETD * multiplica(ETD* num1, ETD* num2){
	ETD* n1 = num1, *n2 = num2;
	ETD* resp = (ETD*)malloc(sizeof(ETD)); //criando lista que retorna o resultado
	resp->prox = NULL;
	ETD* contador = (ETD*)malloc(sizeof(ETD));
	contador->valor = '+';
	contador->prox = NULL;
	contador = insereComeco(contador, 0);
	ETD* somar = (ETD*)malloc(sizeof(ETD));
	somar->prox = NULL;
	somar = insereComeco(somar, 0);
	somar->valor = '+';
	ETD* somador = (ETD*)malloc(sizeof(ETD));
	somador->prox = NULL;
	somador = insereComeco(somador, 1);
	somador->valor = '+';

	if(num1->valor == '+' && num2->valor == '-') resp->valor = '-';
	else if (num1->valor == '-' && num2->valor == '+') resp->valor = '-';
	else resp->valor = '+';

	n1->valor = '+';
	n2->valor = '+';

	int maior = maiorMagnitude(contador, n2);
	if(maior==0){
		resp = insereComeco(resp, 0);
		return resp;
	}
	maior = maiorMagnitude(contador, n1);
	if(maior==0){
		resp = insereComeco(resp, 0);
		return resp;
	}

	do{
		somar = soma(somar, n1);
		contador = soma(contador, somador);
		maior = maiorMagnitude(contador, n2);
	}while(maior!=0);

	resp->prox = somar->prox;

	return resp;
}

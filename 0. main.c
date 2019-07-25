
#include "operacoes.h"


int main(void){
	ETD *carc1 = inicializacaoCarac(1);
	ETD *carc2 = inicializacaoCarac(2);


	CRTR  *inv2;
	char oper;
	oper = operacao();
	printf("Operação: %c", oper);
	printf("\n");

	if((oper == '+')||(oper == '-')){
		if(oper == '+') printf("\nResultado da Soma:\n");
		else printf("\nResultado da Subtração:\n");
		ETD *resp = verifica(carc1, carc2, oper);
		escreveCarac(resp);
		liberaCarac(resp);
		printf("\n");


	} else if(oper == '*'){
		printf("\nResultado da Multiplicação:\n");
		ETD *multiplicando = multiplica(carc1, carc2);
		escreveCarac(multiplicando);
		liberaCarac(multiplicando);
		printf("\n");


	} else if(oper == '/'){
		printf("\nResultado da Divisão:\n");
		ETD* zero = (ETD*)malloc(sizeof(ETD));
		zero = insereComeco(zero, 0);
		if(maiorMagnitude(zero, carc2)!=0){
			ETD *dividindo = divide(carc1, carc2);
			escreveCarac(dividindo);
			liberaCarac(dividindo);
		}
		else printf("Não podemos dividir numero por 0");
		liberaCarac(zero);
		printf("\n");

	}
	liberaCarac(carc1);
	liberaCarac(carc2);
}

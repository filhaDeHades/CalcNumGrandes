
#include "operacoes.h"


int main(void){
	ETD *carc1 = inicializacaoCarac(1);
	ETD *carc2 = inicializacaoCarac(2);


	CRTR  *inv2;
	char oper;
	oper = operacao();
	printf("Operação: %c", oper);
	jump

	if((oper == '+')||(oper == '-')){
		if(oper == '+') printf("\nResultado da Soma:\n");
		else printf("\nResultado da Subtração:\n");
		ETD *resp = verifica(carc1, carc2, oper);
		tiraZero(resp);
		escreveCarac(resp);
		liberaCarac(resp);
		jump

	} else if(oper == '*'){
		printf("\nResultado da Multiplicação:\n");
		ETD *multiplicando = multiplica(carc1, carc2);
		escreveCarac(multiplicando);
		liberaCarac(multiplicando);
		jump

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
		jump

	}
	liberaCarac(carc1);
	liberaCarac(carc2);
}

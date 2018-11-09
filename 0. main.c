// #include "2. etd.h"
// #include "1. ng.h"
#include "operacoes.h"

int main(void){

	ETD *carc1 = inicializacaoCarac(1);
	ETD *carc2 = inicializacaoCarac(2);
	CRTR *inv1, *inv2;
	char oper;

	oper = operacao();
	printf("Operação: %c", oper);

	printf("\nNum1\n");
	escreveCarac(carc1);
	printf("\nNum2:\n");
	escreveCarac(carc2);

	inv1 = invC(carc1->prox);
	printf("\nNum1 inverso:\n");
	escreveAlg(inv1);
	inv2 = invC(carc2->prox);
	printf("\nNum2 inverso:\n");
	escreveAlg(inv2);

	liberaCarac(carc1);
	liberaCarac(carc2);
	liberaAlg(inv1);
	liberaAlg(inv2);

	NG* num1 = inicializacao(num1, 1);
	NG* num2 = inicializacao(num2, 2);

	printf("\e[33mComo foi enviado:\n\e[m");
	escreverNum(inverteNum(num1), 1);
	escreverNum(inverteNum(num2), 2);
	printf("\n");
	printf("\e[33mComo o número está armazenado:\n\e[m");
	escreverNum(num1, 1);
	escreverNum(num2, 2);
}

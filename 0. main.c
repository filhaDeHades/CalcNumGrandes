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
}

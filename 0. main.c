#include "2. etd.h"
#include "1. ng.h"

int main(void){
	ETD *carc1 = inicializacaoCarac(1);
	ETD *carc2 = inicializacaoCarac(2);

	printf("\nNum1\n");
	escreveCarac(carc1);
	printf("\nNum2:\n");
	escreveCarac(carc2);


	/*NG* num1 = inicializacao(num1, 1);
	NG* num2 = inicializacao(num2, 2);

	printf("\e[33mComo foi enviado:\n\e[m");
	escreverNum(inverteNum(num1), 1);
	escreverNum(inverteNum(num2), 2);
	printf("\n");
	printf("\e[33mComo o número está armazenado:\n\e[m");
	escreverNum(num1, 1);
	escreverNum(num2, 2);*/
}

// #include "2. etd.h"
// #include "1. ng.h"
#include "operacoes.h"
#define oi printf("oi\n");


int main(void){
	ETD *carc1 = inicializacaoCarac(1);
	ETD *carc2 = inicializacaoCarac(2);
	CRTR  *inv2;
	char oper;

	oper = operacao();
	printf("Operação: %c", oper);
	printf("\n");

	printf("%d\n", carc1->ult->car);
	printf("\nNum1\n");
	escreveCarac(carc1);
	printf("\nNum2:\n");
	escreveCarac(carc2);

	if(oper == '+'){
		printf("\nResultado da Soma:\n");
		ETD *somamdo = soma(carc1, carc2);
		escreveCarac(somamdo);
		printf("\n");
	} else if(oper == '-'){
		printf("\nResultado da Subtração:\n");
		/*ETD *subtraindo = subtrai(carc1, carc2);
		escreveCarac(subtraindo);*/
		printf("\n");
	} else if(oper == '*'){
		printf("\nResultado da Multiplicação:\n");
		/*ETD *multiplicando = multiplica(carc1, carc2);
		escreveCarac(multiplicando);*/
		printf("\n");
	} else if(oper == '/'){
		printf("\nResultado da Divisão:\n");
		/*ETD *dividindo = divide(carc1, carc2);
		escreveCarac(dividindo);*/
		printf("\n");
	}

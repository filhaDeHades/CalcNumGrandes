// #include "2. etd.h"
// #include "1. ng.h"
#include "operacoes.h"


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
		ETD zero = (ETD*)malloc(sizeof(ETD));
		zero = insereComeco(zero, 0);
		if(maiorMagnitude(zero, carc2)!=0){
			ETD *subtraindo = subtrai(carc1, carc2);
			escreveCarac(subtraindo);
		}
		else printf("Não podemos dividir numero por 0");
		printf("\n");
	} else if(oper == '*'){
		printf("\nResultado da Multiplicação:\n");
		ETD *multiplicando = multiplica2(carc1, carc2);
		escreveCarac(multiplicando);
		printf("\n");
	} else if(oper == '/'){
		printf("\nResultado da Divisão:\n");
		ETD *dividindo = divide(carc1, carc2);
		escreveCarac(dividindo);
		printf("\n");
	}
}

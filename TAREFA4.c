#include <stdio.h>
#include <locale.h>
#include <stdlib.h>

int main()
{
	setlocale(LC_ALL,"");
	
	float valor_passagem, arrecadacao[10] , arrecadacao_total=0;
	int viagem, qtd_passageiro[10] ;
	
	printf("* PREFEITURA *");
	printf("\nInforme o valor da passagem => ");
	scanf("%f",&valor_passagem);
	
	for (viagem=0; viagem<10; viagem=viagem+1) {
		printf("\nInforme a quantidade de passageiros da viagem %i => ", (viagem+1));
		scanf("%i",&qtd_passageiro[viagem]);
		arrecadacao[viagem] = qtd_passageiro[viagem] * valor_passagem;
	}
	
	printf("* RESULTADO *");
	printf("\nValor do bilhete => %f", valor_passagem);
	for (viagem=0; viagem<10; viagem=viagem+1) {
		printf("\nA viagem %i teve %i com arrecadação de %f ", (viagem+1), qtd_passageiro[viagem], arrecadacao[viagem]);
		arrecadacao[viagem] = qtd_passageiro[viagem] * valor_passagem;
		arrecadacao_total = arrecadacao_total + arrecadacao[viagem];
		
		}
	printf("\nA arrecadação total foi %f ", arrecadacao_total );
	
}
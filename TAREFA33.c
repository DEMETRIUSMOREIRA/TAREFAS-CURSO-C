#include <stdio.h>
#include <locale.h>
#include <stdlib.h>

int main()
{
	setlocale(LC_ALL,"");
	
	char nomealu[5][60];
	float notas_alu[5][4], med[5], total[5], soma=0;
	int opcao=-1, cont1=0, contnotas=0, opcao2=-1;
	char op;
	
	while (opcao != 0) {
		printf("* SISTEMA DE ENTRADA DE NOTA *");
		printf("\n** ESCOLHA A OPÇÃO DESEJADA **");
		printf("\n1- Informar nome dos alunos");
		printf("\n2- Entrar com as notas dos alunos");
		printf("\n3- Calcular Nota total e Media dos alunos");
		printf("\n4- Resultado final da nota");
		printf("\n5- Editar nota do aluno");
		printf("\n0- Sair do sistema");
		printf("\n => ");
		scanf("%d",&opcao);	
		
		switch (opcao) {
		   	case 1: /* Leu 5 nomes e gravou em nomealu */
		   		printf("\n** 1- Informar nome dos alunos **\n");
		   		cont1=0;
    	        while (cont1<5) {
		          printf("\nInforme nome do aluno %i: ", (cont1+1) );      
		          scanf("%s",nomealu [cont1] );
		          printf("aluno gravado: %s",nomealu [cont1]);
		          cont1++;
                }
                printf("\n\n");      
		   		break;
		   	case 2: /* fez for passando pelos 5 nomes e pedindo 4 notas para cada */
		   		printf("\n** 2- Entrar com as notas dos alunos **\n");
		   	    for (cont1=0;cont1<5;cont1=cont1+1) {
		   	    	contnotas = 0;
				  	printf("\n* Informe as notas do aluno %s *\n", nomealu[cont1] ); 
					while (contnotas<4) {
						printf("\nInforme a %iª nota: ", (contnotas+1)  );      
						scanf("%f", &notas_alu[cont1][contnotas] );
						printf("\nA nota digitada foi %f ", notas_alu[cont1][contnotas] );      
						if (notas_alu[cont1][contnotas] >=0 && notas_alu[cont1][contnotas]<=10) {
							contnotas = contnotas + 1;
						} else {
							printf(" --> ERRO: A nota informada é inválida, informe valor de 0 a 10.\n");	
						}
	                }  
			    }
			    printf("\n\n");  
			    break;
			case 3: /* Passou pelos 5 nomes e calculou a media e total */
				printf("\n** 3- Calcular Nota total e Media dos alunos **\n");
				for (cont1=0;cont1<5;cont1=cont1+1) {
		   	    	soma=0;
				  	printf("\n* Totalizando aluno %s *\n", nomealu[cont1] ); 
					for (contnotas=0;contnotas<4;contnotas=contnotas+1) {
						printf("%iª nota: %f | ", (contnotas+1), notas_alu[cont1][contnotas]  );      
						soma = soma + notas_alu[cont1][contnotas];
	                }  
	                total[cont1] = soma;
	                med[cont1] = soma / 4;
	                printf("\nNota Total: %f | Nota Média: %f \n", total[cont1], med[cont1] );      
			    }
			    printf("\n\n");
				break;
			case 4: /* Passou pelo 5 nomes e mostrou a situaçaõ (aprovado / recuperação / reprovado) */
				printf("\n** 4- Resultado final da nota **\n");
				for (cont1=0;cont1<5;cont1=cont1+1) {
		   	    	soma=0;
				  	printf("\n* Totalizando aluno %s *\n", nomealu[cont1] ); 
					for (contnotas=0;contnotas<4;contnotas=contnotas+1) {
						printf("%iª nota: %f | ", (contnotas+1), notas_alu[cont1][contnotas]  );      
	                }  
	                printf("\nNota Total: %f | Nota Média: %f ", total[cont1], med[cont1] );      
					if (med[cont1]<4) {
						printf(" | REPROVADO");    	
					} else if (med[cont1]<6) {
						printf(" | RECUPERAÇÃO");    	
					} else {
						printf(" | APROVADO");    	
					}
	                printf("\n");  
			    }
			    printf("\n\n");
				break;
			case 5: /* motra os nomes em um menu e permite editar as 4 notas do aluno selecionado */
				printf("\n** 5- Editar nota do aluno **\n");
				while (opcao2 != 0) {
					printf("* ESOLHA O ALUNO *");	
					for (cont1=0;cont1<5;cont1=cont1+1) {
				  		printf("\n%i - Editar nota do aluno %s", (cont1+1) , nomealu[cont1] );
				  	}
				  	printf("\n0 - Sair da edição de notas");
				  	printf("\n => ");
					scanf("%d",&opcao2);
					if (opcao2>=1 && opcao2<=5) {
						cont1 = opcao2-1;
						printf("\n* Você está editando a nota do aluno %s *\n", nomealu[cont1] );
						contnotas = 0;
						soma=0;
						while (contnotas<4) {
							printf("\nA %iª nota é %f, informe a nota nota: ", (contnotas+1), notas_alu[cont1][contnotas] );      
							scanf("%f", &notas_alu[cont1][contnotas] );
							printf("\nA nota digitada foi %f ", notas_alu[cont1][contnotas] );      
							if (notas_alu[cont1][contnotas] >=0 && notas_alu[cont1][contnotas]<=10) {
								soma = soma + notas_alu[cont1][contnotas];
								contnotas = contnotas + 1;
							} else {
								printf(" --> ERRO: A nota informada é inválida, informe valor de 0 a 10.\n");	
							}
		                }  	
						total[cont1] = soma;
	                    med[cont1] = soma / 4;					
					} else {
						printf("\n Opção inválida. Escolha a opção conforme o menu abaixo\n");	
					}
				}
				break;
			case 0: //OK
				break;
			default: //OK 
				printf("\n Opção inválida. Escolha a opção conforme o menu abaixo\n");
				break;
		}		
	}
	printf("\nVocê saiu");
}
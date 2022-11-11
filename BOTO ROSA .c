#include <stdio.h>
#include <locale.h>
#include <stdlib.h>
#include <string.h>

int logado = 0, menu=0, submenu=0, x;

typedef struct // Cria uma STRUCT para armazenar os dados de uma pessoa
{
	char nome_passageiro [60], email_passageiro [100], local_embarque[40], local_desembarque[40], dt_nascimento[10], cpf_passageiro[11];
	int codigo_embarque, usado;
} Embarque; 

typedef struct // Cria uma STRUCT para armazenar os dados de uma carga
{
	char descricao [60], local_embarque[40], local_desembarque[40];
	int codigo_embarque, usado;
	float altura, comprimento, profundidade, peso;
} Carga; 

typedef struct // Cria uma STRUCT para armazenar os dados de um tripulante
{
	char nome [60], email[100], cpf[11], dt_nascimento[10];
	int codigo_embarque, usado, patente;
	float altura, comprimento, profundidadade, peso;
} Tripulacao; 

Embarque passageiros[50]; 
Carga cargas[50]; 
Tripulacao funcionarios[50]; 

int telaLogin();
int telaBoasVindas();

int telaMenuPassageiro();
int telaMenuCarga();
int telaMenuTripulacao();
int telaMenuAjuda();
int telaMenuSobre();
int subMenuPassageiro();


int main()
{
	setlocale(LC_ALL,"");
	while (logado==0) {
		logado = telaLogin();
		
	}
	
	if (logado==1) menu=-1; //Ativando menu caso LOGADO
	while (menu!=0) {
		menu = telaBoasVindas();
		submenu = -1;	
		if (menu==1) {
			while (submenu != 0) {
				submenu = telaMenuPassageiro();
			}
		} else if (menu==2) {
			while (submenu != 0) {
				submenu = telaMenuCarga();
			}
		} else if (menu==3) {
			while (submenu != 0) {
				submenu = telaMenuTripulacao();
			}
		} else if (menu==4) {
			submenu = telaMenuAjuda();
		} else if (menu==5) {
			submenu = telaMenuSobre();
		}
	}
	
	
}

int telaLogin() {
	char usuario[10], senha[10];
	printf("* BOTO ROSA - LOGIN *");
	printf("\nInforme o usuário: ");
	scanf("%s",usuario);	
	printf("\nInforme a senha: ");
	scanf("%s",senha);
	if ( strcmp(usuario,"admin")==0 && strcmp(senha,"mudar")==0 ) {
		return 1;
	} else {
		printf("\nERRO - Login inválido\n");
	}
	return 0;
}

int telaBoasVindas() {
	int opcaoEscolhida;
	system("cls");
	printf("* BOTO ROSA - MENU *");
	printf("\n1- Menu Passageiros \n2- Menu Cargas \n3- Menu Tripulação \n4- Ajuda \n5- Sobre \n0- Sair do programa \n=>");
	scanf("%d", &opcaoEscolhida);	
	if (opcaoEscolhida<0 || opcaoEscolhida>5) {
		printf("\nERRO - Opção escolhida não é válida\n");
	} 
	return opcaoEscolhida;
}

int telaMenuPassageiro() {
	int opcaoEscolhida;
	system("cls");
	printf("* BOTO ROSA - MENU PASSAGEIRO *");
	printf("\n1- Cadastrar Passageiro \n2- Excluir Passageiro \n3- Listar Passageiros \n0- Voltar ao Menu Principal\n=>");
	scanf("%d", &opcaoEscolhida);	
	if (opcaoEscolhida == 1) {
		int indice=-1;
		system("cls");
		printf("* BOTO ROSA - CADASTRO PASSAGEIRO *");
		for (x=0; x<50; x++) {
			if (passageiros[x].usado != 1) {
				indice=x;
				break;	
			}
		}
		if (indice>=0) {
			passageiros[indice].usado = 1;
			printf("\nCódigo do embarque: ");  //REPETIR PARA OUTROS DADOS
			scanf("%d", &passageiros[indice].codigo_embarque);  //REPETIR PARA OUTROS DADOS
			printf("\nNome do passageiro: ");  //REPETIR PARA OUTROS DADOS
			scanf("%d", &passageiros[indice].nome_passageiro);  //REPETIR PARA OUTROS DADOS
			printf("\nE-mail do passageiro: ");  
			scanf("%d", &passageiros[indice].email_passageiro); 
			printf("\nLocal de embarque: "); 
			scanf("%d", &passageiros[indice].local_embarque); 
			printf("\nLocal de desembarque: ");  
			scanf("%d", &passageiros[indice].local_desembarque);
			printf("\nData de nascimento: "); 
			scanf("%d", &passageiros[indice].dt_nascimento);
			printf("\nCPF do passageiro: ");  
			scanf("%d", &passageiros[indice].cpf_passageiro); 
			printf("\nCódigo de embarque: "); 
			scanf("%d", &passageiros[indice].codigo_embarque); 
			
			
			//Fazer nome e outros
		} else {
			printf("\nERRO - Limite de passageiros alcançado.\n");
		}
	} else if (opcaoEscolhida == 2) {
		system("cls");
		int indiceExcluir=-1;
		printf("* BOTO ROSA - EXCLUIR PASSAGEIRO *");
		while (indiceExcluir != 0) {
			printf("\nInforme o número do passageiro a ser excluído (1 a 50) ou 0 (zero) para sair: ");
			scanf("%d", &indiceExcluir);
			printf("\nlido: ");
			if (indiceExcluir >= 1 && indiceExcluir <= 50) {
				passageiros[(indiceExcluir-1)].usado = 0;
				indiceExcluir = 0;
				printf("\excluido: ");
			} else if (indiceExcluir!=0 ){
				printf("\nERRO - Número do passageiro é inválido.\n");
			}
		}
	} else if (opcaoEscolhida == 3) {
		system("cls");
		int indiceExcluir=-1;
		printf("* BOTO ROSA - LISTAR PASSAGEIROS *");
		for (x=0; x<50; x++) {
			if (passageiros[x].usado == 1) {
				printf("\nPOSIÇÃO %d - Com Passageiro", (x+1) );
				printf("\nCódigo do embarque: %d", passageiros[x].codigo_embarque); //REPETIR PARA OUTROS DADOS
				printf("\nNome do Passageiro: %d", passageiros[x].nome_passageiro); //REPETIR PARA OUTROS DADOS
				
				printf("\nE-mail do passageiro: %d", passageiros[x].email_passageiro); 
				printf("\nLocal de embarque: %d", passageiros[x].local_embarque); 
				printf("\nLocal de desembarque: %d", passageiros[x].local_desembarque); 
				printf("\nData de nascimento: %d", passageiros[x].nome_passageiro); 
				printf("\nCPF do passageiro: %d", passageiros[x].cpf_passageiro); 
				printf("\nCódigo de embarque: %d", passageiros[x].codigo_embarque); 
				
				//Mostrar dados
			} else {
				printf("\nPOSIÇÃO %d - Sem Passageiro", (x+1) );
			}
		}
		printf("\n");	
		system("pause");	
	} else if (opcaoEscolhida<0 || opcaoEscolhida>3) {
		printf("\nERRO - Opção escolhida não é válida\n");
	} 
	return opcaoEscolhida;	
}

int telaMenuCarga() {
	int opcaoEscolhida;
	system("cls");
	printf("* BOTO ROSA - MENU CARGA *");
	printf("\n1-Cadastrar Cargas \n2- Excluir Cargas \n3- Listar cargas \n0- Voltar ao Menu Principal\n=>");
	scanf("%d", &opcaoEscolhida);	
	if (opcaoEscolhida == 1) {
		int indice=-1;
		system("cls");
		printf("* BOTO ROSA - CADASTRO CARGA *");
		for (x=0; x<50; x++) {
			if (cargas[x].usado != 1) {
				indice=x;
				break;	
			}
		}
		if (indice>=0) {
			cargas[indice].usado = 1;
			printf("\nCódigo do embarque: ");  //REPETIR PARA OUTROS DADOS
			scanf("%d", cargas[indice].codigo_embarque);  //REPETIR PARA OUTROS DADOS
			
			printf("\nLocal de embarque: "); 
			scanf("%d", cargas[indice].local_embarque); 
			printf("\nLocal de desembarque: "); 
			scanf("%d", cargas[indice].local_desembarque); 
			printf("\nAltura da mercadoria: ");
			scanf("%d", cargas[indice].altura);
			printf("\nComprimento da mercadoria: ");
			scanf("%d", cargas[indice].comprimento); 
			printf("\nProfundidade da mercadoria: ");
			scanf("%d", cargas[indice].profundidade);
			printf("\nPeso da mercadoria: ");
			scanf("%d", cargas[indice].peso);

			
			//Fazer nome e outros
		} else {
			printf("\nERRO - Limite de carga alcançado.\n");
		}
	} else if (opcaoEscolhida == 2) {
		system("cls");
		int indiceExcluir=-1;
		printf("* BOTO ROSA - EXCLUIR CARGA *");
		while (indiceExcluir != 0) {
			printf("\nInforme o número da carga a ser excluída (1 a 50) ou 0 (zero) para sair: ");
			scanf("%d", &indiceExcluir);
			if (indiceExcluir >= 1 && indiceExcluir <= 50) {
				cargas[(indiceExcluir-1)].usado = 0;
				indiceExcluir = 0;
			} else if (indiceExcluir!=0 ){
				printf("\nERRO - Número da carga é inválido.\n");
			}
		}
	} else if (opcaoEscolhida == 3) {
		system("cls");
		int indiceExcluir=-1;
		printf("* BOTO ROSA - LISTAR CARGAS *");
		for (x=0; x<50; x++) {
			if (cargas[x].usado == 1) {
				printf("\nPOSIÇÃO %d - Carregado", (x+1) );
				printf("\nCódigo do embarque: %d", cargas[x].codigo_embarque); //REPETIR PARA OUTROS DADOS
				printf("\nLocal de embarque: %d", cargas[x].local_embarque);
				printf("\nLocal de desembarque: %d", cargas[x].local_desembarque);
				printf("\nAltura da mercadoria: %d", cargas[x].altura);
				printf("\nComprimento da mercadoria: %d", cargas[x].comprimento);
				printf("\nProfundidade da mercadoria: %d", cargas[x].profundidade);
				printf("\nPeso da mercadoria: %d", cargas[x].peso);
				
				
				//Mostrar dados
			} else {
				printf("\nPOSIÇÃO %d - Descarregado", (x+1) );
			}
			printf("\n");
		}		
	} else if (opcaoEscolhida<0 || opcaoEscolhida>3) {
		printf("\nERRO - Opção escolhida não é válida\n");
	} 
	return opcaoEscolhida;	
}

int telaMenuTripulacao(){
	int opcaoEscolhida;
	system("cls");
	printf("* BOTO ROSA - MENU TRIPULAÇÃO *");
	printf("\n1- Cadastrar Tripulação \n2- Excluir Tripulaççao \n3- Listar tripulação \n0- Voltar ao Menu Principal\n=>");
	scanf("%d", &opcaoEscolhida);	
	if (opcaoEscolhida == 1) {
		int indice=-1;
		system("cls");
		printf("* BOTO ROSA - CADASTRO TRIPULAÇÃO *");
		for (x=0; x<50; x++) {
			if (funcionarios[x].usado != 1) {
				indice=x;
				break;	
			}
		}
		if (indice>=0) {
			funcionarios[indice].usado = 1;
			printf("\nCódigo do embarque: ");  //REPETIR PARA OUTROS DADOS
			scanf("%d", funcionarios[indice].codigo_embarque);  //REPETIR PARA OUTROS DADOS
			
			printf("\nNome do tripulante: ");  
			scanf("%d", funcionarios[indice].nome);
			printf("\nE-mail do tripulante: ");  
			scanf("%d", funcionarios[indice].email);
			printf("\nCPF do tripulante: ");  
			scanf("%d", funcionarios[indice].cpf);
			printf("\nData de nascimento do  tripulante: ");  
			scanf("%d", funcionarios[indice].dt_nascimento);
			printf("\nPatente do tripulante: ");  
			scanf("%d", funcionarios[indice].patente);
			
			//Fazer nome e outros
			} else {
			printf("\nERRO - Limite de tripulação alcançado.\n");
		}
	} else if (opcaoEscolhida == 2) {
		system("cls");
		int indiceExcluir=-1;
		printf("* BOTO ROSA - EXCLUIR TRIPULAÇÃO *");
		while (indiceExcluir != 0) {
			printf("\nInforme o número da tripulação a ser excluída (1 a 50) ou 0 (zero) para sair: ");
			scanf("%d", &indiceExcluir);
			if (indiceExcluir >= 1 && indiceExcluir <= 50) {
				funcionarios[(indiceExcluir-1)].usado = 0;
				indiceExcluir = 0;
			} else if (indiceExcluir!=0 ){
				printf("\nERRO - Número da tripulação é inválido.\n");
			}
		}
	} else if (opcaoEscolhida == 3) {
		system("cls");
		int indiceExcluir=-1;
		printf("* BOTO ROSA - LISTAR TRIPULAÇÃO *");
		for (x=0; x<50; x++) {
			if (funcionarios[x].usado == 1) {
				printf("\nPOSIÇÃO %d - Tripulado", (x+1) );
				printf("\nCódigo do embarque: %d", funcionarios[x].codigo_embarque); //REPETIR PARA OUTROS DADOS
				printf("\nNome do tripulante: %d", funcionarios[x].nome);
				printf("\nE-mail do tripulante: %d", funcionarios[x].email);
				printf("\nCPF do tripulante: %d", funcionarios[x].nome);
				printf("\nData de nascimento do  tripulante %d", funcionarios[x].dt_nascimento);
				printf("\nPatente do tripulante: %d", funcionarios[x].patente);
				//Mostrar dados
			} else {
				printf("\nPOSIÇÃO %d - Sem tripulação", (x+1) );
			}
			printf("\n");
		}		
	} else if (opcaoEscolhida<0 || opcaoEscolhida>3) {
		printf("\nERRO - Opção escolhida não é válida\n");
	} 
	return opcaoEscolhida;	
}

int telaMenuAjuda(){
	int opcaoEscolhida;
	system("cls");
	printf("* BOTO ROSA - MENU AJUDA *");
	printf("\n Versao 1.0A12b n0- Voltar ao Menu Principal\n=>");
	scanf("%d", &opcaoEscolhida);	
	if (opcaoEscolhida<0 || opcaoEscolhida>5) {
		printf("\nERRO - Opção escolhida não é válida\n");
	} 
	return opcaoEscolhida;	
	/*Ajuda (dúvidas gerais de como usar o sistema).*/	
}

int telaMenuSobre(){
	int opcaoEscolhida;
	system("cls");
	printf("* BOTO ROSA - MENU SOBRE *");
	printf("\nEESTE SISTEMA É REFEENTE A ETAPA 5 DE PROGRAMAÇAO EM C++ SISTSEMA DE CONTROLE DE PASSAGEIROS E CARGAS");
	scanf("%d", &opcaoEscolhida);	
	if (opcaoEscolhida<0 || opcaoEscolhida>5) {
		printf("\nERRO - Opção escolhida não é válida\n");
	} 
	return opcaoEscolhida;	
	/*Sobre (versão do sistema, desenvolvido por, sobre o sistema e funcionalidades em geral, direitos reservados, etc.) */	
}
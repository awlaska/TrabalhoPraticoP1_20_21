#include <stdio.h>
#include <stdlib.h>
#include "login.h"

int menu(){
	int opc=0;
	system("cls");
	printf(" 1 - Autenticar \n 2- Criar Utilizador\n");		
	printf("0- Sair\n\n");
	printf(">"); scanf("%i",&opc);
	return opc;
}

int main(int argc, char *argv[]) {

	int opcao=0;
	do{
		opcao = menu();
		switch (opcao){
			case 1: menuUsers(); break;
			case 2: criarUser(); break;
			case 0: system("cls"); printf("\n\t\tA ENCERRAR APLICACAO...\n"); break;
			default: printf("Opcao errada!\n"); system("pause");
		}
	}while(opcao !=0 );
	
	return 0;
}

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#include "login.h"

#define MAX 1000

int loginUser(){
	int i=0, num_utilizadores=0;
	int menu_entrada, login_sucesso;
	USER aceder;
	USER *dados=NULL;
	FILE*fp;
	
	fp=fopen("adms_users.txt", "a+");
	
	if(fp==NULL) {
		printf("ERRO AO ABRIR FICHEIRO"); 
		system("pause");
		return;
	}			
	else{			
		fread(&num_utilizadores, sizeof(int), 1, fp);
		
		dados = (USER*)calloc(num_utilizadores, sizeof(USER));
		
		fread(dados, sizeof(USER), num_utilizadores, fp);
		
		// PROCURA NO FICHEIRO DE TEXTO DADOS EXISTENTES IGUAIS AOS DADOS INSERIDOS
		for(i=0; i < num_utilizadores; i++) {					
			if(strcmp(aceder.username, dados[i].username)==0) {
				if(strcmp(aceder.senha, dados[i].senha)==0) {
					login_sucesso = 1;
				}
			}
	}
	
	fflush(stdin);
	printf("\nIntroduza o tipo de utilizador: (ac-accionista ad-admin)");
	scanf_s("%s", aceder.tipo);
	fflush(stdin);
		
	printf("\nNome de utilizador: ");
	scanf_s("%s", aceder.username);
	printf("\nSenha: ");
	scanf_s("%s", aceder.senha);
	
	if(login_sucesso==1) {
		printf("Bem-vindo(a) %s",aceder.username);
		//atas_menu()
	}
	else{
		printf("Utilizador ou senha errados!!");
		return -1;
	}
	fclose(fp);
	}
	return 0;
}

USER criarUser(){
	int i=0;
	int menu_entrada;
	int num_utilizadores=0;
	int login_sucesso;
	USER aceder;
	USER *dados=NULL;
	USER *fp=NULL;
	
	int entrar=0;
	char aux=0;
		
		printf("\n\n");
			printf("Introduza o nome: ");
			scanf_s("%s", aceder.nome);
			printf("\n\t D - administrador  \t C - acionista");
			printf("\nTipo: ");
			scanf_s("%s", aceder.tipo);
			
			while(strcmp(aceder.tipo, "D") && strcmp(aceder.tipo, "C")) {
				printf("\nIntroduziu um caracter invalido\n");
				printf("\nIntroduza entre estes tipos de utilizador: D - administrador  \t C - acionista\n");
				printf("\nTipo: %s", aceder.tipo);
			}
			fflush(stdin);
			printf("\nIntroduza o ID: ");
			scanf("%s", aceder.username);
			printf("\nIntroduza a senha: ");
            scanf("%s", aceder.senha);
			
			fp=fopen("adms_users.txt", "a");
			
			fread(&num_utilizadores, sizeof(int), 1, fp);
			
			dados = (USER*)calloc(num_utilizadores, sizeof(USER));
			
			fread(dados, sizeof(USER), num_utilizadores, fp);
			
			for(i=0;i<num_utilizadores;i++){
				if(strcmp(aceder.username,dados[i].username)==0){
					entrar=1;
				}
			}
			if(entrar==1){ // CASO EXISTA O DADO INSERIDO IGUAL A UM DADO JA EXISTENTE NO FICHEIRO DE TEXTO, RETORNA VALOR 1
				printf("Nome de utilizador ja existente-> Escolha outro!!!");
			}//  
			else{
				fp = fopen("adms_users->txt","r");
				num_utilizadores++;
				fwrite(&num_utilizadores,sizeof(int),1,fp);
				fclose(fp);
				
				fp = fopen("adms_users.txt","a");
				fwrite(&aceder,sizeof(USER),1,fp);
				fclose(fp);
			}
	return aceder;
}

// cria a instancia do ficheiro utilizadores
int utilizadores() {
	
	int op=0;
	int menu_tipo;
							
	switch(op){
		case 1: {
			loginUser(); break;
		}
					
		case 2: {
			criarUser(); break;
		}	
	}
}

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<locale.h>
#include <login.h>

#define MAX 1000


// struct do utilizador
typedef struct utilizador{
	char nome[100];
	char senha[100];
	char username[100];
	char tipo[2];
	int id_utilizador;
}LOGIN;


// struct elem
typedef struct elem{
    LOGIN info;
    struct elem *seguinte;
} ELEM;


// cria a instancia do ficheiro utilizadores
FILE utilizadores() {
	
	int menu_entrada;
	int i=0, op=0;
	int num_utilizadores=0;
	int menu_tipo;

	LOGIN aceder;
	LOGIN *dados=NULL;
	
	FILE*fp;
			
	printf(" 1 - entrar \n 2- registar");
	printf("\nQual tipo: ");
	scanf_s("%i", &op);
	fflush(stdin);
	menu_entrada:

			
	switch(op){
		case 1: {
			int login_sucesso;
			
			printf("\nNome de utilizador: ");
			scanf_s("%s", aceder.username);
			printf("\nSenha: ");
			scanf_s("%s", aceder.senha);
			
			fp=fopen_s("adms_users.txt", "a+");
				
			if(fp==NULL) {
				printf("ERRO AO ABRIR FICHEIRO");
				return;
			}
			else{
			
				fread(&num_utilizadores, sizeof(int), 1, fp);
				
				dados = (LOGIN*)calloc(num_utilizadores, sizeof(LOGIN));
				
				fread(dados, sizeof(LOGIN), num_utilizadores, fp);
				
				// PROCURA NO FICHEIRO DE TEXTO DADOS EXISTENTES IGUAIS AOS DADOS INSERIDOS
				for(i=0; i < num_utilizadores; i++) {
					
					
					if(strcmp(aceder.utilizador, dados[i].utilizador)==0) {
						if(strcmp(aceder.senha, dados[i].senha)==0) {
							login_sucesso = 1;
						}
					}
				}
				
				if(login_sucesso==1) {
					printf("Bem-vindo(a) %s",aceder.utilizador);
					
				}
				else{
					printf("Utilizador ou senha errados!!");
					goto menu_entrada;
				}
				fclose(fp);
			}
		}
				
		case 2: {
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
				scanf_s("%s", aceder.utilizador);
				printf("\nIntroduza a senha: ");
                scanf_s("%s", aceder.senha);
				
				fp=fopen_s("adms_users.txt", "a");
				
				fread(&num_utilizadores, sizeof(int), 1, fp);
				
				dados = (LOGIN*)calloc(num_utilizadores, sizeof(LOGIN));
				
				fread(dados, sizeof(LOGIN), num_utilizadores, fp);
				
				for(i=0;i<num_utilizadores;i++){
					if(strcmp(aceder.utilizador,dados[i].utilizador)==0){
						entrar=1;
					}
				}
				if(entrar==1){ // CASO EXISTA O DADO INSERIDO IGUAL A UM DADO JA EXISTENTE NO FICHEIRO DE TEXTO, RETORNA VALOR 1
					printf("Nome de utilizador ja existente-> Escolha outro!!!");
				}//  
				else{
					fp = fopen_s("adms_users->txt","r");
					num_utilizadores++;
					fwrite(&num_utilizadores,sizeof(int),1,fp);
					fclose(fp);
					
					fp = fopen_s("adms_users.txt","a");
					fwrite(&aceder,sizeof(LOGIN),1,fp);
					fclose(fp);
				}
			
				break;
			}	
		}
	}


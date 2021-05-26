#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<locale.h>
#include <login.h>

#define MAX 1000

typedef struct utilizador{
	char nome[100];
	char senha[100];
	char username[100];
	char tipo[2];
	int id_utilizador;
}LOGIN;

typedef struct elem{
    LOGIN info;
    struct elem *seguinte;
} ELEM;



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
	scanf("%d", &op);
	fflush(stdin);
	menu_entrada:

			
	switch(op){
			
		case 1: {
					
			int login_sucesso;
			
			printf("\nNome de utilizador: ");
			gets(aceder.username);
			printf("\nSenha: ");
			gets(aceder.senha);
			
			fp=fopen("adms_users.txt", "r");
				
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
				gets(aceder.nome);
				printf("\n\t D - administrador  \t C - acionista");
				printf("\nTipo: ");
				gets(aceder.tipo);
				
				while(strcmp(aceder.tipo, "D") && strcmp(aceder.tipo, "C")) {
					printf("\nIntroduziu car�cter inv�lido\n");
					printf("\nIntroduza entre estes tipos de utilizador: D - administrador  \t C - acionista\n");
					printf("\nTipo: ", aceder.tipo);
				}
				fflush(stdin);
				printf("\nIntroduza o ID: ");
				gets(aceder.utilizador);
				printf("\nIntroduza a senha: ");
				gets(aceder.senha);
				
				fp=fopen("adms_users.txt", "a");
				
				fread(&num_utilizadores, sizeof(int), 1, fp);
				
				dados = (LOGIN*)calloc(num_utilizadores, sizeof(LOGIN));
				
				fread(dados, sizeof(LOGIN), num_utilizadores, fp);
				
				for(i=0;i<num_utilizadores;i++){
					if(strcmp(aceder.utilizador,dados[i].utilizador)==0){
						entrar=1;
					}
				}
				if(entrar==1){ // CASO EXISTA O DADO INSERIDO IGUAL A UM DADO J� EXISTENTE NO FICHEIRO DE TEXTO, RETORNA VALOR 1
					printf("Nome de utilizador j� existente-> Escolha outro!!!");
				}//  
				else{
					fp = fopen("adms_users->txt","r");
					num_utilizadores++;
					fwrite(&num_utilizadores,sizeof(int),1,fp);
					fclose(fp);
					
					fp = fopen("adms_users.txt","a");
					fwrite(&aceder,sizeof(LOGIN),1,fp);
					fclose(fp);
				}
			
				break;
			}	
		}
	}


#include "stdio.h"

// struct do utilizador
typedef struct utilizador{
	char nome[100];
	char senha[100];
	char username[100];
	char tipo[2];
	int id_utilizador;
}USER;


// struct elem
typedef struct elem{
    USER info;
    struct elem *seguinte;
}ELEM;

USER criarUser();
int loginUser();
int utilizadores();

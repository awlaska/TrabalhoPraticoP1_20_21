//
// Created by cicero on 31/05/2021.
//

#include<stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100

typedef struct {
    char local[MAX];
    char data[10];
    char texto[MAX];
}ATA;

typedef struct elem{
    ATA info;
    struct elem *seguinte;
} ELEM;

ATA escreverAta();
void mostrarLista(ELEM *iniLista);
int insereInicio(ELEM **iniLista, ATA info);
void menu();
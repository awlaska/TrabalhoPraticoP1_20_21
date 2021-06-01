//
// Created by cicero on 31/05/2021.
//
#include "blavla.h"

void menu() {
    printf("\n\nMenu");
    printf("\n\n1 - Inserir dados");
    printf("\n2 - Listar");
    printf("\n3 - Insere no Início");
    printf("\n0 - Fechar");
}

ATA escreverAta() {

    ATA ata;

    fflush(stdin);
    printf("\nData: ");
    scanf("%s", ata.data);
    fflush(stdin);

    printf("\nLocal da assembleia: ");
    scanf("%s",ata.local);
    fflush(stdin);

    printf("\n\nIntroduza o texto da ata: ");
    scanf("%s", ata.texto);
    fflush(stdin);

    FILE *fl;
    fl=fopen("ataDaAssembleia.txt", "w");

    if(fl==NULL) {
        printf("\nERRO AO ABRIR ATA");
        return ata;
    }
    fprintf(fl, "Data: %s \nLocal: %s, \n texto: %s",
            ata.data, ata.local, ata.texto);
    fclose(fl);
    printf("sucesso!");

    return ata;
}

void mostrarLista(ELEM *iniLista) {
    ELEM *aux = NULL;

    if(iniLista==NULL) {
        printf("lista vazia\n");
        return;
    }
    else {
        for(aux=iniLista; aux!=NULL; aux=aux->seguinte) {
            printf("%s, %s; %s",
                   iniLista->info.data,
                   iniLista->info.local,
                   iniLista->info.texto);
        }
    }
    return;
}
int insereInicio(ELEM **iniLista, ATA info)
{
    ELEM *novo = NULL;
    novo = (ELEM *)calloc(1, sizeof(ELEM));
    if (novo == NULL)
    {
        printf("OUT of memory!\n");
        return -1;
    }
    novo->info = info;
    novo->seguinte = NULL;
    if (*iniLista == NULL) // Primeiro elemento da lista
    {
        *iniLista = novo;
    }
    else
    {
        novo->seguinte = *iniLista;
        *iniLista = novo;
    }
    return 0;
}
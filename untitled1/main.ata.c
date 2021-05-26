// fazer tudo em uma só função
// fazer as funções de listagem em um ficheiro a parte


#include<stdio.h>
#include<stdlib.h>

typedef struct {
    char local[100];
    char data[10];
    char texto[100];
}ATA;

typedef struct elem{
    ATA info;
    struct elem *seguinte;
} ELEM;


FILE *localAta1() {

    ATA ata;

    printf("\n\nData: ");
    gets(ata.data);
    fflush(stdin);
    printf("\nLocal da assembleia: ");
    gets(ata.local);

    FILE *fl;

    fl=fopen("ataDaAssembleia.txt", "w");

    if(fl==NULL) {
        printf("\nERRO AO ABRIR ATA");
    }
    else {
        fprintf(fl, "Data: %s \nLocal: %s", ata.data, ata.local);
    }

    fclose(fl);

}

FILE *escreverAta1() {

    char texto[100];

    ATA ata;
    FILE *fl;

    fl=fopen("ataDaAssembleia.txt", "a");

    if(fl==NULL) {
        printf("\nERRO AO ABRIR ATA");
    }

    printf("\n\nIntroduza o texto da ata: ");
    scanf("%s", &ata.texto);

    fprintf(fl, "\n\ntexto: %s", ata.texto);
    fflush(stdin);
    fclose(fl);

}

/*
void imprimeLista(ELEM *iniLista)
{
    ELEM *aux = NULL;
    if (iniLista == NULL)
    {
        printf("Lista Vazia!\n");
        return;
    }
    for (aux = iniLista; aux != NULL; aux = aux->seguinte)
    {
        printf("Data: %s\n Local: %s\n", aux->info.data
                                        , aux->info.local);
    }
}
*/

void mostrarLista(ELEM *iniLista)
{
    ELEM * aux = NULL;

    if(iniLista=NULL) {
                printf("Lista vazia\n");
        return;
    }
    else {
        while (iniLista!=NULL) {
                printf("Data: %s//Local: %s", aux->info.data
                                            , aux->info.local);
                iniLista=iniLista->seguinte;
        }
    }
    return;
}
int inserirInicio(ELEM **iniLista, ATA info) {

    ELEM*novo=NULL;

    novo=(ELEM*)calloc(1, sizeof(ELEM));

    if(novo==NULL) {printf("OUT OF MEMORY \n"); return -1;
    }

    novo->info=info;
    novo->seguinte=NULL;

    if(*iniLista==NULL) {

        *iniLista=novo;
    }
    else {
        novo->seguinte=*iniLista;
        (*iniLista)=novo;
    }
    return 0;
}

int main(int argc, const char *argv[]){

    ATA*iniLista = NULL;

    iniLista=localAta1();
    mostrarLista(iniLista);

    
    return 0;
}


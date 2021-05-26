// fazer tudo numa só função
// fazer as funções de listagem num ficheiro a parte

#include<stdio.h>
#include<stdlib.h>
#include <string.h>

// struct da ata
typedef struct ata {
    int numero;
    int dia_assembleia[2];
    int mes_assembleia[2];
    int ano_assembleia[4];
    char local_assembleia[50];
    int lista_acionistas[];
    char estado;
    char texto[1000];
}ATA;


// struct para fazer lista ligada a apontar para o seguinte
typedef struct elem{
    ATA info;
    struct elem *seguinte;
} ELEM;

// cria a instancia do ficheiro ataDaAssembleia
FILE *localAta1() {
        ATA ata;

        printf("\n\nData: ");
        gets(ata.data_assembleia);
        fflush(stdin);
        printf("\nLocal da assembleia: ");
        gets(ata.local_assembleia);

        printf("\n\nDia da assembleia: ");
        gets(ata.dia_assembleia);
        printf("\n\nMês da assembleia: ");
        gets(ata.mes_assembleia);
        printf("\n\nAno da assembleia: ");
        gets(ata.ano_assembleia);
        fflush(stdin);
        printf("\nLocal da assembleia: ");
        gets(ata.local_assembleia);


        FILE *fl;


        fl=fopen("ataDaAssembleia.txt", "a+");

        if(fl==NULL) {
            printf("\nERRO AO ABRIR ATA");
        }
        else {
            fprintf(fl, "%i;%i;%i;%s", *ata.dia_assembleia, *ata.mes_assembleia, *ata.ano_assembleia, ata.local_assembleia);
        }
        fclose(fl);
    }

    // cria a instancia do ficheiro %i.txt
FILE *escreverAta1() {


        char texto[100];
        ATA ata;
        FILE *fl;

        fl=fopen("%i.txt", numero, "a");

        if(fl==NULL) {
            printf("\nERRO AO ABRIR ATA");
        }
        printf("\n\nIntroduza o texto da ata: ");
        scanf("%s", &ata.texto);

        fprintf(fl, "%s", ata.texto);
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


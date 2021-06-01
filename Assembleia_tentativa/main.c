#include "blavla.h"

int main(int argc, const char *argv[]){

	ELEM *iniLista = NULL;
    ATA info, *novo=NULL;
    int menu_escolha;
    int op=0;

    menu_escolha:
    menu();
    printf("\nEscolha uma opção: ");
    scanf("%i", &op);

    switch(op) {
        case 1: {
            escreverAta();

            goto menu_escolha;
        }
        case 2:
            //iniLista = escreverAta();
            mostrarLista(iniLista);
          goto menu_escolha;
        case 3:


            printf("Local : ");
            fflush(stdin);
            scanf("%100[^\n]s",info.local);

            insereInicio(&iniLista,info);

            goto menu_escolha;
        case 0:

            return 0;

    }
    return 0;
}

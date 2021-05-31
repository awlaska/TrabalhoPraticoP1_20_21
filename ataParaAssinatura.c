#include<stdio.h>

// struct ata
typedef struct {
	char local[100];
	char data[10];
}ATA;

// struct para fazer lista ligada a apontar para o seguinte
typedef struct elem{
    ATA info;
    struct elem *seguinte;
} ELEM;

// cria a instancia do ficheiro ataDaAssembleia
FILE localAta1() {
	
	ATA ata;
	
	char texto[100];
	
	printf("\n\nData: ");
	gets(ata.data);
	fflush(stdin);
	printf("\nLocal da assembleia: ");
	gets(ata.local);
	
	FILE *fl;
	
	fl=fopen("ataDaAssembleia.txt", "w");
	
	if(fl==NULL) {
		printf("\nERRO AO ABRIR ATA");
		return;
	}
	fprintf(fl, "Data: %s \nLocal: %s", ata.data, ata.local);
	fclose(fl);	
}

FILE *escreverAta1() {
	
	char texto[100];
	
	FILE *fl;
	
	fl=fopen("ataParaAssinatura.txt", "a");
	
	if(fl==NULL) {
		printf("\nERRO AO ABRIR ATA");
		return;
	}
	
	printf("\n\nIntroduza o texto da ata: ");
	gets(texto);
	
	fprintf(fl, "\n\ntexto: %s", texto);
	fclose(fl);
	
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
	
	localAta1();
	escreverAta1();
	
	return 0;
}

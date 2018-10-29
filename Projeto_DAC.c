#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct aluno {
	char nome[100],ra[8], senha[9];
};
typedef struct aluno Aluno;


Aluno *add(char nom[100],char log[8],char sen[9]){
	Aluno *aux;
	aux=(Aluno*)malloc(sizeof(Aluno));
	strcpy(aux->nome,nom);
	strcpy(aux->ra,log);
	strcpy(aux->senha,sen);
	return aux;
}

void grava(Aluno *aluno){
	FILE *op;
	op=fopen("classe.txt","a");
	fprintf(op,"%s,%s,%s\n",aluno->nome,aluno->ra,aluno->senha);
}

int verifica(char log[8], char sen[9]){
	int cont=0;
	char c, ra[8];
	FILE*arq;
	arq=fopen("classe.txt","r");
	do{
	cont++;
	c=fgetc(arq);
	}while(c!=',');
	fgets(ra,7,arq);
	fseek(arq,cont+8,SEEK_SET);	
	fscanf(arq,"%s",sen);
	return 0;
}


int main(){
	
	
}

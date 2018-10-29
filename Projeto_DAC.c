#include<stdio.h>
#include<stdlib.h>

struct aluno{
	char nome[100],ra[8], senha[9];
};
typedef aluno Aluno;


Aluno *add(char nom[100],char log[8],char sen[9]){
	Aluno *aux;
	aux=(Aluno*)malloc(sizeof(Aluno);
	aux->nome=nom;
	aux->login=log;
	aux->senha=sen;
	return aux;
}

void grava(Aluno *aluno){
	FILE *op;
	op=fopen("classe.txt","a");
	fprintf(op,"%s,%s,%s\n",aluno->nome,aluno->login,aluno->senha);
}

int verifica(char log[8], char sen[9]){
	int cont=0;
	FILE*arq;
	if(arq=fopen("classe.txt","r")==NULL){
		printf("PROBLEMAS NA ABERTURA DO ARQUIVO")
	}
	do{
	while(c=fgetc(arq!=',')){
	cont++;
	}
	fgets(arq,7,login);
	fseek(arq,cont+8,SEEK_SET);	
	fscanf(arq,"%s",&sen)
}


int main(){
	
	
}

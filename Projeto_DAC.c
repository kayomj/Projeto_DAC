#include<stdio.h>
#include<stdlib.h>
#include<string.h>

//Estrutura de aluno
struct aluno {
	char ra[7], nome[100], login[8], senha[9];
};
typedef struct aluno Aluno;

//Função que adiciona um aluno novo
Aluno *Cadastro_aluno(char ra[7], char nome[100], char login[8],char senha[9]){
	Aluno *aux;
	aux=(Aluno*)malloc(sizeof(Aluno));//Reserva espaço na memória
	strcpy(aux->ra,ra);
	strcpy(aux->nome,nome);
	strcpy(aux->login,login);
	strcpy(aux->senha,senha);
	return aux;
}

void grava(Aluno *aluno){
	FILE *op;
	op=fopen("classe.txt","a");
	fprintf(op,"%s,%s,%s,%s\n",aluno->ra,aluno->nome,aluno->login,aluno->senha);
}

int verifica_login(char log[8], char sen[9]){//Valida login do Aluno
	int cont=0, validar_senha, validar_log;
	char c, ra[8],senha[9];
	FILE*arq;
	arq=fopen("Alunos.txt","r");
	do{
		fseek(arq,7,SEEK_CUR);//Pula 7 posições
		do{
			cont++;
			c=fgetc(arq);
		}while(c!=',');//Para na primeira virgula
		fgets(ra,7,arq);//Lê a variável Login do arquivo
		fseek(arq,1,SEEK_CUR);//Pula a virgula faltante
		fscanf(arq,"%s",senha);
		validar_senha=strcmp(sen,senha);
		validar_log=strcmp(log,ra);
		if((validar_log==0 && validar_senha==0)){
			return 0;
		}
	}while(c!=EOF);
	return 1;
}


int main(){
	int opcao, cont_op1, valida_login, sair;
	char login_main[8], senha_main[9];
	printf("Opções:\n 1)Login\n 2)Cadastra-se\n");
	scanf("%d",&opcao);
	switch(opcao){
		case 1:
			for (cont_op1=0;cont_op1<3;cont_op1++){
				printf("Digite seu usuário:\n");
				sgets("%s",&login_main);
				printf("Digite sua senha:\n");
				sgets("%s",&senha_main);
				valida_login=(verifica_login(login_main,senha_main));
				if (valida_login==0){
					do{
						printf("");
						printf("");
						printf("");
					}while(sair!=1);
				}
			}
	}
	
}

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

//Estrutura de aluno
struct aluno {
	char ra[7], nome[100], login[8], senha[9];
};
typedef struct aluno Aluno;

//FunÃ§Ã£o que adiciona um aluno novo
Aluno *Cadastro_aluno(){
	Aluno *aux;
	aux=(Aluno*)malloc(sizeof(Aluno));//Reserva espaÃ§o na memÃ³ria
	scanf("%s",aux->ra);
	printf("%s",aux->ra);
	fflush(stdin);
	fgets(aux->nome, 100, stdin);
	fflush(stdin);
	printf("%s",aux->nome);
	scanf("%s",aux->login);
	printf("%s",aux->login);
	scanf("%s",aux->senha);
	printf("%s",aux->senha);
	return aux;
}

void grava(Aluno *aluno){
	FILE *op;
	op=fopen("C:\\Users\\s092984\\Downloads\\Projeto_DAC-master\\classe.txt","a");
	fprintf(op,"%s,%s,%s,%s\n",aluno->ra,aluno->nome,aluno->login,aluno->senha);
}

int verifica_login(char logx[8], char sen[9]){//Valida login do Aluno
	int cont=0, cont_vir=0, cont_aux, tamanho;
	char linha[100],c, *login,*senha;
	FILE*arq;
	arq=fopen("Alunos.txt","r");
	while (fgets(linha,100,arq)){
		strtok(linha, ",");
		strtok(NULL, ",");
		login=strtok(NULL, ",");
		senha=strtok(NULL, "\n");
		if(strcmp(logx,login)==0 && strcmp(sen,senha)==0) return 0;
	}
	return 1;
}

void Tads_matriculando(){
	
}

int main(){
char c_nome[100], c_ra[7], c_login[8], c_senha[9], c, p, tam[150], tam_1[12], codigo_d[6],ra[7], aux[6], aux_1[6], aux_2[6], percorre[6];
Aluno *a;
FILE *disciplina, *pre_req, ver_aluno ;
disciplina=fopen("C:\\Users\\s092984\\Downloads\\Projeto_DAC-master\\Disciplinas.txt","r");
if(disciplina==NULL){
	printf("erro na abertura do arquivo");
}
pre_req=fopen("C:\\Users\\s092984\\Downloads\\Projeto_DAC-master\\Prerequisitos.txt","r");
		do{
		printf("Digite seu login e senha\n");
		scanf("%s",login);
		scanf("%s",senha);
		autentica = (verifica_login(login,senha));
		printf("Verificou %d\n", autentica);
	}while(autentica==1);
			printf("1-consultar disciplina 2-cadastrar aluno\n");
			int op;
			scanf("%d",&op);
			//edicao solon 
			switch(op){
				case 1: printf("digite o codigo da disciplina\n");
						scanf("%s",codigo_d);
							while(fscanf(disciplina,"%s",tam)){
								for(int i=0;i<5;i++){
									aux[i]=tam[i];
								}
								if(strcmp(aux,codigo_d)==0){
									printf("Disciplina,nome,creditos: %s\n", tam);
									while(fgets(tam_1,12,pre_req)!=NULL){
										for(int i=0;i<=5;i++){
										aux_1[i]=tam_1[i];
										aux_2[i]=tam_1[i+6];
										}
										if(strcmp(codigo_d,aux_2)==0){
											printf("%s e pre requisito para fazer %s\n", aux_1,aux_2);
										}
									}		
								}
							}
							
						
				break;	
				case 2: printf("digite o ra o nome login e a senha");
						a= Cadastro_aluno();
						grava(a);
						free(a);
						break;
				
				 
			}
fclose(disciplina);
}

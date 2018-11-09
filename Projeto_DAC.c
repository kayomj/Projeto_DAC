#include<stdio.h>
#include<stdlib.h>
#include<string.h>

//Estrutura de aluno
struct aluno {
	char ra[7], nome[100], login[8], senha[9];
};
typedef struct aluno Aluno;

//FunÃ§Ã£o que adiciona um aluno novo
Aluno *Cadastro_aluno(char ra[7], char nome[100], char login[8], char senha[9]){
	Aluno *aux;
	aux=(Aluno*)malloc(sizeof(Aluno));//Reserva espaÃ§o na memÃ³ria
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
	int cont=0, validar_senha, validar_login;
	char c, login[8],senha[9];
	FILE*arq;
	arq=fopen("Alunos.txt","r");
	do{
		fseek(arq,7,SEEK_CUR);//Pula 7 posiÃ§Ãµes
		do{
			cont++;
			c=fgetc(arq);
		}while(c!=',');//Para na primeira virgula
		fgets(login,7,arq);//LÃª a variÃ¡vel Login do arquivo
		fseek(arq,1,SEEK_CUR);//Pula a virgula faltante
		fscanf(arq,"%s",senha);
		validar_senha=strcmp(senha,sen);
		validar_login=strcmp(login,log);
		if((validar_login==0 && validar_senha==0)){
			return 0;
		}
	}while(c!=EOF);
	return 1;
}



int main(){
char login[8], senha[9], c, p, tam[100], tam_1[150], codigo_d[6],ra[7], aux[6], nome[100], percorre[6];
Aluno *a;
FILE *disciplina, *pre_req ;
disciplina=fopen("C:\\Users\\s092984\\Downloads\\Projeto_DAC-master\\Disciplinas.txt","r");
if(disciplina==NULL){
	printf("erro na abertura do arquivo");
}
pre_req=fopen("C:\\Users\\s092984\\Downloads\\Projeto_DAC-master\\Prerequisitos.txt","r");
	/*do{
		printf("Digite seu login e senha");
		scanf("%s",login);
		scanf("%s",senha);
		}while(verifica_login(login,senha)==0);*/
			printf("1-consultar disciplina 2-cadastrar aluno");
			int op;
			scanf("%d",&op);
			switch(op){
				case 1: printf("digite o codigo da disciplina");
						scanf("%s",codigo_d);
							fscanf(disciplina,"%s",tam);
							for(int i=0;i<6;i++){
								aux[i]=tam[i];
							}
							
							if(strcmp(aux,codigo_d)==0){
							printf("Disciplina,nome,creditos: %s", tam);
								printf("%s",tam);
								break;
								fgets(tam_1,150,pre_req);
								strtok(tam,",");
								//if(strcmp(percorre,codigo_d)==0){
									
								//}
								//break;
							}

							else{
								for(int i=0;p!='\n';i++){
									p=fgetc(disciplina);
								}
							}
				break;	
				case 2: printf("digite o ra o nome login e a senha");
						scanf("%s",ra);
						gets(nome);
						gets(login);
						gets(senha);
						*a=*Cadastro_aluno(ra, nome, login, senha);
						grava(a);
						free(a);
						break;
			}
fclose(disciplina);
}

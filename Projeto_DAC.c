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
	gets(aux->ra);
	printf("%s",aux->ra);
	fgets(aux->nome, 100, stdin);
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

void Tads_matriculando(){
	printf("escolha entre as opcoes");
	printf("\n1-ralizar matricula");
	do{
		
	}
}

int main(){
char c_nome[100], c_ra[7], c_login[8], c_senha[9], c, p, tam[100], tam_1[12], codigo_d[6],ra[7], aux[6], aux_1[6], aux_2[6], percorre[6];
Aluno *a;
FILE *disciplina, *pre_req, ver_aluno ;
disciplina=fopen("C:\\Users\\s092984\\Downloads\\Projeto_DAC-master\\Disciplinas.txt","r");
if(disciplina==NULL){
	printf("erro na abertura do arquivo");
}
pre_req=fopen("C:\\Users\\s092984\\Downloads\\Projeto_DAC-master\\Prerequisitos.txt","r");
		//printf("Digite seu login e senha");
		//do{
		//scanf("%s",login);
		//scanf("%s",senha);
		//}while(verifica_login(login,senha)==0);
			printf("1-consultar disciplina 2-cadastrar aluno");
			int op;
			scanf("%d",&op);
			//edicao solon 
			switch(op){
				case 1: printf("digite o codigo da disciplina");
						scanf("%s",codigo_d);
							fscanf(disciplina,"%s",tam);
							for(int i=0;i<5;i++){
								aux[i]=tam[i];
							}
							if(strcmp(aux,codigo_d)==0){
								printf("Disciplina,nome,creditos: %s\n", tam);
									fgets(tam_1,12,pre_req);
									for(int i=0;i<=5;i++){
										aux_1[i]=tam_1[i];
										aux_2[i]=tam_1[i+6];
									}
									if(strcmp(codigo_d,aux_2)==0){
										printf("%s e pre requisito para fazer %s", aux_1,aux_2);
									}
							}
						
				break;	
				case 2: printf("digite o ra o nome login e a senha");
						*a= *Cadastro_aluno();
						grava(a);
						free(a);
						break;
				
				case 3: 
			}
fclose(disciplina);
}

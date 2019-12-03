#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>
#define MAX 100

struct cadastro{
	char nome[50];
	char endereco[100];
	char fone[10];
	long int CEP;
} pessoa;

int opcao();
void novo_cadastro();
void especifica();
void nomes();

int main()
{
	FILE *lista=fopen("Agenda_Eletronica.txt","r");
	int op;
	do{
		printf("\n");
		op=opcao();
		printf("\n");
		switch(op){
			case 1:
				novo_cadastro();
				break;
			case 2:
				especifica();
				break;
			case 3:
				nomes();
				break;
			case 4:
				printf("Fim de programa!");
				break;
			default:
				printf("\n Opçao invalida!!!! Escolha novamente\n");
				op=0;
		}
	}while(op!=4);
	fclose(lista);
}

int opcao()
{
	int a;
	printf(" Voce esta numa agenda eletronica.\n");
	printf(" 1:Entrar com um novo cadastro \n 2:Ver os dados de uma pessoa especifica \n 3:Ver a lista de pessoas com nome iniciado com letra digitada \n 4:Finalizar o programa \n");  
	printf(" Digite a opcao desejada: ");
	scanf("%d", &a);
	return a;
}

void novo_cadastro()
{
	FILE *lista=fopen("Agenda_Eletronica.txt","a");
	printf("Voce esta inserindo um novo cadastro\n");
	printf("\nDigite o nome:");
	scanf("%s", &pessoa.nome);
	fprintf(lista,"Nome:%s;\n",pessoa.nome);
	printf("\nDigite o endereço:");
	scanf("%s", &pessoa.endereco);
	fprintf(lista,"Endereco:%s;\n",pessoa.endereco);
	printf("\nDigite o numero do telefone:");
	scanf("%s", &pessoa.fone);
	fprintf(lista,"Telefone:%s;\n",pessoa.fone);
	printf("\nDigite o CEP:");
	scanf("%d", &pessoa.CEP);
	fprintf(lista,"CEP:%d;\n",pessoa.CEP);
	fclose(lista);
}

void especifica()
{
	FILE *lista=fopen("Agenda_Eletronica.txt","r");
	int y=':';
	char n[30],pal[100],*x;
	printf("\nDigite o nome da pessoa que voce deseja ver o cadastro:");
	scanf("%s", &n);
	while(fgets(pal,100,lista)!=NULL)
	{
		if(pal[0]=='N')
		{
			x=strchr(pal,y);
			x[(strlen(x)-1)]='\0';
			if (strstr(x,n))
			{
				printf("\n");
				printf("%s\n",pal);
				while(fgets(pal,100,lista)!=NULL){
					if(pal[0]=='C'){
						printf("%s",pal);
						break;
					}
					printf("%s",pal);	
				}
			}
		}
	}
	fclose(lista);
}

void nomes()
{
	FILE *lista=fopen("Agenda_Eletronica.txt","r");
	int y=':';
	char n[2],pal[100],*x;
	printf("\nDigite a letra para ver os nomes cadastrados:");
	scanf("%s", &n[0]);
	while(fgets(pal,100,lista)!=NULL)
	{
		if(pal[0]=='N'){
			x=strchr(pal,y);
			x[(strlen(x)-1)]='\0';
			if(x[1]==n[0]){
				printf("%s\n",pal);
			}
		}
	}
	fclose(lista);
}

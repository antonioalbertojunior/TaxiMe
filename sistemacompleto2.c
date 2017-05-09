#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#include "funcoes.h"
//#include "funcoes.c"
int main(void)
{
	Tfuncionario *ini,*per;
	Tcliente *ini2;	
	Treserva *ini3;
	Tsupervisor *ini5;
	Tcontrole *ini6;
	char nome2[40];
	int codsuper1;
	int cpf2;
	int nasc2;
	char sexo2[9];
	char horario2[100];
	float salario2;
	int telefone2;
	char senha2[10];
	int op,erro;
	inicializar_controle(&ini6);
	inicializar_super(&ini5);
	do{
	carregasupertxt(&ini5);
	printf("\nBem vindo ao TaxiMe");
	printf("\n1.Login");
	printf("\n2.Cadastro Supervisor");
	printf("\n3.Informacoes do Supervisor");
	printf("\n4.Sair");
	printf("\n\nDigite sua opcao : ");
	scanf("%d",&op);
	getchar();
	switch(op)
	{
		case 1:	do{
				printf("\n\nComo deseja fazer login ?");
				printf("\n1.Supervisor");
				printf("\n2.Funcionario");
				printf("\n3.Voltar ao menu anterior");
				printf("\nDigite sua opcao : ");
				scanf("%d",&op);
				switch(op)
				{
					case 1:
						carregasupertxt(&ini5);
						errosupervisor(&ini5,&ini6);
						break;
					case 2:
						printf("\n\n");
						//carregafunctxt(&ini);
						funcionario_data (&ini);
						break;
					//default: printf("Opcao Invalida");
						break;
			
				}
			}while(op!=3);
			break;
		case 2:
			//cadastro_supervisor();
			erro=inserir_super (&ini5,nome2,codsuper1,cpf2,nasc2,sexo2,horario2,salario2,telefone2,senha2);
			salvasuperxt(&ini5);
			if(erro==1)
			{
				printf("Supervisor ja Cadastrado!");
			}
			break;
		case 3 :
				listarsuper(&ini5);
				break;

		case 4: break;
	}
	}while(op!=4);
	free(ini);
	free(ini2);
	free(ini3);
	free(ini5);
	free(ini6);
	free(per);	
	return 0;
}


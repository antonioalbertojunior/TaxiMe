#include "funcoes.h"
/*--------------------------------------------------------------------------------------------
 MENUS
-------------------------------------------------------------------------------------------*/

void menu()
{
	printf("\nLogado com Supervisor");
	printf("\n\nMenu");
	printf("\n1. Taxistas");
	printf("\n2. Banco de horas");
	printf("\n3. Voltar ");
}

void menu_cliente()
{
	printf("CLIENTE");
	printf("\n1.Dados do cliente");
	printf("\n2.Reserva");
	printf("\n3.Voltar ao menu anterior");
}
void submenu_cliente_dados()
{

	printf("CLIENTE");
	printf("\n1.Cadastro do cliente");
	printf("\n2.Consulta do cliente");
	printf("\n3.Listar todos os clientes");
	printf("\n4.Voltar ao menu anterior");	
}
void submenu_cliente_reserva()
{
	printf("CLIENTE");
	printf("\n1.Consulta da reserva");
	// deseja cadastrar?
	//printf("\n.Excluir reserva");
	printf("\n2.Listar reservas");	
	printf("\n3.Voltar ao menu anterior");	
}

void menu_geral()
{

	printf("MENU TAXISTA\n");
	printf("\n1-Cadastro de Taxistas");
	printf("\n2-Mostrar todos os Taxistas");
	printf("\n3-Excluir Taxista por posicao na lista");
	printf("\n4-Voltar");
}

void menubanco()
{
	printf("\n1.Inserir Horario do funcionario");
	printf("\n2.Mostrar todos os registros");
	printf("\n3.Voltar\n");
}
inicializar_controle(Tcontrole **inicio6)
{
	*inicio6=NULL;
	return 1;
}

int verifica(Tfuncionario **inicio,Tcontrole **inicio6,char *nome)
{
	Tfuncionario *per;
	Tcontrole *aux;
	per=*inicio;
	while(per!=NULL)
	{
		if(strcmp(per->fnome,nome)==0)
		{
			strcpy(per->fnome,aux->named);
			printf("\n");
			return 1;
		}
		else
		{
			per=per->prox;
		}
	}
	return 0;
}

int inserirbanco(Tfuncionario **inicio,Tcontrole **inicio6,int horai3,int mini3,int horaf3,int minf3,int dia3,int mes3,int ano3,char* nome3)
{
	Tcontrole *novo,*per;
	Tfuncionario *aux;
	aux=*inicio;
	per=*inicio6;
	int erro=0;
	novo=(Tcontrole*)malloc(sizeof(Tcontrole));
	printf("Banco de Horas");
	printf("\nDigite o nome do Taxista: ");
	do{
	gets(nome3);
	erro=verifica(&aux,&per,nome3);
	}while(erro==0);
	printf("\nHorario de inicio(00:00): ");
	scanf("%d:%d",&horai3,&mini3);
	getchar();
	printf("Horario do fim (00:00): ");
	scanf("%d:%d",&horaf3,&minf3);
	getchar();
	printf("\nData (00/00/00): ");
	scanf("%d/%d/%d",&dia3,&mes3,&ano3);
	getchar();

	strcpy(novo->named,nome3);
	novo->fhorai=horai3;
	novo->fmini=mini3;
	novo->fhoraf=horaf3;
	novo->fminf=minf3;	
	novo->fdia=dia3;
	novo->fmes=mes3;
	novo->fano=ano3;
	
	if (*inicio6==NULL)
	{
	    novo -> prox = NULL;
	    *inicio6 = novo;	    
	}
	else {
	     novo -> prox = *inicio6;
	     *inicio6 = novo;

	}
	return 0;
}

int listardados(Tcontrole *inicio6)
{
	Tcontrole *aux;
	aux=inicio6;
	if(inicio6==NULL)
	{
		printf("Nao existe dados!");
		return 1;
	}
	else{
	
	while(aux!=NULL)
	{
	printf("\n");
	printf("---------------------------------------------------");
	printf("\nHorario de inicio : %d:%d",aux->fhorai,aux->fmini);
	printf("\nHorario do fim : %d:%d",aux->fhoraf,aux->fminf);
	printf("\nData : %d/%d/%d ",aux->fdia,aux->fmes,aux->fano);
	printf("\nNome: %s",aux->named);
	printf("\n\n");
	aux=aux->prox;
	}
		}
	return 0;

}

int listarsuper(Tsupervisor **inicio5)
{
	Tsupervisor *aux;
	aux=*inicio5;
	if(aux!=NULL)
	{
		printf("\nNome Supervisor: %s",aux->nome);
		printf("\nCodigo do Supervisor :%d",aux->codsuper);
		printf("\nCPF : %d",aux->cpf);
		printf("\nNascimento :%d",aux->nasc);
		printf("\nSexo :%s",aux->sexo);
		printf("\nHorario: %s",aux->horario);
		printf("\nSalario :%f",aux->salario);
		printf("\nTelefone : %d",aux->telefone);
		printf("\n\n");
	}
}

void salvacontrolext(Tcontrole **inicio6)
{
	FILE *fdadosB;
	fdadosB = fopen("Controle.dat","wb");	
	
	Tcontrole *percorre;
	
	percorre = *inicio6;
	
	while(percorre != NULL){			
			fwrite(percorre, sizeof(Tcontrole), 1, fdadosB);	
			percorre = percorre -> prox;			
	}
	
	fclose(fdadosB);
	}
	

int carregacontroletxt(Tcontrole **inicio6)
{
	FILE *fdadosB;
	fdadosB = fopen("Controle.dat","rb+");
	
	Tcontrole *percorre;
	if(fdadosB==NULL)
	
	{
		printf("\n");
		return 1;
	}
	else{
	
	//pegando o primeiro e guardando como inicio
	Tcontrole *noaux = (Tcontrole *) malloc(sizeof(Tcontrole));
	fread(noaux, sizeof(Tcontrole), 1, fdadosB);
	*inicio6 = noaux;
	
	//iniciando o percorre para não perder a referencia do inicio
	percorre = *inicio6;

	
	do{
		
		Tcontrole *noaux = (Tcontrole *) malloc(sizeof(Tcontrole));		
		
		fread(noaux, sizeof(Tcontrole), 1, fdadosB);
	
		percorre  -> prox = noaux;
		
		if(!feof(fdadosB))	
			percorre = percorre	-> prox;
		else
			percorre -> prox = NULL;		
			
	}while(!feof(fdadosB));	
}
	
	fclose(fdadosB);
	return 0;
}


void salvasuperxt(Tsupervisor **inicio5)
{
	FILE *fdadosB;
	fdadosB = fopen("Supervisor.dat","wb");	
	
	Tsupervisor *percorre;
	
	percorre = *inicio5;
	
	while(percorre != NULL){			
			fwrite(percorre, sizeof(Tsupervisor), 1, fdadosB);	
			percorre = percorre -> prox;			
	}
	
	fclose(fdadosB);
	}
	
void carregasupertxt(Tsupervisor **inicio5)
{
	FILE *fdadosB;
	fdadosB = fopen("Supervisor.dat","rb+");
	
	Tsupervisor *percorre;
	if(fdadosB==NULL)
	
	{
		printf("\n");
	}
	else{
	
	//pegando o primeiro e guardando como inicio
	Tsupervisor *noaux = (Tsupervisor *) malloc(sizeof(Tsupervisor));
	fread(noaux, sizeof(Tsupervisor), 1, fdadosB);
	*inicio5 = noaux;
	
	//iniciando o percorre para não perder a referencia do inicio
	percorre = *inicio5;

	
	do{
		
		Tsupervisor *noaux = (Tsupervisor *) malloc(sizeof(Tsupervisor));		
		
		fread(noaux, sizeof(Tsupervisor), 1, fdadosB);
	
		percorre  -> prox = noaux;
		
		if(!feof(fdadosB))	
			percorre = percorre	-> prox;
		else
			percorre -> prox = NULL;		
			
	}while(!feof(fdadosB));	
}
	
	fclose(fdadosB);
}


int inicializar_super(Tsupervisor **inicio5)
{
	*inicio5=NULL;
	return 0;
}

int inserir_super(Tsupervisor **inicio5,char* nome1,int codsuper1,int cpf1,int nasc1,char* sexo1,char* horario1,float salario1,int telefone1,char* senha1)
{
	Tsupervisor *novo;
	novo=(Tsupervisor*)malloc(sizeof(Tsupervisor));
	if(*inicio5==NULL)
	{
	
	printf("Bem vindo ao TaxiME");
	buffer(stdin);
	printf("\nNome Supervisor:");
	fgets(nome1,40,stdin);
	removern(nome1);
	printf("Codigo de identificacao: ");
	scanf("%d",&codsuper1);
	printf("CPF:");
	scanf("%d",&cpf1);
	//getchar();
	printf("Data de nascimento: ");
	scanf("%d",&nasc1);
	buffer(stdin);
	printf("Sexo: ");
	fgets(sexo1,10,stdin);
	removern(sexo1);
	buffer(stdin);
	printf("Horario de trabalho:");
	fgets(horario1,100,stdin);
	removern(horario1);
	printf("Salario:");
	scanf("%f",&salario1);
	printf("Telefone:");
	scanf("%d",&telefone1);
	buffer(stdin);
	printf("Senha:");
	fgets(senha1,10,stdin);
	removern(senha1);
	
	novo->codsuper=codsuper1;
	novo->cpf=cpf1;
	novo->nasc=nasc1;
	strcpy(novo->nome,nome1);
	strcpy(novo->sexo,sexo1);
	strcpy(novo->horario,horario1);
	novo->salario=salario1;
	novo->telefone=telefone1;
	strcpy(novo->senha,senha1);

		novo -> prox = NULL;
		*inicio5 = novo;
		return 0;
	}
	else {
		//novo->prox=*inicio5;
		//*inicio5=novo;
	     return 1;
	}

}

int errocodfunc(Tfuncionario **inicio,int cod)
{
	Tfuncionario *per;
	per=*inicio;
	while(per!=NULL)
	{
		if(per->fcodreserva==cod)
		{
			printf("Codigo ja existente.Digite outro!");
			return 1;
		}
		else
		{
			per=per->prox;
		}
	}
	return 0;
}

int errocpffunc(Tfuncionario **inicio,char* cpf1)
{
	Tfuncionario *per;
	per=*inicio;
	while(per!=NULL)
	{
		if(strcmp(per->fcpf,cpf1)==0)
		{
			printf("Este CPF ja esta em uso.Digite outro!");
			return 1;
		}
		else
		{
			per=per->prox;
		}
	}
	return 0;
}
int errocelularfunc(Tfuncionario **inicio2,int num)
{
	Tfuncionario *per;
	per=*inicio2;
	while(per!=NULL)
	{
		if(per->fcelular==num)
		{
			printf("Este numero de celular ja esta em uso.Digite outro!");
			return 1;
		}
		else
		{
			per=per->prox;
		}
	}
	return 0;
}

int errocodcliente(Tcliente **inicio2,int num)
{
	Tcliente *per;
	per=*inicio2;
	while(per!=NULL)
	{
		if(per->ccodreserva==num)
		{
			printf("Este codigo ja esta em uso.Digite outro!");
			return 1;
		}
		else
		{
			per=per->prox;
		}
	}
	return 0;
	
}

int errocpfcliente(Tcliente **inicio2,char* cpf)
{
	Tcliente *per;
	per=*inicio2;
	while(per!=NULL)
	{
		if(strcmp(per->ccpf,cpf)==0)
		{
			printf("Este CPF ja esta em uso.Digite outro!");
			return 1;
		}
		else
		{
			per=per->prox;
		}
	}
	return 0;
}

int errocelularcliente(Tcliente **inicio2,char* cel)
{
	Tcliente *per;
	per=*inicio2;
	while(per!=NULL)
	{
		if(strcmp(per->ccelular,cel)==0)
		{
			printf("Este celular ja esta em uso.Digite outro!");
			return 1;
		}
		else
		{
			per=per->prox;
		}
	}
	return 0;
}

int taxipref(Tcliente **inicio2,Tfuncionario **inicio,char* taxi)
{
	Tcliente *c;
	Tfuncionario *f;
	f=*inicio;
	c=*inicio2;
	while(f!=NULL)
	{
		if(strcmp(f->fnome,taxi)==0)
		{
			strcpy(c->cnome,f->fnome);
			return 1;
		}
		else
		{
			printf("Funcinario nao cadastrado!Digite um funcionario valido.\n");
			f=f->prox;
			return 0;
		}
	}
}



void errosupervisor(Tsupervisor **inicio5,Tcontrole **inicio6)
{
	//supervisor
	char aux_nome[40];
	char aux_senha[10];
	int num;
	//struct funcionario
    char fnome1[256];
	char fcpf1[14];
	char fnascim[20];
    char fsex[20];
	int fhorai1;
	int fhoraf1;
	char fptaxi[100];
	int fquantc;
	float fsalar;
	int freserv;
	char fmcarro[50];
	int fnumc;
	int erro,erro2;
	// variavel de opçao
	int op;
	int pos;
	int *pos2=0;
	int cod;
	int aux1;
	int sair;
	int resp;
	/*VARIAVEIS PARA O CLIENTE */
	char cnome[256];
	char ccpf1[12];
	char cnascs[20];
	char csex[11];
	char ccelular1[12];
	char ctaxipref1[256];
	char cendereco1[100];
	int ccodreserva1;
	char ctel1[20];
	/*VARIAVEIS PARA A RESERVA */
	char rnome[256];
	char rnasc[20];
	char rendereco[100];
	char rcelular[12];
	char rtaxipref[256];
	int rdata1;
	int rhorai1;
	int rcodreserva;
	int fmini1,fminif1;
	int erro3;
	char aux11[40];
	char aux12[10];
	int fhorai2,fmini2;
	int fhoraf2,fminf2;
	int fdia1,fmes1,fano1;
	char nomef[40];
	int horai3,mini3,horaf3;
	int minf3,dia3,mes3;
	int ano3;
	char nome3[40];
	int erro4;
	/*DECLARAÇÃO VARIAL FUNCIONARIO*/
	Tfuncionario *ini,*per;
	/*DECLARAÇÃO VARIAVEL CLIENTE*/
	Tcliente *ini2;	Treserva *ini3;
	Tcontrole *ini6;
	erro=inicializar_cliente2(&ini2);
	/*DECLARAÇÃO VARIAVEL RESERVA*/
	erro2=inicializar_reserva(&ini3);
	erro3=inicializar_func2(&ini);
	ini6=*inicio6;
	int mostrar=0;
	Tsupervisor *cmp;
	cmp=*inicio5;
	ini6=*inicio6;
	strcpy(aux11,cmp->nome);
	strcpy(aux12,cmp->senha);
	do{
	buffer(stdin);
	printf("\nDigite o nome: ");
	fgets(aux_nome,40,stdin);
	removern(aux_nome);
//	//system("clear")
		
	
		if(strcmp(aux11,aux_nome)==0)
		{
			do{

			printf("\nDigite a senha:");
			fgets(aux_senha,10,stdin);
			removern(aux_senha);
				////system("clear")
				if(strcmp(aux12,aux_senha)==0)
					{

						do{
		////system("cls")
		////system("clear")
		menu();
		printf("\n\nDigite sua opcao: ");
		scanf("%d",&op);
		getchar();
		////system("clear")
		switch(op)
			{
			case 1:
				do{
					////system("clear")
				carregafunctxt(&ini);
				menu_geral();
				printf("\n\nDigite sua opcao: ");
				scanf("%d",&op);
				switch(op)
				{
					case 1:
						erro=inserir_func (&ini,fnome1,fcpf1,fnascim,fsex,fptaxi,fsalar,freserv,fmcarro,fnumc);
	                    if (erro == 0) printf("Insercao realizada com sucesso\n");
	                  	salvafunctxt(&ini);
	                    //getchar();		
						break;
					case 2:
						erro=listar_func (ini);
	                    if (erro==1)
	                    {
	                        printf("\nLista de funcionarios vazia. Impossivel listar\n");
	                    }
	                    getchar();
			                    
								break;
						break;
					case 3:
						printf("\nDigite codigo de reserva : ");
						scanf("%d",&cod);
						erro=remover_func (&ini,cod);
						if(erro==1)
						{
							printf("\nCodigo de reserva invalido. Digite novamente. \n\n");
						}
						getchar();
					
						break;
					case 4:	break;
					default :printf("\nOpcao invalida\n");
					getchar();
					break;
	}

	}while(op!=4);
				break;
			case 2:		
						do{
						menubanco();
						printf("\nDigite sua opcao: ");
						scanf("%d",&op);
						switch(op)
						{
							case 1:
								inserirbanco(&ini,&ini6,horai3,mini3,horaf3,minf3,dia3,mes3,ano3,nome3);
								if(erro==0) salvacontrolext(&ini6);
								printf("Insercao realizada com sucesso !");
								break;
							case 2:
								erro4=carregacontroletxt(&ini6);
								if(erro4==1)
								{
									printf("Lista Vazia!");
								}
								else{
								listardados(ini6);
									}
							 	break;
							case 3:break;
						}
					}while(op!=3);
						
				break;
			case 3:break;
			}	
			}while(op!=3);
					}
				else
				printf("\nErro de senha");
				
			  } while (strcmp(aux12,aux_senha)!=0);
		}
	else 
	printf("Erro de Usuario");
		}	while(strcmp(aux11,aux_nome)!=0);
}

void funcionario_data (Tfuncionario **inicio)
{
	/*VARIAVEIS PARA O CLIENTE */
	char cnome[256];
	char ccpf1[12];
	char cnascs[20];
	char csex[11];
	char ccelular1[12];
	char ctaxipref1[256];
	char cendereco1[100];
	int ccodreserva1;
	char ctel1[20];
	/*VARIAVEIS PARA A RESERVA */
	char rnome[256];
	char rnasc[20];
	char rendereco[100];
	char rcelular[12];
	char rtaxipref[256];
	char rreserva[100];
	int rdata1;
	int rhorai1;
	int rcodreserva;
	int op;
	int pos;
	int *pos2=0;
	int cod;
	int aux1;
	int sair;
	int resp;
	int pos3;
	Tcliente *per;
	int erro,erro2,erro3;
	/*DECLARAÇÃO VARIAVEL CLIENTE*/
	Tcliente *ini2;	Treserva *ini3;
	Tfuncionario *ini;
	erro=inicializar_cliente2(&ini2);
	/*DECLARAÇÃO VARIAVEL RESERVA*/
	erro2=inicializar_reserva(&ini3);
	//erro3=inicializar_func2(&ini);
	ini=*inicio;
		do
				{
					//system("clear")
					menu_cliente();
					//fflush(stdin);
					printf("\n\nDigite uma opcao: ");
					scanf("%d",&op);
					getchar();
					//system("clear")
					switch(op)
					{
					
						case 1:
							do{
							//system("clear")
							submenu_cliente_dados();
							carregaclientetxt(&ini2);
							printf("\n\nDigite sua opcao: ");
							scanf("%d",&op);
							getchar();
							switch(op)
							{
								case 1:
								carregafunctxt(&ini);
								erro=inserir_cliente (&ini2,&ini,cnome,ccpf1,cnascs,csex,ccelular1,ctel1,ctaxipref1,cendereco1,ccodreserva1);
									if(erro==0)
									{
										printf("Insercao realizada com sucesso\n\n");
										salvaclientetxt(&ini2);

									}
									getchar();
									break;
								case 2:
									printf("Digite um codigo para procurar o cliente");
									scanf("%d",&cod);
								erro=obter_dado_c (&ini2,cod,pos2);
								if(erro==1)
								{
									printf("Impossivel buscar. Lista de cliente vazia !\n");
								}
								getchar();
									break;
								case 3:erro=listar_cliente(ini2);	
								if(erro==1)
								{
									printf("Nao existe cadastro de cliente\n");
								}
								getchar();
								break;
								case 4:break;
								default : printf("opcao invalida"); break;
							}
						}while(op!=4);
							break;
						case 2:
							do{

							submenu_cliente_reserva();
							printf("\n\nDigite sua opcao : ");
							scanf("%d",&op);

							switch(op)
								{
									case 1:
										if(ini2==NULL)
										{
											printf("Lista de Cliente vazia\n");
										}
										else{
										
										erro2=cadastro_res(&ini2,&ini3,rhorai1,rdata1,rreserva);
										salvareservaxt(&ini3);
										if(erro2==2)
										{
											printf("\nCliente nao achado.Favor cadastrar\n");
										}
											}
										getchar();
										break;
										case 2:
											erro2=listar_reserva(ini3);
											if(erro2==1)
											{
											printf("\nLista de reservas vazia.\n");	
											}
										getchar();
										break;
										case 3:	break;
									
								}
							}while(op!=3);
							break;	
						case 3:	break;
					}
				
	}while(op!=3);
}
/*----------------------------FUNCIONARIO-------------------------*/

int inicializar_func2(Tfuncionario **inicio)
{
	*inicio=NULL;
	return 0;
}

int inicializar_func (Tfuncionario **inicio)
{
    Tfuncionario *per, *aux;
	if(*inicio != NULL)
	{
      	per= *inicio;
	   while (per != NULL)
	   {
             aux = per;
	         per = per -> prox; 
	         free(aux);
	   }
	   *inicio = NULL; 
	   return 1; 
	}
	else
	{
	   return 0;
	}
}


void salvafunctxt(Tfuncionario **inicio)
{
	FILE *fdadosB;
	fdadosB = fopen("Funcionarios.dat","wb");	
	
	Tfuncionario *percorre;
	
	percorre = *inicio;
	
	while(percorre != NULL){			
			fwrite(percorre, sizeof(Tfuncionario), 1, fdadosB);	
			percorre = percorre -> prox;			
	}
	
	fclose(fdadosB);
	}


void carregafunctxt(Tfuncionario **inicio)
{
	FILE *fdadosB;
	fdadosB = fopen("Funcionarios.dat","rb+");
	
	Tfuncionario *percorre;
	if(fdadosB==NULL)
	
	{
		printf("\n");
	}
	else{
	
	//pegando o primeiro e guardando como inicio
	Tfuncionario *noaux = (Tfuncionario *) malloc(sizeof(Tfuncionario));
	fread(noaux, sizeof(Tfuncionario), 1, fdadosB);
	*inicio = noaux;
	
	//iniciando o percorre para não perder a referencia do inicio
	percorre = *inicio;

	
	do{
		
		Tfuncionario *noaux = (Tfuncionario *) malloc(sizeof(Tfuncionario));		
		
		fread(noaux, sizeof(Tfuncionario), 1, fdadosB);
	
		percorre  -> prox = noaux;
		
		if(!feof(fdadosB))	
			percorre = percorre	-> prox;
		else
			percorre -> prox = NULL;		
			
	}while(!feof(fdadosB));	
}
	
	fclose(fdadosB);
}


int listar_func(Tfuncionario *inicio)
{
	Tfuncionario *per;
	int cont=1;
	if (inicio==NULL)
	{
	return 1;
	}
	while(inicio!=NULL)
	{

		printf("\n\n---------------------------------------------------");
   	 	printf("\n\nNome do funcionario: %s",inicio->fnome);
		printf("\nCPF : %s",inicio->fcpf);
		printf("\nData de nascimento: %s",inicio->fnasc);
		printf("\nSexo do funcionario:%s",inicio->fsexo);
		printf("\nPonto de taxi: %s",inicio->fpontotaxi);
		printf("\nSalario do funcionario: R$ %1.2f",inicio->fsalario);
		printf("\nCodigo de reserva: %d",inicio->fcodreserva);
		printf("\nModelo do carro: %s",inicio->fmodelocarro);
		printf("\nCelular do funcionario: %d",inicio->fcelular);
		printf("\nPosicao do Funcionario na lista : %d",cont);
		printf("\n\n");
		cont++;
		inicio=inicio->prox;
	}
	printf("\n");
	return 0;
}
																
int inserir_func (Tfuncionario **inicio,char* fnome1,char* fcpf1,char* fnascim,char* fsex,char* fptaxi,float fsalar,int freserv,char* fmcarro,int fnumc)
{
   	Tfuncionario *novo,*per;
  	int erro;
    int aux1,aux2,sair;
    char aux3[14];
    novo = (Tfuncionario *) malloc(sizeof(Tfuncionario));
	per=*inicio;
	sair=0;
		printf("\n\nCADASTRO DO Taxista\n");
		buffer (stdin);	
		printf("\n\t\tNome do Taxista: ");
        fgets(fnome1,256, stdin);
        removern  (fnome1);
        buffer(stdin);
		printf("\t\tCPF :");
		do{
	//	fgets(fcpf1,14,stdin);
		gets(fcpf1);
		erro=errocpffunc(&per,fcpf1);
		}while(erro==1);
		removern(fcpf1);
		buffer(stdin);
		printf("\t\tData de nascimento: ");
		fgets(fnascim,20,stdin);
		removern(fnascim);
		buffer(stdin);
		printf("\t\tSexo do Taxista ");
		fgets(fsex,20,stdin);
		removern(fsex);
		buffer(stdin);                                                                        
		printf("Ponto de taxi do Taxista :");
		fgets(fptaxi,100,stdin);
		removern(fptaxi);
		printf("\t\tSalario do Taxista: R$");
		scanf("%f",&fsalar);
		getchar();
		printf("\t\tCodigo de reserva: ");
		do{
		scanf("%d",&freserv);
		erro=errocodfunc(&per,freserv);
		}while(erro==1);
		buffer(stdin);
		printf("\t\tModelo do carro: ");	
		fgets(fmcarro,50,stdin);
		removern(fmcarro);
		printf("\t\tCelular do Taxista: ");
		do{
		scanf("%d",&fnumc);
		erro=errocelularfunc(&per,fnumc);
		}while(erro==1);
		
    strcpy(novo->fnome,fnome1);
	strcpy(novo->fnasc,fnascim);
    strcpy(novo->fsexo,fsex);
	strcpy(novo->fpontotaxi,fptaxi);
	novo-> fsalario=fsalar;	
	novo->fcodreserva=freserv;
	strcpy(novo->fmodelocarro,fmcarro);
	strcpy(novo->fcpf,fcpf1);
	novo->fcelular=fnumc;	

	if (*inicio==NULL)
	{
	    novo -> prox = NULL;
	    *inicio = novo;
	}
	else {
	     novo -> prox = *inicio;
	     *inicio = novo;
	}

    return 0;
}

int obter_dado (Tfuncionario **inicio, int cod, int *pos)
{
	Tfuncionario *per;
	int var1,var2,resul;

  if(*inicio==NULL)
  {
   	return 1;
  }

else{
	per=*inicio;
 	while (cod != per->fcodreserva && per->prox!=NULL)
	{
     per=per->prox;
    
	}
	if(cod==per->fcodreserva)
	{
		
		var1=per->fhoraf;
		var2=per->fhorai;
		resul=var1-var2;
   	 	printf("\n\nNome do funcionario: %s",per->fnome);
		printf("\nCPF : %s",per->fcpf);
		printf("\nData de nascimento: %s",per->fnasc);
		printf("\nSexo do funcionario:%s",per->fsexo);
		printf("\nHorario de trabalho:\n");
		printf("Inicio: %dhr\n",per->fhorai);
		printf("Fim :%dhr\n",per->fhoraf);
		printf("Total : %d Horas/dia",resul);
		printf("\nPonto de taxi: %s",per->fpontotaxi);
		printf("\nQuantidade de corridas/dia: %d",per->fquantcorridas);
		printf("\nSalario do funcionario: R$ %1.2f",per->fsalario);
		printf("\nCodigo de reserva: %d",per->fcodreserva);
		printf("\nModelo do carro: %s",per->fmodelocarro);
		printf("\nCelular do funcionario: %d",per->fcelular);
		printf("\n\n");
        return 0;
	}
	else{
    	if(per->prox==NULL)
		{
   		 printf("\nFuncionario nao achado.\n");
    	return 2;
		}// fum do if
		}//fim do else

	}//fim do else de lista nao vazia

}

int remover_func(Tfuncionario **inicio,int pos)
{
	Tfuncionario *per,*aux;
 	int tam;
 	
 	if (pos<= 0)
       return 1; 

    Obter_Tamanho(*inicio, &tam);
    if (pos > tam)
       return 2; 
       
    if (pos==1)
    {   
        Remover_inicio(inicio);
    }
    else
    {   if (pos == tam)
        {
            Remover_fim(inicio);
        }
        else {
                int pos_aux = 1;
                per = *inicio;
                while (pos_aux!=pos-1) 
                {
                   per = per -> prox;
                   pos_aux++;
                }
                
                aux = per->prox; //acessa a posicao do meio
                per->prox = aux->prox;// o do meio recebe uma posicao a frente
                free(aux); //apaga o meio
        }
    }
    return 0;

}

/* -------------------------------------------------------------------------
REMOCAO
-------------------------------------------------------------------------*/
int Remover_inicio (Tfuncionario **inicio)
{
    Tfuncionario *aux;
    if (*inicio == NULL)
    {
         printf("\nLISTA VAZIA ! \nRemocao Impossivel\n");
        return 1;  /* lista vazia, impossivel remover primeiro */
    }
    else {
        aux = *inicio;
        *inicio = (*inicio)->prox;
        free(aux);
        return 0;
    }
}

int Remover_fim (Tfuncionario **inicio)
{
 	 	
 	Tfuncionario *percorre, *aux;
 	
    if (*inicio == NULL)
	{ 
	    printf("Nao ha dados para serem excluidos!");
	    return 1;
	}
	else { 
	     percorre = *inicio;
	     while (percorre->prox != NULL) // <
		 //percorre -> prox -> prox != NULL
	     {
	     	 aux = percorre;//antes de avançar para o proximo - chegará um antes do NULL
	         percorre = percorre -> prox;
	     }
	     
	    free(percorre);
        aux->prox = NULL;
              
	}
	return 0;
 	
 }
 
int Obter_Tamanho (Tfuncionario *inicio, int *tam)
{
    Tfuncionario *percorre;
    *tam = 0;
	if(inicio != NULL)
	{
       percorre = inicio;
	   while (percorre != NULL)
	   {
         (*tam)++;
         percorre = percorre -> prox;
	   }
     }
    else
    {
         *tam = 0;
    }
    return(0);
}

/*-----------------------------------FIM DAS FUNÇÕES DO FUNCIONARIO-----------------------------------------*/


/*---------------------------------RESERVA E CLIENTE-------------------------------------------------*/

/*--------------------FUNÇÕES DO CLIENTE-----------------------------------------*/

int inicializar_cliente2(Tcliente **inicio2)
{
	*inicio2=NULL;
	return 0;
}

int inicializar_reserva(Treserva **inicio3)
{
	*inicio3=NULL;
	return 0;
}

void salvaclientetxt(Tcliente **inicio)
{
	FILE *fdadosB;
	fdadosB = fopen("Clientes.dat","wb");	
	
	Tcliente *percorre;
	
	percorre = *inicio;
	
	while(percorre != NULL){			
			fwrite(percorre, sizeof(Tcliente), 1, fdadosB);	
			percorre = percorre -> prox;			
	}
	
	fclose(fdadosB);
	}


void carregaclientetxt(Tcliente **inicio)
{
	FILE *fdadosB;
	fdadosB = fopen("Clientes.dat","rb+");
	
	Tcliente *percorre;
	if(fdadosB==NULL)
	
	{
		printf("\n");
	}
	else{
	
	//pegando o primeiro e guardando como inicio
	Tcliente *noaux = (Tcliente *) malloc(sizeof(Tcliente));
	fread(noaux, sizeof(Tcliente), 1, fdadosB);
	*inicio = noaux;
	
	//iniciando o percorre para não perder a referencia do inicio
	percorre = *inicio;

	
	do{
		
		Tcliente *noaux = (Tcliente *) malloc(sizeof(Tcliente));		
		
		fread(noaux, sizeof(Tcliente), 1, fdadosB);
	
		percorre  -> prox = noaux;
		
		if(!feof(fdadosB))	
			percorre = percorre	-> prox;
		else
			percorre -> prox = NULL;		
			
	}while(!feof(fdadosB));	
}
	
	fclose(fdadosB);
}

int listar_cliente (Tcliente *inicio2)
{
	Tcliente *per;
	if (inicio2==NULL)
	{
	return 1;
	}
	else{
	printf("\nLISTA DE TODOS OS CLIENTES");
	per=inicio2;
	while(per!=NULL)
	{
	printf("\n");
	printf("---------------------------------------------------");
   	printf("\nNome do Cliente %s",per->cnome);
	printf("\nCPF : %s",per->ccpf);
	printf("\nData de nascimento: %s",per->cnasc);
	printf("\nSexo do funcionario: %s",per->csexo);
	printf("\nCelular do funcionario: %s",per->ccelular);
	printf("\nTelefone Residencial %s ",per->ctel);	
	printf("\nTaxita de preferencia %s",per->ctaxipref);
	printf("\nEndereco %s",per->cendereco);
	printf("\nCodigo de reserva: %d",per->ccodreserva);
	printf("\n\n");
		per=per->prox;
	}
}
	printf("\n");
	return 0;
}

int inserir_cliente (Tcliente **inicio2,Tfuncionario **inicio,char* cnome1,char* ccpf1,char* cnascs,char* csex,char* ccelular1,char *ctel1,char* ctaxipref1,char* cendereco1,int ccodreserva1)
{
	Tcliente *novo,*per; 	
	Tfuncionario *aux;
    novo = (Tcliente *) malloc(sizeof(Tcliente));
    int erro;
    per=*inicio2;
    aux=*inicio;
	//buffer(stdin);
	printf("\n\nCADASTRO DO CLIENTE \n");
	buffer(stdin);
	printf("\n\t\tNome do Cliente: ");
	fgets(cnome1,256,stdin);
	removern(cnome1);
	buffer(stdin);
	printf("\t\tCPF :");
	do{
		gets(ccpf1);
	//fgets(ccpf1,14,stdin);
	erro=errocpfcliente(&per,ccpf1);
	}while(erro==1);
	//removern(ccpf1);
	buffer(stdin);
	printf("\t\tData de nascimento: ");
	fgets(cnascs,20,stdin);
	removern(cnascs);
	buffer(stdin);
	printf("\t\tSexo do cliente: ");
	fgets(csex,20,stdin);
	removern(csex);
	buffer(stdin);
	printf("\t\tCelular do cliente: ");
	do{
		gets(ccelular1);
		erro=errocelularcliente(&per,ccelular1);
	}while(erro==1);
	//fgets(ccelular1,10,stdin);
	//removern(ccelular1);
	buffer(stdin);
	printf("\t\tTelefone Residencial: ");
	fgets(ctel1,10,stdin);
	removern(ctel1);
	buffer(stdin);
	printf("\t\tTaxita de preferencia: ");
	do{
	gets(ctaxipref1);
	erro=taxipref(&per,&aux,ctaxipref1);
	}while(erro==0 ||erro==2);
	//fgets(ctaxipref1,40,stdin);
	//removern(ctaxipref1);
	buffer(stdin);
	printf("\t\tEndereco : ");
	fgets(cendereco1,100,stdin);
	removern(cendereco1);
	printf("\t\tCodigo de reserva: ");
	do{
	scanf("%d",&ccodreserva1);
	erro=errocodcliente(&per,ccodreserva1);
	}while(erro==1);

	/*VARIAVEIS DO TIPO CHAR*/
	strcpy(novo->cnome,cnome1);
	strcpy(novo->ccpf,ccpf1);
	strcpy(novo->cnasc,cnascs);
    strcpy(novo->csexo,csex);
    strcpy(novo->ccelular,ccelular1);
    strcpy(novo->ctel,ctel1);
    strcpy(novo->ctaxipref,ctaxipref1);
    strcpy(novo->cendereco,cendereco1);
    
    /*VARIAVEIS DO TIPO INT */
    novo->ccodreserva=ccodreserva1;

	if (*inicio2==NULL)
	{
	    novo -> prox = NULL;
	    *inicio2 = novo;
	    // salvaclientetxt(inicio2);
	}
	else {
	     novo -> prox = *inicio2;
	     *inicio2 = novo;
	      //salvaclientetxt(inicio2);
	}
    return 0;
}

int obter_dado_c (Tcliente **inicio2, int cod, int *pos)
{
	Tcliente *per;

  if(*inicio2==NULL)
  {
   	return 1;
  }

else{
	per=*inicio2;
 	while (cod != per->ccodreserva && per->prox!=NULL)
	{
     per=per->prox;
    
	}
	if(cod==per->ccodreserva)
	{
    printf("\nNome do Cliente %s",per->cnome);
	printf("\nCPF : %s",per->ccpf);
	printf("\nData de nascimento: %s",per->cnasc);
	printf("\nSexo do Cliente: %s",per->csexo);
	printf("\nCelular do Cliente: %s",per->ccelular);
	printf("\nTelefone Residencial %s ",per->ctel);	
	printf("\nTaxista de preferencia %s",per->ctaxipref);
	printf("\nEndereco %s",per->cendereco);
	printf("\nCodigo de reserva: %d",per->ccodreserva);
	printf("\n\n");
    return 0;
	}
	else{
    	if(per->prox==NULL)
		{
   		 printf("\nCliente nao achado. Digite outro codigo\n");
    	return 2;
		}// fum do if
		}//fim do else

		}//fim do else de lista nao vazia

}

/*--------------------FIM DAS FUNÇÕES DO CLIENTE--------------------------------*/

/*--------------------FUNÇÕES DE RESERVA----------------------------------------*/

void salvareservaxt(Treserva **inicio3)
{
	FILE *fdadosB;
	fdadosB = fopen("Reservas.dat","wb");	
	
	Treserva *percorre;
	
	percorre = *inicio3;
	
	while(percorre != NULL){			
			fwrite(percorre, sizeof(Treserva), 1, fdadosB);	
			percorre = percorre -> prox;			
	}
	
	fclose(fdadosB);
	}


void carregareservatxt(Treserva **inicio3)
{
	FILE *fdadosB;
	fdadosB = fopen("Reservas.dat","rb+");
	
	Treserva *percorre;
	if(fdadosB==NULL)
	
	{
		printf("\n");
	}
	else{
	
	//pegando o primeiro e guardando como inicio
	Treserva *noaux = (Treserva *) malloc(sizeof(Treserva));
	fread(noaux, sizeof(Treserva), 1, fdadosB);
	*inicio3 = noaux;
	
	//iniciando o percorre para não perder a referencia do inicio
	percorre = *inicio3;

	
	do{
		
		Treserva *noaux = (Treserva*) malloc(sizeof(Treserva));		
		
		fread(noaux, sizeof(Treserva), 1, fdadosB);
	
		percorre  -> prox = noaux;
		
		if(!feof(fdadosB))	
			percorre = percorre	-> prox;
		else
			percorre -> prox = NULL;		
			
	}while(!feof(fdadosB));	
}
	
	fclose(fdadosB);
}


int cadastro_res(Tcliente **inicio2,Treserva **inicio3,int rhorai1,int rdata1,char * rreserva1)
{
	Treserva *novo; 	
	Tcliente *per;
	int rcodreserva1;
	//char rreserva[100];
	char rnome[40];
	char rnasc[20];
	char rcelular[20];
	char rtaxista[40];
	char rendereco[30];
	int rddia1,rmes1,rano1;
	int rmini1;
	novo = (Treserva *) malloc(sizeof(Treserva));
	per=*inicio2;
	printf("\n\nCADASTRO DA RESERVA \n");
	printf("\t\tCodigo de reserva:");
	scanf("%d",&rcodreserva1);
	while (rcodreserva1 != per->ccodreserva && per->prox!=NULL)
	{
     per=per->prox;
    
	}
	if(rcodreserva1==per->ccodreserva)
	{
		printf("\nNome do Cliente: %s",per->cnome);
		printf("\nData de nascimento: %s",per->cnasc);
		printf("\nEndereco %s",per->cendereco);
		printf("\nTaxita de preferencia %s",per->ctaxipref);
		printf("\nCelular do Cliente: %s",per->ccelular);
		printf("\nHora do inicio da corrida (00:00):");
		scanf("%d:%d",&rhorai1,&rmini1);
		printf("\nData da corrida (00/00/00): ");
		scanf("%d/%d/%d",&rddia1,&rmes1,&rano1);
		buffer(stdin);
		printf("\nLocal: ");
		fgets(rreserva1,100,stdin);
		removern(rreserva1);
		
	}
	else{

	return 2;
	}
	
	/*VARIAVEIS DO TIPO CHAR*/
	strcpy(novo->rnome,per->cnome);
	strcpy(novo->rnasc,per->cnasc);
	strcpy(novo->rendereco,per->cendereco);
	strcpy(novo->rtaxista,per->ctaxipref);
	strcpy(novo->rcelular,per->ccelular);
	novo->rcodreserva=per->ccodreserva;
	strcpy(novo->rreserva,rreserva1);
	novo->rhorai=rhorai1;
	novo->rmini=rmini1;
	novo->rddia=rddia1;
	novo->rmes=rmes1;
	novo->rano=rano1;
	
	if (*inicio3==NULL)
	{
	    novo -> prox = NULL;
	    *inicio3 = novo;
	}
	else {
	     novo -> prox = *inicio3;
	     *inicio3 = novo;
	}
    return 0;
	
}

int listar_reserva(Treserva *inicio3)
{
	Treserva *per;
	if (inicio3==NULL)
	{
	return 1;
	}
	else{
	printf("\nLISTA DE TODOS AS RESERVAS");
	per=inicio3;
	while(per!=NULL)
	{
	printf("\n");
	printf("---------------------------------------------------");
   	printf("\nCodigo de reserva do Cliente :%d",per->rcodreserva);
	printf("\nNome do Cliente : %s",per->rnome);
	printf("\nData de nascimento: %s",per->rnasc);
	printf("\nNome do taxista de preferencia %s",per->rtaxista);
	printf("\nCelular do Cliente: %s",per->rcelular);
	printf("\nHora da Corrida %d:%d",per->rhorai,per->rmini);	
	printf("\nData da Corrida %d/%d/%d",per->rddia,per->rmes,per->rano);
	printf("\nLocal: %s",per->rreserva);
	printf("\n\n");
		per=per->prox;
	}
		}
	printf("\n");	
}

int remover_reserv(Treserva **inicio3,int pos)
{
	Treserva *per,*aux;
 	int tam;
 	
 	if (pos<= 0)
       return 1; 

	obtertam_reserva(*inicio3,&tam);
    if (pos > tam)
       return 2; 
       
    if (pos==1)
    {   
        reserva_inicio(inicio3);
    }
    else
    {   if (pos == tam)
        {
            reserva_fim(inicio3);
        }
        else {
                int pos_aux = 1;
                per = *inicio3;
                while (pos_aux!=pos-1) 
                {
                   per = per -> prox;
                   pos_aux++;
                }
                
                aux = per->prox; //acessa a posicao do meio
                per->prox = aux->prox;// o do meio recebe uma posicao a frente
                free(aux); //apaga o meio
        }
    }
    return 0;
}

int obtertam_reserva(Treserva *inicio3, int *tam)
{
	 Treserva *percorre;
    *tam = 0;
	if(inicio3 != NULL)
	{
       percorre = inicio3;
	   while (percorre != NULL)
	   {
         (*tam)++;
         percorre = percorre -> prox;
	   }
     }
    else
    {
         *tam = 0;
    }
    return(0);
}

int reserva_inicio (Treserva **inicio3)
{
	Treserva *aux;
    if (*inicio3 == NULL)
    {
         printf("\nLISTA VAZIA ! \nRemocao Impossivel\n");
        return 1;
    }
    else {
        aux = *inicio3;
        *inicio3 = (*inicio3)->prox;
        free(aux);
        return 0;
    }
}

int reserva_fim (Treserva **inicio3)
{
	Treserva *percorre, *aux;
 	
    if (*inicio3 == NULL)
	{ 
	    printf("Nao ha dados para serem excluidos!");
	    return 1;
	}
	else { 
	     percorre = *inicio3;
	     while (percorre->prox != NULL) // <
		 //percorre -> prox -> prox != NULL
	     {
	     	 aux = percorre;//antes de avançar para o proximo - chegará um antes do NULL
	         percorre = percorre -> prox;
	     }
	     
	    free(percorre);
        aux->prox = NULL;
              
	}
	return 0;
}


/*------------------------------FIM DAS FUNÇÕES DE RESERVA E CLIENTE ------------------------------*/

/*--------------------FUNÇÃO LIMPAR BUFFER ----------------------------------------------------*/
void removern(char *s)
{

int len = strlen(s);

if(len> 0 && s[len-1] == '\n') // if there's a newline
s[len-1]  = '\0';   // truncate the string

}

void  buffer (FILE *fp)
{

int ch;
while((ch =fgetc(fp)) != EOF &&  ch != '\n');


// null body
}

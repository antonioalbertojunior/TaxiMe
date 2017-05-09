#ifndef SISTEMA_TAXIME
#define SISTEMA_TAXIME
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

/*---------MENUS------------------*/
//menu principal
void menu();
//menu do cliente
void menu_cliente();
void submenu_cliente_dados();
void submenu_cliente_reserva();
/*------------Controle-------------*/

struct controle{
	char named[40];
	int fhorai,fmini;
	int fhoraf,fminf;
	int fdia;
	int fmes;
	int fano;
	struct controle *prox;
};
typedef struct controle Tcontrole;

/*-------------SUPERVISOR----------------*/

struct supervisor{
	char nome[40];
	int codsuper;
	int cpf;
	int nasc;
	char sexo[9];
	char horario[100];
	float salario;
	int telefone;
	char senha[10];
	struct supervisor *prox;
};

typedef struct supervisor Tsupervisor;
/* -------------STRUCT FUNCIONARIOS-----------------------*/
struct funcionario{

	char fnome[256];
	char fcpf[14];
	char fnasc[20];
	char fsexo[20];
	int fhorai,fmini;
	int fhoraf,fminf;
	int fdia;
	int fmes;
	int fano;
	char fpontotaxi[100];
	int fquantcorridas;
	float fsalario;
	int fcodreserva;
	char fmodelocarro[50];
	int fcelular;
	struct funcionario *prox;

};

typedef struct funcionario Tfuncionario;

/*----------STRUCT DO CLIENTE -----------------------------------*/
struct cliente{

	char cnome[256];
	char ccpf[14];
	char cnasc[20];
	char csexo[11];
	char ccelular[12];
	char ctaxipref[256];
	char cendereco[100];
	int ccodreserva;
	char ctel[20];
	struct cliente *prox;
};

typedef struct cliente Tcliente;

/*----------STRUCT DA RESERVA -----------------------------------*/
struct reserva{

	char rnome[256];
	char rnasc[20];
	char rcelular[12];
	char rtaxista[256];
	char rendereco[100];
	int rddia,rmes,rano;
	int rhorai,rmini;
	int rcodreserva;
	char rreserva[100];
	struct reserva *prox;

};
typedef struct reserva Treserva;
/*----------------------------ERROS------------------------------------*/
int errocodfunc(Tfuncionario **inicio,int cod);
int errocpffunc(Tfuncionario **inicio,char* cpf1);
int errocelularfunc(Tfuncionario **inicio,int num);
int errocodcliente(Tcliente **inicio2,int cod);
int errocpfcliente(Tcliente **inicio2,char* cpf1);
int errocelularcliente(Tcliente **inicio2,char* cel);
void carregasupertxt(Tsupervisor **inicio5);
void salvasuperxt(Tsupervisor **inicio5);
int taxipref(Tcliente **inicio2,Tfuncionario **inicio,char* taxi);
int listarbanco (Tfuncionario **inicio);
int listarsuper(Tsupervisor **inicio5);
void menubanco();
int inicializar_controle(Tcontrole **inicio6);
int verifica(Tfuncionario **inicio,Tcontrole **inicio6,char *nome);
int inserirbanco(Tfuncionario **inicio,Tcontrole **inicio6,int horai3,int mini3,int horaf3,int minf3,int dia3,int mes3,int ano3,char* nome3);
int listardados(Tcontrole *inicio6);
int carregacontroletxt(Tcontrole **inicio6);
void salvacontrolext(Tcontrole **inicio6);
/*---------------------------------SUPERVISOR-----------------------------*/

//void cadastro_supervisor();

void errosupervisor(Tsupervisor **inicio5,Tcontrole **inicio6);

int inserir_super (Tsupervisor **inicio5,char* nome2,int codsuper1,int cpf2,int nasc2,char* sexo2,char* horario2,float salario2,int telefone2,char* senha2);

int inicializar_super(Tsupervisor **inicio5);


/*-------------------FIM DAS FUN합ES DO SUPERVISOR-------------------------*/


/*------------------------FUNCIONARIO -------------------------------------*/

void menu_geral();

int inserir_func (Tfuncionario **inicio,char* fnome1,char* fcpf1,char* fnascim,char* fsex,char* fptaxi,float fsalar,int freserv,char* fmcarro,int fnumc);

int inicializar_func2(Tfuncionario **inicio);

int remover_func (Tfuncionario **inicio, int pos);

int Remover_inicio (Tfuncionario **inicio);

int Remover_fim (Tfuncionario **inicio);

int Obter_Tamanho (Tfuncionario *inicio, int *tam);

int obter_dado (Tfuncionario **inicio, int codreseva, int *pos);

void carregafunctxt(Tfuncionario **inicio);

void salvafunctxt(Tfuncionario **inicio);

void funcionario_data (Tfuncionario **inicio);

/*--------------------FIM DAS FUN합ES FUNCIONARIO--------------------------*/
/*------------------------PROTOTIPO DAS FUN합ES ---------------------------------------*/

/*CLIENTE*/
void menu_cliente();

void submenu_cliente_dados();

int inserir_cliente (Tcliente **inicio2,Tfuncionario **inicio,char* cnome1,char* ccpf1,char* cnascs,char* csex,char* ccelular1,char *ctel1,char* ctaxipref1,char* cendereco1,int ccodreserva1);

void carregaclientetxt(Tcliente **inicio2);

void salvaclientetxt(Tcliente **inicio2);

int inicializar_cliente2(Tcliente **inicio2);

int obter_dado_c (Tcliente **inicio2, int codreseva, int *pos);

int listar_cliente(Tcliente *inicio2);


/*RESERVA*/
int inicializar_reserva(Treserva **inicio3);

void submenu_cliente_reserva();

int cadastro_res(Tcliente **inicio2,Treserva **inicio3,int rhorai1,int rdata1,char * rreserva1);

int listar_reserva(Treserva *inicio3);

int remover_reserv(Treserva **inicio3,int cod);

int reserva_inicio (Treserva **inicio3);

int reserva_fim (Treserva **inicio3);

int obtertam_reserva(Treserva *inicio3, int *tam);

void carregareservatxt(Treserva **inicio3);

void salvareservaxt(Treserva **inicio3);

/*------------------------FIM DOS PROTOTIPOS-----------------------------------------*/

/*--------------LIMPAR BUFFER----------------*/

void removern(char *s);

void  buffer (FILE *fp);
/*--------------FIM DA FUN플O BUFFER -----------*/

#endif //SISTEMA_TAXIME

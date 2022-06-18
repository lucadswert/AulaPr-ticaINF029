#ifndef FUNCOES_H
#define FUNCOES_H

typedef struct compraAcoes {
    int sigla;
    int qtd;
    float valor;
    struct compraAcoes *prox;
} Compra;

typedef struct vendaAcoes {
    int sigla;
    int qtd;
    float valor;
    struct vendaAcoes *prox;
} Venda;

typedef struct registroAcoes {
    int sigla;
    int qtd;
    float valor;
    struct registroAcoes *prox;
} Registro;

// Histórico das operações //
Registro *listaTmp = NULL;
Registro *listaRegistroPETRA = NULL;
Registro *listaRegistroVALE = NULL;
Registro *listaRegistroITSA = NULL;

Registro *inicioRegistro = NULL;
Registro *inicioRegistroPETRA = NULL;
Registro *inicioRegistroVALE = NULL;
Registro *inicioRegistroITSA = NULL;

// Funcoes Compra//
Compra *listaCompra = NULL;
Compra *inicioCompra = NULL;
void consultar_lista_compra(Compra* inicio);
void consultar_lista_individual(Compra* inicioCompra, int opAcao);
void retiraCompra(Compra* compra);
void arquivoCompras();
Compra *RemoveDado(int dado, Compra *ptr);

//Funcoes de Venda//
Venda *listaVenda = NULL;
Venda *inicioVenda = NULL;
Compra* apagaCompras(Compra* compra);
void consultar_lista_venda(Venda* inicio);
void consultar_lista_venda_individual(Venda* inicioVenda, int opAcao);
Venda* apagaVendas(Venda* venda);
void arquivoVendas();
Venda *RemoveDadoVenda(int dado, Venda *ptr);

//Menus//
void menuPrincipal();
void negociarOfertas();
void apagarOfertas();
void inserir( );
void listarOfertas( );

void consultar_registro(Registro* inicioRegistroPETRA,Registro* inicioRegistroVALE, Registro* inicioRegistroITSA );
Registro* realizarOperacoes(Registro* l, Compra* inicioCompra, Venda* inicioVenda);
Compra *RemoveDadoEspecifico(int qtd, int sigla, float valor, Compra *ptr);
Venda *RemoveDadoEspecificoVenda(int qtd, int sigla, float valor, Venda *ptr);
Registro* inserir_lista_registro(Registro* l, int qtd, float valor, int sigla);
void realizarOperacoesIndividuais(int sigla, Registro* l, Compra* listaCompra, Venda* listaVenda);
void inserir_ordenado(Compra **lista, int qtd, float valor, int sigla);
void inserir_ordenado_venda(Venda **lista, int qtd, float valor, int sigla);


Registro* realizarOperacoesPETRA(Registro* l, int sigla, Compra* listaCompra, Venda* listaVenda);
Registro* realizarOperacoesVALE(Registro* l, int sigla, Compra* listaCompra, Venda* listaVenda);
Registro* realizarOperacoesITSA(Registro* l, int sigla, Compra* listaCompra, Venda* listaVenda);

#endif  // FUNCOES_H

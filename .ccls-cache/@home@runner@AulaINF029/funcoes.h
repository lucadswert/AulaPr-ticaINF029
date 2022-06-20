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
Registro *listaRegistroPETRA = NULL;
Registro *listaRegistroVALE = NULL;
Registro *listaRegistroITSA = NULL;

Registro *inicioRegistroPETRA = NULL;
Registro *inicioRegistroVALE = NULL;
Registro *inicioRegistroITSA = NULL;

// Funcoes Compra//
Compra *listaCompra = NULL;
Compra *inicioCompra = NULL;
void consultar_lista_compra(Compra* inicio);
void consultar_lista_individual(Compra* inicioCompra, int opAcao);
void arquivoCompras();
void inserir_ordenado(Compra **lista, int qtd, float valor, int sigla);

//Funcoes de Venda//
Venda *listaVenda = NULL;
Venda *inicioVenda = NULL;
void consultar_lista_venda(Venda* inicio);
void consultar_lista_venda_individual(Venda* inicioVenda, int opAcao);
void arquivoVendas();
void inserir_ordenado_venda(Venda **lista, int qtd, float valor, int sigla);

//Menus//
void menuPrincipal();
void negociarOfertas();
void inserir( );
void listarOfertas( );

void consultar_registro(Registro* inicioRegistroPETRA,Registro* inicioRegistroVALE, Registro* inicioRegistroITSA );
void RemoveDadoEspecifico(int qtd, int sigla, float valor, Compra *ptr);
void RemoveDadoEspecificoVenda(int qtd, int sigla, float valor, Venda *ptr);
Registro* inserir_lista_registro(Registro* l, int qtd, float valor, int sigla);

Registro* realizarOperacoesPETRA(Registro* l, int sigla, Compra* listaCompra, Venda* listaVenda);
Registro* realizarOperacoesVALE(Registro* l, int sigla, Compra* listaCompra, Venda* listaVenda);
Registro* realizarOperacoesITSA(Registro* l, int sigla, Compra* listaCompra, Venda* listaVenda);

#endif  // FUNCOES_H

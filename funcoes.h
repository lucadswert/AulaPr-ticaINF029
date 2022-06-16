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
Registro *listaRegistro = NULL;
Registro *inicioRegistro = NULL;

// Funcoes Compra//
Compra *listaCompra = NULL;
Compra *inicioCompra = NULL;
void consultar_lista_compra(Compra* inicio);
Compra* inserir_lista_compra(Compra* l, int qtd, float valor, int sigla);
void consultar_lista_individual(Compra* inicioCompra, int opAcao);
void retiraCompra(Compra* compra);
void arquivoCompras();
Compra *RemoveDado(int dado, Compra *ptr);

//Funcoes de Venda//
Venda *listaVenda = NULL;
Venda *inicioVenda = NULL;
Compra* apagaCompras(Compra* compra);
void consultar_lista_venda(Venda* inicio);
Venda* inserir_lista_venda(Venda* l, int qtd, float valor, int sigla);
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
void consultar_registro(Registro* inicioRegistro);
void realizarOperacoes(Registro* l, Compra* inicioCompra, Venda* inicioVenda);
Compra *RemoveDadoEspecifico(int qtd, int sigla, float valor, Compra *ptr);
Venda *RemoveDadoEspecificoVenda(int qtd, int sigla, float valor, Venda *ptr);
void inserir_lista_registro(Registro* l, int qtd, float valor, int sigla);
void realizarOperacoesIndividuais(int sigla, Registro* l, Compra* listaCompra, Venda* listaVenda);

void selectsortVenda(Venda *p);
void selectsortCompra(Compra *p);

#endif  // FUNCOES_H

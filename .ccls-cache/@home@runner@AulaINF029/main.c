#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "funcoes.h"

int main() {
    arquivoCompras();
    arquivoVendas();
    menuPrincipal();
    return 0;
}

void menuPrincipal(  ){
  int resposta;
    do{
      printf( "\n=====================================\n"
                "||        MERCADO DE AÇÕES         || \n"
                "=====================================\n"
                "[1] | Incluir Ofertas\n"
                "[2] | Mostrar as Ofertas Disponíveis\n"
                "[3] | Negociar as Ofertas Disponíveis\n"
                "[0] | Encerrar\n-> " );
      scanf("%d", &resposta);
      switch( resposta ){
          case 1: inserir( ); break;
          case 2: listarOfertas( ); break;
          case 3: negociarOfertas(); break;
          case 0: printf( "\n <<<<<<<<< Programa Encerrado >>>>>>>>>\n\n" );
          break;}
      }while(resposta != 0);
}
void inserir( ){
  Compra compra;
  Venda venda;
  int qtd = 0, opAcao = 0;
  float valor = 0;
  int resposta = 0;
  do{
    printf( "\n=====================================\n"
            "||          MENU - INSERIR         || \n"
            "=====================================\n"
            "[1] | Compra\n"
            "[2] | Venda\n"
            "[0] | Voltar \n-> " );
        scanf("%d", &resposta);
        getchar();
        switch(resposta){
          case 1:
            printf("=====================================\n"
                  "||         OFERTA DE COMPRA        ||\n"
                  "=====================================\n");
                do{
                  printf("Que ação deseja comprar?\n");
                  printf("[1] | PETR4 (PETROBRAS)\n");
                  printf("[2] | VALE5 (VALE)\n");
                  printf("[3] | ITSA4 (ITAÚ)\n");
                  printf("[0] | VOLTAR\n-> ");
                  scanf("%d", &opAcao);
                  getchar();
                  if(opAcao < 0 || opAcao > 3){
                    puts("OPÇAO INVÁLIDA!");
                  }
                  }while(opAcao < 0 || opAcao > 3);
                  if(opAcao == 0){
                    break;}
                  do{
                  printf("\nInsira a quantidade:\n-> ");
                  scanf("%d", &qtd);
                  if(qtd < 0){
                  puts("INSIRA UMA QUANTIDADE POSITIVA!\n");
                  }
                  }while(qtd < 0);
                  do{
                  printf("\nInsira o valor:\n-> ");
                  scanf("%f", &valor);
                  if(valor < 0){
                  puts("INSIRA UM VALOR POSITIVO!\n");
                  }
                  }while (valor < 0);
                  listaCompra = inserir_lista_compra(listaCompra, qtd, valor, opAcao);
                  break;
          case 2:
           printf("=====================================\n"
                  "||        OFERTA DE VENDA          ||\n"
                  "=====================================\n");
               do{
                  printf("Que ação deseja vender?\n");
                  printf("[1] | PETR4 (PETROBRAS)\n");
                  printf("[2] | VALE5 (VALE)\n");
                  printf("[3] | ITSA4 (ITAÚ)\n");
                  printf("[0] | VOLTAR\n-> ");
                  scanf("%d", &opAcao);
                  getchar();
                  if(opAcao < 0 || opAcao > 3){
                    puts("OPÇAO INVÁLIDA!");
                  }
                  }while(opAcao < 0 || opAcao > 3);
                  if(opAcao == 0){
                    break;}
                  do{
                  printf("\nInsira a quantidade:\n-> ");
                  scanf("%d", &qtd);
                  if(qtd < 0){
                  puts("INSIRA UMA QUANTIDADE POSITIVA!\n");
                  }
                  }while(qtd < 0);
                  do{
                  printf("\nInsira o valor:\n-> ");
                  scanf("%f", &valor);
                  if(valor < 0){
                  puts("INSIRA UM VALOR POSITIVO!\n");
                  }
                  }while (valor < 0);
                  listaVenda = inserir_lista_venda(listaVenda, qtd, valor, opAcao);
                  break;
          default:
          break;
          }
    }while (resposta != 0);
}
void listarOfertas(){
  int resposta;
  int opAcao;
  do{
    printf( "\n=====================================\n"
            "||          MENU - LISTAR          ||\n"
            "=====================================\n"
            "[1] | Todas\n"
            "[2] | Compra\n"
            "[3] | Venda\n"
            "[0] | Voltar \n-> " );
        scanf("%d", &resposta);
        getchar();
        switch(resposta){
          case 1:
            consultar_lista_compra(listaCompra);
            consultar_lista_venda(listaVenda);
          break;
          case 2:
            do{
            printf( "\n=====================================\n"
                    "||         LISTAR - COMPRA         ||\n"
                    "=====================================\n"
                    "[1] | Todas\n"
                    "[2] | PETR4\n"
                    "[3] | VALE5\n"
                    "[4] | ITSA4\n"
                    "[0] | VOLTAR \n-> " );
                    scanf("%d", &opAcao);
                    getchar();
            if(opAcao == 0){
              break;}
            if(opAcao == 1){
            consultar_lista_compra(listaCompra);
            break;
            }else{
            consultar_lista_individual(listaCompra, opAcao);}
              }while(opAcao < 1 || opAcao > 4);
          break;
          case 3:
            do{
            printf( "\n=====================================\n"
                    "||          LISTAR - VENDA         ||\n"
                    "=====================================\n"
                    "[1] | Todas\n"
                    "[2] | PETR4\n"
                    "[3] | VALE5\n"
                    "[4] | ITSA4\n"
                    "[0] | VOLTAR \n-> " );
                    scanf("%d", &opAcao);
                    getchar();
            if(opAcao == 0){
              break;}
            if(opAcao == 1){
              consultar_lista_venda(listaVenda);
              break;
            }else{
            consultar_lista_venda_individual(listaVenda, opAcao);}
              }while(opAcao < 1 || opAcao > 4);
              break;
          default:
          break;
          }
    }while (resposta != 0);
}
void negociarOfertas(){
  int resposta;
  selectsortCompra(listaCompra);
  selectsortVenda(listaVenda);
  consultar_registro(listaRegistro);
  do{
     printf( "\n=====================================\n"
             "||            NEGOCIAR             ||\n"
             "=====================================\n"
             "[1] | TODAS\n"
             "[2] | PETR4\n"
             "[3] | VALE5\n"
             "[4] | ITSA4\n"
             "[0] | VOLTAR \n-> " );
             scanf("%d", &resposta);
             getchar();
        if(resposta == 0){
              break;}
        if(resposta == 1){
            realizarOperacoes(listaRegistro, listaCompra, listaVenda);
            consultar_lista_compra(listaCompra);
            consultar_lista_venda(listaVenda);
        }if(resposta == 2){
            consultar_lista_venda_individual(listaVenda, 1);
            consultar_lista_individual(listaCompra, 1);
            realizarOperacoesIndividuais(1, listaRegistro, listaCompra, listaVenda);
        }if(resposta == 3){
            consultar_lista_venda_individual(listaVenda, 2);
            consultar_lista_individual(listaCompra, 2);
            realizarOperacoesIndividuais(2, listaRegistro, listaCompra, listaVenda);
        }if(resposta == 4){
            consultar_lista_venda_individual(listaVenda, 3);
            consultar_lista_individual(listaCompra, 3);
            realizarOperacoesIndividuais(3, listaRegistro, listaCompra, listaVenda);
        }
    }while(resposta != 0);
}

void realizarOperacoesIndividuais(int sigla, Registro* l, Compra* listaCompra, Venda* listaVenda){
  Compra *referenciaCompra = listaCompra;
  for(referenciaCompra = listaCompra; referenciaCompra!= NULL; referenciaCompra = referenciaCompra->prox){
  Venda *referenciaVenda = listaVenda;
    for(referenciaVenda = listaVenda; referenciaVenda!= NULL; referenciaVenda =   referenciaVenda->prox){
        int siglaCompra = referenciaCompra->sigla;
        int siglaVenda = referenciaVenda->sigla;
        int qtdCompra = referenciaCompra->qtd;
        int qtdVenda = referenciaVenda->qtd;
        float valorCompra = referenciaCompra->valor;
        float valorVenda = referenciaVenda->valor;
        if(siglaCompra == sigla && siglaVenda == sigla){
          if(valorCompra >= valorVenda){
            if(qtdCompra > qtdVenda){
              inserir_lista_registro(listaRegistro, qtdVenda, valorCompra, siglaCompra);
              referenciaCompra->qtd = qtdCompra  - qtdVenda;
              RemoveDadoEspecificoVenda(qtdVenda, siglaVenda, valorVenda, listaVenda);
              printf("\t\t||Operação Realizadas||\n");
          if(siglaCompra == 1){
        		printf("\t\t||PETR4 C %3d R$%5.2f||\n", qtdCompra, valorCompra);
            }
            if(siglaCompra == 2){
        		printf("\t\t||VALE5 C %3d R$%5.2f||\n", qtdCompra, valorCompra);
            } 
            if(siglaCompra == 3){
        		printf("\t\t||ITSA4 C %3d R$%5.2f||\n", qtdCompra, valorCompra);
            }
            if(siglaVenda == 1){
        		printf("\t\t||PETR4 V %3d R$%5.2f||\n\n", qtdVenda, valorVenda);
            }
            if(siglaVenda == 2){
        		printf("\t\t||VALE5 V %3d R$%5.2f||\n\n", qtdVenda, valorVenda);
            } 
            if(siglaVenda == 3){
        		printf("\t\t||ITSA4 V %3d R$%5.2f||\n\n", qtdVenda, valorVenda);
            }
            }else if(qtdCompra < qtdVenda){
              inserir_lista_registro(listaRegistro, qtdCompra, valorVenda, siglaCompra);
              referenciaVenda->qtd = qtdVenda - qtdCompra;
              RemoveDadoEspecifico(qtdCompra, siglaCompra, valorCompra, listaCompra);
              printf("\t\t||Operação Realizadas||\n");
              if(siglaCompra == 1){
        		printf("\t\t||PETR4 C %3d R$%5.2f||\n", qtdCompra, valorCompra);
            }
            if(siglaCompra == 2){
        		printf("\t\t||VALE5 C %3d R$%5.2f||\n", qtdCompra, valorCompra);
            } 
            if(siglaCompra == 3){
        		printf("\t\t||ITSA4 C %3d R$%5.2f||\n", qtdCompra, valorCompra);
            }
            if(siglaVenda == 1){
        		printf("\t\t||PETR4 V %3d R$%5.2f||\n\n", qtdVenda, valorVenda);
            }
            if(siglaVenda == 2){
        		printf("\t\t||VALE5 V %3d R$%5.2f||\n\n", qtdVenda, valorVenda);
            } 
            if(siglaVenda == 3){
        		printf("\t\t||ITSA4 V %3d R$%5.2f||\n\n", qtdVenda, valorVenda);
            }
            }
            else if (qtdCompra == qtdVenda){
              inserir_lista_registro(listaRegistro, qtdCompra, valorCompra, siglaCompra);
              RemoveDadoEspecificoVenda(qtdVenda, siglaVenda, valorVenda, listaVenda);
              RemoveDadoEspecifico(qtdCompra, siglaCompra, valorCompra, listaCompra);
              printf("\t\t||Operação Realizada||\n");
              if(siglaCompra == 1){
        		printf("\t\t||PETR4 C %3d R$%5.2f||\n", qtdCompra, valorCompra);
            }
            if(siglaCompra == 2){
        		printf("\t\t||VALE5 C %3d R$%5.2f||\n", qtdCompra, valorCompra);
            } 
            if(siglaCompra == 3){
        		printf("\t\t||ITSA4 C %3d R$%5.2f||\n", qtdCompra, valorCompra);
            }
            if(siglaVenda == 1){
        		printf("\t\t||PETR4 V %3d R$%5.2f||\n\n", qtdVenda, valorVenda);
            }
            if(siglaVenda == 2){
        		printf("\t\t||VALE5 V %3d R$%5.2f||\n\n", qtdVenda, valorVenda);
            } 
            if(siglaVenda == 3){
        		printf("\t\t||ITSA4 V %3d R$%5.2f||\n\n", qtdVenda, valorVenda);
            }
            }
            }
    }}}
    
  } 

void realizarOperacoes(Registro* l, Compra* listaCompra, Venda* listaVenda){
  Compra *referenciaCompra = listaCompra;
  for(referenciaCompra = listaCompra; referenciaCompra!= NULL; referenciaCompra = referenciaCompra->prox){
  Venda *referenciaVenda = listaVenda;
    for(referenciaVenda = listaVenda; referenciaVenda!= NULL; referenciaVenda =   referenciaVenda->prox){
        int siglaCompra = referenciaCompra->sigla;
        int siglaVenda = referenciaVenda->sigla;
        int qtdCompra = referenciaCompra->qtd;
        int qtdVenda = referenciaVenda->qtd;
        float valorCompra = referenciaCompra->valor;
        float valorVenda = referenciaVenda->valor;
        if(siglaCompra == siglaVenda){
          if(valorCompra >= valorVenda){
            if(qtdCompra > qtdVenda){
              inserir_lista_registro(listaRegistro, qtdVenda, valorCompra, siglaCompra);
              referenciaCompra->qtd = qtdCompra  - qtdVenda;
              RemoveDadoEspecificoVenda(qtdVenda, siglaVenda, valorVenda, listaVenda);
              printf("\t\t||Operação Realizadas||\n");
              if(siglaCompra == 1){
          		printf("\t\t||PETR4 C %3d R$%5.2f||\n", qtdCompra, valorCompra);
              }
              if(siglaCompra == 2){
          		printf("\t\t||VALE5 C %3d R$%5.2f||\n", qtdCompra, valorCompra);
              } 
              if(siglaCompra == 3){
          		printf("\t\t||ITSA4 C %3d R$%5.2f||\n", qtdCompra, valorCompra);
              }
              if(siglaVenda == 1){
          		printf("\t\t||PETR4 V %3d R$%5.2f||\n\n", qtdVenda, valorVenda);
              }
              if(siglaVenda == 2){
          		printf("\t\t||VALE5 V %3d R$%5.2f||\n\n", qtdVenda, valorVenda);
              } 
              if(siglaVenda == 3){
          		printf("\t\t||ITSA4 V %3d R$%5.2f||\n\n", qtdVenda, valorVenda);
              }
              }else if(qtdCompra < qtdVenda){
              inserir_lista_registro(listaRegistro, qtdCompra, valorVenda, siglaCompra);              
              referenciaVenda->qtd = qtdVenda - qtdCompra;
              RemoveDadoEspecifico(qtdCompra, siglaCompra, valorCompra, listaCompra);
              printf("\t\t||Operação Realizadas||\n");
              if(siglaCompra == 1){
          		printf("\t\t||PETR4 C %3d R$%5.2f||\n", qtdCompra, valorCompra);
              }
              if(siglaCompra == 2){
          		printf("\t\t||VALE5 C %3d R$%5.2f||\n", qtdCompra, valorCompra);
              } 
              if(siglaCompra == 3){
          		printf("\t\t||ITSA4 C %3d R$%5.2f||\n", qtdCompra, valorCompra);
              }
              if(siglaVenda == 1){
          		printf("\t\t||PETR4 V %3d R$%5.2f||\n\n", qtdVenda, valorVenda);
              }
              if(siglaVenda == 2){
          		printf("\t\t||VALE5 V %3d R$%5.2f||\n\n", qtdVenda, valorVenda);
              } 
              if(siglaVenda == 3){
          		printf("\t\t||ITSA4 V %3d R$%5.2f||\n\n", qtdVenda, valorVenda);
              }
              }
              else if (qtdCompra == qtdVenda){
              inserir_lista_registro(listaRegistro, qtdCompra, valorCompra, siglaCompra);
              RemoveDadoEspecificoVenda(qtdVenda, siglaVenda, valorVenda, listaVenda);
              RemoveDadoEspecifico(qtdCompra, siglaCompra, valorCompra, listaCompra);
              printf("\t\t||Operação Realizada||\n");
              if(siglaCompra == 1){
        		printf("\t\t||PETR4 C %3d R$%5.2f||\n", qtdCompra, valorCompra);
            }
            if(siglaCompra == 2){
        		printf("\t\t||VALE5 C %3d R$%5.2f||\n", qtdCompra, valorCompra);
            } 
            if(siglaCompra == 3){
        		printf("\t\t||ITSA4 C %3d R$%5.2f||\n", qtdCompra, valorCompra);
            }
            if(siglaVenda == 1){
        		printf("\t\t||PETR4 V %3d R$%5.2f||\n\n", qtdVenda, valorVenda);
            }
            if(siglaVenda == 2){
        		printf("\t\t||VALE5 V %3d R$%5.2f||\n\n", qtdVenda, valorVenda);
            } 
            if(siglaVenda == 3){
        		printf("\t\t||ITSA4 V %3d R$%5.2f||\n\n", qtdVenda, valorVenda);
            }
            }
            }
    }}} 
} 
void inserir_lista_registro(Registro* l, int qtd, float valor, int sigla){
	Registro* acoesRegistro= (Registro*) malloc(sizeof(Registro));
  acoesRegistro->sigla = sigla;
	acoesRegistro->qtd = qtd;
  acoesRegistro->valor = valor;
	acoesRegistro->prox = l;
  }
void consultar_registro(Registro* inicioRegistro){
	Registro *referencia = inicioRegistro;
  if (referencia == NULL){
   printf("\nNENHUMA NEGOCIAÇÃO FOI REALIZADA ATÉ O MOMENTO!\n");
  }else{
    printf( "\nA útlima ação comprada foi:\n");
    if(referencia->sigla == 1){
		printf("\t\tPETR4 | %3d unidades | Pelo valor de: R$5%.2f\n", referencia->qtd, referencia->valor);
    }
    if(referencia->sigla == 2){
		printf("\t\tVALE5 | %3d unidades | Pelo valor de: R$5%.2f\n", referencia->qtd, referencia->valor);
    }
    if(referencia->sigla == 3){
		printf("\t\tITSA4 | %3d unidades | Pelo valor de: R$5%.2f\n", referencia->qtd, referencia->valor);
    }
  }
}
Venda* inserir_lista_venda(Venda* l, int qtd, float valor, int sigla){
	Venda* acoesVenda= (Venda*) malloc(sizeof(Venda));
  acoesVenda->sigla = sigla;
	acoesVenda->qtd = qtd;
  acoesVenda->valor = valor;
	acoesVenda->prox = l;
	return acoesVenda;
  }
void consultar_lista_venda(Venda* inicioVenda){
	Venda *referencia = inicioVenda;
  if (referencia == NULL){
   printf("\nNENHUMA OFERTA DE VENDA DISPONÍVEL!\n");
  }else{
  printf("\n=====================================\n"
         "          OFERTAS DE VENDA            \n"
         "=====================================\n");
	for(referencia = inicioVenda; referencia!= NULL; referencia = referencia->prox){
    if(referencia->sigla == 1){
		printf("\t\tPETR4 V %3d R$%5.2f\n", referencia->qtd, referencia->valor);
    } }
    for(referencia = inicioVenda; referencia!= NULL; referencia = referencia->prox){
    if(referencia->sigla == 2){
		printf("\t\tVALE5 V %3d R$%5.2f\n", referencia->qtd, referencia->valor);
    } }
    for(referencia = inicioVenda; referencia!= NULL; referencia = referencia->prox){
    if(referencia->sigla == 3){
		printf("\t\tITSA4 V %3d R$%5.2f\n", referencia->qtd, referencia->valor);
    }}
  }
}
void consultar_lista_venda_individual(Venda* inicioVenda, int opAcao){
	Venda *referencia = inicioVenda;
  if(referencia == NULL){
   printf("\nNENHUMA OFERTA DE VENDA DISPONÍVEL!\n");
  }else{
  printf("\n=====================================\n"
         "          OFERTAS DE VENDA            \n"
         "=====================================\n");
  if(opAcao == 2){
    for(referencia = inicioVenda; referencia!= NULL; referencia = referencia->prox){
    if(referencia->sigla == 1){
		printf("\t\tPETR4 V %3d R$%5.2f\n", referencia->qtd, referencia->valor);
    }}
  }
  if(opAcao == 3){
    for(referencia = inicioVenda; referencia!= NULL; referencia = referencia->prox){
    if(referencia->sigla == 2){
		printf("\t\tVALE5 V %3d R$%5.2f\n", referencia->qtd, referencia->valor);
    }}
  }
  if(opAcao == 4){
    for(referencia = inicioVenda; referencia!= NULL; referencia = referencia->prox){
    if(referencia->sigla == 3){
		printf("\t\tITSA4 V %3d R$%5.2f\n", referencia->qtd, referencia->valor);
      }  }
    }
  }
}
Venda *RemoveDadoEspecificoVenda(int qtd, int sigla, float valor, Venda *ptr){
	Venda* busca;
	Venda* anterior;
	anterior = NULL;
	busca = ptr;
	while (busca != NULL) {
		if (busca->sigla == sigla) {
      if (busca->qtd == qtd){
        if (busca->valor == valor){
    			if (anterior != NULL){
    				anterior->prox = busca -> prox;
    			}else{
    				ptr = busca-> prox;
    			}
			free(busca);
		}}}
		anterior = busca;
		busca = busca->prox;
	}
  return NULL;
}
Compra* inserir_lista_compra(Compra* l, int qtd, float valor, int sigla){
	Compra* acoesCompra= (Compra*) malloc(sizeof(Compra));
  acoesCompra->sigla = sigla;
	acoesCompra->qtd = qtd;
  acoesCompra->valor = valor;
	acoesCompra->prox = l;
	return acoesCompra;
}
void consultar_lista_compra(Compra* inicioCompra){
	Compra *referencia = inicioCompra;
  if (referencia == NULL){
   printf("\nNENHUMA OFERTA DE COMPRA DISPONÍVEL!\n");
  }else{
  printf("\n=====================================\n"
         "          OFERTAS DE COMPRA            \n"
         "=====================================\n");
	for(referencia = inicioCompra; referencia!= NULL; referencia = referencia->prox){
    if(referencia->sigla == 1){
		printf("\t\tPETR4 C %3d R$%5.2f\n", referencia->qtd, referencia->valor);
    }}
    for(referencia = inicioCompra; referencia!= NULL; referencia = referencia->prox){
    if(referencia->sigla == 2){
		printf("\t\tVALE5 C %3d R$%5.2f\n", referencia->qtd, referencia->valor);
    }}
    for(referencia = inicioCompra; referencia!= NULL; referencia = referencia->prox){
    if(referencia->sigla == 3){
		printf("\t\tITSA4 C %3d R$%5.2f\n", referencia->qtd, referencia->valor);
    }}
  }
}
void consultar_lista_individual(Compra* inicioCompra, int opAcao){
	Compra *referencia = inicioCompra;
  if (referencia == NULL){
   printf("\nNENHUMA OFERTA DE COMPRA DISPONÍVEL!\n");
  }else{
  printf("\n=====================================\n"
         "          OFERTAS DE COMPRA            \n"
         "=====================================\n");
  if(opAcao == 2){
    for(referencia = inicioCompra; referencia!= NULL; referencia = referencia->prox){
    if(referencia->sigla == 1){
		printf("\t\tPETR4 C %3d R$%5.2f\n", referencia->qtd, referencia->valor);
    }}  }
  if(opAcao == 3){
    for(referencia = inicioCompra; referencia!= NULL; referencia = referencia->prox){
    if(referencia->sigla == 2){
		printf("\t\tVALE5 C %3d R$%5.2f\n", referencia->qtd, referencia->valor);
    }}
  }
  if(opAcao == 4){
    for(referencia = inicioCompra; referencia!= NULL; referencia = referencia->prox){
    if(referencia->sigla == 3){
		printf("\t\tITSA4 C %3d R$%5.2f\n", referencia->qtd, referencia->valor);
      }  }
    }
  }
}
Compra *RemoveDadoEspecifico(int qtd, int sigla, float valor, Compra *ptr){
	Compra* busca;
	Compra* anterior;
	anterior = NULL;
	busca = ptr;
	while (busca != NULL) {
		if (busca->sigla == sigla) {
      if (busca->qtd == qtd){
        if (busca->valor == valor){
    			if (anterior != NULL){
    				anterior->prox = busca -> prox;
    			}else{
    				ptr = busca-> prox;
    			}
			free(busca);
		}}}
		anterior = busca;
		busca = busca->prox;
	}
  return NULL;
}
void selectsortCompra(Compra *p) {
     Compra *i, *j, *aux;
     aux = (Compra *)malloc (sizeof (Compra));
     i = p;
     while( i != NULL) {
            j = i->prox;
            while (j != NULL) {
                   if (i->valor < j->valor){
                         *aux = *i ;
                         *i =  *j; 
                         i->prox = aux->prox;
                         aux->prox = j->prox;
                         *j = *aux;
                          j->prox = aux->prox; 
                   }
                   j = j->prox;
            }
      i = i->prox;
    }
}
void selectsortVenda(Venda *p) {
     Venda *i, *j, *aux;
     aux = (Venda *)malloc (sizeof (Venda));
     i = p;
     while( i != NULL) {
            j = i->prox;
            while (j != NULL) {
                   if (i->valor > j->valor){
                         *aux = *i ; 
                         *i =  *j; 
                         i->prox = aux->prox; 
                         aux->prox = j->prox; 
                         *j = *aux;
                          j->prox = aux->prox;
                   }
                   j = j->prox;
            }
      i = i->prox;
    }
}
void arquivoCompras(){
    Compra arquivo;   
    FILE * file  = fopen("compras.txt","r");

    if(file == NULL){
    	printf("Não foi possível abrir o arquivo.\n");
    }else{
        while (fscanf(file, "%d %d %f", &arquivo.sigla,&arquivo.qtd,&arquivo.valor) != EOF ){
            listaCompra = inserir_lista_compra(listaCompra,arquivo.qtd, arquivo.valor, arquivo.sigla);
        }
    }
    fclose(file);
}
void arquivoVendas(){
    Venda arquivo;   
    FILE * file  = fopen("vendas.txt","r");

    if(file == NULL){
    	printf("Não foi possível abrir o arquivo.\n");
    }else{
        while (fscanf(file, "%d %d %f", &arquivo.sigla,&arquivo.qtd,&arquivo.valor) != EOF ){
            listaVenda = inserir_lista_venda(listaVenda,arquivo.qtd, arquivo.valor, arquivo.sigla);
        }
    }
    fclose(file);
}
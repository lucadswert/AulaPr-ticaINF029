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
                  inserir_ordenado(&listaCompra, qtd, valor, opAcao);
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
                  inserir_ordenado_venda(&listaVenda, qtd, valor, opAcao);
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
  consultar_registro(listaRegistroPETRA,listaRegistroVALE, listaRegistroITSA);
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
           listaRegistroPETRA = realizarOperacoesPETRA(listaRegistroPETRA, 1, listaCompra, listaVenda);
           listaRegistroITSA = realizarOperacoesITSA(listaRegistroITSA, 3, listaCompra, listaVenda);
           listaRegistroVALE = realizarOperacoesVALE(listaRegistroVALE, 2, listaCompra, listaVenda);
            consultar_lista_compra(listaCompra);
            consultar_lista_venda(listaVenda);
          }
        if(resposta == 2){
          listaRegistroPETRA = realizarOperacoesPETRA(listaRegistroPETRA, 1, listaCompra, listaVenda);
          break;}
        if(resposta == 3){
          listaRegistroVALE = realizarOperacoesVALE(listaRegistroVALE, 2, listaCompra, listaVenda);
          break;}
        if(resposta == 4){
          listaRegistroITSA = realizarOperacoesITSA(listaRegistroITSA, 3, listaCompra, listaVenda);
          break;}
    }while(resposta != 0);
}

Registro* realizarOperacoesPETRA(Registro* l, int sigla, Compra* listaCompra, Venda* listaVenda){
  Registro* referenciaRegistroPETRA = l;
  int siglaTemp = 0, qtdTemp = 0;
  float valorTemp = 0;

  for(Compra *referenciaCompra = listaCompra; referenciaCompra != NULL; referenciaCompra = referenciaCompra->prox){
    for(Venda *referenciaVenda = listaVenda; referenciaVenda!= NULL; referenciaVenda =   referenciaVenda->prox){
        int siglaCompra = referenciaCompra->sigla;
        int siglaVenda = referenciaVenda->sigla;
        int qtdCompra = referenciaCompra->qtd;
        int qtdVenda = referenciaVenda->qtd;
        float valorCompra = referenciaCompra->valor;
        float valorVenda = referenciaVenda->valor;
        if(siglaCompra == 1 && siglaVenda == 1){
          if(valorCompra >= valorVenda){
            if(qtdCompra > qtdVenda){
              siglaTemp = siglaCompra;
              qtdTemp = qtdVenda;
              valorTemp = valorCompra;
              referenciaCompra->qtd -= qtdVenda;
              printf("\t\t||Operação Realizadas||\n");
              if(siglaCompra == sigla){
          		printf("\t\t||PETR4 C %3d R$%5.2f||\n", qtdCompra, valorCompra);
              }
              if(siglaVenda == sigla){
          		printf("\t\t||PETR4 V %3d R$%5.2f||\n\n", qtdVenda, valorVenda);
              }
              RemoveDadoEspecificoVenda(qtdVenda, siglaVenda, valorVenda, listaVenda);
              }if(qtdCompra < qtdVenda){
              siglaTemp = siglaCompra;
              qtdTemp = qtdVenda;
              valorTemp = valorCompra; 
              referenciaVenda->qtd -= qtdCompra;  
              printf("\t\t||Operação Realizadas||\n");
              if(siglaCompra == sigla){
          		printf("\t\t||PETR4 C %3d R$%5.2f||\n", qtdCompra, valorCompra);
              }
              if(siglaVenda == sigla){
          		printf("\t\t||PETR4 V %3d R$%5.2f||\n\n", qtdVenda, valorVenda);
              }
              RemoveDadoEspecifico(qtdCompra, siglaCompra, valorCompra, listaCompra); 
            }
              if(qtdCompra == qtdVenda){
              siglaTemp = siglaCompra;
              qtdTemp = qtdCompra;
              valorTemp = valorVenda;
              printf("\t\t||Operação Realizada||\n");
              if(siglaCompra == sigla){
          		printf("\t\t||PETR4 C %3d R$%5.2f||\n", qtdCompra, valorCompra);
              }
              if(siglaVenda == sigla){
          		printf("\t\t||PETR4 V %3d R$%5.2f||\n\n", qtdVenda, valorVenda);
              }
              RemoveDadoEspecificoVenda(qtdVenda, siglaVenda, valorVenda, listaVenda);
              RemoveDadoEspecifico(qtdCompra, siglaCompra, valorCompra, listaCompra);
            }
          }
        }
      }
  }
  return inserir_lista_registro(listaRegistroPETRA, qtdTemp, valorTemp, siglaTemp);
} 

Registro* realizarOperacoesVALE(Registro* l, int sigla, Compra* listaCompra, Venda* listaVenda){
  Registro* referenciaRegistroVALE = l;
  int siglaTemp = 0, qtdTemp = 0;
  float valorTemp = 0;

  for(Compra *referenciaCompra = listaCompra; referenciaCompra != NULL; referenciaCompra = referenciaCompra->prox){
    for(Venda *referenciaVenda = listaVenda; referenciaVenda!= NULL; referenciaVenda =   referenciaVenda->prox){
        int siglaCompra = referenciaCompra->sigla;
        int siglaVenda = referenciaVenda->sigla;
        int qtdCompra = referenciaCompra->qtd;
        int qtdVenda = referenciaVenda->qtd;
        float valorCompra = referenciaCompra->valor;
        float valorVenda = referenciaVenda->valor;
        if(siglaCompra == sigla && siglaVenda == sigla){
          if(valorCompra >= valorVenda){
            if(qtdCompra > qtdVenda){
              siglaTemp = siglaCompra;
              qtdTemp = qtdVenda;
              valorTemp = valorCompra;
              referenciaCompra->qtd -= qtdVenda;
              printf("\t\t||Operação Realizadas||\n");
              if(siglaCompra == sigla){
          		printf("\t\t||VALE5 C %3d R$%5.2f||\n", qtdCompra, valorCompra);
              }
              if(siglaVenda == sigla){
          		printf("\t\t||VALE5 V %3d R$%5.2f||\n\n", qtdVenda, valorVenda);
              }
              RemoveDadoEspecificoVenda(qtdVenda, siglaVenda, valorVenda, listaVenda);
              }if(qtdCompra < qtdVenda){
              siglaTemp = siglaCompra;
              qtdTemp = qtdVenda;
              valorTemp = valorCompra; 
              referenciaVenda->qtd -= qtdCompra;  
              printf("\t\t||Operação Realizadas||\n");
              if(siglaCompra == sigla){
          		printf("\t\t||VALE5 C %3d R$%5.2f||\n", qtdCompra, valorCompra);
              }
              if(siglaVenda == sigla){
          		printf("\t\t||VALE5 V %3d R$%5.2f||\n\n", qtdVenda, valorVenda);
              }
              RemoveDadoEspecifico(qtdCompra, siglaCompra, valorCompra, listaCompra); 
            }
              if(qtdCompra == qtdVenda){
              siglaTemp = siglaCompra;
              qtdTemp = qtdCompra;
              valorTemp = valorVenda;
              printf("\t\t||Operação Realizada||\n");
              if(siglaCompra == sigla){
          		printf("\t\t||VALE5 C %3d R$%5.2f||\n", qtdCompra, valorCompra);
              }
              if(siglaVenda == sigla){
          		printf("\t\t||VALE5 V %3d R$%5.2f||\n\n", qtdVenda, valorVenda);
              }
              RemoveDadoEspecificoVenda(qtdVenda, siglaVenda, valorVenda, listaVenda);
              RemoveDadoEspecifico(qtdCompra, siglaCompra, valorCompra, listaCompra);
            }
          }
        }
      }
  }
  return inserir_lista_registro(listaRegistroVALE, qtdTemp, valorTemp, siglaTemp);
} 

Registro* realizarOperacoesITSA(Registro* l, int sigla, Compra* listaCompra, Venda* listaVenda){
  Registro* referenciaRegistroITSA = l;
  int siglaTemp = 0, qtdTemp = 0;
  float valorTemp = 0;

  for(Compra *referenciaCompra = listaCompra; referenciaCompra != NULL; referenciaCompra = referenciaCompra->prox){
    for(Venda *referenciaVenda = listaVenda; referenciaVenda!= NULL; referenciaVenda =   referenciaVenda->prox){
        int siglaCompra = referenciaCompra->sigla;
        int siglaVenda = referenciaVenda->sigla;
        int qtdCompra = referenciaCompra->qtd;
        int qtdVenda = referenciaVenda->qtd;
        float valorCompra = referenciaCompra->valor;
        float valorVenda = referenciaVenda->valor;
        if(siglaCompra == sigla && siglaVenda == sigla){
          if(valorCompra >= valorVenda){
            if(qtdCompra > qtdVenda){
              siglaTemp = siglaCompra;
              qtdTemp = qtdVenda;
              valorTemp = valorCompra;
              referenciaCompra->qtd -= qtdVenda;
              printf("\t\t||Operação Realizadas||\n");
              RemoveDadoEspecificoVenda(qtdVenda, siglaVenda, valorVenda, listaVenda);
              if(siglaCompra == sigla){
          		printf("\t\t||ITSA4 C %3d R$%5.2f||\n", qtdCompra, valorCompra);
              }
              if(siglaVenda == sigla){
          		printf("\t\t||ITSA4 V %3d R$%5.2f||\n\n", qtdVenda, valorVenda);
              }
              }if(qtdCompra < qtdVenda){
              siglaTemp = siglaCompra;
              qtdTemp = qtdVenda;
              valorTemp = valorCompra; 
              referenciaVenda->qtd -= qtdCompra;  
              RemoveDadoEspecifico(qtdCompra, siglaCompra, valorCompra, listaCompra); 
              printf("\t\t||Operação Realizadas||\n");
              if(siglaCompra == sigla){
          		printf("\t\t||ITSA4 C %3d R$%5.2f||\n", qtdCompra, valorCompra);
              }
              if(siglaVenda == sigla){
          		printf("\t\t||ITSA4 V %3d R$%5.2f||\n\n", qtdVenda, valorVenda);
              }
            }
              if(qtdCompra == qtdVenda){
              siglaTemp = siglaCompra;
              qtdTemp = qtdCompra;
              valorTemp = valorVenda;
              RemoveDadoEspecificoVenda(qtdVenda, siglaVenda, valorVenda, listaVenda);
              RemoveDadoEspecifico(qtdCompra, siglaCompra, valorCompra, listaCompra);
              printf("\t\t||Operação Realizada||\n");
              if(siglaCompra == sigla){
          		printf("\t\t||ITSA4 C %3d R$%5.2f||\n", qtdCompra, valorCompra);
              }
              if(siglaVenda == sigla){
          		printf("\t\t||ITSA4 V %3d R$%5.2f||\n\n", qtdVenda, valorVenda);
              }
            }
          }
        }
      }
  }
  return inserir_lista_registro(listaRegistroITSA, qtdTemp, valorTemp, siglaTemp);
} 

Registro* inserir_lista_registro(Registro* l, int qtd, float valor, int sigla){
	Registro* acoesRegistro= (Registro*) malloc(sizeof(Registro));
  acoesRegistro->sigla = sigla;
	acoesRegistro->qtd = qtd;
  acoesRegistro->valor = valor;
	acoesRegistro->prox = l;
  return acoesRegistro;
}

void consultar_registro(Registro* inicioRegistroPETRA, Registro* inicioRegistroVALE, Registro* inicioRegistroITSA ){
	Registro *referenciaPETRA = inicioRegistroPETRA;
  Registro *referenciaVALE = inicioRegistroVALE;
  Registro *referenciaITSA = inicioRegistroITSA;
  if (referenciaPETRA == NULL){
   printf("\nNENHUMA NEGOCIAÇÃO DE PETR4 REALIZADA ATÉ O MOMENTO!\n");
  }else{
    printf( "\n\tA útlima ação de PETR4 comprada foi:\n");

		printf("PETR4 | %3d unidades | Pelo valor de: R$%5.2f\n", referenciaPETRA->qtd, referenciaPETRA->valor);
    }
  if (referenciaVALE == NULL){
   printf("\nNENHUMA NEGOCIAÇÃO DE VALE5 REALIZADA ATÉ O MOMENTO!\n");
  }else{
    printf( "\n\tA útlima ação de VALE5 comprada foi:\n");

		printf("VALE5 | %3d unidades | Pelo valor de: R$%5.2f\n", referenciaVALE->qtd, referenciaVALE->valor);
    }
  if (referenciaITSA == NULL){
   printf("\nNENHUMA NEGOCIAÇÃO DE ITSA4 REALIZADA ATÉ O MOMENTO!\n");
  }else{
    printf( "\n\tA útlima ação de ITSA4 comprada foi:\n");
		printf("ITSA4| %3d unidades | Pelo valor de: R$%5.2f\n", referenciaITSA->qtd, referenciaITSA->valor);
    }
}

void inserir_ordenado(Compra **lista, int qtd, float valor, int sigla){
    Compra *i, *j, *aux2;
    Compra *aux, *novo = malloc(sizeof(Compra));

    if(novo){
        novo->qtd = qtd;
        novo->valor = valor;
        novo->sigla = sigla;
        if(*lista == NULL){
            novo->prox = NULL;
            *lista = novo;
        }
        else if(novo->valor > (*lista)->valor){
            novo->prox = *lista;
            *lista = novo;
        }
        else{
            aux = *lista;
            while(aux->prox && novo->valor < aux->prox->valor)
                aux = aux->prox;
            novo->prox = aux->prox;
            aux->prox = novo;
        }
    }
    else{
        printf("Erro ao alocar memoria!\n");}
}

void inserir_ordenado_venda(Venda **lista, int qtd, float valor, int sigla){
    Venda *aux, *novo = malloc(sizeof(Venda));

    if(novo){
        novo->qtd = qtd;
        novo->valor = valor;
        novo->sigla = sigla;
        // a lista está vazia?
        if(*lista == NULL){
            novo->prox = NULL;
            *lista = novo;
        } // é o menor?
        else if(novo->valor < (*lista)->valor){
            novo->prox = *lista;
            *lista = novo;
        }
        else{
            aux = *lista;
            while(aux->prox && novo->valor > aux->prox->valor)
                aux = aux->prox;
            novo->prox = aux->prox;
            aux->prox = novo;
        }
    }
    else
        printf("Erro ao alocar memoria!\n");
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
void arquivoVendas(){
    Venda arquivo;   
    FILE * file  = fopen("vendas.txt","r");

    if(file == NULL){
    	printf("Não foi possível abrir o arquivo.\n");
    }else{
        while (fscanf(file, "%d %d %f", &arquivo.sigla,&arquivo.qtd,&arquivo.valor) != EOF ){
            inserir_ordenado_venda(&listaVenda,arquivo.qtd, arquivo.valor, arquivo.sigla);
        }
    }
    fclose(file);
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
void arquivoCompras(){
    Compra arquivo;   
    FILE * file  = fopen("compras.txt","r");

    if(file == NULL){
    	printf("Não foi possível abrir o arquivo.\n");
    }else{
        while (fscanf(file, "%d %d %f", &arquivo.sigla,&arquivo.qtd,&arquivo.valor) != EOF ){
            inserir_ordenado(&listaCompra, arquivo.qtd, arquivo.valor, arquivo.sigla);
        }
    }
    fclose(file);
}

#ifndef COMPRA_H
#define COMPRA_H

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
		printf("PETR4 C %d R$%.2f\n", referencia->qtd, referencia->valor);
    }}
    for(referencia = inicioCompra; referencia!= NULL; referencia = referencia->prox){
    if(referencia->sigla == 2){
		printf("VALE5 C %d R$%.2f\n", referencia->qtd, referencia->valor);
    }}
    for(referencia = inicioCompra; referencia!= NULL; referencia = referencia->prox){
    if(referencia->sigla == 3){
		printf("ITSA4 C %d R$%.2f\n", referencia->qtd, referencia->valor);
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
		printf("PETR4 C %d R$%.2f\n", referencia->qtd, referencia->valor);
    }}  }
  if(opAcao == 3){
    for(referencia = inicioCompra; referencia!= NULL; referencia = referencia->prox){
    if(referencia->sigla == 2){
		printf("VALE5 C %d R$%.2f\n", referencia->qtd, referencia->valor);
    }}
  }
  if(opAcao == 4){
    for(referencia = inicioCompra; referencia!= NULL; referencia = referencia->prox){
    if(referencia->sigla == 3){
		printf("ITSA4 C %d R$%.2f\n", referencia->qtd, referencia->valor);
      }  }
    }
  }
}

Compra* apagaCompras(Compra* listaCompra){
    Compra* p = listaCompra;
    while(p!=NULL){
        Compra* t = p->prox;
        free(p);
        p = t;
    } 
    return p;
}

Compra *RemoveDado(int dado, Compra *ptr){
	Compra* busca;
	Compra* anterior;
	anterior = NULL;
	busca = ptr;
	while (busca != NULL) {
		if (busca->sigla == dado) {
			if (anterior != NULL){
				anterior->prox = busca -> prox;
			}else{
				ptr = busca-> prox;
			}
			free(busca);
		}
		anterior = busca;
		busca = busca->prox;
	}
  return NULL;
}

Compra *RemoveDadoEspecifico(int qtd, int sigla, float valor, Compra *ptr){
	Compra* busca;
	Compra* anterior;
	anterior = NULL;
	busca = ptr;
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
  return NULL;
}

#endif


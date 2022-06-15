#ifndef VENDA_H
#define VENDA_H

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
		printf("PETR4 V %d R$%.2f\n", referencia->qtd, referencia->valor);
    } }
    for(referencia = inicioVenda; referencia!= NULL; referencia = referencia->prox){
    if(referencia->sigla == 2){
		printf("VALE5 V %d R$%.2f\n", referencia->qtd, referencia->valor);
    } }
    for(referencia = inicioVenda; referencia!= NULL; referencia = referencia->prox){
    if(referencia->sigla == 3){
		printf("ITSA4 V %d R$%.2f\n", referencia->qtd, referencia->valor);
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
		printf("PETR4 V %d R$%.2f\n", referencia->qtd, referencia->valor);
    }}
  }
  if(opAcao == 3){
    for(referencia = inicioVenda; referencia!= NULL; referencia = referencia->prox){
    if(referencia->sigla == 2){
		printf("VALE5 V %d R$%.2f\n", referencia->qtd, referencia->valor);
    }}
  }
  if(opAcao == 4){
    for(referencia = inicioVenda; referencia!= NULL; referencia = referencia->prox){
    if(referencia->sigla == 3){
		printf("ITSA4 V %d R$%.2f\n", referencia->qtd, referencia->valor);
      }  }
    }
  }
}

Venda* apagaVendas(Venda* listaVenda){
    Venda* p = listaVenda;
    while(p!=NULL){
        Venda* t = p->prox;
        free(p);
        p = t;
    } 
    return p;
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

Venda *RemoveDadoVenda(int dado, Venda *ptr){
	Venda* busca;
	Venda* anterior;
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

#endif  // FUNCOES_H

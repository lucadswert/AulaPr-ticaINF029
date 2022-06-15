#ifndef REGISTRO_H
#define REGISTRO_H

Registro* realizarOperacoes(Registro* l, Compra* listaCompra, Venda* listaVenda){
  Compra *referenciaCompra = listaCompra;
  Venda *referenciaVenda = listaVenda;
  
        int siglaCompra = referenciaCompra->sigla, siglaVenda = referenciaVenda->sigla;
        int qtdCompra = referenciaCompra->qtd, qtdVenda = referenciaVenda->qtd;
        float valorCompra = referenciaCompra->valor, valorVenda = referenciaVenda->valor;


  for(referenciaCompra = listaCompra; referenciaCompra!= NULL; referenciaCompra = referenciaCompra->prox){
    for(referenciaVenda = listaVenda; referenciaVenda!= NULL; referenciaVenda =   referenciaVenda->prox){
      puts("baw");
        printf("SIGLA:%d\n",siglaCompra);
        if(siglaCompra == siglaVenda){
          if(valorCompra > valorVenda || valorCompra == valorVenda ){
            if(qtdCompra > qtdVenda){
              Registro* acoesRegistro= (Registro*) malloc(sizeof(Registro));
              acoesRegistro->sigla = siglaCompra;
              acoesRegistro->valor = valorCompra;
              acoesRegistro->qtd = referenciaVenda->qtd;
      	      acoesRegistro->prox = l;
              referenciaCompra->qtd = qtdCompra  - qtdVenda;
              RemoveDadoEspecificoVenda(qtdVenda, siglaCompra, valorVenda, listaVenda);
              //printf("Operações Realizadas\n");
              //return acoesRegistro;
            }else if(qtdCompra < qtdVenda){
              Registro* acoesRegistro= (Registro*) malloc(sizeof(Registro));
              acoesRegistro->sigla = siglaCompra;
              acoesRegistro->valor = valorVenda;
              acoesRegistro->qtd = referenciaCompra->qtd;
              acoesRegistro->prox = l;
              referenciaVenda->qtd = qtdVenda - qtdCompra;
              RemoveDadoEspecifico(qtdCompra, siglaCompra, valorCompra, listaCompra);
              //printf("Operações Realizadas\n");
              //return acoesRegistro;
            }
            else if (qtdCompra == qtdVenda){
              Registro* acoesRegistro= (Registro*) malloc(sizeof(Registro));
              acoesRegistro->qtd = qtdCompra;
              acoesRegistro->sigla = siglaCompra;
              acoesRegistro->valor = valorCompra;
              acoesRegistro->prox = l;
              RemoveDadoEspecificoVenda(qtdVenda, siglaVenda, valorVenda, listaVenda);
              RemoveDadoEspecifico(qtdCompra, siglaCompra, valorCompra, listaCompra);
              //printf("Operações Realizadas\n");
              //return acoesRegistro;
            }
            }
    }}}
  return NULL;
  } 


Registro* inserir_lista_registro(Registro* l, int qtd, float valor, int sigla){
	Registro* acoesRegistro= (Registro*) malloc(sizeof(Registro));
  acoesRegistro->sigla = sigla;
	acoesRegistro->qtd = qtd;
  acoesRegistro->valor = valor;
	acoesRegistro->prox = l;
	return acoesRegistro;
  }

void consultar_registro(Registro* inicioRegistro){
	Registro *referencia = inicioRegistro;
  if (referencia == NULL){
   printf("\nNENHUMA NEGOCIAÇÃO FOI REALIZADA ATÉ O MOMENTO!\n");
  }else{
    printf( "\nA útlima ação comprada foi:\n");
    if(referencia->sigla == 1){
		printf("PETR4 | %d unidades | Pelo valor de: R$%.2f\n", referencia->qtd, referencia->valor);
    }
    if(referencia->sigla == 2){
		printf("VALE5 | %d unidades | Pelo valor de: R$%.2f\n", referencia->qtd, referencia->valor);
    }
    if(referencia->sigla == 3){
		printf("ITSA4 | %d unidades | Pelo valor de: R$%.2f\n", referencia->qtd, referencia->valor);
    }
  }
}
#endif  // FUNCOES_H

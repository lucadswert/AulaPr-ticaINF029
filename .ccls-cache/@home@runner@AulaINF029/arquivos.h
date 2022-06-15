#ifndef ARQUIVOS_H
#define ARQUIVOS_H

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

#endif  // FUNCOES_H
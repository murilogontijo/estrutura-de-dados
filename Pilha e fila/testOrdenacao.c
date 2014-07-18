#include <stdio.h>
#include "estruturas.h"
#include "ordenacao.h"
#include "impressao.h"


/**
 * Testes para os arquivos no ordenacao.h
 */
int main( ) {
	Lista lista;
	
	lista.ultimo = 3;
	Lista *l = &lista;
	
	lista.carros[0].codigo = 120;
	lista.carros[1].codigo = 121;
	lista.carros[2].codigo = 122;
	lista.carros[3].codigo = 123;
	
	lista.carros[0].ativo = 1;
	lista.carros[1].ativo = 1;
	lista.carros[2].ativo = 1;
	lista.carros[3].ativo = 1;
	
	int pos;
	
	retrocederTodoMundo(&lista, 2);
	imprimirLista(&lista);
	
	return 0;
	
}

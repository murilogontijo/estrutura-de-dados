#include <stdio.h>
#include <stdlib.h>     /* malloc, free, rand */
#include "estrutura.h"

/** insere um elemento */
void insere(no* pRaiz, caixa* elemento){
	
	printf("%u\n", pRaiz);
	
	if(!pRaiz){
		pRaiz = (no*) malloc(sizeof(no));
	}
	
	if(pRaiz == NULL) return;
	elemento->codPais = 2000;
	pRaiz->direita = NULL;
	pRaiz->esquerda = NULL;
	pRaiz->cx = *elemento;
	printf("%u\n", pRaiz);
}

int main(int argc, char **argv)
{
	no* pRaiz;
	caixa elementTest;
	elementTest.populacao = 1100;
	elementTest.codPais = 1000;
	
	
	insere(pRaiz, &elementTest);
	printf("%u\n", pRaiz);
	if(pRaiz != NULL){
		printf("%u\n", 000000);
	}
	
	
	return 0;
}

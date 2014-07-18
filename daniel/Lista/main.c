/*
Ana Letícia e Daniel Melo
Lista de carros - inclusão, exclusão, remoção e pesquisa.
*/
#include <stdio.h>
#include <string.h>
#include "estruturas.h"
#include "strings.h"
#include "impressao.h"
#include "ordenacao.h"
#include "cud.h"
#include "busca.h"


int main( )
{
	
	
	Lista lista;
	lista.ultimo =-1;
	
	int opcao;
	int controle = 1;
	
	limparTela();
	menu();
	scanf("%d", &opcao);
	
	
	while(controle !=0){
		switch (opcao){
			case 0:
				limparTela();
				controle = opcao;
			break;
			case 1:
				limparTela();
				imprimirLista(&lista);
			break;
			case 2:
				limparTela();
				lerNovoCarro(&lista);
				limparTela();
			break;
			case 3:
				limparTela();
				alterarCarro(&lista);
				limparTela();
			break;
			case 4:
				limparTela();
				apagarCarro(&lista);
				limparTela();
			break;
			case 5:
				limparTela();
				busca(&lista);
			break;
			default:
				limparTela();
				addMensagem(OPCAO_NAO_SUPORTADA);
		}
		
		
		menu();
		scanf("%d", &opcao);
	}
	return 0;
}



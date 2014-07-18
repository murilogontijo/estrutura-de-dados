#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "constantes.h"
#include "structs.h"
#include "user.h"
#include "system.h"

#include "GerenciamentoClientes.h"
#include "GerenciamentoEstoque.h"
#include "GestaoSupermercado.h"

int main(){
	
	/* Variáveis da main */
	int op = 0;
	T_listaClientes Clientes;
	T_listaProdutos Estoque;
	
	/* Inicialização das estruturas do sistema */
	criarListaClientes(&Clientes); //Criando listas de clientes
	criarListaProdutos(&Estoque);
	
	/* Definição das funções do programa */
	
	do {
		system("clear");
		printf("Menu principal\n\n");
		printf("Qual sistema você deseja acessar?\n");
		printf("Digite 0:\tPara finalizar o programa\n");
		printf("Digite 1:\tCadastro de Clientes\n");
		printf("Digite 2:\tGerenciamento de Estoque\n");
		printf("Digite 3:\tGestão do Supermercado\n");
		printf("Digite a opção desejada: ");
		scanf("%d", &op);
		
		getchar(); //serve para limpar o buffer do teclado antes do programa prosseguir
		
		switch(op) {
			case 0:
				printf("\n\nFinalizar gerenciamento de clientes?\n\n");
				if(telaConfirmacao() == true) travatela();
				else op = -1;
				break;
			case 1:
				GerenciamentoClientes(&Clientes);
				break;
			case 2:
				GerenciamentoEstoque(&Estoque);
				break;
			case 3:
				GestaoSupermercado(&Clientes, &Estoque);
				break;
			default:
				printf("Opção inválida\n");
				travatela();
				break;
		}
	}while(op != 0);
	
	return 0;
	
}

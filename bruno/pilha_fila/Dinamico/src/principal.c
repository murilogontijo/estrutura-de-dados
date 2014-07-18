#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "constantes.h"
#include "structs.h"
#include "user.h"
#include "sistema.h"

int main () {
	
	int op; // Para selecionar opção
	
	/* Essa variável validará se o expediente foi encerrado */
	int encerrado = false;
	
	/* Variável que atribuirá senhas */
	int senha = 1;
	
	/* Estrutura de dado que guardará a fila dinâmica */
	T_fila filaAtendimento;
	
	/* Tipo cliente para passagem em funções */
	T_cliente cliente;
	
	criarFilaVazia(&filaAtendimento);
	
	do {
		do {
			/* Quadro de opções disponíveis para o sistema de atendimento */
			system("clear");
			printf("Digite a opção que você deseja\n\n");
			printf("Digite 1:\tPara receber um cliente\n");
			printf("Digite 2:\tPara atender um cliente\n");
			printf("Digite 3:\tPara encerrar o expediente\n");
			printf("Digite 4:\tPara visualizar elementos da fila\n");
			printf("\nDigite a opção desejada: ");
			
			scanf("%d", &op);
			if (op > 4 || op < 1) {
				printf("\nOpção inválida\n");
				getchar();
				travatela();
			}
		} while (op > 4 || op < 1);
		
		getchar(); // limpar o buffer antes de entrar nas opções do sistema 
		
		switch(op) {
			
			/* =========================== Receber cliente ===========================*/
			case 1:
				system("clear");
				printf("Recepção de cliente\n\n");
				
				printf("Digite o nome do cliente: ");
				fgets(cliente.nome, CAR, stdin);
				
				do {
					printf("Digite a idade do cliente: ");
					scanf("%d", &cliente.idade);
					if(cliente.idade < 18) printf("Idade inválida. Cliente deve ter mais de 18 anos\n\n");
				}while(cliente.idade < 18);
				
				cliente.senha = senha;
				
				if(cliente.idade < 60) receberClienteNormal(&filaAtendimento, cliente);
				else receberClientePreferencial(&filaAtendimento, cliente);
				
				/* Ao final da recepção, deve-se incrementar a senha */
				senha++;
				
				printf("Cliente inserido com sucesso\n\n");
				getchar();
				travatela();
				
				break;
				
			/* =========================== Atender um cliente ===========================*/
			case 2:
				system("clear");
				printf("Atender um cliente\n\n");
				if(validarFilaVazia(&filaAtendimento) == false) {
					desempilharElemento(&filaAtendimento, &cliente);
					printf("Senhor(a) %s Idade: %d anos, Senha: %d favor comparecer ao caixa\n\n", cliente.nome, cliente.idade, cliente.senha);
				}
				else printf("Não tem cliente para atender\n");
				travatela();
				break;
				
			/* =========================== Encerrar sistema ===========================*/
			case 3:
				system("clear");
				printf("Encerrado expediente. Atenda os últimos clientes\n\n");
				encerrado = true;
				travatela();
				break;
			
			/* =========================== Visualizar fila do Banco ===========================*/
			case 4:
				system("clear");
				printf("Visualizar clientes da fila de atendimento\n\n");
				visualizarFila(&filaAtendimento);
				travatela();
		}
		
	} while (encerrado == false);
	
	while (validarFilaVazia(&filaAtendimento) == false) {
		system("clear");
		printf("Atender um cliente\n\n");
		desempilharElemento(&filaAtendimento, &cliente);
		printf("Senhor(a) %s Idade: %d anos, Senha: %d favor comparecer ao caixa\n\n", cliente.nome, cliente.idade, cliente.senha);
		printf("Pressione enter para atender o proximo cliente\n");
		travatela();
	}
	
	printf("Todos os clientes foram atendidos. A agência foi fechada\n");
	
	/* Boa prática de programação: libere toda memória da estrutura antes de finalizar a função */
	while( filaAtendimento.prim->prox != NULL ) free(filaAtendimento.prim->prox);
	
	return 0;

}

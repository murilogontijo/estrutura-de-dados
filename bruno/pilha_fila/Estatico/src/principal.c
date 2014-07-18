/*  == Descrissão do arquivo ==
 * 	Esse arquivo contém a função MAIN (principal) do programa que será utilizada para gerenciar o funcionamento do sistema e sua interação com o usuário.
 * 
 * 	== Lógica algorítmica ==
 * 	Os comentários, no decorrer do arquivo descrevem a lógica algorítmica. Caso algum script necessite ser detalhado, 
 * 	será descrito sua lógica nessa parte do arquivo.
 * */
#include <stdio.h>
#include <stdlib.h>
#include "constantes.h"
#include "struct.h"
#include "user.h"
#include "sistema.h"
#include "receberCliente.h"
#include "atenderCliente.h"

int main() {
	
	T_fila filaBanco;
	T_senha controlaSenha;
	T_preferencial preferenciais;
	
	iniciaFilaBanco(&filaBanco);
	iniciaSenhas(&controlaSenha);
	iniciaPreferenciais(&preferenciais);
	
	int op; // Para selecionar opção
	int encerrado = false;
	
	do {
		do {
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
		
		switch(op) {
			case 1:
				receberCliente(&filaBanco, &controlaSenha, &preferenciais);
				break;
				
			case 2:
				atenderCliente(&filaBanco, &controlaSenha, &preferenciais);
				break;
				
			case 3:
				encerrado = true;
				printf("== O expediente foi encerrado. Atenda os últimos clientes da fila ==\n");
				getchar();
				travatela();
				break;
			case 4:
				system("clear");
				if(validaFilaVazia(&filaBanco) == false) listarElementos(&filaBanco);
				else printf("Nenhum cliente para atender no momento\n");
				getchar();
				travatela();
		}
	} while (encerrado == false);
	
	while (filaBanco.qElementos > 0) {
		system("clear");
		printf("Atender o próximo cliente?\n");
		if (telaConfirmacao() == true) atenderCliente(&filaBanco, &controlaSenha, &preferenciais);
		else {
			printf("Aguarde até um atendente estar disponível\n\n");
			getchar();
			travatela();
		}
	}
	
	printf("Todos os clientes foram atendidos. A agência foi fechada\n");
	
	return 0;

}


/* Assinatura:
 * principal.c
 * 
 * Autor: Bruno Nogueira de Oliveira, aluno do terceiro período do curso de 
 * Sistemas de Informação na Universidade Federal de Goiás.
 * 
 * Algoritmo desenvolvido para disciplina de estrutura de dados, sobre a orientação do 
 * Professor Edmundo S. Spotto
 * 
 * Esse programa é um software proprietário; Ele não pode ser redistribuido
 * ou modificado, sem a permissão prévia do proprietário, informado acima.
 * 
 * Versão inicial desenvolvida dia 27.10.2013
 * Última modificação: 27.10.2013 (entrega do pacote final)
 * 
 */

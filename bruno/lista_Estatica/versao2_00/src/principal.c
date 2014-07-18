/*  == Descrissão do arquivo ==
 * 	Esse arquivo contém a função MAIN (principal) do programa que será utilizada para gerenciar o funcionamento do sistema e sua interação com o usuário.
 * 
 * 	== Lógica algorítmica ==
 * 	Os comentários, no decorrer do arquivo descrevem a lógica algorítmica. Caso algum script necessite ser detalhado, 
 * 	será descrito sua lógica nessa parte do arquivo.
 * */
 
 // ############## BIBLIOTECAS ############## //
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "constantes.h"
#include "struct.h"
#include "user.h"
#include "sistema.h"
#include "cadastramento.h"
#include "criarCampeonato.h"
#include "jogarCampeonato.h"

 // ############## FUNÇÃO MAIN ############## //
 
int main() {
	
	// ################ Variáveis ################ //
	T_Lista lista;
	T_listaJogo campeonato; //Essa é a lista de jogos que terá os jogos do campeonato. O objetivo é construir essa lista//
	
	int validador = false;
	int validadorP = false;
	
	// ################ Funcionamento da MAIN ################ //
	
	criarListaVazia(&lista); /* A primeira coisa que a função main faz é criar uma lista estática*/
	
	do {
		do {
			cadastramento(&lista);
			
			system("clear");
			if(verificarListaVazia(&lista) == true){
				printf("A lista está vazia. Se, ao menos dois times não forem cadastrados, não haverá jogos e não haverá campeonato\n\n");
				if(telaConfirmacao() == true){
					printf("O programa foi encerrado\n");
					travatela();
					return 0;
				}
			}
			else if (lista.elemento < 2) {
				printf("A lista contém apenas 1 time. Se, ao menos dois times não forem cadastrados, não haverá jogos e não haverá campeonato\n\n");
				if(telaConfirmacao() == true){
					printf("O programa foi encerrado\n");
					travatela();
					return 0;
				}
				else {
					printf("Você está voltando para o cadastramento dos times\n\n");
					getchar();
					travatela();
				}
			}
			else {
				printf("Os times já foram inseridos.\nDeseja prosseguir para a geração do campeonato?\n");
				if(telaConfirmacao() == true) validador = true;
				else {
					printf("Você está voltando para o cadastramento dos times\n\n");
					getchar();
					travatela();
				}
			}
		} while(validador == false);
	
	/* Inicializando definição dos jogos da rodada */
		iniciarCampeonatoVazio(&campeonato);
	
		criarCampeonato(&lista, &campeonato);
		
		printf("Campeonato criado. Deseja iniciá-lo?\n");
		if(telaConfirmacao() == false) {
			printf("Você está voltando para o cadastramento de times");
			travatela();
		}
		else validadorP = true;
		
	}while(validadorP == false);
	
	jogarCampeonato(&lista, &campeonato);
	
	return 0;
} // FIM DA FUNÇÃO MAIN
 

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
 * Versão inicial desenvolvida dia 28.09.2013
 * Última modificação: 23.10.2013 (entrega do pacote final)
 * 
 */

// Programa lista_Estatica (Tabela de classificação de um campeonato) //

// ############## BIBLIOTECAS ############## //
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "struct.h"
#include "funcoes_Campeonato.h"

// ############## MACROS ############## //
#define MAX 25			/*Define a quantidade de times que terão no campeonato
						  Define a quantidade de elementos da lista	*/
#define CAR 20 

// ############## DEFINIÇÕES DE TIPO ############## //
typedef char String[CAR];




int main() {
	
	// ## Variáveis ## //
	
	T_Lista lista;	// Essa é a disponibilização de um espaço de memória para lista. Variável que cria a lista estática.
	T_time time; // Essa variável será a que manipularemos os dados dos times.
	int op; // Variável operadora, responsável pela interação do usuário com o sistema.
	int pos; //Auxilia na busca de um time pela posição;
	String nome, nomeCorrigido; //Auxilia na pesquisa de um time por nome e sua correção;
	int time1, time2; //variáveis serão usadas para definir resultado de jogos;
	int golsTime1, golsTime2; //Variável para contagem dos gols feitos por cada time;
	
	// ## Protótipos de funções ## //
	void travatela();
	void criarListaVazia(T_Lista * lista); // Essa função faz a inicialização da lista;
	int inserirElementoFinal(T_Lista * lista, T_time time); // Essa função insere um time no final da lista //
	void listarElementos(T_Lista * lista); // Essa função mostra a tabela do campeonato //
	int inserirElemento(T_Lista * lista, int pos, T_time time); // Insere um elemento no meio da lista //
	int inserirElementoInicio(T_Lista * lista, T_time time); // Insere um elemento no início da lista
	void excluirElemento(T_Lista * lista, String nome);
	void corrigirElemento(T_Lista * lista, int pos, String nomeCorrigido);
	int detalheTime(T_time * time, T_Lista * lista); // Auxilia na inclusão de um time na fila
	int procurarTime(T_Lista * lista, String nome); //Função para procurar um time na lista
	void vitoria(T_Lista * lista, int timeV, int golsTimeV, int timeP, int golsTimeP); // timeV = Vencedor, timeP = Perdedor//
	void empate(T_Lista * lista, int timeC, int golsTimeC, int timeV, int golsTimeV); // timeC = time da casa, timeV = time visitante
	void ordenarClassificacao(T_Lista * lista); //Função que organizará a classificação do campeonato
	int verificarListaCheia(T_Lista * lista);
	
	// ## Funcionamento da MAIN ## //
	
	
	criarListaVazia(&lista); /* A primeira coisa que a função main faz é criar uma lista estática*/
	
	// * Vamos apresentar para o usuário uma série de opções para ele trabalhar * //
	
	do {
		system("clear");		//Faz uma limpeza na tela do usuário
		do{
			printf("== MENU ==\n\n");
			printf("Digite '0':\tPara sair do programa\n");
			printf("Digite '1':\tPara inserir um time no final da lista\n");
			printf("Digite '2':\tPara inserir um time no meio da lista\n");
			printf("Digite '3':\tPara inserir um time no início da lista\n");
			printf("Digite '4':\tPara deletar um time na tabela\n");
			printf("Digite '5':\tPara procurar um time na tabela\n");
			printf("Digite '6':\tPara corrigir o nome de um time\n");
			printf("Digite '7':\tPara visualizar a tabela da competição\n");
			printf("Digite '8':\tPara fazer dois times jogarem\n");
			/* Demais opçṍes serão criadas aqui */
			
			
			printf("\n");
			printf("Digite a opção desejada: ");
			scanf("%d", &op);
			if (op < 0 || op > 9) printf("Opção inválida\n");
			travatela();
			system("clear");
		} while(op < 0 || op > 9);
		
		switch(op) {
			case 0:
				system("clear");
				printf("Até mais\n\n");
				travatela();
				break;
			case 1:
				system("clear");
				printf("Função de inserção de time no final\n\n");
				if (detalheTime(&time, &lista) == 0) {
					inserirElementoFinal(&lista, time);
					printf("\n\nTime inserido com sucesso\n");
					travatela();
				}
				else {
					printf("Time já existe cadastrado!\n\n");
					travatela();
				}
				break;
			
			case 2:
				system("clear");
				printf("Função de inserção de time no meio\n\n");
				if (detalheTime(&time, &lista) == 0) {
					do {
						printf("Digite a posição que você deseja adicionar o time: ");
						scanf("%d", &pos);
						if (pos <= 0 || pos > MAX) printf("Posição inválida\n");
					}while(pos <= 0 || pos > MAX);
					pos -= 1;
					inserirElemento(&lista, pos, time);
					printf("\n\nTime inserido com sucesso\n");
					travatela();
				}
				else {
					printf("Time já existe cadastrado!\n\n");
					travatela();
				}
				break;	
			
			case 3:
				system("clear");
				printf("Função de inserção de time no início.\n\n");
				if (detalheTime(&time, &lista) == 0) {
					inserirElementoInicio(&lista, time);
				}
				else {
					printf("Time já existe cadastrado!\n\n");
					travatela();
				}
				
				break;
			case 4:
				system("clear");
				printf("Deletar time\n\n");
				printf("Digite o time que você deseja deletar: ");
				fgets(nome, CAR, stdin);
				excluirElemento(&lista, nome);
				break;
				
			case 5: 
				system("clear");
				printf("Digite o nome do time que você quer procurar: ");
				fgets(nome, CAR, stdin);
				pos = procurarTime(&lista, nome);
				if (pos != -1) {
					printf("Time encontrado\n\n");
					printf("Nome: %s\n", lista.vetor[pos].nome);
					printf("Pontos: %d\n", lista.vetor[pos].Pontos);
					printf("Vitórias: %d\n", lista.vetor[pos].qVitorias);
					printf("Empates: %d\n", lista.vetor[pos].qEmpates);
					printf("Derrotas: %d\n", lista.vetor[pos].qDerrotas);
					printf("Gols Pró: %d\n", lista.vetor[pos].GolsPro);
					printf("Gols Contra: %d\n", lista.vetor[pos].GolsContra);
					printf("Saldo de gols: %d\n", lista.vetor[pos].Saldo);
					printf("\n"); 
					travatela();
				}
				else {
					printf("Time não encontrado\n\n");
					travatela();
				}
				
				break;
			
			case 6: 
				
				system("clear");
				
				listarElementos(&lista);
				printf("\n\n");
				do{
					printf("\n\nDigite a posição do time que você quer corrigir o nome: ");
					scanf("%d", &pos);
					if (pos < lista.elemento) printf("Posição inválida\n\n");
				}while(pos < lista.elemento);
				
				pos--; //Decrementa pois a posição do time na lista é uma posição a menos daquela que o usuário vê na tela
				
				printf("Digite o nome correto: ");
				getchar();
				fgets(nomeCorrigido, CAR, stdin);
				
				corrigirElemento(&lista, pos, nomeCorrigido);
				
				travatela();
				
				break;
			case 7:
				printf("Tabela do campeonato\n\n");
				listarElementos(&lista);
				travatela();
				
				break;
				
			case 8: //Essa é a foda. Vai fazer dois times jogarem e modificar os dados dos times de acordo com o resultado
				system("clear");
				printf("Jogo da rodada\n\n");
				
				time1 = time2 = -1;
				
				do {
					printf("Digite o nome do time da casa: ");
					fgets(nome, CAR, stdin);
					if (procurarTime(&lista, nome) != -1) {
						time1 = procurarTime(&lista, nome);
					} //time1 recebe índice da lista onde o time 1 está armazenado
					else {
						printf("Time não existe. Digite um time válido\n");
					}
				}while(time1 == -1);
				
				do {
					printf("Digite o nome do time visitante: ");
					fgets(nome, CAR, stdin);
					if (procurarTime(&lista, nome) != -1) {
						time2 = procurarTime(&lista, nome);
					} //time2 recebe índice da lista onde o time 1 está armazenado
					else {
						printf("Time não existe. Digite um time válido\n");
					}
				}while(time2 == -1);
				
				printf("Digite quantos GOLS %s fez: ", lista.vetor[time1].nome);
				scanf("%d", &golsTime1);
				
				printf("Digite quantos GOLS %s fez: ", lista.vetor[time2].nome);
				scanf("%d", &golsTime2);
				
				if (golsTime1 > golsTime2) {
					//Vitória time 1
					vitoria(&lista, time1, golsTime1, time2, golsTime2);
					
				}
				else if (golsTime1 == golsTime2) {
					empate(&lista, time1, golsTime1, time2, golsTime2);
					
				}
				else {
					vitoria(&lista, time2, golsTime2, time1, golsTime1);
					
				}
				ordenarClassificacao(&lista); //ordena classificação da tabela;
				break;
				
			default:
				system("clear");
				printf("Opção inválida\n");
				travatela();
				break;
			
		}
		
		
	} while(op != 0);
	
	
	return 0;
} // ## Fim da função MAIN ## //

// Agora o couro vai comer //

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "constantes.h"
#include "structs.h"
#include "user.h"
#include "sistema.h"

int main() {
	
	/*Essa função contem as operações de criação de cronograma do mês de shows e eventos do sistema */
	
	T_calendario cronograma;
	int validador = false;
	int op = 0, op2 = 0;
	int dia = 0, hora = 0;
	String nome;
	int codigo;
	
	criarMesDeEventos(&cronograma);
	
	do {
		system("clear");
		do{
			printf("\t\tMENU PRINCIPAL\t\t");
			printf("\n\n");
			printf("Digite a opção desejada\n");
			printf("Digite 1:\tInserir Evento\n");
			printf("Digite 2:\tExcluir Evento\n");
			printf("Digite 3:\tVender Ingresso\n");
			printf("Digite 4:\tDevolver Ingresso\n");
			printf("Digite 5:\tVisualizar plateia de um evento\n");
			printf("Digite 6:\tVisualizar eventos disponíveis\n");
			printf("Digite 0:\tSair do sistema\n");
			printf("\n");
			printf("Digite a opção desejada: ");
			scanf("%d", &op);
			if(op < 0 || op > 6) printf("Opção inválida. Digite uma opção válida\n");
		}while(op < 0 || op > 6);
		
		switch(op) {
			case 0:
				system("clear");
				printf("Tchau!\n");
				travatela();
				validador = true;
				break;
			
			case 1:
				system("clear");
				getchar();
				printf("Digite o nome do espetáculo: ");
				fgets(nome, TAM, stdin);
				do{
					printf("Digite o dia do evento: ");
					scanf("%d", &dia);
				}while(dia < 1 || dia > 31);
				
				printf("Horarios possíveis:\n");
				printf("Horario 1:\t09:00 às 11:30\n");
				printf("Horario 2:\t13:00 às 15:30\n");
				printf("Horario 3:\t16:00 às 18:30\n");
				printf("Horario 4:\t19:30 às 22:00\n");
				printf("Horario 5:\t22:30 às 01:00\n");
				
				do {
					printf("Digite o melhor horário: ");
					scanf("%d", &op2);
					switch(op2) {
						case 1:
							hora = apres1;
							break;
						case 2:
							hora = apres2;
							break;
						case 3:
							hora = apres3;
							break;
						case 4:
							hora = apres4;
							break;
						case 5:
							hora = apres5;
							break;
					
						default:
							printf("Opção inválida\n");
							break;
					}
				}while(op2 < 1 || op2 > 5);
				
				hora--;
				
				if(cronograma.datas[dia].apresentacao[hora].horario == false) inserirEvento(&cronograma, nome, dia, hora);
				else {
					printf("Já tem evento cadastrado nessa data e horário\n");
				}
				getchar();
				travatela();
				break;
			
			case 2: 
				system("clear");
				printf("Exclusão de eventos do sistema\n\n");
				visualizarEventos(&cronograma);
				printf("Digite o codigo do evento que você deseja excluir: ");
				scanf("%d", &codigo);
				excluirEvento(&cronograma, codigo);
				getchar();
				travatela();
				break;
				
			case 3:
				system("clear");
				printf("Venda de ingresso\n\n");
				printf("Digite o nome do cliente: ");
				getchar();
				fgets(nome, TAM, stdin);
				printf("\n\n");
				visualizarEventos(&cronograma);
				printf("Digite o codigo do evento que você deseja adquirir o ingresso: ");
				scanf("%d", &codigo);
				venderIngresso(&cronograma, nome, codigo);
				
				getchar();
				travatela();
				
				break;
				
			case 4:
				system("clear");
				
				printf("Sistema de devolução do ingresso\n\n");
				visualizarEventos(&cronograma);
				printf("Digite o codigo do evento que você deseja devolver o ingresso: ");
				scanf("%d", &codigo);
				devolverIngresso(&cronograma, codigo);
				getchar();
				travatela();
				break;
			
			case 5: 
				system("clear");
				visualizarEventos(&cronograma);
				printf("Digite o código do evento que você deseja visualizar a plateia: ");
				scanf("%d", &codigo);
				vizualizacaoPlateia(&cronograma, codigo);
				getchar();
				travatela();
				break;
			
			case 6:
				system("clear");
				visualizarEventos(&cronograma);
				getchar();
				travatela();
			default:
				printf("Opção inválida\n");
				break;
		}
		
	} while(validador == false);	
	return 0;
}

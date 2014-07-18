/*
@author Daniel Melo
@author Ana Letícia Herculano

Este trabalho contem um exemplo de implementação de pilha e fila.
O Tema da fila é o de uma fila de trabalho
O tema da pilha é o de uma pilha de palestras. 
As operações disponíveis para ambas são as mesmas, com as implementações adequadas
    Incluir
    Concluir (retirar/remover)
    Imprimir
    Inverter
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
	
	Pilha palestra;
	Fila trabalho;
	
	strcpy(trabalho.elementos[5].disciplina, "Disciplina 0");
	strcpy(trabalho.elementos[5].assunto, "Assunto 0");
	strcpy(trabalho.elementos[6].disciplina, "Disciplina 1");
	strcpy(trabalho.elementos[6].assunto, "Assunto 1");
	strcpy(trabalho.elementos[0].disciplina, "Disciplina 2");
	strcpy(trabalho.elementos[0].assunto, "Assunto 2");
	strcpy(trabalho.elementos[1].disciplina, "Disciplina 3");
	strcpy(trabalho.elementos[1].assunto, "Assunto 3");
	
	
	trabalho.primeiro = 5;
	trabalho.ultimo = 1;
	
	
	strcpy(palestra.elementos[0].titulo, "Titulo 0");
	strcpy(palestra.elementos[0].local, "Local 0");
	strcpy(palestra.elementos[1].titulo, "Titulo  1");
	strcpy(palestra.elementos[1].local, "Local 1");
	strcpy(palestra.elementos[2].titulo, "Titulo  2");
	strcpy(palestra.elementos[2].local, "Local 2");
	strcpy(palestra.elementos[3].titulo, "Titulo  3");
	strcpy(palestra.elementos[3].local, "Local 3");
	palestra.tamanho = 4;
	
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
			//TRABALHOS - OS TRABALHOS SÃO UMA FILA
			case 1: //adicionar trabalho
				limparTela();
				inserirFila(&trabalho);
			break;
			case 2: //concluir trabalho
				limparTela();
				retirarFila(&trabalho);
			break;
			case 3: //imprimir fila trabalho
				limparTela();
				imprimirFila(&trabalho);
			break;
			case 4: //inverter trabalhos
				limparTela();
				inverterFila(&trabalho);
			break;
			
			//PALETRAS - AS PALESTRAS SÃO UMA PILHA
			case 5: //adicionar palestra
				limparTela();
				inserirPilha(&palestra);
			break;
			case 6: //concluir palestra
				limparTela();
				retirarPilha(&palestra);
			break;
			case 7: //imprimir pilha palestra
				limparTela();
				imprimirPilha(&palestra);
			break;
			case 8: //inverter palestra
				limparTela();
				inverterPilha(&palestra);
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



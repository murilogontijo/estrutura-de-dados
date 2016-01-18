/*
 * Teatro.c
 * 
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 * 
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston,
 * MA 02110-1301, USA.
 * 
 * 
 */

#include <stdio.h>
#include <stdlib.h>
#define QTD_COLUNAS 25
#define QTD_LINHAS 24

/*
 * Inicializa as plateias atribuindo o valor 'v' para todas as cadeiras;
 */
void inicializar_cadeiras(char plateia[QTD_LINHAS][QTD_COLUNAS]) {
	
	int i,j;
	
	for(i = 0; i < QTD_LINHAS; i++) {
		for(j = 0; j < QTD_COLUNAS; j++) {
			plateia[i][j] = 'v';
		}
	}
	
}


/*
 * Apresenta o menu de opcoes disponíveis e retorna o inteiro referente
 * a opcao desejada.
 * 
 */
int apresentar_menu() {
	int op_menu;
	
	//system("clear");
	printf("Escolha uma opcao:\n");
	printf("1-Preencher cadeiras\n");
	printf("2-Visualizar lado esquerdo\n");
	printf("3-Visualizar lado direito\n");
	printf("4-Finalizar\n");
	scanf("%d",&op_menu);
	
	return op_menu;
}

/*
 * Apresenta ocupação das cadeiras da plateia
 */
void vizualizar_plateia(char plateia[QTD_LINHAS][QTD_COLUNAS]) {
	// Imprime o identificador das colunas
	int c = 1;
	printf("    "); // Para nao preencher o cabecalho da identificacao dos numeros.
	while(c <= QTD_COLUNAS) {
		if(c < 10) {
			printf(" 0%d",c);
		} else {
			printf(" %d", c);
		}
		c++;
	}
	
	printf("\n");
	
	int i, j;
	for(i = 0; i < QTD_LINHAS; i++) {
		
		if(i+1 < 10) {
			printf(" 0%d", i+1);
		} else {
			printf(" %d", i+1);
		}
		
		for(j = 0; j < QTD_COLUNAS; j++) {
			printf("  %c", plateia[i][j]);
		}
		printf("\n");
	}
}

/*
 * Função que executa a venda de ingresso
 */
void vender_ingresso(char plateia[QTD_LINHAS][QTD_COLUNAS]) {
	
	int linha, coluna;
	int continua_comprando = 1;
	int op;
	
	while(continua_comprando == 1) {
		system("clear");
		// Mostra a plateia para verificar os lugares ocupados e vazios;
		vizualizar_plateia(plateia);
		
		do {
			printf("Digite a fileira desejada: "); // Linha
			scanf("%d", &linha);
			if(linha <= 0 || linha > QTD_LINHAS) {
				printf("Fileira invalida. Digite novamente...\n");
			}
		} while(linha <= 0 || linha > QTD_LINHAS);
		linha--; //alinha a posição do usuário com a posição da matriz
		
		do {
			printf("Digite o numero da cadeira desejada: "); // Coluna
			scanf("%d", &coluna);
			if(coluna <= 0 || coluna > QTD_COLUNAS) {
				printf("Cadeira invalida. Digite novamente...\n");
			}
		} while(coluna <= 0 || coluna > QTD_COLUNAS);
		coluna--; //alinha a posição do usuário com a posição da matriz
		
		// verifica se está ocupada...
		if(plateia[linha][coluna] == 'O') {
			printf("Cadeira já ocupada. Tente outra...\n");
			continue;
		}
		
		// verifica se está reservada...
		if(plateia[linha][coluna] == 'R') {
			printf("Cadeira já reservada. Tente outra...\n");
			continue;
		}
		
		// Não está ocupada nem reservada... então vende.
		do {
			printf("\n\tEscolha uma opcao:\n");
			printf("1-Ocupar cadeira\n");
			printf("2-Reservar cadeira\n");
			scanf("\t%d",&op);
			
			switch(op) {
				case 1:
					plateia[linha][coluna] = 'O';
					break;
					
				case 2:
					plateia[linha][coluna] = 'R';
					break;
				default:
					system("clear");
					printf("Opção inválida. Tente novamente!");
			}
		} while(op != 1 && op != 2);
		
		
		do {
			printf("Deseja continuar comprando?\nDigite:\n1-SIM\n2-NÃO\nOpção: ");
			scanf("\t%d",&op);
			
			switch(op) {
				case 1:
					break; // Faz nada
				case 2:
					continua_comprando = 0;
					break;
				default:
					system("clear");
					printf("Opção inválida. Tente novamente!");
			}
		} while(op != 1 && op != 2);
		
	}
}

/*
 * Funcao principal do sistema de Teatro.
 */
int main(int argc, char **argv) {
	
	char plateia_direita[QTD_LINHAS][QTD_COLUNAS];
	char plateia_esquerda[QTD_LINHAS][QTD_COLUNAS];
	
	inicializar_cadeiras(plateia_direita);
	inicializar_cadeiras(plateia_esquerda);
	
	int ativo = 1;
	int opcao, lado;
	
	// Enquanto o programa permanecer ativo (ativo = 1) continuar 
	// apresentando as opções
	while(ativo == 1) {
		opcao = apresentar_menu();
		
		switch(opcao) {
			case 1:
				system("clear");
				printf("Deseja preencher cadeiras de qual lado?\n");
				printf("1-Esquerdo\n");
				printf("2-Direito");
				printf("\t\t\t0-Voltar ao menu\n");
				scanf("%d",&lado); 
				
				if(lado == 1) {
					vender_ingresso(plateia_esquerda);
				} else if(lado == 2) {
					vender_ingresso(plateia_direita);
				} else {
					printf("Lado invalido. Inicie a operacao novamente\n");
				}
				break;
				
			case 2:
				system("clear");
				printf(" =============== Lado esquerdo ===============\n\n");
				vizualizar_plateia(plateia_esquerda);
				break;
			
			case 3:
				system("clear");
				printf(" =============== Lado direito ===============\n\n");
				vizualizar_plateia(plateia_direita);
				break;
			
			case 4:
				ativo = 0;
				break;
				
			default:
				printf("Opcao invalida. Digite uma opcao valida\n");
				break;
		}
		
	}
	
	return 0;
}


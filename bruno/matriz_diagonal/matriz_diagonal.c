// Definição das bibliotecas utilizadas no programa //
#include <stdio.h>
#include <stdlib.h>

#define MAX 5
#define DIM 100 			// Essa definição atribui o valor máximo dos numeros que apareceram no vetor.

void travatela() {
	// Essa é a função mais utilizada nesse código. Por se repetir várias vezes, dentro de tantos lugares, atribui esse espaço especial para ela
	printf("Digite ENTER para continuar\n");
	getchar();
}

int main() {
	
	// ## Declaração das variáveis utilizadas no programa ##
	int vet1[MAX], vet2[MAX];
	
	// ## Declaração das funções utilizadas no programa (protótipos) ##
	void telaInicial(); 								// Mostra uma tela de boas-vindas na inicialização do programa
	void capturaMatriz(int vetor[]); 					// Essa função preenche os valores nos vetores criados
	void menu(int vet1[], int vet2[]);
	
	
	// ## Corpo da estrutura main ##
	
	telaInicial(); 										// Chama função tela inicial
	
	capturaMatriz(vet1);								// Chama função para preencher valores no vetor1
	capturaMatriz(vet2);								// Chama função para preencher valores no vetor2
	
	menu(vet1, vet2);									// Chama a função menu
	
	return 0;
} // Fim da função main;

// ##################################### FUNÇṌES ##################################### //

void telaInicial() {
	// Mostra uma tela de boas-vindas na inicialização do programa //
	system("clear");
	printf("Bem vindo ao programa MATRIZ_DIAGONAL\n\nEsse algoritmo foi desenvolvido por Bruno Nogueira de Oliveira, estudante de Sistemas de Informação na Universidade Federal de Goiás, sob a orientação do professor Edmundo S. Spoto para a disciplina de estrutura de dados.\n\nO Script foi escrito na IDE Geany em um Sistema Operacional Linux Ubuntu versão 12.04 LTS.\n\n Para maiores informações leia o arquivo README.txt que se encontra dentro do pacote baixado\n\n");
	
	travatela();
	
	printf("Para agilizar o processo, o programa inicia preenchendo automaticamente dois vetores que serão trabalhados como matrizes\n");
	
	travatela();
} // Fim da função telaInicial


void capturaMatriz(int vetor[]) {
	// Essa função preenche os valores nos vetores criados
	
	int i;
	
	for(i = 0; i < MAX; i++) {
		vetor[i] = random() % DIM; 						// Os valores preenchidos estarão entre 0 e 99 ; 
	}
	
}


void menu(int vet1[], int vet2[]) {
	// Essa função será a principal função do programa. Ela será a responsável por chamar as demais funções que executaram as operações desejadas //
	
	int op; //variável de opção;
	int i; //variável de seleção;
	
	// Funções utilizadas nessa opção
	void visualizaMatriz(int vetor[], int num);
	void somarMatriz(int vet1[], int vet2[]);
	void subtrairMatriz(int vet1[], int vet2[]);
	void multiplicarMatriz(int vet1[], int vet2[]);
	void procurar(int vetor[]);
	void modificar(int vetor[]);
		
	do {
		system("clear");
		
		printf("Bem vindo ao menu\n\n");
		
		printf("O que você deseja fazer?\n\n");
		
		printf("Digite 1:\tPara visualizar uma matriz\n");
		printf("Digite 2:\tPara fazer a soma das matrizes\n");
		printf("Digite 3:\tPara fazer a subtração das matrizes\n");
		printf("Digite 4:\tPara fazer a multiplicação das matrizes\n");
		printf("Digite 5:\tPara procurar um elemento em uma matriz\n");
		printf("Digite 6:\tPara modificar um elemento em uma matriz\n");
		printf("Digite 7:\tPara sair do programa\n");
		printf("\nDigite a opção deseaja: ");
		scanf("%d", &op);
		
		switch(op) {
			case 1:
				do {
					system("clear");
					printf("Digite a matriz que vocẽ deseja visualizar: ");
					scanf("%d", &i);
					if (i == 1) visualizaMatriz(vet1, i);
					else if (i == 2) visualizaMatriz(vet2, i);
					else {
						printf("Não existe essa matriz\n");
						i = -1;
						travatela();
					}
				}while(i == -1);
				break;
			case 2:
				somarMatriz(vet1, vet2);
				break;
				
				
			case 3: 
				subtrairMatriz(vet1, vet2);
				break;
				
			case 4:
				multiplicarMatriz(vet1, vet2);
				break;
			
			case 5:
				do {
					system("clear");
					printf("Digite a matriz que você quer visualizar: ");
					scanf("%d", &i);
					if (i == 1) procurar(vet1);
					else if (i == 2) procurar(vet2);
					else {
						printf("Não existe essa matriz\n");
						i = -1;
						travatela();
						getchar();
					}
				} while(i == -1);
				
				break;
			case 6:
				do {
					system("clear");
					printf("Digite a matriz que você quer modificar: ");
					scanf("%d", &i);
					if (i == 1) modificar(vet1);
					else if (i == 2) modificar(vet2);
					else {
						printf("Não existe essa matriz\n");
						i = -1;
						travatela();
						getchar();
					}
				} while(i == -1);
				
				break;
				
			case 7:
				printf("Até mais\n");
				getchar();
				travatela();
				system("clear");
				break;
			default:
				printf("Opção inválida\n");
				travatela();
				break;
		}
		
	} while(op != 7); // Função menu encerra quando o usuário digita 7;
}

void visualizaMatriz(int vetor[], int num){
	
	int i, j; //Variáveis contadoras
	
	system("clear");
	
	printf("MATRIZ %d\n\n", num);
	
	for (i = 0; i < MAX; i++) {
		for (j = 0; j < MAX; j++) {
			if (i == j) printf("%d", vetor[i]);
			else printf("0");
			
			if(j != (MAX-1)) printf("\t");
			else printf("\n");
		}
		
	}
	getchar();
	travatela();
	
}

void somarMatriz(int vet1[], int vet2[]) {
	int vetor[MAX];
	int i;
	char op;
	
	system("clear");
	printf("Função soma das matrizes\n");
	
	for(i = 0; i < MAX; i++) {
		
		vetor[i] = vet1[i] + vet2[i];
		
	}
	
	do {
		getchar();
		printf("Deseja visualizar a matriz resultante? (S / N): ");
		scanf("%c", &op);
		if(op == 's' || op == 'S') visualizaMatriz(vetor, 3);
		else {
			if (op == 'n' || op == 'N') break;
			else {
				printf("Opção inválida\n");
			}
		}
	} while(op != 's' && op != 'S' && op != 'n' && op != 'N');
		
	
}

void subtrairMatriz(int vet1[], int vet2[]) {
	int vetor[MAX];
	int i;
	char op;
	
	system("clear");
	printf("Função subtrair das matrizes\n");
	
	for(i = 0; i < MAX; i++) {
		
		vetor[i] = vet1[i] - vet2[i];
		
	}
	
	do {
		getchar();
		printf("Deseja visualizar a matriz resultante? (S / N): ");
		scanf("%c", &op);
		if(op == 's' || op == 'S') visualizaMatriz(vetor, 3);
		else {
			if (op == 'n' || op == 'N') break;
			else {
				printf("Opção inválida\n");
			}
		}
	} while(op != 's' && op != 'S' && op != 'n' && op != 'N');
		
	
	
}

void multiplicarMatriz(int vet1[], int vet2[]) {
	int vetor[MAX];
	int i;
	char op;
	
	system("clear");
	printf("Função multiplicar das matrizes\n");
	
	for(i = 0; i < MAX; i++) {
		
		vetor[i] = vet1[i] * vet2[i];
		
	}
	
	do {
		getchar();
		printf("Deseja visualizar a matriz resultante? (S / N): ");
		scanf("%c", &op);
		if(op == 's' || op == 'S') visualizaMatriz(vetor, 3);
		else {
			if (op == 'n' || op == 'N') break;
			else {
				printf("Opção inválida\n");
			}
		}
	} while(op != 's' && op != 'S' && op != 'n' && op != 'N');
		
}

void procurar(int vetor[]) {
	
	int x, y; //variável das cordenadas;
	
	printf("Digite as cordenadas da sua matriz\n");
				
	do {
		printf("Posição i: ");
		scanf("%d", &x);
		if (x <= 0 || x > MAX) printf("POSIÇÃO INVÁLIDA\n");
	} while(x <= 0 || x > MAX);
	
	do {
		printf("Posição j: ");
		scanf("%d", &y);
		if (y <= 0 || y > MAX) printf("POSIÇÃO INVÁLIDA\n");
	} while(y <= 0 || y > MAX);
	
	if (x == y) printf("%d\n", vetor[x-1]);
	else printf("0\n");
	
	getchar();
	travatela();
}

void modificar(int vetor[]) {
	
	int x, y; //variável das cordenadas;
	
	printf("Digite as cordenadas que você deseja modificar\n");
				
	do {
		printf("Posição i: ");
		scanf("%d", &x);
		if (x <= 0 || x > MAX) printf("POSIÇÃO INVÁLIDA\n");
	} while(x <= 0 || x > MAX);
	
	do {
		printf("Posição j: ");
		scanf("%d", &y);
		if (y <= 0 || y > MAX) printf("POSIÇÃO INVÁLIDA\n");
	} while(y <= 0 || y > MAX);
	
	if (x == y) {
		printf("Digite o novo valor que será atribuído a essa posição: ");
		scanf("%d", &vetor[x-1]);
		printf("Valor modificado com sucesso\n");
	}
	else printf("Essa posição não pode ser mudada, pois estamos trabalhando com uma matriz diagonal\n");
	
	getchar();
	travatela();
	
}

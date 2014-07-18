//################################# Definição das bibliotecas utilizadas no programa #################################//
#include <stdio.h>
#include <stdlib.h>

// ################################# Definição das macros utilizadas no programa #################################//
#define MAX 4
#define DIM 100

// ################################# Definição das variáveis globais do programa #################################//
int tamanhoVetor() {
	
	// Essa função ajudará a definir o tamanho do vetor utilizado na pseudo matriz //
	
	int i, j, vet = 0;
	
	for (i = 0; i < MAX; i++) {
		for (j = 0; j < MAX; j++) {
			
			if(i >= j) vet++;

		}
	}
	
	return vet;
}


#define TAM (tamanhoVetor()) 		/* Essa variável será semelhante a uma macro. Durante a execução do programa ela não poderá ser modificada
									Ela terá como função, à partir da dimensão da pseudo-matriz declarado com a macro MAX definir o tamanho do
									* vetor que será utilizado no script do programa. Isso será feito para economizar espaço na memória do programa */



void travatela() {
	// Essa é a função mais utilizada nesse código. Por se repetir várias vezes, dentro de tantos lugares, atribui esse espaço especial para ela
	printf("Digite ENTER para continuar\n");
	getchar();
}


// ################################# Definição da função principal do programa #################################//


int main() {
	
	// ## Declaração das variáveis ## //
	
	int vetor1[TAM], vetor2[TAM];
	
	// ## Declaração das funções ## //
	void telaInicial();
	void capturaMatriz(int vetor[]);
	void menu(int vet1[], int vet2[]);
	
	// ## Estrutura da função main ## //
	
	
	telaInicial();					//Mostra a tela inicial do programa
	capturaMatriz(vetor1);			// Cria o vetor1
	capturaMatriz(vetor2);			// Cria o vetor2
	
	menu(vetor1, vetor2);
	
	return 0;
} // Fim da função main

//################################# FUNÇÕES #################################//

void telaInicial() {
	
	system("clear");
	printf("Bem vindo ao programa MATRIZ_DIAGONAL_SUPERIOR\n\nEsse algoritmo foi desenvolvido por Bruno Nogueira de Oliveira, estudante de Sistemas de Informação na Universidade Federal de Goiás, sob a orientação do professor Edmundo S. Spoto para a disciplina de estrutura de dados.\n\nO Script foi escrito na IDE Geany em um Sistema Operacional Linux Ubuntu versão 12.04 LTS.\n\n Para maiores informações leia o arquivo README.txt que se encontra dentro do pacote baixado\n\n");
	
	printf("\n\n");
	
	printf("Para agilizar o processo, o programa inicia preenchendo automaticamente dois vetores que serão trabalhados como matrizes triangulares superior\n");
	
	travatela();
}

void capturaMatriz(int vetor[]) {
	// Essa função preenche os valores nos vetores criados
	
	int i;
	
	for(i = 0; i < TAM; i++) {
		vetor[i] = random() % DIM;					// Os valores preenchidos estarão entre 0 e 99 ; 
		
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
	void procurar(int vetor[]);
	void modificar(int vetor[]);
		
	do {
		system("clear");
		
		printf("Bem vindo ao menu\n\n");
		
		printf("O que você deseja fazer?\n\n");
		
		printf("Digite 1:\tPara visualizar uma matriz\n");
		printf("Digite 2:\tPara fazer a soma das matrizes\n");
		printf("Digite 3:\tPara fazer a subtração das matrizes\n");
		printf("Digite 4:\tPara procurar um elemento em uma matriz\n");
		printf("Digite 5:\tPara modificar um elemento em uma matriz\n");
		printf("Digite 6:\tPara sair do programa\n");
		printf("\nDigite a opção deseaja: ");
		scanf("%d", &op);
		
		switch(op) {
			case 1:
				do {
					system("clear");
					printf("Existe duas matrizes disponíveis na qual você poderá executar operações.\n\n");
					printf("Digite a matriz que vocẽ deseja visualizar ('1' ou '2'): ");
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
				do {
					system("clear");
					printf("Digite a matriz que você quer visualizar('1' ou '2'): ");
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
			case 5:
				do {
					system("clear");
					printf("Digite a matriz que você quer modificar ('1' ou '2'): ");
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
				
			case 6:
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
		
	} while(op != 6); // Função menu encerra quando o usuário digita 6;
}

void visualizaMatriz(int vetor[], int num){
	
	int i, j, cont = 0 ; //Variáveis contadoras
	
	system("clear");
	printf("MATRIZ %d\n\n", num);
	
	for (i = 0; i < MAX; i++) {
		for (j = 0; j < MAX; j++) {
			if (i <= j) {
				printf("%d", vetor[cont]);
				cont++;
			}
			else printf("0");
			
			
			if(j != (MAX-1)) printf("\t");
			else printf("\n");
		}
		
	}
	getchar();
	travatela();
	
}

void somarMatriz(int vet1[], int vet2[]) {
	int vetor[TAM];
	int i;
	char op;
	
	system("clear");
	printf("Função soma das matrizes\n");
	
	for(i = 0; i < TAM; i++) {
		
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
	int vetor[TAM];
	int i;
	char op;
	
	system("clear");
	printf("Função subtrair das matrizes\n");
	
	for(i = 0; i < TAM; i++) {
		
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

void procurar(int vetor[]) {
	
	int x, y; //variável das cordenadas;
	int i, j; //Variáveis de controle;
	int cont = 0; // Variável contadora;
	
	printf("Digite as cordenadas da sua matriz\n\n");
				
	do {
		printf("Posições disponíveis: de '1' à '%d'\n", MAX);
		printf("Posição i: ");
		scanf("%d", &x);
		if (x <= 0 || x > MAX) printf("POSIÇÃO INVÁLIDA\n");
	} while(x <= 0 || x > MAX);
	
	do {
		printf("Posições disponíveis: de '1' à '%d'\n", MAX);
		printf("Posição j: ");
		scanf("%d", &y);
		if (y <= 0 || y > MAX) printf("POSIÇÃO INVÁLIDA\n");
	} while(y <= 0 || y > MAX);
	
	if (x <= y) {
		
	//##################################################################//
		for(i = 1; i <= MAX; i++) {
			for(j = 1; j <= MAX; j++) {
				if (i <= j){
					if (i == x && j == y) printf("%d\n", vetor[cont]);
					else cont++;
				}
			}
		}
		
	//##################################################################//	
	}
	else printf("0\n");
	
	getchar();
	travatela();
}

void modificar(int vetor[]) {
	
	int x, y; //variável das cordenadas;
	int i, j; //Variáveis de controle;
	int cont = 0; // Variável contadora;
	
	printf("Digite as cordenadas da sua matriz\n\n");
				
	do {
		printf("Posições disponíveis: de '1' à '%d'\n", MAX);
		printf("Posição i: ");
		scanf("%d", &x);
		if (x <= 0 || x > MAX) printf("POSIÇÃO INVÁLIDA\n");
	} while(x <= 0 || x > MAX);
	
	do {
		printf("Posições disponíveis: de '1' à '%d'\n", MAX);
		printf("Posição j: ");
		scanf("%d", &y);
		if (y <= 0 || y > MAX) printf("POSIÇÃO INVÁLIDA\n");
	} while(y <= 0 || y > MAX);
	
	
	if (x <= y) {
		
		for(i = 1; i <= MAX; i++) {
			for(j = 1; j <= MAX; j++) {
				if (i <= j){
					if (i == x && j == y) {
						printf("Digite o novo valor: ");
						scanf("%d", &vetor[cont]);
					}
					else cont++;
				}
			}
		}
	}
	else printf("Essa matriz é triângular superior.\nO elemento solicitado não pode ser modificado\n\n");
	
	getchar();
	travatela();
}

/* Esse programa deve caputurar notas de X alunos em Y disciplinas diferentes e 
calcular a média individual de cada aluno e a média de todos os alunos na matéria.


O programa foi escrito e compilado utilizando o Geany em um ambiente Ubuntu 12.04 LTS

*/

//Bibliotecas utilizadas
#include <stdio.h>
#include <stdlib.h>

//Definição da quantidade de alunos e da quantidade de matérias
#define ALUNOS 55
#define MATERIAS 3

/* ############################################# FUNÇÃO PRINCIPAL DO PROGRAMA ################################################### */
int main() {
	
	// ### Declaração das variáveis ###
	
	float vetor[(ALUNOS + 1)][(MATERIAS + 1)]; //Esse vetor armazenará as notas do aluno e da matéria
	int i = 0, j = 0; //Variáveis contadoras
	
	// ### Declaração das funções do programa ###
	
	float capturaNotas(); //gera uma nota aleatória para o aluno;
	void mediaAlunos(float notas[][MATERIAS+1]); // Calcula a média dos alunos 
	void mediaCurso(float notas[][MATERIAS+1]); // Calcula a média dos cursos
	void menu(float tabela[][MATERIAS+1]); //Função possibilitará trabalho dentro da matriz
	
	//A primeira coisa que o programa deve fazer é capturar ordenadamente as médias de cada matéria para cada aluno
	//Utilizaremos a função capturaNotas(). Ela gerará um valor aleatório e preencherá no vetor;
	

	for(i = 0; i < ALUNOS; i++) {
		
		for (j = 0; j < MATERIAS; j++) {
			
			vetor[i][j] = capturaNotas();
			
		} // Fim do ciclo de preenchimentos da matéria
		
	} // Fim do ciclo de preenchimento do aluno
	
	
	// Uma vez capturada as notas e colocadas nos vetores devemos preencher as médias.
	
	// ## Calculando a média do aluno nas matérias
	
	mediaAlunos( vetor ); // *Essa função, ao ser chamada calcula a média dos alunos
	
	// ## Calculando a média do curso para os alunos
	mediaCurso( vetor );
	
	
	// $$$ Uma vez que aqui chegamos, iremos oferecer algumas opções para o usuário $$$
	
	menu( vetor );
	 
	return 0;
} // Fim da função main do programa



/* #################################################################################################################################### */

float capturaNotas() {
	/* Essa função gerará uma nota aleatória que variara de 0 a 10.
	* Essa função é criada, pois a função random() gera apenas inteiros aleatórios
	* Essa função, à partir de um inteiro de 0 à 100 gerará uma nota de 0 à 10 no tipo de dado float
	*/ 
	
	// ### Declaração das variáveis locais dessa função
	float nota;
	int valor;
	
	valor = random() % 101; // Gera um número inteiro aleatório de 0 à 100
	
	nota = (float) valor / 10; // Transforma o número inteiro aleatório gerado em uma nota de 0.0 à 10.0 no tipo float
	
	return nota;
}




/* #################################################################################################################################### */

void mediaAlunos(float notas[][MATERIAS+1]) {
	/* Essa função vai calcular a média de cada aluno as matérias que ele cursou*/
	
	// ## Declaração das variáveis ##
	float soma = 0;
	float media;
	int i, j;
	
	for(i = 0; i < ALUNOS; i++) {
		
		for (j = 0; j < MATERIAS; j++) {
			
			soma += notas[i][j];
			
		} //Fim do ciclo de procura de notas
		
		media = soma / MATERIAS;
		
		notas[i][j] = media;
		
		soma = 0;
	} //Fim do cíclo do aluno

} // Fim da função mediaAlunos()




/* #################################################################################################################################### */

void mediaCurso(float notas[][MATERIAS+1]) {
	// Essa função vai calcular a média dos alunos que cursaram o curso
	
	// ## Declaração das variáveis
	float media;
	float soma = 0;
	int i, j;
	
	for(i = 0; i < MATERIAS ; i++) {
		
		for (j = 0; j < ALUNOS; j++) {
			soma += notas[j][i];
		}// Fim do ciclo dos alunos
		
		media = soma / ALUNOS;
		
		notas[j][i] = media;
		
		soma = 0;
		
	} //Fim do ciclo das matérias
	
} // Fim da função mediaCurso()


/* #################################################################################################################################### */

void menu( float tabela[][MATERIAS+1] ) {
	/* Com essa função poderemos fazer as seguintes operações
	 * O usuário poderá consultar as notas gerais
	 * O usuário poderá consultar as notas de uma matérias específica
	 * O usuário poderá consultar as notas de um aluno específico
	 * O usuário poderá modificar uma nota de um aluno de uma matéria
	 * */
	
	
	// ## Declaração das variáveis
	int op;
	
	// ## Declaração das funções usadas dentro dessa função
	void visualizarNotasGerais(float notas[][MATERIAS+1]);
	void visualizaNotasMateria(float notas[][MATERIAS+1]);
	void visualizaNotasAluno(float notas[][MATERIAS+1]);
	void modificarNotasAluno(float notas[][MATERIAS+1]);

	do {
		
		printf("O que vocẽ deseja fazer?\n");
		printf("Digite 1\tVisualizar a tabela de notas\n");
		printf("Digite 2\tVisualizar as notas de uma matéria específica\n");
		printf("Digite 3\tConsultar as notas de um aluno específico\n");
		printf("Digite 4\tModificar uma nota de um aluno em uma matéria? \n");
		printf("Digite 5\tSair do programa\n");
		printf("Digite a opção desejada: ");
		scanf("%d", &op);
		
		switch(op) {
			case 1:
				visualizarNotasGerais(tabela);
				break;
			case 2:
				visualizaNotasMateria(tabela);
				break;
			case 3:
				visualizaNotasAluno(tabela);
				break;
			case 4:
				modificarNotasAluno(tabela);
				break;
			case 5: break;
			default: 
				printf("Opção inválida\n");
				getchar();
				break;
		 }
		 printf("\n\nDigite uma tecla para continuar!\n");
		 getchar();
		 system("clear");
	 } while (op != 5);
	 
}



/* #################################################################################################################################### */

void visualizarNotasGerais(float notas[][MATERIAS+1]) {
	// Essa função criará uma tabela com as notas dos alunos
	
	
	int i, j;
	
	system("clear"); //executará uma limpeza do promput de comando
	getchar();
	printf("## Tabela de notas dos alunos ##\n\n");
	
	
	// Esse laço aqui preencherá o primeiro cabeçalho. Ele será do tamanho da tabela necessária
	for (i = 0; i <= (MATERIAS + 1); i++) {
		 
		if (i > 0 && i <= MATERIAS) { 
			printf("|MATERIA %d\t", i);
		} 
		else {
			if (i == MATERIAS+1) {
				printf("|MEDIA ALUNO\t|\n");
			}
			else {
				printf("|\t\t");
			}
		}
	} //Fim do laço que preenche o cabeçalho da tabela
	
	// Esse laço aqui preencherá o restante do corpo do conteúdo
	
	for (i = 0; i <= ALUNOS; i++) {
		
		for (j = 0 ; j <= (MATERIAS+1); j++) {
			
			if (j > 0 && j <= (MATERIAS+1)) { 
				printf("|\t%.2f\t", notas[i][j-1]);
				if (j == (MATERIAS+1)) printf("|\n");
			} 
			else {
					if (i == ALUNOS) printf("|MEDIA\t\t");
					else printf("|ALUNO %d\t", (i+1));
			}				
			
		} //Fim do laço de matérias
		
	} // Fim do laço que preenche o resto da função
	
} // Fim da Função Vizualisar notas gerais



/* #################################################################################################################################### */
void visualizaNotasMateria(float notas[][MATERIAS+1]) {
	// Essa função faz o usuário visualizar as notas de uma matéria
	int i, j;
	
	system("clear");
	
	do {
		//Solicita ao usuário a matéria específica que ele deseja visualizar as notas
		printf("Selecione a matéria que vocẽ deseja visualizar as Notas: ");
		scanf("%d", &j);
		if (j <= 0 || j > MATERIAS) printf("OPÇÃO INVÁLIDA\n\n");
	} while (j <= 0 || j > MATERIAS);
	
	
	printf("|\t\t|MATERIA %d\t|\n", j);
	
	
	for(i = 0; i <= ALUNOS; i++) {
		
		if (i != ALUNOS) printf("|ALUNO %d\t|\t%.2f\t|\n", i + 1, notas[i][j-1]);
		else printf("|MEDIA\t\t|\t%.2f\t|\n", notas[i][j-1]);
		
	}
	
	getchar();
	
}


/* #################################################################################################################################### */
void visualizaNotasAluno(float notas[][MATERIAS+1]) {
	
	int i, j;
	system("clear");
	do{
		printf("Digite o número do aluno que você deseja visualizar: ");
		scanf("%d", &i);
		if (i <= 0 || i > ALUNOS) printf("Opção inválida\n");
		
	} while (i <= 0 || i > ALUNOS); //ok
	
	printf("|\t\t|"); //ok
	for (j = 0; j <= MATERIAS; j++) {
		if (j < MATERIAS) printf("|MATERIA %d\t", j+1);
		else printf("|MEDIA\t\t|\n");
	} //ok
	
	
	for (j = 0; j <= (MATERIAS+1); j++) {
		if (j == 0) printf("|ALUNO %d\t", i);
		else  printf("|\t%.2f\t", notas[i-1][j-1]);
	}
	printf("|\n");
	getchar();
}


/* #################################################################################################################################### */
void modificarNotasAluno(float notas[][MATERIAS+1]) {
	// Essa função possibilitará o usuário a modificar a nota de um aluno em uma matéria
	
	int i, j; //Variáveis que mostrará o apontamento
	float nota;
	
	system("clear");
	
	do {
		printf("Digite o aluno que você deseja modificar a nota: ");
		scanf("%d", &i);
		if (i <= 0 || i > ALUNOS) printf("Esse aluno não existe no sistema\n");
	} while (i <= 0 || i > ALUNOS);
	
	do {
		printf("Digite a matéria que você deseja modificar a nota: ");
		scanf("%d", &j);
		if (j <= 0 || j > MATERIAS) printf("A matéria não existe no sistema\n");
	} while(j <= 0 || j > MATERIAS);
	
	do {
		printf("Digite a nova nota desse aluno nessa matéria: ");
		scanf("%f", &nota);
		if (nota < 0.0 || nota > 10.0) printf("Nota não válida");
	} while(nota < 0.0 || nota > 10.0);
	
	notas[i-1][j-1] = nota;
	
	mediaAlunos( notas );
	mediaCurso( notas );
	
	printf("Modificação executada com sucesso\n");
	printf("Digite Enter para continuar\n");
	getchar();
}


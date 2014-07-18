#define tPilha 10
#define tFila 7


typedef struct Trabalho{
	char disciplina[30];
	char assunto[30];
}Trabalho;

typedef struct Palestra{
	char titulo[30];
	char local[30];
}Palestra;

typedef struct Pilha{
	Palestra elementos[tPilha];
	int tamanho;
}Pilha;

typedef struct Fila{
	Trabalho elementos[tFila];
	int tamanho;
	int primeiro;
	int ultimo;
}Fila;


//quando ultimo+1 == tamanho

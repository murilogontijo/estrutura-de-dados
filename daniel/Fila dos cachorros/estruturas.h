#define tamanhoFila 10
#define tamanhoPilha 10

typedef struct Cachorro{
	int idade;
	char nome[30];
	char raca[10];
}Cachorro;


typedef struct FilaCachorro{
	int ultimo;
	Cachorro cachorro[tamanhoFila];
}FilaCachorro;

typedef struct PilhaCachorro{
	int ultimo;
	Cachorro cachorro[tamanhoPilha];
}PilhaCachorro;


#define tamanho 		10
#define stringModelo 	30
#define stringPlaca 	8


typedef struct Carro{
	int codigo; 	//campo usado na ordenação
	char placa[stringPlaca];
	char modelo[stringModelo];
	int ativo;
}Carro;

typedef struct Lista{
	int ultimo;	//indicação da posição do ultimo elemento
	Carro carros[tamanho]; 
}Lista;


Carro carroHandler;

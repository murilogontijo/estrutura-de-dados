// ############## CONSTANTES ############## //

#define CAR 20
#define MAX 25
typedef char String[CAR];

// ############## ESTRUTURAS ############## //
typedef struct equipe { // *Define o tipo de dado que trabalharemos;
	String nome;		// *Nome do time;
	int qJogos;			// *Deve ser igual ao somatório da quantidade de vitórias, empates e derrotas;
	int qVitorias;		// *Cada vitória contabiliza 3 pontos para o time;
	int qEmpates;		// *Cada empate contabiliza 1 ponto para o time;
	int qDerrotas;		// *Cada derrota não contabiliza pontos ao time;
	int Pontos;			// *Será calculado através da seguinte formula: Pontos = (Vitórias *3) + Empates;
	int GolsPro;		// *Contabiliza a quantidade de gols feitos por um time;
	int GolsContra;		// *Contabiliza a quantidade de gols levados por um time;
	int Saldo;			// *É calculado pela diferença dos gols pró pelos gols contra;
	
}T_time;

typedef struct lista_estatica { // * Esse tipo define a lista que trabalharemos. São as caracteristicas que a lista possuirá //
	T_time vetor[MAX];	// *Define o vetor de elementos time;
	int elemento;		// *Define a quantidade de elementos que a lista possui;
}T_Lista;

// ############## Funções críticas ############## //
		/* Define algumas funções críticas que 
		 * devem ser executadas antes da entrada
		 *  na função main */

// ############## Função main ############## //

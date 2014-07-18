// Lista encadeada dinâmica //
/* Estrutura */ 

typedef struct { 	
	// *Define o tipo de dado que trabalharemos
	// *Representa o elemento
	
	String nome;						// *Nome do time;
	int qJogos;							// *Quantidade de jogos: Deve ser igual ao somatório da quantidade de vitórias, empates e derrotas;
	int qVitorias;						// *Quantidade de vitórias: Cada vitória contabiliza 3 pontos para o time;
	int qEmpates;						// *Quantidade de empates: Cada empate contabiliza 1 ponto para o time;
	int qDerrotas;						// *Quantidade de derrotas: Cada derrota não contabiliza pontos ao time;
	int Pontos;							// *Quantidade de pontos: Será calculado através da seguinte formula: Pontos = (Vitórias *3) + Empates;
	int GolsPro;						// *Quantidade de gols feitos: Contabiliza a quantidade de gols feitos por um time;
	int GolsContra;						// *Quantidade de gols levados: Contabiliza a quantidade de gols levados por um time;
	int Saldo;							// *Saldo de gols: É calculado pela diferença dos gols pró pelos gols contra;
	
}T_time;

typedef struct cx {
	/*Define a caixa da lista. Contém o elemento e o ponteiro que aponta para o próximo elemento */
	T_time time;
	struct cx * prox;
}T_caixa;

typedef T_caixa * pontCaixa; //Cria o tipo ponteiro de caixa

typedef struct {
	/*Essa é a lista encadeada dinâmica. */
	pontCaixa prim, ult; //Dois ponteiros: um aponta para a cabeça da lista e o último aponta para o último elemento da lista
	int tamLista;	//Informa o tamanho da lista
}T_Lista;

/*===========================================================================================================================*/

typedef struct {
	String time1; // Define o nome do time da casa
	int golsTime1; // Define quantos gols feitos pelo time da casa
	String time2; // Define o nome do time visitante
	int golsTime2; // Define quantos gols feitos pelo time visitante
	int jogou; // informa se o jogo ocorreu ou não
}T_jogo;

typedef struct cxjogo {
	T_jogo jogo; //Contém o jogo (elemento da caixa)
	struct cxjogo * prox; //Aponta para o próximo jogo da lista
}T_caixaJogo;

typedef T_caixaJogo * pontCaixaJogo; // Cria um ponteiro que aponta para uma caixa de jogos

typedef struct {
	/* Faz a efetiva criação da lista de jogos */
	pontCaixaJogo prim, ult;
	int tamCampeonato;
}T_campeonato;

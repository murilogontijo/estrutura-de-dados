/*  == Descrissão do arquivo ==
 * 	Esse arquivo contém as estrutura de dados que serão utilizadas no decorrer do programa.
 * 
 * 	== Lógica algorítmica ==
 * 	Os comentários, no decorrer do arquivo descrevem a lógica algorítmica. Caso algum script necessite ser detalhado, 
 * 	será descrito sua lógica nessa parte do arquivo.
 * */

// ############## ESTRUTURAS ############## //
typedef struct equipe { 	
	// *Define o tipo de dado que trabalharemos;
	
	String nome;						// *Nome do time;
	int qJogos;							// *Quantidade de jogos: Deve ser igual ao somatório da quantidade de vitórias, empates e derrotas;
	int qVitorias;						// *Quantidade de vitórias: Cada vitória contabiliza 3 pontos para o time;
	int qEmpates;						// *Quantidade de empates: Cada empate contabiliza 1 ponto para o time;
	int qDerrotas;						// *Quantidade de derrotas: Cada derrota não contabiliza pontos ao time;
	int Pontos;							// *Quantidade de pontos: Será calculado através da seguinte formula: Pontos = (Vitórias *3) + Empates;
	int GolsPro;						// *Quantidade de gols feitos: Contabiliza a quantidade de gols feitos por um time;
	int GolsContra;						// *Quantidade de gols levados: Contabiliza a quantidade de gols levados por um time;
	int Saldo;							// *Saldo de gols: É calculado pela diferença dos gols pró pelos gols contra;
	String estadioCasa;				// *Define qual o estádio casa do time;
	String estadioCasaAlternativo;		// *Define uma alternativa caso o estádio casa esteja ocupado;
	
}T_time;

typedef struct lista_estatica { 
	// * Esse tipo define a lista que trabalharemos. São as caracteristicas que a lista possuirá //
	
	T_time vetor[MAX];	// *Define o vetor de elementos time;
	int elemento;		// *Define a primeira posição disponível da lista
	
}T_Lista;

// ------------------------------------------------------------------------------------------------------- //

typedef struct {
	/*Essa é a struct para definir os dois times que se enfrentam a cada jogo */
	String time1;
	int golsTime1;
	String time2;
	int golsTime2;
	int jogou;
}T_jogo;

typedef struct {
	/*Essa é a lista de jogos do campeonato.
	 * Quando próximo for igual a maximoDeJogos da struct contadora de jogos, deve-se parar de atribuir jogos*/
	T_jogo jogoRodada[JOGOS];
	int proximo;
}T_listaJogo;



 /* Assinatura:
 * Structs.h
 * 
 * Autor: Bruno Nogueira de Oliveira, aluno do terceiro período do curso de 
 * Sistemas de Informação na Universidade Federal de Goiás.
 * 
 * Algoritmo desenvolvido para disciplina de estrutura de dados, sobre a orientação do 
 * Professor Edmundo S. Spotto
 * 
 * Esse programa é um software proprietário; Ele não pode ser redistribuido
 * ou modificado, sem a permissão prévia do proprietário, informado acima.
 * 
 * Versão inicial desenvolvida dia 28.09.2013
 * Última modificação: 23.10.2013 (entrega do pacote final)
 * 
 */

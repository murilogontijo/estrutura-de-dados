/*  == Descrissão do arquivo ==
 * 	Esse arquivo contém CONSTANTES, ENUMS e TIPOS PRÉ DEFINIDOS que o sistema necessitará.
 * 
 * 	== Lógica algorítmica ==
 * 	Os comentários, no decorrer do arquivo descrevem a lógica algorítmica. Caso algum script necessite ser detalhado, 
 * 	será descrito sua lógica nessa parte do arquivo.
 * */

// ############## FUNÇÃO ESPECIAL ############## //
/*Essa função teve que ser escrita aqui, porque uma das constantes precisava ser iniciada com um valor que dependia do valor de outra constante
 * O caso é a constante JOGOS que é iniciada baseadana quantidade definida na constante MAX que define quantos times participam do campeonato.
 */
int contador(int i) {
	int soma = i;
	if(i > 0) soma += contador(i-1);
	return soma;
}

// ############## CONSTANTES ############## //
#define MAX 50			/*Define a quantidade de times que terão no campeonato
						  Define a quantidade de elementos da lista	*/
#define CAR 20 

#define JOGOS 1275

// ############## DEFINIÇÕES DE TIPO ############## //
typedef char String[CAR];		//Tipo pré definido para vetor de caracteres.

 // ############## DEFINIÇÕES DE ENUM ############## //
enum boolean {true = 0, false = -1};  	// Enum boleano que retorna apenas os valores verdadeiro (0) e falso (1)


  /* Assinatura:
 * constantes.h
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

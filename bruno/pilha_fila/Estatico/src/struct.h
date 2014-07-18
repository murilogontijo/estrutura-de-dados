/*  == Descrissão do arquivo ==
 * 		Esse arquivo contém as estrutura de dados que serão utilizadas no decorrer do programa.
 * 
 * 	== Lógica algorítmica ==
 * 	Os comentários, no decorrer do arquivo descrevem a lógica algorítmica. Caso algum script necessite ser detalhado, 
 * 	será descrito sua lógica nessa parte do arquivo.
 * */ 

typedef struct cliente {
	String nome;
	int idade;
	int senha;
}T_cliente;

typedef struct Fila_Bancaria {
	T_cliente fila[MAX];
	int proximo;
	int ultimo;
	int qElementos;
}T_fila;


typedef struct senhas {
	int atribuir;
}T_senha;


typedef struct pilhaAux {
	T_cliente empilhado[MAX];
	int topo;
}T_pilha;

typedef struct Preferencial {
	int quantidade;
}T_preferencial;

/* Assinatura:
 * struct.h
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
 * Versão inicial desenvolvida dia 25.10.2013
 * Última modificação: 27.10.2013 (entrega do pacote final)
 * 
 */

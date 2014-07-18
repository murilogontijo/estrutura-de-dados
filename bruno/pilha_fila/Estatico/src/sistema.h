 /*  == Descrissão do arquivo ==
 * 	Esse arquivo contém as funções sistemicas que controlam o sistema e encapsula funções complexas do programa.
 * 
 * 	== Lógica algorítmica ==
 * 	Os comentários, no decorrer do arquivo descrevem a lógica algorítmica. Caso algum script necessite ser detalhado, 
 * 	será descrito sua lógica nessa parte do arquivo.
 * */

void iniciaFilaBanco(T_fila * filaBanco) {
	filaBanco->proximo = 0;
	filaBanco->ultimo = 0;
	filaBanco->qElementos = 0;
}

void iniciaSenhas(T_senha * controlaSenha) {
	controlaSenha->atribuir = 1;
}

void iniciaPreferenciais(T_preferencial * preferenciais) {
	preferenciais->quantidade = 0;
}

void iniciaEmpilhador(T_pilha * empilhador) {
	empilhador->topo=0;
}

int validaFilaCheia (T_fila * filaBanco)  {
	if (filaBanco->qElementos == MAX) return true;
	else return false;
}

int validaFilaVazia(T_fila * filaBanco) {
	if (filaBanco->qElementos == 0) return true;
	else return false;
}
/* Assinatura:
 * sistema.h
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

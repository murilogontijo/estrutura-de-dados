/*  == Descrissão do arquivo ==
 * 	Esse arquivo contém as funções que tem interação com o usuário;
 * 
 * 	== Lógica algorítmica ==
 * 	Os comentários, no decorrer do arquivo descrevem a lógica algorítmica. Caso algum script necessite ser detalhado, 
 * 	será descrito sua lógica nessa parte do arquivo.
 * */


 // ############## FUNÇÕES ############## //
 
int telaConfirmacao() {
	 
	char OP;
	 
	do {
		printf("Tem certeza que deseja efetuar essa operação (S / N)? ");
		scanf("%c", &OP);
	} while (OP != 'S' && OP != 's' && OP != 'N' && OP != 'n');
	
	if (OP == 'S' || OP == 's') return true;
	else return false;
	 
}
 
void travatela(){
	// Essa função aparece para o usuário quando ele termina de fazer alguma ação no sistema. Ela solicita que o usuário digite enter para voltar para o fluxo principal //
	
	printf("Digite ENTER para continuar\n"); //Mostra mensagem para usuário
	getchar(); //Aguarda ele apertar enter
	
}

int vizualizacaoPlateia(T_calendario * cronograma, int idEvento) {
	int i, j;  //variáveis contadoras
	int dia = 0, hora = 0;
	void desmembraHash(int idEvento, int * dia, int * hora);
	
	desmembraHash(idEvento, &dia, &hora);
	
	if(cronograma->datas[dia].apresentacao[hora].horario == false) {
		printf("Evento não disponível\n\n");
		return false;
	}
	
	for(i = 0; i < VERTICAL; i++) {
		for(j = 0; j < LATERAL; j++) {
			if(cronograma->datas[dia].apresentacao[hora].publico.blocoEsquerda[i][j].vendido != -1) {
				printf("Codigo: %d Cliente: %s, Bloco da Esquerda, fileira %d, posição %d\n", cronograma->datas[dia].apresentacao[hora].publico.blocoEsquerda[i][j].vendido, cronograma->datas[dia].apresentacao[hora].publico.blocoEsquerda[i][j].cliente, i+1, j);
			}
			if(cronograma->datas[dia].apresentacao[hora].publico.blocoDireita[i][j].vendido != -1) {
				printf("Codigo: %d Cliente: %s, Bloco da Direita, fileira %d, posição %d\n", cronograma->datas[dia].apresentacao[hora].publico.blocoDireita[i][j].vendido, cronograma->datas[dia].apresentacao[hora].publico.blocoDireita[i][j].cliente, i+1, j);
			}
		}
	}
	
	return true;
}

  /* Assinatura:
 * user.h
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

/*  == Descrissão do arquivo ==
 * 	Esse arquivo contém as funções farão a geração de jogos e devolverá para o usuário a lista de jogos do campeonato;
 * 
 * 	== Lógica algorítmica ==
 * 	Os comentários, no decorrer do arquivo descrevem a lógica algorítmica. Caso algum script necessite ser detalhado, 
 * 	será descrito sua lógica nessa parte do arquivo.
 * */
 
void criarCampeonato(T_Lista * lista, T_listaJogo * campeonato) {
	
	system("clear");
	
	// Declaração de variáveis //
		
	int i, j; //Variáveis contadoras//
		
	for(i = 0; i < lista->elemento; i++){
		for(j = (i+1); j < lista->elemento; j++){
			atribuirJogo(campeonato, lista, i, j);
			campeonato->proximo++;
		}
	}
	
	
	for(i = 0; i < campeonato->proximo; i++) {
		printf("%s x %s\n", campeonato->jogoRodada[i].time1, campeonato->jogoRodada[i].time2);
	}
	getchar();
	travatela();
	

	
}
 
 
 /* Assinatura:
 * criarCampeonato.h
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
 * Versão inicial desenvolvida dia 13.10.2013
 * Última modificação: 23.10.2013 (entrega do pacote final)
 * 
 */

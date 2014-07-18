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
 
 void listarElementos(T_Lista * lista) {
	// Essa função mostrará na tela do usuário a tabela do campeonato //
	int i = 0;	// Variável contadora //
	
	while (i < lista->elemento) {
		printf("|Time: %s| %dº |:Pontos: %d |Jogos:  %d  |Vitórias: %d |Empates: %d |Derrotas: %d |Gols Pró: %d |Gols Contra: %d |Saldo: %d |\n\n",lista->vetor[i].nome,i+1 ,lista->vetor[i].Pontos, lista->vetor[i].qJogos, lista->vetor[i].qVitorias, lista->vetor[i].qEmpates, lista->vetor[i].qDerrotas, lista->vetor[i].GolsPro, lista->vetor[i].GolsContra, lista->vetor[i].Saldo);
		
		i++; // Incrementa a variável contadora para a próxima interação //
	}
	
}

void listarJogos(T_listaJogo * campeonato) {
	int i; //Variável contadora//
	
	for(i = 0; i < campeonato->proximo; i++) {
		if(campeonato->jogoRodada[i].jogou == true) printf("JOGO %d: %s %d x %d %s\n", (i+1), campeonato->jogoRodada[i].time1, campeonato->jogoRodada[i].golsTime1, campeonato->jogoRodada[i].golsTime2, campeonato->jogoRodada[i].time2);
		else printf("JOGO %d: %s x %s\n", (i+1), campeonato->jogoRodada[i].time1, campeonato->jogoRodada[i].time2);
	}
	
}
 
 int detalheTime(T_time * time, T_Lista * lista) {
	/* Essa função faz a inserção de um time no final da lista.
	 * Ela recebe como parametro a lista estática onde o time deve ser inserdo e um ponteiro apontando para time, variável da função main que preencheremos os dados. Ela retorna TRUE caso a inserção tenha sucesse e FALSE caso o time solicitado já exista na lista*/
	
	String temp; // Variável para receber o nome do time.
	
	int procurarTime(T_Lista * lista, String nome); /* Função para procurar um time na lista. Por algum motivo estranho o compilador está 
														exigindo essa declaração de função aqui*/
	
	printf("Digite o nome do time: ");
	getchar();
	fgets(temp, CAR, stdin);
	if (procurarTime(lista, temp) == false) {
		strcpy(time->nome, temp);
		time->qJogos = 0;
		time->qVitorias = 0;
		time->qEmpates = 0;
		time->qDerrotas = 0;
		time->Pontos = time->qVitorias * 3 + time->qEmpates;
		time->GolsPro = 0;
		time->GolsContra = 0;
		time->Saldo = time->GolsPro - time->GolsContra;
		return true; // O time informado foi incluído! 
	}
	
	else return false; //O time não pode ser incluído porque já existe!

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

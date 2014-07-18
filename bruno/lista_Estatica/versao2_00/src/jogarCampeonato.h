/*  == Descrissão do arquivo ==
 * 	Esse arquivo contém a função 'jogarCampeonato' que fará a atribuição de resultados aos jogos e a dinamização das tabelas.
 * 
 * 	== Lógica algorítmica ==
 * 	Os comentários, no decorrer do arquivo descrevem a lógica algorítmica. Caso algum script necessite ser detalhado, 
 * 	será descrito sua lógica nessa parte do arquivo.
 * */
 
 void jogarCampeonato(T_Lista * lista, T_listaJogo * campeonato) {
	 
	int op; //Variável de atribuição de opção
	int scan, g1, g2; //Auxilia na entrada de dados;
	 
	do {
		system("clear");
		printf("Campeonato de futebol\n\n");
		printf("Digite 0:\tPara terminar o campeonato\n");
		printf("Digite 1:\tPara visualizar a tabela atual o campeonato\n");
		printf("Digite 2:\tPara visualizar os resultados dos jogos\n");
		printf("Digite 3:\tPara atribuir o próximo jogo\n");
		printf("Digite a opção desejada: ");
		scanf("%d", &op);
		
		switch(op) {
			case 0:
				getchar();
				if (telaConfirmacao() == true) {
					op = 9;
					break;
				}
				else continue;
			case 1:
				system("clear");
				printf("Tabela do campeonato\n\n");
				listarElementos(lista);
				getchar();
				travatela();
				break;
				
			case 2:
				system("clear");
				printf("Resultado dos jogos\n\n");
				listarJogos(campeonato);
				getchar();
				travatela();
				break;
				
			case 3:
				system("clear");
				printf("Atribuir resultado ao jogo\n\n");
				listarJogos(campeonato);
				do {
					printf("Digite o jogo que você deseja atribuir resultado: ");
					scanf("%d", &scan);
					if (scan > campeonato->proximo) printf("Opção inválida\n\n");
				}while (scan > campeonato->proximo);
				
				scan--; //Decrementa pois a opção informada pelo usuário é sempre maior em 1 do que a real posição no vetor //
				
				system("clear");
				if(campeonato->jogoRodada[scan].jogou == false) {
					printf("Digite o resultado do jogo\n\n");
					do {
						printf("Gols feitos pelo %s: ", campeonato->jogoRodada[scan].time1);
						scanf("%d", &g1);
						if (g1 < 0) printf("Não se pode atribuir resultados negativos a um jogo\n");
					}while(g1 < 0);
					do {
						printf("Gols feitos pelo %s: ", campeonato->jogoRodada[scan].time2);
						scanf("%d", &g2);
						if (g2 < 0) printf("Não se pode atribuir resultados negativos a um jogo\n");
					}while(g2 < 0);
					
					campeonato->jogoRodada[scan].golsTime1 = g1;
					campeonato->jogoRodada[scan].golsTime2 = g2;
					
					if (g1 > g2) vitoria(lista, campeonato, scan, g1, g2);
					if (g1 == g2) empate(lista, campeonato, scan, g1, g2);
					if (g1 < g2) derrota(lista, campeonato, scan, g1, g2);
					
					campeonato->jogoRodada[scan].jogou = true;
				}
				
				else {
					printf("Jogo já foi jogado\n\n%s %d x %d %s\n", campeonato->jogoRodada[scan].time1, campeonato->jogoRodada[scan].golsTime1, campeonato->jogoRodada[scan].golsTime2, campeonato->jogoRodada[scan].time2);
					getchar();
					travatela();
				}
				break;
				
			default: 
				printf("Opção inválida\n");
				getchar();
				travatela();
				break;
		}
	}while(op != 9);
	 
	printf("Final do Campeonato");
	printf("CAMPEÃO: %s", lista->vetor[0].nome);
	printf("VICE-CAMPEÃO: %s\n", lista->vetor[1].nome);
	
	printf("Classificação\n\n");
	for(scan = 2; scan < lista->elemento; scan++) {
		printf("%dº: %s", scan+1, lista->vetor[scan].nome);
	}
 }
 
   /* Assinatura:
 * principal.c
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

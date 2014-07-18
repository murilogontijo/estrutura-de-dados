void jogarCampeonato(T_Lista * lista, T_campeonato * jogos) {
	
	int op;
	int validador = false;
	
	/* Painel de opções */
	do {
		system("clear");
		printf("Campeonato de futebol\n\n");
		printf("Digite 0:\tPara terminar o campeonato\n");
		printf("Digite 1:\tPara visualizar a tabela atual o campeonato\n");
		printf("Digite 2:\tPara visualizar os resultados dos jogos\n");
		printf("Digite 3:\tPara jogar o próximo jogo\n");
		printf("Digite a opção desejada: ");
		scanf("%d", &op);
		
		switch(op) {
			case 0:
				system("clear");
				printf("Acabou o campeonato!\n\n");
				validador = true;
				getchar();
				travatela();
				break;
				
			case 1:
				system("clear");
				printf("Visualizar tabela do campeonato\n\n");
				listarTimes(lista);
				getchar();
				travatela();
				break;
				
			case 2:
				system("clear");
				printf("Visualizar resultados dos jogos\n\n");
				listarResultados(jogos);
				getchar();
				travatela();
				break;
				
			case 3:
				system("clear");
				printf("Jogar um jogo\n\n");
				listarResultados(jogos);
				printf("Digite o número do jogo que vocẽ deseja jogar: ");
				scanf("%d", &op);
				jogarJogo(jogos, lista, op);
				getchar();
				travatela();
				break;
			
			default:
				printf("Opção inválida\n\n");
				getchar();
				travatela();
				break;
		}
		
	}while(validador == false);
}

void cadastramento(T_Lista * lista) {
	
	int validador = false;
	int op;
	T_time temp;
	String nome;
	
	do {
			do {
				system("clear");
				printf("############ CADASTRAMENTO DE TIMES NO CAMPEONATO ############\n\n\n");
				
				printf("Digite a opção que você deseja\n\n");
				printf("Digite 1:\tPara incluir um time no campeonato\n");
				printf("Digite 2:\tPara editar um time do campeonato\n");
				printf("Digite 3:\tPara excluir um time no campenato\n");
				printf("Digite 4:\tPara visualizar os times da competição\n");
				printf("Digite 0:\tPara finalizar a inserção de times\n\n");
				printf("Digite a opção desejada: ");
				
				scanf("%d", &op);
				if (op < 0 || op > 4) printf("Opção inválida\n");
			}while (op < 0 || op > 4);
			
			getchar(); // Para retirar o caractere de retorno de carro do buffer //
			
			switch(op) {
				/* #################### Terminar inserção #################### */
				case 0:
					validador = true;
					break;
					
				/* #################### Inserir time #################### */
				case 1:
					do {
						system("clear");
						printf("Onde você quer inserir o time?\n\n");
						printf("Digite 1:\tPara inserir no final da tabela\n");
						printf("Digite 2:\tPara inserir no meio da tabela\n");
						printf("Digite 3:\tPara inserir na primeira posição da tabela\n\n");
						
						printf("Digite a opção desejada: ");
						scanf("%d", &op);
						if (op < 1 || op > 3) {
							printf("Opção inválida\n\n");
							travatela();
						}
					} while(op < 1 || op > 3);
						
					switch(op) {
						case 1:
							system("clear");
							printf("Inserir time no final\n\n");
							temp = criarNovoTime(lista);
							inserirTime(lista, temp, lista->tamLista + 1);
							travatela();
							break;
								
								
						case 2:
							system("clear");
							printf("Função de inserção de time no meio\n\n");
							printf("Digite a posição que você deseja inserir o time: ");
							scanf("%d", &op);
							temp = criarNovoTime(lista);
							inserirTime(lista, temp , op);
							travatela();
							break;
								
						case 3:
							system("clear");
							printf("Função de inserção de time no início.\n\n");
							temp = criarNovoTime(lista);
							inserirTime(lista, temp, 1);
							travatela();
							break;
					} // Fim do Switch de inserção
					break;
				
				/* #################### Editar um time na competição #################### */
				case 2:
					/* Cabeçalho */
					system("clear");
					printf("Editar um time na competição\n\n");
					
					/* Mostra para o usuário uma listagem de times da competição */
					listarTimes(lista);
					
					/* Pede para o usuário digitar o nome do time incorreto que ele deseja editar */
					printf("Digite o nome do time que você deseja editar: ");
					fgets(nome, TAM, stdin);
					
					/* Chama a função excluir time para retirar o time da competição e informar qual posição o time estava */
					op = excluirTime(lista, &temp, nome);
					
					if (op != -1) {
						/* Agora faremos a edição do nome do time */
						printf("Digite o nome correto do time: ");
						fgets(nome, TAM, stdin);
						strcpy(temp.nome, nome);
					
						/* Inserimos novamente o time na competição */
						inserirTime(lista, temp, op);
					}
					else printf("Não ocorreu edição!\n\n");
					
					travatela();
					break;
				
				/* #################### Excluir um time da competição #################### */
				case 3:
					system("clear");
					printf("Excluir um time da competição\n\n");
					/* Mostra para o usuário uma listagem de times da competição */
					listarTimes(lista);
					printf("\nDigite o nome do time que deseja excluir: ");
					fgets(nome, TAM, stdin);
					excluirTime(lista, &temp, nome);
					travatela();
					break;
				
				/* #################### Listar times da competição #################### */
				case 4:
					system("clear");
					printf("Listagem de times da competição\n\n");
					listarTimes(lista);
					travatela();
					break;
				
			}// Fim do Switch principal
			
	}while(validador == false);
}

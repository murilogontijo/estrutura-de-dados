 /*  == Descrissão do arquivo ==
 * 	Esse arquivo contém as ações principais para cadastramento de times no campeonato
 * 
 * 	== Lógica algorítmica ==
 * 	Os comentários, no decorrer do arquivo descrevem a lógica algorítmica. Caso algum script necessite ser detalhado, 
 * 	será descrito sua lógica nessa parte do arquivo.
 * */

void cadastramento(T_Lista * lista) {
	
	int testador = false; // Essa é uma variável de controle que será utilizada apenas para modificar as fases do programa para o usuário //
	int op; 				// Variável para interagir entre as opções do sistema.
	T_time time; 			// Variável para pegar informações do time.
	int pos;				// Variável posição
	String nome, nomeCorrigido;	// Variável para correção de nome
	
	
	do {
		do {
			system("clear");
			printf("############ CADASTRAMENTO DE TIMES NO CAMPEONATO ############\n\n\n");
			
			printf("Digite a opção que você deseja\n\n");
			printf("Digite 1:\tPara incluir um time no campeonato\n");
			printf("Digite 2:\tPara editar um time do campeonato\n");
			printf("Digite 3:\tPara procurar um time no campeonato\n");
			printf("Digite 4:\tPara excluir um time no campenato\n");
			printf("Digite 5:\tPara visualizar os times da competição\n");
			printf("Digite 0:\tPara finalizar a inserção de times\n\n");
			printf("Digite a opção desejada: ");
			
			scanf("%d", &op);
			if (op < 0 || op > 5) printf("Opção inválida\n");
		}while (op < 0 || op > 5);
		
		switch(op) {
			case 1:
				if (verificarListaCheia(lista) == false) {//lista não está cheia
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
					}while(op < 1 || op > 3);
					
					switch(op) {
						case 1:
							system("clear");
								printf("Inserir time no final\n\n");
								if (detalheTime(&time, lista) == true) {
									pos = lista->elemento;
									inserirElemento(lista, pos, time);
									printf("\n\nTime inserido com sucesso\n");
								}
								else {
									printf("O time não foi inserido porque já existe na tabela\n");
								}
							travatela();
							
							break;
							
							
						case 2:
							system("clear");
							printf("Função de inserção de time no meio\n\n");
							if (detalheTime(&time, lista) == true) {
								do {
									printf("Digite a posição que você deseja adicionar o time: ");
									scanf("%d", &pos);
									if (pos <= 0 || pos > MAX) printf("Posição inválida\n");
								}while(pos <= 0 || pos > MAX);
								pos -= 1;
								inserirElemento(lista, pos, time);
								printf("\n\nTime inserido com sucesso\n");
								travatela();
							}
							else {
								printf("Time já existe cadastrado!\n\n");
								travatela();
							}
							
							break;
							
						case 3:
							system("clear");
							printf("Função de inserção de time no início.\n\n");
							if (detalheTime(&time, lista) == true) {
								inserirElemento(lista, 0 ,time);
							}
							else {
								printf("Time já existe cadastrado!\n\n");
								travatela();
							}
							
							break;
					}
				}
				else { //lista está cheia
					printf("A lista já está cheia.\n\nNão é possível inserir mais times\n");
					travatela();
				}
				
				break;
				
			case 2:
				system("clear");
				
				if (verificarListaVazia(lista) == false) {
					listarElementos(lista);
					printf("\n\n");
					do{
						printf("\n\nDigite a posição do time que você quer corrigir o nome: ");
						scanf("%d", &pos);
						if (pos > lista->elemento) printf("Posição inválida\n\n");
					}while(pos > lista->elemento);
					
					pos--; //Decrementa pois a posição do time na lista é uma posição a menos daquela que o usuário vê na tela
					
					printf("Digite o nome correto: ");
					getchar();
					fgets(nomeCorrigido, CAR, stdin);
					if (procurarTime(lista, nomeCorrigido) == false) {
						if (telaConfirmacao() == true) {
							corrigirElemento(lista, pos, nomeCorrigido);
							printf("Nome do time corrigido com sucesso\n");
						}
						else printf("Operação abortada\n\n");
					}
					else printf("Já existe um time cadastrado com esse mesmo nome\n");
				}
				else printf("Não existe nenhum time cadastrado no campeonato. Favor, insira algum time\n\n");
				
				travatela();
				break;
			case 3:
				system("clear");
				if (verificarListaVazia(lista) == false) {
					printf("Digite o nome do time que você quer procurar: ");
					getchar();
					fgets(nome, CAR, stdin);
					pos = procurarTime(lista, nome);
					if (pos != false) {
						printf("Time encontrado\n\n");
						printf("Nome: %s\n", lista->vetor[pos].nome);
						printf("Pontos: %d\n", lista->vetor[pos].Pontos);
						printf("Vitórias: %d\n", lista->vetor[pos].qVitorias);
						printf("Empates: %d\n", lista->vetor[pos].qEmpates);
						printf("Derrotas: %d\n", lista->vetor[pos].qDerrotas);
						printf("Gols Pró: %d\n", lista->vetor[pos].GolsPro);
						printf("Gols Contra: %d\n", lista->vetor[pos].GolsContra);
						printf("Saldo de gols: %d\n", lista->vetor[pos].Saldo);
						printf("\n"); 
					}
					else {
						printf("Time não encontrado\n\n");
					}
				}
				else printf("Não existe nenhum time cadastrado no campeonato. Favor, insira algum time\n\n");
				
				travatela();
				
				break;
			case 4:
				system("clear");
				printf("Deletar time\n\n");
				if(verificarListaVazia(lista) == false) {
					do{
						listarElementos(lista);
						printf("\n\nDigite a posição do time que você quer excluir do campeonato: ");
						scanf("%d", &pos);
						if (pos > lista->elemento) printf("Posição inválida\n\n");
					}while(pos > lista->elemento);
					
					pos--; //Decrementa o pos pois o valor visto pelo o usuário é 1 unidade maior que seu indice no vetor
					
					getchar(); //chamamos essa função aqui para ela fazer a limpeza do buffer e não dar pau na próxima função.
					if (telaConfirmacao() == true) {
						excluirElemento(lista, pos);
						printf("Time excluído com sucesso\n\n");
					}
					else printf("OPERAÇÃO ABORATADA\n\n");
				}
				else printf("OPERAÇÃO ABORATADA. Não existe times no campeonato.\nPor favor, insira algum time\n\n");
				
				getchar(); //limpa o buffer
				travatela();
				break;
				
			case 5:
				system("clear");
				printf("Tabela do campeonato\n\n");
				if (verificarListaVazia(lista) == false) listarElementos(lista);
				else printf("Não existe time cadastrado no campeonato\n\n");
				getchar();
				travatela();
				break;
				
			case 0:
				printf("\n\n");
				getchar();
				if (telaConfirmacao() == true) {
					testador = true;
					printf("Você está saindo das operações de cadastramento\n\n");
				}
				else {
					printf("Operação abortada\n");
				}
				getchar();
				travatela();
				break;
		}
		
	} while(testador == false);
	
} // Fim da função cadastramento



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
 * Versão inicial desenvolvida dia 29.09.2013
 * Última modificação: 23.10.2013 (entrega do pacote final)
 * 
 */

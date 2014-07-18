void criarListaVazia(T_Lista * lista) {
	
	/* Começamos pegando a lista, previamente criada e pegamos o ponteiro prim, alocamos um espaço de memória do tamanho de uma caixa e apotamos o ponteiro prim para esse espaço de memória. Ele será a cabeça da lista*/
	lista->prim = (T_caixa *)malloc(sizeof(T_caixa));
	
	/* Apontamos o ponteiro prox, da cabeça da lista, para NULL*/
	lista->prim->prox = NULL;
	
	/* Apontamos o ponteiro últ para o mesmo espaço de memória apontado pelo ponteiro prim*/
	lista->ult = lista->prim;
	
	/* Informamos que o tamanho da lista é zero*/
	lista->tamLista = 0;
	
} // Fim da função criar lista vazia

void criarCampeonatoVazio(T_campeonato * jogos) {
	
	/* Criamos a cabeça da lista e apontamos o ponteiro prim para ela */
	jogos->prim = (T_caixaJogo *)malloc(sizeof(T_caixaJogo));
	
	/* Aterramos o ponteiro prox, pois não existe nenhum jogo criado ainda */
	jogos->prim->prox = NULL;
	
	/* Apontamos o pronteiro ult para a cabeça da lista. Isso vai simbolizar que a lista está vazia */
	jogos->ult = jogos->prim;
	
	/* Informamos que o tamanho da lista é 0 */
	jogos->tamCampeonato = 0;
}

void inserirTime(T_Lista * lista, T_time novoTime, int posicao) {
	/* Essa função vai fazer a inserção do time na posição definida pelo usuário*/ 
	
	/*Cria uma variável contadora que vai definir qual local o time será incluído */
	int i = 1;
	
	/* Cria dois ponteiro auxiliares. Um aponta para a nova caixa inserida (Aux) o outro aponta para a cabeça da lista (L). Esse será movimentado para inserir o time na lista; */
	pontCaixa Aux, L;
	
	/* Cria um espaço na memória do tamamho de uma caixa e faz o ponteiro Aux apontar para lá. */
	Aux = (T_caixa *)malloc(sizeof(T_caixa));
	
	/* Insere o conteúdo do novo time na caixa */
	Aux->time = novoTime;
	
	/* Faz com que L aponte para a cabeça da lista */
	L = lista->prim;
	
	/* Enquanto a variável contadora 'i' for menor que a posição, L vai apontar para o proximo elemento.*/
	while(L->prox != NULL && i < posicao) {
		L = L->prox;
		i++;
	}
	
	/*O ponteiro prox de 'Aux' recebe o apontamento do ponteiro prox de 'L'*/
	Aux->prox = L->prox;
	
	/*O ponteiro prox de L recebe a caixa apontada por Aux */
	L->prox = Aux;
	
	/*Se o ponteiro 'L' estiver apontando para o mesmo ponteiro apontado pelo ponteiro 'ult' da lista, 'ult' passará a apontar para o elemento apontado pelo ponteiro prox da variável L */
	if(L == lista->ult) {
		lista->ult = L->prox;
	}
	
	/*Incrementa o tamanho da lista */
	lista->tamLista++;
	
} //Fim da função inserção de time


void listarTimes(T_Lista * lista) {
	pontCaixa Aux;
	int i = 1;
	
	Aux = lista->prim;
	
	while(Aux->prox != NULL) {
		
		printf("|Time: %s| %dº |:Pontos: %d |Jogos:  %d  |Vitórias: %d |Empates: %d |Derrotas: %d |Gols Pró: %d |Gols Contra: %d |Saldo: %d |\n\n", Aux->prox->time.nome, i, Aux->prox->time.Pontos, Aux->prox->time.qJogos, Aux->prox->time.qVitorias, Aux->prox->time.qEmpates, Aux->prox->time.qDerrotas, Aux->prox->time.GolsPro, Aux->prox->time.GolsContra, Aux->prox->time.Saldo);
		i++;
		Aux = Aux->prox;
	}
	
} //Fim da fulção listar Times

int excluirTime(T_Lista * lista, T_time * time, String nome) {
	//Cria variáveis auxiliar do tipo caixa
	pontCaixa Aux, L;
	int pos = 1; //Essa variável serve exclusivamente para informar a posição que o time estava, para edição de informação; 

	if(lista->prim == lista->ult) {
		printf("A lista está vazia\n\n");
		return -1;
	}
	else {
		// Aux aponta para a cabeça da lista
		Aux = lista->prim;
		
		/*Enqanto Aux nao for o último elemento da lista e o nome o elemento apontado pelo ponteiro prox de 'Aux' for diferente do nome do parâmetro, fazer Aux apontar para o próximo elemento da lista*/
		while(Aux != lista->ult && strcmp(Aux->prox->time.nome, nome) != 0) {
			Aux = Aux->prox;
			pos++;
		}// fim do while
		
		/* Ao terminar o ciclo for, se 'Aux' estiver apontado para o último elemento da lista, o elemento procurado não existe*/
		if(Aux == lista->ult) {
			printf("O elemento não existe na lista\n\n");
			return -1;
		}
		/*Senão: */
		else {
			/* Faz L apontar para o Elemento que será deletado */
			L = Aux->prox;
			
			/* Coloca o time que será deletado na variável Time, passada como ponteiro (isso acontece para ocorrer manipulação externa do conteúdo*/
			*time = L->time;
			
			/* Faz com que o ponteiro prox de Aux, aponte para o elemento apontado pelo ponteiro prox do elemento que será deletado.*/
			Aux->prox = L->prox;
			
			/* Se o elemento que está sendo deletado for o último elemento da lista, fazer com que o ponteiro ult da lista aponte para o elemento anterior, no caso Aux.*/
			if(L == lista->ult) {
				lista->ult = Aux;
			}
			
			/* Libera o elemento que foi deletado */
			free(L);
			
			/* Diminui o tamanho da lista */
			lista->tamLista--;
		}
		
	}// fim do else
	
	return pos;
}

void gerarJogos(T_Lista * lista, T_campeonato * jogos) {
	/* Tem-se uma lista de times, vamos criar dois ponteiros do tipo tipoCaixa, um que irá apontar para o time principal e outro que apontará para o time adversário */
	pontCaixa timeCasa, timeVisitante;
	
	pontCaixaJogo Aux; //Esse ponteiro auxiliará na criação dos jogos;
	
	/* Agora faremos o ponteiro timeCasa apontar para a cabeça da lista */
	timeCasa = lista->prim;
	
	/* Aqui vamos começar a definir os jogos */
	
	/* Enquanto o timeCasa->prox não estiver apontando para um elemento vazio da lista vai gerar jogos */
	while(timeCasa->prox != NULL) {
		/* O ponteiro time visitante vai apontar para o primeiro elemento após o timeCasa. Esse ponteiro vai andar pela lista e enquanto não percorrer toda lista, haverá atribuição de jogos contra o time da casa */
		timeVisitante = timeCasa->prox;
		
		while(timeVisitante != lista->ult) {
			/* Aqui ocorrerá a efetiva criação dos jogos */
			
			/* Primeiramente criaremos uma caixa de jogos que irá receber o jogo em questão */
			Aux = (T_caixaJogo *)malloc(sizeof(T_caixaJogo));
			
			/* Vamos fazer com que o Aux->prox aponte para NULL*/
			Aux->prox = NULL;
			
			/* Agora vamos preencher o conteúdo dessa caixa*/
			strcpy(Aux->jogo.time1, timeCasa->prox->time.nome);
			Aux->jogo.golsTime1 = 0;
			strcpy(Aux->jogo.time2, timeVisitante->prox->time.nome);
			Aux->jogo.golsTime2 = 0;
			Aux->jogo.jogou = false;
			
			/* Com o conteúdo preenchido vamos fazer com que a nova caixa entre no campeonato */
			/* Fazemos com que a última posição do campeonato atual, aponte para a nova caixa de jogos*/
			jogos->ult->prox = Aux;
			
			/* Fazemos que o ponteiro ult aponte para o último elemento do campeonato */
			jogos->ult = Aux;
			
			/* Almentamos a quantidade de jogos atribuídos no campeonato */
			jogos->tamCampeonato++;
			
			/* Apontamos o próximo time visitante */
			timeVisitante = timeVisitante->prox;
		
		} //Fim do laço While;
		
		/* Finalizou a atribuição dos jogos, o time da casa aponta para o próximo elemento da lista */
		timeCasa = timeCasa->prox;
		
	} //Fim do laço While;
	
}

void listarResultados(T_campeonato * jogos) {
	
	/* Essa função vai listar todos os jogos disponíveis no campeonato e os respectivos resultados. */
	
	/* Cria-se um auxiliar que vai apontar para a cabeça da lista */
	pontCaixaJogo Aux = jogos->prim;
	
	int i = 1;
	
	/* Enquanto o próximo elemento da lista de jogos não for nulo, apresentar o proximo jogo da lista*/
	while(Aux->prox != NULL) {
		
		/* Se o jogo não tiver sido jogado, apresentar somente o nome dos times que irão jogar */
		if(Aux->prox->jogo.jogou == false) {
			printf("%d: %s x %s \n", i, Aux->prox->jogo.time1, Aux->prox->jogo.time2);
		}
		/* Se o jogo já tiver sido jogado, mostrar os nomes dos times e o resultado do jogo */
		else printf("%d: %s %d X %d %s\n", i, Aux->prox->jogo.time1, Aux->prox->jogo.golsTime1, Aux->prox->jogo.golsTime2, Aux->prox->jogo.time2);
		
		/* Faz com que o ponteiro auxiliar aponte para o próximo elemento */
		Aux = Aux->prox;
		
		/* Incrementa a variável contadora */
		i++;
		
	}
	
}

void atribuiResultado(pontCaixa L, pontCaixa M, pontCaixaJogo Aux) {
	
	/* Incrementa os gols feitos e levados pelo time */
	L->prox->time.GolsPro += Aux->prox->jogo.golsTime1;
	L->prox->time.GolsContra += Aux->prox->jogo.golsTime2;
	
	M->prox->time.GolsPro += Aux->prox->jogo.golsTime2;
	M->prox->time.GolsContra += Aux->prox->jogo.golsTime1;
	
	/* Calcula o novo saldo de Gols */
	L->prox->time.Saldo = L->prox->time.GolsPro - L->prox->time.GolsContra;
	M->prox->time.Saldo = M->prox->time.GolsPro - M->prox->time.GolsContra;
	
	/* Em caso de vitória do time 1 */
	if(Aux->prox->jogo.golsTime1 > Aux->prox->jogo.golsTime2) {
		L->prox->time.qJogos++;
		L->prox->time.qVitorias++;
		L->prox->time.Pontos = L->prox->time.qVitorias * 3 + L->prox->time.qEmpates;
		M->prox->time.qJogos++;
		M->prox->time.qDerrotas++;
		M->prox->time.Pontos = M->prox->time.qVitorias * 3 + M->prox->time.qEmpates;
	}
	/* Em caso de vitória do time 2 */
	else if(Aux->prox->jogo.golsTime1 < Aux->prox->jogo.golsTime2) {
		M->prox->time.qJogos++;
		M->prox->time.qVitorias++;
		M->prox->time.Pontos = M->prox->time.qVitorias * 3 + M->prox->time.qEmpates;
		L->prox->time.qJogos++;
		L->prox->time.qDerrotas++;
		L->prox->time.Pontos = L->prox->time.qVitorias * 3 + L->prox->time.qEmpates;
	}
	/* Em caso de empate */
	else {
		L->prox->time.qJogos++;
		L->prox->time.qEmpates++;
		L->prox->time.Pontos = L->prox->time.qVitorias * 3 + L->prox->time.qEmpates;
		M->prox->time.qJogos++;
		M->prox->time.qEmpates++;
		M->prox->time.Pontos = M->prox->time.qVitorias * 3 + M->prox->time.qEmpates;
	}
}

void trocarPosicao(pontCaixa Aux, pontCaixa L) {
	/* Aqui ocorre a troca de posição dos times */
	
	/*Cria-se variáveis de ponteiro de caixa auxiliares para não mexer na posição das variáveis Aux e L na função principal. */
	pontCaixa temp = L->prox, tempAux = Aux, tempL = L;
	
	tempAux->prox->prox = tempL->prox->prox;
	temp->prox = tempAux->prox;
	tempAux->prox = temp;
	
}
void ordenarClassificacao(T_Lista * lista) {
	
	/* Cria dois ponteiros auxiliares para validar informações dos times */ 
	pontCaixa Aux, L;
	
	/* Variável contadora que controlará o laço for*/
	int i = 0 , j = 0;
	
	while( i < lista->tamLista ) {
		
		/* O ponteiro Aux aponta para a cabeça da lista */
		Aux = lista->prim;
		
		/* O ponteiro L aponta para o proximo elemento da lista depois da cabeça */
		L = Aux->prox;
		
		while ( L->prox != NULL && j < lista->tamLista ) {
		
			/* Prioridade de pontos */
			if(L->prox->time.Pontos > Aux->prox->time.Pontos) {
				trocarPosicao(Aux, L);
			}
			/* Mesma quantidade de pontos */
			if(Aux->prox->time.Pontos == L->prox->time.Pontos) {
				/* Quem tem mais jogos tem prioridade*/
				if(L->prox->time.qJogos > Aux->prox->time.qJogos) {
					trocarPosicao(Aux, L);
				}
				/* Tem a mesma quantidade de jogos */
				if(Aux->prox->time.qJogos == L->prox->time.qJogos) {
					/* Maior quantidade de vítórias */
					if(L->prox->time.qVitorias > Aux->prox->time.qVitorias) {
						trocarPosicao(Aux, L);
					}
					/* Mesma quantidade de vitórias */
					if(Aux->prox->time.qVitorias == L->prox->time.qVitorias) {
						/* Melhor saldo de Gols */
						if(L->prox->time.Saldo > Aux->prox->time.Saldo) {
							trocarPosicao(Aux, L);
						}
						/* Mesmo Saldo de Gols */
						if(Aux->prox->time.Saldo == L->prox->time.Saldo) {
							/* Valida quem fez mais gols */
							if(L->prox->time.GolsPro > Aux->prox->time.GolsPro) {
								trocarPosicao(Aux, L);
							}
						}
					}
				}
			}
			j++;
			Aux = Aux->prox;
			L = L->prox;
		}
		i++;
	}
}

void jogarJogo(T_campeonato *jogos, T_Lista *lista, int pos) {
	
	/* Criar uma variável contadora que vai encontrar o jogo na lista */
	int i = 1;
	
	/* Cria-se um ponteiro para os jogos que vai percorrer a lista. Coloca ele inicialmente na cabeça da lista */
	pontCaixaJogo Aux = jogos->prim;
	
	/* Ponteiro para apontar para os times da lista de jogos. Inicialmente aponta para a cabeça da lista */
	pontCaixa L = lista->prim,  M = lista->prim;
	
	/* Enquanto o ponteiro prox da caixa apontado pelo ponteiro Aux for diferente de NULL, continuar percorrendo */
	while(Aux->prox != NULL && i < pos) {
		Aux = Aux->prox;
		i++;
	}
	
	/* Se o ponteiro prox da caixa apontada por Aux for NULL ou o jogo apontado pelo ponteiro Aux já tiver sido jogado */
	if(Aux->prox == NULL || Aux->prox->jogo.jogou == true) {
		printf("O jogo que você deseja atribuir resultado, ou não existe ou já foi jogado\n\n");
	}
	/* Se não atribui resultados para o jogo */
	else {
		/* Digita os resultados */
		printf("Digite o resultado do jogo\n\n");
		do {
			printf("%s: ", Aux->prox->jogo.time1);
			scanf("%d", &Aux->prox->jogo.golsTime1);
			if(Aux->prox->jogo.golsTime1 < 0) printf("Não pode atribuir valores negativos\n");
		}while(Aux->prox->jogo.golsTime1 < 0);
		do {
			printf("%s: ", Aux->prox->jogo.time2);
			scanf("%d", &Aux->prox->jogo.golsTime2);
			if(Aux->prox->jogo.golsTime2 < 0) printf("Não pode atribuir valores negativos\n");
		}while(Aux->prox->jogo.golsTime2 < 0);
		
		/* Informa que o jogo foi jogado */
		Aux->prox->jogo.jogou = true;
		
		/* Agora atribui os resultados aos times da lista */
		/* Primeiramente faz L apontar para o Time 1*/
		while(L->prox != NULL && strcmp(L->prox->time.nome, Aux->prox->jogo.time1) != 0) {
			L = L->prox;
		}
		while(L->prox != NULL && strcmp(M->prox->time.nome, Aux->prox->jogo.time2) != 0) {
			M = M->prox;
		}
		
		atribuiResultado(L, M, Aux);
		
		ordenarClassificacao(lista);
		
	}
}

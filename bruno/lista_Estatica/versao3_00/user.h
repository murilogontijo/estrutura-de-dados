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

T_time criarNovoTime(T_Lista * lista) {
	
	/* Novo objeto que será criado do tipo time*/
	T_time novoTime;
	
	/* Variáveis validadoras */ 
	int validador = false, val = false;
	
	/* Nome da equipe */
	String nome;
	
	/*Cria um ponteiro auxiliar do tipo Caixas */
	pontCaixa Aux;
	
	/* Diga o nome do novo time. Enquanto o nome existir na lista, continuar pedindo novos nomes.*/
	do {
		/* Solicita o nome ao usuário */
		printf("Digite o nome do novo time: ");
		getchar();
		fgets(nome, TAM, stdin);
		
		/* Faz com que o ponteiro Aux aponte para a cabeça da lista*/
		Aux = lista->prim;
		val = false;
		
		/* Enquanto o validador 'Val' for igual a false e o ponteiro prox do 'Aux' não apontar para NULL, continuar verificando*/
		while(val == false && Aux->prox != NULL) {
			
			/* Se o nome da nova equipe for diferente oo nome da próxima equipe da lista, fazer com que Aux aponte para o próximo elemento */
			if(strcmp(nome, Aux->prox->time.nome) != 0) Aux = Aux->prox;
			
			/* Senão informe que o próximo time já tem o mesmo nome da nova equipe e termine o laço de verificação.*/
			else {
				printf("Time já existe\n\n");
				val = true;
			}
		}// Fim do laço While
		
		/* Se, ao final do laço o ponteiro prox de 'Aux' estiver apontando para NULL, quer dizer que o novo time não está na lista
		 * Mude o validador para true para terminar o ciclo de solicitação do nome da equipe*/
		if(Aux->prox == NULL) validador = true;
		
	}while(validador == false);
	
	/* Aqui faz a montagem to time*/
	strcpy(novoTime.nome, nome);
	novoTime.qJogos = 0;
	novoTime.qVitorias = 0;
	novoTime.qEmpates = 0;
	novoTime.qDerrotas = 0;
	novoTime.Pontos = 3* novoTime.qVitorias + novoTime.qEmpates;
	novoTime.GolsPro = 0;
	novoTime.GolsContra = 0;
	novoTime.Saldo = novoTime.GolsPro - novoTime.GolsContra;
	
	/* A função retorna o novo time criado*/
	return novoTime;
}

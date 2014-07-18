//Funções do sistema//
int calculaHash(int dia, int horario) {
	/** Testada e homologada */
	/*Essa função calcula o hash de um evento. Esse hash servirá para buscar os eventos de uma maneira mais simmplificada. */
	return dia*10 + horario;
}

void desmembraHash(int idEvento, int * dia, int * hora) {
	/** Testada e homologada */
	
	int i = 0;
	
	while(idEvento % 10 != 0) {
		idEvento--;
		i++;
	}
	*hora = i;
	*dia = idEvento / 10;
}

void criarMesDeEventos(T_calendario * cronograma) {
	/** Testada e homologada */
	
	// Cria a lista para eventos do mês
	int i, j; //variável contadora
	
	cronograma->eventosTotais = DIAS * QAPRES; //seta a quantidade de eventos já disponibilizados
	
	for(i = 0; i < DIAS; i++) {
		cronograma->datas[i].totalApresentacao = QAPRES; //seta que a cada dia não tem apresentações;
		for(j = 0; j < QAPRES; j++) {
			cronograma->datas[i].totalApresentacao = QAPRES;
			cronograma->datas[i].apresentacao[j].horario = false;
			cronograma->datas[i].apresentacao[j].hash = false;
		}
	}
}

int inserirEvento(T_calendario * cronograma, String nomeEvento, int dia , int hora) {
	/** Testada e homologada */
	/*Essa função fará a inserção de um evento no cronograma do teatro*/
	
	int i, j, k;
	
	if(cronograma->eventosTotais == 0) {
		printf("Não é possível inserir eventos. Cronograma lotado!\n\n");
		getchar();
		travatela();
		return false;
	}
	else if (cronograma->datas[dia].totalApresentacao == 0) {
		printf("Essa data possui todos os horários ocupados. Selecione outra data\n\n.");
		getchar();
		travatela();
		return false;
		
	}
	else if(cronograma->datas[dia].apresentacao[hora].horario == true) {
		printf("Esse horário já está ocupado por outra apresentação\n\n");
		getchar();
		travatela();
		return false;
	}
	else {
		cronograma->datas[dia].apresentacao[hora].horario = hora;
		strcpy(cronograma->datas[dia].apresentacao[hora].nome, nomeEvento);
		cronograma->datas[dia].apresentacao[hora].publico.qLugaresPossiveis = 2 * LATERAL * VERTICAL;
		cronograma->datas[dia].apresentacao[hora].hash = calculaHash(dia, hora);
		cronograma->eventosTotais--;
		cronograma->datas[dia].totalApresentacao--;
		printf("Evento cadastrado\n");
	}

	
	/*Hora de definir os preços das cadeiras do espetaculo. Por via de regra, as 5 primeiras fileira perto do palco terão preços maiores, devido à proximidade do palco. As cadeiras medianas terão preços normais, e as 10 últimas fileiras terão preços especiais*/
	
	i = cronograma->datas[dia].apresentacao[hora].publico.qLugaresPossiveis;
	j = 0;
	
	while(i > 0) {
		while(j < 5) {
			for(k = 0; k < LATERAL; k++) {
				cronograma->datas[dia].apresentacao[hora].publico.blocoEsquerda[j][k].preco = PRECOMAX;
				cronograma->datas[dia].apresentacao[hora].publico.blocoEsquerda[j][k].vendido = -1;
				i--; //tratou um lugar;
				cronograma->datas[dia].apresentacao[hora].publico.blocoDireita[j][k].preco = PRECOMAX;
				cronograma->datas[dia].apresentacao[hora].publico.blocoDireita[j][k].vendido = -1;
				i--; //tratou um lugar;
			}
			j++;
		}
		while(j < 33) {
			for(k = 0; k < LATERAL; k++) {
				cronograma->datas[dia].apresentacao[hora].publico.blocoEsquerda[j][k].preco = PRECONORMAL;
				cronograma->datas[dia].apresentacao[hora].publico.blocoEsquerda[j][k].vendido = -1;
				i--; //tratou um lugar;
				cronograma->datas[dia].apresentacao[hora].publico.blocoDireita[j][k].preco = PRECONORMAL;
				cronograma->datas[dia].apresentacao[hora].publico.blocoDireita[j][k].vendido = -1;
				i--; //tratou um lugar;
			}
			j++;
		}
		while(j < VERTICAL) {
			for(k = 0; k < LATERAL; k++) {
				cronograma->datas[dia].apresentacao[hora].publico.blocoEsquerda[j][k].preco = PRECOMIN;
				cronograma->datas[dia].apresentacao[hora].publico.blocoEsquerda[j][k].vendido = -1;
				i--; //tratou um lugar;
				cronograma->datas[dia].apresentacao[hora].publico.blocoDireita[j][k].preco = PRECOMIN;
				cronograma->datas[dia].apresentacao[hora].publico.blocoDireita[j][k].vendido = -1;
				i--; //tratou um lugar;
			}
			j++;
		}
	}
	return true;
}

int venderIngresso (T_calendario * cronograma, String cliente, int idEvento) {
	/*Essa função auxilia na venda de um ingresso de evento para um cliente
	* Requisitos: recebe o nome do cliente e o dia e horário do evento; */
	int op;
	int validador = false;
	int vert;
	int lat;
	int dia = 0, hora = 0;
	
	desmembraHash(idEvento, &dia, &hora);
	
	if(cronograma->datas[dia].apresentacao[hora].horario == false) {
		printf("Evento não está disponível\n\n");
		return false;
	}
		
	do {
		do {
			printf("Escolha que lado você deseja sentar!\n\n");
			printf("Digite 1:\tLado esquerdo\n");
			printf("Digite 2:\tLado direito\n");
			printf("Digite a opção desejada: ");
			scanf("%d", &op);
			if(op > 2 || op < 1) printf("Opção inválida. Digite uma opção válida\n\n");
		}while(op > 2 || op < 1);
		
		do {
			printf("Digite a fileira que você deseja sentar (1 ~ %d): ", VERTICAL);
			scanf("%d", &vert);
			if(vert > VERTICAL && vert < 0) printf("Não existe cadeiras disponível nessa posição\n");
		}while(vert > VERTICAL && vert < 0);
		
		vert--; //Esse decremento ocorre porque a posição apontada pelo usuário não é a mesma do programa;
		
		do{
			printf("Digite qual posição da fileira você deseja sentar (1 ~ %d): ", (LATERAL-1));
			scanf("%d", &lat);
			if(lat < 1 || lat > (LATERAL - 1)) printf("Não existe cadeiras disponível nessa posição");
		}while(lat < 1 || lat > (LATERAL - 1));
				
		if(op == 1 && cronograma->datas[dia].apresentacao[hora].publico.blocoEsquerda[vert][lat].vendido == true) {
			printf("Local já ocupado\n");
		}
		else if (op == 2 && cronograma->datas[dia].apresentacao[hora].publico.blocoDireita[vert][lat].vendido == true) {
			printf("Local já ocupado\n");
		}
		else if (op == 1) {
			printf("O preço do local é R$ %.2f\n", cronograma->datas[dia].apresentacao[hora].publico.blocoEsquerda[vert][lat].preco);
			strcpy(cronograma->datas[dia].apresentacao[hora].publico.blocoEsquerda[vert][lat].cliente, cliente);
			cronograma->datas[dia].apresentacao[hora].publico.blocoEsquerda[vert][lat].vendido = (10000 + vert*100 + lat);
			// cronograma->datas[dia].apresentacao[hora].publico.blocoEsquerda[vert][lat].hashCliente = (10000 + vert*100 + lat);  Retirando hashCliente
			cronograma->datas[dia].apresentacao[hora].publico.qLugaresPossiveis--;
			validador = true;
			printf("Ingresso vendido\n");
		}
		else {
			printf("O preço do local é R$ %.2f\n", cronograma->datas[dia].apresentacao[hora].publico.blocoDireita[vert][lat].preco);
			strcpy(cronograma->datas[dia].apresentacao[hora].publico.blocoDireita[vert][lat].cliente, cliente);
			cronograma->datas[dia].apresentacao[hora].publico.blocoDireita[vert][lat].vendido = (20000 + vert*100 + lat);
			// cronograma->datas[dia].apresentacao[hora].publico.blocoDireita[vert][lat].hashCliente = (20000 + vert*100 + lat); Retirando hashCliente
			cronograma->datas[dia].apresentacao[hora].publico.qLugaresPossiveis--;
			validador = true;
			printf("Ingresso vendido\n");
		}
	}while(validador == false);
		
	return true;
}

void excluirEvento(T_calendario * cronograma, int idEvento) {
	/* Função responsável por excluir um evento do cronograma.
	 * A função recebe o nome do evento e deleta ele da lista*/
	int dia = 0, hora = 0;
	
	desmembraHash(idEvento, &dia, &hora); 
	
	if(cronograma->datas[dia].apresentacao[hora].horario != false) {
		cronograma->datas[dia].apresentacao[hora].horario = false;
		cronograma->datas[dia].apresentacao[hora].hash = false;
		strcpy(cronograma->datas[dia].apresentacao[hora].nome, "ANULADO");
		printf("Evento deletado\n\n");
	}
	else printf("Não existe código informado\n\n");
}

int devolverIngresso(T_calendario * cronograma, int idEvento) {
	
	int dia = 0, hora = 0;
	int codigo, lateral = 0, vertical = 1;
	
	desmembraHash(idEvento, &dia, &hora);
	
	if(cronograma->datas[dia].apresentacao[hora].horario == false) {
		printf("Não existe evento nessa data e horário\n\n");
		return false;
	}
	
	vizualizacaoPlateia(cronograma, idEvento);
	
	printf("Digite o codigo do cliente que deseja devolver o ingresso: ");
	scanf("%d", &codigo);
	
	if(codigo >= 20000) {
		
		while(codigo % 100 != 0) {
			codigo--;
			vertical++;
		}
		lateral = (codigo - 20000) / 100;
		
		if(cronograma->datas[dia].apresentacao[hora].publico.blocoDireita[vertical][lateral].vendido != -1) {
			cronograma->datas[dia].apresentacao[hora].publico.blocoDireita[vertical][lateral].vendido = -1;
			printf("Ingresso devolvido\n\n");
			return true;
		}
	}
	
	else {
		while(codigo % 100 != 0) {
			codigo--;
			vertical++;
		}
		lateral = (codigo - 10000) / 100;
		
		if(cronograma->datas[dia].apresentacao[hora].publico.blocoEsquerda[vertical][lateral].vendido != -1) {
			cronograma->datas[dia].apresentacao[hora].publico.blocoEsquerda[vertical][lateral].vendido = -1;
			printf("Ingresso devolvido\n\n");
			return true;
		}
	}
	
	printf("Ingresso não devolvido\n\n");
	return false;
}

void visualizarEventos(T_calendario * cronograma) {
	/*Essa função mostra todos os eventos em seus respectivos dias e horários */
	
	int i, j;
	
	for(i = 0; i < DIAS; i++) {
		for(j = 0; j < QAPRES; j++) {
			if(cronograma->datas[i].apresentacao[j].horario != false) {
				printf("Código %d: Espetaculo \"%s\". Dia %d das %s. Temos %d ingressos disponíveis para venda\n\n", cronograma->datas[i].apresentacao[j].hash, cronograma->datas[i].apresentacao[j].nome, i, (j == apres1-1 ? "09:00 às 11:30" : (j == apres2-1 ? "13:00 às 15:30" : (j == apres3-1 ? "16:00 às 18:30" : (j == apres4-1 ? "19:30 às 22:00" : "22:30 às 01:00")))), cronograma->datas[i].apresentacao[j].publico.qLugaresPossiveis > (4 * VERTICAL) ? cronograma->datas[i].apresentacao[j].publico.qLugaresPossiveis - (4 * VERTICAL) : cronograma->datas[i].apresentacao[j].publico.qLugaresPossiveis);
			}
		}
	}
}

void venderIngressoAdicional(T_calendario * cronograma, String cliente, int idEvento) {
	/*Essa função aciona a venda de ingressos adicionais (as cadeiras que ficam nos corredores centrais e laterais das plateias) */
	
	char op, op2; //variáveis de seleção
	int i; //variáveis contadoras
	int dia = 0, hora = 0;
	
	desmembraHash(idEvento, &dia, &hora);
	
	do {
		printf("\n\nDigite o bloco que vocẽ deseja sentar (D [direita] / E [esquerda]): ");
		scanf("%s", &op);
		if(op != 'd' && op != 'D' && op != 'e' && op != 'E') printf("Opção inválida!");
	}while(op != 'd' && op != 'D' && op != 'e' && op != 'E');
	
	do{
		printf("Digite o corredor que você deseja (L [lateral] / C [central]): ");
		scanf("%s", &op2);
		if(op2 != 'l' && op2 != 'L' && op2 != 'c' && op2 != 'C') printf("Opção inválida!");
	}while(op2 != 'l' && op2 != 'L' && op2 != 'c' && op2 != 'C');
	
	if((op == 'd' || op == 'D') && (op2 == 'c' || op2 == 'C')) {
		for(i = 0; i < VERTICAL; i++) {
			printf("Cadeira: %d\nStatus: %s\n\n",(i +1) , cronograma->datas[dia].apresentacao[hora].publico.blocoDireita[0][i].vendido != -1 ? "Ocupado" : "Disponível");
		}
	}
	else if((op == 'd' || op == 'D') && (op2 == 'l' || op2 == 'L')) {
		for(i = 0; i < VERTICAL; i++) {
			printf("Cadeira: %d\nStatus: %s\n\n",(i +1) , cronograma->datas[dia].apresentacao[hora].publico.blocoDireita[LATERAL-1][i].vendido != -1 ? "Ocupado" : "Disponível");
		}
	}
	else if((op == 'e' || op == 'E') && (op2 == 'c' || op2 == 'C')) {
		for(i = 0; i < VERTICAL; i++) {
			printf("Cadeira: %d\nStatus: %s\n\n",(i +1) , cronograma->datas[dia].apresentacao[hora].publico.blocoEsquerda[LATERAL-1][i].vendido != -1  ? "Ocupado" : "Disponível");
		}
	}
	else if((op == 'e' || op == 'E') && (op2 == 'l' || op2 == 'L')) {
		for(i = 0; i < VERTICAL; i++) {
			printf("Cadeira: %d\nStatus: %s\n\n",(i +1) , cronograma->datas[dia].apresentacao[hora].publico.blocoEsquerda[0][i].vendido != -1 ? "Ocupado" : "Disponível");
		}
	}
}

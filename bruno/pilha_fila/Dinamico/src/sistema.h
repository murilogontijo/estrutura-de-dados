void criarFilaVazia(T_fila * fila) { // testada e funcional
	/* Função responsável por criar uma fila de atendimento vazia */
	
	/* Aloca um espaço na memória para criar a cabeça da fila */
	fila->prim = (T_caixa *)malloc(sizeof(T_caixa));
	
	/* Faz com que o ponteiro prox da cabeça da lista aponte para NULL */
	fila->prim->prox = NULL;
	
	/* Faz com que o ponteiro ult aponte para a cabeça da lista*/
	fila->ult = fila->prim;
}

int validarFilaVazia(T_fila * fila) { //testada e funcional 
	/* Função para validar se a fila está vazia */
	
	/* Se estiver vazia retorna true */
	if(fila->prim->prox == NULL) return true;
	/* Se não retorna false */
	else return false;
}

void receberClienteNormal(T_fila * fila, T_cliente pessoa) {
	/* Função responsável por inserir um cliente normal na fila de atendimento bancário */
	
	/* Cria um ponteiro de caixa para o novo elemento*/
	pontCaixa new; // new apontará o novo elemento
	
	/* Aloca um espaço na memória para o novo elemento */
	new = (T_caixa *)malloc(sizeof(T_caixa));
	
	/* O elemento da nova caixa recebe o cliente que será recepcionado */
	new->elemento = pessoa;
	
	/* Como se trata de uma fila, o elemento sempre entrará na última posição da fila. Assim sendo, seu ponteiro prox aponta para NULL */
	new->prox = NULL;
	
	/* Faz o ponteiro prox do ultimo elemento da fila apontar para o novo elemento da fila */
	fila->ult->prox = new;
	
	/* Faz com que o ponteiro ult aponte para o novo último elemento da fila */
	fila->ult = new;
	
}

void empilharElemento(T_fila * fila, T_cliente elemento) {
	/* Função responsával por empilhar um elemento na estrutura*/
	 
	/* Cria um ponteiro de caixa para alocar o novo elemento e cria a caixa */
	pontCaixa new = (T_caixa *)malloc(sizeof(T_caixa));
	
	/* Insere o novo cliente no conteúdo da caixa */
	new->elemento = elemento;
	
	/* Faz com que o ponteiro prox da nova caixa aponte para o elemento apontado pela ponteiro prox da cabeça da pilha */
	new->prox = fila->prim->prox;
	/* Faz com que a cabeça da pilha aponte para o novo elemento */
	fila->prim->prox = new;
	
	/* Mesmo sendo tratado como uma pilha, a estrutura define uma fila dinâmica. Assim, quando insere um elemento na pseudo pilha, se o ponteiro ult estiver apontando para a cabeça, ele deverá apontar o novo último elemento. Isso para não perder o registro de onde acaba a fila*/
	if(fila->prim == fila->ult) fila->ult = new;
	
}

void desempilharElemento(T_fila * fila, T_cliente * cliente) {
	
	/* Função responsáve por retirar um elemento da fila */
	
	/* Ponteiro Auxiliar para ajudar a exclusão do elemento */
	pontCaixa Aux = fila->prim->prox;
	
	/* Fazemos com que o elemento que será retirado seja colocado na variável cliente */
	*cliente = fila->prim->prox->elemento;
	
	/* Fazemos com que a cabeça aponte para o proximo elemento da fila */
	fila->prim->prox = fila->prim->prox->prox;
	
	/* Se o elemento que estiver sendo deletado for também o último elemento da fila, faz o ponteiro ult apontar para a cabeça */
	if(Aux == fila->ult) fila->ult = fila->prim;
	
	/* Libera o espaço de memória apontado por Aux */
	free(Aux);
}

void receberClientePreferencial(T_fila * fila, T_cliente pessoa) {
	/* Função responsável por alocar um cliente preferencial na fila */
	
	/* Cria uma fila auxiliar para reordenação dos elementos */
	T_fila filaAux;
	
	/* Cria um tipo de dado cliente para auxiliar a reordenação dos elementos */
	T_cliente clienteAux;
	
	/* Criamos a pilha Auxiliar Vazia */
	criarFilaVazia(&filaAux);
	
	/* Enquanto o primeiro elemento da fila for preferencial, retire-o da fila e coloque-o em uma pilha auxiliar */
	while(fila->prim->prox != NULL && fila->prim->prox->elemento.idade > 60) {
		desempilharElemento(fila, &clienteAux);
		empilharElemento(&filaAux, clienteAux);
	}
	
	/*O proximo elemento da fila não é preferencial, então novo cliente entra na frente dele */
	empilharElemento(fila, pessoa);
	
	/* Feito o empilhamento do elemento, retorna os elementos da pilha auxiliar para a pilha principal *
	 * Enquanto o ponteiro prox de filaAux não estiver apontando para NULL, continuar incluindo elementos
	 * */
	while(filaAux.prim->prox != NULL) {
		desempilharElemento(&filaAux, &clienteAux);
		empilharElemento(fila, clienteAux);
	}
}

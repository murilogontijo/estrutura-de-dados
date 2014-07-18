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

void visualizarFila(T_fila * fila) {
	/* Função responsável por visualizar todos os elementos da fila */
	
	/* Cria um ponteiro de caixa e faz ele apontar para o primeiro elemento da fila */
	pontCaixa Aux = fila->prim;
	
	while(Aux->prox != NULL) {
		/* Imprime o proximo elemento da fila */
		printf("Cliente: %s", Aux->prox->elemento.nome);
		printf("Idade: %d ", Aux->prox->elemento.idade);
		printf("Senha: %d", Aux->prox->elemento.senha);
		printf("\n\n");
		
		/* Aponta para o próximo cliente */
		Aux = Aux->prox;
	}
}

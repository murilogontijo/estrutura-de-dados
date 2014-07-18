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

void listarProdutos(T_listaProdutos * Estoque) {
	
	pontCaixaProduto Aux = Estoque->prim;
	
	while(Aux->prox != NULL) {
		printf("Produto %sCodigo de Barras: %d\nPreço de compra: R$ %.2f\nPreço de Venda: R$ %.2f\nQuantidade: %d\n\n", Aux->prox->produto.nomeProduto, Aux->prox->produto.codBarras, Aux->prox->produto.precoUnitarioCompra, Aux->prox->produto.precoUnitarioVenda, Aux->prox->produto.quantidade);
		Aux = Aux->prox;
	}
	
}

void listarClientes(T_listaClientes * Clientes) {
	pontCaixaCliente Aux;
	
	Aux = Clientes->prim;
	
	while(Aux->prox != NULL) {
		printf("Cliente = %sCartao = %d\nSaldo = %.2f\n\n", Aux->prox->conteudo.nome, Aux->prox->conteudo.numCartao, Aux->prox->conteudo.saldo);
		Aux = Aux->prox;
	}
}

int procurarCliente(T_listaClientes * Clientes, T_cliente cliente) {
	
	pontCaixaCliente Aux;
	Aux = Clientes->prim;
	
	if(strcmp(cliente.nome, "vazio") != 0) {
		/* Percorre a lista */
		while(Aux->prox != NULL && strcmp(Aux->prox->conteudo.nome, cliente.nome) != 0) Aux = Aux->prox;
	}
	else if(cliente.numCartao != false) {
		/* Percorre a lista */
		while(Aux->prox != NULL && Aux->prox->conteudo.numCartao != cliente.numCartao) Aux = Aux->prox;
	}
	
	if (Aux->prox != NULL) {
		printf("Nome: %s\nCartao: %d\nSaldo Disponivel: %.2f\n", Aux->prox->conteudo.nome, Aux->prox->conteudo.numCartao, Aux->prox->conteudo.saldo);
		return true; //Encontrou cliente
	}
	else {
		printf("O cartão informado não existe cadastrado\n");
		return false; //Não encontrou cliente
	}
	
} // Fim da função procurar cliente

void createProduto(T_produto * produto) {
	
	float valor;
	
	printf("Digite o nome do novo produto: ");
	fgets(produto->nomeProduto, CAR, stdin);
	
	printf("Digite o valor de compra do produto: ");
	scanf("%f", &produto->precoUnitarioCompra);
	getchar(); //limpar o buffer
	
	printf("Digite o percentual de lucro sobre o produto: ");
	scanf("%f", &valor);
	getchar(); //limpar o buffer
	
	produto->precoUnitarioVenda = produto->precoUnitarioCompra + produto->precoUnitarioCompra * (valor/100);
	
}

int procurarProduto(T_listaProdutos * Estoque, int codProduto) {
	pontCaixaProduto Aux = Estoque->prim;
	
	while(Aux->prox != NULL && Aux->prox->produto.codBarras != codProduto) Aux = Aux->prox;
	
	if(Aux->prox == NULL) {
		return false;
	}
	else {
		printf("Produto %sCodigo de Barras: %d\nPreço de compra: R$ %.2f\nPreço de Venda: R$ %.2f\nQuantidade: %d\n\n", Aux->prox->produto.nomeProduto, Aux->prox->produto.codBarras, Aux->prox->produto.precoUnitarioCompra, Aux->prox->produto.precoUnitarioVenda, Aux->prox->produto.quantidade);
		return true;
	}
	
}

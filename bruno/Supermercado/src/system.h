
void criarListaClientes(T_listaClientes * Clientes) {
	pontCaixaCliente Aux;
	
	Aux = (T_caixaCliente *)malloc(sizeof(T_caixaCliente));
	Aux->prox = NULL;
	
	Clientes->prim = Aux;
	Clientes->ult = Aux;
	
	Clientes->qtdCliente = 0;
}// Fim da função criarListaClientes

int validarListaClienteVazia(T_listaClientes * Clientes) {
	if(Clientes->prim == Clientes->ult) return true;
	else return false;
}

void cadastrarNovoCliente(T_listaClientes * Clientes, T_cliente pessoa) {
	pontCaixaCliente new, Aux = Clientes->prim;
	
	new = (T_caixaCliente *)malloc(sizeof(T_caixaCliente));
	
	new->conteudo = pessoa;
	
	while(Aux->prox != NULL && Aux->prox->conteudo.numCartao < pessoa.numCartao) Aux = Aux->prox;
	
	new->prox = Aux->prox;
	
	Aux->prox = new;
	
	if(Clientes->ult == Aux) Clientes->ult = new;
	
	Clientes->qtdCliente++;
}

int excluirCliente(T_listaClientes * Clientes, T_cliente * pessoa) {
	pontCaixaCliente Aux = Clientes->prim, L;

	while(Aux->prox != NULL && Aux->prox->conteudo.numCartao != pessoa->numCartao) Aux = Aux->prox; //Percorre a lista
		
	if(Aux->prox == NULL) return false;
	else {
		L = Aux->prox;
		
		*pessoa = L->conteudo;
		
		Aux->prox = L->prox;
		
		if(L == Clientes->ult) Clientes->ult = Aux;
		
		free(L);
		L = NULL; //medidas de segurança
		
		Clientes->qtdCliente--;
		
		return true;
	}
}


/* ============================================= Gerenciamento de estoque ============================================= */

void criarListaProdutos(T_listaProdutos * Estoque) {
	pontCaixaProduto Aux;
	
	Aux = (T_caixaProduto *)malloc(sizeof(T_caixaProduto));
	
	Aux->prox = NULL;
	
	Estoque->prim = Aux;
	Estoque->ult = Aux;
	
	Estoque->qtdProdutos = 0;
}

int validarListaProdutosVazia(T_listaProdutos * Produtos) {
	if(Produtos->prim == Produtos->ult) return true;
	else return false;
}

void AdicionarMercadoriaEstoque(T_listaProdutos * Estoque, T_produto produto) {
	pontCaixaProduto new, Aux;
	
	if(procurarProduto(Estoque, produto.codBarras) ==  true) {
		Aux = Estoque->prim;
		
		while(Aux->prox->produto.codBarras != produto.codBarras) Aux = Aux->prox;
		
		Aux->prox->produto.quantidade += produto.quantidade;
		
	}
	else {
		
		Aux = Estoque->prim;
		new = (T_caixaProduto *)malloc(sizeof(T_caixaProduto));
		
		if(strcmp(produto.nomeProduto, "vazio") == 0) createProduto(&produto);
		
		new->produto = produto;
		
		while(Aux->prox != NULL && Aux->prox->produto.codBarras < produto.codBarras) Aux = Aux->prox;
		
		new->prox = Aux->prox;
		
		Aux->prox = new;
		
		if(Aux == Estoque->ult) Estoque->ult = new;
	}
	
}

int retirarProdutosEstoque(T_listaProdutos * Estoque, T_produto * produto) {
	
	pontCaixaProduto Aux, L;
	int temp;
	
	
	Aux = Estoque->prim;
	
	if(Estoque->prim == Estoque->ult) return false;
	
	else {
		while(Aux->prox != NULL && Aux->prox->produto.codBarras != produto->codBarras) Aux = Aux->prox;
	
		if(Aux->prox == NULL) return false; //Não encontrou o código de barras
		else {
			
			if(produto->quantidade == 0) {
				*produto = Aux->prox->produto;
				
				Aux->prox->produto.quantidade = 0;
			}
			else {
				if(Aux->prox->produto.quantidade < produto->quantidade) {
					printf("Não existe essa quantidade de mercadoria pra ser retirada\n");
					return false;
				}
				else {
					
					temp = produto->quantidade;
					Aux->prox->produto.quantidade -= produto->quantidade;
					
					*produto = Aux->prox->produto;
					
					produto->quantidade = temp;
					
				}
			}
			
			if(Aux->prox->produto.quantidade == 0) {
				L = Aux->prox;
				
				Aux->prox = L->prox;
				
				if(L == Estoque->ult) Estoque->ult = Aux;
				
				free(L);
				
				L = NULL;
			}
		}
	}
	
	return true;
}

void enfileiraProduto(T_listaProdutos * Compras , T_produto item) {
	
	pontCaixaProduto Aux, New;
	
	Aux = Compras->ult;
	
	New = (T_caixaProduto *)malloc(sizeof(T_caixaProduto));
	
	New->produto = item;
	
	New->prox = NULL;
	
	Aux->prox = New;
	
	Compras->ult = New;
	
}

int desinfileiraProduto(T_listaProdutos * Compras, T_produto * item) {
	pontCaixaProduto Aux, L;
	
	if(Compras->prim == Compras->ult) return false;
	else {
		
		Aux = Compras->prim;
		
		L = Aux->prox;
		
		*item = L->produto;
		
		Aux->prox = L->prox;
		
		if(Compras->ult == L) Compras->ult = Aux;
		
		free(L);
		
		L = NULL; 
		
	}
	
	return true;
}

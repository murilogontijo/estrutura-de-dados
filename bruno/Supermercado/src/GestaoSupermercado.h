int GestaoSupermercado(T_listaClientes * Clientes, T_listaProdutos * Estoque) {
	
	int op;
	int cont;
	float totalCompra;
	
	T_cliente cliente;
	T_produto produto;
	T_listaProdutos Compras;
	
	if(validarListaClienteVazia(Clientes) == true || validarListaProdutosVazia(Estoque) == true) {
		printf("Existem listas vazias. Gestão de supermercado não é possível de ser iniciada\n\n");
		travatela();
		return false;
	}
	
	do {
		
		system("clear");
		printf("Gestão de supermercado\n\n");
		
		printf("Digite 0:\tPara sair da Gestão do Supermercado\n");
		printf("Digite 1:\tSimular compra de cliente\n");
		printf("Digite a opção desejada: ");
		scanf("%d", &op);
		getchar(); //limpar buffer
		
		switch(op) {
			case 0:
				printf("Você está finalizando o sistema de gestão de Supermercado\n");
				travatela();
				break;
			
			case 1:
				system("clear");
				printf("Passar compra de cliente\n\n");
				
				printf("Digite o número do cartão do cliente: ");
				scanf("%d", &cliente.numCartao);
				getchar(); //limpar buffer
				strcpy(cliente.nome, "vazio"); // não iremos procurar por nome e sim pelo número do cartão
				
				if(procurarCliente(Clientes, cliente) == true) {
					
					excluirCliente(Clientes, &cliente);
					
					criarListaProdutos(&Compras);
					
					printf("Digite o código de barras do produto: ");
					scanf("%d", &produto.codBarras);
					getchar(); //limpar buffer
				
					while( produto.codBarras != 0 ) {
						
						printf("Digite a quantidade de produtos comprados: ");
						scanf("%d", &produto.quantidade);
						getchar(); //limpar buffer
				
						retirarProdutosEstoque(Estoque, &produto);
				
						if(cliente.saldo >= produto.precoUnitarioVenda * produto.quantidade) {
							enfileiraProduto(&Compras, produto);
							cliente.saldo -= produto.precoUnitarioVenda * produto.quantidade;
						}
						else {
							printf("Cliente não tem saldo para essa quantidade desse produto\n\n");
							AdicionarMercadoriaEstoque(Estoque, produto);
						}
						
						printf("Digite o código de barras do próximo produto: ");
						scanf("%d", &produto.codBarras);
						getchar(); //limpar buffer
						
					}
					
					cadastrarNovoCliente(Clientes, cliente);
					
					cont = 1;
					totalCompra = 0;
					
					while( validarListaProdutosVazia(&Compras) != true ) {
						
						desinfileiraProduto(&Compras, &produto);
						
						printf("%d: %sQtdd: %d, Pç. Unit: R$ %.2f, Total: R$ %.2f\n", cont, produto.nomeProduto, produto.quantidade, produto.precoUnitarioVenda, (produto.quantidade * produto.precoUnitarioVenda));
						
						totalCompra += produto.quantidade * produto.precoUnitarioVenda;
					}
					printf("Total da compra: R$ %.2f\n\n", totalCompra);
				}
				else {
					printf("Cliente não cadastrado na nossa base de clientes. Por favor, cadastre o cliente antes de passar a compra e recarregue seu saldo\n");
				}
				travatela();
				break;
				
			default:
				printf("Opção inválida");
				travatela();
				break;
		}
		
	}while(op != 0);
	
	return true;
}

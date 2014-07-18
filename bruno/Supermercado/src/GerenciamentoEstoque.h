void GerenciamentoEstoque(T_listaProdutos * Estoque) {
	
	int op;
	T_produto produto;
	
	do {
		system("clear");
		printf("Gerenciamento de estoque\n\n");
		printf("Digite 0:\tPara finalizar gerenciamento de estoque\n");
		printf("Digite 1:\tPara receber novo produto no estoque\n");
		printf("Digite 2:\tPara Buscar um Produto\n");
		printf("Digite 3:\tPara Atualizar informações de um produto\n");
		printf("Digite 4:\tPara Retirar um produto do estoque\n");
		printf("Digite 5:\tPara listar Produtos do estoque (temporário)\n");
		printf("Digite a opção desejada: ");
		scanf("%d", &op);
		getchar(); //Limpar buffer do teclado
		
		switch(op) {
			case 0:
				printf("\nVocê está finalizando o gerenciamento de estoque\n\n");
				if(telaConfirmacao() == true) travatela();
				else op = -1;
				break;
				
			case 1:
				system("clear");
				printf("Entrada de produto no estoque\n\n");
				
				printf("Digite o codigo de barras do produto que vocẽ deseja adicionar ao estoque (digite 1 para gerar um aleatório): ");
				scanf("%d", &produto.codBarras);
				getchar(); //limpar o buffer
				if(produto.codBarras == 1) produto.codBarras = rand();
				strcpy(produto.nomeProduto, "vazio");
				
				do{
					printf("Digite a quantidade de produtos que você irá adicionar ao estoque: ");
					scanf("%d", &produto.quantidade);
					getchar(); //limpar o buffer
					if(produto.quantidade < 0) printf("Quantidade inválida\n");
				}while(produto.quantidade < 0);
				
				AdicionarMercadoriaEstoque(Estoque, produto);
				
				travatela();
				break;
				
			case 2:
				system("clear");
				printf("Buscar produto\n\n");
				printf("Digite o código de barras do produto que você deseja buscar: ");
				scanf("%d", &op);
				getchar(); //limpar o buffer
				procurarProduto(Estoque, op);
				op = -1; //para o caso de aparecer um 0 por ai
				travatela();
				break;
				
			case 3:
				system("clear");
				printf("Atualizar informações de um produto\n\n");
				
				printf("Digite o código de barras do produto: ");
				scanf("%d", &produto.codBarras);
				getchar(); //limpar o buffer do teclado
				
				produto.quantidade = 0;
				
				retirarProdutosEstoque(Estoque, &produto);
				
				strcpy(produto.nomeProduto, "vazio");
				
				AdicionarMercadoriaEstoque(Estoque, produto);
				
				getchar(); //limpar o buffer do teclado
				
				travatela();
				break;
				
			case 4:
				system("clear");
				printf("Retirar um produto do estoque\n\n");
				
				printf("Digite o código de barras do produto: ");
				scanf("%d", &produto.codBarras);
				getchar(); //limpar o buffer
				
				do{
					printf("Digite a quantidade de produtos que você deseja retirar do estoque (digite 0 para retirar tudo):  ");
					scanf("%d", &produto.quantidade);
					getchar(); //limpar o buffer
					if(produto.quantidade < 0) printf("Quantidade inválida\n");
				}while(produto.quantidade < 0);
				
				retirarProdutosEstoque(Estoque, &produto);
				
				travatela();
				break;
				
			case 5:
				system("clear");
				printf("Listagem de produtos no estoque\n\n");
				listarProdutos(Estoque);
				travatela();
				break;
				
			default:
				printf("Opção inválida\n");
				travatela();
				break;
		}
		
	}while(op != 0);
	
}

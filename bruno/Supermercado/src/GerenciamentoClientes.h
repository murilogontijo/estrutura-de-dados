/* Sistema implementa principais funções da gerência de clientes 
 * Sistema contém menu com as principais funcionalidades para gerenciamento de clientes */

void GerenciamentoClientes(T_listaClientes * Clientes) {

	int op;
	float valor;
	T_cliente pessoa;
	
	do {
		system("clear");
		printf("Sistema de gerenciamento de clientes\n\n");
		printf("Digite 0:\tPara finalizar gerenciamento de clientes\n");
		printf("Digite 1:\tPara Cadastrar novo cliente\n");
		printf("Digite 2:\tPara Buscar um cliente\n");
		printf("Digite 3:\tPara Atualizar informações de um cliente\n");
		printf("Digite 4:\tPara Excluir um cliente\n");
		printf("Digite 5:\tPara consultar saldo disponível de um cliente\n");
		printf("Digite 6:\tPara carregar Cartão do cliente\n");
		printf("Digite 7:\tPara listar Clientes (temporário)\n");
		printf("Digite a opção desejada: ");
		scanf("%d", &op);
		
		getchar(); //Para limpar o buffer do teclado;
		
		switch(op) {
			case 0:
				printf("\n\nVocê está finalizando o gerenciamento de clientes\n\n");
				if(telaConfirmacao() == true) travatela();
				else op = -1;
				break;
			
			case 1:
				system("clear");
				printf("Cadastrar novo cliente\n\n");
				printf("Digite o nome do novo cliente: ");
				fgets(pessoa.nome, CAR, stdin);
				if(procurarCliente(Clientes, pessoa) == true) {
					printf("Já existe cliente cadastrado\n\n");
				}
				else {
					pessoa.saldo = 0;
					printf("Digite o número do novo cartão (digite 1 para gerar aleatório): ");
					scanf("%d", &pessoa.numCartao);
					getchar(); //limpar buffer
					if(pessoa.numCartao == 1) pessoa.numCartao = rand();
					cadastrarNovoCliente(Clientes, pessoa);
					printf("Novo cliente cadastrado\n");
				}
				travatela();
				break;
				
			case 2:
				system("clear");
				printf("Procurar um cliente\n\n");
				printf("Digite o número do cartão: ");
				scanf("%d", &pessoa.numCartao);
				getchar(); //Limpar o buffer do teclado
				strcpy(pessoa.nome, "vazio"); // não iremos procurar por nome e sim pelo número do cartão
				if(procurarCliente(Clientes, pessoa) == true) printf("\nCliente encontrado\n");
				travatela();
				break;
				
			case 3:
				system("clear");
				printf("Atualizar informação de um cliente\n\n");
				
				printf("Digite o número do cartão do cliente que você deseja editar: ");
				scanf("%d", &pessoa.numCartao);
				getchar(); //limpar o buffer do teclado
				strcpy(pessoa.nome, "vazio"); // não iremos procurar por nome e sim pelo número do cartão
				
				if(procurarCliente(Clientes, pessoa) == false) printf("O numero digitado está incorreto\n\n");
				else {
					excluirCliente(Clientes, &pessoa);
					printf("Digite o nome correto da pessoa: ");
					fgets(pessoa.nome, CAR, stdin);
					cadastrarNovoCliente(Clientes, pessoa);
				}
				
				travatela();
				break;
				
			case 4:
				system("clear");
				printf("Excluir um cliente\n\n");
				if(validarListaClienteVazia(Clientes) == true) {
					printf("Não tem clientes para serem procurados\n");
				}
				else {
					printf("Digite o número do cartão do cliente que você deseja excluir: ");
					scanf("%d", &pessoa.numCartao);
					getchar(); //limpar o buffer
					if(excluirCliente(Clientes, &pessoa) == false) printf("Não ocorreu exclusão de cliente!");
				}
				
				travatela();
				break;
			
			case 5:
				system("clear");
				printf("Consultar o saldo de um cliente\n\n");
				
				printf("Digite o número do cartão do cliente que você deseja consultar o saldo: ");
				scanf("%d", &pessoa.numCartao);
				getchar(); //Limpar o buffer do teclado
				strcpy(pessoa.nome, "vazio"); // não iremos procurar por nome e sim pelo número do cartão
				
				procurarCliente(Clientes, pessoa);
				
				travatela();
				break;
				
			case 6:
				system("clear");
				printf("Carregar cartão de cliente\n\n");
				
				printf("Digite o número do cartão do cliente que você deseja carregar: ");
				scanf("%d", &pessoa.numCartao);
				getchar(); //para limpar o buffer do teclado
				strcpy(pessoa.nome, "vazio"); // não iremos procurar por nome e sim pelo número do cartão
				
				if(excluirCliente(Clientes, &pessoa) == true) {
					do{
						printf("Digite o valor que você deseja adicionar no cartão: ");
						scanf("%f", &valor);
						getchar(); //para limpar o buffer do teclado
						if(valor <= 0) printf("Valor inválido\n");
					}while(valor <= 0);
					pessoa.saldo += valor;
					cadastrarNovoCliente(Clientes, pessoa);
				}
				else printf("Cartão informando não existe para ser excluído\n");
				
				travatela();
				break;
				
			case 7:
				system("clear");
				printf("Listagem de clientes\n\n");
				listarClientes(Clientes);
				travatela();
				break;
				
			default:
				printf("Opção inválida\n");
				travatela();
				break;
		}
	}while(op != 0);
}

/* Arquivo que contém as definições de estruturas do sistema */

/* ======================= Clientes do supermercado ======================= */
typedef struct {
	int numCartao;
	String nome;
	float saldo;
}T_cliente;

typedef struct cx {
	T_cliente conteudo;
	struct cx * prox;
}T_caixaCliente;

typedef T_caixaCliente *pontCaixaCliente;

typedef struct {
	pontCaixaCliente prim, ult;
	int qtdCliente;
}T_listaClientes;

/* ======================= Estoque do supermercado ======================= */
typedef struct {
	int codBarras;
	String nomeProduto;
	float precoUnitarioCompra;
	float precoUnitarioVenda;
	int quantidade;
}T_produto;

typedef struct cxP {
	T_produto produto;
	struct cxP *prox;
}T_caixaProduto;

typedef T_caixaProduto *pontCaixaProduto;

typedef struct {
	pontCaixaProduto prim, ult;
	int qtdProdutos;
}T_listaProdutos;

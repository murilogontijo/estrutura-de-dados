typedef struct {
	String nome;
	int idade;
	int senha;
}T_cliente;

typedef struct cx {
	T_cliente elemento;
	struct cx * prox;
}T_caixa;

typedef T_caixa * pontCaixa;

typedef struct {
	pontCaixa prim, ult;
}T_fila;

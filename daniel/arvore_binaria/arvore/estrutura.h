/* caixa que guarda o valor do nó */
typedef struct caixa{
	int populacao;
	int codPais;
}caixa;

/** Representa os Nós da arvore */
typedef struct no{
	struct no *esquerda;
	struct no *direita;
	caixa cx;
}no;


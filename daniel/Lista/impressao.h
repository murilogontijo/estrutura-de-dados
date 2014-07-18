char MENSAGEM[] = "";

/**
 * Imprime os dados de um carro
 * @param Carro*	o carro
 */
void imprimirCarro(Carro *carro){
	
	__int(carro->codigo);
	__t();
	__(carro->placa);
	__t();
	__(carro->modelo);
	__t();
	__n("");
}

/**
 * Imprime os dados de uma lista
 * @param Lista*	a lista
 */
void imprimirLista(Lista *lista){
	int i;
	if(lista->ultimo < 0){
		addMensagem(LISTA_VAZIA);
		return;
	}
	for(i=0; i<=lista->ultimo; i++){
		
		if(lista->carros[i].ativo != 0){
			imprimirCarro(&lista->carros[i]);
		}
		
	}
	__n("");
	
}

/**
 * Limpa a tela
 * */
void limparTela(){
    printf("\e[H\e[2J"); /* printf() para limpar a tela */
}

void menu(){
	
	mensagem();
	__n(PERGUNTA_MENU);
	__n(MENU);
	
}

void addMensagem(char string[]){
	strcpy(MENSAGEM, string);
}
void limpaMensagem(){
	strcpy(MENSAGEM, "");
}

void mensagem(){
	if(strlen(MENSAGEM) > 0){
		__n(DIVISOR);
		__n(MENSAGEM);
		__n(DIVISOR);
	}
	limpaMensagem();
}

/**
 * Imprime uma tabulação livre na linha
 * */
void __t(){
	printf("\t");
}

/**
 * Imprime uma string e quebra a linha
 * @param char* 	ponteiro da string
 * */
void __(char string[]){
	printf("%s", string);
}
/**
 * Imprime uma string e quebra a linha
 * @param char* 	ponteiro da string
 * */
void __n(char string[]){
	printf("%s\n", string);
	printf("\n");
}

/**
 * Imprime um inteiro
 * @param int i		o inteiro
 * */
void __int( int i){
	printf("%d", i);
}

/**
 * Imprime um float
 * @param float 	o float
 * */
void __float( float f){
	printf("%.2f", f);
}

/**
 * Imprime um endereço hexadecimal
 * @param inteiro do endereço
 * */
void __address( int i){
	printf("%x", i);
}

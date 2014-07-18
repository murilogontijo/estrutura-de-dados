char MENSAGEM[] = "";

void imprimirFila(Fila *estrutura){
	int i = estrutura->primeiro;
	__n(ELEMENTOS_FILA);
	
	if(estrutura->ultimo <  estrutura->primeiro){ //lista deu volta
		int volta =0;
		int max;
		int contador = 0;
		max = (tFila - estrutura->primeiro) + (estrutura->ultimo+1); //determinar quantos elementos serão impressos, para controle;
		
		while( contador < max){
			__int(i);
			printf("[%d]\t%s\t\t%s\n", contador, estrutura->elementos[i].disciplina,estrutura->elementos[i].assunto);
			if(i == tFila-1 && volta==0){
				volta++;
				i=0;
			}
			else{
				i++;	
			}
			contador++;
			
		}
		
	}
	else{
		while( i < estrutura->ultimo+1  ){
			__int(i);
			printf("[%d]\t%s\t\t%s\n", i, estrutura->elementos[i].disciplina,estrutura->elementos[i].assunto);
			i++;
		} 
	}
	
	
	
	
	
	
	__n("\n");
	
}

void imprimirPilha(Pilha *estrutura){
	int i;
	__n(ELEMENTOS_PILHA);
	for(i=0; i< estrutura->tamanho; i++){
		printf("[%d]\t%s\t\t%s\n", i, estrutura->elementos[i].titulo,estrutura->elementos[i].local);
	}
	__n("\n");
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

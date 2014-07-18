void imprimirPilha(PilhaCachorro *pilhaCachorro){
	
}
void imprimirFila(FilaCachorro *filaCachorro){
	
}

/**
 * Limpa a tela
 * */
void limparTela(){
    printf("\e[H\e[2J"); /* printf() para limpar a tela */
}

void menu(){
	
	__n("Selecione uma das opções abaixo ou 0(zero) para sair");
	__n("1 - Imprimir a pilha \t\t2 - Imprimir a fila \n3 - Inserir cachorro na pilha \t\t4 - Inserir cachorro na fila\n5 - Registrar adoção\n5 - Inverter pilha\t\t6 - Inverter fila ");
	
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

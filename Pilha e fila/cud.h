
void inserirPilha(Pilha *estrutura){
	if(cheiaPilha(estrutura) == 1) {
		char titulo[30];
		char local[30];
		__("Digite o título");
		scanf("%s", titulo);
		__("Digite o local");
		scanf("%s", local);
		strcpy(estrutura->elementos[estrutura->tamanho].titulo, titulo);
		strcpy(estrutura->elementos[estrutura->tamanho].local, local);
		estrutura->tamanho++;
	}
	else{
		addMensagem(PILHA_CHEIA);
	}
}

void inserirFila(Fila *estrutura){
	if(cheiaFila(estrutura) == 1) {
		char disciplina[30];
		char assunto[30];

		__("Digite a disciplina");
		scanf("%s", disciplina);
		__("Digite o assunto");
		scanf("%s", assunto);
		strcpy(estrutura->elementos[estrutura->ultimo+ 1].disciplina, disciplina);
		strcpy(estrutura->elementos[estrutura->ultimo+ 1].assunto, assunto);
		estrutura->ultimo++;
	}
	else{
		addMensagem(FILA_CHEIA);
	}
}

void retirarPilha(Pilha *estrutura){
	int cod, i, j;
	imprimirPilha(estrutura);
	__n("");
	__n(DIGITE_CODIGO_REMOVER);
	scanf("%d", &cod);
	
	if(cod<=estrutura->tamanho -1 && cod > 0){ //verificar se codigo é aceitável
		
		i = cod;
		j=i+1;
		while(j<=estrutura->tamanho -1){
			strcpy(estrutura->elementos[i].titulo, estrutura->elementos[j].titulo);
			strcpy(estrutura->elementos[i].local, estrutura->elementos[j].local);
			i++;
			j++;
		}
		estrutura->tamanho--;
	}
	else{
		__n(ELEMENTO_NAO_PILHA);
	}
	
}

void retirarFila(Fila *estrutura){
	int cod, i, j;
	imprimirFila(estrutura);
	__n("");
	__n(DIGITE_CODIGO_REMOVER);
	scanf("%d", &cod);
	
	if(filaDeuVolta(estrutura) == 1){
		i = cod;
		j = (cod+1 >=tFila)?(0):(cod+1);
		if((cod >= estrutura->primeiro && cod < tFila) || (cod>=0 && cod<=estrutura->ultimo)){//determinar se o codigo escolhido é aceitável
			i = cod;
			j =  i+1 >=tFila ? 0 : i+1;
			
			while(i!=estrutura->ultimo){
				printf("%d  recebe %d", i, j);
				strcpy(estrutura->elementos[i].disciplina, estrutura->elementos[j].disciplina);
				strcpy(estrutura->elementos[i].assunto, estrutura->elementos[j].assunto);
				i =  i+1 >=tFila ? 0 : i+1;
				j =  j+1 >=tFila ? 0 : j+1;
			}
			estrutura->ultimo = (i-1<0) ? tFila-1 : i-1;
			printf("O ultimo é %d", estrutura->ultimo);
		}
		else{
			__n(ELEMENTO_NAO_FILA);
		}
	}
	else{
		if( cod >= estrutura->primeiro && cod <= estrutura->ultimo){//determinar se o codigo é aceitável
			i = cod;
			j = i+i;
			while(i!=estrutura->ultimo){
				printf("%d  recebe %d\n", i, j);
				strcpy(estrutura->elementos[i].disciplina, estrutura->elementos[j].disciplina);
				strcpy(estrutura->elementos[i].assunto, estrutura->elementos[j].assunto);
				i++;
				j++;
			}
			estrutura->ultimo = i-1;
			printf("O ultimo é %d", estrutura->ultimo);
			
		}
		else{
			__n(ELEMENTO_NAO_FILA);
		}
	}
	
}

//retorna 1 se a fila deu volta e 0 em caso contrário
int filaDeuVolta(Fila *estrutura){
	if(estrutura->ultimo < estrutura->primeiro){
		return 1;
	}
	else{
		return 0;
	}
}


void inverterPilha(Pilha *estrutura){
	if(vaziaPilha(estrutura) == 0){
		Pilha handler;
		handler.tamanho = estrutura->tamanho;
		int i;
		for(i=0; i<handler.tamanho; i++){
			strcpy(handler.elementos[i].titulo, estrutura->elementos[i].titulo);
			strcpy(handler.elementos[i].local, estrutura->elementos[i].local);
		}
		
		i = 0;
		int j = handler.tamanho-1;
		
		while(i <  estrutura->tamanho){
			
			strcpy(estrutura->elementos[j].titulo, handler.elementos[i].titulo);
			strcpy(estrutura->elementos[j].local, handler.elementos[i].local);
			i++;
			j--;
		}
		imprimirPilha(estrutura);
	}
	else{
		addMensagem("Uma pilha vazia não pode ser invertida");
	}
}

void inverterFila(Fila *estrutura){
	
	if( vaziaFila(estrutura) == 0 ){
		Fila handler;
		handler.primeiro = estrutura->primeiro;
		handler.ultimo = estrutura->ultimo;
		int i;
		for(i=0; i<tFila; i++){
			strcpy(handler.elementos[i].disciplina, estrutura->elementos[i].disciplina );
			strcpy(handler.elementos[i].assunto, estrutura->elementos[i].assunto );
		}
		i = estrutura->primeiro;
		int j = handler.ultimo;
		while( i != estrutura->ultimo+1){
			printf("Transferindo %d para a posição %d\n", i, j);
			strcpy(estrutura->elementos[j].disciplina, handler.elementos[i].disciplina );
			strcpy(estrutura->elementos[j].assunto, handler.elementos[i].assunto );
			if(filaDeuVolta(estrutura)){
				j = (j-1 < 0) ? tFila -1 : j-1;
				i = (i+1 >= tFila) ? 0 : i+1;
			}
			else{
				i++;
				j--;	
			}
		}
		imprimirFila(estrutura);
		
		addMensagem("A fila foi invertida");
	}
	else{
		addMensagem("Uma fila vazia não pode ser invertida");
	}
}

void inicializarFila(Fila *estrutura){
	estrutura->primeiro = 0;
	estrutura->ultimo = 0;
}

void inicializarPilha(Fila *estrutura){
	estrutura->tamanho = 0;
}

int vaziaFila(Fila *estrutura){
	if(estrutura->primeiro == estrutura->ultimo){
		return 1;
	}
	return 0;
}
int vaziaPilha(Pilha *estrutura){
	if(estrutura->tamanho == 0){
		return 1;
	}
	return 0;
}

//retorna 0 se cheia
int cheiaPilha(Pilha *estrutura){
	if(estrutura->tamanho < tPilha){
		return 1;
	}
	return 0;	
}
//retorna 0 se cheia
int cheiaFila(Fila *estrutura){
	if (estrutura->primeiro > estrutura->ultimo) { //lista já deu volta
		if(estrutura->ultimo+1 == estrutura->primeiro){
			return 0;
		}
    	return 1;
	}
	else{ //lista em sequência simples
		if(estrutura->primeiro+estrutura->ultimo +1 == tFila){
			return 0;
		}
		return 1;
	}
}




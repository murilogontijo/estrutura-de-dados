/**
 * Insere um carro em uma lista
 * É verificado se a lista tem espaço, calculado onde colocar o novo carro (ordem por codigo)
 * */
void inserir( Lista *lista, Carro *carro ){
	if(lista->ultimo >= (tamanho-1) ){	//verifica se a lista está cheia
		printf("Lista cheia");
		return;
	}
	else{
		//printf("Lista com vaga");	
		int pos = novaPosicaoOrdenada( lista, carro->codigo ) ;	//descobre em que posição inserir
		avancarTodoMundo(lista, pos);	//daquela posição pra frente, desloca todo mundo uma posição pra frente
		
		
		lista->carros[pos].codigo = carroHandler.codigo;
		strcpy(lista->carros[pos].placa, carroHandler.placa);
		strcpy(lista->carros[pos].modelo, carroHandler.modelo);
		lista->carros[pos].ativo = 1;
		
		return;
	}
}

/**
 * Efetua a leitura de um novo carro, guardando os dados temporários em CarroHandler
 * */
void lerNovoCarro(Lista *lista){
	__n(INSIRA_NOVO_CARRO);	//estranhamento posso passar uma string como argumento oO
	__n(DIVISOR);
	__(DIGITE_CODIGO);
	scanf("%d", &carroHandler.codigo);
	__(DIGITE_PLACA);
	scanf("%s", carroHandler.placa);
	__(DIGITE_MODELO);
	scanf("%s", carroHandler.modelo);
	inserir(lista, &carroHandler);
}

void lerCarroAtualizado(Lista *lista){
	__n(INSIRA_DADOS_CARRO);	//estranhamento posso passar uma string como argumento oO
	__n(DIVISOR);
	__(DIGITE_CODIGO);
	scanf("%d", &carroHandler.codigo);
	__(DIGITE_PLACA);
	scanf("t%s", carroHandler.placa);
	__(DIGITE_MODELO);
	scanf("%s", carroHandler.modelo);
}

void alterarCarro(Lista *lista){
	int pos = lerPosicao();
	int novaPos;
	if(pos >= 0 && pos <= lista->ultimo){
		lerCarroAtualizado(lista);
		
		//carro ficará fora da ordem? se sim, é preparado o espaço adequado e a variavel pos é redefinida para ele
		if(pos == 0){	//o carro era o primeiro
			if(carroHandler.codigo > lista->carros[pos+1].codigo){
				//fere a ordem. o elemento não é mais o primeiro
				__n("fere a ordem. o elemento não é mais o primeiro");
				retrocederTodoMundo(lista, pos);
				pos = novaPosicaoOrdenada(lista, carroHandler.codigo);
				avancarTodoMundo(lista, pos);
			}
		}
		else if( pos > 0 && pos < lista->ultimo){	//o carro estava no meio da lista
			if( carroHandler.codigo > lista->carros[pos+1].codigo ||
				carroHandler.codigo < lista->carros[pos-1].codigo   ){
				__n("fere a ordem. O elemento não mais está nessa posição");
				
				retrocederTodoMundo(lista, pos);
				
				pos = novaPosicaoOrdenada(lista, carroHandler.codigo);
				avancarTodoMundo(lista, pos);
			}
		}
		else{	// o carro era o ultimo
			if(carroHandler.codigo < lista->carros[lista->ultimo-1].codigo){
				 __n("fere a ordem . o elemento não está mais na ultima posição");
				 lista->carros[lista->ultimo].ativo = 0;
				 pos = novaPosicaoOrdenada(lista, carroHandler.codigo);
				 avancarTodoMundo(lista, pos);
			}
		}
		
		lista->carros[pos].codigo = carroHandler.codigo;
		strcpy(lista->carros[pos].placa, carroHandler.placa);
		strcpy(lista->carros[pos].modelo, carroHandler.modelo);
		lista->carros[pos].ativo = 1;
		__n(CARRO_ALTERADO_SUCESSO);
		imprimirLista(lista);
		
	}
	else{
		addMensagem(ACESSO_POSICAO_INEXISTENTE);
	}
}

void apagarCarro(Lista *lista){
	int codigo;
	__n(DIGITE_CODIGO);
	scanf("%d", &codigo);
	int pos = buscarPorCodigo(lista, codigo);
	if ( pos != -1){
		retrocederTodoMundo(lista, pos);
		addMensagem(OPERACAO_SUCESSO);
	}
	else{
		//codigo não cadastrado
		addMensagem(ACESSO_POSICAO_INEXISTENTE);
	}
	
}
int lerPosicao(){
	int pos;
	__n(DIGITE_POSICAO);
	scanf("%d",&pos);
	return pos;
}

/**
 * Obtem uma substring
 * @param char* a string
 * @param inicio o caracter inicial
 * @param comprimento 	o tamanho da string
 * @return string extraida
 * */
char* substring(const char* string, int inicio, int comprimento) 
{ 
  if (string == 0 || strlen(string) == 0 || strlen(string) < inicio || strlen(string) < (inicio+comprimento)) 
    return 0; 

  return strndup(string + inicio, comprimento); 
} 


char* placa(char *placaBruta){
	
	if(strlen(placaBruta) >= 7){
		return substring(placaBruta, 0, 7);
	}
	return placaBruta;
}

void busca(Lista *lista){
	int opcao; 
	int posicao = -1;
	char placa[stringPlaca];
	int codigo;
	
	__n(PERGUNTA_TIPO_BUSCA);
	scanf("%d", &opcao);
	switch(opcao){
		case 1:	//busca por codigo
			
			scanf("%d", &codigo);
			posicao = buscarPorCodigo(lista, codigo);
		break;
		case 2:	//busca por placa
			scanf("%s", placa);
			posicao = buscarPorPlaca(lista, placa);
		break;
	}
	
	if(posicao >=0 ){
		imprimirCarro(&lista->carros[posicao]);
	}
	else{
		__n(NENHUM_RESULTADO_BUSCA);
	}
	
}


int buscarPorPlaca(Lista *lista, char placa[stringPlaca]){
	int i;
	for(i=0; i<=lista->ultimo; i++){
		if ( strcmp(lista->carros[i].placa, placa) == 0 ){
			return i;
		}
	}
	return -1;
}

/**
 * Determina se algum carro na lista possui o codigo em questão
 * @param Lista* lista	A lista
 * @param int codigo	O codigo que é procurado
 * @return int -1 para não encontrado ou o valor da posição do carro
 */
int buscarPorCodigo(Lista *lista, int codigo){
	int i;
	
	for(i=0; i<=lista->ultimo; i++){
		if (lista->carros[i].codigo == codigo){
			return i;
		}
	}
	return -1;
}

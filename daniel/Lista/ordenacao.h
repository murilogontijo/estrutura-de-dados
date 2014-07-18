/**
 * Percorre a lista e verifica em qual posição o novo carro deve ser inserido para se manter na ordem
 * @param Lista lista 	A lista
 * @param int codigo	Código do novo carro, que será usado para encontrar o lugar dele na lista
 * @return int 			posição adequada ou -1 para o caso de duplicação do codigo
 */
int novaPosicaoOrdenada( Lista *lista , int codigo ){
	
	int i;

	for(i=0; i< lista->ultimo; i++){
		if(codigo < lista->carros[i].codigo){
			return i;
		}
		else if(codigo == lista->carros[i].codigo){
			return -1;
		}
	}
	
	return lista->ultimo+1;
	
}
	

void avancarTodoMundo( Lista *lista , int posicao){
	int i;
	
	
	for(i = lista->ultimo; i >= 0; i--){
		
		if( i>=posicao ){
			printf("Transferindo de %d para %d", i, i+1);
			//transfere os dados desde a ultima ocupada para a posição seguinte, que estará vazia;
			lista->carros[i+1].codigo = lista->carros[i].codigo;
			lista->carros[i+1].ativo = lista->carros[i].ativo;
			strcpy(lista->carros[i+1].modelo , lista->carros[i].modelo);
			strcpy(lista->carros[i+1].placa , lista->carros[i].placa);
			
			//para controle, desativa o carro que foi desocupado. Ele será atualizado com o que está sendo inserido;
			lista->carros[i].ativo = 0;
			
		}
	}
	lista->ultimo++;
	
}

/**
 * dada uma posição, todos os itens depois dela na lista são deslocados uma casa para trás,
 * sobrescrevemendo a posição dada
 */
void retrocederTodoMundo (Lista *lista , int posicao){
	int i;
	for(i = posicao; i <= lista->ultimo; i++){
		
		//transfere os dados desde a ultima ocupada para a posição seguinte, que estará vazia;
		lista->carros[i].codigo = lista->carros[i+1].codigo;
		lista->carros[i].ativo = lista->carros[i+1].ativo;
		strcpy(lista->carros[i].modelo , lista->carros[i+1].modelo);
		strcpy(lista->carros[i].placa , lista->carros[i+1].placa);
		
		//desativa a proxima posição, que ja foi deslocada, para manter controle dos ativos
		if(i == lista->ultimo){
			lista->carros[i+1].ativo = 0;
			lista->carros[i+1].codigo = 0;
		}

		
	}
	lista->ultimo--;
	
}


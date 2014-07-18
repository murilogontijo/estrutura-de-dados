// ############## MACROS ############## //
#define MAX 25			/*Define a quantidade de times que terão no campeonato
						  Define a quantidade de elementos da lista	*/
#define CAR 20 

// ############## DEFINIÇÕES DE TIPO ############## //
typedef char String[CAR];
enum boolean {true = 0, false = -1};

// ############## Funções diversas ############## //

void travatela(){
	// Essa função precisa ter interação com o usuário //
	printf("Digite ENTER para continuar\n");
	getchar();
	
}
void criarListaVazia(T_Lista * lista) { /* Passa 'lista' como ponteiro para que qualquer auteração efetuada na função surta efeito na lista //
	// Essa função criará a lista Vazia que precisaremos trabalhar;*/
	
	lista -> elemento = 0; /* lista é a variável que criamos que guarda a lista que utilizaremos. 
							  O operador ' -> ' faz um apontamento para o atrítuto da estrutura T_Lista que pretendemos usar; */
	
}

int inserirElementoFinal(T_Lista * lista, T_time time) {
	
	int verificarListaCheia(T_Lista * lista);
	
	if (verificarListaCheia(lista) == true) return false;
	else {
		lista->vetor[lista->elemento] = time;
		lista->elemento += 1;
		return true;
	}
	
}

void listarElementos(T_Lista * lista) {
	// Essa função precisa ter interação com o usuário //
	int i = 0;	
	
	while (i < lista->elemento) {
		printf("|Time: %s| %dº |:Pontos: %d |Jogos:  %d  |Vitórias: %d |Empates: %d |Derrotas: %d |Gols Pró: %d |Gols Contra: %d |Saldo: %d |\n\n",lista->vetor[i].nome,i+1 ,lista->vetor[i].Pontos, lista->vetor[i].qJogos, lista->vetor[i].qVitorias, lista->vetor[i].qEmpates, lista->vetor[i].qDerrotas, lista->vetor[i].GolsPro, lista->vetor[i].GolsContra, lista->vetor[i].Saldo);
		
		i++;
	}
	
}

int inserirElemento(T_Lista * lista, int pos, T_time time) {
	
	int i;
	
	int verificarListaCheia(T_Lista * lista);
	
	if (verificarListaCheia(lista) == true) return false; // Se a lista tiver cheia a função retorna false
	
	else { // Se não, insere elemento //
		if (pos >= lista->elemento) {
			inserirElementoFinal(lista, time);
			return true;
		}
		else {
			
			for(i = lista->elemento; i > pos; --i) {
				
				lista->vetor[i] = lista->vetor[i-1];
				
			}
			
			lista->vetor[i] = time;
			
			lista->elemento += 1;
			
			return true;
		}
	}
	
}

int inserirElementoInicio(T_Lista * lista, T_time time) {
	
	int verificarListaCheia(T_Lista * lista);
	
	if (verificarListaCheia(lista) == true) return false;
	else {
		inserirElemento(lista, 0, time);
		return true;
	}
}

int detalheTime(T_time * time, T_Lista * lista) {
	// Essa função precisa ter interação com o usuário //
	String temp;
	
	int procurarTime(T_Lista * lista, String nome); //Função para procurar um time na lista
	
	printf("Digite o nome do time: ");
	fgets(temp, CAR, stdin);
	if (procurarTime(lista, temp) == -1) {
		strcpy(time->nome, temp);
		time->qJogos = 0;
		time->qVitorias = 0;
		time->qEmpates = 0;
		time->qDerrotas = 0;
		time->Pontos = time->qVitorias * 3 + time->qEmpates;
		time->GolsPro = 0;
		time->GolsContra = 0;
		time->Saldo = time->GolsPro - time->GolsContra;
		return 0; // O time informado pode ser incluído! 
	}
	
	else return -1; //O time não pode ser incluído porque já existe!

}

int procurarTime(T_Lista * lista, String nome) {
	
	int i = 0; //Variável contadora
	int b = 0; // Essa variável, nessa função, terá uma ação booleana. Se ela for 0 = falso, se 1 = verdadeiro;
	while (i < lista->elemento && b != 1) {
		
		if (strcmp(nome, lista->vetor[i].nome) == 0) {
			b = 1; //Coloca o valor 1 para parar o laço de repetição
			
			return i; //retorna a posição que o time se encontra na lista;
		}
		
		i++; //incrementa para proximo cíclo
		
	}
	
	return -1; //retorna um valor que não existe na lista para informar que o time não existe
}

void vitoria(T_Lista * lista, int timeV, int golsTimeV, int timeP, int golsTimeP) {
	
	// O que o time vencedor ganha
	lista->vetor[timeV].qJogos +=1;
	lista->vetor[timeV].Pontos += 3;
	lista->vetor[timeV].GolsPro += golsTimeV;
	lista->vetor[timeV].GolsContra += golsTimeP;
	lista->vetor[timeV].qVitorias += 1;
	lista->vetor[timeV].Saldo = lista->vetor[timeV].GolsPro - lista->vetor[timeV].GolsContra;
	
	// O que o time perdedor leva
	lista->vetor[timeP].qJogos +=1;
	lista->vetor[timeP].qDerrotas += 1;
	lista->vetor[timeP].GolsPro += golsTimeP;
	lista->vetor[timeP].GolsContra += golsTimeV;
	lista->vetor[timeP].Saldo = lista->vetor[timeP].GolsPro - lista->vetor[timeP].GolsContra;
}

void empate(T_Lista * lista, int timeC, int golsTimeC, int timeV, int golsTimeV) {
	
	// O que o time da casa ganha
	lista->vetor[timeC].qJogos +=1;
	lista->vetor[timeC].Pontos += 1;
	lista->vetor[timeC].qEmpates += 1;
	lista->vetor[timeC].GolsPro += golsTimeC;
	lista->vetor[timeC].GolsContra += golsTimeV;
	lista->vetor[timeC].Saldo = lista->vetor[timeC].GolsPro - lista->vetor[timeC].GolsContra;
	
	// O que o time visitante ganha
	lista->vetor[timeV].qJogos +=1;
	lista->vetor[timeV].Pontos += 1;
	lista->vetor[timeV].qEmpates += 1;
	lista->vetor[timeV].GolsPro += golsTimeV;
	lista->vetor[timeV].GolsContra += golsTimeC;
	lista->vetor[timeV].Saldo = lista->vetor[timeV].GolsPro - lista->vetor[timeV].GolsContra;
}

void ordenarClassificacao(T_Lista * lista) {
	
	int i, j; //Variáveis contadoras
	
	void trocarPosicao(T_Lista * lista, int j) ;
	
	for (i = 0; i <= lista->elemento; i++){
		
		j = 0;
		while (j < (lista->elemento)-1) {
			
			if (lista->vetor[j].Pontos < lista->vetor[j+1].Pontos) { //time anterior tem menos pontos que o próximo time
				trocarPosicao(lista, j);
			}
			if(lista->vetor[j].Pontos == lista->vetor[j+1].Pontos) { //os dois times tem a mesma quantidade de pontos
				
				if(lista->vetor[j].qJogos < lista->vetor[j+1].qJogos) { //nesse caso valida qual tem menos jogos jogados. o time com menos jogos tem maior prioridade na competição
					trocarPosicao(lista, j);
				}
				if (lista->vetor[j].qJogos == lista->vetor[j+1].qJogos) { //os dois times tem a mesma quantidade de jogos jogados
					
					if(lista->vetor[j].qVitorias < lista->vetor[j+1].qVitorias) { // nesse caso, valida qual tem a maior quantidade de vitórias. O time com mais vitórias tem maior prioridade na competição
						trocarPosicao(lista, j);
					}
					if(lista->vetor[j].qVitorias == lista->vetor[j+1].qVitorias) { //os dois times tem a mesma quantidade de vitórias
						
						if(lista->vetor[j].Saldo < lista->vetor[j+1].Saldo) { // nesse caso, valida qual o time tem o melhor saldo de gols. O time com melhor saldo de gols tem maior prioridade na competição
							trocarPosicao(lista, j);
							
						}
						if(lista->vetor[j].Saldo == lista->vetor[j+1].Saldo) { //os dois times tem o mesmo saldo de Gols
							
							if(lista->vetor[j].GolsPro < lista->vetor[j+1].GolsPro) {
								trocarPosicao(lista, j);
							}
							
						}
						
					}
					
				}
				
			}
				
				
			j++; //Isso ocorre depois de todas as verificações possíveis;
		}
		
	}
	
}

void trocarPosicao(T_Lista * lista, int j) {
	T_time temp; //variável temporária
	
	temp = lista->vetor[j];
	lista->vetor[j] = lista->vetor[j+1];
	lista->vetor[j+1] = temp;
	
}

void excluirElemento(T_Lista * lista, String nome) {
	
	int pos; //variável vai guardar a posição do time a ser excluido
	
	pos = procurarTime(lista, nome);
	
	while (pos < lista->elemento - 1) {
		
		lista->vetor[pos] = lista->vetor[pos+1];
		pos++;
	}
	
	lista->elemento -= 1;
	
}

void corrigirElemento(T_Lista * lista, int pos, String nomeCorrigido) {
	
	if (pos != -1) strcpy(lista->vetor[pos].nome, nomeCorrigido);

}

int verificarListaCheia(T_Lista * lista) {
		
	if (lista->elemento == MAX) return true;
	else return false;
}

int verificarListaVazia(T_Lista * lista) {
	
	if (lista->elemento == 0) return true;
	else return false;
	
}

 /*  == Descrissão do arquivo ==
 * 	Esse arquivo contém as funções sistemicas que controlam o sistema e encapsula funções complexas do programa.
 * 
 * 	== Lógica algorítmica ==
 * 	Os comentários, no decorrer do arquivo descrevem a lógica algorítmica. Caso algum script necessite ser detalhado, 
 * 	será descrito sua lógica nessa parte do arquivo.
 * */
 
void criarListaVazia(T_Lista * lista) { /* Passa 'lista' como ponteiro para que qualquer auteração efetuada na função surta efeito na lista //
											 Essa função criará a lista Vazia que precisaremos trabalhar;*/
	
	lista -> elemento = 0; /* lista é a variável que criamos que guarda a lista que utilizaremos. 
							  O operador ' -> ' faz um apontamento para o atrítuto da estrutura T_Lista que pretendemos usar; */
	
}
 
int verificarListaCheia(T_Lista * lista) {
		
	if (lista->elemento == MAX) return true;
	else return false;
}


int verificarListaVazia(T_Lista * lista) {
	
	if (lista->elemento == 0) return true;
	else return false;
	
}
 
 
int procurarTime(T_Lista * lista, String nome) {
	/*Essa função apenas busca em uma lista se o time informado já existe. Ela recebe como parâmetro a lista que ela deve consultar e o nome do time que ela deve procurar. Retorna TRUE caso encontre o time e retorna FALSE caso o time não exista. */
	
	int i = 0; //Variável contadora
	int b = false; /* Variável boleana que vai controlar o laço de repetição para parar quando o usuário buscar um time.
							Inicia como false e vai continuar executando enquanto b não for mudado para TRUE (informa que achou o time)*/
							
							
	while (i < lista->elemento && b != true) { /* Enquanto i estiver apontando para um elemento da lista que seja menor que o 
													elemento apontado pelo ponteiro lista-> elemento e a variável boolean b for false, continuar repetindo*/
													
		if (strcmp(nome, lista->vetor[i].nome) == 0) {
			b = true; //Coloca o valor de b como true para parar o laço de repetição
			
			return i; //retorna a posição que o time se encontra na lista;
		}
		
		i++; //incrementa para proximo cíclo
		
	}
	
	return false; //Retorna para o usuário que o time informado não existe na lista.
}

void inserirElemento(T_Lista * lista, int pos, T_time time) {
	
	int i;

	if (pos >= lista->elemento) {
		lista->vetor[lista->elemento] = time;
	}
	else {
		
		for(i = lista->elemento; i > pos; --i) {
			
			lista->vetor[i] = lista->vetor[i-1];
			
		}
		
		lista->vetor[i] = time;
		
	}
	lista->elemento += 1;
	
}


void corrigirElemento(T_Lista * lista, int pos, String nomeCorrigido) {
	
	if (pos != -1) strcpy(lista->vetor[pos].nome, nomeCorrigido);

}

void excluirElemento(T_Lista * lista, int pos) {
	
	
	while (pos < lista->elemento - 1) {
		
		lista->vetor[pos] = lista->vetor[pos+1];
		pos++;
	}
	
	lista->elemento -= 1;
	
}

void iniciarCampeonatoVazio(T_listaJogo * campeonato) {
	campeonato->proximo = 0;
}

void trocarPosicao(T_Lista * lista, int j) {
	T_time temp; //variável temporária
	
	temp = lista->vetor[j];
	lista->vetor[j] = lista->vetor[j+1];
	lista->vetor[j+1] = temp;
	
}

void ordenarClassificacao(T_Lista * lista) {
	
	int i, j; //Variáveis contadoras
	
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
// ######################################################################################################################## //

void atribuirJogo(T_listaJogo * campeonato, T_Lista * lista, int first, int last) {
	strcpy(campeonato->jogoRodada[campeonato->proximo].time1, lista->vetor[first].nome);
	campeonato->jogoRodada[campeonato->proximo].golsTime1 = -1;
	strcpy(campeonato->jogoRodada[campeonato->proximo].time2, lista->vetor[last].nome);
	campeonato->jogoRodada[campeonato->proximo].golsTime1 = -1;
	campeonato->jogoRodada[campeonato->proximo].jogou = false;
}

void vitoria(T_Lista * lista, T_listaJogo * campeonato, int scan, int g1, int g2) {
	int i;
	
	i = procurarTime(lista, campeonato->jogoRodada[scan].time1);
	lista->vetor[i].qJogos += 1;
	lista->vetor[i].qVitorias += 1;
	lista->vetor[i].Pontos += 3;
	lista->vetor[i].GolsPro += g1;
	lista->vetor[i].GolsContra += g2;
	lista->vetor[i].Saldo = lista->vetor[i].GolsPro - lista->vetor[i].GolsContra;
	
	i = procurarTime(lista, campeonato->jogoRodada[scan].time2);
	lista->vetor[i].qJogos += 1;
	lista->vetor[i].qDerrotas += 1;
	lista->vetor[i].GolsPro += g2;
	lista->vetor[i].GolsContra += g1;
	lista->vetor[i].Saldo = lista->vetor[i].GolsPro - lista->vetor[i].GolsContra;
	
	ordenarClassificacao(lista);
}

void empate(T_Lista * lista, T_listaJogo * campeonato, int scan, int g1, int g2) {
	int i;
	
	i = procurarTime(lista, campeonato->jogoRodada[scan].time1);
	lista->vetor[i].qJogos += 1;
	lista->vetor[i].qEmpates += 1;
	lista->vetor[i].Pontos += 1;
	lista->vetor[i].GolsPro += g1;
	lista->vetor[i].GolsContra += g2;
	lista->vetor[i].Saldo = lista->vetor[i].GolsPro - lista->vetor[i].GolsContra;
	
	i = procurarTime(lista, campeonato->jogoRodada[scan].time2);
	lista->vetor[i].qJogos += 1;
	lista->vetor[i].qEmpates += 1;
	lista->vetor[i].Pontos += 1;
	lista->vetor[i].GolsPro += g1;
	lista->vetor[i].GolsContra += g2;
	lista->vetor[i].Saldo = lista->vetor[i].GolsPro - lista->vetor[i].GolsContra;
	
	ordenarClassificacao(lista);
}

void derrota(T_Lista * lista, T_listaJogo * campeonato, int scan, int g1, int g2) {
	int i;
	i = procurarTime(lista, campeonato->jogoRodada[scan].time2);
	lista->vetor[i].qJogos += 1;
	lista->vetor[i].qVitorias += 1;
	lista->vetor[i].Pontos += 3;
	lista->vetor[i].GolsPro += g2;
	lista->vetor[i].GolsContra += g1;
	lista->vetor[i].Saldo = lista->vetor[i].GolsPro - lista->vetor[i].GolsContra;
	
	i = procurarTime(lista, campeonato->jogoRodada[scan].time1);
	lista->vetor[i].qJogos += 1;
	lista->vetor[i].qDerrotas += 1;
	lista->vetor[i].GolsPro += g1;
	lista->vetor[i].GolsContra += g2;
	lista->vetor[i].Saldo = lista->vetor[i].GolsPro - lista->vetor[i].GolsContra;
	
	ordenarClassificacao(lista);
	
}

/* Assinatura:
 * sistema.h
 * 
 * Autor: Bruno Nogueira de Oliveira, aluno do terceiro período do curso de 
 * Sistemas de Informação na Universidade Federal de Goiás.
 * 
 * Algoritmo desenvolvido para disciplina de estrutura de dados, sobre a orientação do 
 * Professor Edmundo S. Spotto
 * 
 * Esse programa é um software proprietário; Ele não pode ser redistribuido
 * ou modificado, sem a permissão prévia do proprietário, informado acima.
 * 
 * Versão inicial desenvolvida dia 28.09.2013
 * Última modificação: 25.10.2013
 * 
 */

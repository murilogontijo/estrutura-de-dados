/*Estrutura de cados para comportar o sistema*/

typedef struct cadeiras {
	/* Define os dados de cada cadeira no teatro */
	String cliente; //Nome do cliente detentor daquela cadeira;
	float preco; //Define o preço da cadeira no teatro;
	int vendido; //Define se a cadeira em questão já está ocupada / ingresso vendido; Assume função de hashCliente
	// int hashCliente;
}T_cadeiras;

typedef struct plateia {
	T_cadeiras blocoEsquerda[VERTICAL][LATERAL]; //bloco esquerdo da plateia, comportando 30 cadeiras lateralmente e 43 cadeiras enfileiradas
	T_cadeiras blocoDireita[VERTICAL][LATERAL]; //bloco direito da plateia, comportando 30 cadeiras lateralmente e 43 cadeiras enfileiradas
	int qLugaresPossiveis; //define a quantidade de locais possíveis para serem ocupados no teatro;
}T_plateia;

typedef struct evento {
	String nome; //Nome do evento
	int horario; //Horário do evento.
	int hash; // variável que guardará um identificador para o evento.
	T_plateia publico;
	
}T_evento;

typedef struct listaEventos {
	T_evento apresentacao[QAPRES];
	int totalApresentacao;
}T_listaEventos;

typedef struct calendario {
	T_listaEventos datas[DIAS];
	int eventosTotais;
}T_calendario;

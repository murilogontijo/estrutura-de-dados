/*  == Descrissão do arquivo ==
 * 	Esse arquivo contém a função receberCliente do programa que será utilizada para colocar novos membros na fila.
 * 
 * 	== Lógica algorítmica ==
 * 	Os comentários, no decorrer do arquivo descrevem a lógica algorítmica. Caso algum script necessite ser detalhado, 
 * 	será descrito sua lógica nessa parte do arquivo.
 * */

void receberCliente(T_fila * filaBanco, T_senha * controlaSenha, T_preferencial * preferenciais) {
	system("clear");
	
	if (validaFilaCheia(filaBanco) == false) {
		printf("## Receber um cliente ##\n\n");
		
		printf("Digite o nome do cliente: ");
		getchar();
		fgets(filaBanco->fila[filaBanco->ultimo].nome, CAR, stdin); 
		
		do {
			printf("Digite a idade do cliente: ");
			scanf("%d", &filaBanco->fila[filaBanco->ultimo].idade);
			if (filaBanco->fila[filaBanco->ultimo].idade < 0) printf("Não digite idades negativas\n");
		}while(filaBanco->fila[filaBanco->ultimo].idade < 0);
		
		if(filaBanco->fila[filaBanco->ultimo].idade >= 60) preferenciais->quantidade++;
		
		filaBanco->fila[filaBanco->ultimo].senha = controlaSenha->atribuir;
		
		controlaSenha->atribuir++;
		
		filaBanco->qElementos++;
		filaBanco->ultimo++;
		
		if(filaBanco->ultimo == MAX) filaBanco->ultimo = 0;
	}
	else {
		printf("A fila do Banco atingiu sua capacidade máxima. Não é possível receber mais clientes\n\n");
		getchar();
		travatela();
	}
}

/* Assinatura:
 * receberCliente.h
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
 * Versão inicial desenvolvida dia 25.10.2013
 * Última modificação: 27.10.2013 (entrega do pacote final)
 * 
 */

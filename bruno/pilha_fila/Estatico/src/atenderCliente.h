/*  == Descrissão do arquivo ==
 * 	Esse arquivo contém a função atenderCliente que será utilizada para retirar elementos da fila no programa. 
 * 
 * 	== Lógica algorítmica ==
 * 	Os comentários, no decorrer do arquivo descrevem a lógica algorítmica. Caso algum script necessite ser detalhado, 
 * 	será descrito sua lógica nessa parte do arquivo.
 * */

void atenderCliente(T_fila * filaBanco, T_senha * controlaSenha, T_preferencial * preferenciais) {
	system("clear");
	
	T_pilha empilhador;
	
	printf("## Atender cliente ##\n\n");
	if(validaFilaVazia(filaBanco) == false){
		
		if(preferenciais->quantidade > 0) {
			
			iniciaEmpilhador(&empilhador);
			
			while (filaBanco->fila[filaBanco->proximo].idade < 60) {
				
				empilhador.empilhado[empilhador.topo] = filaBanco->fila[filaBanco->proximo];
				
				filaBanco->proximo++;
				if(filaBanco->proximo == MAX) filaBanco->proximo = 0;
				
				empilhador.topo++;
			}
			
			
			printf("Senha %d prioridade: PREFERENCIAL\n", filaBanco->fila[filaBanco->proximo].senha);
			printf("Sr(a) %s", filaBanco->fila[filaBanco->proximo].nome);
			printf("Favor, comparecer ao caixa\n");
			
			preferenciais->quantidade--;
			filaBanco->qElementos--;
			empilhador.topo--; //Para apontar para o elemento superior da pilha para o desempilhamento
			
			while (empilhador.topo >= 0) {
				filaBanco->fila[filaBanco->proximo] = empilhador.empilhado[empilhador.topo];
				
				empilhador.topo--;
				
				if(empilhador.topo > -1) filaBanco->proximo--;
				if(filaBanco->proximo == -1) filaBanco->proximo = MAX-1;
				
			}
		}
		else {
			printf("Senha %d prioridade: NORMAL\n", filaBanco->fila[filaBanco->proximo].senha);
			printf("Sr(a) %s", filaBanco->fila[filaBanco->proximo].nome);
			printf("Favor, comparecer ao caixa\n");
			
			filaBanco->qElementos--;
			filaBanco->proximo++;
			 
			if (filaBanco->proximo == MAX) filaBanco->proximo = 0;
		}
	}
	else {
		printf("Não tem nenhum cliente para ser atendido\n");
	}
	
	getchar();
	travatela();
}

/* Assinatura:
 * atenderCliente.h
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

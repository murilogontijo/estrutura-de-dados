/*  == Descrissão do arquivo ==
 * 	Esse arquivo contém as funções que tem interação com o usuário;
 * 
 * 	== Lógica algorítmica ==
 * 	Os comentários, no decorrer do arquivo descrevem a lógica algorítmica. Caso algum script necessite ser detalhado, 
 * 	será descrito sua lógica nessa parte do arquivo.
 * */


 // ############## FUNÇÕES ############## //
 
int telaConfirmacao() {
	 
	 char OP;
	 
	 do {
		 printf("Tem certeza que deseja efetuar essa operação (S / N)? ");
		 scanf("%c", &OP);
	 } while (OP != 'S' && OP != 's' && OP != 'N' && OP != 'n');
	 
	 if (OP == 'S' || OP == 's') return true;
	 else return false;
	 
 }
 
void travatela(){
	// Essa função aparece para o usuário quando ele termina de fazer alguma ação no sistema. Ela solicita que o usuário digite enter para voltar para o fluxo principal //
	
	printf("Digite ENTER para continuar\n"); //Mostra mensagem para usuário
	getchar(); //Aguarda ele apertar enter
	
}

void listarElementos(T_fila * filaBanco) {
	int i = filaBanco->proximo; //Variável contadora
	
	printf("Temos %d pessoas aguardando para serem atendidas\n\n", filaBanco->qElementos); 
	
	if (filaBanco->qElementos < MAX) {
		if (filaBanco->ultimo == 0) {
			do{
				printf("Nome: %sIdade: %d\nSenha: %d\t", filaBanco->fila[i].nome, filaBanco->fila[i].idade, filaBanco->fila[i].senha);
				filaBanco->fila[i].idade >= 60 ? printf("Atendimento preferencial\n\n") : printf("Atendimento normal\n\n");
				i++;
			} while(i < (filaBanco->ultimo == 0 ? MAX : filaBanco->ultimo));
		}
		else {
			do {
				printf("Nome: %sIdade: %d\nSenha: %d\t", filaBanco->fila[i].nome, filaBanco->fila[i].idade, filaBanco->fila[i].senha);
				filaBanco->fila[i].idade >= 60 ? printf("Atendimento preferencial\n\n") : printf("Atendimento normal\n\n");
				i++;
				if (i == MAX) i = 0;
			}while (i != filaBanco->ultimo);
		}
		
		/*for(i = filaBanco->proximo; i < (filaBanco->ultimo == 0 ? MAX - 1 : filaBanco->ultimo); i++) {
			printf("Nome: %sIdade: %d\nSenha: %d\t", filaBanco->fila[i].nome, filaBanco->fila[i].idade, filaBanco->fila[i].senha);
			filaBanco->fila[i].idade >= 60 ? printf("Atendimento preferencial\n\n") : printf("Atendimento normal\n\n") ;
		}*/
	}
	else {
		do {
			printf("Nome: %sIdade: %d\nSenha: %d\t", filaBanco->fila[i].nome, filaBanco->fila[i].idade, filaBanco->fila[i].senha);
			filaBanco->fila[i].idade >= 60 ? printf("Atendimento preferencial\n\n") : printf("Atendimento normal\n\n") ;
			i++;
			if (i == MAX) i = 0;
		} while(i != filaBanco->proximo /*(filaBanco->ultimo == 0 ? MAX - 1 : filaBanco->ultimo - 1)*/);
		
		/*for(i = filaBanco->proximo; i <= (filaBanco->ultimo == 0 ? MAX - 1 : filaBanco->ultimo - 1); i++) {
			printf("Nome: %sIdade: %d\nSenha: %d\t", filaBanco->fila[i].nome, filaBanco->fila[i].idade, filaBanco->fila[i].senha);
			filaBanco->fila[i].idade >= 60 ? printf("Atendimento preferencial\n\n") : printf("Atendimento normal\n\n") ;
		}*/
		
	}
}

  /* Assinatura:
 * user.h
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
 * Última modificação: 27.10.2013 (entrega do pacote final)
 * 
 */

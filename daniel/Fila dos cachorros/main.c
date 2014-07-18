#include <stdio.h>
#include <string.h>
#include "estruturas.h"
#include "impressao.h"

int main(){
	
	PilhaCachorro pilhaCachorro;
	FilaCachorro filaCachorro;
	pilhaCachorro.ultimo = -1;
	filaCachorro.ultimo = -1;
	
	
	
	int opcao;
	int controle = 1;
	
	limparTela();
	menu();
	scanf("%d", &opcao);
	
	
	while(controle !=0){
		switch (opcao){
			case 0:
				limparTela();
				controle = opcao;
			break;
			case 1:
				limparTela();
				imprimirPilha(&pilhaCachorro);
			break;
			case 2:
				limparTela();
				imprimirPilha(&pilhaCachorro);
			break;
			case 3:
				limparTela();
				novoCachorro();
			break;
			case 4:
				limparTela();
			break;
			case 5:
				limparTela();
			break;
			default:
				limparTela();
				__n("Opção não suportada");
		}
		
		
		menu();
		scanf("%d", &opcao);
	}
	
	return 0;

}

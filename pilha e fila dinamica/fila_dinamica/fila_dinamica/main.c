/**
 * Daniel e Ana Letícia
 * */
#include <stdio.h> 
#include <stdlib.h>
 
typedef int elemento;
 

typedef struct no{ 
    elemento valor; 
    struct no *proximo; 
} No; 
 
typedef struct fila{ 
    No *inicio; 
    No *fim; 
    int quantidade; 
} Fila; 

void fila_inicializar(Fila *f){ 
    f->inicio=NULL; 
    f->fim=NULL; 
    f->quantidade=0; 
}
 
void fila_inserir(Fila *f, elemento e){ 
    No *aux=malloc(sizeof(No)); 
    aux->valor=e; 
    aux->proximo=NULL; 
 
    if(f->inicio==NULL){ 
        f->inicio=aux; 
    }
    else{ 
        f->fim->proximo=aux; 
 
    }
 
    f->fim=aux; 
    f->quantidade++; 
}
 
 
int fila_quantidade(Fila f){ 
return f.quantidade; 
}
 
elemento fila_remover(Fila *f){ 
    No *aux=f->inicio; 
    elemento e=aux->valor; 
    f->inicio=aux->proximo; 
    free(aux); 
    f->quantidade--; 
    if(f->inicio==NULL){ 
        f->fim=NULL; 
    }
    return e; 
}
 


void fila_imprimir(Fila *f){
	if(f->quantidade == 0) { return; }
	No *aux=f->inicio; 	//a partir do inicio, imprime os nos recursivamente
	fila_imprimir_no(aux);
}

//imprime a partir de um certo no todos os seguintes
void fila_imprimir_no(No* n){
	printf(">\t%d\n", n->valor);
	if(n->proximo != NULL){
		fila_imprimir_no(n->proximo);
	}
}

int main(){
	Fila f;
	fila_inicializar(&f);
	
	printf("Fila inicializada\n");
	int escolha,x;
	
	
	for(;;){
		printf("\n-------\n\n");
		printf("1 - Enfileirar\n");
		printf("2 - Desenfileirar\n");
		printf("3 - Imprimir\n");
		printf("4 - Sair\n");
		printf("\n-------\n\n");
		printf("Opção: ");
		scanf("%d", &escolha);
     
        switch(escolha) {
			case 1:   
				 printf("Digite o numero a inserir\n");
				 scanf("%d",&x);
				 fila_inserir(&f, x);
			  break;
			case 2:       
				 printf("Desenfileirando elemento\n");
				 fila_remover(&f);
			  break;
			case 3:
				 printf("%d Elementos na fila\n", fila_quantidade(f));
				 fila_imprimir(&f);
			  break;   
			case 4:
				 exit (1);
              }                                  
   }
}


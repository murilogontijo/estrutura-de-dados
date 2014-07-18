/**
 * Daniel e Ana Letícia
 * */
 
#include <stdio.h>
#include <stdlib.h>


typedef struct celulaLista{
   int informacao;
   struct celulaLista *proximo;
}celula;

int main(){
   
      celula *pLista;
      int opcao = 0;
   
      void initLista(celula **pRecebido);
      void insertLista(celula **pRecebido);
      void buscaListaSimples(celula **pRecebido);
      void removeElementoListaSimples(celula **pRecebido);
      int leValor(int *valorRecebido);

   
      pLista = (celula *)malloc(sizeof(struct celulaLista));
      initLista(&pLista);
      for(;;){
         printf("\n1 - Inserir : ");
         printf("\n2 - Consultar: ");
         printf("\n3 - Remover");
         printf("\n4 - Sair\n");
         scanf("%d", &opcao);
         opcao = leValor(&opcao);
         switch(opcao)
         {
            case 1:
          insertLista(&pLista);
          break;
       case 2:
          buscaListaSimples(&pLista);
          break;
       case 3:
         removeElementoListaSimples(&pLista);
         break;
       case 4:
         exit(0);
        }
     }
     return 0;
}


void initLista(celula **pRecebido){
   (*pRecebido)->proximo = NULL;
}


void insertLista(celula **pRecebido){
	
	//adicionado uso de recursao. se o proximo ja está usado, será feita uma tentativa no proximo do proximo
	if((*pRecebido)->proximo == NULL){ 	
      celula *temporario;
      int valor;
   
      printf("\nInforme um Valor a ser Inserido : ");
      scanf("%d", &valor);
      temporario = (celula *)malloc(sizeof(celula));
      temporario->informacao = valor;
      //temporario->proximo = (*pRecebido)->proximo;
	  
		temporario->proximo = NULL;
		(*pRecebido)->proximo = temporario;
		return;
	}
	else{
		  insertLista(&(*pRecebido)->proximo);
	}
	  
}

void buscaListaSimples(celula **pRecebido){
   
      celula *temporario;
   
      if((*pRecebido)->proximo == NULL){
         printf("Lista Vazia!\n");
      }
      else{
         temporario = (celula *)malloc(sizeof(celula));
         temporario = (*pRecebido)->proximo;
         while(temporario != NULL){
            printf("Valor : %d\n", temporario->informacao);
            temporario = temporario->proximo;
         }
      }
}

void removeElementoListaSimples(celula **pRecebido){
   
      celula *temporario;
   
      if((*pRecebido)->proximo == NULL){
         printf("\nLista Vazia!");
      }
      else{
         temporario = (*pRecebido)->proximo;
         (*pRecebido)->proximo = temporario->proximo;
         free(temporario);
      }
}

int leValor(int *valorRecebido){
 
      while((*valorRecebido > 4) || (*valorRecebido < 1)){
         printf("Opcao Invalida. Informe novamente : \n");
         scanf("%d", &(*valorRecebido));
      }
      return(*valorRecebido);
}

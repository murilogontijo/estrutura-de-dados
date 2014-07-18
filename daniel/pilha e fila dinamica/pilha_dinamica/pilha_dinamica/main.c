/**
 * Daniel e Ana Letícia
 * */
#include <stdio.h>  
#include <stdlib.h>

typedef struct tipo_pilha{
      int info;
      struct tipo_pilha *lig ;
};
typedef struct tipo_pilha *pont_pilha;
typedef pont_pilha pilha;
pilha p;

pont_pilha* criar (pilha p);
pont_pilha* empilhar (int x,pilha p);
void vazia (pilha p);
void elementoTopo (pilha p);
pont_pilha* desempilhar(pilha p);
void imprimir(pilha p);

int main()
{
	int escolha,x;
	p = criar(p);
	printf("Pilha inicializada\n");
	for(;;){
		printf("1 - Empilhar\n");
		printf("2 - Verificar se a pilha esta vazia\n");
		printf("3 - Desempilhar\n");
		printf("4 - Para Acessar o elementoTopoo da pilha\n");
		printf("5 - Imprimir pilha\n");
		printf("6 - Sair\n");
		printf("\n----------------------------------------------------\n\n");
		printf("Opção: ");
		scanf("%d", &escolha);
     
        switch(escolha) {
			case 1:   
				 printf("Digite o numero a inserir\n");
				 scanf("%d",&x);
				 p = empilhar(x,p); 
			  break;
			case 2:       
				  vazia (p);
			  break;
			case 3:
				  p = desempilhar (p);
			  break; 
			case 4: 
				 elementoTopo (p);
			  break;

			case 5:     
				 imprimir(p);   
			  break;   
			case 6:
				 exit (1);
              }      
       //system("clear");                              
   }
return 0; 
}

//inicializa a pilha
pilha* criar (pilha p)
{
   p = NULL;
   return p;
 }
 
// adiciona um elemento novo na pilha
pilha* empilhar (int x,pilha p)
{
	pilha pont;
	
	if((pont = malloc(sizeof(pont_pilha)))==NULL)
		printf("Não foi possivel alocar mais memória.\n");
	else{
		pont->info = x;
		pont->lig = p;
	}
	
	return pont; 
}

// verifica se a pilha passada está vazia
void vazia (pilha p)
{
   if(p == NULL)
   printf("Pilha vazia\n");
   else
   printf("Pilha nao vazia\n");
}

//retorna o elemento atualmente no topo da lista
void elementoTopo (pilha p)
{
    if(p!=NULL) 
    printf("elementoTopoo da pilha %d\n",p->info);
    else
     printf("Pilha vazia\n");
}

//remove o elemento do topo da pilha
pilha* desempilhar(pilha p)
{
   pont_pilha aux;
   
   if(p==NULL){
      printf("A pilha está vazia\n");            
     return;
   }  
   aux = p->lig;
   free(p);
 
   return aux;
}

// imprime os elementos da pilha
void imprimir(pilha p)
{
   pont_pilha aux;
   
   if(p!= NULL)
   for(aux = p;aux!=NULL;aux=aux->lig)
     printf(">\t%d \n",aux->info);
   else 
    printf("Pilha vazia\n");
}
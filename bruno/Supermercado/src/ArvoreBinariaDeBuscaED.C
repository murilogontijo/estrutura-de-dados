#include <stdlib.h>
#include <stdio.h>

/**
 * Progama de prontuario do pacientes no hospital.
 * 
 * Utiliza a estrutura de dados Arvore Binaria para
 * realizar a insercao, remocao e busca dos elementos.
 * 
 * Por Ana Leticia Herculano e Daniel Melo 
*/

//Estrutura que representa um prontuario de paciente.
typedef struct {
	int numero;
    char Nome[40];    
    char Data_Entrada[11]; 
    char Data_Saida[11];  
    char Tel[14];        
} Tipo_Prontuario;
                 
//Estrutura que representa um nó da árvore binária.
typedef struct nd {
	Tipo_Prontuario Elem;
	struct nd *Esq, *Dir;
} Nodo;

//Arvore binaria para insercao e busca de prontuarios.
typedef Nodo *Arvore;

/*
 * Cria uma arvore vazia.
*/
void Criar_Arvore_Vazia(Arvore *T) {
	(*T)=NULL;
}

/*
 * Exibe um menu.
*/
void Menu() {
	printf("1 - Cadastrar Prontuario de Paciente \n");
    printf("2 - Remover Prontuario de Paciente \n");
    printf("3 - Percorrer prontuarios em ordem \n");
    printf("4 - Percorrer prontuarios em pos-ordem \n");
    printf("5 - Percorrer prontuarios em pre-ordem \n");
    printf("0 - Sair \n");  
    printf("Opcao: ");
}

/*
 * Insere um elemento na arvore.
*/    
void Inserir_Elemento_Arvore(Arvore *T, Tipo_Prontuario X) {
    Arvore A;
    if((*T)==NULL) {
		A = (Arvore) malloc (sizeof (Nodo));
        A->Elem = X;
        A->Esq = NULL;
        A->Dir =NULL;
        (*T)=A;
    } else if (X.numero<((*T)->Elem.numero)) {
        Inserir_Elemento_Arvore(&(*T)->Esq, X);
    } else if (X.numero>((*T)->Elem.numero)) {		
        Inserir_Elemento_Arvore(&(*T)->Dir, X);
    } else {
		printf("Prontuario ja cadastrado: %d \n",X.numero);
	}
 }

/*
 * Recupera o maior sucessor de um determinado prontuario.
 */ 
Tipo_Prontuario Sucessor_Maior (Arvore *Q, Tipo_Prontuario *R) {
	while ((*Q)->Dir != NULL) {
		(*Q)=(*Q)->Dir;
		*R=(*Q)->Elem;
	}
	
	return((*Q)->Elem);
}

/*
 * Realiza a impressao de um determinado prontuario.
*/ 
void Exibir_Elemento(Tipo_Prontuario X) {
	printf("\n___________________________________\n ");
	printf("\n PRONTUARIO NUMERO: %d", X.numero);
    printf(" \n \n *  Nome: %s   \n",X.Nome);
    printf(" *  Data_Entrada: %s   \n",X.Data_Entrada);
    printf(" *  Data_Saida: %s   \n",X.Data_Saida);
    printf(" *  Telefone: %s   \n",X.Tel);
    printf("\n_______________________________________\n ");
}

/*
 * Remove um determinado prontuario da arvore.
*/ 
void Remover_Elemento_Arvore(Arvore *T,Tipo_Prontuario *X) { 
	Arvore A;
 
	if ((*T)==NULL) {
		printf("Arvore vazia - Elemento nao encontrado \n");
	} else {
		if ((X->numero < (*T)->Elem.numero)) {
			Remover_Elemento_Arvore (&(*T)->Esq,&(*X));
	   } else if ((X->numero > (*T)->Elem.numero)) {
			Remover_Elemento_Arvore (&(*T)->Dir,&(*X));
	   } else {
			A = (*T); 
			*X = A->Elem;
	        if ((*T)->Esq == NULL) {
				*X=(*T)->Elem;
                A = *T;
                (*T) = (*T)->Dir;
                free(A);
			} else if ((*T)->Dir == NULL) {
				(*X)=(*T)->Elem;
				A=(*T);
				(*T) = (*T)->Esq;
				free(A);
			} else {
				(*T)->Elem = Sucessor_Maior(&(*T)->Esq,&(*X));
				Remover_Elemento_Arvore(&(*T)->Esq,&(*X));
			}
		}
		Exibir_Elemento(*X);
	}
}
/*
 * Realiza a impressao pre-ordem
 */ 
void pre_ordem(Arvore T) {
	if (T!=NULL) {
		Exibir_Elemento(T->Elem);
        pre_ordem(T->Esq);
        pre_ordem(T->Dir);
     }
}

/*
 * Realiza a impressao em ordem.
 */ 
void imprimirEmOrdem(Arvore T) {
	if (T!=NULL) {
	imprimirEmOrdem(T->Esq);
        Exibir_Elemento(T->Elem);
        imprimirEmOrdem(T->Dir);
    }
 }
 
 /*
  * Realiza a impressao pos-ordem.
 */ 
 void pos_ordem(Arvore T) {
	 if (T!=NULL) {
		pos_ordem(T->Esq);
        pos_ordem(T->Dir);
        Exibir_Elemento(T->Elem);
     }
}
 
/*
 * Realiza a leitura dos dados do prontuario.
 */  
void Ler_Prontuario(Tipo_Prontuario *X) {
     printf("\n Cadastro de um paciente \n ");
     
     printf("\n Entre com o numero do prontuario: ");
     scanf("%d",&(X->numero));
     getchar();
     
     printf("\n Entre com o Nome do paciente: ");
     scanf("%s", (X -> Nome));
     
     printf("\n Entre com a Data de Entrada do paciente: ");
     scanf("%s", (X -> Data_Entrada));
     
     printf("\n Entre com a provavel Data de Saida do paciente: ");
     scanf("%s", (X -> Data_Saida));
     
     printf("\n Entre com o Telefone do Paciente: ");
     scanf("%s", (X -> Tel));
}

/*
 * Metodo principal do programa.
 */
int main()
 {  Arvore T;
    Tipo_Prontuario X;
    int op;
    
	Criar_Arvore_Vazia(&T); 
	do {
		Menu();
	    scanf("%d", &op);
		switch (op) { 
			case 1:
				Ler_Prontuario(&X);
			    Inserir_Elemento_Arvore(&T,X);
			    break;
			case 2:
				printf("\n Entre com o numero de prontuario que deseja remover: ");
			    scanf("%d",&(X.numero));
			    Remover_Elemento_Arvore(&T,&X);			         		
			    break;
			case 3:
				imprimirEmOrdem(T);
			    break;
			case 4:
				pos_ordem(T);
				break;
			case 5:
				pre_ordem(T);
				break;
			case 0:
				return (0);
			default:
				printf("Nao existe esta opção no Menu \n");
			}
	} while (op!=0);
	
	return(0);
 }

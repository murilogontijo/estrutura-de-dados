/* Constantes do sistema */

#define LATERAL 16 //define a quantidade de cadeiras que cabem lateralmente no teatro
#define VERTICAL 43 //define a quantidade de fileiras que cabem no teatro 
#define TAM 20

typedef char String[TAM]; //Possibilita o uso de uma cadeia de caracteres com até 20 caracteres

enum boolean {false = -1, true = 0 }; //define um tipo de dado booleano (true or false);

#define QAPRES 5 //define a quantidade de apresentacoes diárias
#define DIAS 31 //define a quantidade de dias que o mês possui para apresentações

enum horarios {apres1 = 1, apres2 = 2, apres3 = 3, apres4 = 4, apres5 = 5}; //define a quantidade de apresentações possíveis pelo teatro. Usado somente na struct T_evento na variável 'horario'

#define PRECOMAX 50
#define PRECONORMAL 35
#define PRECOMIN 20

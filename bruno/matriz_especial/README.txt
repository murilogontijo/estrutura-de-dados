Esse algoritmo foi desenvolvido por Bruno Nogueira de Oliveira, estudante de Sistemas de Informação na Universidade Federal de Goiás, sob a orientação do professor Edmundo S. Spoto para a disciplina de estrutura de dados.

O arquivo enviado para avaliação do professor contém o código do programa desenvolvido na linguagem C e o arquivo README.txt onde está especificado as características do programa.

O programa contém as seguintes características: 

O Script foi escrito na IDE Geany em um Sistema Operacional Linux Ubuntu versão 12.04 LTS.

A compilação e execução do código deverá ser feito em plataforma semelhante, uma vez que o algoritmo utiliza da função 'system' que torna o código menos portável. Portanto para a compilação ocorrer com sucesso, deve-se compilar o algoritmo na plataforma correta.

## FUNCIONALIDADES DO PROGRAMA ##

O programa trabalhará um vetor como se fosse elementos de uma matriz triangular superior. A quantidade de elementos desse vetor será calculado baseado na dimensão da pseudo-matriz que será declarada pela MACRO MAX. Isso é feito através da função tamanhoVetor();

No início do algoritmo será declarado uma MACRO chamada MAX que será responsável por definir a dimensão da Matriz quadrada. O valor declarado em MAX será o número de linhas e colunas da MATRIZ.

Logo depois será declarado outra macro chamado DIM. Essa macro definirá a dimensão dos números que serão utilizados para preenchimento automático na MATRIZ. Ela será utilizada em apenas um local do programa, na função capturaMatriz();
O algorítmo dessa função, basicamente gera um número inteiro aleatório positivo, utiliza um operador MODULO, para definir o resto da divisão do número aleatório pelo valor da MACRO DIM. Essa macro, portanto, faz o controle dos valores que serão preenchidos nessa função.

Em seguida, é declarada uma função, chamada tamanhoVetor() que será utilizada para definir, à partir da dimensão da MATRIZ definida pela MACRO MAX, qual a quantidade de elementos que esse vetor precisa ter. Isso deve-se ao fato de a MATRIZ ser apenas triangular superior, não existindo a necessidade de gerar, no vetor, todas as posições da matriz. É necessário apenas gerar as posições que serão utilizadas.
A lógica permite concluir que serão utilizadas apenas as posições da MATRIZ do elemento Aixj onde i é maior ou igual a j.
A quantidade de elementos que o vetor vai possuir ficará gravada na MACRO TAM.

Uma função chamada trava tela sempre limpará a tela durante a transição de uma funcionalidade para outra, solicitando ao usuário digitar ENTER para sair de cada tela do programa.

A função main fará poucas coisas:
	Ela inicializará os vetores que serão utilizados na função. Serão dois vetores que comportarão apenas elementos inteiros e terão dimensão 
	TAM, segundo definido nessa macro.
	
	Ela apresentará, em seguida, uma tela inicial que apresentará algumas informações do programa.
	
	Depois ela inicializará os dois vetores, atribuindo valores à eles através da função capturaMatriz();
	
	Terminando de atribuir os valores, ela chamará a função menu(); Nessa função o usuário terá todo o controle do programa.
	
Na função menu o usuário fará interações com o programa que permitira a ele visualizar as duas matrizes definidas automaticamente;
Fazer a soma dessas duas matrizes;
Fazer a subtração dessas duas matrizes;
Consultar um elemento da matriz;
Ou então modificar um elemento da matriz, desde que o elemento esteja na posição triangular superior da matriz.
	
	

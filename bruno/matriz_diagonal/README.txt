Matriz diagonal;

Esse algoritmo foi desenvolvido por Bruno Nogueira de Oliveira, estudante de Sistemas de Informação na Universidade Federal de Goiás, sob a orientação do professor Edmundo S. Spoto para a disciplina de estrutura de dados.

O arquivo enviado para avaliação do professor contém o código do programa desenvolvido na linguagem C e o arquivo README.txt onde está especificado as caracteristicas do programa.

O programa contém as seguintes caracteristicas:

O Script foi escrito na IDE Geany em um Sistema Operacional Linux Ubuntu versão 12.04 LTS.

A compilação e execução do código deverá ser feito em plataforma semelhante, uma vez que o algoritmo utiliza da função 'system' que torna o código menos portável. Portanto para a compilação ocorrer com sucesso, deve-se compilar o algoritmo na plataforma correta.

## FUNCIONALIDADES DO PROGRAMA ##

No algoritmo, trabalharemos um vetor de forma a parecer para o usuário que estamos trabalhando apenas com elementos da diagonal de uma matriz. Caso o usuário tente efetuar qualquer ação fora da diagonal dessa pseudo-matriz, o sistema retornara uma excessão.

O programa, ao ser iniciado, mostra uma tela inicial de boas vindas, que mostra ao usuário algumas específicações do programa.

Feito isso o programa cria dois vetores e atribui a eles valores aleatórios que variam de 0 à DIM (dimensão). Isso faz com que valores diferentes possam ser gerados. Por defeaut atribuimos 100, portanto os números variarão de 0 à 99.

Será mostrado ao usuário uma tela chamada MENU. Nessa tela o usuário poderá:

Visualizar uma MATRIZ:
O usuário escolherá entre uma das duas matrizes geradas automaticamente pelo script para visualizar.

Somar as matrizes;
O usuário, ao selecionar essa opção aciona o mecanismo para somar os dois vetores. Será questionado se o usuário gostaria de ver a matriz resultante

Subtrair as matrizes:
O usuário, ao selecionar essa opção aciona o mecanismo para subtrair os dois vetores. Será questionado se o usuário gostaria de ver a matriz resultante.

Multiplicar as matrizes:
O usuário, ao selecionar essa opção aciona o mecanismo para multiplicar os dois vetores. Será questionado se o usuário gostaria de ver a matriz resultante.

Procurar um elemento:
O usuário poderá procurar por um membro dentro de uma matriz, passando como parâmetro as cordenadas i e j de uma matriz. Se i for igual a j será retornado o valor do elemento i do vetor, caso contrário será retornado 0, visto que a posição solicitada não existe ou está nula.

Modificar um elemento: 
O usuário poderá modificar um elemento do vetor, desde que, na passagem dos parâmetros para essa modificação, o usuário digite a cordenada i e j da pseudomatriz com o mesmo valor. Caso os valores sejam diferente, o sistema retornará mensagem falando que o elemento solicitado não está na diagonal da matriz.

Finalizar o programa:
O usuário encerra o uso do script

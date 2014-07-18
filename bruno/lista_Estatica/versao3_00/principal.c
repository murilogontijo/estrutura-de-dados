#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "constantes.h"
#include "struct.h"
#include "user.h"
#include "sistema.h"
#include "cadastramento.h"
#include "jogarJogos.h"

int main() {
	T_Lista lista;
	T_campeonato jogos;
	
	criarListaVazia(&lista);
	criarCampeonatoVazio(&jogos);
	
	cadastramento(&lista);
	
	gerarJogos(&lista, &jogos);
	
	jogarCampeonato(&lista, & jogos);
	
	return 0;
} //Fim da main

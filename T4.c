#include <stdio.h>
#include <stdlib.h>
#include <math.h>

struct fracao{
	int numerador = 0
	int denominador = 0;
};

int main(int argc, char const *argv[]){
	int nEquacoes = 0, nCoeficientes = 0;
	char objeto = '';

	scanf("%d %d", &nEquacoes, &nCoeficientes);
	scanf("%c", &objeto);

	fracao **matriz;

	matriz = (*fracao) malloc(nCoeficientes * sizeof(*fracao));

	if (objeto == 'r'){
		
	} else {

	}
	return 0;
}
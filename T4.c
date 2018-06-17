#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct fracao{
	int numerador;
	int denominador;
} fracao;

int main(int argc, char const *argv[]){
	int nEquacoes = 0, nCoeficientes = 0, qntdEquacoes = 0;
	char objeto;

	scanf("%d %d", &nEquacoes, &nCoeficientes);
	scanf("%c", &objeto);

	fracao **matriz;

	matriz = (fracao**) malloc(nEquacoes * sizeof(fracao*));

	for (int i = 0; i < nCoeficientes; ++i){
		matriz[i] = (fracao*) malloc(nCoeficientes * sizeof(fracao));
	}

	do{
		scanf("%c", &objeto);
		if(objeto == 'p'){
			for (int i = 0; i < nCoeficientes; ++i){
					scanf("%d %d", &matriz[i]->numerador, &matriz[i]->denominador);
				}	
		} else {

		}
	} while (qntdEquacoes < nEquacoes);

	return 0;
}
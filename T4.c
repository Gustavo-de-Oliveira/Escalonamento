#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/*
TODO:
FREE EM MATRIZ
*/

typedef struct fracao{
	int numerador;
	int denominador;
} fracao;

void Swap(fracao **matriz, int nEquacoes);

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
					scanf("%d %d", &matriz[qntdEquacoes][i].numerador, &matriz[qntdEquacoes][i].denominador);
				}
				qntdEquacoes++;
		} else if(objeto == 'r'){
			for (int i = 0; i < nCoeficientes; ++i){
					scanf("%d %d", &matriz[qntdEquacoes][i].numerador, &matriz[qntdEquacoes][i].denominador);
				}
				qntdEquacoes++;
			for (int i = 0; i < nCoeficientes; ++i){
					scanf("%d %d", &matriz[qntdEquacoes][i].numerador, &matriz[qntdEquacoes][i].denominador);
				}
				qntdEquacoes++;
		}
	} while (qntdEquacoes < nEquacoes);

	if (matriz[0][0].numerador == 0){
		Swap(matriz, nEquacoes);
	}

	return 0;
}

void Swap(fracao **matriz, int nEquacoes){
	for (int i = 0; i < nEquacoes; ++i){
			if (matriz[i][0].numerador != 0){
				//switch(matriz[0] e matriz[i])
			}
		}	
}

/*
3 4
r
0 1 2 1 0 1 0 1
2 1 0 1 0 1 0 1
p
3 1 -1 1 0 1 3 1
*/
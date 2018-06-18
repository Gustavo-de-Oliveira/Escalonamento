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

void Swap(fracao **matriz, int nEquacoes, int nCoeficientes);

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
		Swap(matriz, nEquacoes, nCoeficientes);
	}

	for (int i = 0; i < 3; ++i)
	{
		for (int j = 0; j < 4; ++j)
		{
			printf("%d ", matriz[i][j].numerador/matriz[i][j].denominador);
		}
		printf("\n");
	}

	return 0;
}

void Swap(fracao **matriz, int nEquacoes, int nCoeficientes){
	int totalNumerador = 0, totalDenominador = 0;
	for (int i = 0; i < nEquacoes; ++i){
			if (matriz[i][0].numerador != 0){
				for (int j = 0; j < nCoeficientes; ++j){
					totalNumerador = matriz[i][j].numerador;
					totalDenominador = matriz[i][j].denominador;

					matriz[i][j].numerador = matriz[0][j].numerador;
					matriz[i][j].denominador = matriz[0][j].denominador;

					matriz[0][j].numerador = totalNumerador;
					matriz[0][j].denominador = totalDenominador;

					totalNumerador = 0; totalDenominador = 0;
				}
				break;
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
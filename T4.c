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

void Swap(fracao **matriz, int nEquacoes, int nCoeficientes, int inicioLinha);

int main(int argc, char const *argv[]){
	int nEquacoes = 0, nCoeficientes = 0, qntdEquacoes = 0;
	char objeto;
	fracao pivo;

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

	Swap(matriz, nEquacoes, nCoeficientes, 0);

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

void Swap(fracao **matriz, int nEquacoes, int nCoeficientes, int inicioLinha){
	int totalNumerador = 0, totalDenominador = 0;
	fracao fator, equacao;
	for (int i = inicioLinha; i < nEquacoes; ++i){
		if (matriz[i][inicioLinha].numerador != 0){
			for (int j = inicioLinha; j < nCoeficientes; ++j){
				totalNumerador = matriz[i][j].numerador;
				totalDenominador = matriz[i][j].denominador;

				matriz[i][j].numerador = matriz[inicioLinha][j].numerador;
				matriz[i][j].denominador = matriz[inicioLinha][j].denominador;

				matriz[inicioLinha][j].numerador = totalNumerador;
				matriz[inicioLinha][j].denominador = totalDenominador;

				totalNumerador = 0; totalDenominador = 0;
			}
			break;
		}
	}

	for (int i = inicioLinha+1; i < nEquacoes; ++i){
		fator.numerador = matriz[i][inicioLinha].numerador * matriz[inicioLinha][inicioLinha].denominador;
		fator.denominador = matriz[i][inicioLinha].denominador * matriz[inicioLinha][inicioLinha].numerador;

		if (fator.numerador != 0){
			for (int j = inicioLinha; j < nCoeficientes; ++j){
				//matriz[i][j] -= matriz[inicioLinha][j] * (matriz[i][inicioLinha]/matriz[inicioLinha][inicioLinha])
				equacao.numerador = matriz[inicioLinha][j].numerador;
				equacao.denominador = matriz[inicioLinha][j].denominador;

				equacao.numerador *= fator.numerador;
				equacao.denominador *= fator.denominador;

				matriz[i][j].denominador *= equacao.denominador;
				
			}
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

3 4
r
0/1 2/1 0/1 0/1
2/1 0/1 0/1 0/1
p
3/1 -1/1 0/1 3/1
*/
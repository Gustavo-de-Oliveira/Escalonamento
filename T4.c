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

void Escalonar(fracao **matriz, int nEquacoes, int nCoeficientes, int inicioLinha);
void Swap(fracao **matriz, int nEquacoes, int nCoeficientes, int inicioLinha);
int MenorMultiploComum(int a, int b);

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

		} else if(objeto == 'r') {
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

	Escalonar(matriz, nEquacoes, nCoeficientes, 0);

	for (int i = 0; i < 3; ++i)
	{
		for (int j = 0; j < 4; ++j)
		{
			//printf("%d/%d ", matriz[i][j].numerador, matriz[i][j].denominador);
			printf("%d ", matriz[i][j].numerador/matriz[i][j].denominador);
			//printf("%d ", matriz[i][j].denominador);
		}
		printf("\n");
	}

	return 0;
}

void Escalonar(fracao **matriz, int nEquacoes, int nCoeficientes, int inicioLinha){
	
	if (inicioLinha+1 == nEquacoes) return;
	if (matriz[inicioLinha][inicioLinha].numerador == 0) Swap(matriz, nEquacoes, nCoeficientes, inicioLinha);

	fracao pivo, a_equacao, equacao1, equacao;
	int mmc = 0;

	pivo.numerador = matriz[inicioLinha][inicioLinha].numerador;
	pivo.denominador = matriz[inicioLinha][inicioLinha].denominador;

	for (int i = inicioLinha+1; i < nEquacoes; ++i){
		a_equacao.numerador = matriz[i][inicioLinha].numerador;
		a_equacao.denominador = matriz[i][inicioLinha].denominador;

		for (int j = inicioLinha; j < nCoeficientes; ++j){
			equacao1.numerador = matriz[inicioLinha][j].numerador;
			equacao1.denominador = matriz[inicioLinha][j].denominador;

			a_equacao.numerador *= pivo.denominador;
			a_equacao.denominador *= pivo.numerador;

			equacao1.numerador *= a_equacao.numerador;
			equacao1.denominador *= a_equacao.denominador;

			mmc = MenorMultiploComum(equacao1.denominador, matriz[i][j].denominador);

			matriz[i][j].numerador = (mmc/matriz[i][j].denominador) * matriz[i][j].numerador;
			matriz[i][j].denominador = mmc;

			equacao1.numerador = (mmc/equacao1.denominador) * equacao1.numerador;

			matriz[i][j].numerador -= equacao1.numerador;
		}
	}

	Escalonar(matriz, nEquacoes, nCoeficientes, inicioLinha+1);
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
}

int MenorMultiploComum(int num1, int num2) {

    int resto, a, b;

    a = num1;
    b = num2;

    do {
        resto = a % b;

        a = b;
        b = resto;

    } while (resto != 0);

    return ( num1 * num2) / a;
}



/*
3 4
r
0 1 2 1 0 1 0 1
2 1 0 1 0 1 0 1
p
3 1 -1 1 0 1 3 1
*/
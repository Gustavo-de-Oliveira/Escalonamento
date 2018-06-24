/*
	Dados dois objetos no espaço (nesse caso, reta ou plano), verificar se há  colisão  (intersecção)  entre eles. Assim, temos três possibilidades: colisão entre dois planos, colisão entre uma reta e um  plano e, finalmente, colisão entre duas retas.
	Trabalho 4 - ICC
	Gustavo de Oliveira Silva - ICMC/USP	
	30/04/2018
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct fracao{ //Definição de um tipo de variavel que representa uma fração
	int numerador;
	int denominador;
} fracao;

void Escalonar(fracao **matriz, int nEquacoes, int nCoeficientes, int inicioLinha);
void Swap(fracao **matriz, int nEquacoes, int nCoeficientes, int inicioLinha);
long int MenorMultiploComum(int a, int b);

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

	do{//Laço que lê todas as equações que forem inseridas, assim podendo verificar a colisão de n objetos
		scanf("%c", &objeto);
		if(objeto == 'p'){//Recebe a equação de um plano
			for (int i = 0; i < nCoeficientes; ++i){
				scanf("%d %d", &matriz[qntdEquacoes][i].numerador, &matriz[qntdEquacoes][i].denominador);
			}
			qntdEquacoes++;

		} else if(objeto == 'r') {//Recebe a equação de uma reta(dois planos)
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

	Escalonar(matriz, nEquacoes, nCoeficientes, 0);//Chama a função que vai iniciar o processo de eliminação gaussiana

	int flag = 0;

	for (int i = 0; i < nEquacoes; ++i){
		if(matriz[i][0].numerador == 0 && matriz[i][1].numerador == 0 && matriz[i][2].numerador == 0 && matriz[i][3].numerador != 0) flag = 1;//Verifica se há algum absurdo nas equações finais
	}

	if (flag == 1) printf("nao\n");//se houver absurdo, não há colisão
	else printf("sim\n");

	for (int i = 0; i < nEquacoes; ++i){//Imprime a matriz na tela
		for (int j = 0; j < nCoeficientes; ++j){
			if (matriz[i][j].numerador%matriz[i][j].denominador == 0) printf("%d", matriz[i][j].numerador/matriz[i][j].denominador);
			else printf("%d/%d", matriz[i][j].numerador, matriz[i][j].denominador);
			if (i != nCoeficientes-1)printf("\t");
		}
		printf("\n");
	}
	return 0;
}

void Escalonar(fracao **matriz, int nEquacoes, int nCoeficientes, int inicioLinha){

	if (inicioLinha == nEquacoes-1) return; //Caso base da recursão, se estiver na ultima linha não há retorno
	if (matriz[inicioLinha][inicioLinha].numerador == 0) Swap(matriz, nEquacoes, nCoeficientes, inicioLinha);//Se o pivô for igual à zero a função Swap é chamada

	fracao a_equacao, equacao1;
	long int mmc = 0;

	for (int i = inicioLinha+1; i < nEquacoes; ++i){
		a_equacao.numerador = matriz[i][inicioLinha].numerador * matriz[inicioLinha][inicioLinha].denominador;
		a_equacao.denominador = matriz[i][inicioLinha].denominador * matriz[inicioLinha][inicioLinha].numerador;//a_equação se torna o 'a' da equação e logo após se torna o fator
				
		for (int j = inicioLinha; j < nCoeficientes; ++j){
			equacao1.numerador = matriz[inicioLinha][j].numerador;
			equacao1.denominador = matriz[inicioLinha][j].denominador;

			equacao1.numerador *= a_equacao.numerador;
			equacao1.denominador *= a_equacao.denominador;//Acontece a multiplicação do fator pelos valores da 1ª equação


			mmc = MenorMultiploComum(equacao1.denominador, matriz[i][j].denominador);//Descobre-se o valor do mmc dos denominadores das equações

			matriz[i][j].numerador = (mmc/matriz[i][j].denominador) * matriz[i][j].numerador;
			matriz[i][j].denominador = mmc;

			equacao1.numerador = (mmc/equacao1.denominador) * equacao1.numerador;

			//Acima ocorre todas as operações necessarias para se trabalhar com soma de frações

			matriz[i][j].numerador -= equacao1.numerador;//Subtração de frações

		}
	}
	Escalonar(matriz, nEquacoes, nCoeficientes, inicioLinha+1);//Caso de recursão
}

void Swap(fracao **matriz, int nEquacoes, int nCoeficientes, int inicioLinha){
	int totalNumerador = 0, totalDenominador = 0;

	for (int i = inicioLinha; i < nEquacoes; ++i){
		if (matriz[i][inicioLinha].numerador != 0){
			for (int j = inicioLinha; j < nCoeficientes; ++j){
				totalNumerador = matriz[i][j].numerador;
				totalDenominador = matriz[i][j].denominador;//Variavel auxiliar recebe os valores da linha cujo o pivô é diferente de zero

				matriz[i][j].numerador = matriz[inicioLinha][j].numerador;
				matriz[i][j].denominador = matriz[inicioLinha][j].denominador;//Ocorre a substituição da linha do pivô pela linha com o novo pivô

				matriz[inicioLinha][j].numerador = totalNumerador;
				matriz[inicioLinha][j].denominador = totalDenominador;//A variavel auxiliar copia os valores devolta para a matriz

				totalNumerador = 0; totalDenominador = 0;
			}
			break;
		}
	}
}

long int MenorMultiploComum(int n1, int n2){
	long int resto = 0, a = 0, b = 0;

    a = n1;
    b = n2;

    do{
        resto = a%b;
        a = b;
        b = resto;
    } while (resto != 0);

    return (n1*n2)/a;//Calculo do mmc através do algoritimo de Euclides
}
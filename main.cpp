/*
 * Main.cpp
 *
 *  Created on: 20/03/2015
 *      Author: Eliton
 */
#include<stdio.h>
#include<stdlib.h>
#define MAX_C 50
#define MAX_E 2500

int matriz[MAX_C][MAX_C];
int vetorCidades[MAX_C];
int C, E, L, P;

void busca(int k, int pag){
	for(int j = 0; j < C && pag < P ; j++){
		if( matriz[k][j] == 1 && vetorCidades[j] == 0){
			vetorCidades[j] = 1;
			busca(j, pag+1);
		}
	}
}

int main(){

	int testes = 0;

	do{
		testes++;
		scanf("%d %d %d %d", &C, &E, &L, &P);
		int a, b;
		int fila[MAX_C];
		for(int i = 0; i < C; i++){
			vetorCidades[i] = 0;
			fila[i] = 0;
			for(int j = 0; j < C; j++){
				matriz[i][j] = 0;
			}
		}
		for(int i = 0; i < E; i++){
			scanf("%d %d", &a, &b);
			matriz[a-1][b-1] = 1;
			matriz[b-1][a-1] = 1;
		}
		if(C == 0 || E == 0 || L == 0 || P == 0)
			exit(0);

		int L1 = L-1;

		vetorCidades[L1] = 0;


		int ini, fim;
		ini = fim = 0;

		fila[fim] = L1;
		fim++;

		while(ini != fim){
			int no = fila[ini];
			ini++;

			for(int i = 0; i < C ; i++){
				if(no != i && matriz[no][i] == 1  && vetorCidades[i] == 0){
					vetorCidades[i] = vetorCidades[no]+1;
					fila[fim] = i;
					fim++;
				}
			}
		}

/*
		for(int i = 0; i < C; i++){
			for(int j = 0; j < C; j++){
				printf("%d ", matriz[i][j]);
			}
			printf("\n");
		}*/
		vetorCidades[L1] = 0;
		printf("Teste %d\n", testes);
		for(int i = 0; i < C; i++){
			if(vetorCidades[i] != 0 && vetorCidades[i] <= P){
				printf("%d ", i+1);
			}
		}
		printf("\n\n");


	}while(1);

	return 0;
}





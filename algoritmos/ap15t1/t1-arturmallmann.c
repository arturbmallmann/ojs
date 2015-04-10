#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define N 4
static const int V[4] = {5,10,20,50};

int findMin(const int * notas){
	int min = 3;
	int i = N;
	while ( i-- ){
		if( notas[i] > 0 )
			min = i;
	}
	return min;
}

int total(const int * notas){
	int restante = 0;
	int i = 0;
	for(i=0; i < N ;i++){
		restante = restante + notas[i]*V[i];
	}
	return restante;
}

void sacar(const int valor,int * notas){
	int i,sacar[4];
	memcpy(sacar,notas,sizeof(int)*N);
	int saque=total(sacar);
	int acumulado=0;
	i = N;
		while(i--){
			while( (valor - acumulado) / V[i] && sacar[i]){
				sacar[i]--;
				acumulado += V[i];
			}
		}

	if ( acumulado != valor || total(sacar) < 0 ){
		printf("valor impossível\n");
		return;
	}
	i = N;
	printf("Notas sacadas:\n");
	while(i--)
		printf("R$ %d - %d\n",V[i],notas[i]-sacar[i]);
	
	memcpy(notas, sacar, sizeof(int)*N);
}

int main(){

		int op = 0;
		int * notas;
		notas = (int *)malloc(sizeof(int)*N);
		printf("informe quantas notas de 50,20,10 e 05 respectivamente deverá depositar\n");
		int i = N;
		while(i--)
			scanf("%d",&notas[i]);

		do {
			int restante = total(notas);
			printf("Saldo restante no cofre: R$ %d\n",restante);
			if(restante)
				printf("O valod mínimo para saque é R$ %d\n\nInforme o valor que deseja sacar:\n",V[findMin(notas)]);
			scanf("%d",&op);
			sacar(op,notas);
		}while(op>=0);
	return 0;
}

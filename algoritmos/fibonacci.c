#include<stdio.h>

int main(){
	int ant=0,atual=1,aux=0,iteracoes;
	scanf("%d",&iteracoes);
//	for(int i=0;i<iteracoes;i++){
	int i=0;
	while(i<iteracoes){
		printf("%d ",ant);
		aux = ant + atual;
		ant = atual;
		atual = aux;
		i++;
	}
	printf("\n");

	return 0;
}

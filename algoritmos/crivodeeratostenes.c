#include<stdio.h>
#include<math.h>
#include<stdlib.h>

#define DEBUG

void crivo (int n,int *phisao) {
	phisao[0]=2;
	int i,j,tp=1;
	int primo;
	for( i = 3 ; tp <= n ; i+= 2 ){
		primo = 1;
//		printf("floor de %d é: %d",i,(int)floor(sqrt(i)));
		for( j = 0 ; phisao[j] <= (int)floor(sqrt(i)) && j < tp; j++ ){
			if( i % phisao[j] == 0 ){
				primo = 0;
//				printf(". %d não é primo",i);
				break;
			}
//				printf(". %d é primo",i);
		}
//		printf("\n");
		if(primo)
			phisao[tp++]=i;
	}

}
int main(){
	int * phisao;
	printf("N primeiros Primos: ");
	int n;
	scanf("%d",&n);
	phisao = (int*)malloc(sizeof(int)*n);
	crivo(n,phisao);

	int i;
	for(i = 0; i < n; i++ )
		printf("%d ",phisao[i]);
	printf("\n");

	return 0;
}

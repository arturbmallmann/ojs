#include<stdio.h>

#define true 1
#define false 0

typedef int bool;

int main(){
	int numero;
	char op='n';
	scanf("%d",&numero);
/*	while ( op != 'x'){
		printf("Exibir todos os fatores? [%c]\n",op);
		scanf("%c",&op);
		while(getchar()!='\n'){}
	}//*/
	int i=1;
	bool scape=false;
	while( i<numero){//2){// && !scape && op=='n'){
		i++;
		scape = !(numero % i );
		if(scape){
			printf("%d | %d\n",numero,i);
			numero=numero/i;
		}
	}
	if(scape)
		printf("%d\n",numero);
//		printf("Multiplo de %d\n",i);
	else
		printf("Primo\n");
	return 0;
}

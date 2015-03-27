#include<stdio.h>
int main(){
	int P,Ni;
	scanf("%d %d",&P,&Ni);
	int contadores[P];
	int i,posicao;
	for(i=0;i<P;i++)
		contadores[i]=0;//iniciar com valor zero ao invés de lixo
	for(i=0;i<Ni;i++){
		scanf("%d",&posicao);
		contadores[posicao-1]++;
	}
	int err=0;
	int ref=Ni/P;
	if(Ni%P)
		ref++;//pombal ;)
	for(i=0;i<P;i++){
		if(contadores[i]>ref)
			err=1;
	}
	if(err)
		printf("N\n");
	else
		printf("S\n");

	return 0;
}

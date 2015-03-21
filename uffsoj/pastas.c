#include<stdio.h>

#define false 0
#define true 1
typedef int bool;


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
//	for(i=0;i<P;i++)
//		printf ("%d ",contadores[i]);

	bool check=false,err=false;
	int ref=Ni/P;
	Ni%P && (ref++);//pombal ;)
	for(i=0;i<P;i++){
		if(contadores[i]>ref)
			err=true;
	}
	if(err)
		printf("N\n");
	else
		printf("S\n");

	return 0;
}

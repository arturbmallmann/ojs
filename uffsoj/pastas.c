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
	Ni%P && (ref++);//pombal ;)
	if (contadores[0]>ref){
		err=true;
	}else{
		for(i=1;i<P;i++){
			if(contadores[i]>ref||contadores[i-1] < contadores[i]){
				err=true;
				break;
				}
		}
	}
	if(err)
		printf("N\n");
	else
		printf("S\n");

	return 0;
}

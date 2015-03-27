#include <stdio.h>

int main(){
	typedef struct{
		int id;
		float valor;
	}item;

	int nitens, mitens,listaIds[100];
//	item listaItens[100];
	scanf("%d %d",&nitens,&mitens);
	while(nitens != 0 && mitens != 0){
		float total=0;
		for(int i=0;i<nitens;i++)
			scanf("%d",&listaIds[i]);
		item last,temp;
		last.id = 0;
		temp.id = 0;
		int lids=0;
		for(int i=0;i<mitens;i++){
			scanf("%d %f",&temp.id,&temp.valor);
			if(temp.id == last.id && listaIds[lids] != last.id && temp.valor < last.valor)
				total = total - last.valor + temp.valor;
			else if(listaIds[lids] == temp.id){
				total = total + temp.valor;
				last = temp;
				lids++;
			}
		}
		if(lids==nitens)
			printf("%.2f\n",total);
		else
			printf("Impossible\n");
		scanf("%d %d",&nitens,&mitens);
	}

}

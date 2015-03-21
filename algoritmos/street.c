#include<stdio.h>

//#DEFINE L = 20
//#DEFINE C = 20

int main (){
//	int mapa[L][C];
	int x1,y1,h1=2,w1=2;
	int x2,y2,h2=2,w2=2;
	printf("posicao XxY");
//	printf("tamanho WxH\n");
	scanf("%d %d",&x1,&y1);
	printf("posicao XxY ");
//	printf("tamanho WxH\n");
	scanf("%d %d",&x2,&y2);


	if ( x1 <= x2 + w2 && x2 >= x1+w1 ){
		printf("alinhadas\n");
		if ( y1 >= y2 + h2 && y1 + h1 <= y2 ){
			printf("Colisão\n");
		}
	}

	/*int il,ic;
	for(il=0,il < L, il++){
		for(ic=0,il < C,ic++{
			mapa[il][ic]=0;
			if(il
		}
	}*/

	
}

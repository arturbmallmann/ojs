#include<stdio.h>
int main(){
	int a , b , c, maior,menor;

	scanf("%d %d %d",&a,&b,&c);
	printf("%d %d %x",a,b,c);

	if(a>=b){	
		if( a <= c ){
				maior = c;
				menor = b;
			}else{
				if( b > c ){
					menor = c;
				}else{
					menor = b;
				}
				maior = a;
		}
	}else{
		if( b < c ){
			maior = c;
			menor = a;
		}else{
			if(a < c){
				menor = a;
			}else{
				menor = c;
			}
			maior = b;
		}
	}
	printf("Maior valor: %d\nMenor: %d\n",maior,menor);
	return 0;
}

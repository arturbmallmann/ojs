#include<stdio.h>
int main (){
	int a,b,c,d;
	float total;
	scanf("%d",&a);
	scanf("%d",&b);
	scanf("%d",&c);
	scanf("%d",&d);
	total = (float)(a+b+c+d)/4;
	printf("A média da soma dos valore: %d %d %d %d \n é igual a %.2f\n",a,b,c,d,total);

}

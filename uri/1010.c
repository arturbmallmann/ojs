#include<stdio.h>

void main (){
	int cod1,qnt1, cod2,qnt2;
	double v1,v2,total;


	scanf ("%d %d %lf",&cod1,&qnt1,&v1);
	scanf ("%d %d %lf",&cod2,&qnt2,&v2);

	total = (qnt1 * v1) + (qnt2 * v2);

	printf("VALOR A PAGAR: R$ %.2lf\n",total);

	return 0;
}

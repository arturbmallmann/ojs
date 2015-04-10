#include<stdio.h>
int mdc(int a , int b){
	return b == 0 ? a : mdc (b,a % b) ;
}
int main(){
	int a , b;
	scanf("%d %d",&a,&b);
	while( a || b){
		printf("%d\n",mdc(a,b));
		scanf("%d %d",&a,&b);
	}
	return 0;
}

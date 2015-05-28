#include<stdio.h>
int main(){
	unsigned long long a = 0x5;
	unsigned long long b = 0xffffffff;
	printf("a %x, b %x \n", a , b ) ;
	unsigned long long r = a + b;
	unsigned int result = ( r & 0xffffffff);
	char cout;
	cout = (r >> 32) & 0x1 ;
	printf("r: %x, value %x, cout %x  \n", r, result, cout ) ;
	
	printf("ou exclusivo como not controlado %xH \n ", 0x0f ^ 0xff);

//	for(int i = 1 ; i <= 127 ; i++)
//		printf("%d : %c\n", i, i);
}

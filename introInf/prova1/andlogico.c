#include<stdio.h>
int main(){
	unsigned int a = 0xff;
	unsigned int  b = 0xff;
	printf("a %x, b %x \n", a , b ) ;
//	printf("%x \n", ~(a ^ b)  );
	unsigned int r = a + b;
	char result = (char) r % 256;
	char cout;
	cout = (char) (r >> 8) & 0x1 ;
	printf("r: %x, value %x, cout %x  \n", r, result, cout ) ;
	
	printf("ou exclusivo como not controlado %xH \n ", 0x0f ^ 0xff);

	for(int i = 1 ; i <= 127 ; i++)
		printf("%d : %c\n", i, i);
}

#include <stdio.h>

int main (){
	typedef struct conect {
		int a,b,c,d,e;
		} conector; 
	conector c1,c2;
	

	scanf("%d %d %d %d %d",&c1.a, &c1.b, &c1.c, &c1.d, &c1.e);
	scanf("%d %d %d %d %d",&c2.a, &c2.b, &c2.c, &c2.d, &c2.e);
	

	if ( c1.a != c2.a && c1.b != c2.b
	&& c1.c != c2.c 
	&& c1.d != c2.d && c1.e != c2.e)
		printf("Y\n");
	else
		printf("N\n");
		
	return 0;
}

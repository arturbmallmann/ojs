#include<stdio.h>
#define T 2
int main(){

	typedef struct{
		int x0, x1, y0, y1;
	}objeto;
	objeto obj[T];
	int i;
	for(i=0;i<T;i++)
		scanf("%d %d %d %d",&obj[i].x0, &obj[i].x1, &obj[i].y0, &obj[i].y1);

	
}

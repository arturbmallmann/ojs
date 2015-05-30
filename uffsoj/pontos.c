#include<stdio.h>

void limitamin(int * v){
	if (*v < 0)
		*v=0;
}
void limitamax(int * v,const int * b){
	if (*v > *b)
		*v = *b;
}

int main(){
//	typedef struct{
//		int x,y,d;
//	} sensor;
	int l,c;
	scanf("%d %d",&l,&c);
	char mar[l][c];
	char linha[c+2];
	for(int i=0;i<l;i++){
		scanf("%s",&linha);
		for(int o=0;o<c;o++)
			mar[l][c]=linha[o];
//			scanf("%c",&mar[i][o]);
	}
	printf("leu");
	int ns;
	scanf("%d",&ns);
	int saidas[ns];
//	sensor s[ns];
	for(int ss=0;ss<ns;ss++){
		int x,y,d;
		saidas[ss]=0;
		scanf("%d %d %d",&x,&y,&d);
		int imin=x-d;
		int omin=y-d;
		int imax=x+d;
		int omax=x+d;
		limitamin(&imin);
		limitamin(&omin);
		limitamax(&imax,&l);
		limitamax(&omax,&c);
		for(int i=imin;i<imax;i++){
			for(int o=omin;o<omax;o++){
				printf("%c",mar[i][o]);
				if(mar[i][o]=='.')
					saidas[ss]++;
			}
			printf("\n");
		}
	}
	for(int ss=0;ss<ns;ss++)
		printf("%d\n",saidas[ss]);
	return 0;
}

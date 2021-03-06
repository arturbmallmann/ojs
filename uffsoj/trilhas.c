#include<stdio.h>

#define N 100
#define M 1000
#define H 1000

int main(){
	int imax;

	scanf("%d",&imax);

	typedef struct{
		int col;
		int altitudes[M];
		int diff1,diff2;
		int menor;
	}trilhas;

	trilhas trilha[imax];
	int it, icol;
	for(it=0;it < imax;it++){
		scanf("%d",&trilha[it].col);
		for(icol = 0; icol < trilha[it].col; icol++)
			scanf("%d",&trilha[it].altitudes[icol]);
	}				

	int tdiff;
	trilhas * t;
	int menor=0;
	for(it=0;it < imax;it++){
		t = &trilha[it];
		t->diff1=0;
		t->diff2=0;
		for(icol = 0 ; icol < t->col - 1 ; icol++){
			tdiff = t->altitudes[icol] - t->altitudes[icol+1];
			tdiff > 0 && (t->diff1 = t->diff1 + tdiff);

			tdiff = t->altitudes[icol+1] - t->altitudes[icol];
			tdiff > 0 && (t->diff2 = t->diff2 + tdiff);
				
			}

		if(t->diff2 < t->diff1)
			t->menor = t->diff2;
		else
			t->menor = t->diff1;
		if(t->menor < trilha[menor].menor)
			menor = it;
	}

	printf("%d\n",menor+1);		
	return 0;
}

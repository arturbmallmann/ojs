#include<stdio.h>
#include<strings.h>	

void imprime_nomes(char nome[100]){
	int i;
	int FLAG=0;
	for(i=0;nome[i]!=0;i++){
		if(nome[i]>='a' && nome[i]<='z'||nome[i]>='A' && nome[i]<='Z'){
			if(FLAG++ == 2){
				putchar(nome[i-2]);
				putchar(nome[i-1]);
				putchar(nome[i]);
			}else if (FLAG>2)
				putchar(nome[i]);
		}else{
			if(FLAG!=0){
				if(FLAG>3)
					putchar('\n');
				FLAG=0;
			}
		}
	}
}


int main(){
	char entrada[100];
//	scanf("%s",entrada);//ou
	fgets(entrada,100 * sizeof(char),stdin);
	imprime_nomes(entrada);
}

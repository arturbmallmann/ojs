#include<stdio.h>
#include<string.h>
int main (){

	char texto[1000];
	printf("1 - criptografar\n2 - descriptografar\n");
	int op=0;
	scanf("%d",&op);
	if( op == 1 )
		op=3;
	else
		op=26-3;

	scanf("%s",&texto);

//	int t = strlen(texto);
	char resposta[1000];
	for(int i=0;texto[i]!='\n';i++){
		if(texto[i] >= 'a' && texto[i] <= 'z'){
			resposta[i] = (char)( texto[i] - 'a' + op) % 26 + 'a';
		}else
			resposta[i] = texto[i];
	}
	printf("%s\n",resposta);
}

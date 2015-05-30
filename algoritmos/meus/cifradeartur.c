#include<stdio.h>
#include<string.h>
int main (){

	char texto[1000];
	scanf("%s",&texto);

//	int t = strlen(texto);
	char resposta[1000];
	for(int i=0;texto[i]!='\n';i++){
		if(texto[i] >= 'a' && texto[i] <= 'z'+4){
			int deslocamento = (texto[i] - 'a')/6 * 6;
			resposta[i] = (char)( texto[i] - 'a' + 3 ) % 6 +deslocamento + 'a';
		}else
			resposta[i] = texto[i];
	}
	printf("%d: %s\n",strlen(resposta),resposta);
}

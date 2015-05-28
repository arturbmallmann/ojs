#include<stdio.h>

int main(){
	char input[500];
	fgets(input,500,stdin);
	int mod = 'z' - 'a';
	for(int i=0;input[i]!=0;i++){
		char t= input[i];
		input[i]= (t>='a' && t<= 'z' ) ? input[i]=( (t - 'a') + 2 ) % 26 + 'a' : t ;
	}
	printf("%s", input);

}

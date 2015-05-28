#include<stdio.h>

#include<strings.h>
#include<string.h>

typedef union{
	char z[3];
	struct{
		char a;
		char b;
		char c;
	};
}tupla;

char testa_letra(tupla * tuplas,char a){
	for(int i=0;tuplas[i].a!=0;i++)
		if(tuplas[i].a==a)
			return tuplas[i].b;
	return a;
}

char * troca(const char * input,tupla * tuplas){
	char * output = new char[strlen(input)];
	strcpy(output,input);
	for(int i=0;output[i]!=0;i++){
		output[i]=testa_letra(tuplas,input[i]);
	}
	return output;
}

int main(){
	tupla tuplas[4];
	strcpy(tuplas[0].z,"km");
	strcpy(tuplas[1].z,"qo");
	strcpy(tuplas[2].z,"eg");
	strcpy(tuplas[3].z,"\0\n");
	char input[500];
//	scanf("%s",&input);
	fgets(input,sizeof(char)*500,stdin);
	char * output;
	output = troca(input,tuplas);
	printf("%s\n",output);
}

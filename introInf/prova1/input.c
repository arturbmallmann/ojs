#include "prova.h"

void print_num(const num * v){
	for(int i = 0 ; i < v->size ; i++){
		printf("%x",i,v->value[i]);
	}
	putchar('\n');
}

int char_value(char chr){
	int valor = 0;
	if(chr >= '0' && chr <= '9')
			valor = chr - '0';
		else if(chr>= 'a' && chr <= 'f')
			valor = chr - 'a' + 10;
		else if(chr>= 'A' && chr <= 'F')
			valor = chr - 'A' + 10;
	return valor;
}

num * read_num(){
	char entrada[1000];
	printf("entre com algarismos hexadecimais [0-9 + a - f]\n");
	scanf("%s",entrada);
	int ts = strlen(entrada);
	int tam = ts/8 + (ts%8==0?0:1);
	u_int32 value[tam];
	memset(value,0,tam * sizeof(u_int32));
	u_int32 valor = 0;
	int inicio = (0x7ffffff8-ts) % 8;
	int f=0;
	if(char_value(entrada[0]) > 7)
		f=0xf;
	for(int i=0; i < inicio;i++){
		value[0] = value[0]|(u_int32) f << 28 - (4*i);
	}
	int shift = 0;
	f = 0;
	for(int i = 0; i < ts ; i++){
		char x = entrada[i];
		valor = char_value(x);
		shift = i % 8;
		f = tam - floor(i/8)-1;
		value[f] = value[f] | (u_int32)valor << (28 - (4*shift));
	}

	for(int i = 0 ; i < tam ; i++){
		printf("value of %d is %x\n",i,value[i]);
	}
	printf("tam %d sobrou %d \n",tam,inicio);
	num * v = newnum;
	v->size = tam;
	v->value = value;
	return v;
}


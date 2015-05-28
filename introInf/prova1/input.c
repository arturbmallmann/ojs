#include "prova.h"

void print_num(const num * v){
	printf("size of the num:%d\nvalue:",v->size);
	int tam = v->size;
	u_int32 * value= v->value;
	for(int i = 0 ; i < tam ; i++){
		printf("value of %d is %x\n",i,value[i]);
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

	u_int32 * value = newvalue;
	memset(value,0,tam * sizeof(u_int32));
	
	int des = (0x7ffffff8-ts) % 8;
	int f=0;
	if(char_value(entrada[0]) > 7)
		f=0xf;
	int cont;
	for(cont=0; cont < des;cont++){
		value[0] = value[0]|(u_int32) f << 28 - (4*cont);
	}

	int shift;
		f = 0;
	u_int32 valor = 0;
	for(int i=0; (cont-des) < ts ; cont++){
		valor = char_value(entrada[cont-des]);
		shift = cont%8;
		i=floor(cont/8);
//		printf("algarismo %d: %x\nshift:%d\n",cont,valor,shift);
		value[i] = value[i] | (u_int32) valor << (28 - (4*shift));
	}

//	for(int i = 0 ; i < tam ; i++){
//		printf("value of %d is %x\n",i,value[i]);
//	}
	num * v = newnum;
	v->size = tam;
	v->value = value;
	print_num( v );
	printf("\ntam %d sobrou\n\n",tam);
	return v;
}


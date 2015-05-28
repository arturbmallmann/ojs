#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct{
	int size;
	char * value;
} num;

num * _new (int size,char * value){
	num * v = (num *) malloc(sizeof(num));
	v->size = size;
	if(value = 0 ){
		v->value = (char *) malloc(size);
		memset(v->value, 0 , v->size);
	}
}

char sum_byte(char v1,char v2,char * cout,char cin){
    unsigned int a = v1;// 0xff;
	unsigned int b = v2;//0xff;
	unsigned int r = a + b + cin;
	char result = (char) r % 256;
	*cout = (char) (r >> 8) & 0x1 ;
	return result;
}

void print_num(const num * v){
	for( int i = 0; i < v->size; i++ )
		printf("%x\n", v->value[i]);
}

num * complete_sum(const num * v1, const num * v2,char op){
	const num * maior;
	const num * menor;

	if ( v1->size  > v2->size ){
		maior = v1;
		menor = v2;
	}else{
		maior = v2;
		menor = v1;
	}
	printf("chegou aqui\n");
	num * resultado = _new(maior->size + 1, 0);
	// op : 0 = sum, op : 1 = sub
	char cout, cin = op;

	if( op ){
		for ( int i = 0 ; i < v2->size; i++)
			v2->value[i] = ~v2->value[i]; //v2->value[i] ^ 0xff;
	}
	for ( int i = 0; i < maior->size ; i++ ){
		if ( menor->size < i )
			resultado->value[i] = sum_byte( menor->value[i], maior->value[i], &cout, cin);
		else
			resultado->value[i] = sum_byte( 0 , maior->value[i], &cout, cin );
		cin = cout;
	}
	return resultado;
}

num * sum (num * v1, num *v2){
	printf("%d", v1->size);
	return complete_sum(v1,v2,0);
}

num * sub (const num * v1, const num *v2){
	return complete_sum(v1,v2,1);
}

num * read_num(){
	char entrada[1000];
	printf("entre com algarismos hexadecimais [0-9 + a - f]\n");
	scanf("%s",entrada);
	int tam = strlen(entrada)/2 + 1;
	char value[tam];
	memset(value,0,tam);
	unsigned int valor;
	int shift = 0;
	int o = 0;
	for(int i = 0 ; i < tam ; i++){
		char x = entrada[i];
		if(x >= '0' && x <= '9')
			valor = x - '0';
		else if(x>= 'a' && x <= 'f')
			valor = x - 'a' + 10;
		else if(x>= 'A' && x <= 'F')
			valor = x - 'A' + 10;
		if( i%2 == 0 ){
			value[o] = value[o] | (unsigned int)valor*16;
			o++;
		}else
			value[o] = value[o] | (unsigned int)valor;
		printf("valor: %x byte:%x o: %d\n", valor, value[o],o);
	}
	printf("\n");
	return _new ( o+1, value);
}

int main(){
	num * a, * b;
	a = read_num();
	b = read_num();
	print_num ( a );
	print_num ( b );
//	num * resultado = sum( a , b );
//	num * resultado = complete_sum(&a, &b, 0);
//	print_num ( resultado );
}

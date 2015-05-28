#include"prova.h"

unsigned int sum_part(u_int32 v1,u_int32 v2,char * cout,char cin){
	u_int64 r = v1 + v2 + cin;
	u_int32 result = (u_int32) ((u_int64) r & 0xffffffff);
	*cout = (char) (r >> 32) & 0x1 ;
	return result;
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

	int size = maior->size + 1;
	num * resultado = newnum;
	resultado->size = size;
	resultado->value = (u_int32*)malloc(size * sizeof(u_int32));

	char cout, cin = op;

	if( op ){
		for ( int i = 0 ; i < v2->size; i++)
			v2->value[i] = ~v2->value[i]; //v2->value[i] ^ 0xff;
	}
	for ( int i = maior->size; i >= 0 ; i-- ){
	printf("chegou aqui\n");
//		if ( menor->size < i )
//			resultado->value[i] = sum_part( menor->value[i], maior->value[i], &cout, cin);
//		else
			resultado->value[i] = sum_part( 0 , maior->value[i], &cout, cin );
		cin = cout;
	}
	if(!cout) resultado->size--;
	return resultado;
}

num * sum (num * v1, num *v2){
	printf("%d", v1->size);
	return complete_sum(v1,v2,0);
}

num * sub (const num * v1, const num *v2){
	return complete_sum(v1,v2,1);
}


int main(){
	num * a, * b;
	a = read_num();
	b = read_num();
//	print_num ( a );
//	print_num ( b );
	num * resultado = sum( a , b );
//	num * resultado = complete_sum(&a, &b, 0);
	printf("resultado: ");
	print_num ( resultado );
}

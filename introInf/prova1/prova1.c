#include"prova.h"

unsigned int sum_part(u_int32 a,u_int32 b,char * cout,char cin){
    u_int64 r = (u_int64)a + (u_int64)b + cin;
    u_int32 result = ( r & 0xffffffff);
	*cout = (char)(r >> 32) & 1 ;
	printf("%x + %x + cin %d= %x cout %x\n\n",a,b,cin,result,*cout);
	return result;
}


num * complete_sum(const num * v1, const num * v2,char op){
	const num * maior;
	const num * menor;
	int diff;
	if ( (diff=v1->size - v2->size) > 0){
		maior = v1;
		menor = v2;
	}else{
		maior = v2;
		menor = v1;
	}

	int tam = maior->size;
	num * resultado = newnum;
	resultado->size = tam+1;
	resultado->value = newvalue(tam);

	char cout = 0, cin;

	if( op ){
		for ( int i = 0 ; i < v2->size; i++){
			v2->value[i] = ~v2->value[i]+1;
		}
	}
	for ( int i = tam; i >= 0 ; i-- ){
		if ( i - diff > -1)
			resultado->value[i+1] = sum_part( menor->value[i-diff], maior->value[i], &cout, cin);
		else
			resultado->value[i] = sum_part( 0 , maior->value[i], &cout, cin );
		cin = cout;
	}
	 	
	resultado->value[0] = op? 0 : cout;
	return resultado;
}

num * sum (num * v1, num *v2){
	return complete_sum(v1,v2,0);
}

num * sub (const num * v1, const num *v2){
	return complete_sum(v1,v2,1);
}

u_int32 * value_shift(const u_int32 * val, const int n,const int size){
	u_int64 aux;
	u_int32 * value = newvalue(size);
	memcpy((char*)value,(char*)val,size/8);
	//value[0]= value[0] << n;
	printf("chegou aqui %d\n",value[0]);
	for(int i = 0;i<size;i++){
		printf("%d\n",value[i]);
		aux = (u_int64) value[i] << n;
		if(i==0) printf("great part: %d\n",(aux & 0xffffffff00000000)>>32+n);
		else
			value[i-1] = (aux & 0xffffffff00000000) >> 32 + n;
		value[i] = aux & 0x00000000ffffffff;
	}
	return value;
}

num * multiplicate(const num * v1,const num * v2){
	num * result = newnum;
	result->size = v1->size + v2->size;
	result->value = newvalue(result->size);
	u_int * mask = newvalue(v2->size);
	mask [v2->size - 1 ] = 1;
//	for(int i = v2->size*8; i != 0 ; i--)
	return 0;
}

int main(){
int op=-1;
	num * resultado;
	num * a, * b;
	while(op!=0){
			printf("\n=======================================================\n");
			printf("somar..........1\nsubtrair......2\nmultiplicar....3\nshift..........4\nsair.............0[q]\n\n");
			scanf("%d",&op);
		switch (op){
			case 1:
				a = read_num();
				b = read_num();
				resultado = sum( a , b );
				break;
			case 2:
				a = read_num();
				b = read_num();
				resultado = sub( a , b );
				break;
			case 4:
				a = read_num();
				a->value = value_shift(a->value,1,a->size);
				break;
			}
			if(op) print_num ( resultado );
	}
}

#define MAX_DEGREE 101
#define MAX_TERMS 100;
typedef struct{
	int degree;
	int coef[MAX_DEGREE];
} polynomial_dense;


void print_dense(polynomial_dense p){
	int i;
	for(i=p.degree;i>0;i--){
		printf("%dx^%d +",p.coef[i],i);
	}
	printf("%d",p.coef[0]);
	printf("\n");
}

polynomial_dense* poly_dense_add(polynomial_dense p1,polynomial_dense p2){
	polynomial_dense* p3=malloc(sizeof(polynomial_dense));
	int max= p1.degree>p2.degree ? p1.degree : p2.degree;
	int i;
	p3->degree=max;
	for(i=max;i>=0;i--){
		p3->coef[i]=p1.coef[i]+p2.coef[i];
	}
	return p3;
}

typedef struct{
	int coef;
	int expon;
} polynomial_sparse;

void print_sparse(){
	
} 

polynomial_sparse* poly_sparse_add(){
}


int main(void){
	polynomial_dense p1,p2;
	polynomial_dense* ans;
	p1.degree=p2.degree=-1;
	int i;
	for(i=0;i<MAX_DEGREE;i++){
		p1.coef[i]=p2.coef[i]=0;
	}
	p1.degree=2,p1.coef[2]=3;p1.coef[1]=2; p1.coef[0]=4;
	p2.degree=4; p2.coef[4]=1; p2.coef[3]=10; p2.coef[2]=3; p2.coef[0]=1;
	
	print_dense(p1);
	print_dense(p2);
	ans=poly_dense_add(p1,p2);
	
	print_dense(*ans);
	
	return 0;
}

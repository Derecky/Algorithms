#include <stdio.h>
#include <stdlib.h>

typedef struct functions{
    double* a, *b, *c,*d;
    int size;
} Functions;

Functions* spline_cubic(double *x, double *y, int size){
    Functions* output = (Functions*) malloc(sizeof(Functions));

    output->a = (double*) malloc((sizeof(double))*(size+1));
    output->b = (double*) malloc((sizeof(double))*(size+1));
    output->c = (double*) malloc((sizeof(double))*(size+1));
    output->d = (double*) malloc((sizeof(double))*(size+1));

    output->size = size;

    double h[size];
    int i,j;
    for(i=0 ; i< size - 1 ; i++){

        h[i] = x[i+1] - x[i];
    }

    double alpha[size];
    for(i=1 ; i < size - 1; i++){

        alpha[i] = (3/(h[i]) * (y[i+1] - y[i])) -  (3/(h[i-1]) * (y[i] - y[i-1]));
    }

    double aux1[size];
    double aux2[size];
    double aux3[size];

    aux1[0] = 1;
    aux2[0] = 0;
    aux3[0] = 0;

    for(i=1 ; i < size - 1; i++){

        aux1[i] = 2*(x[i+1] - x[i-1]) - h[i-1]*aux2[i-1];
        aux2[i] = h[i]/aux1[i];
        aux3[i] = (alpha[i] - h[i-1]*aux3[i-1])/aux1[i];
    }

    aux1[size-1] = 1;
    aux3[size-1] = 0;
    output->c[size-1] = 0;

    for(j=size-2 ; j >= 0 ; j-- ){

        output->c[j] = aux3[j] - aux2[j]*output->c[j+1];
        output->b[j] = (y[j+1] - y[j])/h[j] - h[j]*(output->c[j+1] + 2*output->c[j])/3;
        output->d[j] = (output->c[j+1] - output->c[j])/(3*h[j]);
        output->a[j] = y[j];


    }
    return output;
}

void print_function( Functions *graf){
    int i;
    for(i=0 ; i<graf->size-1; i++){
        //puts("Certo ate aqui!");
        printf("%.2lfx³ + %.2lfx² + %.2lfx + %.2lf\n", graf->d[i],graf->c[i],graf->b[i],graf->a[i]);
    }
}

int main(){
    double x[3] = {1., 2., 3.};
    double y[3] = {2., 3., 5.};
    int size = 3;

    Functions *teste = spline_cubic(x, y, size);

    print_function(teste);

    return 0;
}


#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int longitud(int); 
int maxi(int, int); 
int karatsuba(int, int);
int main(){
    int x = -2501;
    int y = 4786;
    printf("%d", karatsuba(x,y));
    return 0;
}

int karatsuba(int x, int y){
    int lenX = longitud(x);
    int lenY = longitud(y);

    int n = maxi(lenX,lenY);
    int m = ceil(n/2.0);
    double p = pow(10,m);

    int a = x/(int)p;
    int b = x%(int)p;
    int c = y/(int)p;
    int d = y%(int)p;

    if ( n == 1 ) return x * y;

    int ac = karatsuba(a,c);
    int bd = karatsuba(b,d);

    int abcd = karatsuba(a + b, c + d) - ac - bd;
    return  ac * pow(10, 2 * m) + abcd * p + bd;

}

int maxi(int x, int y){
    return (x > y) ? x : y;
}
int longitud(int x){
    return log10(abs(x)) + 1;
}

#include <stdio.h>
#include <math.h>

double MyPower(double, int);

int main(void){
    double base;
    int exponent;
    printf("Gimme two numbers: ");
    scanf("%lf %d", &base, &exponent);
    double result  = MyPower(base, exponent);
    printf("Result: %lf", result);
    return 0;
}

double MyPower(double base, int exponent){
    double total = 1;
    while(exponent != 0){
        total *= base;
        --exponent;
    }
    return total;
}

#include <stdio.h>
#include <math.h>

double MyPower(double, int);
void DoTest(double, int);

int main(void){
    int i, j;
    for(i = 1; i < 5; i++){
        for(j = 1; i < 5; i++){
            DoTest(i, j);
        }
    }
    double power = MyPower(i, j);
    printf("%ld\n", power);
    return 0;
}

double MyPower(double base, int exponent){
    for(int i = 0; i < exponent; i++){
        base * base;
    }
    return base;
}

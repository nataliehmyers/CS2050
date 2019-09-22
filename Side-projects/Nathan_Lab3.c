#include <stdio.h>

int x_error_check(int);
int y_error_check(int);

int main(void){
    int x, y, check_x, check_y;
    printf("Please enter two positive integers that are less than 10:\n");
    scanf("%d %d", &x, &y);

    printf("x=%d y=%d", x, y);

    return 0;
}

#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <math.h>
#include  <Windows.h>
#define eps 0.000001

double f( double x );
void print_result(double a, double b, unsigned int n, double I );
double left_rectangle_method( double a, double b, unsigned int n );
double right_rectangle_method( double a, double b, unsigned int n );
double trapezoid_method( double a, double b, unsigned int n );
double simpson_method( double a, double b, unsigned int n );

double h,x;

int main() {

    SetConsoleCP (65001);
    SetConsoleOutputCP (65001);

    unsigned int n=10000, N = 0, choose;
    double const a = 1, b = 3;
    double I, I1, I2;
    h = ( b - a ) / n;

    printf("\n\n Виберіть свій метод:\n1 - лівих трикутників \n2 - правих трикутників \n3 - трапеції \n4 - Сімпсона\n>");
    scanf("%u", &choose);

    while(  choose < 1  ||   choose > 4 ) {
        printf("\nНеправильні дані, введіть 1,2,3 або 4:");
        scanf("%u", &choose);
    }

    switch(choose) {
        case(1):

            printf("\nВи вибрали метод лівих трикутніків");
            I = left_rectangle_method(a, b, n);
            print_result(a, b, n, I);

            do{
                N = N + 2;
                I1 = left_rectangle_method(a, b, N);
                I2 = left_rectangle_method(a, b, N+2);
            }while(  fabs(I2-I1) > eps );

            printf("\n\nN=%u,  I1(N)=%.8lf\n", N, I1);

            break;

        case(2):

            printf("\nВи вибрали метод правих трикутніків");
            I=right_rectangle_method(a, b, n);
            print_result(a, b, n, I);

            do{
                N = N + 2;
                I1 = right_rectangle_method(a, b, N);
                I2 = right_rectangle_method(a, b, N+2);
            }while(  fabs(I2-I1) > eps );

            printf("\n\nN=%u,  I1(N)=%.8lf\n", N, I1);

            break;

        case(3):

            printf("\nВи вибрали метод трапеції");
            I=trapezoid_method(a, b, n);
            print_result(a, b, n, I);

            do{
                N = N + 2;
                I1 = left_rectangle_method(a, b, N);
                I2 = left_rectangle_method(a, b, N+2);
            }while(  fabs(I2-I1) > eps );

            printf("\n\nN=%u,  I1(N)=%.8lf\n", N, I1);

            break;

        case(4):

            printf("\nВи вибрали метод Сімпсона");
            I=simpson_method(a, b, n);
            print_result(a, b, n, I);

            do{
                N = N + 2;
                I1 = left_rectangle_method(a, b, N);
                I2 = left_rectangle_method(a, b, N+2);
            } while(  fabs(I2-I1) > eps );

            printf("\n\nN=%u,  I1(N)=%.8lf\n", N, I1);

            break;
    }

    return 0;
}

//===============================================================

double left_rectangle_method(double a, double b, unsigned int n) {

    double sum = 0;

    x = a;

    for (int k = 0;  k <= n-1;  k++) {
        sum = sum + f(x);
        x = x + h;
    }

    return sum * h;
}

//===============================================================

double right_rectangle_method(double a, double b, unsigned int n) {

    unsigned int k;
    double sum = 0;

    x = a;

    for (k = 1;  k <= n;  k++ ) {
        sum = sum + f(x);
        x = x + h;
    }

    return sum * h;
}

//===============================================================

double trapezoid_method(double a, double b, unsigned int n) {

    unsigned int k;
    double sum = 0;

    x = a;

    for (k = 0;  k <= n-1;  k++ ) {
        sum = sum + (f(x)+f(x + h))/2;
        x = x + h;
    }

    return sum * h;
}

//===============================================================

double simpson_method(double a, double b, unsigned int n) {

    double I=0;
    x = a + h;

    while (x < b) {
        I += 4*f(x);
        x += h;
        if (x >= b) {
            I += 2*f(x);
            x += h;
        }
    }
    I = (h / 3) * (I + f(a) + f(b));

    return I * h;
}

//===============================================================

double f( double x ) {
    double y;
    y = 1/2*pow(x,2) + (3*x) - 2;
    return y;
}

//===============================================================

void print_result(double a, double b, unsigned int n, double I) {

    system("cls");
    printf("\n+=====================+");
    printf("\n+     Результати      +");
    printf("\n+=====================+\n");

    printf("a=%.2lf  b=%.2lf   n=%u    I = %.8lf", a, b, n, I);
}

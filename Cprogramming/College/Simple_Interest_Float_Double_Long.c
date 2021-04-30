<<<<<<< HEAD
    
#include <stdio.h>
void main()
{
    float p1, t1, r1, SI1;
    double p2, t2, r2, SI2;
    long double p3, t3, r3, SI3;

    printf("Enter the float integer priciple: ");
    scanf("%f", &p1);
    printf("Enter the float integer time: ");
    scanf("%f", &t1);
    printf("Enter the float integer rate: ");
    scanf("%f", &r1);
    SI1= p1*t1*r1/100;
    printf("The float Simple Interest is: %f", SI1);


    printf("\nEnter the double float integer priciple: ");
    scanf("%lf", &p2);
    printf("Enter the double float integer time: ");
    scanf("%lf", &t2);
    printf("Enter the double float integer rate: ");
    scanf("%lf", &r2);
    SI2= p2*t2*r2/100;
    printf("The double float Simple Interest is: %lf", SI2);


    printf("\nEnter the long double integer priciple: ");
    scanf("%Lf", &p3);
    printf("Enter the long doule integer time: ");
    scanf("%Lf", &t3);
    printf("Enter the long double integer rate: ");
    scanf("%Lf", &r3);
    SI3= p3*t3*r3/100;
    printf("The long double Simple Interest is: %Lf", SI3);
=======
    
#include <stdio.h>
void main()
{
    float p1, t1, r1, SI1;
    double p2, t2, r2, SI2;
    long double p3, t3, r3, SI3;

    printf("Enter the float integer priciple: ");
    scanf("%f", &p1);
    printf("Enter the float integer time: ");
    scanf("%f", &t1);
    printf("Enter the float integer rate: ");
    scanf("%f", &r1);
    SI1= p1*t1*r1/100;
    printf("The float Simple Interest is: %f", SI1);


    printf("\nEnter the double float integer priciple: ");
    scanf("%lf", &p2);
    printf("Enter the double float integer time: ");
    scanf("%lf", &t2);
    printf("Enter the double float integer rate: ");
    scanf("%lf", &r2);
    SI2= p2*t2*r2/100;
    printf("The double float Simple Interest is: %lf", SI2);


    printf("\nEnter the long double integer priciple: ");
    scanf("%Lf", &p3);
    printf("Enter the long doule integer time: ");
    scanf("%Lf", &t3);
    printf("Enter the long double integer rate: ");
    scanf("%Lf", &r3);
    SI3= p3*t3*r3/100;
    printf("The long double Simple Interest is: %Lf", SI3);
>>>>>>> 31a0cd55077ad1ba304e75cb49a460b4e3e75082
}
#include <stdio.h>
void main()
{
    int P;
    int T;
    int R;
    int SI;
    printf("Enter the principle:");
    scanf("%d",&P);
    printf("Enter the time:");
    scanf("%d",&T);
    printf("Enter the rate:");
    scanf("%d",&R);
    SI= P*T*R/100;
    printf("The Simple Interest is %d",SI);
}


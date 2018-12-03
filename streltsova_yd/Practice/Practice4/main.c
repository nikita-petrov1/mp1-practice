#include <stdio.h>
#define N 9999
#define L 10
void main()
{
    int mode, sum = 0, sum_dis = 0;
    long int num, i;
    char goods[N][L] = {"Chocolate", "Bread", "Pasta", "Milk", "Cheese", "Apples", "Fish", "Meat", "Biscuits", "Juice"};
    int price[N] = {57, 20, 48, 42, 87, 30, 96, 110, 75, 65};
    float discount[N] = {15, 3, 5, 4, 25, 10, 30, 35, 17, 8};
    int count[N] = {0};
    printf ("Electronic cash register\n");
    printf ("Select an operation. To select the operation, enter:\n");
    printf("1 - scan the product\n");
    printf("2 - display the product description\n");
    printf("3 - add product data to the check\n");
    printf("4 - generate a check for the purchase\n");
    printf("5 - calculate the total amount to be paid\n");
    do
    {
        do 
        {
            scanf ("%d", &mode);
        }while ((mode != 1) && (mode != 2) && (mode != 3) && (mode != 4) && (mode != 5));
        if (mode == 1)
        {
            do
            {
                scanf ("%ld", &num);
            }while ((num < 1) || (num > 9999));
        }
        if (mode == 2)
        {
            printf ("Goods - ");
            for (i = 0; i < L; i++)
                printf( "%c", goods[num - 1][i]);
            printf ("\n");
            printf ("Price - %d\n", price[num - 1]);
            printf ("Discount - %f\n", discount[num - 1]);
        }
        if (mode == 3)
        {
            count[num - 1]++;
            printf ("Item added to check\n");
        }
        if (mode == 4)
        {
             printf ("Goods     Price per 1     Count     Total cost\n");
            for (i = 0; i < N; i++)
                if (count[i] != 0)
                {
                    for (num = 0; num < L; num++)
                        printf ("%c", goods[i][num]);
                    printf ( "  %d              %d          %d\n", price[i], count[i], price[i] * count[i]);
                    sum += price[i] * count[i];
                    sum_dis += count[i] * price[i] * (discount[i] / 100);
                }
                printf ("Total cost - %d\n", sum);
                printf ("Total discount - %d\n", sum_dis);
                printf ("Final amount - %d\n", sum - sum_dis);
        }
        if (mode == 5)
            printf ("Final amount - %d\n", sum - sum_dis);
    }while (mode !=5); 
}
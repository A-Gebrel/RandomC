#include <stdio.h>

void listItems()
{
    printf("Items list:\n1. Apple\t $1.00\n2. Banana\t $1.50\n3. Orange\t $2.00\n4. Salad\t $3.00\n5. Quit\n");
}

void showSelected(int choice)
{
    switch(choice)
    {
        case 1: printf("You have selected Apple.\n"); break;
        case 2: printf("You have selected Banana.\n"); break;
        case 3: printf("You have selected Orange.\n"); break;
        case 4: printf("You have selected Salad.\n"); break;
        default: printf("Incorrect Input!\n");
    }
}

float readMoney()
{
    float x;
    printf("Please enter your cash: ");
    scanf("%f", &x);
    return x;

}

int main()
{
    int choice, amount;
    float priceList[4] = {1.00, 1.50, 2.00, 3.00};
    float output[4][2];
    float total;
    float cash;
    float remainingCash;
    for(int i=0; i<4; i++)
    {
        output[i][0] = 0;
        output[i][1] = 0;
    }
    while(1==1)
    {
        printf("MENU:\n\n");
        listItems();
        printf("Please enter your selection:");
        scanf("%i", &choice);
        if(choice >= 1 && <6)
        {
            showSelected(choice);
            printf("Please enter how many you need?");
            scanf("%i", &amount);
            output[choice-1][0] += amount;
            output[choice-1][1] += amount*priceList[choice-1];
            total += amount*priceList[choice-1];
        }
        else
        {
            printf("Please enter a valid choice!\n");
        }

    }
    cash = readMoney();
    if(cash < total)
    {
        printf("Not enough money!");
    }
    else
    {
        FILE *fp;
       fp = fopen("output.txt", "w+");
       fprintf(fp, "Item\tPrice\t\tQuantity\t\tTotal\tPaid Money\tRemaining Money\n");
       fprintf(fp, "___________________________________________________________\n");
       for(int i=0; i<4; i++)
       {
           if(output[i][0] > 0)
           {
               if(i == 0) { fprintf(fp, "%s", "Apple"); }
               if(i == 1) { fprintf(fp, "%s", "Banana"); }
               if(i == 2) { fprintf(fp, "%s", "Orange"); }
               if(i == 3) { fprintf(fp, "%s", "Salad"); }
               fprintf(fp, "\t%0.2f\t\t%0.2f\t\t%0.2f\t", priceList[i], output[i][0], output[i][1]);
               fprintf(fp, "\n");
           }
       }
       fprintf(fp, "\t\t\t\t\t\t\t\t\t\t\t\t%0.2f\t%0.2f", cash, cash-total);
       fclose(fp);
    }
    return 0;
}

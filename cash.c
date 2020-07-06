// Ask user how much change is owed and then 
// prints the minimum number of coins with which that change can be made.

#include <cs50.h>
#include <stdio.h>
#include <math.h>

int main(void)
{
    float dollars;

    // Check user input within range 0-1    
    do
    {
        dollars = get_float("Change owed: ");
    }
    while (dollars <= 0);

    int cents = round(dollars * 100);
    int coins = 0, x;
    
    // Greedy algorithm to find optimal number of coins
    // Find number of quarters
    if (cents >= 25)
    {
        x = round(cents / 25);
        cents = cents - x * 25;
        coins += x;
    }
    
    // Find number of dimes and update coins
    if (cents >= 10)
    {
        x = round(cents / 10);
        cents = cents - x * 10;
        coins += x;
    }
    
    //Find number of nickels and update coins
    if (cents >= 5)
    {
        x = round(cents / 5);
        cents = cents - x * 5;
        coins += x;
    }
    
    //Find number of pennies and update coins
    if (cents >= 1)
    {
        coins += cents;
    }    
    
    printf("%i", coins);
    printf("\n");

}

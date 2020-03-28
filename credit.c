#include <cs50.h>
#include <stdio.h>
#include <math.h>

int sum_of_other_digits(double card, int n, int total);
double divide_by_power(double card, int n);
int find_first_digits(double card, double value, int precision);

int main(void)
{
    double card = get_long("Number: ");
    int total = 0;
    total = (sum_of_other_digits(card, 1, total));
    total = sum_of_other_digits(card, 0, total);
    if (total % 10 == 0)
    {
        if ((find_first_digits(card, pow(10, 15), 10) == 4) || (find_first_digits(card, pow(10, 12), 10) == 4))
        {
            printf("VISA\n");
        }
        else if ((find_first_digits(card, pow(10, 13), 100) == 34) || (find_first_digits(card, pow(10, 13), 100) == 37))
        {
            printf("AMEX\n"); 
        }
        else if ((find_first_digits(card, pow(10, 14), 100) >= 51) && (find_first_digits(card, pow(10, 14), 100) <= 55))
        {
            printf("MASTERCARD\n"); 
        }
        else
        {
            printf("INVALID\n");
        }
    }
    else
    {
        printf("INVALID\n");
    }
}

// Sum of every other digit
int sum_of_other_digits(double card, int n, int total)
{
    double i = divide_by_power(card, n);
    while (i >= 1)
    {
        if ((fmod(i, 10) >= 5) && (n % 2 == 1))
        {
            int j = fmod(i, 10);
            total +=  fmod(2 * j, 10) + fmod(divide_by_power(2 * j, 1), 10);
            n += 2;
            i = divide_by_power(card, n);
        }
        else
        {
            if (n % 2 == 1)
            {
                int j = fmod(i, 10);
                total += 2 * j;
            }
            else
            {
                int j = fmod(i, 10);
                total += j;
            }
            n += 2;
            i = divide_by_power(card, n);
        }
    }
    return total;
}

// Divides by a power of 10
double divide_by_power(double card, int n)
{
    return card / (pow(10, n));
}

// Finds first digits
int find_first_digits(double card, double value, int precision)
{
    double i = card / value;
    int j = fmod(i, precision);
    return j;
}
    

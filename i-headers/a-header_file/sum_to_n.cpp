#include "sum_to_n.h"
int total_val = 0;

int sum_to_n(int n)
{
    total_val++;

    int sum = 0;
    for (size_t i = 1; i <= n; i++)
    {
        sum += i;
    }
    return sum;
}
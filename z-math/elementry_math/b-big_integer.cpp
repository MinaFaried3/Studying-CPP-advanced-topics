#include <iostream>
#include <sstream>
#include <string>
#include <algorithm>
using namespace std;

#define all(v) ((v).begin()), ((v).end())
#define sz(v) ((int)((v).size()))
#define clr(v, d) memset(v, d, sizeof(v))

const int MAX = 300;
typedef int big[MAX];

void big_zero(big num) // b = 0
{
    int i;
    for (i = 0; i < MAX; i++)
        num[i] = 0;
}

void big_copy(big to, big from) // to <-- from
{
    int i;
    for (i = 0; i < MAX; i++)
        to[i] = from[i];
}

int big_len(big num)
{
    int j;
    for (j = MAX - 1; j && !num[j]; j--)
        ;
    return j;
}

void big_print(big num)
{
    int i;
    for (i = big_len(num); i >= 0; i--)
    {
        cout << num[i];
        if (i && !(i % 3))
            cout << ',';
    }
    cout << "\n";
}

void big_from_str(big num, string str) // num = reverse(str)
{
    int i, len = str.size() - 1;
    big_zero(num);

    for (i = len; i > -1; i--)
        num[len - i] = str[i] - '0';
} // 153-->153  00153-->153

string bit_to_str(big num)
{
    ostringstream oss;
    for (int i = big_len(num); i >= 0; i--)
        oss << num[i];
    return oss.str();
}

void big_from_int(big num, int x)
{
    int len = 0;
    big_zero(num);

    while (x)
    {
        num[len++] = x % 10;
        x /= 10;
    }
}

int big_cmp(big a, big b) // a <=> b return 1, 0, -1
{
    int i;
    for (i = MAX - 1; i >= 0; i--)
    {
        if (a[i] > b[i])
            return 1;
        else if (a[i] < b[i])
            return -1;
    }
    return 0;
}

void big_add(big ac, int n) // add n over a
{
    int i, num, carry = n;
    for (i = 0; i < MAX && carry; i++)
    {
        num = ac[i] + carry;
        ac[i] = num % 10;
        carry = num / 10;
    }
}

void big_add(big a, big b, big result) // result = a + b
{
    int i, carry = 0;
    for (i = 0; i < MAX; i++)
    {
        result[i] = carry + a[i] + b[i];
        carry = result[i] / 10;
        result[i] %= 10;
    }
}

char big_sub(big a, big b, big result, char sign = '+')
{
    if (big_cmp(a, b) < 0)
        return big_sub(b, a, result, '-');

    big_zero(result);
    int len_a = big_len(a);
    int len_b = big_len(b);

    int i, max = len_a > len_b ? len_a : len_b;

    for (i = 0; i <= max; i++)
        result[i] = a[i] - b[i];

    for (i = 0; i <= max; i++)
    {
        while (result[i] < 0)
        {
            result[i] += 10;
            result[i + 1] -= 1;
        }
    }
    return sign;
}

void big_product(big result, int factor)
{
    int carry = 0;
    for (int i = 0; i < MAX; i++)
    {
        carry += result[i] * factor;
        result[i] = carry % 10;
        carry /= 10;
    }
}
// Work with leading zeros
void big_product(big a, big b, big result)
{
    int len_a = big_len(a);
    int len_b = big_len(b);

    if (len_a < len_b)
    {
        big_product(b, a, result);
        return;
    }

    big_zero(result);
    int i, j;

    int cursor = 0, pos = 0;

    for (i = 0; i <= len_b; pos = 0, cursor++, i++)
    {
        for (j = 0; j <= len_a; j++, pos++)
        {
            result[pos + cursor] += b[i] * a[j];

            if (result[pos + cursor] >= 10)
            {
                result[pos + cursor + 1] += result[pos + cursor] / 10;
                result[pos + cursor] %= 10;
            }
        }
    }
}

int big_divide(big ac, int div)
{
    int i = big_len(ac);
    int reminder = 0;

    while (i >= 0)
    {
        reminder = reminder * 10;
        reminder = reminder + ac[i];
        ac[i] = 0;

        if (div <= reminder)
        {
            ac[i] = reminder / div;
            reminder %= div;
        }
        i--;
    }
    return reminder;
}

void big_divide(big ac, big div, big reminder)
{
    big cpy;
    big_zero(reminder);

    int i = big_len(ac);

    while (i >= 0)
    {
        big_product(reminder, 10);
        big_add(reminder, ac[i]);
        ac[i] = 0;

        while (big_cmp(reminder, div) >= 0) // Insted of /, % is >= right or only >
        {
            big_sub(reminder, div, cpy); // cpy = reminder-div
            big_copy(reminder, cpy);     // reminder = cpy
            ac[i]++;
        }
        i--;
    }
    big_print(reminder);
    big_print(ac);
}

void big_mod(big a, big div, big reminder)
{
    big cpy;
    big_zero(reminder);

    int i = big_len(a);

    while (i >= 0)
    {
        big_product(reminder, 10);
        big_add(reminder, a[i]);

        while (big_cmp(reminder, div) >= 0) // Insted of /, %
        {
            big_sub(reminder, div, cpy); // cpy = reminder-div
            big_copy(reminder, cpy);     // reminder = cpy
        }
        i--;
    }
}

void big_gcd(big ac, big bc) // ac: means big a will be changed
{
    big t;

    while (!(bc[0] == 0 && big_len(bc) == 0))
    {
        big_mod(ac, bc, t); // t = a % b
        big_copy(ac, bc);   // a = b
        big_copy(bc, t);    // b = t
    }                       // a now represent the gcd
}

void factorial(int n, big fact) /* Fast untill !1200 */
{
    int i, j, len;

    big_zero(fact);
    fact[0] = 1, len = 1;

    for (i = 2; i <= n; i++)
    {
        for (j = 0; j < len; j++)
            fact[j] *= i;

        for (j = 0; j < len; j++)
        {
            if (fact[j] >= 10)
                fact[j + 1] += fact[j] / 10, fact[j] %= 10;
        }

        while (fact[len])
            if (fact[len++] >= 10)
                fact[len] += fact[len - 1] / 10, fact[len - 1] %= 10;
    }
}

big remain, odd, answer, temp; // Set them out side to save memory
void big_squareRoot(string s)  // Using Pell's equation // TLE
{
    long int group, count;

    big_zero(remain);
    big_zero(odd);
    big_zero(answer);

    if (s.size() % 2 == 1)
        s = "0" + s;

    for (int i = 0; i < s.size(); i += 2)
    {
        group = (s[i] - '0') * 10 + s[i + 1] - '0';

        big_copy(odd, answer);
        big_product(odd, 20);
        big_add(odd, 1);

        big_product(remain, 100);
        big_add(remain, group);

        count = 0;
        while (big_cmp(remain, odd) >= 0)
        {
            count++;
            big_sub(remain, odd, temp);
            big_copy(remain, temp);
            big_add(odd, 2);
        }
        big_product(answer, 10);
        big_add(answer, count);
    }
    big_print(answer); // Contain only the int value //Give TLE
}

string big_to_str(big num)
{
    ostringstream oss;
    int i;
    for (i = big_len(num); i >= 0; i--)
    {
        oss << num[i];
    }
    return oss.str();
}

string toBinay(string str)
{
    big a;
    big_from_str(a, str);

    big zero;
    big_from_int(zero, 0);

    big two;
    big_from_int(two, 2);

    big mod;
    string ret = "";

    while (big_cmp(a, zero) != 0)
    {
        big_mod(a, two, mod);
        ret += big_to_str(mod);
        big_divide(a, 2);
    }

    reverse(all(ret));
    return ret;
}

string toDecimal(string binary)
{
    big twoPow;
    big_from_int(twoPow, 1);

    big a;
    big_zero(a);

    big temp;
    for (int i = sz(binary) - 1; i >= 0; --i)
    {
        if (binary[i] == '1')
        {
            big_add(a, twoPow, temp);
            big_copy(a, temp);
        }

        big_product(twoPow, 2);
    }
    return big_to_str(a);
}

string fibonaccie(int n)
{
    int fib[3][MAX];

    big_from_int(fib[0], 1);
    big_from_int(fib[1], 1);
    big_from_int(fib[2], 1);

    for (int i = 2; i < n; i++)
    {
        big_add(fib[0], fib[1], fib[2]);
        big_copy(fib[0], fib[1]);
        big_copy(fib[1], fib[2]);
    }
    return bit_to_str(fib[2]);
}

int main()
{
    string num1, num2;
    big a, b, c;

    while (cin >> num1 >> num2)
    {
        big_from_str(a, num1);
        big_from_str(b, num2);

        big_product(a, b, c);
        big_print(c);
    }
    return 0;
}
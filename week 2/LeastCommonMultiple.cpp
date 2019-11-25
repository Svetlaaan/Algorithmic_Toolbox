#include <iostream>

long long    gcd(long long a, long long b)
{
    long long c;
    while (b)
    {
        c = a % b;
        a = b;
        b = c;
    }
    return ((a < 0) ? -a : a);
}

long long    nok(long long a, long long b)
{
    long long res;
    long long num_gcd;

    if (!a || !b)
        return 0;
    if (a % b == 0)
        return a;
    else
        {
            num_gcd = gcd(a, b);
            res = (a*b)/num_gcd;
        }
    return res;
}

int main() {
    long long a, b;
    std::cin >> a >> b;
    std::cout << nok(a, b) << std::endl;
    return 0;
}
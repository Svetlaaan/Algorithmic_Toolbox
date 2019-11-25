#include <iostream>
#include <vector>

using std::cin;
using std::cout;
using std::vector;

long long pisano(long long n, long long m)
{
    long long i;
    if (m == 1)
        return 0;
    vector<long long> numbers(m * 6);
    numbers[0] = 0;
    numbers[1] = 1;
    long period_len = 0;
    for ( i = 2; i < m * 6; ++i)
    {
        numbers[i] = (numbers[i - 1] + numbers[i - 2]) % m;
        period_len++;
        if (numbers[i] == 1 && numbers[i - 1] == 0)
            break;
    }
    long long pos = n % period_len;
    return numbers[pos];
}

int main()
{
    long long n,m;
    cin >> n >> m;
    std::cout << pisano(n,m) << '\n';
    return 0;
}

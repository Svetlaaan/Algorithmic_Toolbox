#include <iostream>
#include <vector>

using std::vector;
using std::cin;
using std::cout;

int fibonacci_fast(int n)
{
    int res = 0;
    int i = 1;
    if (n >= 0 && n <= 45)
    {
        vector<int> numbers(n + 1);
        if (n == 1)
            return 1;
        numbers[0] = 0;
        numbers[1] = 1;
        for (i = 2; i <= n; ++i)
        {
            numbers[i] = numbers[i - 1] + numbers[i - 2];
            res = numbers[i];
        }
    }
    else
        return 0;
    return res;
}

int main()
{
    int n;
    cin >> n;
    std::cout << fibonacci_fast(n) << '\n';
    return 0;
}

#include <iostream>
#include <cassert>
#include <vector>

using std::vector;

long long binary_search(const vector<long long> &a, long long x)
{
    long long left = 0, right = (long long)a.size();
    long long mid = 0;
    while (left <= right)
    {
       mid = ((right - 1 - left)/2) + left;
       if (a[mid] == x)
           return (mid);
       else if (a[mid] > x)
           right = mid - 1;
       else
           left = mid + 1;
    }
    return (-1);
}

int main() {
    long long n;
    std::cin >> n;
    if (n < 1 || n > 30000)
        return (-1);
    vector<long long> a(n);
    for (size_t i = 0; i < a.size(); i++)
        std::cin >> a[i];
    long long m;
    std::cin >> m;
    if (m < 1 || m > 100000)
        return (-1);
    vector<long long> b(m);
    for (long long i = 0; i < m; ++i)
        std::cin >> b[i];
    for (long long i = 0; i < m; ++i)
        std::cout << binary_search(a, b[i]) << ' ';
}

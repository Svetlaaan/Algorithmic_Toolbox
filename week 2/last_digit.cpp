#include <iostream>
#include <cmath>

using std::cin;
using std::cout;
using std::pow;
using std::sqrt;

long long fibonacci_last_digit(long long n) {
    return (pow((1 + sqrt(5)) / 2 , n) - pow((1 - sqrt(5)) / 2 , n)) / sqrt(5);
}

long long last_number(long long n) {
    return fibonacci_last_digit(n % 60) % 10;
}

int main()
{
    long long n;
    cin >> n;
    std::cout << last_number(n) << '\n';
    return 0;
}

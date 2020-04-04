#include <algorithm>
#include <iostream>
#include <vector>

using std::vector;

// Сортируем оба массива по возрастанию, попробуем пузырьковую сортировку

long long max_dot_product(vector<int> a, vector<int> b, size_t n)
{
    long long result = 0;

    for (size_t i = 0; i < n; i++) {
        for (size_t j = 0; j < n - 1; j++) {
            if (a[j] > a[j + 1]) {
                int tmp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = tmp;
            }
        }
    }
    for (size_t i = 0; i < n; i++) {
        for (size_t j = 0; j < n - 1; j++) {
            if (b[j] > b[j + 1]) {
                int tmp = b[j];
                b[j] = b[j + 1];
                b[j + 1] = tmp;
            }
        }
    }
    for (size_t i = 0; i < a.size(); i++)
    {
        result += ((long long) a[i]) * b[i];
    }
    return result;
}

int main() {
    size_t n;
    std::cin >> n;
    vector<int> a(n), b(n);
    for (size_t i = 0; i < n; i++) {
        std::cin >> a[i];
    }
    for (size_t i = 0; i < n; i++) {
        std::cin >> b[i];
    }
    std::cout << max_dot_product(a, b, n) << std::endl;
}


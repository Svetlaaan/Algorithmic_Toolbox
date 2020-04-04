#include <iostream>
#include <vector>

using std::vector;

int get_majority_element(vector<long> &a, int left, int right)
{
    if (left == right)
        return -1;
    if (left + 1 == right)
        return a[left];

    int leftem = get_majority_element(a, left, (left + right - 1) / 2 + 1);
    int rightem = get_majority_element(a, (left + right - 1) / 2 + 1, right);

    int l_count = 0;
    for (int i = left; i < right; i++)
    {
        if (a[i] == leftem)
            l_count += 1;
    }
    if (l_count > (right - left) / 2)
        return leftem;
    int r_count = 0;
    for (int i = left; i < right; i++)
    {
        if (a[i] == rightem)
            r_count += 1;
    }
    if (r_count > (right - left) / 2)
        return rightem;
    return -1;
}

int main()
{
    int n;

    std::cin >> n;
    if (n < 1 || n > 100000)
        return (-1);
    vector<long> a(n);
    for (size_t i = 0; i < a.size(); ++i)
        std::cin >> a[i];
    std::cout << (get_majority_element(a, 0, a.size()) != -1) << '\n';
}

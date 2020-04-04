#include <iostream>
#include <vector>
#include <cstdlib>

using namespace std;

vector<int> partition3(vector<long> &a, int l, int r)
{
    vector<int> ret(2);
    int i = l + 1;
    int x = a[l];
    ret[0] = l;
    ret[1] = r;
    while (i <= ret[1]) {
        if (a[i] < x) {
            swap(a[i], a[ret[0]]);
            ret[0] += 1;
            i += 1;
        } else if (a[i] > x) {
            swap(a[i], a[ret[1]]);
            ret[1] -= 1;
        } else
            i += 1;
    }
    return ret;
}
//    for (int i = l + 1; i <= r; i++)
//    {
//        if (a[i] <= x)
//        {
//            ret[0]++;
//            swap(a[i], a[ret[0]]);
//        }
//    }
//    swap(a[l], a[ret[0]]);
//    ret[1] = ret[0] - 1;
//    for (int i = l; i < ret[0] && ret[1] >= l && ret[1] > i; i++)
//        if (a[ret[0]] == a[i])
//            swap(a[i], a[ret[1]--]);
//    ret[1]++;
//    return ret;

void randomized_quick_sort(vector<long> &a, int l, int r)
{
    if (l >= r)
        return;
    int k = l + rand() % (r - l + 1);
    swap(a[l], a[k]);
    vector<int> z(2);

    while (l < r)
    {
        z = partition3(a, l, r);
        if (z[0] - l < r - z[1])
        {
            randomized_quick_sort(a, l, z[0] - 1);
            l = z[1] + 1;
        }
        else
        {
            randomized_quick_sort(a, z[1] + 1, r);
            r = z[0] - 1;
        }
    }
//    randomized_quick_sort(a, l, z[0] - 1);
//    randomized_quick_sort(a, z[1] + 1, r);
}

int main()
{
    int n;
    std::cin >> n;
    if (n < 1 || n > 100000)
        return (-1);
    vector<long> a(n);
    for (size_t i = 0; i < a.size(); ++i)
    {
        std::cin >> a[i];
        if (a[i] < 1 || a[i] > 1000000000)
            return (-1);
    }
    randomized_quick_sort(a, 0, a.size() - 1);
    for (size_t i = 0; i < a.size(); ++i)
        std::cout << a[i] << ' ';
}
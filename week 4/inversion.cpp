#include <iostream>
#include <vector>

using namespace std;

long long merge(vector<int> &a, vector<int> &b, size_t left, size_t mid, size_t right)
{
    size_t i = left, j = mid, k = left;
    long long inv_count = 0;
    while (i <= mid - 1 && j <= right)
    {
        if (a[i] <= a[j])
        {
            b[k] = a[i];
            i++;
        }
        else
            {
            b[k] = a[j];
            inv_count += mid - i;
            j++;
        }
        k++;
    }
    while (i <= mid - 1)
    {
        b[k] = a[i];
        i++;
        k++;
    }
    while (j <= right)
    {
        b[k] = a[j];
        j++;
        k++;
    }
    for (i = left; i <= right; i++)
        a[i] = b[i];
    return inv_count;
}

long long get_number_of_inversions(vector<int> &a, vector<int> &b, size_t left, size_t right)
{
    long long number_of_inversions = 0;
    if (right <= left + 1)
        return number_of_inversions;
    size_t mid = left + (right - left) / 2;
    number_of_inversions += get_number_of_inversions(a, b, left, mid); // count nmbr of inversions in left part
    number_of_inversions += get_number_of_inversions(a, b, mid, right); // count nmbr of inversions in right part
    number_of_inversions += merge(a, b, left, mid + 1, right);
    return number_of_inversions;
}

int main()
{
    int n;
    std::cin >> n;
    vector<int> a(n);
    for (size_t i = 0; i < a.size(); i++)
        std::cin >> a[i];
    vector<int> b(a.size()); // empty
    std::cout << get_number_of_inversions(a, b, 0, a.size()) << '\n';
}

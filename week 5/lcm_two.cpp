#include <iostream>
#include <vector>

using namespace std;

int lcs2(vector<int> &a, vector<int> &b) {
    int m = a.size();
    int n = b.size();
    int L[m + 1][n + 1];
    int i, j = 0;

    for (i = 0; i <= m; i++) {
        for (j = 0; j <= n; j++) {
                if (i == 0 || j == 0)
                    L[i][j] = 0;
                else if (a[i - 1] == b[j - 1])
                    L[i][j] = L[i - 1][j - 1] + 1;
                else
                    L[i][j] = max(L[i - 1][j], L[i][j - 1]);
        }
    }
    return L[m][n];
//    int seq = 0;
//    int j = 0;
//
//    for (int i = 0; i <= a.size(); i++)
//    {
//        if (j > b.size())
//            break ;
//        for (j = 0; j <= b.size() - 1; j++)
//        {
//            while (a[i] == b[j]) {
//                seq += 1;
//                i++;
//                j++;
//            }
//        }
//    }
//    return seq;
}

int main() {
    size_t n;
    cin >> n;
    if (n < 1 || n > 100)
        return (0);
    vector<int> a(n);
    for (size_t i = 0; i < n; i++) {
        cin >> a[i];
        if (a[i] > 1000000000 || a[i] < -1000000000)
            return (0);
    }

    size_t m;
    cin >> m;
    if (m < 1 || m > 100)
        return (0);
    vector<int> b(m);
    for (size_t i = 0; i < m; i++) {
        cin >> b[i];
        if (b[i] > 1000000000 || b[i] < -1000000000)
            return (0);
    }
    cout << lcs2(a, b) << endl;
}
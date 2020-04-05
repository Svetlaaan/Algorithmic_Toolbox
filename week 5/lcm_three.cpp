#include <iostream>
#include <vector>

using namespace std;

int lcs3(vector<int> &a, vector<int> &b, vector<int> &c) {
    int m = a.size();
    int n = b.size();
    int o = c.size();
    int L[m + 1][n + 1][o + 1];
    int i, j, k = 0;

    for (i = 0; i <= m; i++) {
        for (j = 0; j <= n; j++) {
            for (k = 0; k <= o; k++) {
                if (i == 0 || j == 0 || k == 0)
                    L[i][j][k] = 0;
                else if (a[i - 1] == b[j - 1] && a[i - 1] == c[k - 1])
                    L[i][j][k] = L[i - 1][j - 1][k - 1] + 1;
                else
                    L[i][j][k] = max(max(L[i - 1][j][k], L[i][j - 1][k]), L[i][j][k - 1]);
            }
        }
    }
    return L[m][n][o];
}

int main() {
    size_t an;
    cin >> an;
    if (an < 1 || an > 100)
        return (0);
    vector<int> a(an);
    for (size_t i = 0; i < an; i++) {
        cin >> a[i];
        if (a[i] > 1000000000 || a[i] < -1000000000)
            return (0);
    }
    size_t bn;
    cin >> bn;
    if (bn < 1 || bn > 100)
        return (0);
    vector<int> b(bn);
    for (size_t i = 0; i < bn; i++) {
        cin >> b[i];
        if (b[i] > 1000000000 || b[i] < -1000000000)
            return (0);
    }
    size_t cn;
    cin >> cn;
    if (cn < 1 || cn > 100)
        return (0);
    vector<int> c(cn);
    for (size_t i = 0; i < cn; i++) {
        cin >> c[i];
        if (c[i] > 1000000000 || c[i] < -1000000000)
            return (0);
    }
    cout << lcs3(a, b, c) << endl;
}

#include <iostream>
#include <vector>

using std::vector;
using std::max;

int optimal_weight(int W, const vector<int> &w) {
    int n = w.size();
    int i = 0;
    int j = 0;

    if (W == 0 || n == 0)
        return (0);
   vector<vector<int>> dynamic_table(n + 1, vector<int>(W + 1));
    for (j = 0; j <= W; j++)
        dynamic_table[0][j] = 0;
    for (i = 0; i <= n; i++)
        dynamic_table[i][0] = 0;
    for (i = 1; i <= n; i++)
    {
        for (j = 1; j <= W; j++)
        {
            if (w[i - 1] <= j)
                dynamic_table[i][j] = max(dynamic_table[i - 1][j], dynamic_table[i - 1][j - w[i - 1]] + w[i - 1]);
            else
                dynamic_table[i][j] = dynamic_table[i - 1][j];
        }
    }
    return (dynamic_table[n][W]);
}

int main() {
    int n, W;
    std::cin >> W >> n;
    if (W < 1 || W > 10000)
        return (-1);
    if (n < 1 || n > 300)
        return (-1);
    vector<int> w(n);
    for (int i = 0; i < n; i++) {
        std::cin >> w[i];
    }
    std::cout << optimal_weight(W, w) << '\n';
}

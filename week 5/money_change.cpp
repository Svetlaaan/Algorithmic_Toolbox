#include <iostream>
#include <climits>
#include <vector>

using namespace std;

//S(n) = 1 + min[S(n-1), S(n-3), S(n-4)] - formula for our example {1,3,4}
// https://www.youtube.com/watch?v=PvidIBzi-sA&list=PLUfHxBkkFMScqPOn8J0aHvd48wykQNcWS&index=23&t=0s

int get_change(int m) {
    int quant = 3;
    vector<int> change(m+1);
    vector<int> coins = {1, 3, 4};

    for (int i=1; i <= m; ++i) {
        int min_coins = 10001;
        for (int j = 0; j < quant; ++j) {
            if (i >= coins[j]) {
                int n_nmbr = 1 + change[i - coins[j]]; // S(n)
                if (n_nmbr < min_coins) {
                    min_coins = n_nmbr;
                }
            }
        }
        change[i] = min_coins;
    }
    return change[m];
}

int main() {
    int m;
    cin >> m;
    if (m < 0 || m > 10000)
        return (-1);
    cout << get_change(m) << '\n';
}

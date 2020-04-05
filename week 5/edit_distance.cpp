#include <iostream>
#include <string>
#include <vector>

using namespace std;

int edit_distance(const string &str1, const string &str2) {
    int m = str1.size();
    int n = str2.size();
    vector<vector<int>> edit(m + 1, vector<int>(n + 1));

    for(int i = 0; i <= m; i++) {
        edit[i][0] = i;
    }
    for(int i = 0; i <= n; i++) {
        edit[0][i] = i;
    }
    int cost = 0;
    for(int i = 1; i <= m; i++) {
        for(int j = 1; j <= n; j++) {
            if(str1[i-1] == str2[j-1])
                cost = 0;
            else
                cost = 1;
            edit[i][j] = min(min(edit[i-1][j],edit[i][j-1]) + 1, edit[i-1][j-1] + cost);
        }
    }
    return edit[m][n];
}

int main() {
    string str1;
    string str2;
    cin >> str1 >> str2;
    cout << edit_distance(str1, str2) << endl;
    return 0;
}

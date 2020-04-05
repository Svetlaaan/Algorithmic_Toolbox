#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
using std::vector;
using std::min;

vector<int> optimal_sequence(int n) {
    vector<int> sequence;
    vector<int> s(n + 1);

    for(int i = 1; i < n + 1; i++)
    {
        s[i] = s[i - 1] + 1;
        if (i % 2 == 0)
            s[i] = min(1 + s[i / 2], s[i]);
        if (i % 3 == 0)
            s[i] = min(1 + s[i / 3], s[i]);
    }
    int i = n;
    while (i > 1)
    {
        sequence.push_back(i);
        if (s[i - 1] == s[i] - 1)
            i -= 1;
        else if (i % 2 == 0 && (s[i / 2] == s[i] - 1))
            i /= 2;
        else if (i % 3 == 0 && (s[i / 3] == s[i] - 1))
            i /= 3;
    }
    sequence.push_back(1);
    reverse(sequence.begin(), sequence.end());
    return sequence;
}

int main() {
    int n;
    cin >> n;
    if (n < 1 || n > 1000000)
        return (-1);
    vector<int> sequence = optimal_sequence(n);
    cout << sequence.size() - 1 << endl;
    for (size_t i = 0; i < sequence.size(); ++i) {
        cout << sequence[i] << " ";
    }
}

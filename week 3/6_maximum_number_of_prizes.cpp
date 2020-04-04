#include <iostream>
#include <vector>

using std::vector;

vector<int> optimal_summands(int n) {
    vector<int> summands;
    int i = 0;

    int i1, i2, i3, i4, i5, i6, i7, i8, i9, MAX = 10;
    for (i1 = 0; i1 < MAX; i1++)
        for (i2 = i1; i2 < MAX; i2++)
            for (i3 = i2; i3 < MAX; i3++)
                for (i4 = i3; i4 < MAX; i4++)
                    for (i5 = i4; i5 < MAX; i5++)
                        for (i6 = i5; i6 < MAX; i6++)
                            for (i7 = i6; i7 < MAX; i7++)
                                for (i8 = i7; i8 < MAX; i8++)
                                    for (i9 = i8; i9 < MAX; i9++)
                                        if (i1 + i2 + i3 + i4 + i5 + i6 + i7 + i8 + i9 == n) {
                                            if (i1 != 0)
                                                summands[i] = i1;
                                            if (i2 != 0)
                                                summands[i++] = i2;
                                            if (i3 != 0)
                                                summands[i++] = i3;
                                            if (i4 != 0)
                                                summands[i++] = i4;
                                            if (i5 != 0)
                                                summands[i++] = i5;
                                            if (i6 != 0)
                                                summands[i++] = i6;
                                            if (i7 != 0)
                                                summands[i++] = i7;
                                            if (i8 != 0)
                                                summands[i++] = i8;
                                            if (i9 != 0)
                                                summands[i++] = i9;
                                        }
    return summands;
}

int main() {
    int n;
    std::cin >> n;
    vector<int> summands = optimal_summands(n);
    std::cout << summands.size() << '\n';
    for (size_t i = 0; i < summands.size(); ++i) {
        std::cout << summands[i] << ' ';
    }
}

#include <iostream>
#include <vector>

using std::vector;
using std::min;

int     max_val_per1(int n, vector<double> &per1)
{
    int max = 0;
    int i;

    for (i = 0; i < per1.size(); ++i) {
        if (i == 0)
            max = i;
        else if (per1[i] > per1[max])
            max = i;
        else
            max = max;
    }
    per1.erase(per1.begin()+  max);
    return max;
}

double get_optimal_value(int capacity, vector<int> weights, vector<int> values, int n)
{
    double value = 0.0;
    int i;
    int max;
    vector<double> per1(n);
    //double a = 0.0;

    for (i = 0; i < n; ++i)
        per1[i] = (double)values[i] / weights[i];
    /*while (!per1.empty())
    {
        max = max_val_per1(n, per1);
        if (a <= capacity) {
            if (a == capacity)
                return value;
            else if (weights[max] + a <= capacity) {
                a += (double)weights[max];
                value += (double)values[max];
            }
            else if (weights[max] + a > capacity) {
                a += ((double)weights[max] / capacity)/weights[max] * 100;
                value += (((double)values[max]/weights[max]) * a);
            }
        }
    }*/
    for (i = 0; i < n; i++)
    {
        if (capacity == 0)
            return value;
        max = max_val_per1(n, per1);
        int a = min(capacity, weights[max]);
        value += a * (double) values[max] / weights[max];
        values.erase(values.begin()+ max);
        weights.erase(weights.begin()+  max);
        capacity -= a;
    }
    return value;
}

int main() {
    int n; //кол-во вещей
    int capacity;// вместимость сумки
    std::cin >> n >> capacity;
    vector<int> values(n);//ценность
    vector<int> weights(n);//вес
    for (int i = 0; i < n; i++) {
        std::cin >> values[i] >> weights[i];
    }
    double optimal_value = get_optimal_value(capacity, weights, values, n);
    std::cout.precision(10);
    std::cout << optimal_value << std::endl;
    return 0;
}

#include <iostream>
#include <vector>

using std::cin;
using std::cout;
using std::vector;
using std::max;

int find(int i, vector<int> & stops, int currRef, int tank, int numRef, int dist, int n)
{
    for (i = 0; i < (int)stops.size(); ++i) {
        if(stops[i + 1] - stops[i]>= tank)
            if (stops[i + 1] - currRef > tank) {
                currRef = stops[i];
                ++numRef;
            }
    }

    return numRef;
}

int compute_min_refills(int dist, int tank, vector<int> & stops, int n)
{
   int numRef = 0;
   int currRef = 0;
   int i = 0;

   if (dist == tank || tank > dist)
       return 0;
   if ((n <= 300 && n >= 1) && (dist >= 1 && dist <= 100000) && (tank >= 1 && tank <= 400)) {
       if (((stops[n - 1] - stops[n - 2]) > tank) || (stops[n] - stops[n - 1] > tank))
           return -1;
       numRef = find(i, stops, currRef, tank, numRef, dist, n);
   }
    return numRef;
}


int main()
{
    int d = 0;
    cin >> d;
    int m = 0;
    cin >> m;
    int n = 0;
    cin >> n;

    vector<int> stops(n + 1);
    for (size_t i = 0; i < n; ++i)
        cin >> stops.at(i);
    stops.at(n) = d;
    cout << compute_min_refills(d, m, stops, n) << "\n";
    return 0;
}
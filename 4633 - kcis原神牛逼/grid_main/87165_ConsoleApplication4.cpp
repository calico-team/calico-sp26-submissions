#include <iostream>
#include <cstdio>
#include <queue>
#include <vector>
#include <utility>
#include <map>
#include <algorithm>

using namespace std;

int main()
{
    int t, n, d, e, f, g;

    std::vector<int> c(d);
    e = 0;
    std::cin >> t;
    while (t > 0)
    {
        f = 0;
        g = 0;
        cin >> n;
        while (n > e)
        {
            e++;
            std::cin >> d;
            c[e] = d;
            g = c[e] - c[e + 1];
            if (g < 0)
            {
                g * -1;
            }
            f + g;


        }

    }
}
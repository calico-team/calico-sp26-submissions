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
    int t, n, m, c, d;
    cin >> t;

    while (t > 0) {
        c = 0;
        cin >> n >> m;
        d = m;
        while (n > 0)
        {
            m = d;
            while (m > 0)
            {

                printf("%d", c);
                ++c;
                --m;
                if (c == 4)
                {
                    c = 0;
                }

            }
            printf("\n");
            n--;
        }




    }

}

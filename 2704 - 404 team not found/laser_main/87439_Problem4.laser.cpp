#include <iostream>
using namespace std;
int main(){
    int t;
    cin >> t;
    for(int j = 0;j < t;j++){
        int k, n, m, p, q;
        cin >> k >> n >> m >> p >> q;
        int x[100] = {0};
        int y[100] = {0};
        for(int i = 0;i < k;i++){
            cin >> x[i] >> y[i];
        }
        int cur_x = x[0];
        int cur_y = y[0];
        int point_num = 0;
        bool flag = 1;
        while(1){
            if(flag == 0){
                break;
            }
            cur_x += q;
            cur_y += p;
            for(int i = 0;i < k;i++){
                if(cur_x == x[i] && cur_y == y[i]){
                    point_num = i;
                    flag = 0;
                    break;
                }
            }
            if(cur_x > n - 1){
                 cur_x = cur_x % (n);
            }
            if(cur_y > m - 1){
                cur_y = cur_y % (m);
            }
            for(int i = 0;i < k;i++){
                if(cur_x == x[i] && cur_y == y[i]){
                    point_num = i;
                    flag = 0;
                    break;
                }
            }
            //cout << cur_x << ' ' << cur_y << endl;
        }
        cout << point_num << endl;
    }
    return 0;
}
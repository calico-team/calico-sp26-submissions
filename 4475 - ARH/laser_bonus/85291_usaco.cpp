#include <iostream>
#include <climits>
using namespace std;

int64_t k;
int64_t n,m;
int64_t p,q;

struct point64_t{
    int64_t x;
    int64_t y;
} asteroids[100010];


int64_t gcd(int64_t a, int64_t b, int64_t& x, int64_t& y){
    if(b==0){
        x=1;
        y=0;
        return a;
    }
    int64_t new_x,new_y;
    int64_t d = gcd(b,a%b,new_x,new_y);
    x=new_y;
    y=new_x-new_y*(a/b);
    return d;
}
int64_t inv(int64_t a, int64_t m){
    int64_t x, y;
    gcd(a,m,x,y);
    x%=m;
    if(x<0){
        x+=m;
    }
    return x;
}
int64_t crt(int64_t a, int64_t m, int64_t b, int64_t n){
    int64_t x,y;
    int64_t g = gcd(m,n,x,y);
    if((a-b)%g!=0){
        return -1;
    }
    int64_t lcm = m/g*n;
    int64_t ans = (a+(b-a)/g*x%(n/g)*m)%lcm;
    if(ans<0){
        ans+=lcm;
    }
    return ans;
}

int main(){
    int64_t t;
    cin>>t;
    while(t--){
        cin>>k>>n>>m>>p>>q;
        for(int64_t i = 0;i<k;i++){
            int64_t a, b;
            cin>>a>>b;
            asteroids[i].x=a;
            asteroids[i].y=b;
        }
        int64_t start_x=asteroids[0].x;
        int64_t start_y=asteroids[0].y;
        int64_t ans = INT_MAX;
        int64_t index = 0;
        for (int64_t i = 0; i < k; i++) {
            int64_t dx = (asteroids[i].x - start_x) % n;
            if (dx < 0){
                dx += n;
            }
            int64_t dy = (asteroids[i].y - start_y) % m;
            if (dy < 0){
                dy += m;
            }
            int64_t x,y;
            int64_t g1 = gcd(q,n,x,y);
            if (dx % g1 != 0){
                continue;
            }
            int64_t n1 = n / g1;
            int64_t q1 = q / g1;
            int64_t dx1 = dx / g1;
            int64_t q_inv = inv(q1 % n1, n1);
            int64_t t1 = (dx1 * q_inv) % n1;
            int64_t g2 = gcd(p,m,x,y);
            if (dy % g2 != 0){
                continue;
            }
            int64_t m1 = m / g2;
            int64_t p1 = p / g2;
            int64_t dy1 = dy / g2;
            int64_t p_inv = inv(p1 % m1, m1);
            int64_t t2 = (dy1 * p_inv) % m1;
            int64_t t = crt(t1, n1, t2, m1);
            if (t == -1){
                continue;
            }
            int64_t lcm = n1 / gcd(n,m,x,y) * m1;
            if (t == 0){
                t = lcm;
            }
            if (t < ans) {
                ans = t;
                index = i;
            }
        }
        cout<<index<<endl;
        //cout<<asteroids[index].x<<" "<<asteroids[index].y<<endl;
    }
}
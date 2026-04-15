#include <iostream>
#include <climits>
using namespace std;

int k;
int n,m;
int p,q;

struct point{
    int x;
    int y;
} asteroids[100010];


int gcd(int a, int b, int& x, int& y){
    if(b==0){
        x=1;
        y=0;
        return a;
    }
    int new_x,new_y;
    int d = gcd(b,a%b,new_x,new_y);
    x=new_y;
    y=new_x-new_y*(a/b);
    return d;
}
int inv(int a, int m){
    int x, y;
    gcd(a,m,x,y);
    x%=m;
    if(x<0){
        x+=m;
    }
    return x;
}
int crt(int a, int m, int b, int n){
    int x,y;
    int g = gcd(m,n,x,y);
    if((a-b)%g!=0){
        return -1;
    }
    int lcm = m/g*n;
    int ans = (a+(b-a)/g*x%(n/g)*m)%lcm;
    if(ans<0){
        ans+=lcm;
    }
    return ans;
}

int main(){
    int t;
    cin>>t;
    while(t--){
        cin>>k>>n>>m>>p>>q;
        for(int i = 0;i<k;i++){
            int a, b;
            cin>>a>>b;
            asteroids[i].x=a;
            asteroids[i].y=b;
        }
        int start_x=asteroids[0].x;
        int start_y=asteroids[0].y;
        int p_inv=inv(p,m);
        int q_inv=inv(q,n);
        int ans = INT_MAX;
        int index = 0;
        for (int i = 0; i < k; i++) {
            int dx = (asteroids[i].x - start_x) % n;
            if (dx < 0){
                dx += n;
            }
            int dy = (asteroids[i].y - start_y) % m;
            if (dy < 0){
                dy += m;
            }
            int x,y;
            int g1 = gcd(q,n,x,y);
            if (dx % g1 != 0){
                continue;
            }
            int n1 = n / g1;
            int q1 = q / g1;
            int dx1 = dx / g1;
            int invQ = inv(q1 % n1, n1);
            int t1 = (dx1 * invQ) % n1;
            int g2 = gcd(p,m,x,y);
            if (dy % g2 != 0){
                continue;
            }
            int m1 = m / g2;
            int p1 = p / g2;
            int dy1 = dy / g2;
            int invP = inv(p1 % m1, m1);
            int t2 = (dy1 * invP) % m1;
            int t = crt(t1, n1, t2, m1);
            if (t == -1){
                continue;
            }
            int lcm = n1 / gcd(n,m,x,y) * m1;
            if (t == 0){
                t = lcm;
            }
            if (t < ans) {
                ans = t;
                index = i;
            }
        }
        cout<<index<<endl;
    }
}
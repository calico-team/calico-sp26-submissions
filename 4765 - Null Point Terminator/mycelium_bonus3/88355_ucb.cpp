#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <vector>
using namespace std;

int main() {
    int t;
    scanf("%d", &t);
    while(t--) {
        long long xg, yg, xm, ym;
        scanf("%lld %lld %lld %lld", &xg, &yg, &xm, &ym);

        long long D = abs(xg-xm) + abs(yg-ym);
        long long R = 3*D/4 + 15;

        long long x1 = min(xg, xm-R) -2;
        long long y1 = min(yg, ym-R) -2;
        long long x2 = max(xg, xm+R) +2;
        long long y2 = max(yg, ym+R) +2;
        int W = (int)(x2-x1+1);
        int H =(int)(y2-y1+1);

        int gx =(int)(xg-x1);
        int gy = (int)(yg-y1);
        int cx =(int)(xm-x1);
        int cy =(int)(ym-y1);

        long long sz = (long long)W*H;
        char* g =(char*)calloc(sz, 1);

        for(int j = 0; j < H; j++) {
            g[j] = 3;
            g[(long long)(W-1)*H+j] =3;
        }
        for(int i = 0; i <W; i++) {
            g[(long long)i*H] =3;
            g[(long long)i*H+H-1] = 3;
        }

        g[(long long)cx*H+cy] =2;
        g[(long long)gx*H+gy] =1;

        long long ans =1;
        vector<int> cur, nxt;
        cur.push_back(gx*H+gy);
        int dd =0;

        while(!cur.empty()) {
            dd++;
            for(int ci : cur) {
                int x = ci/H, y =ci%H;
                int ds[4] ={1,-1,H,-H};
                int dx[4] ={0,0,1,-1};
                int dy[4] = {1,-1,0,0};
                for(int k = 0; k <4; k++) {
                    int ni = ci+ds[k];
                    if(g[ni] ==0) {
                        int dm =abs(x+dx[k]-cx)+abs(y+dy[k]-cy);
                        if(7*dm < 2*dd) {
                            g[ni] =2; ans++;
                        } else{
                            g[ni] = 1; nxt.push_back(ni);
                        }
                    }
                }
            }
            cur.swap(nxt);
            nxt.clear();
        }

        for(long long a = -R; a <=R; a++) {
            int ix =(int)(cx+a);
            if(ix <=0 || ix >= W-1) continue;
            long long bm = R-abs(a);
            for(long long b =-bm; b <= bm; b++) {
                int iy =(int)(cy+b);
                if(iy <=0 || iy >=H-1) continue;
                if(g[(long long)ix*H+iy] ==0) ans++;
            }
        }

        free(g);
        printf("%lld\n", ans);
    }
}

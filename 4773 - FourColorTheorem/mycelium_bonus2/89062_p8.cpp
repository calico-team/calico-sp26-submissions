
#include <iostream>
#include <vector>
#include <queue>
#include <map>

using namespace std;

struct EV {

    int time;
    int tp;
    int x,y;

    bool operator>(const EV& other) const {
        if (time!=other.time)
            return time>other.time;

        return tp>other.tp;
    }
};



int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin>>T;


    while (T--) {
        int xg,yg,xm,ym;
        cin>>xg>>yg>>xm>>ym;

        priority_queue<EV,vector<EV>,greater<EV>> pq;

        map<pair<int,int>,int> own;

        pq.push({0,1,xg,yg});
        pq.push({0,2,xm,ym});

        int total_A=0;



        int poses=1;
        int delx[]={0,0,1,-1};
        int dely[]={1,-1,0,0};

        while (!pq.empty() && poses>0) {

            auto q=pq.top();
            pq.pop();

            // std::cout<<q.tp;

            if (q.tp==2) poses--;

    
            if (own.count({q.x,q.y})) continue;

        
            own[{q.x,q.y}]=q.tp;


            if (q.tp==2){
                total_A++;
                
            }

        
            for (int i=0;i<4;i++) {

                int x1=q.x+delx[i];
                int y1=q.y+ dely[i];


                // std::cout<<"_"<<x1<<" "<<y1;

                if (own.find({x1,y1})==own.end()) {

                    int tt=(q.tp==1)?2:7;
                    pq.push({q.time+tt,q.tp,x1,y1});


                    if (q.tp==2) poses++;
                }
            }
        }

        cout<<total_A<<endl;
    }
}
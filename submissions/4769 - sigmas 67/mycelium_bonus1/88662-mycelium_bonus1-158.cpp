#include <iostream>
#include <vector>
#include <set>
#include <utility>
using namespace std;

int main(){

    int T;
    cin >> T;
    vector<int> pr(T);

    for(int i = 0; i < T; i++){

        set<pair<int,int>> mycelium;
        set<pair<int,int>> grass;
        int ticks = 1;
        int x,y;

        cin >> x >> y;
        grass.insert(pair<int,int>(x,y));

        cin >> x >> y;
        mycelium.insert(pair<int,int>(x,y));

        while(true){
            if(ticks % 2 == 0){
                set<pair<int,int>> addGrass;
                set<pair<int,int>>::iterator itg = grass.begin();
                while(itg != grass.end()){
                    int xLOOP = itg->first;
                    int yLOOP = itg->second;

                    pair<int,int> p1 = pair<int,int>(xLOOP + 1,yLOOP);
                    pair<int,int> p2 = pair<int,int>(xLOOP,yLOOP + 1);
                    pair<int,int> p3 = pair<int,int>(xLOOP - 1,yLOOP);
                    pair<int,int> p4 = pair<int,int>(xLOOP,yLOOP - 1);

                    if(grass.find(p1) == grass.end() && mycelium.find(p1) == mycelium.end()){
                        addGrass.insert(p1);
                    }
                    if(grass.find(p2) == grass.end() && mycelium.find(p2) == mycelium.end()){
                        addGrass.insert(p2);
                    }
                    if(grass.find(p3) == grass.end() && mycelium.find(p3) == mycelium.end()){
                        addGrass.insert(p3);
                    }
                    if(grass.find(p4) == grass.end() && mycelium.find(p4) == mycelium.end()){
                        addGrass.insert(p4);
                    }

                    itg++;
                }
                grass.insert(addGrass.begin(), addGrass.end());
            }

            if(ticks % 7 == 0){
                int previousMy = mycelium.size();
                set<pair<int,int>> addMy;
                set<pair<int,int>>::iterator itm = mycelium.begin();
                while(itm != mycelium.end()){
                    int xLOOP = itm->first;
                    int yLOOP = itm->second;

                    pair<int,int> p1 = pair<int,int>(xLOOP + 1,yLOOP);
                    pair<int,int> p2 = pair<int,int>(xLOOP,yLOOP + 1);
                    pair<int,int> p3 = pair<int,int>(xLOOP - 1,yLOOP);
                    pair<int,int> p4 = pair<int,int>(xLOOP,yLOOP - 1);

                    if(grass.find(p1) == grass.end() && mycelium.find(p1) == mycelium.end()){
                        addMy.insert(p1);
                    }
                    if(grass.find(p2) == grass.end() && mycelium.find(p2) == mycelium.end()){
                        addMy.insert(p2);
                    }
                    if(grass.find(p3) == grass.end() && mycelium.find(p3) == mycelium.end()){
                        addMy.insert(p3);
                    }
                    if(grass.find(p4) == grass.end() && mycelium.find(p4) == mycelium.end()){
                        addMy.insert(p4);
                    }

                    itm++;
                }

                mycelium.insert(addMy.begin(), addMy.end());

                if((int)mycelium.size() == previousMy){
                    break;
                }
            }

            ticks++;
        }

        pr[i] = mycelium.size();
    }

    for(int i = 0; i < T; i++){
        cout << pr[i] << endl;
    }

    return 0;
}
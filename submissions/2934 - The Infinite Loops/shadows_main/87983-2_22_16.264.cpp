

#include <bits/stdc++.h>
using namespace std;

int main() {
	int T;
    cin >> T;
    while(T--){
        int n;
        cin >> n; 
        vector<string> s1(n);
        vector<string> s2(n);
        for(int i=0; i<n; i++){
            cin >> s1[i];
        }
        for(int i=0; i<n; i++){
            cin >> s2[i];
        }
        
        int min = 0;
        
        for(int i=0; i<n; i++){
            int ocount =0; int tcount = 0;
            for(int j=0; j<n; j++){
                if(s2[i][j] == s1[i][j] && s2[i][j] == '#'){
                    min++;
                }
                else if(s2[i][j] == '#'){
                    tcount++;
                    //cout << "t" << i << j << endl;
                }
                else if(s1[i][j] == '#'){
                    ocount++;
                    //cout << "o" << i << j << endl;
                }
            }
            if(tcount==0&&ocount==0){
                min+=0;
            }
            else if(tcount==0)tcount++;
            else if(ocount==0)ocount++;
            min+=tcount*ocount;

            //cout << ocount << " " << tcount << endl;
        }

        vector<vector<int>> x1(n,vector(n,n));
        //vector<vector<int>> y1(n,vector(n,3));
        //vector<vector<int>> z1(n,vector(n,3));
        for(int i=0; i<n; i++){ //first
            for(int j=0; j<n; j++){
                if(s1[i][j] == '.'){
                    x1[i][j] = 0;
                    
                }
            }
        }
        int max = 0;
        for(int i=0; i<n; i++){ //second
            for(int j=0; j<n; j++){
                if(s2[i][j] == '.'){
                    for(int c=0; c<n;c++){
                        if(x1[i][c]!=0)
                            x1[i][c]-=1;
                    }
                    
                }
            }
        }
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                max+=x1[i][j];
            }
        }
        cout <<max << " "<< min << endl;
    }
}

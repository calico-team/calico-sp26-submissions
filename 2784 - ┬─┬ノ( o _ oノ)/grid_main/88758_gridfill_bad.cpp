#include <bits/stdc++.h>
using namespace std;
ostream& operator<<(ostream& out, const vector<int>& a){
    for(int i=0; i<a.size(); i+=1){
        cout<<a[i]<<" ";
    }
    return out;
}
void solve(){
    int n;
    cin>>n;
    vector<int> asdfasdfasdf;
    for(int i=0; i<n; i+=1){
        int aaaa;
        cin>>aaaa;
        asdfasdfasdf.push_back(aaaa);
    }
    if(asdfasdfasdf.size()==1){
        cout<<asdfasdfasdf[0]<<"\n";
    }
    else if(asdfasdfasdf.size()==2){
        int min_sum=10000069;
        int iteration_index=0;
        int current_best_index=-69;
        vector<vector<int>> AAAAAAAAAAAAAAAAAAAAA;
        for(int i=0; i<asdfasdfasdf.size(); i+=1){
            for(int j=0; j<asdfasdfasdf.size(); j+=1){
                // for(int k=0; k<asdfasdfasdf.size(); k+=1){
                    vector<int> qwerqwerqwerqwer;
                    int poiupoiu=0;
                    qwerqwerqwerqwer.push_back(asdfasdfasdf[i]);
                    qwerqwerqwerqwer.push_back(asdfasdfasdf[j]);
                    // qwerqwerqwerqwer.push_back(asdfasdfasdf[k]);
                    for(int qq=0; qq<qwerqwerqwerqwer.size()-1; qq+=1){
                        poiupoiu+=abs(qwerqwerqwerqwer[qq]-qwerqwerqwerqwer[qq+1]);
                    }
                    for(int qq=0; qq<asdfasdfasdf.size()-1; qq+=1){
                        poiupoiu+=abs(asdfasdfasdf[qq]-asdfasdfasdf[qq+1]);
                    }
                    for(int qq=0; qq<qwerqwerqwerqwer.size(); qq+=1){
                        poiupoiu+=abs(qwerqwerqwerqwer[qq]-asdfasdfasdf[qq]);
                    }
                    AAAAAAAAAAAAAAAAAAAAA.push_back(qwerqwerqwerqwer);
                    if(poiupoiu<min_sum){
                        min_sum=poiupoiu;
                        current_best_index=iteration_index;
                    }
                    iteration_index+=1;
                // }
            }
        }
        cout<<AAAAAAAAAAAAAAAAAAAAA[current_best_index]<<"\n";
    }
    else if(asdfasdfasdf.size()==3){
        int min_sum=10000069;
        int iteration_index=0;
        int current_best_index=-69;
        vector<vector<int>> AAAAAAAAAAAAAAAAAAAAA;
        for(int i=0; i<asdfasdfasdf.size(); i+=1){
            for(int j=0; j<asdfasdfasdf.size(); j+=1){
                for(int k=0; k<asdfasdfasdf.size(); k+=1){
                    vector<int> qwerqwerqwerqwer;
                    int poiupoiu=0;
                    qwerqwerqwerqwer.push_back(asdfasdfasdf[i]);
                    qwerqwerqwerqwer.push_back(asdfasdfasdf[j]);
                    qwerqwerqwerqwer.push_back(asdfasdfasdf[k]);
                    for(int qq=0; qq<qwerqwerqwerqwer.size()-1; qq+=1){
                        poiupoiu+=abs(qwerqwerqwerqwer[qq]-qwerqwerqwerqwer[qq+1]);
                    }
                    for(int qq=0; qq<asdfasdfasdf.size()-1; qq+=1){
                        poiupoiu+=abs(asdfasdfasdf[qq]-asdfasdfasdf[qq+1]);
                    }
                    for(int qq=0; qq<qwerqwerqwerqwer.size(); qq+=1){
                        poiupoiu+=abs(qwerqwerqwerqwer[qq]-asdfasdfasdf[qq]);
                    }
                    AAAAAAAAAAAAAAAAAAAAA.push_back(qwerqwerqwerqwer);
                    if(poiupoiu<min_sum){
                        min_sum=poiupoiu;
                        current_best_index=iteration_index;
                    }
                    iteration_index+=1;
                }
            }
        }
        cout<<AAAAAAAAAAAAAAAAAAAAA[current_best_index]<<"\n";
    }
}
int main(){
    long long t;
    cin>>t;
    for(long long test=0; test<t; test+=1){
        solve();
    }
}
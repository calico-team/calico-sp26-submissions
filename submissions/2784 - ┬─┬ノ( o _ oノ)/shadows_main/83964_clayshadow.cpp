#include <bits/stdc++.h>
using namespace std;
ostream& operator<<(ostream& out, const vector<long long>& a){
    for(long long i=0; i<a.size(); i+=1){
        cout<<a[i]<<" ";
    }
    return out;
}
void solve(){
    int n;
    cin>>n;
    vector<int> number_of_filled_left;
    for(int i=0; i<n; i+=1){
        string asdfasdfasdfasdf;
        cin>>asdfasdfasdfasdf;
        int sum_of_filled=0;
        for(int j=0; j<asdfasdfasdfasdf.size(); j+=1){
            if(asdfasdfasdfasdf[j]=='#'){
                sum_of_filled+=1;
            }
        }
        number_of_filled_left.push_back(sum_of_filled);
    }
    vector<int> number_of_filled_right;
    for(int i=0; i<n; i+=1){
        string asdfasdfasdfasdf;
        cin>>asdfasdfasdfasdf;
        int sum_of_filled=0;
        for(int j=0; j<asdfasdfasdfasdf.size(); j+=1){
            if(asdfasdfasdfasdf[j]=='#'){
                sum_of_filled+=1;
            }
        }
        number_of_filled_right.push_back(sum_of_filled);
    }
    int max_possible=0;
    int min_possible=0;
    for(int i=0; i<n; i+=1){
        int min_for_layer=1000069;
        if(number_of_filled_left[i]>number_of_filled_right[i]){
            min_for_layer=number_of_filled_left[i];
        }
        else if(number_of_filled_left[i]<=number_of_filled_right[i]){
            min_for_layer=number_of_filled_right[i];
        }
        int max_for_layer=number_of_filled_left[i]*number_of_filled_right[i];
        min_possible+=min_for_layer;
        max_possible+=max_for_layer;
    }
    cout<<max_possible<<" "<< min_possible<<"\n";
}
int main(){
    long long t;
    cin>>t;
    for(long long test=0; test<t; test+=1){
        solve();
    }
}
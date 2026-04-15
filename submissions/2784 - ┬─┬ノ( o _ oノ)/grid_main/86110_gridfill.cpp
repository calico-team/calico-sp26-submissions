#include <bits/stdc++.h>
using namespace std;
ostream& operator<<(ostream& out, const vector<int>& a){
    for(long long i=0; i<a.size(); i+=1){
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
    int sum_of_diffs=0;
    // int total_sum;
    map<int, int> counts;
    for(int i=0; i<n-1; i+=1){
        sum_of_diffs+=abs((asdfasdfasdf[i]-asdfasdfasdf[i+1]));
    }
    for(int i=0; i<n; i+=1){
        // if(count(counts.begin(), counts.end(), asdfasdfasdf[i])<=0){
        //     counts[asdfasdfasdf[i]]=0;
        // }
        counts[asdfasdfasdf[i]]+=1;
    }
    int current_max_amount=-100;
    int current_max_thingy;
    for(int i=0; i<n; i+=1){
        if(counts[asdfasdfasdf[i]]>current_max_amount){
            current_max_amount=counts[asdfasdfasdf[i]];
            current_max_thingy=asdfasdfasdf[i];
        }
    }
    // cout<<current_max_thingy<<" asdfasdfasdf\n";
    int sum_of_diffffffff_2=0;
    for(int i=0; i<n; i+=1){
        sum_of_diffffffff_2+=abs(current_max_thingy-asdfasdfasdf[i]);
    }
    // cout<<sum_of_diffffffff_2<<" a\n";
    // cout<<sum_of_diffs<<" b\n";
    // cout<<min(sum_of_diffffffff_2+sum_of_diffs, sum_of_diffs*2)<<"\n";
    if(sum_of_diffffffff_2+sum_of_diffs<=sum_of_diffs*2){
        for(int i=0; i<n; i+=1){
            cout<<current_max_thingy<<" ";
        }
        cout<<"\n";
    }
    else if(sum_of_diffffffff_2+sum_of_diffs>sum_of_diffs*2){
        cout<<asdfasdfasdf<<"\n";
    }
}
int main(){
    long long t;
    cin>>t;
    for(long long test=0; test<t; test+=1){
        solve();
    }
}
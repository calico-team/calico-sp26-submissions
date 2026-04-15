// Source: https://usaco.guide/general/io

#include <bits/stdc++.h>
using namespace std;

int main() {
	long long t; cin >> t;
    for (int i = 0; i<t; i++){
        long long n; cin >> n;
        vector<long long> arr1;
        vector<long long> arr2;

        for (int j = 0; j<n; j++){
            long long cnt = 0;
            
            string s; cin >> s;
            for (int k = 0; k<n; k++){
                if (s[k] == '#'){
                    cnt+=1;
                }
            }
            arr1.push_back(cnt);
        }

        for (int j = 0; j<n; j++){
            long long cnt = 0;
            
            string s; cin >> s;
            for (int k = 0; k<n; k++){
                if (s[k] == '#'){
                    cnt+=1;
                }
            }
            arr2.push_back(cnt);
        }

        long long s1 = 0;
        for (int j = 0; j<n; j++){
            s1+=arr1[j]*arr2[j];
        }
        long long s2 = 0;
        for (int j = 0;j<n; j++){
            s2+=max(arr1[j], arr2[j]);
        }

        cout << s1 << " " << s2 << endl;
    }
}

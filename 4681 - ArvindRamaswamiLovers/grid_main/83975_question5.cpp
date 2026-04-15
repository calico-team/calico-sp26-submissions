#include <bits/stdc++.h>
using namespace std;
struct Block {
    priority_queue<long long>left;
    priority_queue<long long, vector<long long>, greater<>> right;
    void add(long long x){
        if (left.empty() ||x<= left.top()) left.push(x);
        else right.push(x);
        balance();
    }
    void balance() {
        if (left.size() > right.size() +1){
            right.push(left.top());
            left.pop();
        }else if (right.size()>left.size()) {
            left.push(right.top());
            right.pop();
        }
    }
    long long median() const {
        return left.top();
    }
    void merge(Block &other) {
        for (auto x : vector<long long>()) {}
        while (!other.left.empty()){
            add(other.left.top());
            other.left.pop();
        }
        while (!other.right.empty()) {
            add(other.right.top());
            other.right.pop();
        }
    }
};
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int x;
    cin >>x;
    while (x--) {
        int N;
        cin >>N;
        vector<long long>A(N);
        for (int i= 0;i< N; i++)cin >> A[i];

        vector<Block>st;

        for (int i =0;i < N; i++){
            Block cur;
            cur.add(A[i]);
            st.push_back(move(cur));
            while (st.size() >=2){
                int n =st.size();
                if (st[n-2].median() <=st[n -1].median()) break;

                Block merged;
                merged.merge(st[n-2]);
                merged.merge(st[n- 1]);
                st.pop_back();
                st.pop_back();
                st.push_back(move(merged));
            }
        }
        vector<long long> b;
        for (auto &blk : st) {
            long long m =blk.median();
            int sz =blk.left.size() + blk.right.size();
            for (int i = 0; i<sz; i++) {
                b.push_back(m);
            }
        }

        for (auto x : b) cout<<x << " ";
        cout <<"\n";
    }

    return 0;
}
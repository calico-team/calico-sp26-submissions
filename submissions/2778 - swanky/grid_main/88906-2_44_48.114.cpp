#include<iostream>
#include<vector>
using namespace std;

void one(){
    int a;
    cin>>a;
    cout<<a<<endl;
}

void two(){
    int a,b;
    cin>>a>>b;
    cout<<a<<" "<<b<<endl;
}

void three(){
    int a,b,c;
    cin>>a>>b>>c;
    int dif=abs(a-b)+abs(b-c);
    int suma,sumb,sumc;
    suma=abs(a-a)+abs(a-b)+abs(a-c);
    sumb=abs(b-a)+abs(b-b)+abs(b-c);
    sumc=abs(c-a)+abs(c-b)+abs(c-c);
    if(suma<=sumb && suma<=sumc)
        cout<<a<<" "<<a<<" "<<a<<endl;
    else if(sumb<=suma && sumb<=sumc)
        cout<<b<<" "<<b<<" "<<b<<endl;
    else cout<<c<<" "<<c<<" "<<c<<endl;
}

int main(){
    int test;
    cin>>test;
    for(int t=0;t<test;t++){
        int n;
        cin>>n;
        if(n==1)
            one();
        if(n==2)
            two();
        if(n==3)
            three();
    }
}
#include <bits/stdc++.h>
using namespace std;

#define ll long long

const ll MAXN=1e5+5;

ll n, a[MAXN], m1[MAXN], oddSum, m2[MAXN], evenSum;

void oddIdx()
{
    for (int i=1; i<n; i+=2)
    {
        m1[i]=a[i];
    }
    m1[0]=a[0];
    if (n%2==1)
    {
        m1[n-1]=a[n-1];
    }
    for (int i=2; i<n-1; i+=2)
    {
        if (a[i]>=max(a[i-1], a[i+1]))
        {
            m1[i]=max(a[i-1], a[i+1]);
        }
        else if (a[i]<=min(a[i-1], a[i+1]))
        {
            m1[i]=min(a[i-1], a[i+1]);
        }
        else
        {
            m1[i]=a[i];
        }
    }
    oddSum=0;
    for (int i=0; i<n; i++)
    {
        oddSum+=abs(m1[i]-a[i]);
        if (i+1<n)
        {
            oddSum+=abs(m1[i+1]-m1[i]);
        }
    }
}

void evenIdx()
{
    for (int i=0; i<n; i+=2)
    {
        m2[i]=a[i];
    }
    if (n%2==0)
    {
        m2[n-1]=a[n-1];
    }
    for (int i=1; i<n-1; i+=2)
    {
        if (a[i]>=max(a[i-1], a[i+1]))
        {
            m2[i]=max(a[i-1], a[i+1]);
        }
        else if (a[i]<=min(a[i-1], a[i+1]))
        {
            m2[i]=min(a[i-1], a[i+1]);
        }
        else
        {
            m2[i]=a[i];
        }
    }
    evenSum=0;
    for (int i=0; i<n; i++)
    {
        evenSum+=abs(m2[i]-a[i]);
        if (i+1<n)
        {
            evenSum+=abs(m2[i+1]-m2[i]);
        }
    }
}

void solve()
{
    cin >> n;
    for (int i=0; i<n; i++)
    {
        cin >> a[i];
    }
    oddIdx();
    evenIdx();
    if (oddSum<evenSum)
    {
        for (int i=0; i<n; i++)
        {
            cout << m1[i] << " ";
        }
        cout << "\n";
    }
    else
    {
        for (int i=0; i<n; i++)
        {
            cout << m2[i] << " ";
        }
        cout << "\n";
    }
}

int main()
{
    ll t;
    cin >> t;
    while (t--)
    {
        solve();
    }
}
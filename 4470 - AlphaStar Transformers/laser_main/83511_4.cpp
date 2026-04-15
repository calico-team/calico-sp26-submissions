#include <bits/stdc++.h>
using namespace std;

#define ll long long

/*
first reduce so that if p and q have gcd>1 with m and n we know that
then for each starting asteroid we check how many moves it takes,
this can be done by taking diff mod n and m, and then multiplying by qinv, pinv, and taking both of them mod nRed, mRed resp.
then it suffices to do crt
*/

const ll MAXK=1e5+5;

ll k, n, m, p, q, nq, mp, pRed, qRed, nRed, mRed, pinv, qinv, bestMoves, bestIdx, x[MAXK], y[MAXK];

void solve()
{
    cin >> k >> n >> m >> p >> q;
    nq=__gcd(n, q);
    mp=__gcd(m, p);
    pRed=p/mp;
    qRed=q/nq;
    nRed=n/nq;
    mRed=m/mp;
    for (int i=1; i<mRed; i++)
    {
        if ((pRed*i)%mRed==1)
        {
            pinv=i;
        }
    }
    for (int i=1; i<nRed; i++)
    {
        if ((qRed*i)%nRed==1)
        {
            qinv=i;
        }
    }
    bestIdx=0;
    bestMoves=(nRed*mRed)/(__gcd(nRed, mRed));
    cin >> x[0] >> y[0];
    for (int i=1; i<k; i++)
    {
        cin >> x[i] >> y[i];
        x[i]=(x[i]-x[0]+n)%n;
        y[i]=(y[i]-y[0]+m)%m;
        if (x[i]%nq!=0 || y[i]%mp!=0)
        {
            continue;
        }
        x[i]/=nq;
        y[i]/=mp;
        x[i]=(x[i]*qinv)%nRed;
        y[i]=(y[i]*pinv)%mRed;
        //now we simply have the number of moves needed to reach the right x and y mod nRed and mRed, suffices to find the number using CRT maybe?
        for (int j=0; j<mRed; j++)
        {
            if (x[i]%mRed==y[i])
            {
                break;
            }
            x[i]+=nRed;
        }
        if (x[i]%mRed!=y[i])
        {
            continue;
        }
        if (bestMoves>x[i])
        {
            bestMoves=x[i];
            bestIdx=i;
        }
    }
    cout << bestIdx << "\n";
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
#include <iostream>
using namespace std;

long long gcd(long long a, long long b)
{
    while(b)
    {
        long long t = b;
        b = a % b;
        a = t;
    }
    return a;
}

long long modInverse(long long e, long long phi)
{
    long long t = 0, newt = 1;
    long long r = phi, newr = e;

    while(newr != 0)
    {
        long long q = r / newr;

        long long temp = newt;
        newt = t - q * newt;
        t = temp;

        temp = newr;
        newr = r - q * newr;
        r = temp;
    }

    if(t < 0)
        t += phi;

    return t;
}

int main()
{
    long long p,q,n,phi,e,d;

    cout<<"Nhap p = ";
    cin>>p;

    cout<<"Nhap q = ";
    cin>>q;

    n = p*q;

    phi = (p-1)*(q-1);

    e = 2;

    while(e < phi)
    {
        if(gcd(e,phi)==1)
            break;
        e++;
    }

    d = modInverse(e,phi);

    cout<<"\n===== KHOA RSA =====\n";

    cout<<"Khoa cong khai:\n";
    cout<<"e = "<<e<<endl;
    cout<<"n = "<<n<<endl;

    cout<<"\nKhoa bi mat:\n";
    cout<<"d = "<<d<<endl;
    cout<<"n = "<<n<<endl;

    return 0;
}


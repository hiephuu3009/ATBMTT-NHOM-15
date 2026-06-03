#include <iostream>
#include <string>

using namespace std;

long long modPow(long long base,
                 long long exp,
                 long long mod)
{
    long long result = 1;

    while(exp > 0)
    {
        if(exp % 2 == 1)
            result = (result * base) % mod;

        base = (base * base) % mod;

        exp /= 2;
    }

    return result;
}

long long simpleHash(string str)
{
    long long hash = 0;

    for(char c : str)
    {
        hash = (hash * 131 + c) % 1000000007;
    }

    return hash;
}

int main()
{
    string message;

    long long d,n;

    cout<<"Nhap khoa bi mat d = ";
    cin>>d;

    cout<<"Nhap n = ";
    cin>>n;

    cin.ignore();

    cout<<"Nhap thong diep: ";
    getline(cin,message);

    long long hashValue =
        simpleHash(message);

    long long signature =
        modPow(hashValue,d,n);

    cout<<"\nGia tri bam: "
        <<hashValue<<endl;

    cout<<"Chu ky so: "
        <<signature<<endl;

    return 0;
}








#include <iostream>
#include <string>
using namespace std;

//======================
// Bien toan cuc
//======================
long long p = 0, q = 0;
long long n = 0, phi = 0;
long long e = 0, d = 0;

string thongDiep = "";
long long chuKy = -1;

//======================
// Kiem tra so nguyen to
//======================
bool laSoNguyenTo(long long n)
{
    if(n < 2) return false;

    for(long long i = 2; i * i <= n; i++)
    {
        if(n % i == 0)
            return false;
    }

    return true;
}

//======================
// UCLN
//======================
long long gcd(long long a, long long b)
{
    while(b != 0)
    {
        long long t = b;
        b = a % b;
        a = t;
    }

    return a;
}

//======================
// Euclid mo rong
//======================
long long modInverse(long long e, long long phi)
{
    long long t = 0;
    long long newt = 1;

    long long r = phi;
    long long newr = e;

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

    if(r > 1)
        return -1;

    if(t < 0)
        t += phi;

    return t;
}

//======================
// Luy thua modulo nhanh
//======================
long long modPow(long long base,
                 long long exp,
                 long long mod)
{
    long long result = 1;

    base %= mod;

    while(exp > 0)
    {
        if(exp % 2 == 1)
        {
            result = (result * base) % mod;
        }

        base = (base * base) % mod;
        exp /= 2;
    }

    return result;
}

//======================
// Ham bam don gian
//======================
long long simpleHash(string str)
{
    long long hash = 0;

    for(char c : str)
    {
        hash = (hash * 131 + c) % 1000000007;
    }

    return hash;
}

//======================
// Tao khoa RSA
//======================
void taoKhoaRSA()
{
    cout << "\n===== TAO KHOA RSA =====\n";

    do
    {
        cout << "Nhap so nguyen to p: ";
        cin >> p;

        if(!laSoNguyenTo(p))
            cout << "p khong phai so nguyen to!\n";

    } while(!laSoNguyenTo(p));

    do
    {
        cout << "Nhap so nguyen to q: ";
        cin >> q;

        if(!laSoNguyenTo(q))
            cout << "q khong phai so nguyen to!\n";

    } while(!laSoNguyenTo(q));

    n = p * q;

    phi = (p - 1) * (q - 1);

    e = 2;

    while(e < phi)
    {
        if(gcd(e, phi) == 1)
            break;

        e++;
    }

    d = modInverse(e, phi);

    cout << "\nTao khoa thanh cong!\n";
}

//======================
// Hien thi khoa
//======================
void hienThiKhoa()
{
    if(n == 0)
    {
        cout << "\nBan chua tao khoa RSA!\n";
        return;
    }

    cout << "\n===== THONG TIN KHOA =====\n";

    cout << "\nKhoa cong khai:\n";
    cout << "(e, n) = ("
         << e << ", "
         << n << ")\n";

    cout << "\nKhoa bi mat:\n";
    cout << "(d, n) = ("
         << d << ", "
         << n << ")\n";
}

//======================
// Ky dien tu
//======================
void kyDienTu()
{
    if(n == 0)
    {
        cout << "\nHay tao khoa RSA truoc!\n";
        return;
    }

    cin.ignore();

    cout << "\nNhap thong diep can ky:\n";
    getline(cin, thongDiep);

    long long hashValue =
        simpleHash(thongDiep);

    chuKy =
        modPow(hashValue, d, n);

    cout << "\n===== KET QUA KY SO =====\n";

    cout << "Gia tri bam: "
         << hashValue
         << endl;

    cout << "Chu ky dien tu: "
         << chuKy
         << endl;
}

//======================
// Xac minh chu ky
//======================
void xacMinh()
{
    if(chuKy == -1)
    {
        cout << "\nChua co chu ky de kiem tra!\n";
        return;
    }

    long long hashValue =
        simpleHash(thongDiep);

    long long verify =
        modPow(chuKy, e, n);

    cout << "\n===== XAC MINH CHU KY =====\n";

    cout << "Gia tri goc: "
         << hashValue % n
         << endl;

    cout << "Gia tri giai ma: "
         << verify
         << endl;

    if(verify == hashValue % n)
    {
        cout << "\nKET QUA: CHU KY HOP LE\n";
        cout << "Thong diep khong bi thay doi.\n";
    }
    else
    {
        cout << "\nKET QUA: CHU KY KHONG HOP LE\n";
        cout << "Thong diep da bi sua doi.\n";
    }
}

//======================
// Menu
//======================
void menu()
{
    cout << "\n";
    cout << "=====================================\n";
    cout << "   CHUONG TRINH CHU KY DIEN TU RSA\n";
    cout << "=====================================\n";

    cout << "1. Tao khoa RSA\n";
    cout << "2. Hien thi khoa\n";
    cout << "3. Ky dien tu\n";
    cout << "4. Xac minh chu ky\n";
    cout << "5. Thoat\n";

    cout << "\nNhap lua chon: ";
}

//======================
// Main
//======================
int main()
{
    int luaChon;

    do
    {
        menu();

        cin >> luaChon;

        switch(luaChon)
        {
            case 1:
                taoKhoaRSA();
                break;

            case 2:
                hienThiKhoa();
                break;

            case 3:
                kyDienTu();
                break;

            case 4:
                xacMinh();
                break;

            case 5:
                cout << "\nKet thuc chuong trinh!\n";
                break;

            default:
                cout << "\nLua chon khong hop le!\n";
        }

    } while(luaChon != 5);

    return 0;
}

#include<iostream>
#include<string>
#include<math.h>
#include<iomanip>
#include<algorithm>
using namespace std;
typedef long long ll;

class Dong_Ho
{
    int gio;
    int phut;
    int giay;
public:
    void Nhap();
    void Xuat();
    friend Dong_Ho operator+(Dong_Ho a, Dong_Ho b);
    friend Dong_Ho operator-(Dong_Ho a, Dong_Ho b);
    friend bool operator>(Dong_Ho a, Dong_Ho b);
    friend bool operator<(Dong_Ho a, Dong_Ho b);
    friend bool operator==(Dong_Ho a, Dong_Ho b);
    void Change(int &a, int &b, int &c);
    friend istream &operator >> (istream &in, Dong_Ho &ps)
    {
        in >> ps.gio >> ps.phut >> ps.giay;
        return in;
    }

    friend ostream& operator << (ostream &os, const Dong_Ho &x)
    {
        os << x.gio << "/" << x.phut << "/" << x.giay << endl;
        return os;
    }
    friend Dong_Ho operator++(Dong_Ho &c)
    {

        c.giay = c.gio*3600 + c.phut*60 + c.giay;
        c.giay = c.giay + 1;
        c.Change(c.gio, c.phut, c.giay);
        return c;
    }
    friend Dong_Ho operator--(Dong_Ho &c)
    {

        c.giay = c.gio*3600 + c.phut*60 + c.giay;
        c.giay = c.giay - 1;
        c.Change(c.gio, c.phut, c.giay);
        return c;
    }
};

void Dong_Ho :: Nhap()
{
    cin >> gio >> phut >> giay;
    if(gio > 24)
        gio = gio % 24;
    if(phut > 60)
        phut = phut % 60;
    if(giay > 60)
        giay = giay % 60;
    gio = abs(gio);
    phut = abs(phut);
    giay = abs(giay);
    giay = gio*3600 + phut*60 + giay;
    Change(gio, phut, giay);
}

void Dong_Ho ::Xuat()
{
    if(gio > 24)
        gio = gio % 24;
    if(phut > 60)
        phut = phut % 60;
    if(giay > 60)
        giay = giay % 60;
    gio = abs(gio);
    phut = abs(phut);
    giay = abs(giay);
    giay = gio*3600 + phut*60 + giay;
    Change(gio, phut, giay);
    cout << gio << "/" << phut << "/" << giay << endl;
}

Dong_Ho operator+(Dong_Ho a, Dong_Ho b)
{
    Dong_Ho c;
    a.giay = a.gio * 3600 + a.phut * 60 + a.giay;
    b.giay = b.gio * 3600 + b.phut * 60 + b.giay;
    c.giay = a.giay + b.giay;
    c.Change(c.gio, c.phut, c.giay);
    return c;
}

Dong_Ho operator-(Dong_Ho a, Dong_Ho b)
{
    Dong_Ho c;
    a.giay = a.gio * 3600 + a.phut * 60 + a.giay;
    b.giay = b.gio * 3600 + b.phut * 60 + b.giay;
    c.giay = a.giay - b.giay;
    c.Change(c.gio, c.phut, c.giay);
    return c;
}

bool operator>(Dong_Ho a, Dong_Ho b)
{
    a.giay = a.gio * 3600 + a.phut * 60 + a.giay;
    b.giay = b.gio * 3600 + b.phut * 60 + b.giay;
    return a.giay > b.giay;
}

bool operator<(Dong_Ho a, Dong_Ho b)
{
    a.giay = a.gio * 3600 + a.phut * 60 + a.giay;
    b.giay = b.gio * 3600 + b.phut * 60 + b.giay;
    return a.giay < b.giay;
}

bool operator==(Dong_Ho a, Dong_Ho b)
{
    a.giay = a.gio * 3600 + a.phut * 60 + a.giay;
    b.giay = b.gio * 3600 + b.phut * 60 + b.giay;
    return a.giay == b.giay;
}

int Compare(Dong_Ho a, Dong_Ho b)
{
    if(a > b)
        return 1;
    else if(a < b)
        return -1;
    else
        return 0;
}

void Dong_Ho ::Change(int &a, int &b, int &c)
{
    a = c/3600;
    c = c%3600;
    b = c/60;
    c = c%60;
}

int main()
{
    Dong_Ho a;
    Dong_Ho b;
    a.Nhap();
    b.Nhap();
    a.Xuat();
    b.Xuat();
    Dong_Ho kq, kq1;
    kq = a+b;
    kq1 = a - b;
    kq.Xuat();
    kq1.Xuat();
    int kq2 = Compare(a, b);
    if(kq2 == 1)
        cout << "Lon hon\n";
    else if(kq2 == -1)
        cout << "Nho hon\n";
    else
        cout << "Bang nhau\n";
    a = ++a;
    b = --b;
    a.Xuat();
    b.Xuat();
    return 0;
}

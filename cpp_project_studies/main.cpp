#include <iostream>
#include <cstdlib>
#include <cmath>

#define MAX_N 10000

int tab_int[MAX_N];
int new_tab[MAX_N];
unsigned long long tab_naturals[MAX_N];
double tab_double[MAX_N];
using namespace std;

void read(int n)
{
    cout << "Wprowadz " << n << " liczb po spacji: ";
    for(int i=0;i<n;i=i+1)
	    cin >> tab_int[i];
}

struct punkty
{
    long double x,y;
}tab_points[MAX_N];

void read_points(int n)
{
    cout << "WPROWADZAJ PUNKTY PO KOLEI" << endl;
    for(int i=0; i<n; i=i+1)
    {
        cout << "Podaj wspolrzedne " << i+1 << " punktu: " << endl;
        cout << "Wprowadz wspolrzedna x: ";
        cin >> tab_points[i].x;
        cout << "Wprowadz wspolrzedna y: ";
        cin>> tab_points[i].y;
    }
}

void read_naturals(int n)
{
    cout << "Wprowadz " << n << " liczby po spacji: ";
    for(int i=0;i<n;i=i+1)
    {
        cin >> tab_naturals[i];
    }

}

int f0(int n,int tab_empty)
{
    int min_index=0,minimum;

    if(tab_empty==1)
        read(n);

    for(int i=0;i<n;i=i+1)
        if(tab_int[i] < tab_int[min_index])
            min_index = i;
	if(tab_empty==1)
    {
        minimum = tab_int[min_index];
        cout << "Pozycja zawieraj¹ca najmniejsza wartosc: ";
        for(int i=0;i<n;i=i=i+1)
            if(tab_int[i]==minimum)
                cout << i+1 << endl;
        return 0;
    }
    else
        return min_index;
}

void f1(int n)
{
    read(n);
    int index, m;
    m = n;
    for(int i=0;i<n;i=i+1)
    {
        index = f0(m,0);
        m = m - 1;
        new_tab[m]=tab_int[index];
        for(int x=index; x<m; x=x+1)
            tab_int[x]=tab_int[x+1];
    }
    cout << "Posortowany ciag liczb: ";
    for(int j=0;j<n;j=j+1)
        cout << new_tab[j] << " ";
    cout << endl;
}

int f2(int n, int tab_empty)
{
    int sum=0,result;
    if(tab_empty==1)
        read(n);
    for(int i=0;i<(n);i=i+1)
        sum = sum + (tab_int[i] * tab_int[i]);

    if(tab_empty==1)
    {
        result = sqrt(sum);
        cout << "Dlugosc euklidesowa: " << result << endl;
        return 0;
    }
    else
        return sum;
}
void f3(int n)
{
    int sum1=0,sum2,sigma;
    read(n);
    for(int i=0;i<n;i=i+1)
        sum1 = sum1 + tab_int[i];
    sum2 = f2(n,0);
    sigma=sqrt(double(sum2-(sum1*sum1)/(n*n)));
    cout << "Odchylenie standardowe: ";
    cout << floor(sigma) << endl;
}

void f4(int n)
{
    read(n);
    int sub, last;
    last = n-1;
    for(int i=0; i<n/2; i=i+1)
    {
        sub=tab_int[last];
        tab_int[last]=tab_int[i];
        tab_int[i]=sub;
        last=last-1;
    }
    cout << "Odwrocony ciag liczb: ";
    for(int i=0; i<n; i=i+1)
        cout << tab_int[i] << " ";
    cout<<endl;
}

void f5(int n)
{
    read(n);
    for(int i=0;i<n;i=i+1)
    {
        int is_prime = 1;
        if(tab_int[i]==0 || tab_int[i]==1)
            cout<<"Liczba " << tab_int[i] << " nie jest pierwsza" << endl;
        else
        {
            for(int j=2;j<=sqrt(tab_int[i]);j=j+1)
                if(tab_int[i]%j==0)
                {
                    is_prime= 0;
                    cout << "Liczba " << tab_int[i] << " nie jest pierwsza" << endl;
                    break;
                }
            if(is_prime==1)
                cout<<"Liczba " << tab_int[i] << " jest pierwsza" << endl;
        }
    }
     cout<<endl;
}

void f6(int n)
{
    long double  result, sum=0;
    int last,j;
    read_points(n);
    last=n;
    for(int i=0; i<last; i=i+1)
    {
        j = (i+1);
        if(j==last)
            j=0;
        sum = sum +(tab_points[i].x * tab_points[j].y - tab_points[j].x * tab_points[i].y);
    }
    if(sum<0)
        sum=sum*-1;
    result = sum/2;
    cout<<"Pole wielokata: " << floor(result)<<endl;
}

void f7()
{
    double a,b,c,d;
    cout << "Wprowadz a: ";
    cin >> a;
    cout << "Wprowadz b: ";
    cin >> b;
    cout << "Wprowadz c: ";
    cin >> c;

    if(a==0)
        NULL;
    else
    {
        double delta,x1,x2,x;
        delta = b*b-4*a*c;
        if(delta>0)
        {
            x1=(-b-sqrt(delta))/(2*a);
            x2=(-b+sqrt(delta))/(2*a);
            if(x1<x2)
                cout << floor(x1) << " " << floor(x2);
            else
                cout << floor(x2) << " " << floor(x1);
        }
        else if(delta==0)
        {
            x = -b/(2*a);
            cout << x;
        }
        else
            cout << "Nie ma rozwiazan";
    }
    cout << endl;
}

unsigned long long f8(int n)
{
    if(n==0)
        return 0;
    else
        return f8(n-1)+n*(n+1)*(n+1);
}
void f9(int n)
{
    unsigned int number;
    int sum_bits = 0;
    number = n;
    while(number != 0)
    {
        if(number%2==1)
            sum_bits=sum_bits+1;
        number = number / 2;
    }
    cout << "Liczba bitow dla " << n << " wynosi: " << sum_bits << " ";
    cout << endl;
}


int main()
{
    cout <<"Operacje do wyboru: " << endl;
    cout << "0 - ZnajdŸ pozycje zawieraj¹ce najmniejsza wartosc dla wejsciowego ciagu liczb" << endl;
    cout <<"1 - Posortuj wejsciowy ciag liczb" << endl;
    cout <<"2 - Znajdz d³ugosc euklidesowa wektora" << endl;
    cout <<"3 - Znajdz odchylenie standardowe dla wejsciowego ciagu liczb" << endl;
    cout <<"4 - Zapisz podany wejsciowy ciag liczbowy w tablicy i odwroc go w miejscu" << endl;
    cout <<"5 - Odpowiedz, czy liczba jest pierwsza" << endl;
    cout <<"6 - Znajdz pole wielokata wypuklego" << endl;
    cout <<"7 - Rozwiaz rownanie kwadratowe" << endl;
    cout <<"8 - Wyznacz wartosc wyrazenia 1*2^2 + 2*3^2 + ... + n(n+1)^2 dla zadanego n" << endl;
    cout <<"9 - Zlicz liczbe ustawionych bitow w liczbie naturalnej" << endl << endl;
int subprogram, n;
while(true)
    {
        cout << "Jaka operacje chcesz wykonac? ";
        cin >> subprogram;
        switch (subprogram)
        {
        case 0:
            cout << "Ile liczb chcesz wprowadzic? ";
            cin >> n;
            f0(n,1);
            cout << endl;
            break;
        case 1:
            cout << "Ile liczb chcesz wprowadzic? ";
            cin >> n;
            f1(n);
            cout << endl;
            break;
        case 2:
            cout << "Ile liczb chcesz wprowadzic? ";
            cin >> n;
            f2(n,1);
            cout << endl;
            break;
        case 3:
            cout << "Ile liczb chcesz wprowadzic? ";
            cin >> n;
            f3(n);
            cout << endl;
            break;
        case 4:
            cout << "Ile liczb chcesz wprowadzic? ";
            cin >> n;
            f4(n);
            cout << endl;
            break;
        case 5:
            cout << "Ile liczb chcesz wprowadzic? ";
            cin >> n;
            f5(n);
            cout << endl;
            break;
        case 6:
            cout << "Ile punktow chcesz wprowadzic? ";
            cin >> n;
            f6(n);
            cout << endl;
            break;
        case 7:
            f7();
            cout << endl;
            break;
        case 8:
            cout << "Podaj 'n': ";
            cin >> n;
            cout << "Wynik: " << f8(n) << endl << endl;
            break;
        case 9:
            cout << "Jaka liczbe chcesz sprawdzic? ";
            cin >> n;
            f9(n);
            cout << endl;
            break;
        }
    }
return 0;
}


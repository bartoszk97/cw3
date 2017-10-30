#include <iostream>
#include <sstream>
#include <fstream>
#include <vector>
#include <string>
#include <stdexcept>

using namespace std;
int main(int argc, char* argv[])

struct Probka
{
    double x1, x2;
    string linia;
    typedef pair <double,double> Probka;
    ifstream plik("sygnal.csv");
    vector <Probka> dane;
    while (getline(plik, linia))
    {
        stringstream ss(linia);
        ss >> x1;
        ss.ignore();
        ss >> x2;
dane.push_back(Probka(x1, x2));

    }
    plik.close();
    return dane;
}

void wyswietl (const vector<Probka>& dane)
{
    for (int i = 0; i < dane.size(); ++i)
        {
            cout << dane[i].t << ", " << dane[i].x << endl;
        }
}

void zapisz (const vector<Probka>& dane, const string& nazwa_pliku)
{
    ofstream plik;
    plik.open(nazwa_pliku.c_str(), ios::out);
    for (int i = 0; i < dane.size(); ++i)
        {
            plik << dane[i].t << ", " << dane[i].x << endl;
        }
    plik.close();
}



double maksimum(const vector <Probka>& dane)
{
    double _max = -1000000;
    for ( int i=0; i<dane.size(); i++)
        {
            if (dane[i].x > _max)
            _max = dane[i].x;
        }
    return _max;
}

double minimum(const vector <Probka>& dane)
{
    double _min = 10000000;
    for ( int i=0; i<dane.size(); i++)
        {
            if (dane[i].x < _min)
                _min = dane[i].x;
        }
    return _min;
}

double srednia (const vector<Probka>& dane)
{
    double m = 0.0;
    for (int i = 0; i < dane.size(); ++i)
        {
            m += dane[i].x;
        }
    if (dane.size() > 0)
        {
            m = m / dane.size();
        }
    return m;
}

int main ()
{
    string o_nazwa, z_nazwa;
    cout << "Plik odczytowy(-.csv) : "; cin >> o_nazwa;
    cout << "Plik zapisowy(-.csv) : "; cin >> z_nazwa;
    wyswietl (wczytaj(o_nazwa));
    cout << "Maksimum : " << maksimum(wczytaj(o_nazwa)) << endl;
    cout << "Minimum : " << minimum (wczytaj(o_nazwa)) << endl;
    cout << "Srednia : " << srednia (wczytaj(o_nazwa)) <<  endl;
    zapisz (wczytaj (o_nazwa), z_nazwa);
}

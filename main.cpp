#include <iostream>
#include <fstream>
#include <string>

using namespace std;

// klasa sprawdzajaca listy imion
class checker {
public:
    string lista1[10];
    string lista2[10];

    // funkcja wczytujaca imiona z plikow
    void wczytaj() {
        ifstream plik1("lista1.txt");
        ifstream plik2("lista2.txt");

        // wczytanie 10 imion z kazdego pliku
        for (int i = 0; i < 10; i++) {
            getline(plik1, lista1[i]);
            getline(plik2, lista2[i]);
        }

        plik1.close();
        plik2.close();
    }

    // funkcja zapisujaca raport do pliku
    void raport() {
        ofstream wynik("wynik.txt");

        // wyswietlenie imion wspolnych
        wynik << "IMIONA WSPOLNE:" << endl;
        for (int i = 0; i < 10; i++) {
            for (int j = 0; j < 10; j++) {
                if (lista1[i] == lista2[j]) {
                    wynik << lista1[i] << endl;
                    break;
                }
            }
        }

        // imiona tylko z pierwszego pliku
        wynik << "\nTYLKO W PLIKU 1:" << endl;
        for (int i = 0; i < 10; i++) {
            bool znaleziono = false;

            // sprawdzanie, czy imiona sa na drugiej liscie
            for (int j = 0; j < 10; j++) {
                if (lista1[i] == lista2[j]) {
                    znaleziono = true;
                }
            }

            if (znaleziono == false) {
                wynik << lista1[i] << endl;
            }
        }

        // imiona tylko z drugiego pliku
        wynik << "\nTYLKO W PLIKU 2:" << endl;
        for (int i = 0; i < 10; i++) {
            bool znaleziono = false;

            // sprawdzanie, czy imiona sa na pierwszej liscie
            for (int j = 0; j < 10; j++) {
                if (lista2[i] == lista1[j]) {
                    znaleziono = true;
                }
            }

            if (znaleziono == false) {
                wynik << lista2[i] << endl;
            }
        }

        wynik.close();
    }
};

int main() {
    checker c;

    c.wczytaj();
    c.raport();

    cout << "Wyniki zapisano do pliku" << endl;

    return 0;
}


// lab_6.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#define _USE_MATH_DEFINES
#include <iostream>
#include <math.h>

struct Lzespolona {
    double rzeczywista;
    double urojona;
} liczba;

int menu();
void wypisz_z(Lzespolona liczba);
void wypelnij(Lzespolona t[], int rozmiar);
void wczytaj(Lzespolona t[], int rozmiar);
void wydrukuj(Lzespolona t[], int rozmiar);
double modul(Lzespolona & liczba);
double argument(Lzespolona& liczba);
Lzespolona suma(const Lzespolona& a, const Lzespolona & b);
Lzespolona iloczyn(const Lzespolona& a, const Lzespolona& b);

int main()
{
    srand(time(nullptr));
    const int n = 10;
    Lzespolona zespolone[n];
    bool wygenerowana = false;
    int k = 0;
    do {
        int wybor = menu();
        std::cout << "\n";
        switch (wybor) {
        case 1:
            wypelnij(zespolone, n);
            wygenerowana = true;
            break;
        case 2:
            wczytaj(zespolone, n);
            wygenerowana = true;
            break;
        case 3:
            if (wygenerowana) {
                wydrukuj(zespolone, n);
            }
            else {
                std::cout << "Tablica nie ma jeszcze zadnych wartosci\n";
            }
            break;
        case 4:
            if (wygenerowana) {
                int a;
                std::cout << "Podaj ktora liczbe z tablicy: ";
                std::cin >> a;
                std::cout << modul(zespolone[a-1]);
                std::cout << "\n";
            }
            else {
                std::cout << "Tablica nie ma jeszcze zadnych wartosci\n";
            }
            break;
        case 5:
            if (wygenerowana) {
                int a;
                std::cout << "Podaj ktora liczbe z tablicy: ";
                std::cin >> a;
                std::cout << argument(zespolone[a - 1]);
                std::cout << "\n";
            }
            else {
                std::cout << "Tablica nie ma jeszcze zadnych wartosci\n";
            }
            break;
        case 6:
            if (wygenerowana) {
                int a, b;
                std::cout << "Podaj ktore liczby z tablicy: ";
                std::cin >> a;
                std::cin >> b;
                wypisz_z(suma(zespolone[a - 1], zespolone[b-1]));
                std::cout << "\n";
            }
            else {
                std::cout << "Tablica nie ma jeszcze zadnych wartosci\n";
            }
            break;
        case 7:
            if (wygenerowana) {
                int a, b;
                std::cout << "Podaj ktore liczby z tablicy: ";
                std::cin >> a;
                std::cin >> b;
                wypisz_z(iloczyn(zespolone[a - 1], zespolone[b - 1]));
                std::cout << "\n";
            }
            else {
                std::cout << "Tablica nie ma jeszcze zadnych wartosci\n";
            }
            break;
        case 8:
            k = 8;
            break;
        }
    } while (k != 8);
}

void wypisz_z(Lzespolona liczba) {
    if (liczba.rzeczywista == 0 and liczba.urojona != 0) {
        std::cout << liczba.urojona << "i\n";
    }
    else if (liczba.rzeczywista != 0 and liczba.urojona > 0) {
        std::cout << liczba.rzeczywista << "+" << liczba.urojona << "i\n";
    }
    else if (liczba.rzeczywista != 0 and liczba.urojona < 0) {
        std::cout << liczba.rzeczywista << liczba.urojona << "i\n";
    }
    else if (liczba.rzeczywista != 0 and liczba.urojona == 0) {
        std::cout << liczba.rzeczywista;
    }
    else if(liczba.rzeczywista == 0 and liczba.urojona == 0) {
        std::cout << "0";
    }
}

int menu() {
    std::cout << "---------------------------\n";
    std::cout << "Co chcesz zrobic?\n";
    std::cout << "1 - Wygeneruj tablice z losowymi liczbami zespolonymi\n";
    std::cout << "2 - Recznie wypelnij tablice liczbami zespolonymi\n";
    std::cout << "3 - Wydrukuj tablice liczb zespolonych\n";
    std::cout << "4 - Oblicz modul danej liczby z tablicy\n";
    std::cout << "5 - Oblicz argument danej liczby z tablice\n";
    std::cout << "6 - Zsumuj dwie liczby z tablicy\n";
    std::cout << "7 - Pomnoz dwie liczby z tablicy\n";
    std::cout << "8 - Zakoncz\n";
    int input;
    std::cin >> input;
    return input;
}

void wypelnij(Lzespolona t[], int rozmiar) {
    for (int i = 0; i < rozmiar; i++) {
        Lzespolona liczba;
        liczba.rzeczywista = (rand() % 100 - 10)/10.0;
        liczba.urojona = (rand() % 100 - 10)/10.0;
        t[i] = liczba;
     }
}

void wczytaj(Lzespolona t[], int rozmiar) {
    for (int i = 0; i < rozmiar; i++) {
        Lzespolona liczba;
        double temp;
        std::cout << "Rzeczywista?: ";
        std::cin >> temp;
        liczba.rzeczywista = temp;
        std::cout << "Urojona?: ";
        std::cin >> temp;
        liczba.urojona = temp;
        t[i] = liczba;
    }
}

void wydrukuj(Lzespolona t[], int rozmiar) {
    for (int i = 0; i < rozmiar; i++) {
        wypisz_z(t[i]);
    }
}

double modul(Lzespolona& liczba) {
   return sqrt(pow(liczba.rzeczywista, 2) + pow(liczba.urojona, 2));
}

double argument(Lzespolona& liczba) {
    if (liczba.rzeczywista > 0) {
        return atan(liczba.urojona / liczba.rzeczywista);
    }
    else if(liczba.rzeczywista < 0){
        return atan(liczba.urojona / liczba.rzeczywista) + M_PI;
    }
    else if (liczba.rzeczywista == 0) {
        if (liczba.urojona > 0) {
            return 0;
        }
        else {
            return M_PI;
        }
    }
}

Lzespolona suma(const Lzespolona& a, const Lzespolona& b) {
    Lzespolona zsumowana;
    zsumowana.rzeczywista = a.rzeczywista + b.rzeczywista;
    zsumowana.urojona = a.urojona + b.urojona;
    return zsumowana;
}

Lzespolona iloczyn(const Lzespolona& a, const Lzespolona& b) {
    Lzespolona pomnozona;
    pomnozona.rzeczywista = (a.rzeczywista * b.rzeczywista) + (-1 * (a.urojona * b.urojona));
    pomnozona.urojona = (a.rzeczywista * b.urojona) + (a.urojona * b.rzeczywista);
    return pomnozona;
}

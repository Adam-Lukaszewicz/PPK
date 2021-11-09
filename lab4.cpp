
#include <iostream>
#include <algorithm>
void zad1() {
    int T[100], o = 0, r = 0, streak = 0;
    for (int i = 0; i < 100; i++) {
        T[i] = rand() % 2;
        if (T[i] == 0) {
            o++;
        }
        else {
            r++;
        }
        if (i >= 3) { // to mozna zrobic lepiej (petla nie do konca tylko do n - 3 i sprawdzaj do przodu nie do tylu
            if (T[i - 3] + T[i - 2] + T[i - 1] + T[i] == 4) { // mozna sprawdzac boolowo
                streak = 1;
            }
        }
    }

    std::cout << "Prawdopodobienstwo reszki " << double(r)/100 << "\n";
    if (streak) {
        std::cout << "By³a seria reszek";
    }
    else {
        std::cout << "Nie by³o serii";
    }
}

void zad2() {
    int T[100], six = 0, onetwo = 0, choice;
    for (int i = 0; i < 100; i++) {
        T[i] = rand() % 6 + 1;
        if (T[i] == 6) {
            six++;
        }
        if (T[i] == 1 or T[i] == 2) {
            onetwo++;
        }
    }
    std::cout << "Co chcesz zrobic\n1-szostki  2 - 1/2\n";
    std::cin >> choice;
    switch (choice) {
    case 1:
        std::cout << "Ilosc 6: " << six;
        break;
    case 2:
        std::cout << "Prawdopodobienstwo 1 lub 2: " << double(onetwo)/100;
    }
}

void zad3() {
    double T[12], kwartal = 0;
    int choice;
    for(int i = 0; i < 12; i++){
        std::cin >> T[i];
    }
    std::cout << "Co chcesz zrobic\n1-kwartaly  2 - roznica\n";
    std::cin >> choice;
    switch (choice) {
    case 1:
        for (int i = 0; i < 12; i++) {
            kwartal += T[i];
            if((i+1)%3 == 0){
                std::cout << "Kwartal " << (i + 1) / 3 << " = " << kwartal << "\n";
                kwartal = 0;
            }
        }
        break;
    case 2:
        double maks, min;
        for (int i = 0; i < 12; i++) {
            if (i == 0) {
                min = T[i];
                maks = T[i];
            }
            if (T[i] > maks) {
                maks = T[i];
            }
            if (T[i] < min) {
                min = T[i];
            }
        }
        std::cout << "Roznica: " << maks - min;
        break;
    }
}
void zad4() {
    const int n = 30;
    char T[n]; //97-122
    int choice;
    bool duo = false;
    for (int i = 0; i < n; i++) {
        T[i] = char(rand() % 26 + 97);
    }
    std::cout << "Co chcesz zrobic\n1-odwrot  2 - dwie te same\n";
    std::cin >> choice;
    switch (choice) {
    case 1:
        for (int i = n-1; i >= 0; i--) {
            std::cout << T[i];
        }
        break;
    case 2:
        for (int i = 0; i < n - 1; i++) {
            if (T[i] == T[i + 1]) {
                duo = true;
            }
        }
        if (duo) {
            std::cout << "Sa dwie obok siebie";
        }
        else {
            std::cout << "Nie ma";
        }
        break;
    }
}

void zad5(){
    const int n = 100;
    int T[n], six = 0, one = 0, two = 0, three = 0, four = 0, five = 0, maks = 0;
    for (int i = 0; i < n; i++) {
        T[i] = rand() % 6 + 1;
        if (T[i] == 6) {
            six++;
        }
        if (T[i] == 1 ) {
            one++;
        }
        if (T[i] == 2) {
            two++;
        }
        if (T[i] == 3) {
            three++;
        }
        if (T[i] == 4) {
            four++;
        }
        if (T[i] == 5) {
            five++;
        }
    }
    std::cout << "Prawdopodobientswo szostki = " << double(six) / n;
    //szukanie najwiekszej sposrod zmiennych - obczaj w domu
}
int main()
{
    srand(time(nullptr)); //zawsze jak uzywasz randa

    zad5();
}

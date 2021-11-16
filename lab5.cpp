

#include <iostream>
#include <vector>
#include <math.h>

bool pierwsza(int liczba) {
    bool wynik = true;
    for (int i = 2; i*i <= liczba; i++) {
        if (liczba % i == 0) {
            wynik = false;
        }
    }
    return wynik;
}

void los_tablica(int T[], int size, int p, int k) {
    //int L = sizeof(T) / sizeof(int);
    for (int i = 0; i < size; i++) {
        T[i] = rand() % (k-p+1) + p;
    }
}

void wyp_tablica(int T[], int size) {
    //int L = sizeof(T) / sizeof(int);
    for (int i = 0; i < size; i++) {
        std::cout << T[i] << " ";
    }
    std::cout << "\n";
}

void sort_tablica(int T[], int size) {
    for (int i = 0; i < size-1; i++) {
        
    }
}

int Fibonacci_rek(int n) {
    if (n == 0 or n == 1) {
        return n;
    }
    else
        return Fibonacci_rek(n - 1) + Fibonacci_rek(n - 2);
}
int Fibonacci_ite(int n) {
    return 0;
}

double rownanie_kwadratowe(double a, double b, double c) {
    double x1, x2;
    double delta = b * b - (4 * a * c);
    if (delta < 0) {
        std::cout << "Delta mniejsza niz 0, brak rozwiazan";
        return 0;
    }
    else if (delta==0){
        x1 = (-1 * b) / (2 * a);
        x2 = x1;
    }
    else {
        x1 = ((-1 * b) - sqrt(delta)) / (2 * a);
        x2 = ((-1 * b) + sqrt(delta)) / (2 * a);
    }
}

void los_vector(std::vector<int> &w, int size, int p, int k) {
    for (int i = 0; i < size; i++) {
        w.push_back(rand() % (k - p + 1) + p); 
    }
}
void wyp_vector(std::vector<int>& w) {
    for (auto el:w) {
        std::cout << el << " ";
    }
    std::cout << "\n";
}
void pier_vector(std::vector<int>& w) {
    for (auto el : w) {
        if (pierwsza(el)) {
            std::cout << el << " ";
        }
    }
    std::cout << "\n";
}

void multipier(int n) {
    for (int i = 2; i <= n; i++) {
        if (pierwsza(i)) {
            std::cout << i << " ";
        }
    }
    std::cout << "\n";
}

void Pascal(std::vector<int>& w, int wiersze) {
    w.push_back(1);
    wyp_vector(w);
    for (int i = 0; i < wiersze-1; i++) {
        for (int i = w.size()-1; i > 0; i--) {
            w[i] = w[i] + w[i - 1];
        }
        w.push_back(1);
        wyp_vector(w);
    }
}

int main()
{
    srand(time(nullptr));
    const int n = 10;
    int T[n];
    std::vector<int> wektor;
    std::vector<int> trojkat;
    //los_tablica(T, n, 1, 10);
    //wyp_tablica(T, n);
    //sort_tablica(T, n);
    //wyp_tablica(T, n);
    //std::cout << Fibonacci_rek(14);
    //los_vector(wektor, 20, 5, 20);
    //wyp_vector(wektor);
    //pier_vector(wektor);
    //multipier(50);
    Pascal(trojkat, 5);
}


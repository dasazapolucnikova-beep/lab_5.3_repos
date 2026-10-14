#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

double p(const double x);

int main()
{
    double qp, qk, z;
    int n;

    cout << "qp = "; cin >> qp;
    cout << "qk = "; cin >> qk;
    cout << "n = "; cin >> n;

    double dq = (qk - qp) / n;
    double q = qp;

    // Шапка таблиці
    cout << endl;
    cout << "-------------------------" << endl;
    cout << "|" << setw(10) << "q" << " |" << setw(10) << "z" << " |" << endl;
    cout << "-------------------------" << endl;

    // Обчислення та вивід рядків таблиці
    for (int i = 0; i <= n; i++)
    {
        z = p(2 * q + 1) + pow(p(q * q - 1), 2) + sqrt(p(1));

        cout << "|" << setw(10) << fixed << setprecision(4) << q
            << " |" << setw(10) << setprecision(4) << z << " |" << endl;

        q += dq;
    }

    cout << "-------------------------" << endl;

    return 0;
}

double p(const double x)
{
    if (abs(x) >= 1)
    {
        return (sin(x) + cos(x)) / (pow(sin(x), 2) + exp(x));
    }
    else
    {
        double S = 0;
        double a = 1; // j = 0, a_0 = 1
        S = a;

        int j = 0;
        do
        {
            j++;
            // Рекурентне співвідношення для (-1)^j * x^(2j) / (2j)!
            double R = -(x * x) / ((2 * j - 1) * (2 * j));
            a *= R;
            S += a;
        } while (j < 4);

        return (1.0 / cos(x)) * S;
    }
}
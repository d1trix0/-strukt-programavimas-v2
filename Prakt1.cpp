#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

const double GBP_Bendras = 0.8729;
const double GBP_Pirkti = 0.8600;
const double GBP_Parduoti = 0.9220;

const double USD_Bendras = 1.1793;
const double USD_Pirkti = 1.1460;
const double USD_Parduoti = 1.2340;

const double INR_Bendras = 104.6918;
const double INR_Pirkti = 101.3862;
const double INR_Parduoti = 107.8546;

int main() {
    cout << "\n===== EXCHANGE RATES =====\n";

    cout << "USD: 1 EUR = " << USD_Bendras << " USD;" << " 1 USD = " << 1.0 / USD_Bendras << " EUR\n";

    cout << "GBP: 1 EUR = " << GBP_Bendras << " GBP;" << " 1 GBP = " << 1.0 / GBP_Bendras << " EUR\n";

    cout << "INR: 1 EUR = " << INR_Bendras << " INR;" << " 1 INR = " << 1.0 / INR_Bendras << " EUR\n";
    int money;
    int valuet = -1;
    int getValuet;
    double eur;
    double result;
    double buyRate, sellRate;

    cout << fixed << setprecision(2);

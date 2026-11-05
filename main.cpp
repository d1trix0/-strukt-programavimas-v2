#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

const int MAX_MOKINIU = 100;
const int MAX_PAZYMIU = 10;
// logikos patikrinimos
int nuskaitytiSkaiciu(string pranesimas, int nuo, int iki)
{
    int skaicius;

    while (true)
    {
        cout << pranesimas;
        cin >> skaicius;

        if (cin.fail())
        {
            cin.clear();
            cin.ignore(1000, '\n');
        }
        else if (skaicius >= nuo && skaicius <= iki)
        {
            return skaicius;
        }

        cout << "Neteisinga ivestis. Iveskite skaiciu nuo "
             << nuo << " iki " << iki << ".\n";
    }
}
// funkc 1
int pasirinktiMokini(string vardai[], int mokiniuKiekis)
{
    cout << "Mokiniai:\n";
    for (int i = 0; i < mokiniuKiekis; i++)
    {
        cout << i + 1 << ". " << vardai[i] << endl;
    }

    return nuskaitytiSkaiciu(
        "Mokinio numeris: ", 1, mokiniuKiekis) - 1;
}
// new mokinis
void ivestiMokini(
    string vardai[],
    int pazymiai[][MAX_PAZYMIU],
    int pazymiuKiekiai[],
    int& mokiniuKiekis)
{
    if (mokiniuKiekis == MAX_MOKINIU)
    {
        cout << "Mokiniu sarasas pilnas.\n";
        return;
    }

    cin.ignore(1000, '\n');
    cout << "Iveskite mokinio varda: ";
    getline(cin, vardai[mokiniuKiekis]);
    // pazimio patikrinimas
    pazymiuKiekiai[mokiniuKiekis] = nuskaitytiSkaiciu(
        "Kiek mokinys turi pazymiu (0-10)? ", 0, MAX_PAZYMIU);

    for (int i = 0; i < pazymiuKiekiai[mokiniuKiekis]; i++)
    {
        pazymiai[mokiniuKiekis][i] = nuskaitytiSkaiciu(
            "Iveskite pazymi nuo 1 iki 10: ", 1, 10);
    }

    mokiniuKiekis++;
    cout << "Mokinys pridetas.\n";
}
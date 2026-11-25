#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
using namespace std;




double PrekesSuma(double kaina, int kiekis) {
	
	
	return kaina * kiekis;
}


double Nuolaida(int kiekis, double suma) {

	if (kiekis >= 10) {
		return suma * 0.10;
	}
	else {
		return 0;
	}
}
double KategorijosSuma(string Kategorija[], double kaina[], int kiekis[], int n , string ieskomas ) 
{
	double suma = 0;
	for (int i = 0; i < n; i++) {
		if (Kategorija[i] == ieskomas) {
			double prekesSuma = PrekesSuma(kaina[i], kiekis[i]);
			double nuolaida = Nuolaida(kiekis[i], prekesSuma);

			suma += prekesSuma - nuolaida;
		}
	}
	return suma;
}


int main() {

	string kategorija[100];
	string varda[100];
	double kaina[100];
	int kiekis[100];
	int n;





	ifstream f("uzsakymas.txt");
	if (!f.is_open()) {
		cout << "Failure" << endl;
		return 1;
	}
	f >> n;
	f.ignore(1000, '\n');
	cout << "Priekiu kiekis :" << n << endl;
	cout << "-------------------------" << endl;
	if (n < 1 || n > 100) {
		cout << "Klaida: netinkamas prekiu kiekis" << endl;
		return 1;
	}





	for (int i = 0; i < n; i++) {
		getline(f, kategorija[i], ';');
		getline(f, varda[i], ';');
		f >> kaina[i];
		f.ignore(1, ';');
		f >> kiekis[i];
		f.ignore(1000, '\n');

	}
	int pasirinkimas;

	do {
		cout << "========== MENIU ==========" << endl;
		cout << "1. Visi produktai" << endl;
		cout << "2. Pasirinkti kategorija" << endl;
		cout << "3. Kategoriju sumos" << endl;
		cout << "4. Visa ataskaita" << endl;
		cout << "5. Baigti programa" << endl;
		cout << "Pasirinkite: ";

		cin >> pasirinkimas;

		switch (pasirinkimas) {

		case 1:
			cout << "Prekiu informacija: " << endl;
			cout << "________________________________________________________________________" << endl;

			for (int i = 0; i < n; i++) {
				double suma = PrekesSuma(kaina[i], kiekis[i]);
				double nuolaida = Nuolaida(kiekis[i], suma);

				cout << "Kategorija: " << i + 1 << ": " << kategorija[i] << endl;
				cout << "Varda: " << varda[i] << endl;
				cout << "Kaina: " << fixed << setprecision(2) << kaina[i] << endl;
				cout << "Kiekis: " << kiekis[i] << endl;
				cout << "Suma: " << suma << endl;
				cout << "Nuolaida: " << nuolaida << endl;
				cout << "Galutine suma: " << suma - nuolaida << endl;
				cout << "-------------------------" << endl;
			}
			break;

		case 2:{
			string pasirinktaKategorija;

			cout << "Pasirinkite kategorija:" << endl;
			cout << "1. Dviraciai" << endl;
			cout << "2. Dalys" << endl;
			cout << "3. Aksesuarai" << endl;

			int pasirinkimas2;
			cin >> pasirinkimas2;

			switch (pasirinkimas2) {
			case 1:
				pasirinktaKategorija = "Dviraciai";
				break;

			case 2:
				pasirinktaKategorija = "Dalys";
				break;

			case 3:
				pasirinktaKategorija = "Aksesuarai";
				break;

			default:
				cout << "Neteisingas pasirinkimas!" << endl;
				break;
			}

			for (int i = 0; i < n; i++) {
				if (kategorija[i] == pasirinktaKategorija) {
					cout << varda[i] << " | "
						<< kaina[i] << " | "
						<< kiekis[i] << endl;
				}
			}

			break;
		}

		case 3:
			cout << fixed << setprecision(2);

			cout << "Dviraciai: "
				<< KategorijosSuma(kategorija, kaina, kiekis, n, "Dviraciai") << " EUR" << endl;

			cout << "Dalys: "
				<< KategorijosSuma(kategorija, kaina, kiekis, n, "Dalys") << " EUR" << endl;

			cout << "Aksesuarai: "
				<< KategorijosSuma(kategorija, kaina, kiekis, n, "Aksesuarai") << " EUR" << endl;

			break;
		case 4:{
			double bendraSuma = 0;
			double bendraNuolaida = 0;

			cout << fixed << setprecision(2);

			cout << "\n========== VISA ATASKAITA ==========" << endl;

			for (int i = 0; i < n; i++) {
				double suma = PrekesSuma(kaina[i], kiekis[i]);
				double nuolaida = Nuolaida(kiekis[i], suma);

				bendraSuma += suma;
				bendraNuolaida += nuolaida;

				cout << "\nKategorija: " << kategorija[i] << endl;
				cout << "Preke: " << varda[i] << endl;
				cout << "Kaina: " << kaina[i] << " EUR" << endl;
				cout << "Kiekis: " << kiekis[i] << endl;
				cout << "Suma: " << suma << " EUR" << endl;
				cout << "Nuolaida: " << nuolaida << " EUR" << endl;
			}

			cout << "\n========== SUVESTINE ==========" << endl;
			cout << "Bendra suma: " << bendraSuma << " EUR" << endl;
			cout << "Bendra nuolaida: " << bendraNuolaida << " EUR" << endl;
			cout << "Galutine suma: " << bendraSuma - bendraNuolaida << " EUR" << endl;

			break;
		}

		case 5:
			cout << "Programa baigta" << endl;
			break;

		default:
			cout << "Neteisingas pasirinkimas!" << endl;
		}

	} while (pasirinkimas != 5);
	cout << fixed << setprecision(2);
	


	
	


	
	f.close();

	return 0;
}
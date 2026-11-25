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
void Ataskaita(string kategorija[], string varda[], double kaina[], int kiekis[], int n)
{
	double bendraSuma = 0;
	double bendraNuolaida = 0;

	cout << fixed << setprecision(2);
	cout << "\n========== VISA ATASKAITA ==========" << endl;

	for (int i = 0; i < n; i++) {
		double suma = PrekesSuma(kaina[i], kiekis[i]);
		double nuolaida = Nuolaida(kiekis[i], suma);
		double moketi = suma - nuolaida;

		bendraSuma += suma;
		bendraNuolaida += nuolaida;

		cout << "\nKategorija: " << kategorija[i] << endl;
		cout << "Preke: " << varda[i] << endl;
		cout << "Kaina: " << kaina[i] << " EUR" << endl;
		cout << "Kiekis: " << kiekis[i] << endl;
		cout << "Suma: " << suma << " EUR" << endl;
		cout << "Nuolaida: " << nuolaida << " EUR" << endl;
		cout << "Moketi: " << moketi << " EUR" << endl;
	}

	cout << "\nBendra suma: " << bendraSuma << " EUR" << endl;
	cout << "Bendra nuolaida: " << bendraNuolaida << " EUR" << endl;
	cout << "Galutine suma: " << bendraSuma - bendraNuolaida << " EUR" << endl;

	cout << "\n========== KATEGORIJU SUVESTINE ==========" << endl;

	cout << "Dviraciai: "
		<< KategorijosSuma(kategorija, kaina, kiekis, n, "Dviraciai") << " EUR" << endl;

	cout << "Dalys: "
		<< KategorijosSuma(kategorija, kaina, kiekis, n, "Dalys") << " EUR" << endl;

	cout << "Aksesuarai: "
		<< KategorijosSuma(kategorija, kaina, kiekis, n, "Aksesuarai") << " EUR" << endl;
}

void IssaugotiAtaskaita(string kategorija[], string varda[], double kaina[], int kiekis[], int n)
{
	ofstream out("ataskaita.txt");

	if (!out.is_open()) {
		cout << "Nepavyko atidaryti ataskaita.txt" << endl;
		return;
	}

	double bendraSuma = 0;
	double bendraNuolaida = 0;

	out << fixed << setprecision(2);
	out << "========== VISA ATASKAITA ==========" << endl;

	for (int i = 0; i < n; i++) {
		double suma = PrekesSuma(kaina[i], kiekis[i]);
		double nuolaida = Nuolaida(kiekis[i], suma);
		double moketi = suma - nuolaida;

		bendraSuma += suma;
		bendraNuolaida += nuolaida;

		out << "\nKategorija: " << kategorija[i] << endl;
		out << "Preke: " << varda[i] << endl;
		out << "Kaina: " << kaina[i] << " EUR" << endl;
		out << "Kiekis: " << kiekis[i] << endl;
		out << "Suma: " << suma << " EUR" << endl;
		out << "Nuolaida: " << nuolaida << " EUR" << endl;
		out << "Moketi: " << moketi << " EUR" << endl;
	}

	out << "\nBendra suma: " << bendraSuma << " EUR" << endl;
	out << "Bendra nuolaida: " << bendraNuolaida << " EUR" << endl;
	out << "Galutine suma: " << bendraSuma - bendraNuolaida << " EUR" << endl;

	out << "\n========== KATEGORIJU SUVESTINE ==========" << endl;

	out << "Dviraciai: "
		<< KategorijosSuma(kategorija, kaina, kiekis, n, "Dviraciai") << " EUR" << endl;

	out << "Dalys: "
		<< KategorijosSuma(kategorija, kaina, kiekis, n, "Dalys") << " EUR" << endl;

	out << "Aksesuarai: "
		<< KategorijosSuma(kategorija, kaina, kiekis, n, "Aksesuarai") << " EUR" << endl;

	out.close();

	if (out.fail()) {
		cout << "Nepavyko irasyti ataskaitos!" << endl;
	}
	else {
		cout << "Ataskaita sekmingai issaugota!" << endl;
	}
}
void VisoUzsakimoSuma(string kategorija[], double kaina[], int kiekis[], int n) {
	double bendraSuma = 0;
	double bendraNuolaida = 0;
	for (int i = 0; i < n; i++) {
		double suma = PrekesSuma(kaina[i], kiekis[i]);
		double nuolaida = Nuolaida(kiekis[i], suma);
		bendraSuma += suma;
		bendraNuolaida += nuolaida;
	}
	cout << fixed << setprecision(2);
	cout << "Bendra suma: " << bendraSuma << " EUR" << endl;
	cout << "Bendra nuolaida: " << bendraNuolaida << " EUR" << endl;
	cout << "Galutine suma: " << bendraSuma - bendraNuolaida << " EUR" << endl;
}


bool Nuskaityti(string kategorija[], string varda[], double kaina[], int kiekis[], int& n)
{
	ifstream f("uzsakymas.txt");

	if (!f.is_open()) {
		cout << "Nepavyko atidaryti uzsakymas.txt" << endl;
		return false;
	}

	if (!(f >> n)) {
		cout << "Klaida nuskaitant prekiu kieki!" << endl;
		return false;
	}

	f.ignore(1000, '\n');

	if (n < 1 || n > 100) {
		cout << "Klaida: netinkamas prekiu kiekis!" << endl;
		return false;
	}

	for (int i = 0; i < n; i++) {
		if (!getline(f, kategorija[i], ';') ||
			!getline(f, varda[i], ';') ||
			!(f >> kaina[i]) ||
			f.get() != ';' ||
			!(f >> kiekis[i])) {

			cout << "Klaida nuskaitant preke!" << endl;
			return false;
		}

		f.ignore(1000, '\n');

		if (kategorija[i] != "Dviraciai" &&
			kategorija[i] != "Dalys" &&
			kategorija[i] != "Aksesuarai") {
			cout << "Klaida: netinkama kategorija!" << endl;
			return false;
		}

		if (kaina[i] <= 0 || kiekis[i] <= 0) {
			cout << "Klaida: netinkama kaina arba kiekis!" << endl;
			return false;
		}
	}

	return true;
}


int main() {

	string kategorija[100];
	string varda[100];
	double kaina[100];
	int kiekis[100];
	int n;





	if (!Nuskaityti(kategorija, varda, kaina, kiekis, n)) {
		return 1;
	}
	





	
	int pasirinkimas;

	do {
		cout << "========== MENIU ==========" << endl;
		cout << "1. Visi produktai" << endl;
		cout << "2. Pasirinkti kategorija" << endl;
		cout << "3. Viso uzsakymo suma" << endl;
		cout << "4. Kategoriju sumos" << endl;
		cout << "5. Visa ataskaita" << endl;
		cout << "6. Issaugoti ataskaita" << endl;
		cout << "7. Baigti programa" << endl;
		cout << "Pasirinkite: ";

		cin >> pasirinkimas;
		if (cin.fail()) {
			cin.clear();
			cin.ignore(1000, '\n');
			cout << "Iveskite skaiciu nuo 1 iki 7!" << endl;
			continue;
		}

		switch (pasirinkimas) {

		case 1:
			cout << "Prekiu informacija: " << endl;
			cout << "________________________________________________________________________" << endl;

			for (int i = 0; i < n; i++) {
				double suma = PrekesSuma(kaina[i], kiekis[i]);
				double nuolaida = Nuolaida(kiekis[i], suma);

				cout << "Kategorija: " << kategorija[i] << endl;
				cout << "Varda: " << varda[i] << endl;
				cout << "Kaina: " << fixed << setprecision(2) << kaina[i] << " EUR" << endl;
				cout << "Kiekis: " << kiekis[i] << endl;
				cout << "Suma: " << suma << " EUR" << endl;
				cout << "Nuolaida: " << nuolaida << " EUR" << endl;
				cout << "Galutine suma: " << suma - nuolaida << " EUR" << endl;
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
			if (cin.fail()) {
				cin.clear();
				cin.ignore(1000, '\n');
				cout << "Iveskite skaiciu nuo 1 iki 3!" << endl;
				break;
			}

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
			if (pasirinkimas2 < 1 || pasirinkimas2 > 3) {
				break;
			}

			bool rasta = false;
			double kategorijosSuma = 0;

			cout << fixed << setprecision(2);

			for (int i = 0; i < n; i++) {
				if (kategorija[i] == pasirinktaKategorija) {

					rasta = true;

					double suma = PrekesSuma(kaina[i], kiekis[i]);
					double nuolaida = Nuolaida(kiekis[i], suma);
					double moketi = suma - nuolaida;

					kategorijosSuma += moketi;

					cout << "\nPreke: " << varda[i] << endl;
					cout << "Kaina: " << kaina[i] << " EUR" << endl;
					cout << "Kiekis: " << kiekis[i] << endl;
					cout << "Suma: " << suma << " EUR" << endl;
					cout << "Nuolaida: " << nuolaida << " EUR" << endl;
					cout << "Moketi: " << moketi << " EUR" << endl;
					cout << "-------------------------" << endl;
				}
			}

			if (rasta) {
				cout << "Kategorijos suma: " << kategorijosSuma << " EUR" << endl;
			}
			else {
				cout << "Sioje kategorijoje prekiu nera!" << endl;
			}

			break;
		}

		case 3:
			VisoUzsakimoSuma(kategorija, kaina, kiekis, n);
			break;

		case 4:
			cout << fixed << setprecision(2);

			cout << "Dviraciai: "
				<< KategorijosSuma(kategorija, kaina, kiekis, n, "Dviraciai") << " EUR" << endl;

			cout << "Dalys: "
				<< KategorijosSuma(kategorija, kaina, kiekis, n, "Dalys") << " EUR" << endl;

			cout << "Aksesuarai: "
				<< KategorijosSuma(kategorija, kaina, kiekis, n, "Aksesuarai") << " EUR" << endl;
			break;

		case 5:
			Ataskaita(kategorija, varda, kaina, kiekis, n);
			break;
		case 6:
			IssaugotiAtaskaita(kategorija, varda, kaina, kiekis, n);
			break;

		case 7:
			cout << "Programa baigta" << endl;
			break;

		default:
			cout << "Neteisingas pasirinkimas!" << endl;
		}

	} while (pasirinkimas != 7);
	cout << fixed << setprecision(2);
	


	
	


	


	return 0;
}
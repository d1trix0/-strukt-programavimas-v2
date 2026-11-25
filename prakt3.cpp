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
	cout << fixed << setprecision(2);
	cout << "Dviraciai: " << KategorijosSuma(kategorija, kaina, kiekis, n, "Dviraciai") << endl;

	cout << "Dalys: " << KategorijosSuma(kategorija, kaina, kiekis, n, "Dalys") << endl;

	cout << "Aksesuarai: " << KategorijosSuma(kategorija, kaina, kiekis, n, "Aksesuarai") << endl;

	cout << "-------------------------" << endl;


	for (int i = 0; i < n; i++) {
		double suma = PrekesSuma(kaina[i], kiekis[i]);
		double nuolaida = Nuolaida(kiekis[i], suma);
		
		cout << "Kategorija: " << i+1<< ": " << kategorija[i] << endl;
		cout << "Varda: "<<  varda[i] << endl;
		cout << "Kaina: "<< fixed << setprecision(2) << kaina[i] << endl;
		cout << "Kiekis: "<< kiekis[i] << endl;
		cout << "Suma: " << suma << endl;
		cout << "Nuolaida: " << nuolaida << endl;
		cout << "Galutine suma: " << suma - nuolaida << endl;
		cout << "-------------------------" << endl;
	}
	


	
	f.close();

	return 0;
}
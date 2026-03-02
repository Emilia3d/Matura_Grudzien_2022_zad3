#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <iomanip>
#include <algorithm>
#include <sstream>

using namespace std;

//ifstream plik("liczby_przyklad.txt");
ifstream plik("liczby.txt");

bool SITO[100000];
void SitoEratostenesa(int n) {
	SITO[1] = false;
	for (int i = 2; i <= n; i++) 
		SITO[i] = true;
	for (int i = 2; i <= n; i++) {
		if (SITO[i] == true) {
			cout << i << endl;
			int j = i*i ;
			while (j <= n) {
				SITO[j] = false;
				//cout << "skreslamy wielokrotnosc "<<i<<" czyli " << j << endl;
				j = j + i;
			}
		}
	}
}
bool czyPierwsza(int n) {
	if (n < 2) return false;

	for (int i = 2; i * i <= n; i++) {
		if (n % i == 0)
			return false;
	}
	return true;
}

int ileRozkladow(int n) {
	int licznik = 0;

	for (int p = 2; p <= n / 2; p++) { //  n/2, bo po przekroczeniu połowy zaczęlibyśmy liczyć te same pary drugi raz
		if (czyPierwsza(p) && czyPierwsza(n - p))
			licznik++;
	}
	return licznik;
}


int main()
{
	int n = 50;
	//zad. 3.1
	cout << "zad. 3.1" << endl;
	SitoEratostenesa(n);

	//zad. 3.2
	cout << "zad. 3.2" << endl;
	int x;
	int ilePierw = 0;

	while (plik >> x) {
		if (czyPierwsza(x - 1))
			ilePierw++;
	}
	cout << ilePierw << endl;

	plik.clear();
	plik.seekg(0);
	//zad. 3.3
	cout << "zad. 3.3" << endl;

	
	int maxLiczba = 0, maxRozklady = 0;
	int minLiczba = 0, minRozklady = 1000000;

	while (plik >> x) {

		int ile = ileRozkladow(x);
		//cout << ile << endl;
	
		if (ile > maxRozklady) {
			maxRozklady = ile;
			maxLiczba = x;
		}

		if (ile < minRozklady) {
			minRozklady = ile;
			minLiczba = x;
		}
	}

	cout << maxLiczba << " " << maxRozklady << endl;
	cout << minLiczba << " " << minRozklady << endl;
	
	plik.clear();
	plik.seekg(0);

	//zad. 3.4
	cout << "zad. 3.4" << endl;
	int liczba;
	vector<char> cyfry;

	while (plik >> liczba) {

		if (liczba == 0) {
			cyfry.push_back('0');
		}

		while (liczba > 0) {
			int reszta = liczba % 16;

			if (reszta < 10)
				cyfry.push_back('0' + reszta);
			else
				cyfry.push_back('A' + (reszta - 10));

			liczba /= 16;
		}
	}

	vector<char>szesnast = { '0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'A', 'B', 'C', 'D', 'E', 'F' };

	for (auto c : szesnast) {
		cout << c << ":" << count(cyfry.begin(), cyfry.end(), c) << endl;
	}
		//cout << ile << endl;
	//zad. 8
	cout << "zad. 8" << endl;
	cout << setbase(4) ;
	//cout << 3211+2322 << endl;
	cout<<stoi("3211", nullptr, 4)+ stoi("2322", nullptr, 4)<<endl;
	cout << stoi("3211", nullptr, 4) - stoi("2322", nullptr, 4) << endl;
	return 0;
}

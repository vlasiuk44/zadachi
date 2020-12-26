#include <fstream>
#include <iostream>
#include <cmath>
#include <String>
using namespace std;



int main()
{
	int kucha = 100; //любое число камней >  0
	int hod_1_cheloveka;
	int hod_2_cheloveka;
	hod_1_cheloveka = 1;
	hod_2_cheloveka = 2;
	while (kucha > 10) { //оптимальная стратегия, первый игрок всегда берет 1 камень, второй вынужден брать 2
		
		kucha -= hod_1_cheloveka;
		kucha -= hod_2_cheloveka;

	}
	
	if (kucha == 9) {// ходы идут пока не останется 3 камня после хода 2 человека, тогда первый забирает на 1 больше(3 штуки) и побеждает 
		while (kucha > 3) {
			kucha -= hod_1_cheloveka;
			cout << "hod_1_cheloveka\n";
			kucha -= hod_2_cheloveka;
			cout << "hod_2_cheloveka\n";
		}
		hod_1_cheloveka = hod_2_cheloveka + 1;
		kucha -= hod_1_cheloveka;
	}

	else if (kucha == 10 || kucha == 8) { //после остаются 3 варианта: 10 камней в куче, 9 или 8. Если в куче 10 камней то стратегия продолжается и побеждает  1 игрок.
		while (kucha > 0) {  // Если в куче 8 камней стратегия так же повторяется пока в куче не останется 1 камень, но второй игрок обязан брать два, по этому проигрывает
			kucha -= hod_1_cheloveka;
			cout << "hod_1_cheloveka\n";
			if (kucha > 0 && kucha - hod_2_cheloveka > 0) {
				kucha -= hod_2_cheloveka;
				cout << "hod_2_cheloveka\n";
			}
		}

	}

	else if (kucha == 3)cout << "pobedil 2 chelovek"; //если в куче меньше 10 камней все сводится к тем же исходам кроме кучи из 3 камней
	else if (kucha == 1)cout << "pobedil 1 chelovek, ostalos' kamrei ";
	


	else {
		while (kucha > 1) {
			kucha -= hod_1_cheloveka;
			cout << "hod_1_cheloveka\n";
			if (kucha > 0 && kucha - hod_2_cheloveka > 0) {
				kucha -= hod_2_cheloveka;
				cout << "hod_2_cheloveka\n";
			}
		}
	}
	

	
	
	cout << kucha;//при любых условиях последним забирает камни 1 игрок кроме кучи из 3 камней
}


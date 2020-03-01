//Аня Палкина
#include <iostream>
#include <vector>

using namespace std;

int main() {
	int r, c, v, h;
	int k, l;
	cin >> r >> c >> v >> h;
	vector <int> vv(v); //высоты прямоугольников
	vector <int> hh(h); //широты прямоугольников
	for (int i = 0; i < v; i++)
		cin >> vv[i];
	for (int i = 0; i < h; i++)
		cin >> hh[i];
	int bwh = 0; //булл ширины
	int bwv = 0; //булл высоты
	for (int i = 0; i < v; i++) { //перебор вектора с высотами прямоугольников
		for (l = 0; l < vv[i]; l++) { //с границы прошлой высоты до границы следующей
			bwh = 0;
			if (bwv == 0) { //в начальном случае
				for (int j = 0; j < h; j++) {//перебор вектора с шириной прямоугольников
					for (k = 0; k < hh[j]; k++) { //с границы прошлой ширины до границы следующей
						if (bwh == 0)
							cout << 'B';
						else
							cout << 'W';
					}
					if (bwh == 0) {
						bwh = 1;
					}
					else
						bwh = 0;
				}
			}
			else {
				for (int j = 0; j < h; j++) {
					for (k = 0; k < hh[j]; k++) {
						if (bwh == 0)
							cout << 'W';
						else
							cout << 'B';
					}
					if (bwh == 0) {
						bwh = 1;
					}
					else
						bwh = 0;
				}

			}
			cout << endl;
		}
		if (bwv == 0) {
			bwv = 1;
		}
		else
			bwv = 0;
	}
	int gg;
	cin >> gg;
}
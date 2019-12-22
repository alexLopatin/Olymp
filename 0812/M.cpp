
#include <iostream>
#include <vector>
#include <string>
#include <math.h>
using namespace std;

int x,y,r;

double DistanceSquare(double x1, double y1, double x2, double y2) {
    return (x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2);
}

bool CheckPixel(int pX, int pY) {
    double leftBottom = DistanceSquare(x + 0.5, y + 0.5, pX, pY);
    double leftTop = DistanceSquare(x + 0.5, y + 0.5, pX, pY + 1);
    double rightTop = DistanceSquare(x + 0.5, y + 0.5, pX + 1, pY + 1);
    double rightBottom = DistanceSquare(x + 0.5, y + 0.5, pX + 1, pY);
    double Min = min( min(leftBottom, leftTop), min(rightBottom, rightTop) );
    return (Min < (r + 0.5) * (r + 0.5));
}

int main(int argc, char *argv[]) {
    cin >> x >> y >> r;
    unsigned long long res = 0;
    for(int i = x - r; i <= x + r; i++) {
        for(int j = y - r; j <= y + r; j++) {

            res += CheckPixel(i, j);
            cout << CheckPixel(i,j);
        }
        cout << endl;
    }
    cout << res << endl;
}

#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main(int argc, char *argv[]) {
    int n, m, h;
    cin >> n >> m >> h;
    vector< vector<int> > xProjection(n);
    for ( int i = 0 ; i < n ; i++ )
        xProjection[i].resize(m);
    vector< vector<int> > yProjection(n);
    for ( int i = 0 ; i < n ; i++ )
        yProjection[i].resize(h);
    for ( int i = 0 ; i < n ; i++ ) {
        for ( int j = 0 ; j < m ; j++ ) {
            char t;
            cin >> t;
            xProjection[i][j] = t - '0';
        }
    }
    for ( int i = 0 ; i < n ; i++ ) {
        for ( int j = 0 ; j < h ; j++ ) {
            char t;
            cin >> t;
            yProjection[i][j] = t - '0';
        }
    }
    int max = 0;
    int min = 0;
    vector< vector< vector<int> > > minVolume(n);
    for ( int i = 0 ; i < n ; i++ ) {
        minVolume[i].resize(m);
        for ( int j = 0 ; j < m ; j++ )
            minVolume[i][j].resize(h);
    }
    vector< vector< vector<int> > > maxVolume(n);
    for ( int i = 0 ; i < n ; i++ ) {
        maxVolume[i].resize(m);
        for ( int j = 0 ; j < m ; j++ )
            maxVolume[i][j].resize(h);
    }
    for ( int i = 0 ; i < n ; i++ ) {
        for ( int j = 0 ; j < m ; j++ ) {
            bool b = true;
            if(xProjection[i][j]) {
                for ( int k = 0 ; k < h ; k++ ) {
                    if(yProjection[i][k] && b){
                        b = false;
                    }
                    if(yProjection[i][k]){
                        maxVolume[i][j][k] = 1;
                        max += 1;
                    }
                }
                if(b) {
                    cout << -1 << endl;
                    return 0;
                }
            }
        }
    }
    cout << max << endl;
    for ( int i = 0 ; i < n ; i++ ) {
        for ( int j = 0 ; j < m ; j++ )
            for ( int k = 0 ; k < h ; k++ ) {
                if(maxVolume[i][j][k]) {
                    cout << i << ' ' << j << ' ' << k << endl;
                }
            }
    }
    for ( int i = 0 ; i < n ; i++ ) {
        for ( int j = 0 ; j < m ; j++ )
            for ( int k = 0 ; k < h ; k++ ) {
                if(xProjection[])
            }
    }
    
}
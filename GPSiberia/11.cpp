#include <iostream>
#include <vector>
#include <map>
#include <string>
using namespace std;

struct Vertex {
    map<int, int> edges;
};

int main(int argc, char *argv[]) {
    int n;
    cin >> n;
    vector<Vertex> vertices(n + 1);
    for(int i = 0; i < n - 1; i++) {
        int a, b, c1, c2;
        cin >> a >> b >> c1 >> c2;
        vertices[a].edges[b] = c1;
        vertices[b].edges[a] = c2;
    }
    for(int i = 1; i < n + 1; i++) {
        map<int, int>::iterator itr;
        int res = 0;
        for( itr = vertices[i].edges.begin(); itr != vertices[i].edges.end(); ++itr) {
            
        }
        cout << res << endl;
    }
}
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
    vector<Vertex> vertices(n);
    for(int i = 0; i < n - 1; i++) {
        int a, b, c1, c2;
        cin >> a >> b >> c1 >> c2;
        vertices[a].edges[b] = c1;
        vertices[b].edges[a] = c2;
    }
    
}
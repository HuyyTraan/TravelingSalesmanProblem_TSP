#include <iostream>
#include <fstream>
#include "bellman.h"
#include "tsm.h"

int main() {
    int G[20][20];
    int BFValue[20], BFPrev[20];
    
    int n = 12;

    std::ifstream fin;
    fin.open("inMat1.txt");
    for (int i = 0; i < n; i++) {
        BFValue[i] = BFPrev[i] = -1;
        for (int j = 0; j < n; j++) {
            fin >> G[i][j];
        }
    }
    fin.close();

    std::cout << "Bellman-Ford algorithm:" << std::endl;
    for (int i = 0; i < n - 1; i++) {
        std::cout << "Step " << i + 1 << ":" << std::endl;
        BF(G, n, 'A', BFValue, BFPrev);
        for (int j = 0; j < n; j++) {
            std::cout << BFValue[j] << " ";
        }
        std::cout << std::endl;
        for (int j = 0; j < n; j++) {
            std::cout << BFPrev[j] << " ";
        }
        std::cout << std::endl;
    }

    std::cout << "Shortest path from A to L: " << BF_Path(G, n, 'A', 'L') << std::endl;

    std::cout << "Traveling Salesman Problem:" << std::endl;
    std::string path = Traveling(G, n, 'A');
    std::cout << "Shortest path: " << path << std::endl;
    std::cout << pathlength(G, n, path) << std::endl;

    return 0;
}
#include <iostream>
#include <vector>
#include <stack>
using namespace std;
void BF(int graph_mat[20][20], int nb_Vertices, char ini_vertex, int distanceArray[20], int predecessorArray[20]) ;
std::string BF_Path(int graphMatrix[20][20], int vertexCount, char initialVertex, char goalVertex) ;

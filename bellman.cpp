#include "bellman.h"
class BellmanFord {
public:
    BellmanFord(const int graphMatrix[20][20], int vertexCount, char initialVertex)
        : vertexCount(vertexCount), initialVertex(initialVertex - 'A') {
        copyGraphMatrix(graphMatrix);
        distanceArray.assign(vertexCount, -1);
        predecessorArray.assign(vertexCount, -1);
    }

    void run() {
        initializeDistanceAndPredecessorArrays();
        for (int i = 0; i < vertexCount - 1; ++i) {
            relaxGraphEdges();
        }
    }

    std::string getPath(char goalVertex) {
        int goalVertexIndex = goalVertex - 'A';
        if (distanceArray[goalVertexIndex] == -1) {
            return "";
        }
        return buildPath(goalVertexIndex);
    }

private:
    int vertexCount;
    int initialVertex;
    std::vector<std::vector<int>> graphMatrix;
    std::vector<int> distanceArray;
    std::vector<int> predecessorArray;

    void copyGraphMatrix(const int sourceMatrix[20][20]) {
        graphMatrix.resize(20, std::vector<int>(20, 0));
        for (int i = 0; i < 20; ++i) {
            for (int j = 0; j < 20; ++j) {
                graphMatrix[i][j] = sourceMatrix[i][j];
            }
        }
    }

    void initializeDistanceAndPredecessorArrays() {
        for (int i = 0; i < vertexCount; ++i) {
            if (i == initialVertex) {
                distanceArray[i] = 0;
                predecessorArray[i] = -1;
            } else {
                if (graphMatrix[initialVertex][i] != 0) {
                    distanceArray[i] = graphMatrix[initialVertex][i];
                    predecessorArray[i] = initialVertex;
                } else {
                    distanceArray[i] = -1;
                    predecessorArray[i] = -1;
                }
            }
        }
    }

    void relaxGraphEdges() {
        std::vector<int> tempDistances = distanceArray;
        for (int u = 0; u < vertexCount; ++u) {
            for (int v = 0; v < vertexCount; ++v) {
                if (graphMatrix[u][v] != 0) {
                    if (distanceArray[u] != -1) {
                        int newDistance = distanceArray[u] + graphMatrix[u][v];
                        if (tempDistances[v] == -1 || newDistance < tempDistances[v]) {
                            tempDistances[v] = newDistance;
                            predecessorArray[v] = u;
                        }
                    }
                }
            }
        }
        distanceArray = tempDistances;
    }

    std::string buildPath(int goalVertexIndex) {
        std::stack<char> stack;
        int vertex = goalVertexIndex;
        while (vertex != initialVertex) {
            stack.push('A' + vertex);
            vertex = predecessorArray[vertex];
        }
        stack.push('A' + initialVertex);

        std::string path;
        while (!stack.empty()) {
            path += stack.top();
            stack.pop();
            if (!stack.empty()) {
                path += " ";
            }
        }
        return path;
    }
};

void initializeDistanceAndPredecessorArrays_BF(int vertexCount, int initialVertexIndex, int graphMatrix[20][20], int distanceArray[20], int predecessorArray[20]) {
    for (int i = 0; i < vertexCount; ++i) {
        if (i == initialVertexIndex) {
            distanceArray[i] = 0;
            predecessorArray[i] = -1;
        } else {
            if (graphMatrix[initialVertexIndex][i] != 0) {
                distanceArray[i] = graphMatrix[initialVertexIndex][i];
                predecessorArray[i] = initialVertexIndex;
            } else {
                distanceArray[i] = -1;
                predecessorArray[i] = -1;
            }
        }
    }
}

void copyArray_BF(int vertexCount, int sourceArray[20], int destinationArray[20]) {
    for (int i = 0; i < vertexCount; ++i) {
        destinationArray[i] = sourceArray[i];
    }
}

void BF(int graphMatrix[20][20], int vertexCount, char initialVertex, int distanceArray[20], int predecessorArray[20]) {
    int initialVertexIndex = initialVertex - 'A';
    bool isFirstRun = true;

    for (int i = 0; i < vertexCount; ++i) {
        if (distanceArray[i] != -1 || predecessorArray[i] != -1) {
            isFirstRun = false;
            break;
        }
    }

    if (isFirstRun) {
        initializeDistanceAndPredecessorArrays_BF(vertexCount, initialVertexIndex, graphMatrix, distanceArray, predecessorArray);
        return;
    }

    int tempDistances[20];
    copyArray_BF(vertexCount, distanceArray, tempDistances);

    for (int u = 0; u < vertexCount; ++u) {
        for (int v = 0; v < vertexCount; ++v) {
            if (graphMatrix[u][v] != 0) {
                if (distanceArray[u] != -1) {
                    int newDistance = distanceArray[u] + graphMatrix[u][v];
                    if (tempDistances[v] == -1 || newDistance < tempDistances[v]) {
                        tempDistances[v] = newDistance;
                        predecessorArray[v] = u;
                    }
                }
            }
        }
    }

    copyArray_BF(vertexCount, tempDistances, distanceArray);
}

std::string BF_Path(int graphMatrix[20][20], int vertexCount, char initialVertex, char goalVertex) {
    int distanceArray[20], predecessorArray[20];
    std::fill(std::begin(distanceArray), std::end(distanceArray), -1);
    std::fill(std::begin(predecessorArray), std::end(predecessorArray), -1);

    for (int i = 0; i < vertexCount; ++i) {
        BF(graphMatrix, vertexCount, initialVertex, distanceArray, predecessorArray);
    }

    int initialVertexIndex = initialVertex - 'A';
    int goalVertexIndex = goalVertex - 'A';

    if (distanceArray[goalVertexIndex] == -1) {
        return "";
    }

    std::stack<char> stack;
    int vertex = goalVertexIndex;
    while (vertex != initialVertexIndex) {
        stack.push('A' + vertex);
        vertex = predecessorArray[vertex];
    }
    stack.push(initialVertex);

    std::string path;
    while (!stack.empty()) {
        path += stack.top();
        stack.pop();
        if (!stack.empty()) {
            path += " ";
        }
    }
    return path;
}

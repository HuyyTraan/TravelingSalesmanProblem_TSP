
#include "tsm.h"

int pathlength(const int graph[20][20], int numVertices, const string &path) {
    stringstream ss(path);
    vector<char> vertices;

    string vertex;
    while (ss >> vertex) {
        vertices.push_back(vertex[0]);
    }

    int length = 0;
    size_t i = 0;
    while (i < vertices.size() - 1) {
        length += graph[vertices[i] - 'A'][vertices[i + 1] - 'A'];
        i++;
    }
    return length;
}

vector<int> optimalPath;
int minimumCost, minEdgeWeight;

string constructPathString() {
    string result = "";
    size_t i = 0;
    while (i < optimalPath.size()) {
        result += string(1, optimalPath[i] + 'A') + " ";
        i++;
    }
    return result + string(1, optimalPath[0] + 'A');
}

void iterativeTSP(const int graph[20][20], int numVertices, int startIndex) {
    struct SearchState {
        int currentNode;
        int currentCost;
        vector<int> currentPath;
        vector<bool> visited;
    };

    stack<SearchState> stateStack;
    stateStack.push({startIndex, 0, {startIndex}, vector<bool>(numVertices, false)});
    stateStack.top().visited[startIndex] = true;

    while (!stateStack.empty()) {
        SearchState currentState = stateStack.top();
        stateStack.pop();

        if (currentState.currentPath.size() == numVertices) {
            if (graph[currentState.currentPath.back()][currentState.currentPath[0]] == 0) {
                continue;
            }
            int totalCost = currentState.currentCost + graph[currentState.currentPath.back()][currentState.currentPath[0]];
            if (totalCost < minimumCost) {
                minimumCost = totalCost;
                optimalPath = currentState.currentPath;
            }
            continue;
        }

        int i = 0;
        while (i < numVertices) {
            if (!currentState.visited[i]) {
                if (graph[currentState.currentPath.back()][i] == 0) {
                    i++;
                    continue;
                }
                int newCost = currentState.currentCost + graph[currentState.currentPath.back()][i];
                if (newCost + (numVertices - currentState.currentPath.size()) * minEdgeWeight < minimumCost) {
                    SearchState newState = currentState;
                    newState.currentNode = i;
                    newState.currentCost = newCost;
                    newState.currentPath.push_back(i);
                    newState.visited[i] = true;
                    stateStack.push(newState);
                }
            }
            i++;
        }
    }
}

string Traveling(const int graph[20][20], int numVertices, char startVertex) {
    int startIndex = startVertex - 'A';

    minimumCost = minEdgeWeight = INT_MAX;

    int i = 0;
    while (i < numVertices) {
        int j = 0;
        while (j < numVertices) {
            if (graph[i][j] != 0 && graph[i][j] < minEdgeWeight) {
                minEdgeWeight = graph[i][j];
            }
            j++;
        }
        i++;
    }

    iterativeTSP(graph, numVertices, startIndex);
    return constructPathString();
}

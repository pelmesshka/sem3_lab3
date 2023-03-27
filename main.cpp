#include <iostream>
#include "Graph.h"
#include "Test.h"
#include "Menu.h"
#include "GraphFunctions.h"

using namespace std;

template<typename T>
void Mainfunc() {
    int Command = -1;
    Graph<T> graph;
    GraphFunctions<T> GrFunctions;
    while (Command != 0) {
        CommandMenu();
        cin >> Command;
        if (Command == 1) {
            cin >> graph;
        } else if (Command == 2) {
            cout << graph;
        } else if (Command == 3) {
            Edge<T> edge;
            cin >> edge;
            graph.Push_back(edge);
        } else if (Command == 4) {
            GrFunctions.GetTheLeastWeightDistanceAnswer(graph);
        } else if (Command == 9) {
            Test();
        }
    }
}

int main() {
    DataTypeMenu();
    int DataType = 0;
    cin >> DataType;
    cout << "first of all input sequence please" << '\n';
    if (DataType == 1) {
        Mainfunc<int>();
    } else if (DataType == 2) {
        Mainfunc<double>();
    }
}
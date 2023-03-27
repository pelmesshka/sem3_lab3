#pragma once

#include <iostream>
#include "Graph.h"
#include <set>

using namespace std;

template<class T>
class GraphFunctions {
public:
    vector<T> GetTheLeastWeightDistance(Graph<T> graph, int StartVertex) { //поиск кратчайшего пути
        set<pair<int, int>> Set;
        vector<T> Weights(graph.GetLength(), 1000000000);
        vector<bool> Flag(graph.GetLength(), false);
        Weights[StartVertex] = 0;
        Set.insert({0, StartVertex});
        while (Set.size() != 0) {
            int StartVertex = Set.begin()->second;
            Set.erase(Set.begin());
            for (int i = 0; i < graph.Get(StartVertex).GetIncedentArrayLength(); i++) {
                int FinishVertex = graph.Get(StartVertex).Get(i).GetNumberOfVertexTo();
                T Weight = graph.Get(StartVertex).Get(i).GetWeight();
                if (Weights[StartVertex] + Weight < Weights[FinishVertex]) {
                    Set.erase({Weights[FinishVertex], FinishVertex});
                    Weights[FinishVertex] = Weights[StartVertex] + Weight;
                    Set.insert({Weights[FinishVertex], FinishVertex});
                }
            }
        }
        return Weights;
    }

    void GetTheLeastWeightDistanceAnswer(Graph<T> graph) {//получение ответа
        int StartVertex;
        cout << "input please vertex for which you want to get answer\n";
        cin >> StartVertex;
        StartVertex--;
        vector<T> Weights = GetTheLeastWeightDistance(graph, StartVertex);
        for (int i = 0; i < Weights.size(); i++) {
            if (Weights[i] == 1000000000)
                cout << "To vertex number " << i << " there is no path from start vertex number " << StartVertex
                     << '\n';
            else if (i == StartVertex) cout << "it is start vertex\n";
            else
                cout << "To vertex number " << i << " weigth of path from start vertex number " << StartVertex << " is "
                     << Weights[i] << '\n';
        }
    }
};
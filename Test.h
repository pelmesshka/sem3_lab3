#include <iostream>
#include "Graph.h"
#include "assert.h"
#include "GraphFunctions.h"

#pragma once


using namespace std;

void TestEdgeConstuctor() {
    Edge<int> edge = Edge<int>();
    assert(edge.GetNumberOfVertexFrom() == 0);
    assert(edge.GetNumberOfVertexTo() == 0);
    assert(edge.GetWeight() == 0);
    edge = Edge<int>(1, 2, 3);
    assert(edge.GetNumberOfVertexFrom() == 1);
    assert(edge.GetNumberOfVertexTo() == 2);
    assert(edge.GetWeight() == 3);
}

void TestEdgeFirstGroup() {
    Edge<int> edge = Edge<int>();
    edge.Set(0, 1, 1);
    assert(edge.GetNumberOfVertexFrom() == 0);
    assert(edge.GetNumberOfVertexTo() == 1);
    assert(edge.GetWeight() == 1);
}

void TestVertexConstructor() {
    Vertex<int> vertex = Vertex<int>();
    assert(vertex.GetNumberOfElement() == 0);
    assert(vertex.GetIncedentArrayLength() == 0);
    assert(vertex.GetHiddenIncedentArrayLength() == 0);
    vertex = Vertex<int>(3);
    assert(vertex.GetNumberOfElement() == 3);
    assert(vertex.GetIncedentArrayLength() == 0);
    assert(vertex.GetHiddenIncedentArrayLength() == 0);
}

void TestVertexSetNumberOfElement() {
    Vertex<int> vertex = Vertex<int>();
    vertex.SetNumberOfElement(1);
    assert(vertex.GetNumberOfElement() == 1);
}

void TestVertexPush_back(){
    Vertex<int> vertex = Vertex<int>(2);
    assert(vertex.GetIncedentArrayLength() == 0);
    Edge<int> edge = Edge<int>(2, 3, 4);
    vertex.Push_back(edge);
    assert(vertex.GetIncedentArrayLength() == 1);
    assert(vertex.Get(0) == edge);
}

void TestVertexHiddenPush_back() {
    Vertex<int> vertex = Vertex<int>(2);
    assert(vertex.GetIncedentArrayLength() == 0);
    Edge<int> edge = Edge<int>(1, 2, 4);
    vertex.HiddenPush_back(edge);
    assert(vertex.GetHiddenIncedentArrayLength() == 1);
    assert(vertex.GetHidden(0) == edge);
}

void TestGraphConstrutors() {
    Graph<int> graph = Graph<int>(0);
    assert(graph.GetLength() == 0);
    graph = Graph<int>(3);
    assert(graph.Get(0).GetNumberOfElement() == 0);
    assert(graph.Get(1).GetNumberOfElement() == 1);
    assert(graph.Get(2).GetNumberOfElement() == 2);
    assert(graph.GetLength() == 3);
}

void TestGraphGetLength() {
    Graph<int> graph = Graph<int>(3);
    assert(graph.GetLength() == 3);
}

void TestGraphPush_back() {
    Graph<int> graph = Graph<int>(3);
    assert(graph.Get(0).GetIncedentArrayLength() == 0);
    Edge<int> edge = Edge<int>(0, 1, 2);
    graph.Push_back(edge);
    assert(graph.Get(0).GetIncedentArrayLength() == 1);

}

void TestGraphFunctionsGetTheLeastWeightDistance() {
    GraphFunctions<double> GrFunctions;
    Graph<double> graph = Graph<double>(5);
    Edge<double> edge = Edge<double>(0, 1, 1);
    graph.Push_back(edge);
    edge.Set(0, 2, 2);
    graph.Push_back(edge);
    edge.Set(1, 3, 4);
    graph.Push_back(edge);
    edge.Set(2, 3, 5);
    graph.Push_back(edge);
    vector<double> answer = GrFunctions.GetTheLeastWeightDistance(graph, 0);
    assert(answer[0] == 0);
    assert(answer[1] == 1);
    assert(answer[2] == 2);
    assert(answer[3] == 5);
    assert(answer[4] == 1000000000);
}

void Test() {
    cout << "FOR EDGE :";
    cout << '\n';
    TestEdgeConstuctor();
    cout << "   Constructor for Edge works correct\n";
    TestEdgeFirstGroup();
    cout << "   Set(), GetNumberOfVertexFrom(), GetNumberOfVertexTo(), GetWeight() work correct\n";
    cout << "FOR Vertex : ";
    cout << '\n';
    TestVertexConstructor();
    cout << "   Constructor, GetIncedentArrayLength(), GetHiddenIncedentArrayLength() and GetNumberOfElement()  for Vertex works correct\n";
    TestVertexSetNumberOfElement();
    cout << "   SetNumberOfElement() for Vertex works correct\n";
    TestVertexPush_back();
    cout << "   Push_back() and Get() for Vertex work correct\n";
    TestVertexHiddenPush_back();
    cout << "   HiddenPush_back() for Vertex works correct\n";
    cout << "FOR GRAPH : ";
    cout << '\n';
    TestGraphConstrutors();
    cout << "   All constructors and Get() for Graph work correct\n";
    TestGraphGetLength();
    cout << "   GetLength() for Graph works correct\n";
    TestGraphPush_back();
    cout << "   Push_back() for Graph works correct\n";

    TestGraphFunctionsGetTheLeastWeightDistance();
    cout << "   GetTheLeaseWeightDistance() for GraphFunctions works correct\n";
}
#pragma once

#include <iostream>

using namespace std;

void DataTypeMenu() {
    cout << "What data type you want?" << '\n';
    cout << "1 - int" << '\n';
    cout << "2 - double" << '\n';
}

void CommandMenu() {
    cout << "What do you want to do?\n";
    cout << "1 - input graph\n";
    cout << "2 - print graph\n";
    cout << "3 - add edge to graph\n";
    cout << "4 - get the distance with the least weight to each of the vertices\n";
    cout << "9 - Test\n";
    cout << "0 - Stop\n";
}
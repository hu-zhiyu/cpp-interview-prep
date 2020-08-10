#include <iostream>
#include <vector>
#include <queue>
#include <string.h>
#include <cstdlib>
#include <unordered_map>
using namespace std;

int main()
{   
    int id = 0;
    auto f = [id]() mutable {
        cout << "id: " << id << endl;
        id++;
    };
    id++;
    f();
    f();
    f();
    cout << id << endl;
}
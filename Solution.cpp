#include <iostream>
#include <iomanip>
#include <vector>
#include <algorithm>
#include <queue>
#include <stack>
#include <list>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <iterator>
#include <cmath>
#include <cctype>
#include <cstring>
#include <cstdlib>
#include <ctime>

#include "Line.hpp"
#include "Vertex.hpp"
#include "Edge.hpp"
#include "Segment.hpp"
#include "Polygon.hpp"

using namespace std;

int main(int argc, char const *argv[])
{
    Vertex v1(10, 12);
    Vertex v2(3, 4);
    Vertex v3(12,19);
    
    Polygon poly;
    poly.addEdge(v1, v2);
    poly.addEdge(v2, v3);
    poly.addEdge(v3, v1);

    for(auto e : poly.LAE.entities) {
        e.Info();
        cout << endl;
    }

    return 0;
}

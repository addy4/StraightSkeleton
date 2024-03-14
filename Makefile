all: solution.exe

solution.exe: Solution.o Line.o Vertex.o Edge.o Segment.o Polygon.o
	g++ -o solution.exe Solution.o Line.o Vertex.o Edge.o Segment.o Polygon.o

Solution.o: Solution.cpp
	g++ -c Solution.cpp

Line.o: Line.cpp
	g++ -c Line.cpp

Vertex.o: Vertex.cpp
	g++ -c Vertex.cpp

Edge.o: Edge.cpp
	g++ -c Edge.cpp

Segment.o: Segment.cpp
	g++ -c Segment.cpp

Polygon.o: Polygon.cpp
	g++ -c Polygon.cpp

clean:
	del solution.exe *.o

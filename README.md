# Straight Skeleton
Straight Skeleton algorithm computation for convex polygons. 

## How to run
```bash
# Makefile needs to be edited for UNIX environment
make clean
make
solution.exe > points.txt
python wavePlot.py
```

**NOTE: wavePlot.py is a python script to plot points and line segments.**

## Modes
- Simulation Mode
- Skeleton Generation Mode

### Simulation Mode
1. Model polygon using **LAV** _(list of active vertices)_ which is a circular connected doubly linked list
2. For each vertex:
    - Set incident edges
    - Set angle bisector
3. Set d = _x_ (where, x = distance moved by **each edge** as it goes inwards. Edges move with same speed so _x_ is equal for all)
4. For each vertex:
    - Compute _l_ which is the distance to be moved by the vertex along bisector _(trignometric functions used)_
    - Modify vertex coordinates
6. Repeat from **2** to **4** for N iterations (N can be given as input)

![simulatePolygon](https://github.com/addy4/StraightSkeleton/assets/42651751/57cd6ef9-6a83-4dff-ba68-ddd27ff5f7c8)

### Skeleton Generation Model
1. Model polygon using **LAV** _(list of active vertices)_ which is a circular connected doubly linked list
2. For each vertex:
    - Set incident edges
    - Set angle bisector
3. _dMin = INTMAX_
4. For each vertex:
    - Get intersection _INX_ point of angle bisector of current vertex and next vertex
    - Compute distance _d_ of intersection point with incident edges
    - _dMin = d < dMin ? d : dMin_
5. **For vertex associated to _dMin_, do StraightSkeletonSketch.add((vertex.xCoordinate, INX.xCoordinate) to (vertex.yCoordinate, INX.yCoordinare))**
5. For each vertex:
    - Compute _l_ according to _dMin_ which is the distance to be moved by the vertex along bisector _(trignometric functions used)_
    - Modify vertex coordinates
6. Repeat from **2** to **5** (until LAV.size <= 3)
7. Print **StraightSkeletonSketch**  
  
![SkeletonPolygon](https://github.com/addy4/StraightSkeleton/assets/42651751/705f4711-aba4-4425-8430-b670f91914d8)



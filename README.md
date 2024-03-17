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
    - Get intersection point _(INX)_ of the angle bisectors of current vertex and next vertex
    - Compute distance _d_ of intersection point with incident edges
    - _dMin = d < dMin ? d : dMin_
4. Save INX associated to least _d_ value. **Add line segments connecting (vertex,INX) and (nextVertex,INX)**
6. The edge lying between the two angle bisectors i.e. edge connecting current vertex to next vertex COLLAPSES.  
7. For each vertex:
    - Compute _l_ according to _dMin_ which is the distance to be moved by the vertex along bisector _(trignometric functions used)_
    - Modify vertex coordinates
8. Remove the coinciding vertices (of collapsed edges) **leaving just one of them**
9. Repeat from **2** to **9** (until LAV.size <= 3)
10. Print **StraightSkeletonSketch**  
  
![SkeletonPolygon](https://github.com/addy4/StraightSkeleton/assets/42651751/705f4711-aba4-4425-8430-b670f91914d8)



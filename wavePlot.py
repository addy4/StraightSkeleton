import matplotlib.pyplot as plt

linesToPlot = []
with open('points.txt', 'r') as inputfile:
    for line in inputfile:
        partsOfLine = line.strip().replace(' ', '').split(',')
        points = list(map(float, partsOfLine))
        linesToPlot.append(points)

plt.figure(figsize=(8, 6))  # Set the figure size

for line in linesToPlot:
    point_source = (line[0], line[1])
    point_dest = (line[2], line[3])

    # Plot points
    plt.scatter(*point_source, color='blue')
    plt.scatter(*point_dest, color='blue')

    # Plot line segment
    plt.plot([point_source[0], point_dest[0]], [point_source[1], point_dest[1]], color='blue')

plt.xlabel('X')
plt.ylabel('Y')
plt.title('Skeleton')
plt.grid(True)
plt.show()
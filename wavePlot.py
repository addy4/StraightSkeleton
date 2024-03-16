import matplotlib.pyplot as plt

# Read points from the text file
lines = []
with open('points.txt', 'r') as file:
    for line in file:
        # Remove whitespace characters and then split by comma
        parts = line.strip().replace(' ', '').split(',')
        points = list(map(float, parts))
        lines.append(points)

# Create the plot with all points and line segments
plt.figure(figsize=(8, 6))  # Set the figure size

for line in lines:
    # Extract points from each line
    point1 = (line[0], line[1])
    point2 = (line[2], line[3])

    # Plot points
    plt.scatter(*point1, color='blue')
    plt.scatter(*point2, color='blue')

    # Plot line segment
    plt.plot([point1[0], point2[0]], [point1[1], point2[1]], color='blue')

plt.xlabel('X')
plt.ylabel('Y')
plt.title('Plot of Points with Line Segments')
plt.grid(True)
plt.show()
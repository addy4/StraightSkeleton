import matplotlib.pyplot as plt

# Read points from the text file
points = []
with open('points.txt', 'r') as file:
    for line in file:
        # Split each line by comma and convert to float
        parts = line.strip().split(',')
        x = float(parts[0])
        y = float(parts[1])
        points.append((x, y))

# Separate x and y coordinates
x_coords, y_coords = zip(*points)

# Create the plot
plt.scatter(x_coords, y_coords, color='blue')
plt.xlabel('X')
plt.ylabel('Y')
plt.title('Plot of Points')
plt.grid(True)
plt.show()

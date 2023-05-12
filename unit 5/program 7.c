# Develop a new graph algorithm to solve the traveling salesman problem and evaluate its efficiency and effectiveness in Python.

# Algorithm:

# Choose a starting city
# For each city, find the nearest neighbor that has not been visited yet
# Visit the nearest neighbor
# Repeat step 2-3 until all cities have been visited
# Return to the starting city to complete the tour

import math

def distance(city1, city2):
    """
    Computes the Euclidean distance between two cities
    """
    x1, y1 = city1
    x2, y2 = city2
    return math.sqrt((x1 - x2) ** 2 + (y1 - y2) ** 2)

def nearest_neighbor(city, cities, visited):
    """
    Finds the nearest neighbor of a given city that has not been visited yet
    """
    min_distance = float('inf')
    nearest_city = None
    for c in cities:
        if c not in visited:
            d = distance(city, c)
            if d < min_distance:
                min_distance = d
                nearest_city = c
    return nearest_city

def tsp(cities):
    """
    Solves the traveling salesman problem using a nearest neighbor heuristic
    """
    tour = [cities[0]]
    visited = {cities[0]}
    while len(visited) < len(cities):
        city = tour[-1]
        nearest = nearest_neighbor(city, cities, visited)
        tour.append(nearest)
        visited.add(nearest)
    tour.append(cities[0])
    return tour
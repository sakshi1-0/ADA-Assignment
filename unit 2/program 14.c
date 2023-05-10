14. Implement a recursive algorithm for computing the Euclidean distance between two points in 2D space using divide-and-conquer.

#include <stdio.h>
#include <math.h>

typedef struct point {
    double x;
    double y;
} Point;

double distance(Point p1, Point p2) {
    return sqrt(pow(p1.x - p2.x, 2) + pow(p1.y - p2.y, 2));
}

double recursive_distance(Point* points, int start, int end) {
    if (end - start == 1) {
        return distance(points[start], points[end]);
    } else if (end - start == 2) {
        return fmin(distance(points[start], points[start + 1]),
                    distance(points[start], points[end]));
    } else {
        int mid = (start + end) / 2;
        double left_distance = recursive_distance(points, start, mid);
        double right_distance = recursive_distance(points, mid + 1, end);
        double min_distance = fmin(left_distance, right_distance);
        int num_points = end - start + 1;
        Point* strip = malloc(num_points * sizeof(Point));
        int j = 0;
        for (int i = start; i <= end; i++) {
            if (fabs(points[i].x - points[mid].x) < min_distance) {
                strip[j++] = points[i];
            }
        }
        for (int i = 0; i < j; i++) {
            for (int k = i + 1; k < j && (strip[k].y - strip[i].y) < min_distance; k++) {
                double d = distance(strip[i], strip[k]);
                min_distance = fmin(min_distance, d);
            }
        }
        free(strip);
        return min_distance;
    }
}

double closest_distance(Point* points, int num_points) {
    qsort(points, num_points, sizeof(Point), compare_points_by_x);
    return recursive_distance(points, 0, num_points - 1);
}

int main() {
    Point points[] = {{1, 1}, {2, 3}, {3, 4}, {4, 2}, {5, 7}};
    int num_points = sizeof(points) / sizeof(points[0]);
    double d = closest_distance(points, num_points);
    printf("The closest distance is %lf\n", d);
    return 0;
}
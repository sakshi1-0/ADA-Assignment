19. Implement a divide-and-conquer algorithm for finding the closest pair of points in 2D space.

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MIN(a, b) ((a) < (b) ? (a) : (b))

typedef struct {
    double x, y;
} point;

int cmp_x(const void* a, const void* b) {
    point* pa = (point*)a;
    point* pb = (point*)b;
    if (pa->x < pb->x) {
        return -1;
    } else if (pa->x > pb->x) {
        return 1;
    } else {
        return 0;
    }
}

int cmp_y(const void* a, const void* b) {
    point* pa = (point*)a;
    point* pb = (point*)b;
    if (pa->y < pb->y) {
        return -1;
    } else if (pa->y > pb->y) {
        return 1;
    } else {
        return 0;
    }
}

double dist(point* p1, point* p2) {
    double dx = p1->x - p2->x;
    double dy = p1->y - p2->y;
    return sqrt(dx * dx + dy * dy);
}

double brute_force(point* points, int n) {
    double min_dist = INFINITY;
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            double d = dist(&points[i], &points[j]);
            if (d < min_dist) {
                min_dist = d;
            }
        }
    }
    return min_dist;
}

double strip_closest(point* strip, int size, double d) {
    double min_dist = d;
    for (int i = 0; i < size; i++) {
        for (int j = i + 1; j < size && strip[j].y - strip[i].y < min_dist; j++) {
            double d = dist(&strip[i], &strip[j]);
            if (d < min_dist) {
                min_dist = d;
            }
        }
    }
    return min_dist;
}

double closest_util(point* points_x, point* points_y, int n) {
    if (n <= 3) {
        return brute_force(points_x, n);
    }
    int mid = n / 2;
    point mid_point = points_x[mid];
    point* points_y_l = calloc(mid, sizeof(point));
    point* points_y_r = calloc(n - mid, sizeof(point));
    int li = 0;
    int ri = 0;
    for (int i = 0; i < n; i++) {
        if (points_y[i].x < mid_point.x) {
            points_y_l[li++] = points_y[i];
        } else {
            points_y_r[ri++] = points_y[i];
        }
    }
    double d_l = closest_util(points_x, points_y_l, mid);
    double d_r = closest_util(points_x + mid, points_y_r, n - mid);
    double d_min = MIN(d_l, d_r);
    point* strip = calloc(n, sizeof(point));
    int j = 0;
    for (int i = 0; i < n; i++) {
        if (fabs(points_y[i].x - mid_point.x) < d_min) {
            strip[j++] = points_y[i];
        }
   
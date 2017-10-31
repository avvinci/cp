#include <bits/stdc++.h>
using namespace std;

typedef pair<double, double> point;

const double PI = 2*acos(0);
const double EPS = 1E-9;

/*
 * Tests if a given_pt is Left|On|Right of an infinite line.
 * Input:  three given_pts P0, P1, and P2
 * Return:  1 for P2 left of the line through P0 and P1
 *          0 for P2 on the line
 *         -1 for P2 right of the line
 */
int is_left(point a, point b, point c) {
	double x = (b.F - a.F) * (c.S - a.S);
	double y = (c.F - a.F) * (b.S - a.S);
	if((x - y) > EPS) {
		return 1;
	} else if((y - x) > EPS) {
		return -1;
	} return 0;
}

void print_point(point a) {
	printf("[%0.1f %0.1f]\n", a.F, a.S);
}

double dist(point a, point b) {
	double x = pow(a.F - b.F, 2);
	double y = pow(a.S - b.S, 2);
	return sqrt(x + y);
}

int main(int argc, char const *argv[]) {
	
	return 0;
}
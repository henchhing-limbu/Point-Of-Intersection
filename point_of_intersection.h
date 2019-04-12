#ifndef PT_OF_INTERSECTION_H
#define PT_OF_INTERSECTION_H

struct Point {
	float x_coordinate;
	float y_coordinate;
};

struct Line_Eqn {
	float x_coeff;
	float y_coeff;
	float cons;
	float slope;
};

// slope is obtained using the formula
// slope = (y2 - y1)/(x2 - x1)
float slope(Point a, Point b);

// equation of the line is in obtained using the formula
// y - y1 = m(x - x1)
Line_Eqn* eqn_of_line(Point pt_1, Point pt_2);

// finds intersecting point between two lines
Point* pt_of_intersection(Line_Eqn* line_1, Line_Eqn* line_2);
// assigns coordinate value to a point
void assign_coordinates(Point* pt, float x, float y);
// prints the equation of line in slope intercept form
// y = mx + c
void print_eqn(Line_Eqn* eqn);

// prints the point in the form (x, y)
void print_point(Point* pt);

#endif


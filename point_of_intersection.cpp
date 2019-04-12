#include <iostream>
#include "point_of_intersection.h"

float slope(Point p1, Point p2) {
	return (p1.y_coordinate - p2.y_coordinate)/(p1.x_coordinate - p2.x_coordinate);
}

Line_Eqn* eqn_of_line(Point p1, Point p2) {
	Line_Eqn* line_eqn = new Line_Eqn;
  float line_slope = slope(p1, p2);

  line_eqn->slope = line_slope;
  line_eqn->y_coeff = 1.0;
  line_eqn->x_coeff = line_slope;
  line_eqn->cons = p1.y_coordinate - line_slope * p1.x_coordinate;
	return line_eqn;
}

Point* pt_of_intersection(Line_Eqn* line_eqn_1, Line_Eqn* line_eqn_2) {
	Point* pt = new Point;
  float x, y;
  x = (line_eqn_1->cons - line_eqn_2->cons)/
        (line_eqn_2->x_coeff - line_eqn_1->x_coeff);
  y = line_eqn_1->slope * x + line_eqn_1->cons;
  assign_coordinates(pt, x, y);
	return pt;
}

void assign_coordinates(Point* pt, float x, float y) {
	pt->x_coordinate = x;
	pt->y_coordinate = y;
}

void print_eqn(Line_Eqn* line_eqn) {
  std::cout << "Equation of the line is : \n";
  std::cout << "y = " << line_eqn->x_coeff << "x";
  if (line_eqn->cons > 0)
    std::cout << " + " << line_eqn->cons;
  else if (line_eqn->cons < 0)
    std::cout << " - " << line_eqn->cons;
  std::cout << std::endl;
}

void print_point(Point* pt) {
  std::cout << "(" << pt->x_coordinate << ", " << pt->y_coordinate << ")\n";
}
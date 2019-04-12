#include <unistd.h>
#include <iostream>
#include "point_of_intersection.h"

int main(int argc, char *args[]) {
  std::cout << "Entered here\n";
	Point line1_pt1, line1_pt2, line2_pt1, line2_pt2;

	assign_coordinates(&line1_pt1, 1, 1);
	assign_coordinates(&line1_pt2, 4, 4);
	assign_coordinates(&line2_pt1, 1, 8);
	assign_coordinates(&line2_pt2, 2, 4);

  Line_Eqn* line1 = eqn_of_line(line1_pt1, line1_pt2);
  Line_Eqn* line2 = eqn_of_line(line2_pt1, line2_pt2);
  print_eqn(line1);
  print_eqn(line2);
  Point* intersecting_pt = pt_of_intersection(line1, line2);
  std::cout << "The intersection point is ";
  print_point(intersecting_pt);

	return 0;
}

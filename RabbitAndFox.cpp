// Johnathan R. Burgess, Guilford Technical Community College (GTCC Team)
// Triad Programming Contest - Problem #2 "Fox and Rabbit"
// 4/6/2019
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <math.h>
#include <iomanip>

using namespace std;

typedef vector<double> Position;
typedef vector<Position> NumberList;

int main() {

	NumberList hole_coordinates;
	NumberList rabbit_positions;
	NumberList fox_positions;

	fstream file;
	try {
		file.open("rabbit.txt", ios::in);
		int count = 0;
		int number_of_holes = 0;
		int original_number_of_holes = 0;
		int number_of_situations = 0;
		double x, y, x2, y2;
		while (file) {
			Position pos;
			Position pos2;
			// if this is the first line in the file
			if (count == 0) {
				file >> number_of_holes;
				if (number_of_holes > 32) {
					original_number_of_holes = number_of_holes;
					number_of_holes = 32;
				}
				else {
					original_number_of_holes = number_of_holes;
				}
			}
			else if ((count>0) && (count < (number_of_holes+1))) {
				file >> x >> y;
				pos.push_back(x);
				pos.push_back(y);
				hole_coordinates.push_back(pos);
			}
			else if (count == (original_number_of_holes+2)) {
				file >> number_of_situations;
			}
			else if ((count > (original_number_of_holes+2))){
				file >> x >> y >> x2 >> y2;
				pos.push_back(x);
				pos.push_back(y);
				pos2.push_back(x2);
				pos2.push_back(y2);
				rabbit_positions.push_back(pos);
				fox_positions.push_back(pos2);
			}
			count++;
		}
		file.close();
	}
	catch (string exception){
		return 1;
	}
	/*for (int i = 0; i < hole_coordinates.size(); i++) {
		Position p = hole_coordinates.at(i);
		for (int j = 0; j < 2; j++) {
			cout << p.at(j) << " ";
		}
		cout << endl;
	}
	cout << endl;

	for (int i = 0; i < fox_positions.size()-1; i++) {
		Position p = fox_positions.at(i);
		for (int j = 0; j < 2; j++) {
			cout << p.at(j) << " ";
		}
		cout << endl;
	}
	cout << endl;

	for (int i = 0; i < rabbit_positions.size()-1; i++) {
		Position p = rabbit_positions.at(i);
		for (int j = 0; j < 2; j++) {
			cout << p.at(j) << " ";
		}
		cout << endl;
	}

	cout << endl << endl;*/

	// main solver:
	for (int i = 0; i < (fox_positions.size()-1); i++) {
		double rabbit_distance_from_target_hole;
		double fox_distance_from_target_hole;
		Position position_target_hole;
		Position rabbit_position = rabbit_positions.at(i);
		Position fox_position = fox_positions.at(i);
		double smallest = 10.0;
		bool foundHole = false;
		for (int j = 0; j < hole_coordinates.size(); j++) {
			int hole_x = hole_coordinates.at(j).at(0);
			int hole_y = hole_coordinates.at(j).at(1);
			double x_distance_between_hole_and_rabbit = abs(rabbit_position.at(0) - hole_x);
			double y_distance_between_hole_and_rabbit = abs(rabbit_position.at(1) - hole_y);
			double real_distance_between_hole_and_rabbit = sqrt((x_distance_between_hole_and_rabbit * x_distance_between_hole_and_rabbit)
				+ (y_distance_between_hole_and_rabbit * y_distance_between_hole_and_rabbit));
			double x_distance_between_hole_and_fox = abs(fox_position.at(0) - hole_x);
			double y_distance_between_hole_and_fox = abs(fox_position.at(1) - hole_y);
			double real_distance_between_hole_and_fox = sqrt((x_distance_between_hole_and_fox * x_distance_between_hole_and_fox)
				+ (y_distance_between_hole_and_fox * y_distance_between_hole_and_fox));
			if (real_distance_between_hole_and_rabbit < smallest) {
				if (real_distance_between_hole_and_fox > (real_distance_between_hole_and_rabbit * 2)) {
					smallest = real_distance_between_hole_and_rabbit;
					position_target_hole = hole_coordinates.at(j);
					foundHole = true;
				}
			}
		}
		if (foundHole == true) {
			cout << setprecision(1) << fixed;
			cout << "safe at " << position_target_hole.at(0) << ", " << position_target_hole.at(1) << endl;
		}
		else {
			cout << "The rabbit is doomed." << endl;
		}

	}

	system("pause");
	return 0;
}
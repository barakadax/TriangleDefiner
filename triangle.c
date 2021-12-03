#include <math.h>
#include <stdio.h>
#define PI 3.1415926
#define TRIANGLE_SIDES_NUM 3
#define TRIANGLE_DEGREE_MAX 180

void InputTriangleSides(double *triangle) {
    for (int isValidInput = 0, triangle_side_counter = 0; !isValidInput && triangle_side_counter < TRIANGLE_SIDES_NUM; isValidInput = 0) {
		printf("Please enter triangle side #%d: ", triangle_side_counter + 1);
        isValidInput = scanf("%lf", &triangle[triangle_side_counter]);
        for (char ch; ch = getchar() != '\n' && ch != EOF;) {};
		!isValidInput || triangle[triangle_side_counter] <= 0.0 ? printf("Incorrect input!.\n") : triangle_side_counter++;
    }
}

void PrintTriangleType(double *triangle) {
	triangle[0] == triangle[1] && triangle[0] == triangle[2] ? printf("The triangle type is equilateral") :
	triangle[0] == triangle[1] || triangle[0] == triangle[2] || triangle[1] == triangle[2] ?
	printf("The triangle type is isosceles") : printf("The triangle type is different sides");
}

void CalculateTriangleDegrees(double *triangle, double *angles) {
	for (unsigned short int triangle_side_counter = 0; triangle_side_counter < TRIANGLE_SIDES_NUM; triangle_side_counter -= -1)
		angles[triangle_side_counter] = acos(((pow(triangle[triangle_side_counter], 2) +
		pow(triangle[(triangle_side_counter + 1) % 3], 2) - pow(triangle[(triangle_side_counter + 2) % 3], 2))
		/ (2 * triangle[triangle_side_counter] * triangle[(triangle_side_counter + 1) % 3]))) * TRIANGLE_DEGREE_MAX / PI;
}

void PrintIfRightTriangle(double *angles) {
	for (unsigned short int triangle_side_counter = 0; triangle_side_counter < TRIANGLE_SIDES_NUM; triangle_side_counter -= -1)
		if ((int)angles[triangle_side_counter] == 90 && round(angles[triangle_side_counter]) == 90)
			printf(" & the triangle is also right triangle");
	printf(".\n");
}

void main() {
	double triangle[TRIANGLE_SIDES_NUM] = {0.0}, angles[TRIANGLE_SIDES_NUM] = {0.0};
	InputTriangleSides(triangle);
	PrintTriangleType(triangle);
	CalculateTriangleDegrees(triangle, angles);
	PrintIfRightTriangle(angles);
}
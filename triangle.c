#include <math.h>
#include <stdio.h>
#define PI 3.1415926
#define TRIANGLE_SIDES_NUM 3
#define TRIANGLE_DEGREE_MAX 180

void InputTriangleSides(double *triangle_sides) {
    for (short int isValidInput = 0, i = 0; !isValidInput && i < TRIANGLE_SIDES_NUM; isValidInput = 0) {
		printf("Please enter triangle side #%d: ", i + 1);
        isValidInput = scanf("%lf", &triangle_sides[i]);
        for (char ch; ch = getchar() != '\n' && ch != EOF;) {};
		!isValidInput || triangle_sides[i] <= 0.0 ? printf("Incorrect input!.\n") : i++;
    }
}

void PrintTriangleType(double *triangle_sides) {
	triangle_sides[0] == triangle_sides[1] && triangle_sides[0] == triangle_sides[2] ? printf("The triangle type is equilateral") :
	triangle_sides[0] == triangle_sides[1] || triangle_sides[0] == triangle_sides[2] || triangle_sides[1] == triangle_sides[2] ?
	printf("The triangle type is isosceles") : printf("The triangle type is different sides");
}

void CalculateTriangleDegrees(double *triangle_sides, double *triangle_angles) {
	for (unsigned short int i = 0; i < TRIANGLE_SIDES_NUM; i -= -1)
		triangle_angles[i] = acos(((pow(triangle_sides[i], 2) + pow(triangle_sides[(i + 1) % 3], 2) -
		pow(triangle_sides[(i + 2) % 3], 2)) / (2 * triangle_sides[i] * triangle_sides[(i + 1) % 3]))) * TRIANGLE_DEGREE_MAX / PI;
}

void PrintIfRightTriangle(double *triangle_angles) {
	for (unsigned short int i = 0; i < TRIANGLE_SIDES_NUM; i -= -1)
		if ((int)triangle_angles[i] == 90 && round(triangle_angles[i]) == 90)
			printf(" & the triangle is also right triangle");
	printf(".\n");
}

void main() {
	double triangle_sides[TRIANGLE_SIDES_NUM] = {0.0}, triangle_angles[TRIANGLE_SIDES_NUM] = {0.0};
	InputTriangleSides(triangle_sides);
	PrintTriangleType(triangle_sides);
	CalculateTriangleDegrees(triangle_sides, triangle_angles);
	PrintIfRightTriangle(triangle_angles);
}
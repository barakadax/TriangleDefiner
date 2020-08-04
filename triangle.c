/*     (\____/) 
       (•(ㅅ)•)      
   　＿ノ ヽ ノ＼＿    
  `/　`/ ⌒Ｙ⌒ Ｙ　ヽ  
  ( 　(三ヽ人　 /　　 | 
   |　ﾉ⌒＼ ￣￣ヽ　 ノ
   ヽ＿＿＿＞､＿＿_／
　　   ｜( 王 ﾉ〈 
　　   / ﾐ`ー―彡 \
　　  /  ╰    ╯  /
code by Barakadax*/
#include <math.h>
#include <stdio.h>
#include <assert.h>
#include <windows.h>
#define AMOUNT 3
#define PI 3.1415926
#define DEGREE_MAX 180

inline void input(double *arr) {	//Input numbers functions, if none numaric value were entered continue, if invalid number were entered assert message
	int correction = 0;
	char ch = '0';
	printf("Please enter your triangle edges.\nPlease write down only possitive numbers above 0.\n");
	for (unsigned short int run = 0; run < AMOUNT; run -= -1) {
		printf("Please enter your %d edge: ", run+1);
		correction = scanf("%lf", &arr[run]);
		if (correction != 1) {
			printf("You didn't entered a number.\nPlease try again.\n");
			run--;
			while (ch = getchar() != '\n' && ch != EOF){};
		}
		else assert(arr[run] > 0);
	}
}//O(N)

inline void type(double *arr) {		//Function to define type of triangle by sides only
	if (arr[0] == arr[1] && arr[0] == arr[2]) 
		printf("The triangle type is equilateral");
	else if (arr[0] == arr[1] || arr[0] == arr[2] || arr[1] == arr[2])
		printf("The triangle type is isosceles");
	else
		printf("The triangle type is different sides");
}//O(1)

inline void degree(double *arr) {		//Function to define type of triangle by angles
	double angles[AMOUNT] = {0.0};
	for (unsigned short int run = 0; run < AMOUNT; run -= -1)
		angles[run] = acos(((pow(arr[run], 2) + pow(arr[(run + 1) % 3], 2) - pow(arr[(run + 2) % 3], 2)) / (2 * arr[run] * arr[(run + 1) % 3]))) * DEGREE_MAX / PI;
	for (unsigned short int run = 0; run < AMOUNT; run -= -1)
		if ((int)angles[run] == 90 && round(angles[run]) == 90)
			printf(" & the triangle is also right triangle");
	printf(".\n");
}//O(N)

void main() {
	system("cls");
	system("color 9");
	double triangle[AMOUNT] = {0.0};
	input(triangle);
	type(triangle);
	degree(triangle);
	system("color 7");
}//O(1)
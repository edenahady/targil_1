#include<iostream>
#include<math.h>
#include<cmath>

using namespace std;
void manhattan_distance(double x1, double x2, double y1, double y2, double z1, double z2)
{
	double distance;
	double x_dif, y_dif, z_dif;

	x_dif = abs(x2 - x1);
	y_dif = abs(y2 - y1);
	z_dif = abs(z2 - z1);
	distance = x_dif + y_dif + z_dif;
	cout << "\n\nManhattan Distance between P1(" << x1 << "," << y1 << ") and P2(" << x2 << "," << y2 << ") : " << distance;
}

double distanceCalculate(double x1, double y1, double z1, double x2, double y2, double z2)
{
	double x = x1 - x2; //calculating number to square in next step
	double y = y1 - y2;
	double z = z1 - z2;
	double dist;

	dist = pow(x, 2) + pow(y, 2) + pow(z, 2);       //calculating Euclidean distance
	dist = sqrt(dist);

	return dist;
}

//int main()
//{
//	double x1, y1, x2, y2;
//	double dist;
//	cout << "Enter x1:" << endl;    //user inputs the points
//	cin >> x1;
//	cout << "Enter y1:" << endl;
//	cin >> y1;
//	cout << "Enter x2:" << endl;
//	cin >> x2;
//	cout << "Enter y2:" << endl;
//	cin >> y2;
//
//	dist = distanceCalculate(x1, y1, x2, y2);    //initiate equation
//	cout << "Distance Between (" << x1 << " , " << y1 << ") and (" << x2 << " , " << y2 << ") = " << dist;
//}
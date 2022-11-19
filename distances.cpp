#include<iostream>
#include<math.h>
<<<<<<<< HEAD:distances.cpp
#include<cmath>
#include<vector>

========
#include<cmath.h>
>>>>>>>> 86cf2238d01223285eadfdfea8570dc980fe6cb5:euclidean .cpp
using namespace std;

array difference_calculator(arr1, arr2)
{
	double x_dif, y_dif, z_dif;
	double dif_arr[];

	dif_arr[0] = abs(arr1[0] - arr2[0]);
	dif_arr[1] = abs(arr1[1] - arr2[1]);
	dif_arr[2] = abs(arr1[2] - arr2[2]);
	return dif_arr
}


=======
<<<<<<<< HEAD:distances.cpp
#include<cmath>

========
#include<cmath.h>

using namespace std;
>>>>>>> 5f32e8814c42ffe37ad185c6ce17885be41eb04e
void manhattan_distance(dif_arr)
{
	double distance = dif_arr[0] + dif_arr[1] + dif_arr[2];
	cout << distance;
}

void euclidean(dif_arr)
{
	

	double dist = pow(dif_arr[0], 2) + pow(dif_arr[1], 2) + pow(dif_arr[2], 2);       //calculating Euclidean distance
	dist = sqrt(dist);

	cout << dist;
}


void chebyshev(dif_arr)
{
	double max_temp = max(dif_arr[0], diff_arr[1]);
	max_temp = max(max_temp, diff_arr[2]);
	cout << max_temp;
}

void canberra(dif_arr, arr1, arr2)
{
	sol1 = dif_arr[0] / (arr1[0] + arr2[0]);
	sol2 = dif_arr[1] / (arr1[1] + arr2[1]);
	sol3 = dif_arr[2] / (arr1[2] + arr2[2]);
	dist = sol1 + sol2 + sol3;
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
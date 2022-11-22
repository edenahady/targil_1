#include<iostream>
#include<math.h>

#include<vector>
#include <iomanip>
#include<cmath>
#include"distances.h"

using namespace std;
>>>>>>> 5f32e8814c42ffe37ad185c6ce17885be41eb04e

void manhattan_distance(double[] dif_arr)
{
	double distance = dif_arr[0] + dif_arr[1] + dif_arr[2];
	cout << setprecision(10) << distance;
}
double * difference_calculator(double[] arr1, double[] arr2)
{
	double x_dif, y_dif, z_dif;
	double dif_arr[];

	dif_arr[0] = Math.Abs(arr1[0] - arr2[0]);
	dif_arr[1] = Math.Abs(arr1[1] - arr2[1]);
	dif_arr[2] = Math.Abs(arr1[2] - arr2[2]);
	return dif_arr
}


void euclidean(double[] dif_arr)
{
	

	double dist = pow(dif_arr[0], 2) + pow(dif_arr[1], 2) + pow(dif_arr[2], 2);       
	dist = sqrt(dist);

	cout << setprecision(10) << dist;
}


void chebyshev(double[] dif_arr)
{
	double max_temp = max(dif_arr[0], diff_arr[1]);
	max_temp = max(max_temp, diff_arr[2]);
	cout << setprecision(10) << max_temp;
}

void canberra(double[] dif_arr, double[] arr1, double[] arr2)
{
	sol1 = dif_arr[0] / (arr1[0] + arr2[0]);
	sol2 = dif_arr[1] / (arr1[1] + arr2[1]);
	sol3 = dif_arr[2] / (arr1[2] + arr2[2]);
	dist = sol1 + sol2 + sol3;
	cout << setprecision(10) << dist;
}

void minkowski(double[] diff_arr)
{
	int sum = 0;
	for (int i = 0; i < 3; i++)
	{
		sum = sum + Math.Pow(diff_arr[i], 2);
	}
	cout<< setprecision(10) << Math.Sqrt(sum);
}

int main()
{
	
	double arry1[3];
	for (int i = 0; i < 3 i++)
	{
		cin >> arry1[i];
	}
	cout<< << endl;
	double arry2[3];

	for (int i = 0; i < 3 i++)
	{
		cin >> arry2[i];
	}
	cout<< << endl;

	euclidean(difference_calculator(arry1, arry2));
	manhattan_distance(difference_calculator(arry1, arry2));
	chebyshev(difference_calculator(arry1, arry2));
	canberra(difference_calculator(arry1, arry2), arry1, arry2);
	minkowski(difference_calculator(arry1, arry2));
}
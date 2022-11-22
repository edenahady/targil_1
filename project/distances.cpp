#include<iostream>
#include<math.h>
#include<vector>
#include <iomanip>
#include<cmath>
#include"distances.h"

using namespace std;
// >>>>>>> 5f32e8814c42ffe37ad185c6ce17885be41eb04e
class distances{

	distances::distances(vector<double> v1, vector<double> v2) {};
	distances::distances(){};
	void distances:: manhattan_distance(double dif_arr[])
	{
		double distance = dif_arr[0] + dif_arr[1] + dif_arr[2];
		cout << setprecision(10) << distance;
	}
	double * distances:: difference_calculator(double arr1[], double arr2[])
	{
		double x_dif, y_dif, z_dif;
		double dif_arr[3] = {};

		dif_arr[0] = abs(arr1[0] - arr2[0]);
		dif_arr[1] = abs(arr1[1] - arr2[1]);
		dif_arr[2] = abs(arr1[2] - arr2[2]);
		return dif_arr;
	}


	void distances::euclidean(double dif_arr[])
	{
		

		double dist = pow(dif_arr[0], 2) + pow(dif_arr[1], 2) + pow(dif_arr[2], 2);       
		dist = sqrt(dist);

		cout << setprecision(10) << dist;
	}


	void distances:: chebyshev(double dif_arr[])
	{
		double max_temp = max(dif_arr[0], dif_arr[1]);
		max_temp = max(max_temp, dif_arr[2]);
		cout << setprecision(10) << max_temp;
	}

	void distances:: canberra(double dif_arr[], double arr1[], double arr2[])
	{
		double sol1 = dif_arr[0] / (arr1[0] + arr2[0]);
		double sol2 = dif_arr[1] / (arr1[1] + arr2[1]);
		double sol3 = dif_arr[2] / (arr1[2] + arr2[2]);
		double dist = sol1 + sol2 + sol3;
		cout << setprecision(10) << dist;
	}

	void distances:: minkowski(double dif_arr[])
	{
		int sum = 0;
		for (int i = 0; i < 3; i++)
		{
			sum = sum + pow(dif_arr[i], 2);
		}
		cout<< setprecision(10) << sqrt(sum);
	}

	int main()
	{
		vector <double> v1{1, 2, 3};
		vector <double> v2{3, 2, 1};
		
		// double arry1[3];
		// for (int i = 0; i < 3; i++)
		// {
		// 	cin >> arry1[i];
		// }
		// cout<< endl;
		// double arry2[3];

		// for (int i = 0; i < 3; i++)
		// {
		// 	cin >> arry2[i];
		// }
		// cout<< endl;

		distances dis(v1, v2);
		dis.euclidean(difference_calculator(v1,v2));
		manhattan_distance(difference_calculator(arry1, arry2));
		chebyshev(difference_calculator(arry1, arry2));
		canberra(difference_calculator(arry1, arry2), arry1, arry2);
		minkowski(difference_calculator(arry1, arry2));
	}
}
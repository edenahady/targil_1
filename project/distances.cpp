#include<iostream>
#include<math.h>
#include<vector>
#include <iomanip>
#include<cmath>
#include"distances.h"

//lynn molga nagar 319090965
//eden ahady 318948106

using namespace std;
// >>>>>>> 5f32e8814c42ffe37ad185c6ce17885be41eb04e


Distances::Distances(vector<double> v1, vector<double> v2) {}
Distances::Distances(){};

// vector<double> Distances:: Difference_Calculator(vector<double> v1, vector<double> v2)
// //calculates the difference between 2 vectors
// {
// 	vector<double> Dif_V;
// 	for (int i=0; i<v1.size(); i++)
// 	{
// 		Dif_V[i] = abs(v1[i] - v2[i]);
// 	}
// 	return Dif_V;
// 	// dif_arr[0] = abs(v1[0] - v2[0]);
// 	// dif_arr[1] = abs(v1[1] - v2[1]);
// 	// dif_arr[2] = abs(v1[2] - v2[2]);
// 	// return dif_arr;
// }

double Distances:: Manhattan_Distance(vector<double> v1, vector<double> v2)
//uses the difference and sums them
{
	double sum = 0;
	for (int i=0; i<v1.size(); i++)
	{
		sum += abs(v1[i]-v2[i]);
	}
	// double distance = dif_v[0] + dif_v[1] + dif_v[2];
	return sum;
}

double Distances::euclidean(vector<double> v1, vector<double> v2)
//returns the square root of sum of the squares of the difference
{
	double dist = 0;
	for (int i=0; i<v1.size(); i++)
	{
		dist += pow(abs(v1[i]-v2[i]),2);
	}
	// double dist = pow(dif_v[0], 2) + pow(dif_v[1], 2) + pow(dif_v[2], 2);       
	dist = sqrt(dist);
	// cout << setprecision(10) << dist;
	return dist;
}


double Distances::chebyshev(vector<double> v1, vector<double> v2)
{
//returns the max of the differences of the 2 vectors
	double max = 0;
	for (int i=0; i<v1.size(); i++){
		if (max< abs(v1[i]-v2[i]))
		{
			max = abs(v1[i]-v2[i]);
		}
	}
	// double max_temp = max(dif_arr[0], dif_arr[1]);
	// max_temp = max(max_temp, dif_arr[2]);
	return max;
}

double Distances:: canberra(vector<double> v1, vector<double> v2)
//returns the difference between the 2 vector devided by the sum of them
{
	double sum = 0;
	for (int i=0; i< v1.size(); i++)
	{
		sum += abs(v1[i]-v2[i])/(v1[i]+v2[i]);
	}
	// double sol1 = dif_arr[0] / (arr1[0] + arr2[0]);
	// double sol2 = dif_arr[1] / (arr1[1] + arr2[1]);
	// double sol3 = dif_arr[2] / (arr1[2] + arr2[2]);
	// double dist = sol1 + sol2 + sol3;
	return sum;
}

double Distances::minkowski(vector<double> v1, vector<double> v2)
//returns the square root of sum of the squares of the difference
{
	int sum = 0;
	for (int i = 0; i < v1.size(); i++)
	{
		sum += pow(abs(v1[i]-v2[i]), 2);
	}
	return sqrt(sum);
}

int main()
{
	vector<double> v1{1, 2, 3};
	vector<double> v2{3, 2, 1};
	
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

	Distances dis(v1, v2);
	//vector<double> difference = dis.Distances::Difference_Calculator(v1,v2);
	double euc =  dis.Distances::euclidean(v1, v2);
	double ManH = dis.Distances::Manhattan_Distance(v1, v2);
	double cheb = dis.Distances::chebyshev(v1, v2);
	double canb = dis.Distances::canberra(v1, v2);
	double mink = dis.Distances::minkowski(v1, v2);
	cout<<setprecision(10)<<euc<<endl;
	cout<<setprecision(10)<<ManH<<endl;
	cout<<setprecision(10)<<cheb<<endl;
	cout<<setprecision(10)<<canb<<endl;
	cout<<setprecision(10)<<mink<<endl;
}
	//setprecision(10) לזכור לשים

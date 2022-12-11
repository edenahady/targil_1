#include"distances.h"
#include<iostream>
#include<math.h>
#include<vector>
#include <iomanip>
#include <ctype.h>
#include <stdio.h>
#include <algorithm>
#include <string>

//lynn molga nagar 319090965
//eden ahady 318948106

using namespace std;
// >>>>>>> 5f32e8814c42ffe37ad185c6ce17885be41eb04e


Distances::Distances(vector<double> doublev1, vector<double> doublev2) {}
Distances::Distances() {};

double Distances::Manhattan_Distance(vector<double> v1, vector<double> v2)
//uses the difference and sums them
{
	double sum = 0;
	for (int i = 0; i < v1.size(); i++)
	{
		sum += abs(v1[i] - v2[i]);
	}
	return sum;
}

double Distances::euclidean(vector<double> v1, vector<double> v2)
//returns the square root of sum of the squares of the difference
{
	double dist = 0;
	for (int i = 0; i < v1.size(); i++)
	{
		dist += pow(abs(v1[i] - v2[i]), 2);
	}     
	dist = sqrt(dist);
	return dist;
}


double Distances::chebyshev(vector<double> v1, vector<double> v2)
{
	//returns the max of the differences of the 2 vectors
	double max = 0;
	for (int i = 0; i < v1.size(); i++) 
	{
		if (max < abs(v1[i] - v2[i]))
		{
			max = abs(v1[i] - v2[i]);
		}
	}
	return max;
}

double Distances::canberra(vector<double> v1, vector<double> v2)
//returns the difference between the 2 vector devided by the sum of them
{
	double sum = 0;
	for (int i = 0; i < v1.size(); i++)
	{
		sum += abs(v1[i] - v2[i]) / (v1[i] + v2[i]);
	}
	return sum;
}

double Distances::minkowski(vector<double> v1, vector<double> v2)
//returns the square root of sum of the squares of the difference
{
	double sum = 0;
	for (int i = 0; i < v1.size(); i++)
	{
		sum += pow(abs(v1[i] - v2[i]), 2);
	}
	return sqrt(sum);
}

// int main()
// {
// 	vector<string> v1;
// 	vector<string> v2;
// 	string num1;
// 	string num2;
// 	getline(cin, num1);
	
// 	for (int i = 0; i < num1.size(); i++)
// 	{
// 		if (num1[i] == ' ' && (i != 0 && i != num1.size() - 1))
// 		{
// 			continue;
// 		}
// 		if (isdigit(num1[i]))
// 		{
// 			v1.push_back(&num1[i]);
// 		}
// 		else
// 		{
// 			exit(1);
// 		}
// 	}

// 	getline(cin, num2);
// 	for (int i = 0; i < num2.size(); i++)
// 	{
// 		if (num2[i] == ' ' && (i != 0 && i != num2.size() - 1))
// 		{
// 			continue;
// 		}
// 		if (isdigit(num2[i]))
// 		{
// 			v2.push_back(&num2[i]);
// 		}
// 		else
// 		{
// 			exit(1);
// 		}
// 	}

// 	if (v1.size() != v2.size())
// 	{
// 		exit(1);
// 	}

// 	vector<double> doublev1;
// 	doublev1.reserve(v1.size());
// 	transform(v1.begin(), v1.end(), back_inserter(doublev1),
// 		[](string const& val) {return stod(val); });

// 	vector<double> doublev2;
// 	doublev2.reserve(v2.size());
// 	transform(v2.begin(), v2.end(), back_inserter(doublev2),
// 		[](string const& val) {return stod(val); });

// 	Distances dis(doublev1, doublev2);
// 	double euc = dis.Distances::euclidean(doublev1, doublev2);
// 	double ManH = dis.Distances::Manhattan_Distance(doublev1, doublev2);
// 	double cheb = dis.Distances::chebyshev(doublev1, doublev2);
// 	double canb = dis.Distances::canberra(doublev1, doublev2);
// 	double mink = dis.Distances::minkowski(doublev1, doublev2);
// 	if (euc == round(euc)) {
// 		cout << euc <<".0" << endl;
// 	}
// 	else
// 	{
// 		cout << setprecision(10) << euc << endl;
// 	}
// 	if (ManH == round(ManH)) {
// 		cout << ManH<< ".0" << endl;
// 	}
// 	else
// 	{
// 		cout << setprecision(10) << ManH << endl;
// 	}
// 	if (cheb == round(cheb)) {
// 		cout << cheb << ".0" << endl;
// 	}
// 	else
// 	{
// 		cout << setprecision(10) << cheb << endl;
// 	}
// 	if (canb == round(canb)) {
// 		cout << canb << ".0" << endl;
// 	}
// 	else
// 	{
// 		cout << setprecision(10) << canb << endl;
// 	}
// 	if (mink == round(mink)) {
// 		cout << mink << ".0" << endl;
// 	}
// 	else
// 	{
// 		cout << setprecision(10) << mink << endl;
// 	}
// }
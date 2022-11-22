#pragma once
#define HEADER_distances
#include<iostream>
#include<math.h>
#include<vector>
#include <iomanip>
#include<cmath>

using namespace std;
using std::vector;
class Distances
{
   public:
       Distances(vector<double> v1, vector<double> v2);
       Distances();
       double Manhattan_Distance(vector<double> Dif_V);
       vector<double> Difference_Calculator(vector<double> v1, vector<double> v2);
       double euclidean(vector<double>& Dif_V);
       double chebyshev(vector<double> Dif_V);
       double canberra(vector<double> Dif_V, vector<double> v1, vector<double> v2);
       double minkowski(vector<double>& Dif_V);
};
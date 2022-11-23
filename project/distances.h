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
    Distances(vector<double> doublev1, vector<double> doublev2);
    Distances();
    double Manhattan_Distance(vector<double> v1, vector<double> v2);
    //vector<double> Difference_Calculator(vector<string> v1, vector<string> v2);
    double euclidean(vector<double> v1, vector<double> v2);
    double chebyshev(vector<double> v1, vector<double> v2);
    double canberra(vector<double> v1, vector<double> v2);
    double minkowski(vector<double> v1, vector<double> v2);
};
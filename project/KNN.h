#pragma once
#define HEADER_KNN
#include<iostream>
#include<vector>
#include <fstream>
#include<iostream>
#include<sstream>
#include <string>
#include <algorithm>
#include <stdio.h>

using namespace std;
using std::vector;
class KNN
{
public:
    KNN(string kStr, string disStr, string fileStr);
    bool checkK(string kStr);
    bool checkDis(string disStr);
    vector< vector<string> > checkFile ();
};
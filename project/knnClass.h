#pragma once
#include "pair.h"
#include <map>
#include<vector>
using namespace std;
class knnClass
{
    private:
    vector<vector<string>> content;
    vector<double> input;
    string dis ;
    int k;

public:
 knnClass(vector<vector<string>> content, vector<double> input, string dis, int k);
 vector<Pair> calcDist();
 vector<Pair> sortvec(vector<Pair> pairs);
 string biggestCount(map<string,int> classCount);
 string classification(vector<Pair> pairs);

};
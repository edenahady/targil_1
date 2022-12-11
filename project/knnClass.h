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


};
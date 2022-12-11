#include "distances.h"
#include "KNN.h"
#include "knnClass.h"
#include "pair.h"
#include <vector>

using namespace std;


    // parameterized constructor to initialize variables
    knnClass::knnClass(vector<vector<string>> content1, vector<double> input1, string dis1, int k1) 
    {
      content = content1;
      input = input1;
      k = k1;
      dis = dis1;

    }

    vector<Pair> knnClass::calcDist()
    {
        vector<Pair> Pairs;
        double distance;
        for(int j=0; j<content.size(); j++)
        {
                vector<double> disVec;
                disVec.reserve(content[j].size()-1);
                transform(content[j].begin(), prev(content[j].end()), back_inserter(disVec),
                [](string const& val) {return stod(val); });
                Distances vectors = Distances(input,disVec);
                if(dis == "MAN")
                {
                    distance = vectors.Manhattan_Distance(disVec, input);                  
                }
                 else if(dis == "AUC")
                {
                    distance = vectors.euclidean(disVec, input);                  
                }
                else if(dis == "CHB")
                {
                    distance = vectors.chebyshev(disVec, input);                  
                }
                else if(dis == "CAN")
                {
                    distance = vectors.canberra(disVec, input);                  
                }
                else if(dis == "MIN")
                {
                    distance = vectors.minkowski(disVec, input);                  
                }
                Pair p = Pair(distance, j);
                Pairs.push_back(p);
        }
        return Pairs;
    }
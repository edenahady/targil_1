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
        vector<Pair> Pairs; //vector of pairs
        double distance;
        for(int j=0; j<content.size(); j++)
        {
                vector<double> disVec;
                disVec.reserve(content[j].size()-1);
                transform(content[j].begin(), prev(content[j].end()), back_inserter(disVec),
                [](string const& val) {return stod(val); }); //casting the inner vector from string to double
                Distances vectors = Distances(input,disVec); //distances object
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
                Pair p = Pair(distance, j); //creates a pair with distance and index
                Pairs.push_back(p); //insert to pair vector
        }
        return Pairs;
    }

    vector<Pair> knnClass::sortvec(vector<Pair> pairs) //sorts vector
    {
        sort(pairs.begin(), pairs.end(), [](Pair a,Pair b) {
        return a.getval() < b.getval();});
        return pairs;
    }

    string knnClass::classification(vector<Pair> pairs)
    {
        map<string, int> classCount;
        string s;
        int count = 0;
        for (int i=0; i<k; i++)
        {
            int index_in_vec = pairs[i].getindex(); //index of the vector
            int size_of_inner_vec = content[index_in_vec].size()-1; //size of the inner vector
            count = 0;
            for (int j=0; j<k; j++)
            {
                int index_in_vecJ = pairs[j].getindex();
                int size_of_inner_vecJ = content[index_in_vec].size()-1;
                
                s = content[index_in_vec][size_of_inner_vec]; //classification of inner vector 
                
                if (s == content[index_in_vecJ][size_of_inner_vecJ])
                {
                    count++;
                }
            }
            classCount.insert(make_pair(s,count));
        }
        return classCount.rbegin()->first; //returns the value of the last key in map (the biggest count)
    }

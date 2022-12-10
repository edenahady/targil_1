#include "distances.h"
#include "distances"
#include "KNN.cpp"
#include <map>

using namespace std;
class knnClass
{
    private:
    vector<vector<string>> content;
    vector<double> input;
    string dis ;
    int k;

  public:
    // parameterized constructor to initialize variables
    knnClass(vector<vector<string>> content, vector<double> input, string dis, int k) 
    {
      content = content;
      input = input;
      k = k;
      dis = dis;

    }

    map<double,int> makedic(vector<vector<string>> content, vector<double> input, string dis)
    {
        map<double,int> disMap;
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
                disMap.insert(pair<double, int>(distance,j));
        }
        return disMap;
    }

};
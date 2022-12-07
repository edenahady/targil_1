//lynn molga nagar 319090965
//eden ahady 318948106
#include<iostream>
#include<vector>
#include <fstream>
#include<iostream>
#include<sstream>
using namespace std;

bool checkK(string kStr)
{
    for (int i=0; i<kStr.size(); i++)
    {
        if (kStr[i] == ' ' && (i != 0 && i != kStr.size() - 1))
		{
			return false;
		}
        for (int j = 0; j< kStr.size(); j++)
		{
			if (!isdigit(kStr[i]))
		 {
			return false;
		 }

		}
    }
    return true;
}

bool checkDis(string disStr)
{
    if(disStr == "AUC" || disStr == "MAN" || disStr == "CHB" || disStr == "CAN" || disStr == "MIN")
    {
        return true;
    } 
    return false;
}

bool checkFile (string fileStr)
{
    ifstream ifile;
    ifile.open(fileStr);
    if(ifile) 
    {
        return true;
    } else
    {
        return false;
    }
}

int main()
{   
    string str;
    string kStr;
    string fileStr;
    string disStr;
    string word = "";
    getline(cin, str);
    int count = 0;
    bool f = true;
    for (auto x : str)
    {
        if (x == ' ')
        {
            if(f == true) 
            {
                exit(1);
            }
            else
            {
                count++;
                
                switch (count)
                {
                case 1:
                     kStr = word;
                    break;
                
                case 2:
                    fileStr = word;
                    break;
                }
                word = "";
            }
        }
        else 
        {
            word = word + x;
            f = false;
        }
    }
    disStr = word;
    int numK;
    if (checkK(kStr))
    {
        istringstream(kStr) >>numK;
    }
    else{
        exit(1);
    }

    if(!checkDis(disStr))
    {
        exit(1);
    }
    // if(!checkFile(fileStr))
    // {
    //    exit(1);
    // }

    string vec;
    string num;
    getline(cin, vec);
    vector<string> v1;
    for (int i = 0; i < vec.size(); i++)
    {
        if (vec[i] == ' ' && (i != 0 && i != vec.size() - 1))
		{
			continue;
		}
        while(vec[i] != ' ' && i<vec.size())
		{
			num.push_back(vec[i]);
			i++;
		}
		for (int j = 0; j< num.size(); j++)
		{
			if (!isdigit(num[j]) && num[j] != '.')
		 {
			exit(1);
		 }

		}
		v1.push_back(num);
        num = "";

    }
   

}
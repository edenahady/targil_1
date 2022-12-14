//lynn molga nagar 319090965
//eden ahady 318948106
#include "distances.h"
#include "KNN.h"
#include "knnClass.h"
#include "pair.h"
#include<iostream>
#include<vector>
#include <fstream>
#include<iostream>
#include<sstream>
#include <string>
#include <algorithm>
#include <stdio.h>
#include <map>


using namespace std;

KNN::KNN(string kStr, string disStr, string fileStr){};

bool KNN::checkK(string kStr) //check k input is a possitive int 
{
    for (int i=0; i<kStr.size(); i++)
    {
        if (kStr[i] == ' ' && (i != 0 && i != kStr.size() - 1)) //checks if theres a blank space
		{
			return false; 
		}
        for (int j = 0; j< kStr.size(); j++)
		{
			if (!isdigit(kStr[i])) //checks all characters are numbers
		 {
			return false;
		 }

		}
    }
    return true;
}

bool KNN::checkDis(string disStr) //checks that the name of distance is from list
{
    if(disStr == "AUC" || disStr == "MAN" || disStr == "CHB" || disStr == "CAN" || disStr == "MIN")
    {
        return true;
    } 
    return false;
}

vector< vector<string> > KNN::checkFile (string dataType, string fileStr, string dataSets) //checks that the file exists on computer
{
    vector<vector<string>> content;
    vector<string> row;
    string line, word;
    ifstream infile;
    string path =dataSets+"/"+dataType+"/"+fileStr; //creates path
    infile.open(path, ifstream::in); //opens file
    if(infile) 
    {
         while(getline(infile, line))
        {
            row.clear();
            stringstream str(line);
            while(getline(str, word, ','))
            {
                
                     row.push_back(word); //inserts into inner vector
                
            }
            content.push_back(row); //inserts into outer vector
        }
     } 
        infile.close();
        return content;
    else
    {
        cout<<"Could not open the file\n";
    }
    infile.close();
    vector<vector<string>> empty;
    return empty;
}

int main(int argc, char* argv[])
{   
    string str;
    string kStr = argv[1];
    string fileStr = argv[2];
    string disStr = argv[3];
    string word = "";
    KNN obj = KNN(kStr,disStr,fileStr);
    int numK;
    if (obj.checkK(kStr))
    {
        //if k is a number then cast to int
        istringstream(kStr) >>numK; 
    }
    else{
        exit(1);
    }

    if(!obj.checkDis(disStr))
    {
        exit(1); //exit if distance is not from list
    }
    string dataSets = "datasets";
    string dataType;
    if(fileStr.find("iris") != string::npos) //checks type of file
    {
        dataType = "iris";
    }
     if(fileStr.find("beans")!= string::npos)
    {
        dataType = "beans";
    }
     if(fileStr.find("wine")!= string::npos)
    {
        dataType = "wine";
    }
    vector<vector<string>> lines = obj.checkFile(dataType, fileStr, dataSets);
    string vec;
    string num;
    getline(cin, vec); //gets vector from user
    vector<string> v1;
    for (int i = 0; i < vec.size(); i++)
    {
        if (vec[i] == ' ' && (i != 0 && i != vec.size() - 1)) //check that there are no blank spaces before or after vector input
		{
			continue;
		}
        while(vec[i] != ' ' && i<vec.size()) //if not space
		{
			num.push_back(vec[i]);
			i++;
		}
		for (int j = 0; j< num.size(); j++)
		{
			if (!isdigit(num[j]) && num[j] != '.') //check that it is a number and not a letter or symbol
		 {
			exit(1);
		 }

		}
		v1.push_back(num);
        num = "";

    }
	for(int i=0; i<lines.size(); i++) //checks that the sizes of the vectors in the file are the same
    {
	    if (lines[1].size() != lines[i].size())
        {
             exit(1);
        }
    }
	if (v1.size() != lines[1].size()-1) //checks that the size of users vector is the same as file
	{
		exit(1);
	}
    vector<double> doublev1;
	doublev1.reserve(v1.size());
	transform(v1.begin(), v1.end(), back_inserter(doublev1),
		[](string const& val) {return stod(val); }); //casts string vector into double
    knnClass findK = knnClass(lines,doublev1, disStr,numK); //knnclass object
    vector<Pair> pairs = findK.calcDist(); //claculates the distance using the distance given
    pairs = findK.sortvec(pairs); //sorts the vector of pairs
    string s = findK.classification(pairs); //finds classification
    cout<<s;
}

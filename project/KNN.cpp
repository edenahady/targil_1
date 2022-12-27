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
    if(infile) {
        while (getline(infile, line)) {
            row.clear();
            stringstream str(line);
            while (getline(str, word, ',')) {

                row.push_back(word); //inserts into inner vector

            }
            content.push_back(row); //inserts into outer vector
        }

        infile.close();
        return content;
    }
    else
    {
        cout<<"Could not open the file\n";
    }
    infile.close();
    vector<vector<string>> empty;
    return empty;
}

string KNN::Check_Input(char buffer[], string file)
{
    char Vec_Arr[];
    string kStr;
    string fileStr;
    char disStr[];
    int man = fileStr.find("MAN") //checks type of file
    if (man >= 0) {
        strncpy(Vec_Arr, buffer, man)
        strncpy(disStr, buffer + man, buffer.size())
    }
    int auc = fileStr.find("AUC") //checks type of file
    if (auc >= 0) {
        strncpy(Vec_Arr, buffer, auc)
        strncpy(disStr, buffer + auc, buffer.size())
    }
    int chb = fileStr.find("CHB") //checks type of file
    else if (chb >= 0) {
        strncpy(Vec_Arr, buffer, chb)
        strncpy(disStr, buffer + chb, buffer.size())
    }
    int can = fileStr.find("CAN") //checks type of file
    else if (can >= 0) {
        strncpy(Vec_Arr, buffer, can)
        strncpy(disStr, buffer + can, buffer.size())
    }
    int min = fileStr.find("MIN") //checks type of file
    else if (min >= 0) {
        strncpy(Vec_Arr, buffer, min)
        strncpy(disStr, buffer + min, buffer.size())
    } else {
        return "invalid input";
    }
    string distance(disStr);
    string vecStr(Vec_Arr);
    int count = 0;
    istringstream iss(distance);
    while (s.find(' ') != string::npos)
    {
        getline(iss, kStr, ' ')
        count++;
    }
    if (count != 1)
    {
        return "invalid input";
    }
    KNN obj = KNN(kStr,disStr,file);
    int numK;
    if (obj.checkK(kStr))
    {
        //if k is a number than cast to int
        istringstream(kStr) >>numK; 
    }
    else{
        return "invalid input";
    }

    if(!obj.checkDis(disStr))
    {
        return "invalid input";
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
    string num;
    if (lines.empty())
    {
        return "invalid input";
    }
    vector<string> v1;
    for (int i = 0; i < vecStr.size(); i++) {
        if (vecStr[i] == ' ' &&
            (i != 0 && i != vecStr.size() - 1)) //check that there are no blank spaces before or after vector input
        {
            continue;
        }
        while (vecStr[i] != ' ' && i < vecStr.size()) //if not space
        {
            num.push_back(vecStr[i]);
            i++;
        }
        for (int j = 0; j < num.size(); j++) {
            if (!isdigit(num[j]) && num[j] != '.' && num[j] != 'e') //check that it is a number and not a letter or symbol
            {
                return "invalid input";
            }

        }
        v1.push_back(num);
        num = "";

    }
    for (int i = 0; i < lines.size(); i++) //checks that the sizes of the vectors in the file are the same
    {
        if (lines[1].size() != lines[i].size()) {
            return "invalid input";
        }
    }
    if (v1.size() != lines[1].size() - 1) //checks that the size of users vector is the same as file
    {
        return "invalid input";
    }
    vector<double> doublev1;
    doublev1.reserve(v1.size());
    transform(v1.begin(), v1.end(), back_inserter(doublev1),
              [](string const &val) { return stod(val); }); //casts string vector into double
    knnClass findK = knnClass(lines, doublev1, disStr, numK); //knnclass object
    vector<Pair> pairs = findK.calcDist(); //claculates the distance using the distance given
    pairs = findK.sortvec(pairs); //sorts the vector of pairs
    string s = findK.classification(pairs); //finds classification
    return s;
}

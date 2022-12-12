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
    string path ="../"+dataSets+"/"+dataType+"/"+fileStr;
    infile.open(path, ifstream::in);
    if(infile) 
    {
         while(getline(infile, line))
        {
            row.clear();
            stringstream str(line);
            while(getline(str, word, ','))
            {
                
                     row.push_back(word);
                
            }
            content.push_back(row);
        }
        for (int i=0; i<4; i++)
        {
            for (int j=0; j<5; j++)
            {
                cout<<content[i][j] << " ";
            }
            if(i==3)
            {
                cout<<endl;
            }
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

// vector< vector<string> > getFileContent(string fileName, vector<vector<string>> & vecOfLines)
// {
//     vector<string> row;
// string line, word;
 
// fstream file (fileName, ios::in);
// if(file.is_open())
// {
//     while(getline(file, line))
//     {
//         row.clear();
//         stringstream str(line);
//         while(getline(str, word, ','))
//         {
//             row.push_back(word);
//             vecOfLines.push_back(row);
//         }
        
//     }
// }
// else
// {
//     cout<<"Could not open the file\n";
// }
 
//  return vecOfLines;
// }


int main()
{   
    string str;
    string kStr;
    string fileStr;
    string disStr;
    string word = "";
    getline(cin, str); //get input from user
    int count = 0;
    KNN obj = KNN(kStr,disStr,fileStr);
    bool f = true;
    for (auto x : str)
    {
        if (x == ' ')
        {
            if(f == true) 
            {
                exit(1); //first character is blank space
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
		
		        case 3: //more than 2 blank spaces in input
			        exit(1);	
                }
                word = "";
            }
        }
        else 
        {
            word = word + x; //adds characters to word
            f = false;
        }
    }
    disStr = word;
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
    if(fileStr.find("iris") >=0)
    {
        dataType = "iris";
    }
     if(fileStr.find("beans")>= 0)
    {
        dataType = "beans";
    }
     if(fileStr.find("wine")>=0)
    {
        dataType = "wine";
    }
    vector<vector<string>> lines = obj.checkFile(dataType, fileStr, dataSets);
    // if(!checkFile(fileStr))
    // {
    //    cout << "file didn't open";
    //    exit(1);
       
    // }

    string vec;
    string num;
    getline(cin, vec);
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
	//for i<line.size-1{
	// if line[1].size != line[i].size){
	//print not same size + exit(1);}}
	if (v1.size() != line[1].size())
	{
		exit(1);
	}
    vector<double> doublev1;
	doublev1.reserve(v1.size());
	transform(v1.begin(), v1.end(), back_inserter(doublev1),
		[](string const& val) {return stod(val); });
    knnClass findK = knnClass(lines,doublev1, disStr,numK);
    vector<Pair> pairs = findK.calcDist();
    pairs = findK.sortvec(pairs);
    string s = findK.classification(pairs);
    cout<<s;
}

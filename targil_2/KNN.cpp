//lynn molga nagar 319090965
//eden ahady 318948106
#include<iostream>
#include<vector>
#include <fstream>
#include<iostream>
#include<sstream>
using namespace std;

bool checkK(string kStr) //check k input is a possitive int 
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

bool checkDis(string disStr) //checks that the name of distance is from list
{
    if(disStr == "AUC" || disStr == "MAN" || disStr == "CHB" || disStr == "CAN" || disStr == "MIN")
    {
        return true;
    } 
    return false;
}

bool checkFile (string fileStr) //checks that the file exists on computer
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
    getline(cin, str); //get input from user
    int count = 0;
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
    if (checkK(kStr))
    {
        istringstream(kStr) >>numK; //if k is a number then cast to int
    }
    else{
        exit(1);
    }

    if(!checkDis(disStr))
    {
        exit(1); //exit if distance is not from list
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
   

}

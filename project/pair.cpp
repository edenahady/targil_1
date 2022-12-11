#include "pair.h"
using namespace std;

Pair::Pair(double value1, int index1)
{
    value = value1;
    index = index1;
}
double Pair::getval()
{
    return value;
}
int Pair::getindex()
{
    return index;
}
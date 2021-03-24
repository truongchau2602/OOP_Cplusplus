#include<iostream>
#include<stdio.h>
using namespace std;
class BaseMath
{
public:
    bool isEvenNumber(int number)
    {
        if (number %2==0)
            return 1;
        else return 0;
    }
    int factorial(int n)
    {
        int fac=1;
        for(int i=1;i<=n;i++)
        {
            fac=fac*i;
        }
        return fac;
    }
};
class AdvancedMath: public BaseMath
{
public:
    float estimateEulerNumber(int loops)
    {
        float result=1.0;
        for (int i=1;i<=loops;i++)
        {
            result=result+(1.0/factorial(i));
        }
        return result;
    }
};
int main()
{
    AdvancedMath math;
    cout<<"factorial(5)="<<math.factorial(5)<<endl;
    cout<<"Euler(3)="<<math.estimateEulerNumber(3)<<endl;
}

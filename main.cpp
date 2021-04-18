// all the functions with very large numbers. both are stored in arrays.
#include <iostream>
#include <stdlib.h>
#include <string>
#include <vector>
#include <algorithm>
#include <math.h>
#include <time.h>
using namespace std;

vector <int> string_to_integer(string str) // CONVERTOR in reverse order
{
    int x=str.length();
    vector <int> arr;
    int index=0;
    while(x>0)
    {
        arr.push_back(str[x-1]-'0');
        x--;
    }
    return arr;  
    
}

vector <int> add(vector <int> a, vector <int> b) // SUM FUNCTION
{
    
    vector <int> result;
    int a_size=a.size(), b_size=b.size();
    if(a_size>b_size)
    {
        int i;
        int sum, carry=0;
        
        for(i=0;i<b_size;i++)
        {
            sum=carry+a.at(i)+b.at(i);
            result.push_back(sum%10);
            carry=sum/10;
        }
        for(i=b_size;i<a_size;i++)
        {
            sum=carry+a.at(i);
            result.push_back(sum%10);
            carry=sum/10;
        }
        if(carry==1)
            result.push_back(carry);
        return result;
        
    } // a>b over
    
    if(b_size>a_size)
    {
        int i;
        int sum, carry=0;
        
        for(i=0;i<a_size;i++)
        {
            sum=carry+a.at(i)+b.at(i);
            result.push_back(sum%10);
            carry=sum/10;
        }
        for(i=a_size;i<b_size;i++)
        {
            sum=carry+b.at(i);
            result.push_back(sum%10);
            carry=sum/10;
        }
        if(carry==1)
            result.push_back(carry);
        return result;
        
    } // b over
    
    else
    {
        int i;
        int sum, carry=0;
        for(i=0;i<a_size;i++)
        {
            sum=carry+a.at(i)+b.at(i);
            result.push_back(sum%10);
            carry=sum/10;
        }
        if(carry==1)
            result.push_back(carry);
        return result;
    }
    
}

vector <int> subtract(vector <int> a, vector <int> b) //DIFFERENCE FUNCTION First number greater than the other.
{
    vector <int> result;
    int a_size=a.size(), b_size=b.size();
    int i;
    for(i=0;i<b_size;i++)
    {
        
            if(a.at(i)>b.at(i))
                result.push_back(a.at(i)-b.at(i));
            else
            {
                result.push_back(10+a.at(i)-b.at(i));
                a.at(i+1)=a.at(i+1)-1;
            }
        
        
        
    }
    return result;
    
}


int modulus(vector <int> a, int n) // A given array mod the given number
{
    vector <int> result;
    int mod=0;
    for(int i=a.size()-1;i>=0;i--)
    {
        mod=(mod*10+a.at(i)-'0')%n;
    }
    return mod;
}

int main()
{
    string str1;string str2;
    cin>>str1>>str2;
    vector <int> a=string_to_integer(str1);
    vector <int> b=string_to_integer(str2);
    for(int i=a.size()-1;i>=0;i--)
    {
        cout<<a.at(i);
    }
    cout<<endl;
    for(int i=b.size()-1;i>=0;i--)
    {
        cout<<b.at(i);
    }
    cout<<endl;
    vector <int> sum=add(a,b);
    for(int i=sum.size()-1;i>=0;i--)
    {
        cout<<sum.at(i);
    }
    cout<<endl;
    vector <int> dif=subtract(a,b);
    for(int i=dif.size()-1;i>=0;i--)
    {
        cout<<dif.at(i);
    }
    return 0;
}
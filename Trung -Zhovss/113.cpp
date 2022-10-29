#include <iostream>
#include <unordered_map>
#include <algorithm>
using namespace std;
 
void SortArray(int FirstArray[], int SecondArray[], int m, int n)
{   
    int ThirdArray[100];
    unordered_map<int, int> frequence;
    int k = 0;
    for(int i = 0; i < m; i++)
    {
        frequence[FirstArray[i]]++;
    }
    for(int i = 0; i<n; i++)
    {
        while(frequence[SecondArray[i]]!=0)
        {
            ThirdArray[k] = SecondArray[i];
            frequence[SecondArray[i]]--;
            k++;
        }
        for(int j = 0; j<m; j++)
        {
            if(FirstArray[j]==SecondArray[i])
            {
                for(int h = j; h<m-1; h++)
                {
                    FirstArray[h] = FirstArray[h+1];
                }
                m--;
                j--;
            }
        }
    }
    sort(FirstArray,FirstArray+m);
    for(int i = 0; i<k; i++)
    {
        cout<<ThirdArray[i]<<" ";
    }
    for(int i = 0; i<=m; i++)
    {
        cout<<FirstArray[i]<<" ";
    }
}   
int main()
{
    int FirstArray[] = { 1,2,5,1,5,1,2,3,4,6 };
    int SecondArray[] = { 3,5,2 };
 
    int m = sizeof(FirstArray) / sizeof(FirstArray[0]);
    int n = sizeof(SecondArray) / sizeof(SecondArray[0]);
    SortArray(FirstArray,SecondArray,m,n);
    return 0;
} 
    


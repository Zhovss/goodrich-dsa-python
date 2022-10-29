#include <iostream>
#include <unordered_map>
#include <algorithm>
using namespace std;
typedef struct 
{
    int List[5];
}SortedList;
void MergeList(int m, SortedList Array[])
{
    int ArrayRef[m*5];
    int index = 0;
    for(int i = 0; i<m; i++)
    {
        for(int j = 0; j<5; j++)
        {
            cin>>Array[i].List[j];
            Array[i].List[j] = ArrayRef[index];
            index++;
        }
    }
    sort(ArrayRef, ArrayRef + m*5);
    for(int i = 0; i<m*5; i++)
    {
        cout<<ArrayRef[i]<<" ";
    }
}
int main()
{
    int m = 4;
    SortedList Array[m];
    return 0;
}

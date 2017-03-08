#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
   int width = 0;
    cin >> width;
   int testCases = 0;
    cin >> testCases;
   int theWidth[width];
    for (int i =0 ; i < width; i++)
       {
       int input =0;
       cin >> input;
       theWidth[i] = input;
   }
    int vehicle[3]= {1,2,3};
    int startPoint = 0;
    int endPoint = 0;
    int result[testCases];
    int index =0;
    for (int j =0; j < testCases; j++)
        {
        cin >> startPoint;
        cin >> endPoint;
        for (int first = startPoint; first <= endPoint; first++)
            {
            int howBig = theWidth[first];
            if (howBig == 1 )
                {
                result[index]= 1;
                index++;
                for (int i = 1; i<=3; i++)
                {
                    vehicle[i-1]=1;
                }
                break;
            }
            else
                {
                if (howBig == 2)
                    {
                    // Not possible to put a truck in there;
                    vehicle[2] = 0;
                    }
                }
           
            }
          
        
        int max = 1;
            for (int k = 0; k < 3; k++)
                {
                if (max < vehicle[k])
                    {
                    max = vehicle[k];
                }
            }
     result[index]= max;
            index++; 
            for (int i = 1; i<=3; i++)
                {
                vehicle[i-1]=1;
            }
    
    }
    index =0;
    for (index; index< testCases; index++)
        {
        cout << result[index];
        cout << endl;
    }
    return 1;
    
   
}
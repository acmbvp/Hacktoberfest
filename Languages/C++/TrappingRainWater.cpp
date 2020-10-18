/*Complexity Analysis: 
Time Complexity: O(n). 
As only one traversal of the array is needed.
Auxiliary Space: O(1). 
As no extra space is required.*/




#include<iostream> 
using namespace std; 
 
int maxWater(int arr[], int n) 
{ 
    int size = n - 1; 
  
    
    int prev = arr[0]; 
 
    int prev_index = 0; 
    int water = 0; 
  
 
    int temp = 0; 
    for(int i = 1; i <= size; i++) 
    { 
  
    
        if (arr[i] >= prev)  
        { 
            prev = arr[i]; 
            prev_index = i; 
  
          
            temp = 0; 
        }  
        else
        { 
              
           
            water += prev - arr[i]; 
  
           
            temp += prev - arr[i]; 
        } 
    } 
  

    if(prev_index < size)  
    { 
  
     
        water -= temp; 
  
        
        prev = arr[size]; 
  
      
        for(int i = size; i >= prev_index; i--)  
        { 
  
            
            if(arr[i] >= prev) 
            { 
                prev = arr[i]; 
            }  
            else
            { 
                water += prev - arr[i]; 
            } 
        } 
    }
    return water; 
} 
  

int main() 
{ 
    int arr[] = { 0, 1, 0, 2, 1, 0,  
                  1, 3, 2, 1, 2, 1 };  
    int n = sizeof(arr) / sizeof(arr[0]); 
  
    cout << maxWater(arr, n); 
    return 0; 
} 
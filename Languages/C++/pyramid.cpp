#include <iostream> 
using namespace std; 
  
// Function to demonstrate printing pattern 
void pypart(int n) 
{ 
    // outer loop to handle number of rows 
    //  n in this case 
    for (int i=0; i<n; i++) 
    { 
        //  inner loop to handle number of columns 
        //  values changing acc. to outer loop 
        for(int j=0; j<=i; j++ ) 
        { 
            // printing stars 
            cout << "* "; 
        } 
  
        // ending line after each row 
        cout << endl; 
    } 
} 
  
// Driver Function 
int main() 
{ 
    int n = 5; 
    pypart(n); 
    return 0; 
} 

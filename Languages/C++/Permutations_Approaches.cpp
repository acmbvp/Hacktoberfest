// Permutations_Approaches.cpp : Defines the entry point for the console application.
//


#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;


/* 
Problem: Given a collection of distinct integers, return all possible permutations.
Order of output doesn't matter.

Input [1,2,3]
Output:{[1,2,3],[1,3,2],[2,1,3],[2,3,1],[3,1,2],[3,2,1]}

This approach could also be used to finding next higher numbers with same set of digits.
This works with or without duplicates!.
Steps:

1. First find the smallest number possible with same set of digits(sort the number and if there are any leading zeros     then swap 1st leading zero with 1st Non zero digit starting from left i.e. 001789 so 100789 this is smallest     
   possible number).
2. Now keep finding the next higher number using same set of digits i.e.
3. Find a digit which is smaller  than the digit in next index starting from right.
4. Swap with last digit.(if we don't find any such digit just swap the last 2 digits).
5.  sort all the digits in the right of this digit(which is smaller than the digit in right index or 2nd last).
*/

vector<vector<int>>Permute_Approach1(vector<int>& nums) {

    vector<vector<int>> result;
	sort(nums.begin(), nums.end()); 
	int len = nums.size();
	int i = 0, j = 0;
	while(1){
	result.push_back(nums);
	i = len -2, j = len -1;
	while(i> 0 && nums[i] >= nums[i+1]) i--;
	while(j > 0 && nums[i] >= nums[j]) j--;
	if(j == 0) break;
	swap(nums[i], nums[j]);
	i++;
	j = len-1;
    while(i < j){
		swap(nums[i], nums[j]);
		i++;
		j--;
	  }
	}
	return result;
}

/*Approach 2: 
	This approach is based on BFS and this is generic way of solving multiple similar Problems. The approach above         is very specific to the problem type. This is the approach described in Grokking coding interviews.  

	Following a BFS approach, we will consider one number at a time: 
	1. If the given set is empty then we have only an empty permutation set: []
	2. Let’s add the first element (1), the permutations will be: [1]
	3. Let’s add the second element (3), the permutations will be: [3,1], [1,3]
	4. Let’s add the third element (5), the permutations will be: [5,3,1], [3,5,1], [3,1,5], [5,1,3], [1,5,3], [1,3,5]

	Let’s analyze the permutations in the 3rd and 4th step. How can we generate permutations in the 4th step from the permutations of the 3rd step?

	If we look closely, we will realize that when we add a new number (5), we take each permutation of the previous step and insert the new number in every position to generate the new permutations. For example, inserting ‘5’ in different positions of [3,1] will give us the following permutations:

	- Inserting ‘5’ before ‘3’: [5,3,1]
	- Inserting ‘5’ between ‘3’ and ‘1’: [3,5,1]
	- Inserting ‘5’ after ‘1’: [3,1,5]


*/


vector<vector<int>> Permute_Approach2(vector<int>& nums) {
        
        vector<vector<int>> result;
        queue<vector<int>> permutations;
        permutations.push(vector<int>());
        
        for(int i = 0; i<nums.size(); i++){
        
            int n = permutations.size();
            
            for(int j = 0; j<n; j++){
            
                vector<int> oldPermutations = permutations.front();
                permutations.pop();
                
                for(int k = 0; k<=oldPermutations.size(); k++){

                    vector<int> newPermutations(oldPermutations);
                    newPermutations.insert(newPermutations.begin() + k, nums[i]); //it doesn't overwrite, it creates new memory and does shifting of elements similar to erasing elements.
                    if(newPermutations.size() == nums.size())
                        result.push_back(newPermutations);
                    else
                        permutations.push(newPermutations);
                    
                }
            }
        }
        
     return result;
}

int main()
{
	int size = 0, digits = 0;
	vector<int> input;
	cout<<"Please Enter Input Size: "<<endl;
	cin>>size;
	cout<<"Please Enter Numbers: ";
	for(int i = 0; i<size; i++){
		cin>>digits;
		input.push_back(digits);
	}

	vector<vector<int>> result = Permute_Approach2(input);

	for(int i = 0; i<result.size(); i++){
		for(int j = 0; j<result[i].size(); j++){
			cout<<result[i][j]<<" ";
		}
		cout<<endl;
	}
	return 0;
}


//this was my first technical interview question (I completely bombed it) and later my first real struggle on Leetcode. It is near and dear to my heart. 

//Given a target and an array of integers, return the indices of the two integers that add together to reach the target
//Example: 
// t = 10
// arr = [1,2,4,9]
// function twoSum(t, arr) ---> should return ---> [0,3]

function twoSum(t, arr){
    //first, create an empty object that we can use as a map to plot out the integer and the index at which it exists in the array
    let obj = {};
    //set up a for loop 
    for(let i = 0; i < arr.length; i++){
        //establish a variable for the difference between the target number and each number in the array
        let diff = t - arr[i];
        //establish a variable for each number in the array
        let number = arr[i];
        //set up a conditional that asks: does the diff exist in the obj?
        //if it doesn't, go ahead and make it exist in the object and set the key equal to the integer and the value equal to the index
        if(!(diff in obj)){
            obj[number] = i;
        }
        //if it does exist, return an array that is the object value at the entry where the diff exists (the index associated with the key), and the index
        else {
            return [obj[diff], i];
        }
    }
    return [];
    //don't forget to return something if there's no match
};

twoSum(10, [1,2,4,9])


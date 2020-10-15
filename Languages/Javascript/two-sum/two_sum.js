/**
 *
 * Given an array of integers nums and an integer target, return indices of the two numbers such that they add up to target.
 *
 *  You may assume that each input would have exactly one solution, and you may not use the same element twice.
 *
 *   You can return the answer in any order.
 */

var twoSum = function(nums, target) {
    var result = [];
    var hashTable = {};
      for(i = 0; i < nums.length; i++) {
          let diff = target  - nums[i];
          if((hashTable[diff.toString()]) !== undefined) {
              // console.log(nums[i], diff)
              result.push(i, hashTable[diff.toString()]);
          }
          hashTable[nums[i]] = i;
      }
      
      return result;
  
};
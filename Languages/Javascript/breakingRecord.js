// LANGUAGE: Javascript
// ENV: Node.js
// AUTHOR: Tek Loon 
// GITHUB: https://github.com/tlcheah2
// to run it: node breakingRecord.js

/**
 * Accepting Array of Scores and Calculate How many times they breaking the records either highest or lowest
 * @param {Array} scores 
 */
const breakingRecords = (scores) => {
    let countForBreakingMaximum = 0;
    let countForBreakingMinimum = 0;
    // Set maximum and minimum to null
    let minimum = null;
    let maximum = null;
    for(let i = 0; i < scores.length; i++) {
        const currentScore = scores[i];
        // Skip the first time and set the minimum and maximum score
        if(minimum == null && maximum == null) {
            minimum = currentScore;
            maximum = currentScore;
            continue;
        }
        // If score is higher than maximum, it means break the maximum record
        if(currentScore > maximum) {
            maximum = currentScore;
            countForBreakingMaximum++;
        } 
        // If score is lesser than minimum, it means break the minimum record
        else if(currentScore < minimum) {
            minimum = currentScore;
            countForBreakingMinimum++;
        }
    }
    return [countForBreakingMaximum, countForBreakingMinimum];
}

const result = breakingRecords([100, 120, 90, 50, 100, 80, 130]);
// 2 times it break the maximum record, from 100 to 120, and to 130
// From 100 to 120
// From 120 to 130
console.log('Breaking Maximum Record Count: ' + result[0]);
// 2 times it break the minimum record, from 100 to 120, and to 130
// From 100 to 90
// From 90 to 50,  
console.log('Breaking Minimum Record Count: ' + result[1]);
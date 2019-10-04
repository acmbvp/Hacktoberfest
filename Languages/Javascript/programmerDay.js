// LANGUAGE: Javascript
// ENV: Node.js
// AUTHOR: Tek Loon 
// GITHUB: https://github.com/tlcheah2
// to run it: node programmerDay.js

const dayOfProgrammer = (year) => {
    const numOfDay = [31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31]; 
    const isJulian = year < 1918;
    const programmerDay = 256;
    let count = 0;
    let index = 0;

    // Leap Year Calculation
    let isLeapYear;
    if(isJulian) {
        // Julian Calendar Leap Year Logic
        isLeapYear = year % 4 === 0;
    } else {
        // Gregorian Calendar Leap Year Logic
        isLeapYear = (year % 400 === 0) || (year % 4 === 0 && year % 100 !== 0);
    } 

    // Calculate the number of day for February
    if(year === 1918) {
        const numOfDayInFeb = isLeapYear ? 29 - 14 + 1 : 28 -14 + 1;
        numOfDay[1] = numOfDayInFeb;
    } else {
        

        if(isLeapYear) {
            numOfDay[1] = 29;
        } else {
            numOfDay[1] = 28;
        }
    }

    // If the remaining days to programmer day less than the number of day of the month
    // Stop the loop.
    while (programmerDay - count > numOfDay[index]) {
        count += numOfDay[index];
        index++;
    }
    // Calculate the day
    let day = programmerDay - count;
    // Calculate the month 
    let month = index + 1;

    // Format day, add 0 to front if string length equal to 1
    if(day.toString().length === 1) {
        day = '0' + day;
    }
    // Format month, add 0 to front if string length equal to 1
    if(month.toString().length === 1) {
        month = '0' + month;
    }
    return `${day}.${month}.${year}`;
}

console.log('Programmer Day For 1918: ' + dayOfProgrammer(1918));
console.log('Programmer Day For 2019: ' + dayOfProgrammer(2019));
console.log('Programmer Day For 2100: ' + dayOfProgrammer(2100));
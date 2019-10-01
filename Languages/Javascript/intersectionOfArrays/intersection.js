const arrayOfNumbers1 = new Set([4, 5, 6, 1, 9, 11]);
const arrayOfNumbers2 = new Set([2, 5, 11, 1, 0, 4]);

let intersect = (array1, array2) => {
    return [...array1].filter(element => array2.has(element));
};

let resultOfIntersection = intersect(arrayOfNumbers1, arrayOfNumbers2);

console.log(resultOfIntersection);


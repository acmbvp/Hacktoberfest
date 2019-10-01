// LANGUAGE: Javascript
// ENV: Node.js
// AUTHOR: Natalia C
// GITHUB: https://github.com/Natalia504
// to run it: node longestWord.js

const longestWord = str => {
  let splitStr = str.split(" ");
  var longest = 1;
  var result;

  splitStr.map(word => {
    word.length > longest ? (longest = word.length) : (result = word);
  });
  return result;
};

console.log(longestWord("I love ice-cream foreverandever"));

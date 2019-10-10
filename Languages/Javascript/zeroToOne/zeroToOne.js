// Using a single line code to convert 0 to 1 and 1 to 0

let binaryArray = [0, 1, 1, 0, 1];

binaryArray.forEach(function(element) {
  element = 1 - element;
  console.log(element); // Output: 1, 0, 0, 1, 0
});

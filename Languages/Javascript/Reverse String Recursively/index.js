// LANGUAGE: Javascript
// ENV: Node.js
// AUTHOR: Aayushi Shah
// GITHUB:@aayushah711

function runProgram() {
    input = 'Aayushi';
    console.log(recursion(0));
    function recursion(index) {
        if (index >= input.length) {
            return '';
        }
        return recursion(index + 1) + input[index];
    }
}

runProgram();

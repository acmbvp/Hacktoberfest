//A simple way to compose functions!

const compose = (...fns) => x =>
    fns.reduceRight((acc, fn) => fn(acc), x)

//Usage example
const exclaim = str => `${ str }!`
const upperCase = str => str.toUpperCase()

const scream = compose(exclaim, upperCase)('Very nice!')
console.log(scream) // "VERY NICE!!"

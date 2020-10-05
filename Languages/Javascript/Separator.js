// LANGUAGE: Javascript
// AUTHOR: Mustaqiem
// GITHUB: https://github.com/Mustaqiem
// to run it: js Separator.js

const Separator = (value) => {
    let number = value.toString()
    let sisa = number.length % 3
    let rupiah = number.substr(0, sisa)
    let ribuan = number.substr(sisa).match(/\d{3}/g)

    if (ribuan) {
        let separator = sisa ? '.' : ''
        rupiah += separator + ribuan.join('.')
    }
    return rupiah
}

console.log(Separator(12090000))
// 12.090.000

function checkEmail(email) {
    // let regex = /^\w+([\.-]?\w+)*@\w+([\.-]?\w+)*(\.\w{2,3})+$/;
    // let regex =  /^[a-zA-Z0-9.!#$%&'*+/=?^_`{|}~-]+@[a-zA-Z0-9-]+(?:\.[a-zA-Z0-9-]+)*$/;
    // let regex =   /^(([^<>()\[\]\\.,;:\s@"]+(\.[^<>()\[\]\\.,;:\s@"]+)*)|(".+"))@((\[[0-9]{1,3}\.[0-9]{1,3}\.[0-9]{1,3}\.[0-9]{1,3}\])|(([a-zA-Z\-0-9]+\.)+[a-zA-Z]{2,}))$/;
    let regex =  /^[^ ]+@[^ ]+\.[a-z]{2,3}$/;
    // let regex =  /^([a-zA-Z0-9_\.\-])*\@(([a-zA-Z0-9\-])+\.)+([a-zA-Z0-9]{2,4})+$/;
    // !!x || x === ''
    if (typeof(email) != 'undefined') {
        if (typeof(email) == 'string') {
            if (email.match(regex)) {
                return 'VALID'
            }else{
                let regex2 = new RegExp('[a-z0-9]+@test');
                if (regex2.test(email)) {
                    return "INVALID"
                }else{
                    return "Error : Alamat email tidak sesuai"
                }
            }
        }else{
                return "Error : Invalid data type"
        }
    }else{
        return "Error : Bro where is the parameter ? "
    }
 
}
console.log(checkEmail('apranata@test.co.id'));
console.log(checkEmail('apranata@test.com'));
console.log(checkEmail('apranata@test'));
console.log(checkEmail('apranata'));
console.log(checkTypeNumber(checkEmail(3322)));
console.log(checkEmail());
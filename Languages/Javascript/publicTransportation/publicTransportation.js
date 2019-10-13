// add passenger in public transportation

let passenger = [];

function addPassenger(passengerName, passenger) {
    if(passenger.length == 0) {
        passenger.push(passengerName);
        return passenger;
    }
    else {
        for(let i = 0; i<passenger.length; i++) {
            if(passenger[i] == undefined) {
                passenger[i] = passengerName;
                return passenger;
            }
            else if(passenger[i] == passengerName) {
                console.log(`passenger by name ${passengerName} already exists`);
                return passenger;
            }
            else if(i == passenger.length -1) {
                passenger.push(passengerName);
                return passenger;
            }
        }
    }
};
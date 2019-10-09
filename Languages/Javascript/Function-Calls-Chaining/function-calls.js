// Objective: To make the calls variable equal to 'JerryKramerGeorgeElaine' with only a single invocation to the function jerry

let calls = "";

function jerry(str) {
  calls += "Jerry";
  kramer();
}

function george(str) {
  calls += "George";
  elaine();
}

function elaine(str) {
  calls += "Elaine";
}

function kramer(str) {
  calls += "Kramer";
  george();
}

jerry();
console.log(calls); // should log: 'JerryKramerGeorgeElaine'

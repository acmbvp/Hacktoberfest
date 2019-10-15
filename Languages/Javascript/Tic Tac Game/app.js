//  get div from index.html
var mainDiv = document.getElementById("mainDiv");



// heading
var h1 = document.createElement("h1");
h1.setAttribute("class", "heading");
var h1Text = document.createTextNode("Tic tac Game")



// palyer tracking
var playerDiv = document.createElement("span");
playerDiv.setAttribute("class", "player");
playerDiv.setAttribute("id", "player");
var playerText = document.createTextNode("Start Game");
playerDiv.setAttribute("style", "color:#33b5e5")




// sub div
var subDiv = document.createElement("div");
subDiv.setAttribute("class", "subDiv");
subDiv.setAttribute("id", "subDiv");

// box1
var box1 = document.createElement("div");
box1.setAttribute("class", "box1");
box1.setAttribute("id", "box1");
box1.setAttribute("onClick", "getUser1()")

// box2
var box2 = document.createElement("div");
box2.setAttribute("class", "box2");
box2.setAttribute("id", "box2");

// box3
var box3 = document.createElement("div");
box3.setAttribute("class", "box3");
box3.setAttribute("id", "box3");

// box4
var box4 = document.createElement("div");
box4.setAttribute("class", "box4");
box4.setAttribute("id", "box4");

// box5
var box5 = document.createElement("div");
box5.setAttribute("class", "box5");
box5.setAttribute("id", "box5");

// box6
var box6 = document.createElement("div");
box6.setAttribute("class", "box6");
box6.setAttribute("id", "box6");

// box7
var box7 = document.createElement("div");
box7.setAttribute("class", "box7");
box7.setAttribute("id", "box7");

// box8
var box8 = document.createElement("div");
box8.setAttribute("class", "box8");
box8.setAttribute("id", "box8");

// box9
var box9 = document.createElement("div");
box9.setAttribute("class", "box9");
box9.setAttribute("id", "box9");



// reply btn fontawesome
var fontAwesome = document.createElement("i");
fontAwesome.setAttribute("style", "padding-right: 4px");
fontAwesome.setAttribute("class", "fas fa-undo");

// replay btn
var btn = document.createElement("button");
var btnText = document.createTextNode("REPLAY");
btn.setAttribute("onClick", "replay()")
btn.setAttribute("class", "btn btn-outline-success btn-lg btn-block")
btn.appendChild(fontAwesome);
btn.appendChild(btnText);



// append child
h1.appendChild(h1Text)
mainDiv.appendChild(h1);

playerDiv.appendChild(playerText);
mainDiv.appendChild(playerDiv);

subDiv.appendChild(box1);
subDiv.appendChild(box2);
subDiv.appendChild(box3);

subDiv.appendChild(box4);
subDiv.appendChild(box5);
subDiv.appendChild(box6);

subDiv.appendChild(box7);
subDiv.appendChild(box8);
subDiv.appendChild(box9);
subDiv.appendChild(btn);

mainDiv.appendChild(subDiv);



// ------------------------------ var initialize ------------------------------------- 
var user1;
var x_or_o = 0;
var temp = 0;
var flag = false;
var tracking = document.getElementById("player");




// ************************************* onLoad Function get player name ***************************************
function onLoad() {
    swal({
        title: "Start Game",
        icon: "./image/logo.png",
        text: "1st Player Please Select X or O...",
        content: "input",
        button: {
            text: "Selected",
            closeModal: true,
        }
    })
    .then((value) => {
            if (value.toLowerCase() !== 'x' && value.toLowerCase() !== "o") {
                swal({
                    title: "Ooh noes, you Selected Wrong name!",
                    text: "You are only allowed to Select 'X' or 'O' name",
                    icon: "./image/oh no.png",
                    button: {
                        text: "Try again!",
                        closeModal: true,
                    }
                })
                    .then(() => {
                        location = './index.html'
                    });
            } else if (value === 'x' || value === "X") {
                swal({
                    title: "You Selected X!",
                    text: "Second User is O!",
                    icon: "./image/x.png",
                    button: "Play Now!",
                });
                user1 = value.toUpperCase();
                return user1;
            } else if (value === 'o' || value === "O") {
                swal({
                    title: "You Selected O!",
                    text: "Second User is X!",
                    icon: "./image/o.png",
                    button: "Play Now!",
                });
                user1 = value.toUpperCase();
                return user1;
            }
        }).catch(function (error) {
            swal({
                title: "Bad Habit !!!",
                text: "You are not allowed to play Until you fill input Field...",
                icon: "./image/angry.png",
            })
            .then(function (){
                onLoad();
            })
            
        })
}
// ********************************** end of onLoad() function *********************************************




// get all boxes
var boxes = document.querySelectorAll("#subDiv div");




// ************************* onclick function input values in divs ********************************************
for(var i = 0; i < boxes.length; i++) {
    boxes[i].onclick = function() {
        if(user1 === "X") {
            if(this.innerHTML !== "X" && this.innerHTML !== "O") {
                if(x_or_o%2 === 0) {
                    this.innerHTML = "X";
                    this.style.color = "dodgerblue";
                    tracking.innerHTML = "<span style='color:#ff4444'>O Turn Now</span>";
                    winner();
                    x_or_o += 1;
                }
                else{
                    this.innerHTML = "O";
                    this.style.color = "#ff4444";
                    tracking.innerHTML = "<span style='color:dodgerblue'>X Turn Now</span>";
                    winner();
                    x_or_o += 1;
                }
                console.log(temp++);
            }
        }
        if(user1 === "O") {
            if(this.innerHTML !== "X" && this.innerHTML !== "O") {
                if(x_or_o%2 === 0) {
                    this.innerHTML = "O";
                    this.style.color = "#ff4444";
                    tracking.innerHTML = "<span style='color:dodgerblue'>X Turn Now</span>";
                    winner();
                    x_or_o += 1;
                }
                else{
                    this.innerHTML = "X";
                    this.style.color = "dodgerblue";
                    tracking.innerHTML = "<span style='color:#ff4444'>O Turn Now</span>";
                    winner();
                    x_or_o += 1;
                }
                console.log(temp++);
            }
        }
    }    
}
// **************************** onClick function() end ****************************************




// ********************************* possibilities to check winner **************************************
function winner() {
    var box1 = document.getElementById("box1"),
        box2 = document.getElementById("box2"),
        box3 = document.getElementById("box3"),
        box4 = document.getElementById("box4"),
        box5 = document.getElementById("box5"),
        box6 = document.getElementById("box6"),
        box7 = document.getElementById("box7"),
        box8 = document.getElementById("box8"),
        box9 = document.getElementById("box9");

        if(box1.innerHTML !== "" && box1.innerHTML === box2.innerHTML && box2.innerHTML === box3.innerHTML && box1.innerHTML === box3.innerHTML) {
            winnerBox(box1, box2, box3);
            flag = true;
            swal({
                title: box1.innerHTML + " won",
                icon: "./image/winner.png",
                text: "Congratulation " +box1.innerHTML+ " you have Won the Match...",
                buttons: ["cancel", "try again"]
            })
                .then((load) => {
                    if(load) {
                    location = './index.html'
            }
            else{
                swal({
                    title: "It was a nice to have you here",
                    text: "Please come Soon I'll be waiting bye",
                    icon : "./image/bye.png",
                })
            }
        })
        }

        if(box4.innerHTML !== "" && box4.innerHTML === box5.innerHTML && box5.innerHTML === box6.innerHTML && box4.innerHTML === box6.innerHTML) {
            winnerBox(box4, box5, box6);
            flag = true;
            swal({
                title: box4.innerHTML + " won",
                icon: "./image/winner.png",
                text: "Congratulation " +box4.innerHTML+ " you have Won the Match...",
                buttons: ["cancel", "try again"]
            })
                .then((load) => {
                    if(load) {
                    location = './index.html'
            }
            else{
                swal({
                    title: "It was a nice to have you here",
                    text: "Please come Soon I'll be waiting bye",
                    icon : "./image/bye.png",
                })
            }
        })
        }

        if(box7.innerHTML !== "" && box7.innerHTML === box8.innerHTML && box8.innerHTML === box9.innerHTML && box7.innerHTML === box9.innerHTML) {
            winnerBox(box7, box8, box9);
            flag = true;
            swal({
                title: box7.innerHTML + " won",
                icon: "./image/winner.png",
                text: "Congratulation " +box7.innerHTML+ " you have Won the Match...",
                buttons: ["cancel", "try again"]
            })
                .then((load) => {
                    if(load) {
                    location = './index.html'
            }
            else{
                swal({
                    title: "It was a nice to have you here",
                    text: "Please come Soon I'll be waiting bye",
                    icon : "./image/bye.png",
                })
            }
        })
        }

        if(box1.innerHTML !== "" && box1.innerHTML === box4.innerHTML && box4.innerHTML === box7.innerHTML && box1.innerHTML === box7.innerHTML) {
            winnerBox(box1, box4, box7);
            flag = true;
            swal({
                title: box1.innerHTML + " won",
                icon: "./image/winner.png",
                text: "Congratulation " +box1.innerHTML+ " you have Won the Match...",
                buttons: ["cancel", "try again"]
            })
                .then((load) => {
                    if(load) {
                    location = './index.html'
            }
            else{
                swal({
                    title: "It was a nice to have you here",
                    text: "Please come Soon I'll be waiting bye",
                    icon : "./image/bye.png",
                })
            }
        })
        }

        if(box2.innerHTML !== "" && box2.innerHTML === box5.innerHTML && box5.innerHTML === box8.innerHTML && box2.innerHTML === box8.innerHTML) {
            winnerBox(box2, box5, box8);
            flag = true;
            swal({
                title: box2.innerHTML + " won",
                icon: "./image/winner.png",
                text: "Congratulation " +box2.innerHTML+ " you have Won the Match...",
                buttons: ["cancel", "try again"]
            })
                .then((load) => {
                    if(load) {
                    location = './index.html'
            }
            else{
                swal({
                    title: "It was a nice to have you here",
                    text: "Please come Soon I'll be waiting bye",
                    icon : "./image/bye.png",
                })
            }
        })
        }

        if(box3.innerHTML !== "" && box3.innerHTML === box6.innerHTML && box6.innerHTML === box9.innerHTML && box3.innerHTML === box9.innerHTML) {
            winnerBox(box3, box6, box9);
            flag = true;
            swal({
                title: box3.innerHTML + " won",
                icon: "./image/winner.png",
                text: "Congratulation " +box3.innerHTML+ " you have Won the Match...",
                buttons: ["cancel", "try again"]
            })
                .then((load) => {
                    if(load) {
                    location = './index.html'
            }
            else{
                swal({
                    title: "It was a nice to have you here",
                    text: "Please come Soon I'll be waiting bye",
                    icon : "./image/bye.png",
                })
            }
        })
        }

        if(box1.innerHTML !== "" && box1.innerHTML === box5.innerHTML && box5.innerHTML === box9.innerHTML && box1.innerHTML === box9.innerHTML) {
            winnerBox(box1, box5, box9);
            flag = true;
            swal({
                title: box1.innerHTML + " won",
                icon: "./image/winner.png",
                text: "Congratulation " +box1.innerHTML+ " you have Won the Match...",
                buttons: ["cancel", "try again"]
            })
                .then((load) => {
                    if(load) {
                    location = './index.html'
            }
            else{
                swal({
                    title: "It was a nice to have you here",
                    text: "Please come Soon I'll be waiting bye",
                    icon : "./image/bye.png",
                })
            }
        })
        }

        if(box3.innerHTML !== "" && box3.innerHTML === box5.innerHTML && box5.innerHTML === box7.innerHTML && box3.innerHTML === box7.innerHTML) {
            winnerBox(box3, box5, box7);
            flag = true;
            swal({
                title: box3.innerHTML + " won",
                icon: "./image/winner.png",
                text: "Congratulation " +box3.innerHTML+ " you have Won the Match...",
                buttons: ["cancel", "try again"]
            })
                .then((load) => {
                    if(load) {
                    location = './index.html'
            }
            else{
                swal({
                    title: "It was a nice to have you here",
                    text: "Please come Soon I'll be waiting bye",
                    icon : "./image/bye.png",
                })
            }
        })
        }

        if(temp === 8 && flag == false) {
            tracking.innerHTML = "Match Tie";
            swal({
                title: "Match tie!!!",
                text: "Oh no Match is tie",
                icon: "error",
                buttons: ["cancel", "Reload"]
            })
            .then((again) => {
                if(again) {    
                location = './index.html'
            }
            else{
                swal({
                    title: "OKH! , So you Don't want to play...",
                    icon : "./image/ok.png"           
                })
            }
            });
    }

}
// *************************** possibilities function() end ********************************************



// **************************************** select winner box ***************************************
function winnerBox(box1, box2, box3) {
    box1.style.backgroundColor = "#007E33";
    box2.style.backgroundColor = "#007E33";
    box3.style.backgroundColor = "#007E33";
    box1.style.color = "white";
    box2.style.color = "white";
    box3.style.color = "white";
    box1.style.borderRadius = "3px";
    box2.style.borderRadius = "3px";
    box3.style.borderRadius = "3px";
    tracking.innerHTML = box1.innerHTML+ " won congrat";
}
// ****************************************** winner box function () End *********************************** 




// ********************************* reply btn function() ****************************************************
function replay() {
    for(var i = 0; i < boxes.length; i++) {
        boxes[i].innerHTML = "";
        playerDiv.innerHTML = "Start Game";
        boxes[i].style.backgroundColor = "";
        boxes[i].style.borderRadius = "";
    }
    swal({
        title: "Try your Best",
        icon : "./image/like.png"    
    })
    .then(function () {
        location = "./index.html"
    })
}
// ************************************ reply btn function() end **************************************************


//                                   *********************************
//                                             HAPPY CODING
//                                              AHSAN MANI
//                                   *********************************



















































// function getUser1() {
//     swal({
//         text: "To start Tick tac game please select X or Y",
//         content: {
//             placeholder: "select Please",
//             // color: "red",
//         },
//         button:{
//             text:"selected",
//             // background: "dodgerblue",
//             closeModal: false,
//         }
//     })
//     .then(function (coin) {
//         var x = "X";
//         var y = "Y"
//             if(coin !== null && coin !== undefined && coin !== "" && coin !== " " && coin.toUpperCase() === x || coin.toUpperCase() === y) {
//                 swal({
//                     text: "First player have Selected " +coin.toUpperCase(),
//                     button:{
//                         text:"go for second player",
//                         closeModal:true, 
//                     }
//                 })
//                 .then(function () {
//                     user1 = coin.toUpperCase();
//                     for(var i = 0; i < 4; i++) {
//                         if(user1 === "X") {
//                             coinX.push(user1);
//                         }
//                         else{
//                             coinY.push(user1);
//                         }
//                     }
//                     getUser2();
//                 })
//             }

//         else{
//             swal({
//                 text: "please select valid user",
//                 button:{
//                     text:"ok",
//                     closeModal: true,
//                 }
//             })
//             .then(function () {
//                 getUser1();
//             }) 
//         }
//     })
//     .catch(function (error) {
//         getUser1()
//     })
// }
// getUser1()

// function getUser2() {
//     swal({
//         text: "player2 please Select X or Y",
//         content:{
//             placeholder: "Please Select",
//         },
//         button:{
//             text: "ok",
//             closeModal: false
//         }
//     })
//     .then(function (coin) {
//         var x = "X";
//         var y = "Y"
//             if(coin !== null && coin !== undefined && coin !== "" && coin !== " " && coin.toUpperCase() === x || coin.toUpperCase() === y) {
//                 swal({
//                     text: "second player have Selected " +coin.toUpperCase(),
//                     button:{
//                         text:"go for second player",
//                         closeModal:true, 
//                     }
//                 })
//                 .then(function () {
//                     user2 = coin.toUpperCase();
//                     for(var i = 0; i < 4; i++) {
//                         if(user2 === "Y") {
//                             coinY.push(user2);
//                         }
//                         else{
//                             coinX.push(user2);
//                         }
//                     }
//                     play();
//                 })
//             }
//             else{
//                 swal({
//                     text: "please Select X or Y",
//                     button:{
//                         text: "ok",
//                         closeModal:true,
//                     }
//                 })
//                 .then(function() {
//                     getUser2();
//                 })
//             }
//             })
//             .catch(function (error){
//                 userInput2();
//             })
// }

let firstCard = getRandomCard()
let secondCard = getRandomCard()
let cards = [firstCard,secondCard]
let hasBlackJack = false
let isAlive = false
let message = ""
let sum = firstCard + secondCard




function getRandomCard() {
    let randomcards=Math.floor(Math.random()*13)+1
    if (randomcards>10){
        return 10
    }else if (randomcards===1){
        return 11
    }else{
        return randomcards
    }
}

function startGame() {
    isAlive=true
    renderGame()
}

function renderGame() {
    if (sum < 21) {
        message="Do you want to draw a new card"
    }
    else  if (sum > 21){
        message="Sorry, you lost"
        isAlive = false
    }
    else{
        message="Congrats on your victory"
        hasBlackJack = true
    }
    let cardsEl = document.getElementById("cards-el")

    document.getElementById("message-el").textContent = message
    document.querySelector("#sum-el").textContent = "Sum: " + sum
    cardsEl.textContent="Cards: "
    for (let i = 0; i < cards.length;i++){
    cardsEl.textContent += cards[i]+","
    }
}

function newCard() {
    if (isAlive===true && hasBlackJack===false){
        console.log("Drawing out new card from the deck!!!")
    let newCard=getRandomCard()
    cards.push(newCard)
    sum+=newCard
    renderGame()
    }

}


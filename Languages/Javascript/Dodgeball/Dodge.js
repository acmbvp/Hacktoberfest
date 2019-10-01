var player; //the square that user controls
var balls = []; // track on-screen balls

var level; // level level of the balls

function setup() {

  createCanvas(700, 400);

	level = 2;

	/* initialize player */
    var widthOver2 = width / 2;
    var heightOver2 = height / 2;
    player = new Square(widthOver2, heightOver2,30, color("#FFFFFF"), null, level * 0.8);

	textAlign(CENTER);
  textSize(40);
}

function draw() {

  background(51);

    controlballs();
	controlPlayer();
	controlKeys();

	attemptNewBall(frameCount);

  drawScore();
}

//attempting to push a new ball to the balls array
function attemptNewBall(frame) {

	if (frame % 30 === 0) {
		//one ball every 0.5 seconds

    if (random(level) > 1.25) {
			// difficulty based upon level

			balls.push(generateSquare());
		}

		// difficulty level increase over time
    level += 0.05;
  }
}

//creating player control buttons and speed
function controlKeys() {

	// player is always 20% slower than balls, both getting faster by time
	var speed = level * 0.8;

  if (keyIsDown(UP_ARROW))
    player.move(0, -speed);

	if (keyIsDown(DOWN_ARROW))
    player.move(0, speed);

  if (keyIsDown(LEFT_ARROW))
    player.move(-speed, 0);

  if (keyIsDown(RIGHT_ARROW))
    player.move(speed, 0);

}

//outputs score
function drawScore() {

	noStroke();
  text(frameCount, width / 2, 60);
}

//updates, draws, checks collision for Squares manages balls array
function controlballs() {

	for (var i = balls.length - 1; i >= 0; i--) {

		// update & draw
    balls[i].update(false); // false = not-the-player
    balls[i].draw();

    if (balls[i].collidesWith(player))
			// check if balls collide, if true, execute endGame function
      endGame();

    if (balls[i].isOffscreen())
			// delete from array
      balls.splice(i, 1);

  }
}
//updates, draws, and constrains the player
function controlPlayer() {

// update & draw
	player.update(true);
  player.draw();

// constrain the player
  if (player.isOffscreen()) {
    endGame();
  }
}

//stops the loop, draws message
function endGame() {

  noLoop();
  textSize(70);
  fill(255);
  noStroke();
  text("Game Over!", width / 2, height / 2);
  textSize(40);
}

//returns a randomly generated Square
function generateSquare() {

  // creates square
  var plane = (random() > 0.5); // true = randomise x=axis, false = randomise y-axis

    //Balls spawning from edges of the canvas only
  var x = (plane) ? random(width) : ((random() > 0.5) ? 0 : width);
  var y = (plane) ? ((random() > 0.5) ? 0 : height) : random(height);

  return new Square(x, y, random(35), randomColor(), player.position, level);
}

//returns a random color
function randomColor() {
  return color(random(255), random(255), random(255));
}

class Vector2 {
  constructor(x, y) {
    this.x = x;
    this.y = y;
  }

  getNewPoint(start) {
    this.x += start.x;
    this.y += start.y;
  }

  magnitude() {
    return Math.sqrt((Math.pow(this.x, 2)) + (Math.pow(this.y, 2)));
  }
}

const canvas = document.getElementById("Display");
const ctx = canvas.getContext("2d");

let Point = { x: 0, y: 0 };
let Vector = new Vector2(9, 20);

const Paint = () => {
  ctx.beginPath();
  ctx.moveTo(Point.x, Point.y);
  ctx.lineTo(Vector.x, Vector.y);
  ctx.stroke();

  const p = document.getElementById("Length");
  p.style.display = "block";
  p.innerHTML = "Magnitude: " + Vector.magnitude();
}

/**
 * @param {String} input 
 */
const Compile = (input) => {
  const dictionary = { x: null, y: null };
  const nums = ["0", "1", "2", "3", "4", "5", "6", "7", "8", "9"];

  var VALID = false;

  if(!input.length) 
  {
    return dictionary;
  }

  for(var i = 0; i < input.length; i++) 
  {
    if(input.charAt(i) === "(") 
    {
      VALID = true;
    }

    if(VALID && input.charAt(i) !== ")" && input.charAt(i) !== " " && input.charAt(i) !== "," && nums.includes(input.charAt(i)))
    {
      var num = input.charAt(i);
    
      for(var j = i + 1; j < input.length; j++)
      {
        if(nums.includes(input.charAt(j)))
        {
          num += input.charAt(j);
        }
        else
        {
          break;
        }
      }

      if(dictionary.x === null)
      {
        dictionary.x = parseInt(num);
      }
      else if(dictionary.y === null) 
      {
        dictionary.y = parseInt(num);
        break;
      }

      i += j;
    }

    if(input.charAt(i) === ")")
    {
      VALID = false;
      break;
    }
  }

  return dictionary;
}

const submit = document.getElementById("Paint");
submit.addEventListener("click", (ev) => {
  Point = Compile(document.getElementById("Start").value);
  
  const vector = Compile(document.getElementById("Vector").value);
  Vector = new Vector2(vector.x, vector.y);

  console.log(JSON.stringify(Point) + "\n" + JSON.stringify(Vector))

  Paint();
});
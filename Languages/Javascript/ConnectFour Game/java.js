

//-----------------Variable declarations--------------------------------

var gameField = new Array();
var board = document.getElementById("game-table");
var currentColumn;
var currentRow;
var currentPlayer;
var id = 1;



newgame();

//---------------------Function For Creating new Game----------------------

function newgame()
{
  prepareField();
  placeDisc(Math.floor(Math.random()*2)+1);
}





function checkForVictory(row,column)
{
  if(getAdj(row,column,0,1)+getAdj(row,column,0,-1) > 2)
  {
    return true;
  } 
  else 
  {
    if(getAdj(row,column,1,0) > 2)
	{
      return true;
    } 
	else 
	{
      if(getAdj(row,column,-1,1)+getAdj(row,column,1,-1) > 2)
	  {
        return true;
      } 
	  else 
	  {
        if(getAdj(row,column,1,1)+getAdj(row,column,-1,-1) > 2)
		{
          return true;
        } 
		else 
		{
          return false;
        }
      }
    }
  }
}




function getAdj(row,column,row_inc,column_inc)
{
  if(cellValue(row,column) == cellValue(row+row_inc,column+column_inc))
  {
    return 1+getAdj(row+row_inc,column+column_inc,row_inc,column_inc);
  } else 
  {
    return 0;
  }
}



//---------------------Function For Cell Values----------------------



function cellValue(row,column)
{
  if(gameField[row] == undefined || gameField[row][column] == undefined)
  {
    return -1;
  }
  else 
  {
    return gameField[row][column];
  }
}





//---------------------Function For Free Rows----------------------




function firstFreeRow(column,player)
{
  for(var i = 0; i<6; i++)
  {
    if(gameField[i][column]!=0)
	{
      break;
    }
  }
  gameField[i-1][column] = player;
  return i-1;
}




//---------------------Function For Possible Columns----------------------



function possibleColumns()
{
  var moves_array = new Array();
  for(var i=0; i<7; i++)
  {
    if(gameField[0][i] == 0)
	{
      moves_array.push(i);
    }
  }
  return moves_array;
}



//-------------------------Function for Computer movements------------------------

function think()
{
  var possibleMoves = possibleColumns();
  var aiMoves = new Array();
  var blocked;
  var bestBlocked = 0;
  
  for(var i=0; i<possibleMoves.length; i++)
  {
    for(var j=0; j<6; j++)
	{
      if(gameField[j][possibleMoves[i]] != 0)
	  {
        break;
      }
    }
    
    gameField[j-1][possibleMoves[i]] = 1;
    blocked = getAdj(j-1,possibleMoves[i],0,1)+getAdj(j-1,possibleMoves[i],0,-1);
    blocked = Math.max(blocked,getAdj(j-1,possibleMoves[i],1,0));
    blocked = Math.max(blocked,getAdj(j-1,possibleMoves[i],-1,1));
    blocked = Math.max(blocked,getAdj(j-1,possibleMoves[i],1,1)+getAdj(j-1, possibleMoves[i],-1,-1));
    
    if(blocked >= bestBlocked)
	{
      if(blocked>bestBlocked)
	  {
        bestBlocked = blocked;
        aiMoves = new Array();
      }
      aiMoves.push(possibleMoves[i]);
    }
    gameField[j-1][possibleMoves[i]] = 0;
  }
  
  return aiMoves;
}




//---------------------Function For Players Disc----------------------



function Disc(player)
{
  this.player = player;
  this.color = player == 1 ? 'red' : 'yellow';
  this.id = id.toString();
  id++;
  
  this.addToScene = function()
  {
    board.innerHTML += '<div id="d'+this.id+'" class="disc '+this.color+'"></div>';
    if(currentPlayer==2)
	{
      //computer move
      var possibleMoves = think();
      var cpuMove = Math.floor( Math.random() * possibleMoves.length);
      currentColumn = possibleMoves[cpuMove];
      document.getElementById('d'+this.id).style.left = (14+60*currentColumn)+"px";
      dropDisc(this.id,currentPlayer);
    }
  }
  
  
  var $this = this;
  document.onmousemove = function(evt)
  {
    if(currentPlayer == 1)
	{
    currentColumn = Math.floor((evt.clientX - board.offsetLeft)/60);
    if(currentColumn<0){currentColumn=0;}
    if(currentColumn>6){currentColumn=6;}
    document.getElementById('d'+$this.id).style.left = (14+60*currentColumn)+"px";
    document.getElementById('d'+$this.id).style.top = "-55px";
    }
  }
  document.onload = function(evt)
  {
    if(currentPlayer == 1)
	{
    currentColumn = Math.floor((evt.clientX - board.offsetLeft)/60);
    if(currentColumn<0){currentColumn=0;}
    if(currentColumn>6){currentColumn=6;}
    document.getElementById('d'+$this.id).style.left = (14+60*currentColumn)+"px";
    document.getElementById('d'+$this.id).style.top = "-55px";
    }
  }
  
  
  document.onclick = function(evt){
    if(currentPlayer == 1){
      if(possibleColumns().indexOf(currentColumn) != -1){
        dropDisc($this.id,$this.player);
      }
    }
  }
}




//---------------------Function For Dropping Discs----------------------



function dropDisc(cid,player)
{
  currentRow = firstFreeRow(currentColumn,player);
  moveit(cid,(14+currentRow*60));
  currentPlayer = player;
  checkForMoveVictory();
}


//---------------------Function For Checking Victory between computer and player----------------------


function checkForMoveVictory()
{
  if(!checkForVictory(currentRow,currentColumn))
  {
    placeDisc(3-currentPlayer);
  } 
  else 
  {
    var ww = currentPlayer == 2 ? 'Computer' : 'Player';
    placeDisc(3-currentPlayer);
    alert(ww+" win!");
    board.innerHTML = "";
    newgame();
  }
}




//---------------------Function For player to place the new disc----------------------



function placeDisc(player)
{
  currentPlayer = player;
  var disc = new Disc(player);
  disc.addToScene();
}


function prepareField()
{
  gameField = new Array();
  for(var i=0; i<6; i++)
  {
    gameField[i] = new Array();
    for(var j=0; j<7; j++)
	{
      gameField[i].push(0);
    }
  }
}

function moveit(who,where)
{
    document.getElementById('d'+who).style.top = where+'px';
}
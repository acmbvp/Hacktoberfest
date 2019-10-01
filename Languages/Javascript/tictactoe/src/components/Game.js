import React,{Component} from 'react';
import '../style.css';
// class Square extends Component
// {  
// 	render()
// 	{
// 		return(
// 			<td onClick={this.props.onClick}>{this.props.value} </td>
// 			)
// 	}
// }

function Square(props)
{
  return(
   <td onClick={props.onClick}>{props.value} </td>
  )
}

class Board extends Component
{  
	constructor(props)
	{
		super(props)
		this.state={
			squares: Array(9).fill(null),
			xIsNext: true
		}
	}


	handleClick(i)
	{
		const squarecopy = this.state.squares.slice();
		if(CalculateWinner(squarecopy) || squarecopy[i])
			{return;}
		squarecopy[i] = this.state.xIsNext ? 'X' : 'O';
		this.setState({squares:squarecopy,
			xIsNext: !this.state.xIsNext})


	}
	renderSquare(i)
	{   
		return(
			<Square value={this.state.squares[i]} onClick={()=>this.handleClick(i)}/>
			)
	}
	render()
	{   const winner = CalculateWinner(this.state.squares)
		let status;
		if(winner)
		{
           status = 'Hurray!!! ' +  winner + ' won the Game';
		}
		else
		{
           status = 'Next player :'+(this.state.xIsNext ? 'X' :'O');
		}
		 
		return(
		<div>
		  {status}

		 <tr>{this.renderSquare(0)}
			{this.renderSquare(1)}
			{this.renderSquare(2)}
			</tr>
			<tr>
			{this.renderSquare(3)}
			{this.renderSquare(4)}
			{this.renderSquare(5)}
			</tr>
			<tr>
			{this.renderSquare(6)}
			{this.renderSquare(7)}
			{this.renderSquare(8)}
		 </tr>
		   </div>
			
			
			)
	}
}

class Game extends Component
{
   render()
   {
   	return(
   		<Board />)
   }
}
function CalculateWinner(square)
{
  let lines = [
  [0,1,2],
  [3,4,5],
  [6,7,8],
  [0,3,6],
  [1,4,7],
  [2,5,8],
  [0,4,8],
  [2,4,6]]
  for(let i =0 ;i<lines.length;i++)
  {
  	const [a,b,c] = lines[i];
  	if(square[a] && square[a]===square[b] && square[a]===square[c] )
  	{
  		return square[a]
  	}
  }
  return null;
}
export default Game;
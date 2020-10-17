package main

import (
	"fmt"
)

type Move struct {
	x int
	y int
}

func allSame(a int, b int, c int) bool {
	if a == b && b == c && a != 2 && b != 2 {
		return true
	}
	return false
}

func isTerminal(board [3][3]int) bool {
	isTerm := false
	for i := 0; i < 3; i++ {
		if allSame(board[i][0], board[i][1], board[i][2]) {
			isTerm = true
		}
		if allSame(board[0][i], board[1][i], board[2][i]) {
			isTerm = true
		}
	}
	if allSame(board[0][0], board[1][1], board[2][2]) {
		isTerm = true
	}
	if allSame(board[0][2], board[1][1], board[2][0]) {
		isTerm = true
	}
	return isTerm
}

func isUnplayed(board [3][3]int, move Move) bool {
	if board[move.x][move.y] == 2 {
		return true
	}
	return false
}

func gameOver(board [3][3]int) bool {
	flag := true
	for x := 0; x < 3; x++ {
		for y := 0; y < 3; y++ {
			if isUnplayed(board, Move{x, y}) {
				flag = false
			}
		}
	}
	if isTerminal(board) {
		flag = true
	}
	return flag
}
func minimax(board [3][3]int, player int, depth int) (int, Move) {
	// player = 1 means human
	// player = 0 means AI
	//fmt.Print(board)
	var score int
	bestscore := -100
	var bestmove Move

	nextPlayer := player
	if player == 1 {
		nextPlayer = 0
	} else {
		nextPlayer = 1
	}

	for x := 0; x < 3; x++ {
		for y := 0; y < 3; y++ {
			move := Move{x, y}
			newBoard := board
			if isUnplayed(board, move) {
				newBoard[move.x][move.y] = player
				if isTerminal(newBoard) {
					return 20*player - 10, move
				}

				score, _ = minimax(newBoard, nextPlayer, depth+1)

				if bestscore == -100 {
					bestscore = score
				}
				if player == 0 && score <= bestscore {
					bestscore = score
					bestmove = move
				}
				if player == 1 && score >= bestscore {
					bestscore = score
					bestmove = move
				}
			}

		}
	}
	return bestscore, bestmove
}

func playAI(board [3][3]int) [3][3]int {
	_, move := minimax(board, 0, 0)
	board[move.x][move.y] = 0
	return board
}
func main() {
	board := [3][3]int{
		{2, 2, 2},
		{2, 2, 2},
		{2, 2, 2},
	}

	for true {
		var x, y int
		fmt.Scanln(&x)
		fmt.Scanln(&y)
		if isUnplayed(board, Move{x, y}) {
			board[x][y] = 1
		} else {
			fmt.Println("Try again")
			continue
		}
		board = playAI(board)
		fmt.Println(board[0])
		fmt.Println(board[1])
		fmt.Println(board[2])

		if gameOver(board) {
			fmt.Println("Game Over!")
			break
		}

	}
}

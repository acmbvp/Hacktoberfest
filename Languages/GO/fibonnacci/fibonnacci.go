package main

import (
	"fmt"
)

func main() {
	var n int
	fmt.Println("Enter the value of n:")
	fmt.Scanf("%d", &n)

	fibonnacci(n)
}

func fibonnacci(n int) {
	arr := make([]int, n)
	arr[0] = 0
	arr[1] = 1

	for i := 2; i < n ; i++ {
		arr[i] = arr[i-1] + arr[i-2]
	}
	fmt.Println("Your desired fibonnaci series: \n",arr)
}
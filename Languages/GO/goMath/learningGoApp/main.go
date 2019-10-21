package main

import (
	"fmt"
	"strings"

	"practice/goPractice/learningGoApp/learningGoApp/area"
	"practice/goPractice/learningGoApp/learningGoApp/calculator"
)

func main() {

	//getOperation is a label, use labels to define sections within a single func or multi func
	//we use as a checkpoint under main, to choose an operation.
getOperation:
	var operation string
	fmt.Println("Do you want Arithmetic or Geometry?")
	fmt.Scanln(&operation)
	operation = strings.ToLower(operation)
	switch *&operation {
	case "arithmetic", "+", "-", "*", "/":
		fmt.Println("Arithmetic it is!")
		calculator.ArithmeticCalculator()
		goto getOperation
	case "geometry", "area", "shape":
		fmt.Println("Area it is!")
		area.GeometryCalculator()
		goto getOperation
	case "exit":
		break
	default:
		fmt.Println("Invalid operation selected. Please try again!")
		//The goto in this case saves us from introducing another (boolean) variable used just for control-flow, checked for at the end. In this case, the goto statement makes the code actually better to read and easier follow
		goto getOperation
		// var mathOperation string
		// var operation string
	}
}

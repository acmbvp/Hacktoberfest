package calculator

import (
	"bufio"
	"fmt"
	"math"
	"os"
	"strconv"
	"strings"
)

//MATH Functions
func Add(num1, num2 float64) float64 {
	return num1 + num2
}

//Subtract is
func Subtract(num1, num2 float64) float64 {
	return num1 - num2
}

//Multiply is
func Multiply(num1, num2 float64) float64 {
	return num1 * num2
}

//Divide is
func Divide(num1, num2 float64) float64 {
	return num1 / num2
}

//Divmod is
func Divmod(numerator, denominator int64) (quotient, remainder int64) {
	quotient = numerator / denominator // integer division, decimals are truncated
	remainder = numerator % denominator
	return
}

//Sqrt is
func Sqrt(num float64) float64 {
	return math.Sqrt(num)
}

// HELPER Functions
func isNumeric(s string) bool {
	_, err := strconv.ParseFloat(s, 64)
	return err == nil
}

func stringToInt(str string) int {
	i, err := strconv.Atoi(str)
	if err != nil {
		fmt.Println(err)
		os.Exit(2)
	}
	return i
}

func stringToFloat64(str string) float64 {
	f, err := strconv.ParseFloat(str, 64)
	if err != nil {
		fmt.Println(err)
		os.Exit(2)
	}
	return f
}

func float64ToString(float float64) string {
	return fmt.Sprintf("%f", float)
}

func SplitStringByCharacter(str string) []string {
	strArray := []string{}
	var multiCharValue string
	index := 0
	for _, char := range str {
		if string(char) == "-" && (index-1) == -1 {
			multiCharValue += string(char)
		} else if string(char) == "-" && !isNumeric(string(str[index-1])) && string(str[index-1]) != ")" {
			multiCharValue += string(char)
		} else if isNumeric(string(char)) && ((index + 1) != len(str)) && isNumeric(string(str[index+1])) {
			multiCharValue += string(char)
		} else if isNumeric(string(char)) && ((index + 1) != len(str)) && !isNumeric(string(str[index+1])) {
			multiCharValue += string(char)
			strArray = append(strArray, string(multiCharValue))
			multiCharValue = ""
		} else if isNumeric(string(char)) && ((index + 1) == len(str)) {
			multiCharValue += string(char)
			strArray = append(strArray, string(multiCharValue))
			multiCharValue = ""
		} else {
			strArray = append(strArray, string(char))
		}
		index++
	}
	return strArray
}

func contains(expr []string, charToFind string) int {
	var index int
	if charToFind == "(" {
		//loop through expr backward when searching for opening parenthesis
		//this is to capture innermost parenthesis in case of nested parentheses
		for i := len(expr) - 1; i >= 0; i-- {
			if charToFind == expr[i] {
				index = i
				break
			} else {
				index = -1
			}
		}
	} else {
		for exprIndex, exprValue := range expr {
			if charToFind == exprValue {
				index = exprIndex
				break //not greedy will return after first occurence found
			} else {
				index = -1
			}
		}
	}
	return index
}

func evaluateExpression(expr []string) []string {
	for {
		fmt.Println("\tEvaluate Expression ", expr)
		if len(expr) >= 3 {
			//[low:high] Just means upto but not includding (high)
			subExpr := expr[0:3]
			subSolution := evaluate(subExpr)
			subSolutionStr := float64ToString(subSolution)
			//update the expr array
			subExprSolution := []string{subSolutionStr}
			suffix := expr[3:]

			expr = append(subExprSolution, suffix...)
		} else {
			break
		}
	}
	return expr
}

func evaluate(expr []string) float64 {
	var solution float64
	switch expr[1] {
	case "^":
		solution = stringToFloat64(expr[0])
		exp := stringToFloat64(expr[2])
		if stringToFloat64(expr[2]) < 0 {
			exp = -exp
		}
		for i := 1.0; i < exp; i++ {
			solution = solution * stringToFloat64(expr[0])
		}
		if stringToFloat64(expr[2]) < 0 {
			solution = 1 / solution
		}
	case "*":
		solution = Multiply(stringToFloat64(expr[0]), stringToFloat64(expr[2]))
	case "/":
		solution = Divide(stringToFloat64(expr[0]), stringToFloat64(expr[2]))
	case "+":
		solution = Add(stringToFloat64(expr[0]), stringToFloat64(expr[2]))
	case "-":
		solution = Subtract(stringToFloat64(expr[0]), stringToFloat64(expr[2]))
	}
	return solution
}

func resetExpressionArray(indexBeforeOperator int, indexAfterOperator int, expr []string, subExprSolution string) []string {
	prefixAndSubExprSolution := append(expr[0:indexBeforeOperator], subExprSolution)
	suffix := expr[(indexAfterOperator):]
	expr = append(prefixAndSubExprSolution, suffix...)

	return expr
}

func parseExpression(expr []string) float64 {
	var solution float64
	//TODO: add support sqrt and divmoid input
	for {
		//search for operators following PEMDAS precedences
		if openParenthesisIndex := contains(expr, "("); openParenthesisIndex != -1 {
			closeParentheisIndex := contains(expr, ")")
			subExpr := expr[(openParenthesisIndex + 1):(closeParentheisIndex)]
			expr = resetExpressionArray(openParenthesisIndex, closeParentheisIndex+1, expr, evaluateExpression(subExpr)[0])
		} else if exponentIndex := contains(expr, "^"); exponentIndex != -1 {
			subExpr := expr[(exponentIndex - 1) : (exponentIndex)+2]
			expr = resetExpressionArray(exponentIndex-1, exponentIndex+2, expr, evaluateExpression(subExpr)[0])
		} else if multiIndex := contains(expr, "*"); multiIndex != -1 {
			subExpr := expr[(multiIndex - 1) : (multiIndex)+2]
			expr = resetExpressionArray(multiIndex-1, multiIndex+2, expr, evaluateExpression(subExpr)[0])
		} else if divisionIndex := contains(expr, "/"); divisionIndex != -1 {
			subExpr := expr[(divisionIndex - 1) : (divisionIndex)+2]
			expr = resetExpressionArray(divisionIndex-1, divisionIndex+2, expr, evaluateExpression(subExpr)[0])
		} else { //addition or subtraction
			expr = evaluateExpression(expr)
		}
		if len(expr) == 1 {
			solution = stringToFloat64(expr[0])
			break
		}
	}
	return solution
}

//ArithmeticCalculator main controller
func ArithmeticCalculator() {
	scanner := bufio.NewScanner(os.Stdin)
	for {
		fmt.Println("Enter expression. NO EQUALS SIGN.")
		fmt.Println("Available inputs: [ 0-9 ( ) + - * ]")
		fmt.Print("User input: ")
		scanner.Scan()
		solution := parseExpression(SplitStringByCharacter(strings.Replace(scanner.Text(), " ", "", -1)))
		fmt.Println("\n", scanner.Text(), "= ", solution)
	}
}

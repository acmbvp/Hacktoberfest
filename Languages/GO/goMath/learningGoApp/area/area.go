package area

import (
	"fmt"
	"math"
)

type square struct {
	length float64
}
type rectangle struct {
	length float64
	width  float64
}
type circle struct {
	radius float64
}
type triangle struct {
	length float64
}
type sphere struct {
	length float64
	width  float64
}
type cylinder struct {
	length float64
	width  float64
}

func (s *square) Area() float64 {
	return s.length * s.length
}
func (r *rectangle) Area() float64 {
	return r.length * r.width
}
func (c *circle) Area() float64 {
	return math.Pi * c.radius * c.radius
}
func (t *triangle) Area() float64 {
	return t.length * t.length * t.length
}
func (s *sphere) Area() float64 {
	return s.length * s.width
}
func (c *cylinder) Area() float64 {
	return c.length * c.width
}

//NewSquare something
func NewSquare() Shape {
	return &square{}
}

//NewSquare something
func NewRectangle() Shape {
	return &rectangle{}
}

//NewSquare something
func NewCircle(radius float64) Shape {
	var circle circle
	circle.radius = radius
	return &circle
}

//NewSquare something
func NewTriangle() Shape {
	return &triangle{}
}

//NewSquare something
func NewSphere() Shape {
	return &sphere{}
}

//NewSquare something
func NewCylinder() Shape {
	return &cylinder{}
}

//Shape interface
type Shape interface {
	Area() float64
}

func info(s Shape) {
	fmt.Println("area", s.Area())
}

//GeometryCalculator main controller
func GeometryCalculator() {
	var operation string
setShape:
	fmt.Println("Choose the shape you want the area of (Circle or Square) ")
	fmt.Scanln(&operation)
	fmt.Println("you entered", operation)
getOperation:
	switch *&operation {
	case "circle":
		var circle circle
		// var square float64
		fmt.Print("Input a Radius of the circle: ")
		fmt.Scanln(&circle.radius)

		fmt.Println(circle.Area())
	case "square":
		var square square
		fmt.Println("Input a Length of the Square: ")
		fmt.Scanln(&square.length)
		fmt.Println(square.Area())

	case "rectangle":
		var rectangle rectangle
		fmt.Println("Input a Length & Width of the rectangle: ")
		fmt.Scanln(&rectangle.length)
		fmt.Println(rectangle.Area())
	case "exit":
		return
	default:
		fmt.Println("Invalid operation selected. Please try again!")
		//The goto in this case saves us from introducing another (boolean) variable used just for control-flow, checked for at the end. In this case, the goto statement makes the code actually better to read and easier follow
		goto getOperation
	}
	goto setShape
}

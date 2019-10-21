package calculator_test

import (
	"fmt"

	. "practice/goPractice/learningGoApp/learningGoApp/calculator"

	. "github.com/onsi/ginkgo"
	. "github.com/onsi/gomega"
)

var _ = Describe("Calculator", func() {

	var (
		num1, num2 float64
	)

	BeforeEach(func() {
		fmt.Println("Running test case.")
		num1 = 6
		num2 = 4
	})

	AfterEach(func() {
		fmt.Println("Test case executed.")
	})

	// Describe("Testing ", func() {
	Context("calculating sum of (6,4).", func() {
		It("should return 10.0", func() {
			Expect(Add(num1, num2)).To(Equal(10.0))
		})
	})

	Context("calculating subtraction of (4,6).", func() {
		It("should return -2.0", func() {
			Expect(Subtract(num2, num1)).To(Equal(-2.0))
		})
	})

	Context("calculating multiplication of (6, 4).", func() {
		It("should return 24.0", func() {
			Expect(Multiply(num1, num2)).To(Equal(24.0))
		})
	})

	Context("calculating square root of (9).", func() {
		It("should return 3.0", func() {
			Expect(Sqrt(9)).To(Equal((3.0)))
		})
	})
	Context("split string by character", func() {
		It("should seperate characters properly", func() {
			expr := "-25+(1+20)"
			splitExpr := SplitStringByCharacter(expr)
			Expect(splitExpr[0]).To(Equal("-25"))
			Expect(splitExpr[1]).To(Equal("+"))
			Expect(splitExpr[5]).To(Equal("20"))
		})
	})

})

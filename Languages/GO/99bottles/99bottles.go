package main

import "fmt"

func main() {

	word := "bottle"

	for beers := 99; beers >= 0; beers-- {

		var plural string

		if beers == 1 {
			plural = word
		} else {
			plural = word + "s"
		}

		fmt.Printf("%d %s of beer on the wall, %d %s of beer\n", beers, plural, beers, plural)

		if beers > 0 {
			fmt.Printf("Take one down, pass it around %d %s of beer on the wall!\n", beers, plural)
		} else {
			fmt.Println("You're out of beer, get some more!")
		}
	}
}

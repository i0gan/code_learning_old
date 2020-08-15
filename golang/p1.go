package main
import "fmt"

func main() {
	fmt.Println("Hello World!")

	var i int = 0
	for i = 0; i < 5; i = i + 1 {
		fmt.Println(i)
	}

	hello := "aaa"
	fmt.Print(hello)
}

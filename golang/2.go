package main
import "fmt"

func main() {
	s := "hello world"
	for i := 0; i < len(s); i++ {
		fmt.Printf("%c", s[i])
	}

	s2 := "白萝卜"
	s3 := []rune(s2) 
	s3[0] = '红'
	fmt.Println(string(s3))

	c1 := "红"

	fmt.Println("%c", c1)
	fmt.Println("%T", s2)
}

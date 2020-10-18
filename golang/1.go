package main
import "fmt"

func max(num1, num2 int) int {
	var result int
	if(num1 > num2) {
		result = num1
	} else {
		result = num2
	}
	return result
}

// 函数返回多个值
func swap(x, y string) (string, string) {
	return y, x
}

func main() {
	fmt.Println("hello world!")
	fmt.Println("max is ", max(1, 2))

	// 采用返回值赋予不同变量
	a, b := swap("A", "B")
	fmt.Println(a, b)
}

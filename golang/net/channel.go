package main
import "fmt"
import "sync"

var a[]int
var ch chan int // 指定通道中元素的类型
var ch2 chan int // 指定通道中元素的类型
var wg sync.WaitGroup // 定义一个同步信号


func main() {
	// 不带缓冲区的通道
	ch = make(chan int) // 使用make函数初始化
	// 带缓冲区的通道
	ch2 = make(chan int, 16)

	wg.Add(1)	
	go func() {
		defer wg.Done() //计数器-1
		// 接收值
		a := <-ch
		fmt.Printf("\nrecevied: %d\n" ,a)
	}()

	// 发送值
	fmt.Printf("\nsend\n")
	ch <- 10

	fmt.Println(ch)
	// 发送值
	ch2 <- 3
	wg.Wait()
}

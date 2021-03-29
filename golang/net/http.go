 
package main
import (
	"encoding/json"
	"fmt"
	"net/http"
	"time"
)
type BaseJsonBean struct {
	Code    int         `json:"code"`
	Data    interface{} `json:"data"`
	Message string      `json:"message"`
}

func NewBaseJsonBean() *BaseJsonBean {
	return &BaseJsonBean{}
}

func WebServerBase() {
	fmt.Println("This is a webserver base!")
	http.HandleFunc("/login", loginTask)

	err := http.ListenAndServe("127.0.0.1:8000", nil)
	if err != nil {
		fmt.Println("ListenAndServer error: ", err.Error())
	}
}

func loginTask(w http.ResponseWriter, req *http.Request) {
	fmt.Println("loginTask is running...")
	// 模拟延时
	time.Sleep(time.Second * 1)
	// 获取客户端通过GET/POST方式传递的参数
	req.ParseForm()
	param_account, found1 := req.Form["account"]
	param_password, found2 := req.Form["password"]
	if !(found1 && found2) {
		fmt.Fprint(w, "error")
		return
	}
	result := NewBaseJsonBean()
	account := param_account[0]
	password := param_password[0]

	s := "account:" + account + ",password:" + password
	fmt.Println(s)

	if account == "i0gan" && password == "123456" {
		result.Code = 100
		result.Message = "登录成功"
	}else {
		result.Code = 1
		result.Message = "用户密码不正确"
	}

	//向客户端返回JSON数据
	bytes, _ := json.Marshal(result)
	fmt.Fprint(w, string(bytes))

}

func main() {
	fmt.Println("Hello Wrold!")
	WebServerBase()
}
// 验证:
//curl "http://127.0.0.1:8000/login?account=i0gan&password=123456"
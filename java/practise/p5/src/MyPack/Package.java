package MyPack;
import pac1.HelloPack; //也可以采用: import pac1.* ,表示导入所有包

//导入包的可能会出现重名. 采用次方法: java.util.Date date = new java.util.Date(); 来指明
import java.util.Date;
import java.sql.*; //

/*在以后写项目的时候就一定要加包
* 包名命名规范: 域名倒着写, 再加上模块名, 便于管理内部管理类
* 例如: com.sun.test
* cn.sxt.gao.view.model
* java常用包:
* java.lang //核心类
* java.awt //用于图形界面
* java.net //网络相关
* java.io //输入输出
* java..util //工具类
*
* 技巧:
* 按住 Ctrl + 鼠标点击左键即可进入某个类中.
* */

//导入Math下的所有静态属性
import java.lang.Math.*;

public class Package {
    public static void main(String[] args) {
        //此方法不用声明 import pac1.HelloPack;
        pac1.HelloPack p1 = new pac1.HelloPack(2, "I0gan");
        p1.print();

        //此方法需要: import pac1.HelloPack;
        HelloPack p2 = new HelloPack(3, "Mike");
        p2.print();

        //不同包下类重名解决办法:
        java.util.Date date = new java.util.Date();
        java.sql.Date date2 = new java.sql.Date(1);
    }
}

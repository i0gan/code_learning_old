package MyObj;

import java.util.Objects;

/*
 * 重写==函数 (equal)
 *public boolean equals(Object obj) {
 *       return (this == obj); //默认采用判断地址是否相等来判断对象是否相等
 * }
 *
 * */
public class MyObj {
    public static void main(String[] args) {
        Object obj;
        String str;

        User u1 = new User(1, "老王", "123456");
        User u2 = new User(1, "老王", "123456");
        System.out.println(u1 == u2);
        System.out.println(u1.equals(u2));

    }
}

class User {
    int id;
    String name;
    String pwd;
    public User(int id, String name, String pwd) {
        super();
        this.id = id;
        this.name = name;
        this.pwd = pwd;
    }
    //@Override
    public boolean equals(Object obj) {
        System.out.println("equals调用");
        if(this == obj) {
            return true;
        }
        if(obj == null) {
            return false;
        }
        if(getClass() != obj.getClass()) {
            return false;
        }
        User other = (User)obj;
        if(this.id == other.id) {
            return true;
        }
        return true;
    }
    @Override
    public int hashCode() {
        return Objects.hash(id, name, pwd);
    }
}
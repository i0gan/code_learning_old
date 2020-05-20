public class Array {
    public static void main(String[] args) {
        //静态初始化
        int[] a = {1, 2, 4 ,5};
        User[] b = {new User(1), new User(2), new User(3)};
        //动态初始化
        int[] c = new int[4];
        c[0] = 1;
        c[2] = 0;
        //默认初始化
        int d[] = new int[2]; //默认值为0
        boolean[] e = new boolean[3]; // 默认值为false
        String[] s = new String[2];   //默认值为null
        User[] u = new User[4]; //默认值为null

        for(int i = 0; i < u.length; ++i) {
            u[i] = new User(i);
        }
        //不能对对象进行真正的赋值
        for (User i: u) {
            System.out.println(i.getId());
        }
    }
}

class User {
    int id;
    User(int id) {
        this.id = id;
    }
    int getId() {
        return this.id;
    }
}

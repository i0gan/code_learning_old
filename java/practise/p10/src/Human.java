public class Human {
    public String name;
    private int age;
    protected int rev;

    //外部类采用set get来操作private成员
    public void setAge(int age) {
        if(age < 4) {
            age = 4;
        }
        this.age = age;
    }
    public int getAge() {
        return this.age;
    }
}

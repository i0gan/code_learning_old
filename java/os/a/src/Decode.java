public class Decode {
    public static String F1AG_HERE() {
        char[] arrayOfChar = new char[12];
        arrayOfChar[0] = 'W';
        arrayOfChar[1] = 'p';
        arrayOfChar[2] = 'Z';
        arrayOfChar[3] = 'p';
        arrayOfChar[4] = 'w';
        arrayOfChar[5] = 'z';
        arrayOfChar[6] = 'y';
        arrayOfChar[7] = 'q';
        arrayOfChar[8] = '|';
        arrayOfChar[9] = 'v';
        arrayOfChar[10] = 'x';
        arrayOfChar[11] = 'v';
        for (int i = 0; i < 12; i++) {
            (new char[12])[0] = '2';
            (new char[12])[1] = 'A';
            (new char[12])[2] = '2';
            (new char[12])[3] = 'C';
            (new char[12])[4] = 'F';
            (new char[12])[5] = 'L';
            (new char[12])[6] = 'A';
            (new char[12])[7] = 'G';
            (new char[12])[8] = 'D';
            (new char[12])[9] = 'O';
            (new char[12])[10] = 'O';
            (new char[12])[11] = 'G';
            arrayOfChar[i] = (char)(arrayOfChar[i] ^ (new char[12])[i]);
            char c = arrayOfChar[i];
            arrayOfChar[i] = (char)(c - 1);
            arrayOfChar[i] = c;
        }
        return arrayOfChar.toString();
    }
    public static void main(String[] args) {
        System.out.println("aaaa: ");
        System.out.println(F1AG_HERE());
    }
}

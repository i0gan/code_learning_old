import java.io.*;

public class OperatingSystem {
    private Floppy floppyDisk = new Floppy();
    private void writeFileToFloppy(String fileName) {
        File file = new File(fileName);
        InputStream in = null;
        try {
            in = new FileInputStream(file);
            byte[] data = new byte[512];
            // Hardware Signature
            data[510] = 0x55;
            data[511] = (byte)0xaa;
            //写入boot信息
            if(in.read(data) != -1) {
                floppyDisk.writeFloppy(Floppy.MagneticHead.MAGNETIC_HEAD_0,
                        0,1, data);
            }
        } catch (IOException e) {
            e.printStackTrace();
            return;
        }
    }
    public OperatingSystem(String s) {
        writeFileToFloppy(s);
    }
    public void makeFloppy() {
        String s = "LIX SYS:  This is a text from cylinder 3 and sector 2";
        floppyDisk.writeFloppy(Floppy.MagneticHead.MAGNETIC_HEAD_0, 1, 2, s.getBytes());
        floppyDisk.makeFloppy("os.img");
    }
    public static void main(String[] args) {
        OperatingSystem os = new OperatingSystem("./boot");
        os.makeFloppy();
    }
}

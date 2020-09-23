import java.io.DataOutput;
import java.io.DataOutputStream;
import java.io.FileOutputStream;
import java.lang.management.ManagementFactory;
import java.util.ArrayList;
import java.util.HashMap;

public class Floppy {
    enum MagneticHead {
        MAGNETIC_HEAD_0,
        MAGNETIC_HEAD_1,
    };
    private int SECTOR_SIZE = 512;    // 一个扇区有512字节
    private int CYLINDER_COUNT = 80; // 80 个磁道
    private int SECTORS_COUNT = 36;  // 一个磁道有18个扇区
    private MagneticHead magneticHead = MagneticHead.MAGNETIC_HEAD_0; //默认为 0 磁面

    private  int current_cylinder = 0;
    private  int current_sector = 0;
    // 模拟软盘
    private HashMap<Integer, ArrayList<ArrayList<byte[]>>> floppy = new HashMap<Integer, ArrayList<ArrayList<byte[]>>>();

    public Floppy() {
        initFloppy();
    }
    // 初始化盘面数据
    private void initFloppy() {
        // 一个磁盘有两个盘面
        floppy.put(MagneticHead.MAGNETIC_HEAD_0.ordinal(), initFloppyDisk());
        floppy.put(MagneticHead.MAGNETIC_HEAD_1.ordinal(), initFloppyDisk());
    }
    // 初始化磁道数据
    private ArrayList<ArrayList<byte[]>> initFloppyDisk() {
        ArrayList<ArrayList<byte[]>> floppyDisk = new ArrayList<ArrayList<byte[]>>();
        // 初始化80个磁道
        for (int i = 0; i < CYLINDER_COUNT; ++i) {
            floppyDisk.add(initCylinder());
        }
        return floppyDisk;
    }

    // 初始化扇区数据
    private ArrayList<byte[]> initCylinder() {
        ArrayList<byte[]> cylinder = new ArrayList<byte[]>();
        for (int i = 0; i < SECTORS_COUNT; ++i) {
            byte[] sector = new byte[SECTOR_SIZE];
            cylinder.add(sector);
        }
        return cylinder;
    }

    public void setMagneticHead(MagneticHead head) {
        magneticHead = head;
    }
    // 设定 磁柱(磁道)
    public void setCylinder(int cylinder) {
        if (cylinder < 0)
            this.current_cylinder = 0;
        else if ( cylinder >= CYLINDER_COUNT) // 磁柱(磁道)个数
            this.current_cylinder = CYLINDER_COUNT - 1;
        else
            this.current_cylinder = cylinder;
    }
    // 设定扇区
    public void setSector(int sector) {
        // 编号从1 ~ 18
        if(sector < 1)
            this.current_sector = 0;
        else if(sector > SECTORS_COUNT)
            this.current_sector = SECTORS_COUNT - 1;
        else
            this.current_sector = sector - 1;
    }

    public byte[] readFloppy(MagneticHead head, int cylinder_num, int sector_num) {
        setMagneticHead(head);
        setCylinder(cylinder_num);
        setSector(sector_num);

        ArrayList<ArrayList<byte[]>> disk = floppy.get(this.magneticHead.ordinal());
        ArrayList<byte[]> cylinder = disk.get(this.current_cylinder);
        byte[] sector = cylinder.get(this.current_sector);
        return sector;
    }

    public void writeFloppy(MagneticHead head,  int cylinder_num, int sector_num, byte[] data) {
        setMagneticHead(head);
        setCylinder(cylinder_num);
        setSector(sector_num);
        if(data.length > SECTOR_SIZE) {
            System.out.println("func: writeFloppy data too big");
            return;
        }
        ArrayList<ArrayList<byte[]>> disk = floppy.get(this.magneticHead.ordinal());
        ArrayList<byte[]> cylinder = disk.get(this.current_cylinder);
        cylinder.set(this.current_sector, data);

    }

    public void makeFloppy(String fileName) {
        try {
            DataOutputStream out = new DataOutputStream(new FileOutputStream(fileName));
            for(int head = 0; head <= MagneticHead.MAGNETIC_HEAD_1.ordinal(); ++head)
                for(int cylinder = 0; cylinder < CYLINDER_COUNT; ++cylinder)
                    for(int sector = 1; sector <= SECTORS_COUNT; ++sector) {
                        byte[] data = readFloppy(MagneticHead.values()[head], cylinder, sector);
                        out.write(data);
                        if(data.length < SECTOR_SIZE) {
                            int size = data.length;
                            for(int i = 0; i < (SECTOR_SIZE - size); ++i) {
                                out.write((byte)0);
                            }
                        }
                    }
            out.close();

        } catch (Exception e) {
            e.printStackTrace();
        }
    }

}

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <dirent.h>
#include <string.h>
void sys_01() //复制文件函数
{
       	//打开已经存在的文件
	int fd = open("Logan.txt",O_RDONLY);
	if(fd == -1)
	{
		perror("open");
		exit(1);
	}
	//创建文件
	int fd2 = open("Newfile",O_CREAT | O_WRONLY | O_EXCL, 0755);
	if(fd2 == -1)
	{
		perror("open2");
		exit(1);
	}
	char buf[2048] = {0};
	int count = read(fd,buf,sizeof(buf));
	if(count == -1)
	{
		perror("read");
		exit(1);
	}
	while(count)
	{
		//将读出的文件写到另一个文件中
		int sizeofwrite = write(fd2,buf,count);
		printf("write bytes %d\n",sizeofwrite);
		count = read(fd,buf,sizeof(buf));
	}

	close(fd);
	close(fd2);
}
void sys_02()//使用lseek 实现空洞文件
{
	int fd = open("Logan.txt",O_RDWR);
	if(fd == -1)
	{
		perror("open file");
		exit(1);
	}
	int sizeoffile = lseek(fd,0,SEEK_END);
	printf("Size fo file %d\n",sizeoffile);
	lseek(fd,1000,SEEK_END);
	printf("Size fo file %d\n",sizeoffile);
	write(fd,"A",1);
	close(fd);
}
//stat
//lstat
//access
//chmod
//chown
//truncate
//link
//symlink
//readlink
//unlink
//rename
//fcntl
//dup,dup2
//dentry,inode
//解决gcc编译过程中的c99语法报错问题
//alias gcc = 'gcc -std=gnu99'

void sys_03() //stat
{
	//穿透函数---(在获取软链接文件大小等内容时,链接到目标文件获取大小)
	//int stat(const char *path,struct stat *buf)
	//int fstat(int fd, struct stat *buf);
	//不穿透函数---(在获取软链接文件大小等内容时,直接就是本文件大小)
	//int lstat(const char *path, struct stat *buf)
	/*
	 * struct stat {
	 * dev_t st_dev; 	//文件设备编号
	 * ino_t st_ino; 	//节点
	 * mode_t st_mode;	//文件的类型和存储权限
	 * nlink_t st_nlink;	//链接到该文件的数目
	 * uid_t st_uid;	//用户ID
	 * gid_t st_gid;	//组ID
	 * dev_t st_rdev;	//(设备类型) 若此文件为设备文件,则其为设备编号
	 * off_t st_size;	//文件字节数(文件大小)
	 * blksize_t st_blksize;//块大小(文件系统的I/O缓冲区大小
	 * blkcnt_t st_blocks;  //块数
	 * time_t st_atime;     //最后一次访问时间
	 * time_t st_mtime;     //最后一次修改时间
	 * time_t st_ctime      //最后一次改变时间
	 * };
	 * */
	struct stat st;
	int fd = -1;
	fd = open("Logan.txt",O_RDWR);
	if(fd == -1)
	{
		perror("open file");
		exit(1);
	}
	fstat(fd,&st);	
	//获取文件大小
	printf("Size of file %d\n",st.st_size);
}
void sys_04() //access()
{

	//int access(const char *pathname,int mode);
	//测试指定文件是否拥有某种权限
	
	int ret = access("Logan.txt",W_OK);
	if(ret == -1)
	{
		perror("access");
		exit(1);
	}
	printf("you can write this file.\n");
}
//实现一个chmod 命令
void sys_05(int argc,char **argv) //chmod()
{
	//strtol(const char *nptr,char **endptr, int base); //**endptr 通常为NULL
	int ret = chmod(argv[2],strtol(argv[1],NULL,8)); //八进制
	if(argc < 3)
	{
		printf("Useage: ./a.out 755 filename");
	}
	if(ret == -1)
	{
		perror("Chmod");
		exit(1);
	}
	printf("Mode changed!\n");
	//strtol
}
void sys_06(int argc,char **argv) //chown()
{
	 /*
	  * int chown(const char *pathname, uid_t owner,gid_t group);
	  * int fchown(int fd,uid_t owner,gid_t group);
	  * int lchown(const char *pathname,uid_t owner,gid_t group);
	  * uid_t && gid_t 可通过 etc/passwd 获取
	  * 查看配置文件  man 5 passwd
	  * */
}
void sys_07() //truncate()
{
	/*
	 * int truncate(const char *path, off_t length);
	 * int ftruncate(int fd, off_t length);
	 * */
	int trun = truncate("Logan.txt",12);
	if(trun == -1)
	{
		perror("truncate");
		exit(1);
	}
	printf("OK!");

}
void sys_08()
{
	/*创建一个硬链接
	 *int link(const char *oldpath,const char *newpath);
	 *创建软链接
	 *syslink()
	 *读软链接对应的文件名,不是内容
	 *readlink()

	 *
	 *删除一个文件的目录项并减少它的链件数,若成功则返回0,否则返回1
	 *如果想通过这个函数来成功删除文件,你就必须拥有这个目录的可执行和写权限
	 *unlink()
	 * */
}
void sys_09()//rename() 更改名字函数
{
	//rename()
	//renameat(int olddirfd,const char *oldpath,int newdirfd,const char *newpath);
	
	//renameat2(int olddirfd ,const char *oldpath, int newdirfd, const char *newpath, unsigned int flags);
	int ret = rename("./Logan.txt","OK.txt");
	if (ret == -1)
	{
		perror("rename");
		exit(1);
	}
	printf("OK!");
}
void sys_10(int argc,char **argv) //目录操作函数
{
	//chdir()   改变目录 -- int chdir(const char *path);
	//getcwd()  获取路径
	//mkdir()   创建目录
	//rmdir()   删除空目录
	//opendir   打开一个目录 打开成功非0 失败返回 NULL
	//
	//readdir   读目录
	//struct dirent *readdir(DIR *dirp);
	//
	//返回值:
	//struct dirent
	//{
	//	ino_t dino;    //此目录进入点的inode
	//	ff_t  d_off;   //目录文件开头至此目录进入点的位移
	//	signed short int d_reclen; //d_name的长度,不包含NULL字符
	//	unsigned char d_type;	//d_name所指的文件类型
	//	har d_name[256];	//文件名
	//}
	//d_type
	//DT_BLK -块设备
	//DT_CHR -字符设备
	//DT_DIR -目录
	//DT_LNK -软链接
	//DT_FIFO -管道
	//DT_REG  -普通文件
	//DT_SOCK - 套接字
	//DT_UNKNOWN -未知
	//
	//-D_BSD_SOURCE 编译时添加的宏定义
	//
	//
	//closedir  关闭目录
	//
	char path[256] = {0};
	if(argc < 2)
	{
		printf("Useage: ./a.out path");
		exit(1);
	}
	int ret = chdir(argv[1]);
	if(ret == -1)
	{
		perror("chdir");
		exit(1);
	}
	getcwd(path, sizeof(path));
	printf("current path: %s\n",path);
}
//使用readdir函数来获取当前普通文件个数实例
int getFileNum(char *root)
{
	DIR* dir = NULL;
	dir = opendir(root);
	if(dir == NULL)
	{
		perror("opendir");
		exit(1);
	}
	//便利目录
	struct dirent* ptr = NULL;
	char path_name[1024] = {0};
	int total = 0;
	while( (ptr = readdir(dir)) )
	{
		//过滤. 和 ..
		if(strcmp(ptr->d_name,".") == 0 || strcmp(ptr->d_name,"..") == 0)
		{
			continue;
		}	
		//如果是目录
		if(ptr->d_type == DT_DIR)
		{
			//递归 读目录
			sprintf(path_name,"%s/%s",root,ptr->d_name);
			total += getFileNum(path_name);
		}	
		//如果是普通文件
		if(ptr->d_type == DT_REG)
		{
			total++;
		}
	}
	closedir(dir);
	return total;

}
void sys_11(int argc,char **argv)
{
	if(argc < 2)
	{
		printf("Usage:./a.out filepath\n");
		exit(1);
	}
	printf("Number of Curent file:%d\n",getFileNum(argv[1]));
}
void sys_12()
{
	/*文件描述符的复制
	 *
	 *dup(),dup2()
	 *dup()返回一个最小的未被占用的文件描述符号
	 *dup2() dup2(int odfd,int newfd);
	 *打开文件描述符前,若newfd已经存在先关闭newfd,然后再拷贝
	 *若oldfd与newfd是同一个文件描述符,则不会关闭newfd
	 *
	 * */
	int fd = open("Logan.txt",O_RDWR);
	if(fd == -1)
	{
		perror("open");
		exit(1);
	}
	printf("file open fd = %d\n",fd);	
	//找到进程文件描述表中 第一个 可用的文件描述符
	//将参数指定的文件复制到该描述符后,返回这个描述符
	int ret = dup(fd);
	if(ret == -1)
	{
		perror("dup");
		exit(1);
	}
	printf("dup fd = %d\n",ret);
	char* buf = "你是猴子派来的救兵吗?\n";
	char *buf_2 = "你大爷的! 我是程序猿!!\n";
	write(fd, buf,strlen(buf));
	write(ret, buf_2,strlen(buf_2));
	close(fd);
	close(ret);
}
void sys_13()
{
	//fcntl
	//
	//int fcntl(int fd, int cmd)
	//int fcntl(int fd, int cmd, long arg)  (目前使用)
	//int fcntl(int fd, int cmd, struct flock *lock)
	//
	//复制现有的文件描述符 F_DUPFD
	//获得/设置文件描述符标记 --cmd F_GETFD / F_SETFD
	//
	//获得/设置文件状态标记   --CMD 
	//  ***F——GETFL
	//只读打开:  O_RDONLY
	//只写打开:  O_WRONLY
	//读写打开:  O_RDWR
	//执行打开:  O_EXEC
	//搜索打开目录:  O_SEARCH
	//追加写:    A_PPEND
	//非阻塞模式: O_NONBLOCK
	//  ***F_SETFL
	//O_APPEND
	//O_NONBLOCK
	//
	//获得/设置异步I/O所有权 --cmd  F_GETOWN / F_SETOWN
	//获得/设置记录锁 --cmd F_GETLK / F_SETLK / F_SETLKW
	
	char *txt1 = "我是"
	char *txt2 = "Logan"
	int fd = open("Logan.txt",O_WRONLY);
	if(fd == -1)	
	{
		perror("open");
		exit(1);
	}
	if(write(fd,txt1,strlen(txt1)) == -1)
	{
		perror("write");
		eixt(1);
	}
	int flag = fcntl(fd, F_GETFL, 0);


}

int main(int argc,char **argv)
{
	//sys_01();
	//sys_02();
	//sys_03();
	//sys_04();
	//sys_05(argc,argv);
	//sys_07();
	//sys_09();
	//sys_10(argc,argv);
	//sys_11(argc,argv);
	sys_12();
	return 0;
}

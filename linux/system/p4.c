#include <fcntl.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <errno.h>

/*
#include <fcntl.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>

int open(const char *pathname, int flags);
int open(const char *pathname, int flags, mode_t mode);
int close(int fd);

open 函数有两个形式.其中 pathname 是我们要打开的文件名(包含路径名称,缺省是认为在
当前路径下面).flags 可以去下面的一个值或者是几个值的组合.
O_RDONLY:以只读的方式打开文件.
O_WRONLY:以只写的方式打开文件.
O_RDWR:以读写的方式打开文件.
O_APPEND:以追加的方式打开文件.
O_CREAT:创建一个文件.
O_EXEC:如果使用了 O_CREAT 而且文件已经存在,就会发生一个错误.
O_NOBLOCK:以非阻塞的方式打开一个文件.
O_TRUNC:如果文件已经存在,则删除文件的内容.
前面三个标志只能使用任意的一个.如果使用了 O_CREATE 标志,那么我们要使用 open 的第
二种形式.还要指定 mode 标志,用来表示文件的访问权限.mode 可以是以下情况的组合.
-----------------------------------------------------------------
S_IRUSR 用户可以读 S_IWUSR 用户可以写
S_IXUSR 用户可以执行 S_IRWXU 用户可以读写执行
-----------------------------------------------------------------
S_IRGRP 组可以读 S_IWGRP 组可以写
S_IXGRP 组可以执行 S_IRWXG 组可以读写执行
-----------------------------------------------------------------
S_IROTH 其他人可以读 S_IWOTH 其他人可以写
S_IXOTH 其他人可以执行 S_IRWXO 其他人可以读写执行
-----------------------------------------------------------------
S_ISUID 设置用户执行 ID S_ISGID 设置组的执行 ID
-----------------------------------------------------------------
我们也可以用数字来代表各个位的标志.Linux 总共用 5 个数字来表示文件的各种权限.
00000.第一位表示设置用户 ID.第二位表示设置组 ID,第三位表示用户自己的权限位,第四
[18 of 104]
Linux 操作系统 C 语言编程入门
位表示组的权限,最后一位表示其他人的权限.
每个数字可以取 1(执行权限),2(写权限),4(读权限),0(什么也没有)或者是这几个值的和
..
比如我们要创建一个用户读写执行,组没有权限,其他人读执行的文件.设置用户 ID 位那么
我们可以使用的模式是--1(设置用户 ID)0(组没有设置)7(1+2+4)0(没有权限,使用缺省)
5(1+4)即 10705:
open("temp",O_CREAT,10705);
如果我们打开文件成功,open 会返回一个文件描述符.我们以后对文件的所有操作就可以
对这个文件描述符进行操作了.

*/
#define BUFFER_SIZE 4096
int main(int argc, char **argv) {
	int from_fd, to_fd;	
	int bytes_read, bytes_write;
	char buffer[BUFFER_SIZE];
	char *ptr;
	if(argc != 3) {
		fprintf(stderr, "Usage: %s fromfile tofile\n\a", argv[0]);
		exit(1);
	}
	//打开源文件
	if(-1 == (from_fd = open(argv[1], O_RDONLY))) {
		fprintf(stderr, "Open %s Error: %s\n", argv[1], strerror(errno));
		exit(1);
	}
	//创建目的文件
	if(-1 == (to_fd = open(argv[2], O_WRONLY | O_CREAT, S_IRUSR | S_IWUSR))) {
		fprintf(stderr, "Open %s Error: %s\n", argv[2], strerror(errno));
		exit(1);
	}
	//拷贝文件
	while(bytes_read = read(from_fd, buffer, BUFFER_SIZE)) {
		if((bytes_read == -1) && (errno != EINTR)) break;
		else if(bytes_read > 0) {
			ptr = buffer;
			while(bytes_write = write(to_fd, ptr, bytes_read)) {
				if((bytes_write == -1) && (errno != EINTR)) break;
				else if(bytes_write == bytes_read) break;
				else if(bytes_write > 0) {
					ptr += bytes_write;
					bytes_read -= bytes_write;
				}
			}
		}
	}
	close(from_fd);
	close(to_fd);

	return 0;
}

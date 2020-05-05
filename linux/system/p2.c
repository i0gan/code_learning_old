#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <errno.h>
#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int main(int argv, char **argc) {

	pid_t pid;
	int status;
	printf("This will demostrate how to get child status\n");
	if(-1 == (pid = fork())) {
		printf("Fork error: %s\n", strerror(errno)); //与perror差不多
		exit(-1);
	}else if(pid == 0) { //代表是子进程
		int i;
		printf("I'm the child : %d\n", getpid());
		for(int i = 0; i < 1000000; ++i) { //进行大量计算
			sin(i);
		}
		sleep(50);
		i = 4;
		printf("I exit with %d\n", i);
		exit(i); //以 错误号为4退出
	}

	/*
		#include <sys/types.h>
		#include <sys/wait.h>
		pid_t wait(int *stat_loc);
		pid_t waitpid(pid_t pid, int *stat_loc, int options);

wait 系统调用会使父进程阻塞直到一个子进程结束或者是父进程接受到了一个信号.如果
没有父进程没有子进程或者他的子进程已经结束了 wait 回立即返回.成功时(因一个子进
程结束)wait 将返回子进程的 ID,否则返回-1,并设置全局变量 errno.stat_loc 是子进程的
退出状态.子进程调用 exit,_exit 或者是 return 来设置这个值. 为了得到这个值 Linux 定
义了几个宏来测试这个返回值.
WIFEXITED:判断子进程退出值是非 0
WEXITSTATUS:判断子进程的退出值(当子进程退出时非 0).
WIFSIGNALED:子进程由于有没有获得的信号而退出.
WTERMSIG:子进程没有获得的信号号(在 WIFSIGNALED 为真时才有意义).
waitpid 等待指定的子进程直到子进程返回.如果 pid 为正值则等待指定的进程(pid).如果
为 0 则等待任何一个组 ID 和调用者的组 ID 相同的进程.为-1 时等同于 wait 调用.小于-1 时等
待任何一个组 ID 等于 pid 绝对值的进程. stat_loc 和 wait 的意义一样. options 可以决定
父 进 程 的 状 态 . 可 以 取 两 个 值 WNOHANG : 父 进 程 立 即 返 回 当 没 有 子 进 程 存 在 时 .
WUNTACHE
D:当子进程结束时 waitpid 返回,但是子进程的退出状态不可得到.

*/

	while((-1 == (pid = wait(&status))) & (errno == EINTR)); //父进程阻塞,直到子进程结束
	if(-1 == pid) {
		printf("Wait error: %s\n", strerror(errno));
	}else if(!status) {
		printf("Child %d terminated normally return status is zero\n");
	}else if(WIFEXITED(status)) {
		printf("Child %d terminated normally return status is %d\n",
		pid, WEXITSTATUS(status));
	}else if(WIFSIGNALED(status)) { //子进程是以信号方式退出
		printf("Child %d terminated due to signal %d\n",
		pid, WTERMSIG(status));
	} 

	return 0;
}

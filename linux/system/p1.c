#include <unistd.h>
#include <stdio.h>
#include <pwd.h>


int main(void) {
/*
	#include <unistd.h>
	pid_t getpid(void);  //获取当前pid
	pid_t getppid(void); //获取父进程pid
*/
	printf("用户pid: %d\n", getpid());	
	printf("父子进程pid: %d\n", getppid());	

/*
	#include <unistd.h>
	#include <sys/types.h>
	uid_t getuid(void); //获取当前用户uid
	uid_t geteuid(void);//获取当前进程有效uid
	gid_t getgid(void); //获取当前用户的gid
	gid_t getegid(void);//获取当前进程有效gid
*/

	printf("用户uid: %d\n", getuid());	
	printf("进程有效uid: %d\n", geteuid());	 //euid(Effective user id)
	printf("用户gid: %d\n", getgid());	
	printf("进程有效gid: %d\n", getegid());	

/*
	#include <pwd.h>	
	#include <sys/types.h>
	#include <unistd.h>

	struct passwd *info {
		char *pw_name; //登录名称
		char *pw_passwd; //登录口令
		uid_t pw_uid; //用户id
		gid_t pw_gid; //用户组id
		char *pw_gecos; //用户真名
		char *pw_dir; //用户目录
		char *pw_shell; //用户shell
	};

	struct passwd *getpwuid(uid_t uid);
*/
	
	struct passwd *info = NULL;
	info = getpwuid(getuid());
	printf("%p\n", getpwuid(getuid()));
	if(info != NULL) {
		printf("Name  : %s\n", info->pw_name);
		printf("Passwd: %s\n", info->pw_passwd);
		printf("Uid   : %d\n", info->pw_uid);
		printf("Gid   : %d\n", info->pw_gid);
		printf("Real Name: %s\n", info->pw_gecos);
		printf("Home dir : %s\n", info->pw_dir);
		printf("Shell    : %s\n", info->pw_shell);
	}

	return 0;
}

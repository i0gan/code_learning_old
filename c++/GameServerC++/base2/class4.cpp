#include <iostream>
#include <memory>

static void versionOne();
static void versionTwo();

using namespace std;

int main(void) {

	versionOne();
	versionTwo();
	versionThree();
	return EXIT_SUCCESS;
}
void versionOne() {
	//c语言方式开辟内存
	int *ageC = (int*) malloc(sizeof(int));
	if(argC) {
		free(ageC);
	}
	char *c = (char*) malloc(100);
	free(c);

	//c++ 开辟内存方式
	int *age = new int(25);
	int *height = new int(160);
	//缺陷,容易free 或 delete
}

void versionTow() {
	//智能指针
	std::shared_ptr<int> age(new int(28));
	std::shared_ptr<int> height(new int(160));

	std::cout << "VersionTwo: you age is " << *age << ", and your height is "
		<< *height << std::endl;
	//不需要做任何事情, 内存会自动的释放掉
	//基本上,不会造成内存泄露问题
}

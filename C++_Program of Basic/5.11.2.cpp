#include <iostream>
#include <vector>
using namespace std;
/*
使用vector<T>容器 
*/
int main()
{
	vector<int> vec(5 , 2); //或者vector<int> vec {2,2,2,2,2} 但这是矢量容器的创建方式，与正常容器相比 
	int total = 0;			//它们在容器扩张方面有所不同 
	for(int i = 0 ; i <= vec.size() ; ++i)
	{
		total += vec.at(i);
	}
	cout << total << endl;
}
/*
注意：本代码会报错，因为当i = vec.size()时
检查机制at()会检测到i的值已经超出元素个数最大值，超出了1
运行后会在命令提示符面板中出现如下报错： 
terminate called after throwing an instance of 'std::out_of_range'
  what():  vector::_M_range_check: __n (which is 5) >= this->size() (which is 5) 
*/

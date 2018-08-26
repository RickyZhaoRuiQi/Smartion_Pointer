#include "my_auto_ptr.h"
#include "my_unique_ptr.h"
#include "my_shared_ptr.h"
#include <iostream>
#include <string>
using namespace std;

class test
{
	public:
		test()
		{
			cout<<"test create"<<endl;
		}
		~test()
		{
			cout<<"test destroy"<<endl;
		}
};

int main()
{
	/* auto_ptr
	my_auto_ptr<string> p1(new string("zhang rui is my girl"));
	my_auto_ptr<string> p2;
	p2 = p1;
	
	cout<<p2->c_str()<<endl;
	cout<<p1->c_str()<<endl;
	cout<<"process will end"<<endl;
	*/
	
	/* unique_ptr
	my_unique_ptr<string> p1(new string("zhangrui is my girl"));
	my_unique_ptr<string> p2(p1);
	cout<<*p1<<endl;
	*/

	my_shared_ptr<string> p1(new string("zhangrui is my girl"));
	my_shared_ptr<string> p2(p1);
	my_shared_ptr<string> p3;
	p3 = p2;

	cout<<*p1<<" count:"<<p1.use_count()<<endl;
	cout<<*p2<<" count:"<<p2.use_count()<<endl;
	cout<<*p3<<" count:"<<p3.use_count()<<endl;

	return 0;
}

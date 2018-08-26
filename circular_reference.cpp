#include <iostream>
#include <memory>
using namespace std;

struct Node
{
	shared_ptr<Node> pre;
	shared_ptr<Node> next;
	~Node()
	{
		cout<<"Node ~Node() call:"<<this<<endl;
	}
	int data;
};

struct Node_op		//使用弱引用解决循环引用
{
	weak_ptr<Node_op> pre;		//shared_ptr	weak_ptr			总之打破相互的依赖关系，即——析构我必要条件是析构你，析构你
	weak_ptr<Node_op> next;		//weak_ptr		shared_ptr			的必要条件是析构我
	~Node_op()
	{
		cout<<"Node_op ~Node_op() call:"<<this<<endl;
	}
};

int main()
{
	/* 循环引用实例
	shared_ptr<Node> node1(new Node);
	shared_ptr<Node> node2(new Node);

	node1->next = node2;				//第一个节点由 node1和node2的pre指向
	node2->pre = node1;					//第二个节点由 node2和node1的next指向

	cout<<"node1 引用计数："<<node1.use_count()<<endl;
	cout<<"node2 引用计数："<<node2.use_count()<<endl;
	*/
	shared_ptr<Node_op> node1(new Node_op);
	shared_ptr<Node_op> node2(new Node_op);
	node1->next = node2;
	node2->pre = node1;

	cout<<"node1 引用计数："<<node1.use_count()<<endl;
	cout<<"node2 引用计数："<<node2.use_count()<<endl;
	return 0;
}

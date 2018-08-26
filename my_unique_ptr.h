#ifndef MY_UNIQUE_PTR_H_
#define MY_UNIQUE_PTR_H_

template<typename T>
class my_unique_ptr  //前身是scoped_pt，实现粗暴—>禁止转移-->独占资源（只允许一个指针管理资源)
{
	public:
		my_unique_ptr(T *p = nullptr)
			:ptr(p){}
	
		T& operator*() const
		{
			return *ptr;
		}

		T* operator->()
		{
			return ptr;
		}

		T* get()
		{
			return ptr;
		}

		~my_unique_ptr()
		{
			if(ptr)
			{
			  delete ptr;
			  ptr = nullptr;
			}
		}

	private:
		my_unique_ptr(my_unique_ptr & );	//禁止拷贝构造
		my_unique_ptr & operator=(my_unique_ptr & ); //禁止赋值
		T *ptr;
};

#endif

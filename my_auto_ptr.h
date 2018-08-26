#ifndef MY_AUTO_PTR_H_
#define MY_AUTO_PTR_H_

template<typename T>
class my_auto_ptr //采用资源的转移方法管理内存，在它的拷贝构造和赋值运算符引起会出现问题
{
	public:
		my_auto_ptr(T *p = nullptr)
			:ptr(p){}

		my_auto_ptr(my_auto_ptr & sp)
			:ptr(sp.ptr)
		{
			sp.ptr = nullptr;
		}

		my_auto_ptr & operator=(my_auto_ptr & sp)
		{
			if(this != &sp)
			{
				if(sp.ptr)
				  delete ptr;
				ptr = sp.ptr;
				sp.ptr = nullptr;
			}
			return *this;
		}

		T& operator*() const
		{
			return *ptr;
		}

		T* operator->() const
		{
			return ptr;
		}

		T* get()
		{
			return ptr;
		}

		~my_auto_ptr()
		{
			if(ptr)
			{
				delete ptr;
				ptr = nullptr;
			}
		}

	private:
		T *ptr;
};

#endif

#ifndef MY_SHARED_PTR_
#define MY_SHARED_PTR_

template<typename T>
class my_shared_ptr
{
	public:
		my_shared_ptr(T *p = nullptr)
			:ptr(p),count(nullptr)
		{
			if(ptr)
			  count = new int(1);
		}

		my_shared_ptr(my_shared_ptr & sp)
			:ptr(sp.ptr),count(sp.count)
		{
			if(count)
			  ++*count;
		}

		my_shared_ptr & operator=(my_shared_ptr & sp)
		{
			if(ptr == sp.ptr)
			  return *this;

			if(ptr)
			{
				if(0 == --*count)
				{
					delete count;
					count = nullptr;
					delete ptr;
					ptr = nullptr;
				}
			}
			ptr = sp.ptr;
			if(sp.count)
				count = &(++*sp.count);
			return *this;
		}

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

		int use_count()
		{
			return *count;
		}

		bool unique()
		{
			return *count == 1;
		}

		~my_shared_ptr()
		{
			if(ptr && 0 == --*count)
			{
				delete count;
				count = nullptr;
				delete ptr;
				ptr = nullptr;
			}
		}

	private:
		T *ptr;
		int *count;
};

#endif

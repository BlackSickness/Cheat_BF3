#ifndef _CLASST_H
#define _CLASST_H

namespace fb
{

template <typename T>
	class WeakPtr
	{
	private:
		T** m_ptr;

	public:
		T* GetData()
		{
			if(m_ptr == NULL)
				return NULL;

			if(*m_ptr == NULL)
				return NULL;

			return (T*)((DWORD)(*m_ptr) - offsetof(T, m_weakTokenHolder));
		}
	};

	template <typename T>
	class Array
	{
	private:
		T* m_firstElement;

	public:
		T At(INT nIndex)
		{
			if(m_firstElement == NULL)
				return NULL;

			return *(T*)((DWORD)m_firstElement + (nIndex * sizeof(T)));
		};

		T operator [](INT index) { return At(index); }
	};

	template <typename T>
	class RefArray
	{
	private:
		T** m_array;

	public:
		T* At(INT nIndex)
		{
			if(m_array == NULL)
				return NULL;

			return *(T**)((DWORD)m_array + (nIndex * 4));
		}

		T* operator [](INT index) { return At(index); }
	};

	template <typename T>
	class RelocArray
	{
	private:
		UINT m_count;
		T* m_data;

	public:
		UINT Size() { return m_count; }
		T At(INT index) { return *(T*)((DWORD)m_data + (index * sizeof(T))); }
		T operator[](INT index) { return At(index); }
	};


	template <typename T>
	class Tuple2
	{
	public:
		T Element1;
		T Element2;

	public:
		Tuple2(T _Element1, T _Element2)
		{
			Element1=_Element1;
			Element2=_Element2;
		}
	};

	template< typename T > 
	struct SmartRef
	{
		T* m_ptr;
	}; //sizeof() == 0x4

	template< class T > 
	struct SmartPtr
	{
		T* m_ptr;
	}; //sizeof() == 0x4




};

#endif
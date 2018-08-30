#ifndef _STRING_H
#define _STRING_H

namespace fb
{

	class String
	{
	private:
		LPSTR m_string;
	public:
		//char * m_chars;                     // 0x0
		LPSTR GetString() { return m_string; }
		operator LPSTR() { return m_string; }
	};

		class Noncopyable // Inherited class at offset 0x0
	{										
	}; // fb::Noncopyable


	class Buffer :public Noncopyable // Inherited class at offset 0x0
	{
		enum Caps
		{

			 CanRead,                     // constant 0x1
			 CanWrite,                     // constant 0x2
			 CanSeek                     // constant 0x4

		}; // Caps
		const int m_caps;                     // this+0x8
		__int64 m_bufferSize;                     // this+0x10
		void * m_nativeHandle;                     // this+0x18

		virtual void * __vecDelDtor(unsigned int);	// V: 0x0
		virtual int readEx(void *, __int64);	// V: 0x4
		virtual __int64 getAvailableBytes();	// V: 0x8
		virtual void skip(__int64);	// V: 0xC
		virtual int writeEx(const void *, __int64);	// V: 0x10
		virtual void setPosition(__int64);	// V: 0x14
		virtual __int64 getPosition();	// V: 0x18
		virtual void flush();	// V: 0x1C
		virtual const char * getIdentifier();	// V: 0x20
		virtual void setIdentifier(const char *);	// V: 0x24
			

	}; // fb::Buffer

	class StringOutBuffer :public Buffer 
	{

		/*class fb::ExtendableStringBuilder<128>*/void* m_string;                     // this+0x20
		virtual void * __vecDelDtor(unsigned int);	// V: 0x0

	}; // fb::StringOutBuffer

	class OutAsciiStream 
		:public Noncopyable // Inherited class at offset 0x0
	{

		virtual void * __vecDelDtor(unsigned int);	// V: 0x0
		Buffer & m_buffer;                     // this+0x4
		const char * m_floatFormat;                     // this+0x8
		const char * m_doubleFormat;                     // this+0xC
		const char * m_intFormat;                     // this+0x10
		const char * m_uintFormat;                     // this+0x14
		

	}; // fb::OutAsciiStream

	class StringStream :public OutAsciiStream // Inherited class at offset 0x0
	{

		virtual void * __vecDelDtor(unsigned int);	// V: 0x0
		StringOutBuffer m_buffer;                     // this+0x18
		

	}; // fb::StringStream

class StringBuilderBaseImpl
	{

		char * m_buffer;                     // this+0x0
		char * m_pos;                     // this+0x4
		char * m_max;                     // this+0x8
				
	}; // fb::StringBuilderBaseImpl<char>

	class StringBuilderBase
		:public  StringBuilderBaseImpl// Inherited class at offset 0x0
	{

	}; // fb::StringBuilderBase


};

#endif
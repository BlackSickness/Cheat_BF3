#ifndef _BITARRAY_H
#define _BITARRAY_H


namespace fb
{

	class BitArray
	{
	public:
		LPVOID vftable;					// 0x00
		LPINT m_bits;					// 0x04
		DWORD m_externalBufferSize;		// 0x08
		DWORD m_bitCount;				// 0x0C
		DWORD m_wordCount;				// 0x10
	}; // 0x14


};

#endif
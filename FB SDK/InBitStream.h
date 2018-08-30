#ifndef _INBITSTREAM_H
#define _INBITSTREAM_H

namespace fb
{

class InBitStream
	{

		const unsigned char * m_buffer;                     // this+0x0
		unsigned int m_bufferBitSize;                     // this+0x4
		const unsigned int * m_bufferEnd;                     // this+0x8
		unsigned int m_streamChunk;                     // this+0xC
		const unsigned int * m_streamChunkReadPtr;                     // this+0x10
		unsigned int m_streamBitReadPosition;                     // this+0x14
		bool m_overflow;                     // this+0x18
	
	}; // fb::InBitStream



};

#endif
#ifndef _OUTBITSTREAM_H
#define _OUTBITSTREAM_H

namespace fb
{
	class OutBitStream
	{

			unsigned char * m_buffer;                     // this+0x0
		unsigned int m_bufferBitSize;                     // this+0x4
		unsigned int * m_bufferEnd;                     // this+0x8
		unsigned int m_streamChunk;                     // this+0xC
		unsigned int * m_streamChunkWritePtr;                     // this+0x10
		unsigned int m_streamBitWritePosition;                     // this+0x14
		bool m_overflow;                     // this+0x18, len(0x1)
		bool m_isFlushed;                     // this+0x19, len(0x1)
	
	}; // fb::OutBitStream
};

#endif
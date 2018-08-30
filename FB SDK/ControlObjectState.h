#ifndef _CONTROLOBJECTDATA_H
#define _CONTROLOBJECTDATA_H

namespace fb
{

		
	
	class ControlObjectState // Inherited class at offset 0x0
		:public fb::network::IControlObjectState // Inherited class at offset 0x0
	{

	

		unsigned char m_originalBuffer[0x1000];                     // this+0x4
		unsigned char * m_buffer;                     // this+0x1004
		unsigned int * m_startWritePosition;                     // this+0x1008
		/*class fb::BitStream*/void* m_stream;                     // this+0x1010
						
	}; 



};

#endif
#ifndef _MESSAGELISTENER_H
#define _MESSAGELISTENER_H

namespace fb
{
	class MaterialContainerPair
		: public DataContainer			// 0x00
	{
	public:
		DWORD m_flagsAndIndex;			// 0x08
		char m_physicsPropertyIndex;	// 0x0C
		char m_physicsMaterialIndex;	// 0x0D
		PAD(0x2);						// 0x0E
		__forceinline bool isPenetrable()
		{
			return m_flagsAndIndex & 0x80000000;
		};

		__forceinline bool isSeeTrough()
		{
			return m_flagsAndIndex & 0x20000000;
		};


		__forceinline bool isClientDestructible()
		{
			return m_flagsAndIndex & 0x40000000;
		};

		__forceinline bool isBashable(void)
		{
			return m_flagsAndIndex & MfBashable;
		};


	    __forceinline bool NoCollisionResponse(void)
		{
			return m_flagsAndIndex & MfNoCollisionResponse;
		};

		__forceinline bool NoCollisionResponseCombined(void)
		{
			return m_flagsAndIndex & MfNoCollisionResponseCombined;
		}
		
	}; // 0x10

};

#endif
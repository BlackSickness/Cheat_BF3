//////////////////////////////////////////////////////////////////////////
// Havok classes
// 
// 
//////////////////////////////////////////////////////////////////////////

#include <Windows.h>
#include <d3d11.h>
#include <d3dx11.h>

typedef D3DXVECTOR4 hkVector4;

template <class T>
class hkArray
{
public:
	T** m_data;
	INT m_size;
	INT m_capacityAndFlags;
};

class hkBaseObject
{
public:
	LPVOID vftable;		// 0x00
}; // 0x04

class hkReferencedObject
	: public hkBaseObject		// 0x00
{
public:
	WORD m_memSizeAndFlags;		// 0x04
	SHORT m_referencedCount;	// 0x06
}; // 0x08

class hkpEntityListener
{
public:
	LPVOID vftable;		// 0x00
}; // 0x04

class hkpPhantomListener
{
public:
	LPVOID vftable;		// 0x00
}; // 0x04

class hkpCharacterProxy
	: public hkReferencedObject,					// 0x00
	public hkpEntityListener,						// 0x08
	public hkpPhantomListener						// 0x0C
{
public:
	hkArray<DWORD> m_manifold;						// 0x10 hkpRootCdPoint
	hkArray<DWORD> m_bodies;						// 0x1C hkpRigidBody*
	hkArray<DWORD> m_phantoms;						// 0x28 hkpPhantom*
	hkArray<DWORD> m_overlappingTriggerVolumes;		// 0x34 hkpTriggerVolume*
	hkVector4 m_velocity;							// 0x40
	hkVector4 m_oldDisplacement;					// 0x50
	DWORD m_shapePhantom;							// 0x60
	FLOAT m_dynamicFriction;						// 0x64
	FLOAT m_staticFriction;							// 0x68
	BYTE pad_004[0x4];								// 0x6C
	hkVector4 m_up;									// 0x70
	FLOAT m_extraUpStaticFriction;					// 0x80
	FLOAT m_extraDownStaticFriction;				// 0x84
	FLOAT m_keepDistance;							// 0x88
	FLOAT m_keepContactTolerence;					// 0x8C
	FLOAT m_contactAngleSensitivity;				// 0x90
	INT m_userPlanes;								// 0x94
	FLOAT m_maxCharacterSpeedForSolver;				// 0x98
	FLOAT m_characterStrength;						// 0x9C
	FLOAT m_characterMass;							// 0xA0
	hkArray<DWORD> m_listeners;						// 0xA4 hkpCharacterProxyListener*
	FLOAT m_maxSlopeCosine;							// 0xB0
	FLOAT m_penetrationRecoverySpeed;				// 0xB4
	INT m_maxCastIterations;						// 0xB8
	INT m_refreshManifoldInCheckSupport;			// 0xBC
}; // 0xC0

class hkpCharacterContext
	: public hkReferencedObject			// 0x00
{
public:
	INT m_characterType;				// 0x08
	DWORD m_stateManager;				// 0x0C hkpCharacterStateManager
	INT m_currentState;					// 0x10
	INT m_filterEnable;					// 0x14
	FLOAT m_maxLinearAcceleration;		// 0x18
	FLOAT m_maxLinearVelocity;			// 0x1C
	FLOAT m_gain;						// 0x20
}; // 0x24

class hkpShape
	: public hkReferencedObject		// 0x00
{
public:
	DWORD m_userData;				// 0x08
	INT m_type;						// 0x0C
}; // 0x10
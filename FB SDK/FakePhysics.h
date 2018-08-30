#ifndef _FakePhysics_H
#define _FakePhysics_H
#include "FB SDK/Frostbite_Classes.h"

namespace fb
{
	class FakePhysicsData
		:public DataContainer // Inherited class at offset 0x0
	{

		

		CtrRefBase m_childFakePhysics;                     // 0x10
		float m_startSpeed;                     // 0x14
		float m_gravityModifier;                     // 0x18
		float m_startDampening;                     // 0x1C
		float m_endDampening;                     // 0x20
		float m_minSpeed;                     // 0x24
		float m_maxSpeed;                     // 0x28
		float m_mass;                     // 0x2C
		virtual void * __vecDelDtor(unsigned int);	// V: 0x4

	}; // fb::FakePhysicsData
	class FakePhysics
	{

		class State
		{

			bool m_valid;                     // 0x0
			int m_reuseVelocityDifference;                     // 0x4
			LinearTransform m_transform;                     // 0x10
			Vec3 m_velocity;                     // 0x50
			Vec3 m_velocityDifference;                     // 0x60
			float m_deltaTime;                     // 0x70

		}; // State

		virtual void onImpulse(const struct fb::Vec3 &, const struct fb::Vec3 &);	// V: 0x14
		virtual const struct Vec3 & measurePoint();	// V: 0x18
		virtual void setVelocity(float);	// V: 0x1C
		virtual float velocity();	// V: 0x20
		virtual bool isSleeping();	// V: 0x24
		virtual void localUpdate(float, const struct fb::LinearTransform &, const struct fb::Vec3 &, const struct fb::Vec3 *, const struct fb::Vec3 *, struct fb::Vec3 *, struct fb::LinearTransform &, const struct fb::LinearTransform *);	// V: 0x38
		FakePhysicsData & m_data;                     // 0x10
		bool m_started;                     // 0x14
		FakePhysics * m_child;                     // 0x18
		FakePhysics::State m_lastState;                     // 0x20
		virtual void * __vecDelDtor(unsigned int);	// V: 0x0

	}; // fb::FakePhysics

	class BoneFakePhysicsData
		: public DataContainer
	{
		public:
		

		CtrRefBase m_fakePhysics;                     // 0x10
		String m_boneName;                     // 0x14
		int m_boneId;                     // 0x18
		virtual void * __vecDelDtor(unsigned int);	// V: 0x4

	}; // fb::BoneFakePhysicsData

	class BoneFakePhysics
	{
	public:
		BoneFakePhysicsData & m_data;                     // 0x10
		PhysicsEntityBase * m_physicsEntity;                     // 0x14
		FakePhysics * m_fakePhysics;                     // 0x18
		LinearTransform m_currentTransform;                     // 0x20
		Vec3 m_outputForce;                     // 0x60
		virtual void * __vecDelDtor(unsigned int);	// V: 0x0

	}; // fb::BoneFakePhysics


};

#endif
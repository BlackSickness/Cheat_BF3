#ifndef _Vehicle_H
#define _Vehicle_H

#include "VehicleNs.h"
#include "ClientChassisComponentReplicationState.h"
#include "ClientChassisComponentSimulation.h"
#include "ClientPartComponent.h"


namespace fb
{


	class ChassisComponent
	{
	public:
		PAD(0x10);								// 0x04
		Vec3 m_initialWorldPosition;			// 0x10
		PhysicsEntity* m_physics;				// 0x20
		vehicle::IVehicle * m_vehiclePhysics;   // this+0x24
		vehicle::IGearbox * m_gearboxPhysics;   // this+0x28
		FLOAT m_timeDisabledByEMP;				// 0x2C
		LinearTransform m_localTransform;		// 0x30
		DWORD m_inputModifierIndex;				// 0x70
		DWORD m_playerCount;					// 0x74
		FLOAT m_inputSwayTimer;					// 0x78
		FLOAT m_inputSwayYaw;					// 0x7C
		FLOAT m_inputSwayPitch;					// 0x80
		FLOAT m_inputSwayRoll;					// 0x84
		DWORD m_landingGears;					// 0x88
	}; // 0x8C

	class ClientChassisComponent
		: public ClientPartComponent,							// 0x00
		public ChassisComponent									// 0x50
	{
	public:
		class EffectInfo
		{
		public:
			Vec3 position;			// 0x00
			Vec3 normal;			// 0x10
			Asset* effectAsset;		// 0x20
		}; // 0x24

		PAD(0x4);												// 0xDC
		AxisAlignedBox m_cachedBox;								// 0xE0
		Vec3 m_linearVelocity;									// 0x100
		Vec3 m_angularVelocity;									// 0x110
		Vec3 m_prevLinearVelocity;								// 0x120
		DWORD m_chassisEffectHandle;							// 0x130
		DWORD m_effectCount;									// 0x134
		PAD(0x8);												// 0x138
		EffectInfo m_effects;									// 0x140
		PAD(0xEC);												// 0x164
		eastl::vector<UINT> m_waterEffectHandles;				// 0x250
		eastl::vector<UINT> m_waterStreakEffectHandles;			// 0x260
		ClientChassisComponentSimulation* m_controller;			// 0x270
		ClientChassisComponentReplication* m_replicatedBody;	// 0x274
		ClientChassisComponentPrediction* m_predictedBody;		// 0x278
		DWORD m_updater;										// 0x27C ClientChassisComponent::PredictionUpdater
		DWORD m_repUpdater;										// 0x280 ClientChassisComponent::ReplicationUpdater
		MaterialContainerPair* m_groundMaterial;				// 0x284
		DWORD m_speedField;										// 0x28C
		FLOAT m_gForce;											// 0x290
	}; // 0x164


	class FloatPhysicsState
	{

		virtual void set(const struct fb::FloatPhysicsState &);	// V: 0x0

	}; // fb::FloatPhysicsState

	class FloatPhysics
	{

		enum FloatPhysicsType
		{

			FPTBox,                   // constant 0x0
			FPTHull                     // constant 0x1

		}; // FloatPhysicsType

		enum StateLod
		{

			LodUncompressed,                     // constant 0x0
			LodPrediction,                     // constant 0x1
			LodReplication,                     // constant 0x2
			LodSavePrediction,                     // constant 0x3
			LodCount                     // constant 0x4

		}; // StateLod

		virtual void actionUpdate(const float, const class fb::vehicle::Input *);	// V: 0x4
		virtual enum fb::FloatPhysics::FloatPhysicsType type();	// V: 0x8
		virtual void reducePhysicsHealth(float);	// V: 0xC
		virtual void reducePhysicsHealth(int, int, float);	// V: 0x10
		virtual float totalPhysicsHealth();	// V: 0x14
		virtual bool getWaterLineEmitterRegistered();	// V: 0x28
		virtual void registerWaterLineEmitters(const class eastl::vector<fb::Vec3,fb::eastl_arena_allocator> &);	// V: 0x2C
		virtual bool getWaterLineEmitterInfo(class eastl::vector<fb::Vec3,fb::eastl_arena_allocator> &, class eastl::vector<fb::Vec3,fb::eastl_arena_allocator> &);	// V: 0x30
		virtual bool getWaterStreakEmitterRegistered();	// V: 0x34
		virtual void registerWaterStreakEmitters(const class eastl::vector<fb::Vec3,fb::eastl_arena_allocator> &);	// V: 0x38
		virtual bool getWaterStreakEmitterInfo(class eastl::vector<fb::Vec3,fb::eastl_arena_allocator> &, class eastl::vector<fb::Vec3,fb::eastl_arena_allocator> &);	// V: 0x3C
		virtual const class fb::FloatPhysicsData * data();	// V: 0x48
		virtual struct fb::FloatPhysicsState * createState(void *, unsigned int, unsigned int &);	// V: 0x4C
		virtual struct fb::FloatPhysicsState * createState();	// V: 0x50
		virtual void setState(const struct fb::FloatPhysicsState &);	// V: 0x54
		virtual void getState(struct fb::FloatPhysicsState &);	// V: 0x58
		virtual void stateToStream(/*class fb::IBitStreamWrite &*/void*, const struct fb::FloatPhysicsState &, const struct fb::FloatPhysicsState *, enum fb::FloatPhysics::StateLod);	// V: 0x5C
		virtual void streamToState(/*class fb::IBitStreamRead &*/void*, struct fb::FloatPhysicsState &, const struct fb::FloatPhysicsState *, enum fb::FloatPhysics::StateLod);	// V: 0x60
		class fb::PhysicsEntity * m_body;                     // this+0x4
		/*		class eastl::vector<fb::StoredForce,fb::eastl_arena_allocator>*/void* m_delayedForces;                     // this+0x8
		/*		class eastl::vector<fb::StoredForce,fb::eastl_arena_allocator>*/void* m_delayedTorques;                     // this+0x18
		class SleepParams
		{

			float minHighFrequencyTransScale;                     // this+0x0
			float minHighFrequencyRotScale;                     // this+0x4
			float minLowFrequencyTransScale;                     // this+0x8
			float minLowFrequencyRotScale;                     // this+0xC

		}; // SleepParams

		struct fb::FloatPhysics::SleepParams m_storedSleepParams;                     // this+0x28
		float m_storedFriction;                     // this+0x38
		bool m_isInWater;                     // this+0x3C
		float m_waterHeight;                     // this+0x40
		virtual void * __vecDelDtor(unsigned int);	// V: 0x0

	}; // fb::FloatPhysics

	class ClientChassisComponentReplication
		: public ClientChassisComponentSimulation		// 0x00
	{
	public:
		class BodyInfo
		{
		public:
			//	LPVOID vftable;		// 0x00
			virtual vehicle::IVehicle * vehicle();	// V: 0x0
			virtual void processUpdateRequired();	// V: 0x4
			virtual ClientChassisComponent & object();	// V: 0x8
		}; // 0x04

		class Interpolator
			: public network::Interpolator<ClientChassisComponentReplicationState>		// 0x00
		{
		public:
			ClientChassisComponentReplication* m_replication;							// 0x40
		}; // 0x44

		BodyInfo* m_info;								// 0x04
		Interpolator* m_interpolationObject;			// 0x08
		FLOAT m_interpolationFactor;					// 0x0C
		INT m_hasLowVelocityTimer;						// 0x10
		FLOAT m_aheadOfTime;							// 0x14
	}; // 0x18

	class RigidBodyState
	{
	public:
		Vec3 m_orientation;			// 0x00
		Vec3 m_position;			// 0x10
		Vec3 m_linearVelocity;		// 0x20
		Vec3 m_angularVelocity;		// 0x30
		CHAR m_isSleeping;			// 0x40
		PAD(0x3);					// 0x41
	}; // 0x44

	class ClientChassisComponentPrediction
		: public ClientChassisComponentSimulation		// 0x00
	{
	public:
		class State
		{
		public:
			RigidBodyState rigidBodyState;			// 0x00
			PAD(0xC);								// 0x44
			FloatPhysicsState floatPhysicsState;	// 0x50
			DWORD vehicleState;						// 0x54 vehicle::VehicleState
			DWORD gearboxState;						// 0x58 vehicle::GearboxState
			DWORD aerodynamicPhysicsState;			// 0x5C vehicle::AeroDynamicPhysicsState
		}; // 0x60

		class CorrectionInterpolationDelta
		{
		public:
			Vec3 deltaTrans;			// 0x00
			Vec3 deltaOrientation;		// 0x10
		}; // 0x20

		class Updater
		{
		public:
			LPVOID vftable;		// 0x00
		}; // 0x04

		State* m_currentState;							// 0x04
		PAD(0x8);										// 0x08
		State m_predictionState;						// 0x10
		State m_correctionState;						// 0x70
		RigidBodyState m_prevRigidBodyState;			// 0xD0
		PAD(0xC);
		CorrectionInterpolationDelta m_correctionInterpolationDelta;
		CorrectionInterpolationDelta m_frameCorrectionDelta;
		FLOAT m_correctionInterpolationTimer;
		FLOAT m_correctionInterpolationTime;
		FLOAT m_frameInterpolationFactor;
		Updater* m_updater;
	};

	class VehicleEntityHealth
	{
	public:
		class VehicleEntityHealthZone
		{
		public:
			VehicleHealthZoneData* data;		// 0x00
			FLOAT health;						// 0x04
			FLOAT shieldHealth;					// 0x08
			CHAR useProtectedShields;			// 0x0C
			PAD(0x3);							// 0x0D
		}; // 0x10

		LPVOID vftable;											// 0x00
		eastl::vector<Component*> m_components;					// 0x04
		eastl::vector<VehicleEntityHealthZone> m_healthZones;	// 0x14
	}; // 0x24

	class VehicleHealthZoneData
	{
	public:
		FLOAT m_maxHealth;					// 0x00
		FLOAT m_maxShieldHealth;			// 0x04
		FLOAT m_damageAngleMultiplier;		// 0x08
		FLOAT m_minDamageAngle;				// 0x0C
		INT m_useDamageAngleCalculation;	// 0x10
	}; // 0x14

	class ClientVehicleEntityHealth
		: public VehicleEntityHealth	// 0x00
	{
	}; // 0x14

};

#endif
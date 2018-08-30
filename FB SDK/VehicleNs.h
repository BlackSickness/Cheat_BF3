#ifndef _VehicleNs_H
#define _VehicleNs_H


#include "FB SDK/Frostbite_Classes.h"
#include "FB SDK/ArrayTypeInfo.h"

namespace fb
{
		enum VehicleMode
	{

		 VmIdle,                     // constant 0x0
		 VmEntering,                     // constant 0x1
		 VmEntered,                     // constant 0x2
		 VmStarting,                     // constant 0x3
		 VmStarted,                     // constant 0x4
		 VmStopping,                     // constant 0x5
		 VmLeaving                     // constant 0x6

	}; // fb::VehicleMode

	class Boost
	{

		class ArrayTypeInfo :public fb::ArrayTypeInfo // Inherited class at offset 0x0
		{
		
		}; // ArrayTypeInfo

		class ArrayTypeInfo_t  :public fb::ArrayTypeInfo // Inherited class at offset 0x0
		{
						
		}; 
		float m_forwardStrength;                     // this+0x0
		float m_reverseStrength;                     // this+0x4
		float m_dissipationTime;                     // this+0x8
		float m_recoveryTime;                     // this+0xC
		float m_crawlStrength;                     // this+0x10
		float m_accelerationScale;                     // this+0x14

	}; // fb::Boost

	class EngineConfigData
		:public DataContainer // Inherited class at offset 0x0
	{
		virtual void * __vecDelDtor(unsigned int);	// V: 0x4
		Vec3 m_position;                     // this+0x10
		Array<float> m_rpmCurvePoints;                     // this+0x20
		Array<float> m_torqueCurvePoints;                     // this+0x24
		float m_rpmMin;                     // this+0x28
		float m_rpmMax;                     // this+0x2C
		float m_rpmCut;                     // this+0x30
		float m_enginePowerMultiplier;                     // this+0x34
		float m_internalAccelerationFactor;                     // this+0x38
		float m_internalDeaccelerationFactor;                     // this+0x3C
		struct fb::Boost m_boost;                     // this+0x40
		

	}; // fb::EngineConfigData

	class AeroDynamicPhysicsData
		:public DataContainer // Inherited class at offset 0x0
	{
		//virtual void * __vecDelDtor(unsigned int);	// V: 0x4
		LPVOID vTable;
		Vec3 m_bodyDrag;                     // this+0x10
		Vec3 m_bodyDragOffsetYZ;                     // this+0x20
		Vec3 m_bodyDragOffsetXZ;                     // this+0x30
		Vec3 m_bodyDragOffsetXY;                     // this+0x40
			

	}; // fb::AeroDynamicPhysicsData

	class VehicleInputData
	{

		class ArrayTypeInfo :public  fb::ArrayTypeInfo // Inherited class at offset 0x0
		{

			
						
		}; // ArrayTypeInfo

		class ArrayTypeInfo_t :public  fb::ArrayTypeInfo // Inherited class at offset 0x0
		{


						
		}; 

		float m_throttleDeadzone;                     // this+0x0
		float m_brakeDeadzone;                     // this+0x4
		float m_yawDeadzone;                     // this+0x8
		float m_pitchDeadzone;                     // this+0xC
		float m_rollDeadzone;                     // this+0x10
		float m_throttleInertiaOutDuration;                     // this+0x14
		float m_throttleInertiaInDuration;                     // this+0x18
		float m_throttleInertiaMinRatio;                     // this+0x1C
		float m_brakeInertiaOutDuration;                     // this+0x20
		float m_brakeInertiaInDuration;                     // this+0x24
		float m_brakeInertiaMinRatio;                     // this+0x28
		float m_yawInertiaOutDuration;                     // this+0x2C
		float m_yawInertiaInDuration;                     // this+0x30
		float m_yawInertiaMinRatio;                     // this+0x34
		float m_pitchInertiaOutDuration;                     // this+0x38
		float m_pitchInertiaInDuration;                     // this+0x3C
		float m_pitchInertiaMinRatio;                     // this+0x40
		float m_rollInertiaOutDuration;                     // this+0x44
		float m_rollInertiaInDuration;                     // this+0x48
		float m_rollInertiaMinRatio;                     // this+0x4C

	}; // fb::VehicleInputData


	class MyCurvePlotter
	{

		class eastl::deque<float,64> m_samples;                     // this+0x0
		const char * m_name;                     // this+0x2C
		unsigned int m_maxSampleCount;                     // this+0x30
		float m_min;                     // this+0x34
		float m_max;                     // this+0x38
		
	}; // fb::MyCurvePlotter


	class ConstantForceData
	{

		class ArrayTypeInfo :public fb::ArrayTypeInfo // Inherited class at offset 0x0
		{

						
		}; // ArrayTypeInfo

		class ArrayTypeInfo_t :public fb::ArrayTypeInfo // Inherited class at offset 0x0
		{


						
		}; 
		struct fb::Vec3 m_value;                     // this+0x0
		/*enum fb::ForceCondition*/ int m_condition;                     // this+0x10
		/*enum fb::ForceType */int m_typeOfForce;                     // this+0x14
		/*enum fb::SpaceType */int m_space;                     // this+0x18

	}; // fb::ConstantForceData

	class AntiRollBars
{

	class ArrayTypeInfo :public fb::ArrayTypeInfo // Inherited class at offset 0x0
		{

						
		}; // ArrayTypeInfo

		class ArrayTypeInfo_t :public fb::ArrayTypeInfo // Inherited class at offset 0x0
		{


						
		}; 

	CtrRefBase m_front;                     // this+0x0
	CtrRefBase m_rear;                     // this+0x4
	
}; // fb::AntiRollBars

	class VehicleConfigData :public DataContainer // Inherited class at offset 0x0
	{

		struct fb::Vec3 m_centerOfMass;                     // this+0x10
		struct fb::Vec3 m_centerOfMassHandlingOffset;                     // this+0x20
		struct fb::Vec3 m_inertiaModifier;                     // this+0x30
		class fb::CtrRefBase m_aeroDynamicPhysics;                     // this+0x40
		class fb::CtrRefBase m_motionDamping;                     // this+0x44
		struct fb::VehicleInputData m_input;                     // this+0x48
		class fb::CtrRefBase m_floatPhysics;                     // this+0x98
		class fb::CtrRefBase m_stabilizer;                     // this+0x9C
		/*class fb::Array<fb::StabilizerSettings> */void*m_stabilizers;                     // this+0xA0
		class fb::Array<fb::ConstantForceData> m_constantForce;                     // this+0xA4
		enum fb::VehicleMode m_vehicleModeAtReset;                     // this+0xA8
		float m_bodyMass;                     // this+0xAC
		float m_gravityModifier;                     // this+0xB0
		float m_yawMin;                     // this+0xB4
		float m_yawMax;                     // this+0xB8
		float m_downForceBaseFactor;                     // this+0xBC
		float m_downForceWheelFactor;                     // this+0xC0
		float m_vehicleModeChangeEnteringTime;                     // this+0xC4
		float m_vehicleModeChangeStartingTime;                     // this+0xC8
		float m_vehicleModeChangeStoppingTime;                     // this+0xCC
		float m_vehicleModeChangeLeavingTime;                     // this+0xD0
		float m_standStillLowSpeedTimeLimit;                     // this+0xD4
		float m_staticFrictionBreakCollisionMod;                     // this+0xD8
		float m_staticFrictionBreakVelocityMod;                     // this+0xDC
		float m_coefficientOfAirFriction;                     // this+0xE0
		float m_airDensity;                     // this+0xE4
		float m_airDragArea;                     // this+0xE8
		float m_windResistanceBaseFactor;                     // this+0xEC
		float m_windResistanceVelocityFactor;                     // this+0xF0
		float m_windResistanceVelocityFactorMin;                     // this+0xF4
		float m_windResistanceVelocityFactorMax;                     // this+0xF8
		struct fb::AntiRollBars m_antiRollBars;                     // this+0xFC
		bool m_useDownForceWheelFactor;                     // this+0x104
		bool m_useGearbox;                     // this+0x105
		bool m_useStandStillBrake;                     // this+0x106
		bool m_useStandStillSleep;                     // this+0x107
		bool m_useTurnAroundForce;                     // this+0x108
		bool m_useMotorcycleControl;                     // this+0x109
		bool m_invertPitchAllowed;                     // this+0x10A
		bool m_useWindResistance;                     // this+0x10B
		bool m_useDownForce;                     // this+0x10C
			virtual void * __vecDelDtor(unsigned int);	// V: 0x4

	}; // fb::VehicleConfigData

	class GearboxConfigData :public DataContainer // Inherited class at offset 0x0
	{
		class fb::Array<float> m_forwardGearRatios;                     // this+0x10
		class fb::Array<float> m_forwardGearSpeeds;                     // this+0x14
		class fb::Array<float> m_reverseGearRatios;                     // this+0x18
		class fb::Array<float> m_reverseGearSpeeds;                     // this+0x1C
		int m_gearboxType;                     // this+0x20
		int m_gearboxMode;                     // this+0x24
		float m_gearChangeTime;                     // this+0x28
		float m_gearDownSpeedFactor;                     // this+0x2C
		float m_oppositeDirGearChangeMaxSpeed;                     // this+0x30
		float m_oppositeDirGearChangeTime;                     // this+0x34
		float m_clutchSpeedFactor;                     // this+0x38
		float m_transmissionEfficiency;                     // this+0x3C
		bool m_useAutoClutch;                     // this+0x40
		bool m_useClassicGearBoxAutoClutch;                     // this+0x41
		bool m_useNeutralGear;                     // this+0x42
			virtual void * __vecDelDtor(unsigned int);	// V: 0x4

	}; // fb::GearboxConfigData

	namespace vehicle
	{
		class VehicleState
		{

			virtual void set(const class fb::vehicle::VehicleState &);	// V: 0x0
	
		}; // fb::vehicle::VehicleState
	

		class Engine
		{

			enum StateLod
			{

				 LodUncompressed,                     // constant 0x0
				 LodPrediction,                     // constant 0x1
				 LodReplication,                     // constant 0x2
				 LodSavePrediction,                     // constant 0x3
				 LodCount                     // constant 0x4

			}; // StateLod

			enum EngineType
			{

				 Combustion,                     // constant 0x0
				 Propeller,                     // constant 0x1
				 Jet                    // constant 0x2

			}; // EngineType

			enum EngineMode
			{

				 Stopped,                     // constant 0x0
				 Running                     // constant 0x1

			}; // EngineMode

			const class fb::EngineConfigData & m_data;                     // this+0x0
			enum fb::vehicle::Engine::EngineType m_type;                     // this+0x4
			enum fb::vehicle::Engine::EngineMode m_mode;                     // this+0x8
			float m_rpm;                     // this+0xC
			float m_recommendedRpm;                     // this+0x10
			float m_load;                     // this+0x14
			float m_boostTimer;                     // this+0x18
			float m_fakeSteerRpm;                     // this+0x1C
			bool m_skillModeEasy;                     // this+0x20
			bool m_isBoosting;                     // this+0x21
		
		}; // fb::vehicle::Engine

		class GearboxState
		{

			virtual void set(const class fb::vehicle::GearboxState &);	// V: 0x0
	
		}; // fb::vehicle::GearboxState

		class IGearbox
		{

			enum StateLod
			{

				 LodUncompressed,                     // constant 0x0
				 LodPrediction,                     // constant 0x1
				 LodReplication,                     // constant 0x2
				 LodSavePrediction,                     // constant 0x3
				 LodCount                     // constant 0x4

			}; // StateLod

			virtual class fb::vehicle::GearboxState * createState(void *, unsigned int, unsigned int &);	// V: 0x4
			virtual class fb::vehicle::GearboxState * createState();	// V: 0x8
			virtual void setState(const class fb::vehicle::GearboxState &);	// V: 0xC
			virtual void getState(class fb::vehicle::GearboxState &);	// V: 0x10
			virtual void stateToStream(/*class fb::IBitStreamWrite &*/void*, const class fb::vehicle::GearboxState &, const class fb::vehicle::GearboxState *, enum fb::vehicle::IGearbox::StateLod);	// V: 0x14
			virtual void streamToState(/*class fb::IBitStreamRead &*/void*, class fb::vehicle::GearboxState &, const class fb::vehicle::GearboxState *, enum fb::vehicle::IGearbox::StateLod);	// V: 0x18
			virtual int gear();	// V: 0x1C
			virtual bool clutchDown();	// V: 0x20
						virtual void * __vecDelDtor(unsigned int);	// V: 0x0

		}; // fb::vehicle::IGearbox


		class Gearbox :public fb::vehicle::IGearbox // Inherited class at offset 0x0
		{

	

			enum GearboxType
			{

				 Manual,                     // constant 0x0
				 Automatic                    // constant 0x1

			}; // GearboxType

			enum GearboxMode
			{

				 Direct,                     // constant 0x0
				 Classic,                     // constant 0x1
				 MhStyle                    // constant 0x2

			}; // GearboxMode

			enum GearboxLockMode
			{

				 NoLock,                     // constant 0x0
				 LockForward,                     // constant 0x1
				 LockReverse                   // constant 0x2

			}; // GearboxLockMode

			enum GearboxStatus
			{

				 GearboxNoChange,                     // constant 0x0
				 GearboxClutch                    // constant 0x1

			}; // GearboxStatus

			enum GearStatus
			{

				 GearNoChange,                     // constant 0x0
				 GearDoGearUp,                     // constant 0x1
				 GearGearUp,                     // constant 0x2
				 GearDoGearDown,                     // constant 0x3
				 GearGearDown,                     // constant 0x4
				 GearInvertGearbox                     // constant 0x5

			}; // GearStatus

			enum ClutchStatus
			{

				 ClutchNoChange,                     // constant 0x0
				 ClutchDownGearUp,                     // constant 0x1
				 ClutchDownGearDown,                     // constant 0x2
				 ClutchUp                     // constant 0x3

			}; // ClutchStatus

			class State :public fb::vehicle::GearboxState // Inherited class at offset 0x0
			{

			
				/*enum fb::vehicle::Gearbox::GearboxLockMode*/void* gearboxLockMode;                     // this+0x4
				/*enum fb::vehicle::Gearbox::GearboxStatus*/void* gearboxStatus;                     // this+0x8
				/*enum fb::vehicle::Gearbox::GearStatus*/void* gearStatus;                     // this+0xC
				/*enum fb::vehicle::Gearbox::ClutchStatus*/void* clutchStatus;                     // this+0x10
				int gear;                     // this+0x14
				float gearTimer;                     // this+0x18
				float clutch;                     // this+0x1C
				bool clutchToggle;                     // this+0x20, len(0x1)
				bool isGearboxInverted;                     // this+0x21, len(0x1)
				float invertedTimer;                     // this+0x24

			}; // State

				LPVOID vTable;													
			const class fb::GearboxConfigData & m_data;                     // this+0x4
		/*	enum fb::vehicle::Gearbox::GearboxLockMode*/void* m_gearboxLockMode;                     // this+0x8
		/*	enum fb::vehicle::Gearbox::GearboxStatus */void*m_gearboxStatus;                     // this+0xC
		/*	enum fb::vehicle::Gearbox::GearStatus*/void* m_gearStatus;                     // this+0x10
		/*	enum fb::vehicle::Gearbox::ClutchStatus*/void* m_clutchStatus;                     // this+0x14
			int m_gear;                     // this+0x18
			float m_gearTimer;                     // this+0x1C
			float m_clutch;                     // this+0x20
			float m_gearUpClutch;                     // this+0x24
			float m_gearDownClutch;                     // this+0x28
			bool m_clutchToggle;                     // this+0x2C, len(0x1)
			bool m_isGearboxInverted;                     // this+0x2D, len(0x1)
			float m_invertedTimer;                     // this+0x30
			

		}; // fb::vehicle::Gearbox



		class WheelReplicationState
		{

			Vec3 contactNormal;                     // this+0x0
			bool contactStatus;                     // this+0x10
			/*enum fb::vehicle::IWheel::WheelStatus*/int status;                     // this+0x14
			float steeringAngle;                     // this+0x18
			float angularVelocity;                     // this+0x1C
			float localPositionY;                     // this+0x20
			float springLength;                     // this+0x24
			unsigned int contactMaterial;                     // this+0x28

		}; // fb::vehicle::WheelReplicationState

		class WheelState
		{

			virtual void set(const class fb::vehicle::WheelState &);	// V: 0x0
			virtual void getReplicationState(struct fb::vehicle::WheelReplicationState &);	// V: 0x4
	
		}; // fb::vehicle::WheelState

		class WheelFrameInterpolationState
		{

			LinearTransform localTransform;                     // this+0x0
			Vec3 contactNormal;                     // this+0x40
			Vec3 contactPosition;                     // this+0x50
			unsigned int contactMaterial;                     // this+0x60
			/*enum fb::vehicle::IWheel::WheelStatus*/int status;                     // this+0x64
			bool contactStatus;                     // this+0x68

		}; // fb::vehicle::WheelFrameInterpolationState


		class IWheel
		{

			enum WheelStatus
			{

				 NoContact,                     // constant 0x0
				 GripContact,                     // constant 0x1
				 SlipContact                    // constant 0x2

			}; // WheelStatus

			enum StateLod
			{

				 LodUncompressed,                     // constant 0x0
				 LodPrediction,                     // constant 0x1
				 LodReplication,                     // constant 0x2
				 LodSavePrediction,                     // constant 0x3
				 LodCount                     // constant 0x4

			}; // StateLod

			enum NetworkSide
			{

				 Client,                     // constant 0x0
				 Server                    // constant 0x1

			}; // NetworkSide

			virtual void setEnabled(bool);	// V: 0x4
			virtual class fb::vehicle::WheelState * createState(void *, unsigned int, unsigned int &);	// V: 0x8
			virtual class fb::vehicle::WheelState * createState();	// V: 0xC
			virtual void setState(const class fb::vehicle::WheelState &);	// V: 0x10
			virtual void getState(class fb::vehicle::WheelState &);	// V: 0x14
			virtual void stateToStream(/*class fb::IBitStreamWrite &*/void*, enum fb::vehicle::IWheel::NetworkSide, const class fb::vehicle::WheelState &, const class fb::vehicle::WheelState *, enum fb::vehicle::IWheel::StateLod);	// V: 0x18
			virtual void streamToState(/*class fb::IBitStreamRead &*/void*, enum fb::vehicle::IWheel::NetworkSide, class fb::vehicle::WheelState &, const class fb::vehicle::WheelState *, enum fb::vehicle::IWheel::StateLod);	// V: 0x1C
			virtual void setReplicationState(const struct fb::vehicle::WheelReplicationState &);	// V: 0x20
			virtual void getFrameInterpolationState(struct fb::vehicle::WheelFrameInterpolationState &, const class fb::vehicle::WheelState &, const class fb::vehicle::WheelState &, float);	// V: 0x24
			virtual void setInitialPosition(const struct fb::Vec3 &);	// V: 0x28
			virtual void setLocalPosition(const struct fb::Vec3 &);	// V: 0x2C
			virtual const struct fb::LinearTransform & localTransform();	// V: 0x30
			virtual void setSteeringAngle(float);	// V: 0x34
			virtual float steeringAngle();	// V: 0x38
			virtual void setAngularVelocity(float);	// V: 0x3C
			virtual float angularVelocity();	// V: 0x40
			virtual void setRotation(float);	// V: 0x44
			virtual float rotation();	// V: 0x48
			virtual void setStatus(enum fb::vehicle::IWheel::WheelStatus);	// V: 0x4C
			virtual enum fb::vehicle::IWheel::WheelStatus status();	// V: 0x50
			virtual const class fb::MaterialContainerPair * contactMaterial();	// V: 0x54
			virtual float sideSlipAngle();	// V: 0x58
			virtual float slipRatio();	// V: 0x5C
			virtual float springCompression();	// V: 0x60
			virtual void setContactStatus(bool);	// V: 0x64
			virtual bool contactStatus();	// V: 0x68
			virtual void setContactPosition(const struct fb::Vec3 &);	// V: 0x6C
			virtual const struct fb::Vec3 & contactPosition();	// V: 0x70
			virtual void setContactNormal(const struct fb::Vec3 &);	// V: 0x74
			virtual const struct fb::Vec3 & contactNormal();	// V: 0x78
			virtual struct fb::Vec3 springForceVector();	// V: 0x7C
			virtual class fb::PhysicsEntityBase * springForceOtherBody();	// V: 0x80
			virtual int springForceOtherBodyShapeKey();	// V: 0x84
			virtual bool rayCast(const struct fb::Vec3 &, const struct fb::Vec3 &, class fb::RayCastHit &);	// V: 0x88
			virtual void setStatusFromRayCast(const struct fb::Vec3 &, const struct fb::Vec3 &, const class fb::RayCastHit &);	// V: 0x8C
						virtual void * __vecDelDtor(unsigned int);	// V: 0x0

		}; // fb::vehicle::IWheel

		class WingState
		{

			class ReplicationState
			{

				float m_flapAngle;                     // this+0x0
				bool m_liftEnabled;                     // this+0x4
				bool m_flapEnabled;                     // this+0x5
				bool m_landingFlapEnabled;                     // this+0x6

			}; // ReplicationState

			virtual void set(const class fb::vehicle::WingState &);	// V: 0x0
			virtual void getReplicationState(struct fb::vehicle::WingState::ReplicationState &);	// V: 0x4
	
		}; // fb::vehicle::WingState




		class IWing
		{

			enum StateLod
			{

				 LodUncompressed,                     // constant 0x0
				 LodPrediction,                     // constant 0x1
				 LodReplication,                     // constant 0x2
				 LodSavePrediction,                     // constant 0x3
				 LodCount                    // constant 0x4

			}; // StateLod

			enum NetworkSide
			{

				 Client,                   // constant 0x0
				 Server                     // constant 0x1

			}; // NetworkSide

			virtual void setLocalTransform(const LinearTransform &);	// V: 0x0
			virtual const LinearTransform & localTransform();	// V: 0x4
			virtual void setFlapAngle(float);	// V: 0x8
			virtual float flapAngle();	// V: 0xC
			virtual void updateFlapAngle();	// V: 0x10
			virtual float visualFlapAngle();	// V: 0x14
			virtual void updateVisualFlapAngle();	// V: 0x18
			virtual void setEnableLift(bool);	// V: 0x1C
			virtual void setEnableFlap(bool);	// V: 0x20
			virtual void setEnableLandingFlap(bool);	// V: 0x24
			virtual class fb::vehicle::WingState * createState(void *, unsigned int, unsigned int &);	// V: 0x28
			virtual class fb::vehicle::WingState * createState();	// V: 0x2C
			virtual void setState(const class fb::vehicle::WingState &);	// V: 0x30
			virtual void getState(class fb::vehicle::WingState &);	// V: 0x34
			virtual void stateToStream(/*class fb::IBitStreamWrite &*/void*, enum fb::vehicle::IWing::NetworkSide, const class fb::vehicle::WingState &, const class fb::vehicle::WingState *, enum fb::vehicle::IWing::StateLod);	// V: 0x38
			virtual void streamToState(/*class fb::IBitStreamRead &*/void*, enum fb::vehicle::IWing::NetworkSide, class fb::vehicle::WingState &, const class fb::vehicle::WingState *, enum fb::vehicle::IWing::StateLod);	// V: 0x3C
		
		}; // fb::vehicle::IWing

		class BodyDrag
		{

			bool m_useDrag;                     // this+0x0
			bool m_useDragOffsetYZ;                     // this+0x1
			bool m_useDragOffsetXZ;                     // this+0x2
			bool m_useDragOffsetXY;                     // this+0x3
			Vec3 m_drag;                     // this+0x10
			Vec3 m_dragOffsetYZ;                     // this+0x20
			Vec3 m_dragOffsetXZ;                     // this+0x30
			Vec3 m_dragOffsetXY;                     // this+0x40

		}; // fb::vehicle::BodyDrag

		class AeroDynamicPhysics
		{

				enum StateLod
			{

				 LodUncompressed,                    // constant 0x0
				 LodPrediction,                    // constant 0x1
				 LodReplication,                     // constant 0x2
				 LodSavePrediction,                     // constant 0x3
				 LodCount                     // constant 0x4

			}; // StateLod

			const class fb::AeroDynamicPhysicsData & m_data;                     // this+0x0
/*			const class fb::vehicle::Vehicle **/void* m_vehicle;                     // this+0x4
			class fb::vehicle::BodyDrag m_override;                     // this+0x10
	
		}; // fb::vehicle::AeroDynamicPhysics

		class Stabilizer
		{

			struct fb::Vec3 m_directionForYaw;                     // this+0x10
			struct fb::Vec3 m_directionForUp;                     // this+0x20
			struct fb::Vec3 m_initialWorldPosition;                     // this+0x30
			/*const struct fb::StabilizerSettings **/void*  m_data;                     // this+0x40
/*			const class fb::vehicle::Vehicle * */void* m_vehicle;                     // this+0x44
			unsigned int m_count;                     // this+0x48
			bool m_enabled;                     // this+0x4C
			bool m_isYawEnabled;                     // this+0x4D
				virtual void * __vecDelDtor(unsigned int);	// V: 0x0

		}; // fb::vehicle::Stabilizer



		class IVehicle //0x02054DE0
		{
			public:

			enum StateLod
			{

				 LodUncompressed,                     // constant 0x0
				 LodPrediction,                     // constant 0x1
				 LodReplication,                     // constant 0x2
				 LodSavePrediction,                     // constant 0x3
				 LodCount                     // constant 0x4

			}; // StateLod
			
		//	virtual void * __vecDelDtor(unsigned int);	// V: 0x0
		//	virtual void PAD1();
			//virtual void PAD2();
			//virtual void PAD1();

			virtual void setInitialWorldPosition(const struct fb::Vec3 &);	// V: 0x4
			virtual class fb::vehicle::VehicleState * createState(void *, unsigned int, unsigned int &);	// V: 0x8
			virtual class fb::vehicle::VehicleState * createState();	// V: 0xC
			virtual void setState(const class fb::vehicle::VehicleState &);	// V: 0x10
			virtual void getState(class fb::vehicle::VehicleState &);	// V: 0x14
			virtual void stateToStream(/*class fb::IBitStreamWrite &*/void*, const class fb::vehicle::VehicleState &, const class fb::vehicle::VehicleState *, enum fb::vehicle::IVehicle::StateLod);	// V: 0x18
			
			virtual void streamToState(/*class fb::IBitStreamRead &*/void*, class fb::vehicle::VehicleState &, const class fb::vehicle::VehicleState *, enum fb::vehicle::IVehicle::StateLod);	// V: 0x1C
			virtual void update(float);	// V: 0x20
			virtual void setTransform(const struct fb::LinearTransform &, bool);	// V: 0x24
			virtual const struct fb::LinearTransform & transform();	// V: 0x28
			virtual const struct fb::Quat & orientation();	// V: 0x2C
			virtual const struct fb::Vec3 & position();	// V: 0x30
			virtual enum fb::VehicleMode vehicleMode();	// V: 0x34
			virtual void setVehicleMode(enum fb::VehicleMode);	// V: 0x38
			virtual bool enterVehicle(bool);	// V: 0x3C
			virtual bool startVehicle();	// V: 0x40
			virtual bool stopVehicle(bool);	// V: 0x44
			virtual bool leaveVehicle();	// V: 0x48
			virtual bool wantsUpdate();	// V: 0x4C
			virtual void skipModeChangeDelay();	// V: 0x50
			virtual void setThrottle(float);	// V: 0x54
			virtual float throttle();	// V: 0x58
			virtual void setBrake(float);	// V: 0x5C
			virtual float brake();	// V: 0x60
			virtual void setHandBrake(float);	// V: 0x64
			virtual void setYaw(float);	// V: 0x68
			virtual void setPitch(float);	// V: 0x6C
			virtual void setStrafe(float);	// V: 0x70
			virtual void setRoll(float);	// V: 0x74
			virtual void setBoost(bool);	// V: 0x78
			virtual float boost();	// V: 0x7C
			virtual void setCrawl(bool);	// V: 0x80
			virtual void setUseInputFilter(bool);	// V: 0x84
			virtual class fb::PhysicsEntity * body();	// V: 0x88
			virtual void addEngine(class fb::vehicle::Engine *);	// V: 0x8C
			virtual void removeEngine(class fb::vehicle::Engine *);	// V: 0x90
			virtual unsigned int numEngines();	// V: 0x94
			virtual class fb::vehicle::Engine * engine(unsigned int);	// V: 0x98
			virtual void setGearbox(class fb::vehicle::IGearbox *);	// V: 0x9C
			virtual void addWheel(class fb::vehicle::IWheel *);	// V: 0xA0
			virtual void removeWheel(class fb::vehicle::IWheel *);	// V: 0xA4
			virtual unsigned int numWheels();	// V: 0xA8
			virtual class fb::vehicle::IWheel * wheel(unsigned int);	// V: 0xAC
			virtual void addWing(class fb::vehicle::IWing *);	// V: 0xB0
			virtual void removeWing(class fb::vehicle::IWing *);	// V: 0xB4
			virtual class fb::FloatPhysics * floatPhysics();	// V: 0xB8
			virtual class fb::vehicle::AeroDynamicPhysics * aeroDynamicPhysics();	// V: 0xBC
			virtual class fb::vehicle::Stabilizer * getStabilizer();	// V: 0xC0
			virtual class fb::vehicle::AeroDynamicPhysics * getAeroDynamicPhysics();	// V: 0xC4
			virtual bool getIsAirborne();	// V: 0xC8
			virtual bool getIsGroundVehicle();	// V: 0xCC
			virtual void onSpawn();	// V: 0xD0
			virtual bool isClientSimulationEnabled();	// V: 0xD4
			virtual unsigned int clientSimulationTicks();	// V: 0xD8
			virtual void disableClientSimulation();	// V: 0xDC
			virtual void setWaterHeight(float);	// V: 0xE0
			virtual float getWaterHeight();	// V: 0xE4
			virtual void setLandingGearDeployed(bool);	// V: 0xE8
			virtual bool landingGearDeployed();	// V: 0xEC
			virtual void setReplicatedVelocity(const struct fb::Vec3 &);	// V: 0xF0
			virtual void addWorldSpaceForce(const struct fb::Vec3 &, const struct fb::Vec3 &, float);	// V: 0xF4
			virtual void addBodySpaceForce(const struct fb::Vec3 &, const struct fb::Vec3 &, float);	// V: 0xF8
			virtual void setIsOccupied(bool);	// V: 0xFC
			virtual struct fb::Vec3 vehicleCenterOfMass();	// V: 0x100
			
			
		}; // fb::vehicle::IVehicle

		class Input
		{
		public:
			class State
			{

				float oldThrottle;                     // this+0x0
				float oldBrake;                     // this+0x4
				float oldYaw;                     // this+0x8
				float oldPitch;                     // this+0xC
				float oldRoll;                     // this+0x10
				bool boost;                     // this+0x14, len(0x1)
				bool crawl;                     // this+0x15, len(0x1)

			}; // State
			//PAD(0xC);
			VehicleInputData & m_data;                     // this+0x0
			float m_yaw;                     // this+0x4
			float m_oldYaw;                     // this+0x8
			float m_pitch;                     // this+0xC
			float m_oldPitch;                     // this+0x10
			float m_strafe;                     // this+0x14
			float m_roll;                     // this+0x18
			float m_oldRoll;                     // this+0x1C
			float m_throttle;                     // this+0x20
			float m_oldThrottle;                     // this+0x24
			float m_brake;                     // this+0x28
			float m_oldBrake;                     // this+0x2C
			float m_handBrake;                     // this+0x30
			float m_clutch;                     // this+0x34
			bool m_gearUp;                     // this+0x38, len(0x1)
			bool m_gearDown;                     // this+0x39, len(0x1)
			bool m_boost;                     // this+0x3A, len(0x1)
			bool m_crawl;                     // this+0x3B, len(0x1)

			public:
			static Input* Singleton()
			{
				return *(Input**)0x59AB50;
			}

			}; // fb::vehicle::Input

		class VehicleRender :public fb::IHavokRenderObject // Inherited class at offset 0x0
		{

			

				enum CurveMask
			{

				 AngularVelocity,                     // constant 0x1
				 Fx,                     // constant 0x2
				 SlipRatio,                     // constant 0x4
				 CurveAll                     // constant 0xF

			}; // CurveMask

			/*class fb::vehicle::Vehicle &*/void* m_vehicle;                     // this+0xC
			class eastl::vector<eastl::basic_string<char,fb::eastl_arena_allocator>,fb::eastl_arena_allocator> m_movingBodyText;                     // this+0x10
			class eastl::set<unsigned int,eastl::less<unsigned int>,fb::eastl_arena_allocator> m_idCache;                     // this+0x20
			class eastl::fixed_map<enum fb::vehicle::VehicleRender::CurveMask,fb::MyCurvePlotter *,8,1,eastl::less<enum fb::vehicle::VehicleRender::CurveMask>,fb::eastl_arena_allocator> m_curves;                     // this+0x38
			

		}; // fb::vehicle::VehicleRender


		class Vehicle
			:public IVehicle // Inherited class at offset 0x0
		{
		public:
		
			enum VehicleNetworkType
			{

				 Local,                   // constant 0x0
				 Remote                     // constant 0x1

			}; // VehicleNetworkType

			class State :public fb::vehicle::VehicleState // Inherited class at offset 0x0
			{

				
				struct fb::vehicle::Input::State inputState;                     // this+0x4
				enum fb::VehicleMode vehicleMode;                     // this+0x1C
				float vehicleModeChangeTimer;                     // this+0x20
				float timeSlowWithThrottle;                     // this+0x24
				float standStillTimer;                     // this+0x28
				float turnAroundTimer;                     // this+0x2C
				bool useInputFilter;                     // this+0x30
				bool staticFriction;                     // this+0x31
				bool isInWater;                     // this+0x32
				bool landingGearDeployed;                     // this+0x33

			}; // State

			class Less
			{
		
			}; // Less

			PAD(0x4);

			unsigned int m_id;                     // this+0x4
			class fb::vehicle::VehicleRender * m_debugRenderObject;                     // this+0x8
			const class fb::VehicleConfigData & m_data;                     // this+0xC
			class fb::vehicle::Input * m_input;                     // this+0x10
			class fb::vehicle::Gearbox * m_gearbox;                     // this+0x14
			class eastl::vector<fb::vehicle::Engine *,fb::eastl_arena_allocator> m_engines;                     // this+0x18
			/*class eastl::vector<fb::vehicle::Wheel *,fb::eastl_arena_allocator> */void*m_wheels;                     // this+0x28
			class eastl::vector<fb::Vec3,fb::eastl_arena_allocator> m_wheelFrictionForces;                     // this+0x38
			/*class eastl::vector<fb::vehicle::DifferentialDevice *,fb::eastl_arena_allocator>*/void* m_differentials;                     // this+0x48
			bool m_isAirborne;                     // wrong at 84 this+0x58
			bool m_isGroundVehicle;                     //at 85  this+0x59
			bool m_landingGearDeployed;                     // this+0x5A
/*			class fb::GravityAction **/void* m_gravityAction;                     // this+0x5C
			class fb::FloatPhysics * m_floatPhysics;                     // this+0x6
			class fb::vehicle::AeroDynamicPhysics * m_aeroDynamicPhysics;                     // this+0x64
/*			class eastl::vector<fb::vehicle::WingPhysics *,fb::eastl_arena_allocator> */void*m_wingPhysicsCont;                     // this+0x68
			class fb::vehicle::Stabilizer * m_stabilizer;                     // this+0x78
	/*		class fb::vehicle::MotionDamping * */void*m_motionDamping;                     // this+0x7C
	/*		class fb::DynamicPhysicsEntity * */void*m_body;                     // this+0x80
			/*enum fb::vehicle::Vehicle::VehicleNetworkType*/ int m_vehicleNetworkType;                     // this+0x84
			/*enum fb::VehicleMode*/ int m_vehicleMode;                     // this+0x88
			float m_vehicleModeChangeTimer;                     // this+0x8C
			bool m_useStandStillFunctions;                     // this+0x90
			float m_timeSlowWithThrottle;                     // this+0x94
			float m_standStillTimer;                     // this+0x98
			float m_turnAroundTimer;                     // this+0x9C
			float m_sideSlipAngle;                     // this+0xA0
			float m_sideSlipAmount;                     // this+0xA4
			float m_maxHeight;                     // this+0xA8
			float m_wantedPitchAngle;                     // this+0xAC
			bool m_useInputFilter;                     // this+0xB0
			struct fb::Vec3 m_vehicleCenterOfMass;                     // this+0xC0
		/*	class fb::vehicle::VehicleAction * */void*m_vehicleAction;                     // this+0xD0
		/*	class fb::vehicle::StaticFrictionCollision **/void* m_staticFrictionCollision;                     // this+0xD4
		/*		class fb::ProximityPhantom * */void*m_proximityPhantom;                     // this+0xD8
			bool m_requestClientSimulation;                     // this+0xDC
			int m_clientSimulationTicks;                     // this+0xE0
			bool m_wasBackstep;                     // this+0xE4
			bool m_disableClientSimulation;                     // this+0xE5
			struct fb::Vec3 m_clientSimLinVel;                     // this+0xF0
			struct fb::Vec3 m_clientSimAngVel;                     // this+0x100
			int m_hasLowVelocityTimer;                     // this+0x110
			struct fb::Vec3 m_replicatedVelocity;                     // this+0x120
			float m_waterHeight;                     // this+0x130
			int m_canStartLocalSimulationCounter;                     // this+0x134
			struct fb::Vec3 m_lastPos;                     // this+0x140
			struct fb::Vec3 m_originalInertiaTensor;                     // this+0x150
			bool m_isOccupied;                     // this+0x160
			
		}; // fb::vehicle::Vehicle

	};

};

#endif
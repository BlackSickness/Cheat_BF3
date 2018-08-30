#ifndef _SpatialEntity_H
#define _SpatialEntity_H
#include "Frostbite_Classes.h"
#include "Entity.h"
namespace fb
{
	class SpatialEntity
		: public Entity				// 0x00
	{
	public:
		virtual ~SpatialEntity();
		virtual void propertyChanged(/*fb::PropertyModificationListener::PropertyModification const &*/);//1 // V: 0x0
		virtual void listenToParentChanges(void);//2 // V: 0x4
		virtual bool isPropertyChangedAllowed(void);//3 // V: 0x8
		virtual void _event(/*fb::EntityEvent const *)*/);//4 // V: 0x0c
		virtual void editEvent(/*fb::DataUpdateEvent const **/);//5 // V: 0x10
		virtual void getDebugName(/*fb::StringBuilderBase &,bool*/);//6 // V: 0x14
		virtual void getPeerBus(void);//7  // V: 0x18
		virtual void getPeerData(void);//8  V: 0x1c
		virtual void computeWorldTransform(LinearTransform &);//9 0x24
		virtual void getPeerSubBus(void);//10 0x28
		virtual void getRecordingData(/*fb::EntityRecordingData **/);//11  0x2c
		virtual void onCreate(/*fb::EntityBusPeerCreationInfo &*/);//12 0x30
		virtual void onDestroy(void);//13 0x34
		virtual void Function14(); //14  0x38
		virtual void onSaveCreate(/*fb::SaveOutStream &*/); //15 0x3c
		virtual void onInit(/*fb::EntityInitInfo &*/); //16 0x40
		virtual void onSaveInit(/*fb::SaveOutStream &*/);  //17  0x44
		virtual void onDeinit(/*fb::EntityDeinitInfo &*/); //18 0x48
		virtual void getTransform(LinearTransform &);//19 - 0x54
		virtual void setTransform(LinearTransform const &);//20 - 58 
		virtual void computeBoundingBoxWorldTransform(fb::LinearTransform &); // 21V: 0x5c
		virtual void computeBoundingBox(fb::AxisAlignedBox &); // V: 0x60 22
		virtual void Dummy(); // 23V: 0x5c
		virtual void Dummy1(); // V: 0x60 24

		virtual void visualCullScreenArea(void); // V: 0x68 25
		virtual void onHiddenToggled(bool); // V: 0x6C 26
		virtual void spawn(fb::LinearTransform const *,void *,bool);//27- 0x70 
		virtual void needPrePhysicsUpdate(void); // V: 0x74 28
		virtual void prePhysicsUpdate(fb::EntityUpdateInfo const &); // V: 0x78 29
		virtual void prePhysicsQuery(fb::EntityUpdateInfo const &); // V: 0x7c 30
		virtual void needPostPhysicsUpdate(void); // V: 0x80 31
		virtual void postPhysicsUpdate(EntityUpdateInfo const &); // V: 0x84  32
		virtual void postPhysicsQuery(fb::EntityUpdateInfo const &); // V: 0x88  33
		virtual void needPostFrameUpdate(void); // V: 0x8c  34
		virtual void postFrameUpdate(fb::EntityUpdateInfo const &); // V: 0x90  35
		virtual void postFrameQuery(fb::EntityUpdateInfo const &); // V: 0x94  36
		virtual void needFrameInterpolationUpdate(void); // V: 0x98  37
		virtual void frameInterpolationUpdate(fb::EntityUpdateInfo const &); // V: 0x9c  38
		virtual void frameInterpolationQuery(fb::EntityUpdateInfo const &); // V: 0x100  39
		virtual void onSpawn(LPVOID);//(fb::GameEntity::SpawnInfo const &);  40
		virtual void onUnSpawn(LPVOID);//(fb::GameEntity::UnSpawnInfo const &);  41 
		virtual void onDeinit1(LPVOID);//(fb::GameEntity::GameEntityDeinitInfo &); 42
		virtual void worldTransformChanged(fb::LinearTransform const &,bool); //43
		//virtual void onComponentWorldTransformDirty(void); //44
		//virtual void onComponentUpdateRequiredChanged(void); //45
		//virtual void onComponentLocalBoundingBoxDirty(void); //46
		virtual void createUpdater(LPVOID);//(fb::UpdatePass); //44
		virtual void getUpdaters(void); //45
		virtual void meshModel(void); //46
		virtual void visualUpdate( float deltaTime );//fn 47 - 0xCC 
		virtual void Function48(); //
		virtual void fb__SoldierToComponentsInitializedMessage(); //

		virtual float mass(); //
		virtual void Function51(); //
		virtual float invMass(); //
		virtual const Vec3 &linearVelocity();//virtual void Function54(); // velocity
		virtual DWORD Function55(); //
		virtual DWORD Function56(); //
		virtual DWORD Function57(); //
		virtual DWORD onCollision(); //
		virtual DWORD Function59(); //
		virtual DWORD Function60(); //
		virtual DWORD Function61(); //
		virtual DWORD Function62(); //
		virtual DWORD Function63(); //
		virtual DWORD Function64(); //
		virtual DWORD Function65(); //
		virtual DWORD flgetHealth(); //
		virtual DWORD flgetMaxHealth(); //
		virtual DWORD entryInputstate(); //
		virtual DWORD Function69(); //
		virtual DWORD Function70(); //
		virtual DWORD fb__ClientSoldierEntity__postPhysicsUpdateEntry(); //
		virtual DWORD Function72(); //
		virtual ClientControllableEntity *onPlayerEntersControllable(); //
		virtual void UnlockComponentData(void);// ClientControllableEntity *onPlayerExitssControllable(); //
		virtual DWORD Function75(); //
		virtual DWORD Function76(); //
		virtual DWORD Function77(); //
		virtual DWORD Function78(); //
		virtual DWORD Function79(); //
		virtual DWORD Function80(); //
		virtual DWORD Function81(); //
		virtual DWORD Function82(); //
		virtual DWORD Function83(); //
		virtual DWORD ClientPlayer__applyCustomization(); //
		virtual void Function84(); //
		virtual void ClientPlayerKilledMessage();
		virtual void nullsub_6444(); //
		virtual void Function88(); //
		virtual void Function89(); //
		virtual void Function90(); //
		virtual void Function91(); //
		virtual DWORD InputState__getIsDown(); //
		virtual void Function93(); //
		virtual void Function94(); //
		virtual bool somebool(); //
		virtual void SoldierHealthModuleGS__writeGS(); //
		virtual void Function95(); //
		virtual DWORD Clientgamecontexplus16(); //
		virtual int Function98(); //
		virtual int Function99(); 


		DWORD m_cullGridId;                    // 0x0C

		__forceinline Vec3* GetEntityOrigin()
		{
			LinearTransform tmp;
			this->getTransform( tmp );
			return &tmp.trans;
		}

		__forceinline bool GetWorldOrigin(Vec3* v)
		{
			LinearTransform tmp;
			this->computeWorldTransform( tmp );
			memcpy_s(v, sizeof(fb::Vec3), &tmp.trans, sizeof(fb::Vec3));
			if(v) return true;
			return false;
		}
	}; // 0x10


};

#endif
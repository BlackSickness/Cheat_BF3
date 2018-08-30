#ifndef _MESSAGELISTENER_H
#define _MESSAGELISTENER_H

namespace fb
{
	class IPhysicsShape // Inherited class at offset 0x0
	{
		virtual void * __vecDelDtor(unsigned int);	// V: 0x0
		virtual void getLinearTransform(struct fb::LinearTransform &);	// V: 0x4
		virtual void setTransform(const struct fb::LinearTransform &);	// V: 0x8
		virtual void setCollisionLayer(int);	// V: 0xC
	}; // fb::IPhysicsShape

    class IPhysicsSphereShape :public IPhysicsShape
    {
    public:
		virtual float getRadius();	// V: 0x10
		virtual void setRadius(float);	// V: 0x14
    };

	class IPhysicsRenderer
    {
    public:
		
			virtual void * __vecDelDtor(unsigned int);	// V: 0x0
			virtual void render(class hkpWorld *, const struct fb::PhysicsRenderParams &);	// V: 0x4
			virtual void renderEntityPart(const class fb::PhysicsEntityBase *, unsigned int, struct fb::Color32, float);	// V: 0x8
			virtual void renderEntity(const class fb::PhysicsEntityBase *, const struct fb::QuatTransform *, unsigned int, struct fb::Color32, float);	// V: 0xC
			virtual void renderShape(const class hkpShape *, const struct fb::LinearTransform &, struct fb::Color32, float);	// V: 0x10
			virtual void registerRenderObject(class fb::IHavokRenderObject *);	// V: 0x14
			virtual void unregisterRenderObject(class fb::IHavokRenderObject *);	// V: 0x18
			virtual void renderRenderObject(class fb::IHavokRenderObject *, struct fb::Color32);	// V: 0x1C
			virtual class fb::IHavokRenderObject * associatedRenderObject(class fb::PhysicsEntity *);	// V: 0x20
			virtual unsigned int getDebugTextYOffset();	// V: 0x24
		
    };

    class IPhysicsManager
    {
    public:
        virtual ~IPhysicsManager();
		//virtual void * __vecDelDtor(unsigned int);	// V: 0x0
        virtual void init();
        virtual void clear();
        virtual PhysicsManagerType getType();
        virtual void simUpdate(float dt, float filteredDt, unsigned int tick);
		//another place to hook doupdate
        virtual void frameUpdate(float dt, float filteredDt);
        virtual void updateCharacterEntity(fb::CharacterPhysicsEntity *entity, float dt);
        virtual void dummy();//render(fb::LinearTransform *camTrans, fb::Color32 color);
        virtual IPhysicsRenderer* physicsRenderer();
        virtual void addPhantomBox(fb::IPhantomBox *phantom, bool addToEffectWorld);
        virtual void removePhantomBox(IPhantomBox *phantom);
        virtual void addPhantomShape(fb::IPhantomBox *phantom, bool addToEffectWorld);
        virtual void removePhantomShape(IPhantomBox *phantom);
        virtual void batchPhantomBox(IPhantomBox* phantom);
        virtual void batchPhantom(IPhantomBox* phantom);
        virtual void addPhantomBatch();
        virtual void removePhantomBatch();
        virtual IPhantomBox* createPhantomBox(fb::AxisAlignedBox *box);
        virtual IPhantomShape* createPhantomShapeBox(fb::AxisAlignedBox *box, fb::LinearTransform *transform);
        virtual void createRotationBody( void );
        virtual void createLinearMovingBody( void );
        virtual IPhysicsSphereShape* createSphereShape(float radius);
        virtual bool linearCastSphere(const char *ident, fb::IPhysicsSphereShape *shape, fb::Vec3 *end, fb::Vec3 *hitPosition, void* ignoreEntities);
        virtual int getCameraCollisionLayer();
        virtual void setRayCaster( IPhysicsRayCaster* ray );
		//hook for raycaster can be placed here
        virtual IPhysicsRayCaster* rayCaster();
        virtual bool aabbQueryEffectWorld(fb::AxisAlignedBox *box, void *intersectionList);
        virtual void* PhysicsManagerCInfo();
        virtual Vec3* getGravityVector();
        virtual float getWorldSize();
        virtual void* getMaterialGridManager();
        virtual void* getEntityFactory();
        virtual void* ragdollSkeletonManager();
        virtual int getNewSystemGroup();
        virtual bool debugDumpStaticGeometry( const char* geo );
        virtual void* getTerrainEntity();
        virtual void* getWaterEntity();
        virtual float waterHeight( Vec3* out );
        virtual bool rayCastWater(fb::Vec3 *start, fb::Vec3 *end, fb::Vec3 *outPosition);
        virtual void* defaultWaterMaterial();
        virtual void refreshHeightfield( void );
        virtual void enableBatchedWorldModifications( bool enabled );
        virtual void flushBatchWorldModifications( void );
        virtual bool isBatchAddToWorldEnabled( void );
        virtual void beginThreadSafeOperations( void );
        virtual void endThreadSafeOperations( void );
        virtual bool isRegionWakeupEnabled( void );
        virtual void enableRegionWakeup( bool enabled );
        virtual void setDebrisSystemReady( bool ready );
        virtual void setMaxVehicleHeight( float h );
        virtual float getMaxVehicleHeight();
        virtual void writeWorldShapshotToFile( const char* file );
        virtual void writeEffectWorldShapshotToFile( const char* file );
        virtual void writeWorldInformationToFile( const char* file );
        virtual void writeEffectWorldInformationToFile( const char* file );
    };

};

#endif
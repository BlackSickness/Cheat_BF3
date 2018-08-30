#ifndef _IRotation_H
#define _IRotation_H

namespace fb
{
	
    class IRotationBody :public IMovingBody
    {
    public:
	//	virtual void reset();	// V: 0x1C
	//	virtual void step(float);	//V: 0x20
		virtual void setOrientation(const struct Quat &);	// V: 0x24
		virtual const struct fb::Quat & orientation();	// V: 0x28
		virtual /*struct fb::Quat*/ void* getOrientation(float);	// V: 0x2C
		virtual void setAngle(float);	// V: 0x30
		virtual float angle();	// V: 0x34
		virtual void setAngularMomentum(const struct fb::Vec3 &);	// V: 0x38
		virtual const struct fb::Vec3 & angularMomentum();	// V: 0x3C
		virtual void setAngularVelocity(const struct fb::Vec3 &);	// V: 0x40
		virtual const struct fb::Vec3 & angularVelocity();	// V: 0x44
		virtual void setTorque(const struct fb::Vec3 &);	// V: 0x48
		virtual void applyTorque(float, const struct fb::Vec3 &);	// V: 0x4C
		virtual float invMass();	// V: 0x50
		//virtual const class fb::RotationBodyData & data();	// V: 0x54
		virtual void data();
		virtual void getAngularConstraints(float &, float &);	// V: 0x58
		virtual void setParentRotationBody(IRotationBody *);	// V: 0x5C
    };
};

#endif
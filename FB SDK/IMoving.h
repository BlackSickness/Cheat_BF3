#ifndef _IMoving_H
#define _IMoving_H

namespace fb
{
	class IMovingBody // Inherited class at offset 0x0
	{

		enum StateLod
		{
			 LodUncompressed,                     // constant 0x0
			 LodPrediction,                   // constant 0x1
			 LodReplication,                     // constant 0x2
			 LodSavePrediction,                     // constant 0x3
			 LodCount                     // constant 0x4
		}; // StateLod

		virtual void * __vecDelDtor(unsigned int);	// V: 0x0
		virtual struct MovingBodyState * createState(void *, unsigned int, unsigned int &);	// V: 0x4
		virtual struct MovingBodyState * createState();	// V: 0x8
		virtual void setState(const struct MovingBodyState &);	// V: 0xC
		virtual void getState(struct MovingBodyState &);	// V: 0x10
	//	virtual void stateToStream(class fb::IBitStreamWrite &, const struct fb::MovingBodyState &, const struct fb::MovingBodyState *, enum fb::IMovingBody::StateLod);	// V: 0x14
	//	virtual void streamToState(class fb::IBitStreamRead &, struct fb::MovingBodyState &, const struct fb::MovingBodyState *, enum fb::IMovingBody::StateLod);	// V: 0x18
		virtual void stateToStream();
		virtual void streamToState();
		virtual void reset();	// V: 0x1C
		virtual void step(float);	// V: 0x20
							

	}; // fb::IMovingBody

};

#endif
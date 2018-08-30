#ifndef _VEC2_H
#define _VEC2_H

//#include "../Frostbite_classes.h"

namespace fb
{

	class Vec2
	{
	public:
		union
		{
			struct 
			{
				FLOAT x;
				FLOAT y;
			};

			FLOAT data[2];
		};
	//from me
	Vec2 & operator = ( Vec2 & From )
        {
            this->x = From.x;
            this->y = From.y;

            return (*this);
        }
	//new from me get Distance for 2d vec
	float DistanceFrom( Vec2 const &other )
        {
            Vec2 Distance;

			Distance.x = other.x - this->x;
			Distance.y = other.y - this->y;

            return sqrt( ( Distance.x * Distance.x ) + ( Distance.y * Distance.y ) );
        }
	};


};

#endif
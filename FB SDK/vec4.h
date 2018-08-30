#ifndef _VEC4_H
#define _VEC4_H

namespace fb
{

class Vec4
	{
	public:
		enum ZeroType
		{

			Zero                     // constant 0x0

		}; // ZeroType

		enum OneType
		{

			 One                  // constant 0x0

		}; // OneType

		enum XType
		{

		 UnitX                   // constant 0x0

		}; // XType

		enum YType
		{

			UnitY                    // constant 0x0

		}; // YType

		enum ZType
		{

			UnitZ                   // constant 0x0

		}; // ZType

		enum WType
		{

			UnitW                   // constant 0x0

		}; // WType

		union
		{
			struct 
			{
				FLOAT x;
				FLOAT y;
				FLOAT z;
				FLOAT w;
			};
			FLOAT data[4];
		};


		Vec4(){}

	/*	Vec4( float x, float y, float z, float w )
		{
			this->x = x;
			this->y = y;
			this->z = z;
			this->w = w;
		}

		Vec4 & operator = ( Vec4 & From )
		{
			this->x = From.x;
			this->y = From.y;
			this->z = From.z;
			this->w = From.w;

			return (*this);
		}

		
		float Dot( Vec4 Vec )
		{
			return this->x * Vec.x + this->y * Vec.y + this->z * Vec.z + this->w * Vec.w;
		}

		float DistanceFrom( Vec4 Vec )
		{
			Vec4 Distance(
				Vec.x - this->x,
				Vec.y - this->y,
				Vec.z - this->z,
				Vec.w - this->w );
		}*/

	}; // fb::Vec4



};

#endif
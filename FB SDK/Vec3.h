#ifndef _VEC3_H
#define _VEC3_H

//#include "../Frostbite_classes.h"

namespace fb
{

	class Vec3
	{
	public:
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
		void print(char* pthis)
		{
			//LOG.Write("%s Vec3 at 0x%.8X: (%5.1f|%5.1f|%5.1f)\n",pthis,this,x,y,z);
		}
		float len(void)
		{
			return sqrt(x*x+y*y+z*z);
		}
		void normalize(void)
		{
			float _l=len();
			this->x/=_l;
			this->y/=_l;
			this->z/=_l;
		}
		void initialize(void)
		{
			
			this->x/=1;
			this->y/=1;
			this->z=1;
		}
		Vec3 operator * (float const &other)
		{
			this->x*=other;
			this->y*=other;
			this->z*=other;
			return *this;
		}
		Vec3 operator + (Vec3 const &other)
		{
			Vec3 v;
			v.x=this->x+other.x;
			v.y=this->y+other.y;
			v.z=this->z+other.z;
			return v;
		}
		Vec3 operator - (Vec3 const &other)
		{
			Vec3 v;
			v.x=this->x-other.x;
			v.y=this->y-other.y;
			v.z=this->z-other.z;
			return v;
		}
		Vec3 operator += (Vec3 const &other)
		{
			this->x+=other.x;
			this->y+=other.y;
			this->z+=other.z;
			return *this;
		}
		//new from me 
		Vec3 operator -= (Vec3 const &other)
		{
			this->x-=other.x;
			this->y-=other.y;
			this->z-=other.z;
			return *this;
		}
		bool operator ==(Vec3 const &other)
		{
			if(this->x==other.x)
			{
				if(this->y==other.y)
				{
					if(this->z==other.z)
					{
						return true;
					}
				}
			}
			return false;
		}
		//new from me Calculate Dotproduct
		float Dot( Vec3 Vec )
        {
            return this->x * Vec.x + this->y * Vec.y + this->z * Vec.z;
        }

		// new from me get VecLength
		float VectorLength()
		{
			return sqrt( ((this->x)*(this->x)) + ((this->y)*(this->y)) + ((this->z)*(this->z)));
		}
		float VectorLength2()
		{
			return sqrt( ((this->x)*(this->x)) + ((this->z)*(this->z)));
		}
		//new from me get distance to vec
		float DistanceToVector( Vec3 const &other )
        {
			Vec3 Distance;
			Distance.x = other.x - this->x;
			Distance.y = other.y - this->y;
			Distance.z = other.z - this->z;
            return sqrt( ( Distance.x * Distance.x ) + ( Distance.y * Distance.y ) + ( Distance.z * Distance.z ) );
        }
		float DistanceFrom(Vec3 & point)
		{
			float x2 = (point.x - x) * (point.x - x);
			float y2 = (point.y - y) * (point.y - y);
			float z2 = (point.z - z) * (point.z - z);

			float dist = sqrt(x2 + y2 + z2);

			return dist;
		}
	
		
		Vec3 TransferFromD3DXVECTOR3 ( D3DXVECTOR3 const &other )
		{
			this->x = other.x;
			this->y = other.y;
			this->z = other.z;
			return *this;
		}
		
		D3DXVECTOR3 TransfertoD3DXVECTOR3 (Vec3  const &other )
		{
			D3DXVECTOR3 D3D;
			D3D.x = other.x;
			D3D.y = other.y;
			D3D.z = other.z;
			return D3D;
		}

		//new from me calc Veccrossize
		Vec3 VectorCrossSize (CONST Vec3 *pV1, CONST Vec3 *pV2 )
		{
			 this->x = pV1->y * pV2->z - pV1->z * pV2->y;
			 this->y = pV1->z * pV2->x - pV1->x * pV2->z;
			 this->z = pV1->x * pV2->y - pV1->y * pV2->x;
			return *this;
		}

		BOOL WorldToScreen( __out Vec3 *screen )
		{
			static DWORD Function = NULL;

			// Make sure the 
			if (screen == NULL)
				return FALSE;

			// Get the WorldToScreen Function
			if (Function == NULL)
				Function = WORLDTOSCREEN;
			

			__asm
			{
				MOV	ECX, screen;
				PUSH	ECX;
				MOV	ECX, this;
				CALL	Function;
			}
		}

		float Vec3::AimFloat(Vec3 &delta, const float &FOV)
		{
			return asinf(this->Dot(delta)) / FOV;
		}




	};



};

#endif
#ifndef _COLOR32_H
#define _COLOR32_H

//#include "../Frostbite_classes.h"

namespace fb
{

	class Color32
	{
	public:
		union
		{
			struct
			{
				BYTE R;
				BYTE G;
				BYTE B;
				BYTE A;
			};
			DWORD dwColor;
		};
		static Color32 White()
		{
			return Color32( 255, 255, 255, 255 );
		}

		static Color32 Black()
		{
			return Color32( 0, 0, 0, 255 );
		}

		static Color32 Red()
		{
			return Color32(255, 0, 0, 255);
		}

		static Color32 Yellow()
		{
			return Color32(255, 255, 0, 255);
		}

		static Color32 Green()
		{
			return Color32( 0, 255, 0, 255 );
		}

		static Color32 Blue()
		{
			return Color32( 0, 0, 255, 255 );
		}
	public:
		Color32(const DWORD _Color)
		{
			dwColor=_Color;
		}

		Color32(const BYTE Red,const BYTE Green,const BYTE Blue, const BYTE Alpha)
		{
			A=Alpha;
			R=Red;
			G=Green;
			B=Blue;
		}
	};


};

#endif
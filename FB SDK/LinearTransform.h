#ifndef _LINEARTRANSFORM_H
#define _LINEARTRANSFORM_H

namespace fb
{
	class LinearTransform
	{
	public:
		
		union
		{
			struct 
			{
				Vec3 left;
				Vec3 up;
				Vec3 forward;
				Vec3 trans;
			};
			struct
			{
				Vec3 m_rows[4];
			};
			FLOAT data[4][4];


		};
		//new from me to calculate matrix
		LinearTransform & operator = ( LinearTransform & From )
		{
			this->m_rows[0] = From.m_rows[0];
			this->m_rows[1] = From.m_rows[1];
			this->m_rows[2] = From.m_rows[2];
			this->m_rows[3] = From.m_rows[3];

			return (*this);
		};

		/*
		LinearTransform transformto(D3DXMATRIX &ViewMatrix )
		{
			this->m_rows[0] = ViewMatrix._11;
			this->m_rows[1] = ViewMatrix._11;
			this->m_rows[2] = ViewMatrix._11;
			this->m_rows[3] = ViewMatrix._11;

			return (*this);
		};
		*/

		Vec3 one(){ return m_rows[0]; }
        Vec3 two(){ return m_rows[1]; }
        Vec3 three(){ return m_rows[2]; }
        Vec3 four(){ return m_rows[3]; }

		//new from me get origin from matrix/lineartransform
		BOOL GetOrigin(Vec3* vOrigin)
		{
			if(vOrigin)
			{
				memcpy_s(vOrigin, sizeof(fb::Vec3), &(this->trans), sizeof(fb::Vec3));
				return TRUE;
			}
			return FALSE;
		};

	};


};

#endif
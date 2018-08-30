#ifndef _MAT4_H
#define _MAT4_H

namespace fb
{

	class Mat4
	{
		enum ZeroType
		{
			 Zero                    // constant 0x0
		}; // ZeroType

		enum IdentityType
		{
			 Identity                     // constant 0x0
		}; // IdentityType

		enum RotationAxisX
		{
			 RotateX                     // constant 0x0
		}; // RotationAxisX

		enum RotationAxisY
		{
		 RotateY,                     // constant 0x0
		}; // RotationAxisY

		enum RotationAxisZ
		{
			 RotateZ                     // constant 0x0
		}; // RotationAxisZ

		enum BaseVector
		{
			 Right,                     // constant 0x0
			 Up,                     // constant 0x1
			 Forward,                     // constant 0x2
			 Pos                     // constant 0x3
		}; // BaseVector

		Vec4                    m_rows[4];     // 0x0

		Mat4(){}

		Mat4 & operator = ( Mat4 & From )
		{
			this->m_rows[0] = From.m_rows[0];
			this->m_rows[1] = From.m_rows[1];
			this->m_rows[2] = From.m_rows[2];
			this->m_rows[3] = From.m_rows[3];

			return (*this);
		}

		Vec4 one(){ return m_rows[0]; }
		Vec4 two(){ return m_rows[1]; }
		Vec4 three(){ return m_rows[2]; }
		Vec4 four(){ return m_rows[3]; }               

	}; // fb::Mat4



};

#endif
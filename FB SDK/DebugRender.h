#ifndef _DEBUGRENDER_H
#define _DEBUGRENDER_H

//#include "../Frostbite_classes.h"
#define OFF_DEBUGRENDERER2_DRAWTEXT	0x004B7610
#define OFF_DEBUGRENDERER2_DRAWLINE	0x004B9980
#define OFF_DEBUGRENDERER2_DRAWRECT	0x4BA4F0 
#define OFF_DEBUGRENDERER2_FILLRECT  0x4BA4F0
#define OFF_DEBUGRENDERER2_SINGLETON 0x4B2EA0
namespace fb
{

	enum DebugGeometryType
	{

		DebugGeometryType_Triangle3d,                    // constant 0x0
		DebugGeometryType_Line3d,                    // constant 0x1
		DebugGeometryType_Triangle2d,                     // constant 0x2
		DebugGeometryType_Line2d,                     // constant 0x3
		DebugGeometryType_Font2d,                     // constant 0x4
		DebugGeometryTypeCount                   // constant 0x5

	}; // fb::DebugGeometryType

	enum DebugRenderCmdId
	{

		DebugRenderCmdId_Text2d,                     // constant 0x0
		DebugRenderCmdId_Text3d,                     // constant 0x1
		DebugRenderCmdId_TextLog,                     // constant 0x2
		DebugRenderCmdId_Vertices,                     // constant 0x3
		DebugRenderCmdId_Sphere,                     // constant 0x4
		DebugRenderCmdIdCount                     // constant 0x5

	}; // fb::DebugRenderCmdId

	enum DebugRenderFrameType
	{

		 DebugRenderFrameType_Immediate,                  // constant 0x0
		 DebugRenderFrameType_OneFrameLatency,                     // constant 0x1
		 DebugRenderFrameType_Discard                     // constant 0x2

	}; // fb::DebugRenderFrameType

	class DebugRenderStateCombo
	{

		unsigned char transparent;                     // 0x0, len(0x1)
		unsigned char doubleSided;                     // 0x1, len(0x1)
		unsigned char depthTest;                     // 0x2, len(0x1)
		unsigned char depthWrite;                     // 0x3, len(0x1)
		unsigned char shadingMode;                     // 0x4, len(0x2)

	}; // fb::DebugRenderStateCombo

	class DebugRenderCmd
	{

		DebugRenderCmdId id;                     // 0x0
		DebugRenderStateCombo state;                     // 0x4
		unsigned sortOrder;                     // 0x8
		unsigned int size;                     // 0xC

	}; // fb::DebugRenderCmd


	class DebugRenderVertex
	{

		/*struct fb::Tuple3<float> */ void* pos;                     // 0x0
		struct fb::Color32 color;                     // 0xC
		/*struct fb::Tuple3<float>*/ void * normal;                     // 0x10
		unsigned int pad;                     // 0x1C

	}; // fb::DebugRenderVertex

	class DebugRenderStats2
	{

		unsigned int/*[0x5] */typeVertexCounts;                     // 0x0
		unsigned int/*[0x5]*/ typeDrawCallCounts;                     // 0x14
		unsigned int/*[0x5]*/ commandCounts;                     // 0x28
		unsigned int/*[0x5]*/ commandSizes;                     // 0x3C

	}; // fb::DebugRenderStats2

	class DebugRenderCmd_Vertices
		:public DebugRenderCmd   // Inherited class at offset 0x0
	{
/*
		class fb::DebugRenderCmd // Inherited class at offset 0x0
		{

			enum fb::DebugRenderCmdId id;                     // 0x0
			struct fb::DebugRenderStateCombo state;                     // 0x4
			unsigned int sortOrder;                     // 0x8
			unsigned int size;                     // 0xC

		}; // fb::DebugRenderCmd
		*/
		DebugGeometryType type;                     // 0x10
		unsigned int vertexCount;                     // 0x14
		DebugRenderVertex/*[0x0] */vertices;                     // 0x18
		
	}; // fb::DebugRenderCmd_Vertices

	class IDebugRenderBackend
	{

		virtual void beginCmdList(unsigned int, unsigned int *, struct fb::DebugRenderCmd * *);	// V: 0x0
		virtual void endCmdList(unsigned int, unsigned int);	// V: 0x4
		virtual void queueFrame(enum fb::DebugRenderFrameType, const char *, unsigned int, const unsigned int *);	// V: 0x8
		virtual void queueExternalFrame(const char *, unsigned int, struct fb::DebugRenderCmd *);	// V: 0xC
		virtual void draw(float, const class fb::RenderView &, struct fb::DebugRenderStats2 *);	// V: 0x10
		virtual struct fb::Tuple2<unsigned int> getScreenResolution();	// V: 0x14
		
	}; // fb::IDebugRenderBackend


	class DebugRenderer
	{
	public:
		static DebugRenderer* Singleton()
		{
			typedef fb::DebugRenderer* (__stdcall* tGetDebugRenderer)(void);
			tGetDebugRenderer GetDebugRenderer=(tGetDebugRenderer)0x446130;//CSigManager::Singleton()->dwOFFSET_DEBUGRENDERER;//0x004B27E0;
			return GetDebugRenderer();
		}
		void DrawBox(fb::AxisAlignedBox  &aab, fb::LinearTransform &transform,DWORD dwColor)
		{
			typedef void* (__thiscall* tDrawBox)(fb::DebugRenderer*,fb::AxisAlignedBox&,fb::LinearTransform&,DWORD);
			tDrawBox _DrawBox=(tDrawBox)0x0043A260;
			_DrawBox(this,aab,transform,dwColor);
		}
		void DrawLineBox(fb::AxisAlignedBox  &aab, fb::LinearTransform &transform,Color32 dwColor)
		{
			static __declspec(align(16)) fb::AxisAlignedBox box;
			static __declspec(align(16)) fb::LinearTransform trans;
			box.max=aab.max;
			box.min=aab.min;
			trans.forward=transform.forward;
			trans.left=transform.left;
			trans.up=transform.up;
			trans.trans=transform.trans;
			typedef void* (__thiscall* tDrawBox)(fb::DebugRenderer*,fb::AxisAlignedBox&,fb::LinearTransform&,Color32);
			tDrawBox _DrawBox=(tDrawBox)0x00439930;
			_DrawBox(this,box,trans,dwColor);
		}
		void DrawSphere(fb::Vec3 &pos, float radius, fb::Color32 color, bool renderLines, bool scalesmall)
		{
			typedef void (__thiscall *tDrawSphere)(fb::DebugRenderer*,fb::Vec3&, float, fb::Color32,bool renderLines, bool scalesmall);
			tDrawSphere EngDrawSphere=(tDrawSphere)0x0043AF20;
			EngDrawSphere(this,pos,radius,color,renderLines,scalesmall);
		};
	};

	class DebugRenderer2
	{
	public:



		static DebugRenderer2* Singleton()
		{
			typedef DebugRenderer2* (__stdcall* tDebugRenderer2)();
			static tDebugRenderer2 oDebugRenderer2 = (tDebugRenderer2)OFF_DEBUGRENDERER2_SINGLETON;

			return oDebugRenderer2();
		}

	
		void DrawText(float x, float y, float scale, Color32 color, char* text, ...)
		{
			char szBuffer[256] = { 0 };

			va_list va;

			va_start(va, text);
			_vsnprintf(szBuffer, sizeof(szBuffer), text, va);
			va_end(va);

			typedef void(__thiscall* tDrawText)(DebugRenderer2*, int, int, char*, Color32, float);
			tDrawText oDrawText = (tDrawText)OFF_DEBUGRENDERER2_DRAWTEXT;

			oDrawText(this, (int)x, (int)y, szBuffer, color, scale);
		}
		void drawText(int x, int y, Color32 color, char* text)
		{
			typedef void(__thiscall *tdrawText)(fb::DebugRenderer2*, int, int, char*, Color32, float);
			tdrawText mdrawText = (tdrawText)OFF_DEBUGRENDERER2_DRAWTEXT;
			mdrawText(this, (int)x, (int)y, text, color, 1.0f);
		}

		void drawText(int x, int y, Color32 color, char* text, float scale)
		{
			typedef void(__thiscall *tdrawText)(fb::DebugRenderer2*, int, int, char*, Color32, float);
			tdrawText mdrawText = (tdrawText)OFF_DEBUGRENDERER2_DRAWTEXT;
			mdrawText(this, x, y, text, color, scale);
		}
		
		void drawLine2d(Tuple2<float>* pos1, Tuple2<float>* pos2, Color32 color)
		{
			typedef void (__thiscall *tdrawLine2d)(fb::DebugRenderer2*,Tuple2<float>*, Tuple2<float>*, Color32);
			tdrawLine2d mdrawLine2d=(tdrawLine2d)0x004B9980;
			mdrawLine2d(this,pos1,pos2,color);
		}

		void drawLineRect2d(Tuple2<float>* minpos, Tuple2<float>* maxpos, Color32 color)
		{
			typedef void (__thiscall *tdrawLineRect2d)(fb::DebugRenderer2*,Tuple2<float>*, Tuple2<float>*, Color32);
			tdrawLineRect2d mdrawLineRect2d=(tdrawLineRect2d)0x004BA2E0;
			mdrawLineRect2d(this,minpos,maxpos,color);
		}

		void drawRect2d(Tuple2<float>* minpos, Tuple2<float>* maxpos, Color32 color)
		{
			typedef void (__thiscall *tdrawRect2d)(fb::DebugRenderer2*,Tuple2<float>*, Tuple2<float>*, Color32);
			tdrawRect2d mdrawRect2d=(tdrawRect2d)0x004BA4F0;
			mdrawRect2d(this,minpos,maxpos,color);
		}

		void DrawSphere(fb::Vec3 pos, float radius, Color32 col)
		{
			fb::DebugRenderer2* pDR = fb::DebugRenderer2::Singleton();
			if (!pDR)
			{
				return;
			}
			__declspec(align(16)) fb::Vec3 _pos;
			_pos.x = pos.x;
			_pos.y = pos.y;
			_pos.z = pos.z;
			_pos.w = pos.w;
			typedef void(__thiscall* tDrawSphere)(fb::DebugRenderer2*, fb::Vec3*, float, Color32, bool, bool);
			tDrawSphere DrawSphere = (tDrawSphere)0x4B77E0;
			DrawSphere(pDR, &_pos, radius, col, true, false);
		}

		void DrawTriangle2d(float x0, float y0,float x1, float y1,float x2, float y2,DWORD col)
		{
			fb::DebugRenderer2* pDR=fb::DebugRenderer2::Singleton();
			if(!pDR)
			{
				return;
			}
			typedef void (__thiscall* tDrawSingleColorTriangle)(fb::DebugRenderer2*, eastl::Tuple<float>*, eastl::Tuple<float>*, eastl::Tuple<float>*,DWORD);
			tDrawSingleColorTriangle m_DrawSingleColorTriangle=(tDrawSingleColorTriangle)0x004BA160;
			eastl::Tuple<float> t1, t2, t3;
			t1._1=x0;
			t1._2=y0;
			t2._1=x1;
			t2._2=y1;
			t3._1=x2;
			t3._2=y2;
			m_DrawSingleColorTriangle(pDR,&t1,&t2,&t3,col);
		}

		void FillRect(float x, float y, float width, float height, fb::Color32 color)
		{
			fb::Tuple2< float > tupMin = fb::Tuple2< float >(x, y);
			fb::Tuple2< float > tupMax = fb::Tuple2< float >(x + width, y + height);

			typedef void(__thiscall* tFillRect)(fb::DebugRenderer2*, fb::Tuple2< float >*, fb::Tuple2< float >*, fb::Color32);
			tFillRect oFillRect = (tFillRect)0x4BA4F0;

			oFillRect(this, &tupMin, &tupMax, color);
		}

		void DrawRect(float x, float y, float width, float height, fb::Color32 color)
		{
			fb::Tuple2< float > tupMin = fb::Tuple2< float >(x, y);
			fb::Tuple2< float > tupMax = fb::Tuple2< float >(x + width, y + height);

			typedef void(__thiscall* tDrawRectangle)(fb::DebugRenderer2*, fb::Tuple2< float >*, fb::Tuple2< float >*, fb::Color32);
			tDrawRectangle oDrawRectangle = (tDrawRectangle)0x4BA4F0;

			oDrawRectangle(this, &tupMin, &tupMax, color);
		}
		void DrawHealthBar(float x, float y, float w, float health, float max)
		{
			fb::Color32 col = (health >= (max / 2) ? fb::Color32::Green() : fb::Color32::Red());

			float step = (w / max);
			float draw = (step * health);

			DrawRect(x, y, w, 4, fb::Color32::Black());
			FillRect(x, y, w, 4, fb::Color32::Black());
			FillRect(x, y, draw, 4, col);
		}

		void DrawCircle(int x0, int y0, float radius, float thickness, Color32 color) {
			int x = radius, y = 0;
			int radiusError = 1 - x;

			while (x >= y) {
				FillRect(x + x0, y + y0, thickness, thickness, color);
				FillRect(y + x0, x + y0, thickness, thickness, color);
				FillRect(-x + x0, y + y0, thickness, thickness, color);
				FillRect(-y + x0, x + y0, thickness, thickness, color);
				FillRect(-x + x0, -y + y0, thickness, thickness, color);
				FillRect(-y + x0, -x + y0, thickness, thickness, color);
				FillRect(x + x0, -y + y0, thickness, thickness, color);
				FillRect(y + x0, -x + y0, thickness, thickness, color);
				y++;
				if (radiusError<0) {
					radiusError += 2 * y + 1;
				}
				else {
					x--;
					radiusError += 2 * (y - x + 1);
				}
			}
		}

		void DrawLine(float x1, float y1, float x2, float y2, Color32 color)
		{
			fb::Tuple2< float > tupFrom = fb::Tuple2< float >(x1, y1);
			fb::Tuple2< float > tupTo = fb::Tuple2< float >(x2, y2);

			typedef void(__thiscall* tDrawLine)(DebugRenderer2*, fb::Tuple2< float >*, fb::Tuple2< float >*, Color32);
			tDrawLine oDrawLine = (tDrawLine)OFF_DEBUGRENDERER2_DRAWLINE;

			oDrawLine(this, &tupFrom, &tupTo, color);
		}
		void DrawBox2D(float x1, float y1, float w, float h, Color32 color) {
			DrawLine(x1, y1, x1 + w, y1, color); // 1 -> 2
			DrawLine(x1 + w, y1, x1 + w, y1 + h, color); // 2 -> 4
			DrawLine(x1 + w, y1 + h, x1, y1 + h, color); // 4 -> 3
			DrawLine(x1, y1 + h, x1, y1, color); // 3 -> 1
		}
	};


};

#endif
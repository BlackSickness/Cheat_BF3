#ifndef _UI_H
#define _UI_H

namespace fb
{
	class IUISystem
	{
	public:
		/*
		virtual void * __vecDelDtor(unsigned int);	// V: 0x18
		virtual void init();	// V: 0x1C
		virtual void reset();	// V: 0x20
		virtual class fb::UILocalization * getLocalization();	// V: 0x24
		virtual class fb::UIInputManager * getInputManager();	// V: 0x28
		virtual class fb::Client * getClient();	// V: 0x2C
		virtual class EA::Jobs::JobInstanceHandle createJob(float, bool, class EA::Jobs::JobInstanceHandle);	// V: 0x30
		virtual void getDataCopy(const int, class fb::UIDataValue &);	// V: 0x34
		virtual void getData(const int, class fb::UIDataValue * &, bool);	// V: 0x38
		virtual void setData(const int, const char *, enum fb::UINotifyType, enum fb::UIDataValue::UISetType);	// V: 0x3C
		virtual void setData(const int, const double, enum fb::UINotifyType, enum fb::UIDataValue::UISetType);	// V: 0x40
		virtual void setData(const int, const int, enum fb::UINotifyType, enum fb::UIDataValue::UISetType);	// V: 0x44
		virtual void setData(const int, const bool, enum fb::UINotifyType, enum fb::UIDataValue::UISetType);	// V: 0x48
		virtual void setDataValue(const int, const class fb::UIDataValue &, enum fb::UINotifyType, enum fb::UIDataValue::UISetType);	// V: 0x4C
		virtual bool isProcessingQueue();	// V: 0x50
		virtual void refreshData(const int, bool);	// V: 0x54
		virtual void resetHasChanged(const int, bool);	// V: 0x58
		virtual void enterGraph(class fb::ClientUIGraphEntity &, const class fb::UIGraphAsset &, const class fb::InstanceInputNode *, enum fb::UIGraphPriority);	// V: 0x5C
		virtual void exitGraph(const class fb::UIGraphAsset *);	// V: 0x60
		virtual unsigned int getNrOfStackedGraphs();	// V: 0x64
		virtual bool fireWidgetEvent(struct fb::WidgetEventData *, const class fb::UIGraphAsset *);	// V: 0x68
		virtual void fireGraphEventForTopGraph(const class eastl::basic_string<char,fb::eastl_arena_allocator> &, const class fb::UIGraphAsset *);	// V: 0x6C
		virtual void fireGraphEvent(const class eastl::basic_string<char,fb::eastl_arena_allocator> &, const class fb::UIGraphAsset *, const struct fb::Guid &);	// V: 0x70
		virtual bool eventToAllGraphs(const char *);	// V: 0x74
		virtual bool isUIGraphManagerAlive();	// V: 0x78
		virtual bool handleInputPressed(const class fb::UIGraphAsset *, const enum fb::UIInputActionEventType, const enum fb::UIInputAction);	// V: 0x7C
		virtual bool handleInputPressed(const enum fb::UIInputActionEventType, const enum fb::UIInputAction);	// V: 0x80
		virtual void notifyDataListeners(const int, const class eastl::basic_string<char,fb::eastl_arena_allocator> &, class fb::UIDataValue *, const class eastl::vector<eastl::basic_string<char,fb::eastl_arena_allocator>,fb::eastl_arena_allocator> *);	// V: 0x84
		virtual void popScreen(const char *);	// V: 0x88
		virtual void popScreen(const unsigned int, const class fb::UIGraphAsset *);	// V: 0x8C
		virtual bool pushScreen(const struct fb::Guid &, const class fb::UIScreenAsset &, enum fb::UIGraphPriority, const class fb::UIGraphAsset *, bool);	// V: 0x90
		virtual bool showScreen(const struct fb::Guid &, bool);	// V: 0x94
		virtual void eventToWidget(const struct fb::Guid &, enum fb::UIWidgetEventID, class fb::UIDataValue &);	// V: 0x98
		virtual void setWidgetFocus(const char *, const char *);	// V: 0x9C
		virtual void screenEnterCompleted(const char *);	// V: 0xA0
		virtual void screenExitCompleted(const char *);	// V: 0xA4
		virtual void screenLoaded(const char *);	// V: 0xA8
		virtual void setDataBindingFactory(class fb::IUIDataBindingFactory *);	// V: 0xAC
		virtual bool screenExists(const char *);	// V: 0xB0
		virtual bool resolveWidgetPath(const char *, struct fb::WidgetPath &);	// V: 0xB4
		virtual bool isGraphOnQueuedStack(const class fb::UIGraphAsset &);	// V: 0xB8
		virtual bool isGraphOnStack(const class fb::UIGraphAsset &);	// V: 0xBC
		virtual void reduceNrOfScreensInGraph(const class fb::UIGraphAsset *, unsigned int);	// V: 0xC0
		virtual class fb::IUIComponent * getComponentForData(const class fb::TypeInfo *, bool);	// V: 0xC4
		virtual bool isIngame();	// V: 0xC8
		virtual void setSafeArea(float, float);	// V: 0xCC
		*/
					
	}; // fb::IUISystem

	class UIHud
	{
			class UIEngineDrawComp // Inherited class at offset 0x0
			{
			   virtual void * __vecDelDtor(unsigned int);      // V: 0x0
			}; // fb::UIEngine::UIEngineDrawComp
 
			class HudRenderState
			{
				struct UIVertex2d * vertices;                     // 0x0
				unsigned short * indices;                     // 0x4
				unsigned int vertexBufferOffset;                     // 0x8
				unsigned int indexBufferOffset;                     // 0xC
				unsigned int count;                     // 0x10
				unsigned int lastBufferSize;                     // 0x14
				float alpha;                     // 0x18
				DWORD * cb; // function  * cb;                     // 0x1C
 
			}; // HudRenderState
 
			class UIHudDraw
			{
				 virtual void * __vecDelDtor(unsigned int);      // V: 0x0
			}; // UIHudDraw
 
			enum eHudRenderState
			{
 
					eHudRenderState_alpha,                // constant 0x0
					eHudRenderState_add,                    // constant 0x1
					eHudRenderState_count,                   // constant 0x2
					eHudRenderState_notUsed                // constant 0x3
 
			}; // eHudRenderState
 
			class UIHudIconDrawParams
			{
 
					struct fb::Vec2 pos;                     // 0x0
					struct fb::Vec2 size;                     // 0x8
					struct fb::Vec2 flip;                     // 0x10
					enum UIHudIcon icon;                     // 0x18
					enum UIIconState state;                     // 0x1C
					float scale;                     // 0x20
					Color32 color;                     // 0x24
 
			}; // UIHudIconDrawParams
 
			class Text
			{
 
					unsigned int hash;                     // 0x0
					float timeSinceUsed;                     // 0x4
					float textSize;                     // 0x8
					float glowSize;                     // 0xC
					Color32 color;                     // 0x10
					struct Vec2 pos;                     // 0x14
					unsigned char justCreated;                     // 0x1C
					unsigned char textLen;                     // 0x1D
					unsigned short pad;                     // 0x1E
					DWORD /* class GRect<float>*/ textRect;                     // 0x20
					DWORD /*   class GPtr<GFxDrawText> */text;                     // 0x30
					DWORD /*  struct GFxDrawText::Filter*/ filter;                     // 0x34                             
			}; // Text
 
			struct Vec3 m_currentTextColor;                     // 0x10
			bool m_bIsMultiplayer;                     // 0x20
			bool m_bIsCoop;                     // 0x21
			bool m_bCreateNewText;                     // 0x22
			DWORD /* class UIMinimapIconTextureAtlas*/ m_atlas;                     // 0x24
			enum eHudRenderState m_currRenderState;                     // 0x50
			DWORD /* struct HudRenderState[0x2] */m_renderState;                     // 0x54
			DWORD /*class eastl::vector<Text *,eastl_arena_allocator>*/ m_text;                     // 0x94
			DWORD /* class eastl::vector<UIHudDraw *,fb::eastl_arena_allocator>*/ m_drawObjects;                     // 0xA4
			float m_lastDelta;                     // 0xB4
			virtual void * __vecDelDtor(unsigned int);      // V: 0x0
 
	}; // fb::UIHud

	class UINametag
	{

	/*	class fb::DataContainer // Inherited class at offset 0x0
		{

			class fb::ITypedObject // Inherited class at offset 0x0
			{

				virtual const class TypeInfo * getType();	// V: 0x0

			}; // fb::ITypedObject

			enum 
			{

				kMemberType,                   // constant 0x1
				kMemberTypeCategory,// constant 0x1
				kMemberTypeCode,                     // constant 0x3
				 kMemberInfoOtherFlags                     // constant 0x0

			}; // <unnamed-tag>

			enum 
			{

				kDefaultMakeRoomForGuid,                    // constant 0x1

			}; // <unnamed-tag>

			enum 
			{

				field__Count                     // constant 0x0

			}; // <unnamed-tag>

			enum
			{

				 ObjectFlag_ReadOnly                  // constant 0xFFFF8000
				 ObjectFlag_PendingResolve,                     // constant 0x4000
				 ObjectFlag_Aggregated,                     // constant 0x2000
				 ObjectFlag_Exported,                     // constant 0x1000
				 ObjectFlag_Destroyed,                     // constant 0x800
				 ObjectFlag_Invalid,                     // constant 0x400
				 ObjectFlag_Coverage,                     // constant 0x200
				 ObjectFlag_HasInstanceEntry,                     // constant 0x100

			}; // <unnamed-tag>

			class fb::DatabasePartition *void* m_partition;                     // 0x4
			unsigned int m_refCnt;                     // 0x8
			unsigned short m_flags;                     // 0xC
			virtual void * __vecDelDtor(unsigned int);	// V: 0x4

		}; // fb::DataContainer*/
		PAD(20);
		enum 
		{

			 field__Base,                     // constant 0xFF
			 field_Icon,                     // constant 0x0
			 field_IconFadeDistance,                     // constant 0x1
			 field_IconMaxDistance,                     // constant 0x2
			 field_TextFadeDistance,                     // constant 0x3
			 field_TextMaxDistance,                     // constant 0x4
			 field_HealthFadeDistance,                     // constant 0x5
			 field_HealthMaxDistance,                     // constant 0x6
			 field_TextColor,                     // constant 0x7
			 field_Targetimer,                     // constant 0x8
			 field_TargetOutTimer,                     // constant 0x9
			 field__Count               // constant 0xA

		}; // <unnamed-tag>

		Vec3 m_textColor;                     // 0x10
		float m_iconFadeDistance;                     // 0x20
		float m_iconMaxDistance;                     // 0x24
		UIHudIcon m_icon;                     // 0x28
		float m_textFadeDistance;                     // 0x2C
		float m_healthFadeDistance;                     // 0x30
		float m_healthMaxDistance;                     // 0x34
		float m_textMaxDistance;                     // 0x38
		float m_targetInTimer;                     // 0x3C
		float m_targetOutTimer;                     // 0x40
		virtual void * __vecDelDtor(unsigned int);	// V: 0x4

	}; // fb::UINametag

	enum UIUpdateType
	{

		UIUpdateType_Always,                    // constant 0x0
		UIUpdateType_Odd,                   // constant 0x1
		UIUpdateType_Even,                  // constant 0x2
		UIUpdateType_Never                     // constant 0x3

	}; // fb::UIUpdateType

	class IUIComponent // Inherited class at offset 0x0
	{
		virtual void * __vecDelDtor(unsigned int);	// V: 0x0
		virtual void initComponent(/*class fb::UISystem *, class fb::IUIMovieInstance **/void*,void*);	// V: 0x4
		virtual void activate(bool);	// V: 0x8
		virtual bool getIsActive();	// V: 0xC
		virtual void update(float);	// V: 0x10
		virtual bool shouldUpdate();	// V: 0x14
		virtual float getDeltaSinceLastUpdate(float, unsigned int);	// V: 0x18
		virtual bool getRenderException();	// V: 0x1C
		virtual void clearMovieReferences();	// V: 0x20
		virtual void getRefreshData(/*class fb::UIDataValue &*/void*);	// V: 0x24
		virtual bool getDataValue(const int,/*class fb::UIDataValue &*/void*);	// V: 0x28
		virtual bool setDataValue(const int, /*const class fb::UIDataValue &*/void*);	// V: 0x2C
			

	}; // fb::IUIComponent

	class UIComponent :public IUIComponent // Inherited class at offset 0x0
	{
		/*const class fb::UIComponentData & */void*m_data;                     // 0x4
		bool m_renderException;                     // 0x8
		/*class eastl::fixed_vector<int,4,1,fb::eastl_arena_allocator>*/void* m_messageCategories;                     // 0xC
		/*class GPtr<GFxFunctionHandler>[0x2]*/void* m_functionHandler;                     // 0x30
		float m_deltaSinceLastUpdate;                     // 0x38
		const enum fb::UIUpdateType m_updateType;                     // 0x3C
		const int m_updateFrequency;                     // 0x40
		bool m_isActive;                     // 0x44
		virtual void * __vecDelDtor(unsigned int);	// V: 0x0

	}; // fb::UIComponent
 
	class UINametagComp
	{

		class UI3dIconComp // Inherited class at offset 0x0
		{

			class VeniceUIComponent // Inherited class at offset 0x0
				 :public UIComponent
			{

				virtual void * __vecDelDtor(unsigned int);	// V: 0x0

			}; // fb::VeniceUIComponent

			class UI3dPosInfo
			{

				struct fb::Vec2 screenCoord;                     // 0x0
				float scaleFactor;                     // 0x8

			}; // UI3dPosInfo

			class UI3dIcon
			{

				enum UISpottedInfo
				{

					UISpottedInfo_None,                   // constant 0x0
					UISpottedInfo_IconType1,                   // constant 0x1
					UISpottedInfo_IconType2,                    // constant 0x2
					UISpottedInfo_IconType3,                   // constant 0x3
					UISpottedInfo_All                    // constant 0x4

				}; // UISpottedInfo

				class LinearTransform m_lastGoodTransformation;                     // 0x10
				class LinearTransform m_transformation;                     // 0x50
				class LinearTransform m_centerTransformation;                     // 0x90
				float m_animationTimeStart;                     // 0xD0
				float m_animationTimeLeft;                     // 0xD4
				float m_timeSinceTransformationUpdate;                     // 0xD8
				bool m_resetAnimationTime;                     // 0xDC
				struct fb::Vec2 m_shrinkSnapCenter;                     // 0xE0
				struct fb::Vec2 m_snapIconPos;                     // 0xE8
				struct fb::Vec2 m_arrowPos;                     // 0xF0
				struct fb::Vec3 m_offset;                     // 0x100
				struct fb::Vec4 m_iconColor;                     // 0x110
				struct fb::Vec4 m_textColor;                     // 0x120
				struct fb::Vec4 m_healthColor;                     // 0x130
				struct fb::Vec4 m_squadTextColor;                     // 0x140
				/*class eastl::fixed_vector<enum fb::UIHudIcon,3,1,fb::eastl_arena_allocator>*/void* m_iconType;                     // 0x150
				/*class fb::ExtendableStringBuilder<128>*/ void* m_text;                     // 0x170
				/*class fb::ExtendableStringBuilder<128>*/void* m_squadText;                     // 0x1FC
				float m_rotation;                     // 0x288
				bool m_blink;                     // 0x28C
				bool m_snap;                     // 0x28D
				bool m_onlyShowSnapped;                     // 0x28E
				bool m_hasUpdated;                     // 0x28F
				UISpottedInfo m_spottedInfo;                     // 0x290
				unsigned int m_id;                     // 0x294
				int m_team;                     // 0x298
				int m_distance;                     // 0x29C
				bool m_isStatic;                     // 0x2A0
				bool m_isDirty;                     // 0x2A1
				bool m_lookingAt;                     // 0x2A2
				bool m_isFocusPoint;                     // 0x2A3
				float m_focusPointRadius;                     // 0x2A4
				bool m_firstUpdate;                     // 0x2A8
				float m_progress;                     // 0x2AC
				bool m_shrinkSnapWhenClose;                     // 0x2B0
				bool m_playerIsClose;                     // 0x2B1
				float m_verticalOffset;                     // 0x2B4
				bool m_remove;                     // 0x2B8
				unsigned int m_iconTypes;                     // 0x2BC
				/*class GFxValue **/void* m_3dIconRef;                     // 0x2C0
				virtual void * __vecDelDtor(unsigned int);	// V: 0x0

			}; // UI3dIcon

			/*class fb::IUIMovieInstance **/void* m_root;                     // 0x48
			class fb::ClientControllableEntity * m_target;                     // 0x4C
			/*class eastl::fixed_list<fb::UI3dIconComp::UI3dIcon *,64,1,fb::eastl_arena_allocator>*/void* m_tags;                     // 0x50
			class fb::ClientControllableEntity * m_tmpTarget;                     // 0x37C
			unsigned int m_debugInstanceId;                     // 0x380
			float m_displayWidth;                     // 0x384
			float m_displayHeight;                     // 0x388
			float m_targetInTimer;                     // 0x38C
			float m_targetOutTimer;                     // 0x390
			float m_startTargetInTimer;                     // 0x394
			float m_startTargetOutTimer;                     // 0x398
			LinearTransform m_viewProjection;                     // 0x3A0
			Vec3 m_playerPosition;                     // 0x3E0
			bool m_enabled;                     // 0x3F0
			bool m_capturePointTrackingEnabled;                     // 0x3F1
			bool m_show3dIcon;                     // 0x3F2
			int m_maxTagUpdatesPerFrame;                     // 0x3F4
			virtual void * __vecDelDtor(unsigned int);	// V: 0x0

		}; // fb::UI3dIconComp

		/*class fb::UIHud::UIHudDraw // Inherited class at offset 0x400
		{

			virtual void * __vecDelDtor(unsigned int);	// V: 0x0

		}; // fb::UIHud::UIHudDraw*/
		PAD(4);// 0x400

		bool m_bUseFlash;                     // 0x404
		UIHudIcon m_iconWhenOrderSent;                     // 0x408
		float m_lastOrderTime; // 0x40C
		PAD(100);
		/*class ComponentFunctionHandler
		{

			class UIComponent::FunctionHandler<fb::UINametagComp> // Inherited class at offset 0x0
			{

				class GFxFunctionHandler // Inherited class at offset 0x0
				{

					class GRefCountBase<GFxFunctionHandler,2> // Inherited class at offset 0x0
					{

						class GRefCountBaseStatImpl<GRefCountImpl,2> // Inherited class at offset 0x0
						{

							class GRefCountImpl // Inherited class at offset 0x0
							{

								class GRefCountImplCore // Inherited class at offset 0x0
								{

									volatile int RefCount;                     // 0x4
									virtual void * __vecDelDtor(unsigned int);	// V: 0x0

								}; // GRefCountImplCore

								virtual void * __vecDelDtor(unsigned int);	// V: 0x0

							}; // GRefCountImpl

																			virtual void * __vecDelDtor(unsigned int);	// V: 0x0

						}; // GRefCountBaseStatImpl<GRefCountImpl,2>

						enum 
						{

							StatType;                     // constant 0x2

						}; // <unnamed-tag>

						virtual void * __vecDelDtor(unsigned int);	// V: 0x0

					}; // GRefCountBase<GFxFunctionHandler,2>

					class Params
					{

						class GFxValue * pRetVal;                     // 0x0
						class GFxMovieView * pMovie;                     // 0x4
						class GFxValue * pThis;                     // 0x8
						class GFxValue * pArgsWithThisRef;                     // 0xC
						class GFxValue * pArgs;                     // 0x10
						unsigned int ArgCount;                     // 0x14
						void * pUserData;                     // 0x18

					}; // Params

					virtual void Call(const struct GFxFunctionHandler::Params &);	// V: 0x4
																	virtual void * __vecDelDtor(unsigned int);	// V: 0x0

				}; // GFxFunctionHandler

				virtual void Call(const struct GFxFunctionHandler::Params &);	// V: 0x0
				class GFxValue m_global;                     // 0x8
				class GFxValue m_globalData;                     // 0x18
				class GFxValue m_ctor;                     // 0x28
				class fb::UINametagComp * m_component;                     // 0x38
				class GFxMovieView * m_movie;                     // 0x3C
				virtual void * __vecDelDtor(unsigned int);	// V: 0x0
			}; // fb::UIComponent::FunctionHandler<fb::UINametagComp>

			enum Function
			{

				Function_GetData,                    // constant 0x0
				Function_SetData,                   // constant 0x1
				Function_OnWidgetUnload                   // constant 0x2

			}; // Function

			class GFxValue m_object;                     // 0x40
			virtual void * __vecDelDtor(unsigned int);	// V: 0x0

		}; // ComponentFunctionHandler
		*/


		class UINametag3dIcon
		{
			//UINametagComp
			class UI3dIcon // Inherited class at offset 0x0
			{

				enum UISpottedInfo
				{

					UISpottedInfo_None,                    // constant 0x0
					 UISpottedInfo_IconType1,                     // constant 0x1
					UISpottedInfo_IconType2,                    // constant 0x2
					UISpottedInfo_IconType3,                     // constant 0x3
					 UISpottedInfo_All                     // constant 0x4

				}; // UISpottedInfo

				LinearTransform m_lastGoodTransformation;                     // 0x10
				LinearTransform m_transformation;                     // 0x50
				LinearTransform m_centerTransformation;                     // 0x90
				float m_animationTimeStart;                     // 0xD0
				float m_animationTimeLeft;                     // 0xD4
				float m_timeSinceTransformationUpdate;                     // 0xD8
				bool m_resetAnimationTime;                     // 0xDC
				struct fb::Vec2 m_shrinkSnapCenter;                     // 0xE0
				struct fb::Vec2 m_snapIconPos;                     // 0xE8
				struct fb::Vec2 m_arrowPos;                     // 0xF0
				struct fb::Vec3 m_offset;                     // 0x100
				struct fb::Vec4 m_iconColor;                     // 0x110
				struct fb::Vec4 m_textColor;                     // 0x120
				struct fb::Vec4 m_healthColor;                     // 0x130
				struct fb::Vec4 m_squadTextColor;                     // 0x140
/*				class eastl::fixed_vector<enum fb::UIHudIcon,3,1,fb::eastl_arena_allocator>*/void* m_iconType;                     // 0x150
				/*class fb::ExtendableStringBuilder<128>*/ void* m_text;                     // 0x170
				/*class fb::ExtendableStringBuilder<128>*/void* m_squadText;                     // 0x1FC
				float m_rotation;                     // 0x288
				bool m_blink;                     // 0x28C
				bool m_snap;                     // 0x28D
				bool m_onlyShowSnapped;                     // 0x28E
				bool m_hasUpdated;                     // 0x28F
				UISpottedInfo m_spottedInfo;                     // 0x290
				unsigned int m_id;                     // 0x294
				int m_team;                     // 0x298
				int m_distance;                     // 0x29C
				bool m_isStatic;                     // 0x2A0
				bool m_isDirty;                     // 0x2A1
				bool m_lookingAt;                     // 0x2A2
				bool m_isFocusPoint;                     // 0x2A3
				float m_focusPointRadius;                     // 0x2A4
				bool m_firstUpdate;                     // 0x2A8
				float m_progress;                     // 0x2AC
				bool m_shrinkSnapWhenClose;                     // 0x2B0
				bool m_playerIsClose;                     // 0x2B1
				float m_verticalOffset;                     // 0x2B4
				bool m_remove;                     // 0x2B8
				unsigned int m_iconTypes;                     // 0x2BC
				class GFxValue * m_3dIconRef;                     // 0x2C0
							virtual void * __vecDelDtor(unsigned int);	// V: 0x0

			}; // fb::UI3dIconComp::UI3dIcon

					int m_nrOfPassengers;                     // 0x2D0
			int m_nrOfEntries;                     // 0x2D4
			float m_health;                     // 0x2D8
				virtual void * __vecDelDtor(unsigned int);	// V: 0x0

		}; // UINametag3dIcon

		virtual void * __vecDelDtor(unsigned int);	// V: 0x0

	}; // fb::UINametagComp


};

#endif
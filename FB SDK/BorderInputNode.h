#ifndef _BorderInputNode_H
#define _BorderInputNode_H

namespace fb
{
	class BorderInputNode
	{
	public:
	virtual void init();
	virtual void exit();
	virtual void clear();
    virtual void suppressButtons(); // V: 0x10
    virtual float getLevel(InputConceptIdentifiers, bool);        // V: 0x14
    virtual float getLevel2(const class fb::InputActions *, bool); // V: 0x18
    virtual bool isDown(enum fb::InputConceptIdentifiers, bool);   // V: 0x1C
    virtual bool isDown2(const class fb::InputActions *, bool);    // V: 0x20
    virtual bool wentDown(enum fb::InputConceptIdentifiers);       // V: 0x24
    virtual bool wentDown2(const class fb::InputActions *);        // V: 0x28
    virtual bool wentUp(InputConceptIdentifiers); // V: 0x2C
    virtual bool wentUp2(const class fb::InputActions *);  // V: 0x30
    virtual bool isMouseActive();   // V: 0x34
    virtual Pad * getPad();      // V: 0x38
    virtual class MotionController *getMotionController();    // V: 0x3C
    virtual class IMouse * getMouse(); // V: 0x40
    virtual IKeyboard * getKeyboard();   // V: 0x44
    virtual void setUIInputTyping(bool);    // V: 0x48
    virtual void setUIInputClicking(bool, int);     // V: 0x4C
    virtual void setUICursorPosition(int, int);     // V: 0x50
    virtual void setUICursorRect(bool, unsigned int, unsigned int, unsigned int, unsigned int);     // V: 0x54
    virtual void updateBetweenFrames(float);        // V: 0x58
    virtual /*class fb::InputActionData **/void* getTriggeredInputAction(); // V: 0x5C
    virtual bool getTriggeredInputAction(/*class fb::InputActionData &*/void*);     // V: 0x60
    virtual void update(float);     // V: 0x64
	virtual int preFrameUpdate(float fDeltaTime);
	//virtual void postFrameUpdate(float);	
	virtual void postFrameUpdate(float);	// V: 0x6C
	 static BorderInputNode* Singleton()
	 {
		 DWORD BORDERINPUTNODE=0x02384EB8;
		 return *(BorderInputNode**)BORDERINPUTNODE;
	 }


	 //September 4 Patch Changes
//	PAD(8);
	 //commented cause i added postframe virtual
	char unknown0[4];
	InputCache* m_inputCache;
	//new
	bool m_forceReadCache;                     // 0x8
    char pad[0x3];
    Pad * m_pad;								 // 0xC
    MotionController * m_motionController;      // 0x10
    IKeyboard *m_keyboard;                     // 0x14
    IMouse * m_mouse;                     // 0x18
    byte m_disableInput;                     // 0x1C
    byte m_mouseActive;                     // 0x1D
    char pad2[0x2];
    EntryInputActionMap * m_defaultInputConceptDefinition;  // 0x20
    byte m_ps3EnterOnCircle;                     // 0x24
    char pad3[0x3];
	};
	
	class InputCache
    {
    public:
			//PAD(12);
            byte m_disableCache;                     // 0x0
            char pad[0x3];
            float flInputBuffer[123];                    // 0x4
            float m_juiceConceptCache[123];                     // 0x1F0
            float m_prevJuiceConceptCache[123];                     // 0x3DC
            /*class fb::Buffer**/void* m_recordData;                     // 0x5C8
            /*class fb::Buffer**/void* m_replayData;                     // 0x5CC
            class WeakPtr</*fb::JuiceController*/void*> m_juiceController;                     // 0x5D0
    };


};

#endif
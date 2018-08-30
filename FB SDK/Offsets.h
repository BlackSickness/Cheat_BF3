#ifndef __OFFSETS__H_
#define __OFFSETS__H_


typedef enum 
{ 
		
	ENTITY_CLIENTGAMECONTEXT		 

} OFFSET_ID; 

#define INPUT_FORWARD 2
#define INPUT_BACKWARD 3
#define INPUT_RIGHT 1 
#define INPUT_PITCH 6
#define INPUT_YAW 7
#define INPUT_FIRE 10
#define INPUT_ALTFIRE 11
#define INPUT_RELOAD 13
#define INPUT_ZOOM 14
#define INPUT_TOGGLELIGHT 18
#define INPUT_JUMP 19
#define INPUT_CROUCH 20
#define INPUT_PRONE 22 
#define INPUT_DEFIB 28
#define INPUT_SECONDARY 30
#define INPUT_STAB 43 //for mellee
#define INPUT_GRENADE 44
#define INPUT_AUTOSEMI 45  // chage firemode

typedef enum 
{ 
	ENTITY_CLIENT_WEAPON		= 0x0E6,
	//bullet 0x0FC missile 0x0F5
	ENTITY_CLIENT_EXPLOSIVE		= 0x0F8 ,
	ENTITY_CLIENT_VEHICLE       = 0x104 , 
    ENTITY_CLIENT_SOLDIER       = 0x106 ,
    ENTITY_CLIENT_SUPPLYBOX     = 0x0F9 ,
    ENTITY_CLIENT_PICKUP        = 0x10D , 

	ENTITY_CLIENT_MISSILE		= 245	,
    ENTITY_CLIENT_GRENADE       = 246 

} EntityID; 

// December Patch
#define BF3_X						"bf3.exe"	
#define BF3_X_BASE					0x400000	// GameBase
#define BF3_X_SIZE					0x0208A000 	// GameSize
//#define OFFSET_CLIENTGAMECONTEXT	0x02342AE4	// pattern logged or in IDA
//#define OFFSET_BORDERINPUTNODE		0x023468F0	// pattern logged or in IDA search call fb__InputManager__calculateCurrentInput first dword and 2 more 
//#define OFFSET_DXRENDERER			0x0232B6E4	// pattern or search for fb__ArithmeticCodec__ArithmeticCode above that the subroutine has 2 calls to dxrenderer
//#define OFFSET_GAMERENDERER			0x023468B4	// pattern or search call fb__RenderView__updateMatrices 2nd call in search has offset

//#define OFFSETiniMap 0x9F5890

//#define pbcl_BASE						0x0C070000//0x0B8F0000
//#define OFFSET_CLEANSCREENSHOT			0x238B7D0	// fb__ScreenshotCapture_getStatus     0x238A320
//#define OFFSET_PBSS_BUFFER				0x233d978	// pattern or pbSDK__ReceiveSS  
//#define OFFSET_PBSS_TAKESS			0x00744B90 // Function - BF3_X_BASE = IDA Address
//#define OFF_SCREENSHOTDONE				0x737460	// 0x337460 + Base check first xRef for vtable
//#define OFF_SCREENSHOT_BUFFER			0xBA7B5B	// check two asm CALL after eachother, first one is function we want
//#define OFFSET_takePunkbusterScreenshot 0x48AA01D   // 0x11A4450	// 0x7A4450 + Base mov edx, [ecx]//NEED HELP!!!
//seg000:00344B90                         fb__PunkbusterScreenshot__takeScreenshot: +  BF3_X_BASE = OFFSET_PBSS_TAKESS


//#define OFFSET_UPDATEBONES				0xfeb9a0 



//#define OFF_CameraShakeManager			0x20EBCC0	//unknown

//#define OFFSET_GIVEDAMAGE				0x0082DAA0 // Function - BF3_X_BASE = IDA Address
//#define OFFSET_COMPUTEAAB  			0x00C7E220 // Function - BF3_X_BASE = IDA Address
//#define OFFSET_AABWORLDTRANSFORM		0x00C7AE80 // Function - BF3_X_BASE = IDA Address

//#define OFFSET_DBGRENDERER2			0x004B2D70 // Function - BF3_X_BASE = IDA Address
//#define OFFSET_DBGRENDRAWTEXT			0x4B74E0	// seach Debugrenderer2 56 57 8B 7C 24 14 8B C7 8D 70 01
//#define OFFSET_DBGRENDRAW2DLINE			0x4B9850	// seach Debugrenderer2
//#define OFFSET_DBGRENDRAWRECTLINE		0x4BA1B0	// seach Debugrenderer2
//#define OFFSET_DBGRENDRAWRECT			0x4BA3C0	// seach Debugrenderer2
//#define OFFSET_DBGRENDRAWTRIANGLE		0x4BA0F0	// seach Debugrenderer2
//#define OFFSET_DBGRENDRAWSPHERE			0x4B76B0	// seach Debugrenderer2
//#define OFFSET_PLAYERSCOREMANAGER		0x20E06AC	// pattern wrong look again.
//#define OFFSET_GETCLIENTPLAYERSCORE		0x11638F0	// first Xref in Clientplayerscoremanager + Base
//#define OFFSET_UPDATEMATRICES			0x006B86F0 // Function - BF3_X_BASE = IDA Address or seach fb__RenderView__updateMatrices
//#define OFFSET_W2S					0x01257970 // Function - BF3_X_BASE = IDA Address
//#define OFFSET_RS_BEGINDRAW			0x00674D01 // Function - BF3_X_BASE = IDA Address
//#define OFFSET_CLIENTPLAYER_ENTRY		0x00BD2BC0 // Function - BF3_X_BASE = IDA Address
//#define OFFSET_CSW_GETWEAPON			0x00C452B0 // Function - BF3_X_BASE = IDA Address
//#define OFFSET_CSW_GETHEAT			0x00CC4D90 // Function - BF3_X_BASE = IDA Address
//#define OFFSET_VISUALUPDATE				0x117AC20	// seach fb__ClientComponent__visualUpdate + Base

//0x5A3782
//0x9A3782
//needed old
//#define MINIMAP			0x9A378B
//not needed still old offsets
//old Offsets Close Quarter Patch
#define OFFSET_PHYSICSRAYQUERYVTABLE	0x021E9B48


extern DWORD MAIN;
extern DWORD BORDERINPUTNODE;
extern DWORD SYSTEM;
extern DWORD CLIENTGAMECONTEXT;
extern DWORD DXRENDERER;
extern DWORD GAMERENDERER;
extern DWORD GIVEDAMAGE;
extern DWORD VISUALUPDATE;
extern DWORD RECOILVT;
extern DWORD DEVIATIONVT ;
extern DWORD SPOTMSG;
extern DWORD TYPEMANAGER;
extern DWORD KINDOFQUERY;
extern DWORD MODULEMANAGER;

extern DWORD PB_CL_BASE;
extern DWORD PLAYERSCOREMANAGER;
extern DWORD COMPUTEAAB;
extern DWORD AABWORLDTRANSFORM;
extern DWORD UPDATEMATRICES;
extern DWORD WORLDTOSCREEN;
extern DWORD RS_BEGINDRAW;
extern DWORD CLIENTPLAYER_ENTRY;
extern DWORD CSW_GETWEAPON;
extern DWORD CSW_GETHEAT;

extern DWORD PBSS_BUFFER;
extern DWORD SS_MODULE;

extern DWORD dwWEAPONSWAY;

extern DWORD DBGRENDERER2;
extern DWORD DBGRENDRAWTEXT;
extern DWORD DBGRENDRAW2DLINE	;//		0x4B9850	// seach Debugrenderer2
extern DWORD DBGRENDRAWRECTLINE;//		0x4BA1B0	// seach Debugrenderer2
extern DWORD DBGRENDRAWRECT	;//		0x4BA3C0	// seach Debugrenderer2
extern DWORD DBGRENDRAWTRIANGLE;//		0x4BA0F0	// seach Debugrenderer2
extern DWORD DBGRENDRAWSPHERE;

extern DWORD UPDATEBONES	;
extern DWORD MINIMAP;

extern  DWORD GET_CLIENTPLAYER_SCORE;

#endif



/*thispointer for ClientPlayerScoreManager:
Code:
*(ClientPlayerScoreManager**)((*(DWORD*)0x023BD8AC)+0x40)	*/
//0073E071 addy in ida
//007E2A60 addy in ida									     0x400000
//offset call in func from ida 20C9CEC this maybe it at addy 0x00BE5A65  


/*
//not working
#define OFFSET_GETCLIENTPLAYERSCORE		0x11566A0//0x11566A0 // 0x00AF0508;//0x0A115F0;

// all old Working Offsets for Armored Kill
#define BF3_MP							"bf3.exe"										
#define BF3_MP_BASE						0x400000
#define BF3_MP_SIZE						0x2053000
#define OFFSET_MAIN						0x22B67C0
#define OFFSET_CLIENTGAMECONTEXT		0x233FC74
#define OFFSET_GAMERENDERER				0x2343A44
#define OFFSET_DXRENDERER				0x2323D94
//										002B8610 -> update matrices
//										00752B70 -> visual update clientcomp
									  //0x00400000
									  //0x0207AA08
#define MINIMAP			0x6FBCA0//0x0040D9AE
#define OFFSET_VISUALUPDATE				0x01152B70 //seg000:00B52B70 fb__ClientComponent__visualUpdate
#define OFFSET_UPDATEMATRICES			0x6B8610
#define OFFSET_UPDATEBONES				0xC32BE0
#define OFFSET_BORDERINPUTNODE			0x2343A80
#define OFFSET_GIVEDAMAGE				0x99F800  			 
#define OFFSET_DBGRENDERER2				0x04B28E0
#define OFFSET_DBGRENDRAWTEXT			0x004B7070
#define OFFSET_DBGRENDRAW2DLINE			0x004B92D0
#define OFFSET_DBGRENDRAWRECTLINE		0x004B9BA0
#define OFFSET_DBGRENDRAWRECT			0x004B9DB0
#define	OFFSET_DBGRENDRAWSPHERE			0x004B7240
#define	OFFSET_DBGRENDRAWTRIANGLE		0x004B9AE0
//my simple blocker
#define OFFSET_BLOCKSCREENSHOT			0x2380EE0
//zoomgods blocker of addy2380EE0
#define OFFSET_PBRECEIVESS				0x2334418	

#define OFFSET_SCREENPROJECT            0x0947090
#define OFFSET_PLAYERSCOREMANAGER		0x20C9CEC
#define OFFSET_CLIENTSCOREMANAGER		0x023BD8AC +0x40
#define OFFSET_GETRECOILVTABLE			0x209BA34
 sub_7638F0+31p

 #define OFFSET_SCREENPROJECT            0x0947090
 #define OFFSET_UPDATEBONES                0x0C32BE0

 GetRecoil 0x008C73A0
GetRecoil RDATA Reference 0x0209BA34


  add     edi, 4
seg000:000136EC                 cmp     edi, ebx
seg000:000136EE                 jnz     short loc_136E0
*/

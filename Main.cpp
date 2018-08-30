#include "FB SDK\Frostbite.h"

#include "VMT.h"
#include "Functions.h"
#include "Drawing.h"

#pragma region
void* operator new[](size_t size, const char* pName, int flags, unsigned debugFlags, const char* file, int line)
{
	return malloc(size);
}
void* operator new[](size_t size, size_t alignment, size_t alignmentOffset, const char* pName, int flags, unsigned debugFlags, const char* file, int line)
{
	EASTL_ASSERT(alignment <= 8);
	return malloc(size);
}
#pragma endregion EASTL

#pragma region
VMT::VMTHookManager PreFrameHook;
typedef int(__stdcall* tPreFrameUpdate)(float dt);
tPreFrameUpdate oPreFrameUpdate = 0;
fb::BorderInputNode* g_pBorderInputNode = fb::BorderInputNode::Singleton();

VMT::VMTHookManager PresentHook;
typedef signed int(__stdcall* tPresent)(int, int, int);
tPresent oPresent;
#pragma endregion Hook

#pragma region
float g_pInputBuffers[123];

DWORD GIVEDAMAGE = 0x00770F40;

bool bDrawMenu = false;

bool bAutoSpot = false;

bool bPerfectJet = false;

bool bAutoStandUp = false;

bool bNoRecoil = false;
bool bNoBreath = false;
bool bNoSpread = false;
bool bNoSway = false;
bool bInstantBullet = false;

std::map<int, fb::WeaponModifier*> oldModifier;

bool bMagicBullets = false;

bool bAimbot = false;
bool bAimHead = false;
bool bVisibilityChecks = false;

bool bBoxESP = false;
bool bBones = false;
bool bHealthbar = false;
bool bNames = false;
bool bDistance = false;
bool bSnaplines = false;

bool bMinimapHack = false;
bool bForceSquadSpawn = false;
bool bSpottedExplosive = false;

int nMenuindex = 0;
int nMenuelements = 21;
#pragma endregion Global Vars

fb::Color32 red = fb::Color32(255, 0, 0, 255);
fb::Color32 green = fb::Color32(0, 255, 0, 255);

fb::Color32 black = fb::Color32(0, 0, 0, 255);
fb::Color32 white = fb::Color32(255, 255, 255, 255);

DWORD WINAPI PBSSThread(LPVOID a)
{
	while (true)
	{
		*(PDWORD)0x233D978 = 0;
		*(DWORD*)0x0235DB14 = 0;
	}
	return 1;
};

void MouseMenu()
{
	if (bDrawMenu)
	{
		fb::DebugRenderer2::Singleton()->DrawRect(0, 0, 185, 1000, fb::Color32(0, 0, 0, 180));

		bAimbot ? fb::DebugRenderer2::Singleton()->drawText(5, 20, green, "Aimbot             [X]") : fb::DebugRenderer2::Singleton()->drawText(5, 20, red, "Aimbot             [ ]");
		bAimHead ? fb::DebugRenderer2::Singleton()->drawText(5, 35, green, "Aim at Head        [X]") : fb::DebugRenderer2::Singleton()->drawText(5, 35, red, "Aim at Head        [ ]");
		bVisibilityChecks ? fb::DebugRenderer2::Singleton()->drawText(5, 50, green, "Visibility Checks  [X]") : fb::DebugRenderer2::Singleton()->drawText(5, 50, red, "Visibility Checks  [ ]");

		bBoxESP ? fb::DebugRenderer2::Singleton()->drawText(5, 100, green, "Box ESP            [X]") : fb::DebugRenderer2::Singleton()->drawText(5, 100, red, "Box ESP            [ ]");
		bBones ? fb::DebugRenderer2::Singleton()->drawText(5, 115, green, "Bones ESP          [X]") : fb::DebugRenderer2::Singleton()->drawText(5, 115, red, "Bones ESP          [ ]");
		bHealthbar ? fb::DebugRenderer2::Singleton()->drawText(5, 130, green, "Health ESP         [X]") : fb::DebugRenderer2::Singleton()->drawText(5, 130, red, "Health ESP         [ ]");
		bNames ? fb::DebugRenderer2::Singleton()->drawText(5, 145, red, "Names ESP          [X]") : fb::DebugRenderer2::Singleton()->drawText(5, 145, red, "Names ESP          [ ]");
		bDistance ? fb::DebugRenderer2::Singleton()->drawText(5, 160, green, "Distance ESP       [X]") : fb::DebugRenderer2::Singleton()->drawText(5, 160, red, "Distance ESP       [ ]");
		bSnaplines ? fb::DebugRenderer2::Singleton()->drawText(5, 175, green, "Snapline ESP       [X]") : fb::DebugRenderer2::Singleton()->drawText(5, 175, red, "Snapline ESP       [ ]");

		bNoRecoil ? fb::DebugRenderer2::Singleton()->drawText(5, 225, green, "No Recoil          [X]") : fb::DebugRenderer2::Singleton()->drawText(5, 225, red, "No Recoil          [ ]");
		bNoSpread ? fb::DebugRenderer2::Singleton()->drawText(5, 240, green, "No Spread          [X]") : fb::DebugRenderer2::Singleton()->drawText(5, 240, red, "No Spread          [ ]");
		bNoBreath ? fb::DebugRenderer2::Singleton()->drawText(5, 255, green, "No Breath          [X]") : fb::DebugRenderer2::Singleton()->drawText(5, 255, red, "No Breath          [ ]");
		bNoSway ? fb::DebugRenderer2::Singleton()->drawText(5, 270, green, "No Sway            [X]") : fb::DebugRenderer2::Singleton()->drawText(5, 270, red, "No Sway            [ ]");
		bInstantBullet ? fb::DebugRenderer2::Singleton()->drawText(5, 285, green, "Instant Bullet     [X]") : fb::DebugRenderer2::Singleton()->drawText(5, 285, red, "Instant Bullet     [ ]");

		bAutoSpot ? fb::DebugRenderer2::Singleton()->drawText(5, 365, green, "Auto Spot          [X]") : fb::DebugRenderer2::Singleton()->drawText(5, 365, red, "Auto Spot          [ ]");
		bPerfectJet ? fb::DebugRenderer2::Singleton()->drawText(5, 380, green, "Perfect Jet        [X]") : fb::DebugRenderer2::Singleton()->drawText(5, 380, red, "Perfect Jet        [ ]");
		bAutoStandUp ? fb::DebugRenderer2::Singleton()->drawText(5, 395, green, "Auto StandUp       [X]") : fb::DebugRenderer2::Singleton()->drawText(5, 395, red, "Auto StandUp       [ ]");
		bMagicBullets ? fb::DebugRenderer2::Singleton()->drawText(5, 410, green, "Magic Bullets      [X]") : fb::DebugRenderer2::Singleton()->drawText(5, 410, red, "Magic Bullets      [ ]");
		bMinimapHack ? fb::DebugRenderer2::Singleton()->drawText(5, 425, green, "Minimap Hack       [X]") : fb::DebugRenderer2::Singleton()->drawText(5, 425, red, "Minimap Hack       [ ]");
		bForceSquadSpawn ? fb::DebugRenderer2::Singleton()->drawText(5, 440, green, "Force Squad Spawn  [X]") : fb::DebugRenderer2::Singleton()->drawText(5, 440, red, "Force Squad Spawn  [ ]");
		bSpottedExplosive ? fb::DebugRenderer2::Singleton()->drawText(5, 455, green, "Spotted Explosive  [X]") : fb::DebugRenderer2::Singleton()->drawText(5, 455, red, "Spotted Explosive  [ ]");
	}
}
DWORD WINAPI MouseThread(LPVOID lpArgs)
{
	while (1)
	{
		if (GetAsyncKeyState(0x2E))
		{ //del key
			bDrawMenu = !bDrawMenu;
			if (!bDrawMenu) g_pBorderInputNode->m_mouse->setCursorPosition(fb::DxRenderer::Singleton()->m_screenInfo.m_nWidth / 2, fb::DxRenderer::Singleton()->m_screenInfo.m_nHeight / 2);
			bDrawMenu ? g_pBorderInputNode->m_mouse->enableCursorMode(true, 1) : g_pBorderInputNode->m_mouse->enableCursorMode(false, 1);
			Sleep(200);
		}

		if (bDrawMenu)
		{
			POINT p;
			HWND hWnd = GetForegroundWindow();
			GetCursorPos(&p);
			ScreenToClient(hWnd, &p);
			if (GetAsyncKeyState(0x1) & 1)
			{
				if (p.x >= 0 && p.x <= 185 && p.y >= 22 && p.y <= 37)
				{
					bAimbot = !bAimbot;
				}
				else if (p.x >= 0 && p.x <= 185 && p.y >= 37 && p.y <= 52)
				{
					bAimHead = !bAimHead;
				}
				else if (p.x >= 0 && p.x <= 185 && p.y >= 52 && p.y <= 67)
				{
					bVisibilityChecks = !bVisibilityChecks;
				}
				else if (p.x >= 0 && p.x <= 185 && p.y >= 102 && p.y <= 117)
				{
					bBoxESP = !bBoxESP;
				}
				else if (p.x >= 0 && p.x <= 185 && p.y >= 117 && p.y <= 132)
				{
					bBones = !bBones;
				}
				else if (p.x >= 0 && p.x <= 185 && p.y >= 132 && p.y <= 147)
				{
					bHealthbar = !bHealthbar;
				}
				else if (p.x >= 0 && p.x <= 185 && p.y >= 147 && p.y <= 162)
				{
					bNames = !bNames;
				}
				else if (p.x >= 0 && p.x <= 185 && p.y >= 162 && p.y <= 177)
				{
					bDistance = !bDistance;
				}
				else if (p.x >= 0 && p.x <= 185 && p.y >= 177 && p.y <= 192)
				{
					bSnaplines = !bSnaplines;
				}
				else if (p.x >= 0 && p.x <= 185 && p.y >= 227 && p.y <= 242)
				{
					bNoRecoil = !bNoRecoil;
				}
				else if (p.x >= 0 && p.x <= 185 && p.y >= 242 && p.y <= 257)
				{
					bNoSpread = !bNoSpread;
				}
				else if (p.x >= 0 && p.x <= 185 && p.y >= 257 && p.y <= 272)
				{
					bNoBreath = !bNoBreath;
				}
				else if (p.x >= 0 && p.x <= 185 && p.y >= 272 && p.y <= 287)
				{
					bNoSway = !bNoSway;
				}

				else if (p.x >= 0 && p.x <= 185 && p.y >= 302 && p.y <= 317)
				{
					bInstantBullet = !bInstantBullet;
				}
				
				else if (p.x >= 0 && p.x <= 185 && p.y >= 367 && p.y <= 382)
				{
					bAutoSpot = !bAutoSpot;
				}
				else if (p.x >= 0 && p.x <= 185 && p.y >= 382 && p.y <= 397)
				{
					bPerfectJet = !bPerfectJet;
				}
				else if (p.x >= 0 && p.x <= 185 && p.y >= 397 && p.y <= 412)
				{
					bAutoStandUp = !bAutoStandUp;
				}
				else if (p.x >= 0 && p.x <= 185 && p.y >= 412 && p.y <= 427)
				{
					bMagicBullets = !bMagicBullets;
				}
				else if (p.x >= 0 && p.x <= 185 && p.y >= 427 && p.y <= 442)
				{
					bMinimapHack = !bMinimapHack;
				}
				else if (p.x >= 0 && p.x <= 185 && p.y >= 442 && p.y <= 457)
				{
					bForceSquadSpawn = !bForceSquadSpawn;
				}
				else if (p.x >= 0 && p.x <= 185 && p.y >= 457 && p.y <= 472)
				{
					bSpottedExplosive = !bSpottedExplosive;
				}
			}
		}
	}
}

void MenuArrow()
{
	switch (nMenuindex)
	{
	case 0:
		fb::DebugRenderer2::Singleton()->drawText(195, 0, red, "<-");
		break;
	case 1:
		fb::DebugRenderer2::Singleton()->drawText(195, 20, red, "<-");
		break;
	case 2:
		fb::DebugRenderer2::Singleton()->drawText(195, 40, red, "<-");
		break;
	case 3:
		fb::DebugRenderer2::Singleton()->drawText(195, 60, red, "<-");
		break;
	case 4:
		fb::DebugRenderer2::Singleton()->drawText(195, 80, red, "<-");
		break;
	case 5:
		fb::DebugRenderer2::Singleton()->drawText(195, 100, red, "<-");
		break;
	case 6:
		fb::DebugRenderer2::Singleton()->drawText(195, 120, red, "<-");
		break;
	case 7:
		fb::DebugRenderer2::Singleton()->drawText(195, 140, red, "<-");
		break;
	case 8:
		fb::DebugRenderer2::Singleton()->drawText(195, 160, red, "<-");
		break;
	case 9:
		fb::DebugRenderer2::Singleton()->drawText(195, 180, red, "<-");
		break;
	case 10:
		fb::DebugRenderer2::Singleton()->drawText(195, 200, red, "<-");
		break;
	case 11:
		fb::DebugRenderer2::Singleton()->drawText(195, 220, red, "<-");
		break;
	case 12:
		fb::DebugRenderer2::Singleton()->drawText(195, 240, red, "<-");
		break;
	case 13:
		fb::DebugRenderer2::Singleton()->drawText(195, 260, red, "<-");
		break;
	case 14:
		fb::DebugRenderer2::Singleton()->drawText(195, 280, red, "<-");
		break;
	case 15:
		fb::DebugRenderer2::Singleton()->drawText(195, 300, red, "<-");
		break;
	case 16:
		fb::DebugRenderer2::Singleton()->drawText(195, 320, red, "<-");
		break;
	case 17:
		fb::DebugRenderer2::Singleton()->drawText(195, 340, red, "<-");
		break;
	case 18:
		fb::DebugRenderer2::Singleton()->drawText(195, 360, red, "<-");
		break;
	case 19:
		fb::DebugRenderer2::Singleton()->drawText(195, 380, red, "<-");
		break;
	case 20:
		fb::DebugRenderer2::Singleton()->drawText(195, 400, red, "<-");
		break;
	case 21:
		fb::DebugRenderer2::Singleton()->drawText(195, 420, red, "<-");
		break;
	}
}
void ButtonMenu()
{
	if (bDrawMenu)
	{
		MenuArrow();
		bAimbot ? fb::DebugRenderer2::Singleton()->drawText(5, 0, green, "Aimbot - ON") : fb::DebugRenderer2::Singleton()->drawText(5, 0, red, "Aimbot - OFF");
		bAimHead ? fb::DebugRenderer2::Singleton()->drawText(5, 20, green, "Aim at Head - ON") : fb::DebugRenderer2::Singleton()->drawText(5, 20, red, "Aim at Head - OFF");
		bVisibilityChecks ? fb::DebugRenderer2::Singleton()->drawText(5, 40, green, "Visibility Checks - ON") : fb::DebugRenderer2::Singleton()->drawText(5, 40, red, "Visibility Checks - OFF");

		bBoxESP ? fb::DebugRenderer2::Singleton()->drawText(5, 60, green, "Box ESP - ON") : fb::DebugRenderer2::Singleton()->drawText(5, 60, red, "Box ESP - OFF");
		bBones ? fb::DebugRenderer2::Singleton()->drawText(5, 80, green, "Bones ESP - ON") : fb::DebugRenderer2::Singleton()->drawText(5, 80, red, "Bones ESP - OFF");
		bHealthbar ? fb::DebugRenderer2::Singleton()->drawText(5, 100, green, "Health ESP - ON") : fb::DebugRenderer2::Singleton()->drawText(5, 100, red, "Health ESP - OFF");
		bNames ? fb::DebugRenderer2::Singleton()->drawText(5, 120, green, "Names ESP - ON") : fb::DebugRenderer2::Singleton()->drawText(5, 120, red, "Names ESP - OFF");
		bDistance ? fb::DebugRenderer2::Singleton()->drawText(5, 140, green, "Distance ESP - ON") : fb::DebugRenderer2::Singleton()->drawText(5, 140, red, "Distance ESP - OFF");
		bSnaplines ? fb::DebugRenderer2::Singleton()->drawText(5, 160, green, "Snapline ESP - ON") : fb::DebugRenderer2::Singleton()->drawText(5, 160, red, "Snapline ESP - OFF");

		bNoRecoil ? fb::DebugRenderer2::Singleton()->drawText(5, 180, green, "No Recoil - ON") : fb::DebugRenderer2::Singleton()->drawText(5, 180, red, "No Recoil - OFF");
		bNoSpread ? fb::DebugRenderer2::Singleton()->drawText(5, 200, green, "No Spread - ON") : fb::DebugRenderer2::Singleton()->drawText(5, 200, red, "No Spread - OFF");
		bNoBreath ? fb::DebugRenderer2::Singleton()->drawText(5, 220, green, "No Breath - ON") : fb::DebugRenderer2::Singleton()->drawText(5, 220, red, "No Breath - OFF");
		bNoSway ? fb::DebugRenderer2::Singleton()->drawText(5, 240, green, "No Sway - ON") : fb::DebugRenderer2::Singleton()->drawText(5, 240, red, "No Sway - OFF");
		bInstantBullet ? fb::DebugRenderer2::Singleton()->drawText(5, 260, green, "Instant Bullet - ON") : fb::DebugRenderer2::Singleton()->drawText(5, 260, red, "Instant Bullet - OFF");



		bAutoSpot ? fb::DebugRenderer2::Singleton()->drawText(5, 320, green, "Auto Spot - ON") : fb::DebugRenderer2::Singleton()->drawText(5, 280, red, "Auto Spot - OFF");
		bPerfectJet ? fb::DebugRenderer2::Singleton()->drawText(5, 340, green, "Perfect Jet - ON") : fb::DebugRenderer2::Singleton()->drawText(5, 300, red, "Perfect Jet - OFF");
		bAutoStandUp ? fb::DebugRenderer2::Singleton()->drawText(5, 360, green, "Auto StandUp - ON") : fb::DebugRenderer2::Singleton()->drawText(5, 320, red, "Auto StandUp - OFF");
		bMagicBullets ? fb::DebugRenderer2::Singleton()->drawText(5, 380, green, "Magic Bullets - ON") : fb::DebugRenderer2::Singleton()->drawText(5, 340, red, "Magic Bullets - OFF");
		bMinimapHack ? fb::DebugRenderer2::Singleton()->drawText(5, 400, green, "Minimap Hack - ON") : fb::DebugRenderer2::Singleton()->drawText(5, 360, red, "Minimap Hack - OFF");
		bForceSquadSpawn ? fb::DebugRenderer2::Singleton()->drawText(5, 420, green, "Force Squad Spawn - ON") : fb::DebugRenderer2::Singleton()->drawText(5, 380, red, "Force Squad Spawn - OFF");
		bSpottedExplosive ? fb::DebugRenderer2::Singleton()->drawText(5, 440, green, "Spotted Explosive - ON") : fb::DebugRenderer2::Singleton()->drawText(5, 400, red, "Spotted Explosive - OFF");
	}
	else
	{
		fb::DebugRenderer2::Singleton()->drawText(5, 0, green, "Press DEL to open menu");
	}
}
DWORD WINAPI KeyboardThread(LPVOID lpArgs)
{
	while (1)
	{
		if (GetAsyncKeyState(0x2E))
		{ //del key
			bDrawMenu = !bDrawMenu;
			Sleep(200);
		}
		if (bDrawMenu)
		{
			if (GetAsyncKeyState(0x26) && nMenuindex > 0)
			{ //arrow up
				nMenuindex--;
				Sleep(300);
			}
			if (GetAsyncKeyState(0x28) && nMenuindex < nMenuelements)
			{ //arrow down
				nMenuindex++;
				Sleep(300);
			}

			if (GetAsyncKeyState(0x0D))
			{ //enter
				switch (nMenuindex)
				{
				case 0:
					bAimbot = !bAimbot;
					Sleep(500);
					break;
				case 1:
					bAimHead = !bAimHead;
					Sleep(500);
					break;
				case 2:
					bVisibilityChecks = !bVisibilityChecks;
					Sleep(500);
					break;
				case 3:
					bBoxESP = !bBoxESP;
					Sleep(500);
					break;
				case 4:
					bBones = !bBones;
					Sleep(500);
					break;
				case 5:
					bHealthbar = !bHealthbar;
					Sleep(500);
					break;
				case 6:
					bNames = !bNames;
					Sleep(500);
					break;
				case 7:
					bDistance = !bDistance;
					Sleep(500);
					break;
				case 8:
					bSnaplines = !bSnaplines;
					Sleep(500);
					break;
				case 9:
					bNoRecoil = !bNoRecoil;
					Sleep(500);
					break;
				case 10:
					bNoSpread = !bNoSpread;
					Sleep(500);
					break;
				case 11:
					bNoBreath = !bNoBreath;
					Sleep(500);
					break;
				case 12:
					bNoSway = !bNoSway;
					Sleep(500);
					break;
				case 13:
					bInstantBullet = !bInstantBullet;
					Sleep(500);
					break;
				case 14:
					bAutoSpot = !bAutoSpot;
					Sleep(500);
					break;
				case 15:
					bPerfectJet = !bPerfectJet;
					Sleep(500);
					break;
				case 16:
					bAutoStandUp = !bAutoStandUp;
					Sleep(500);
					break;
				case 17:
					bMagicBullets = !bMagicBullets;
					Sleep(500);
					break;
				case 18:
					bMinimapHack = !bMinimapHack;
					Sleep(500);
					break;
				case 19:
					bForceSquadSpawn = !bForceSquadSpawn;
					Sleep(500);
					break;
				case 20:
					bSpottedExplosive = !bSpottedExplosive;
					Sleep(500);
					break;
				}
			}
		}
		Sleep(20);
	}
}

#pragma region AutoSpot
//Source: http://dumpz.org/398889/
typedef int(__thiscall* tSendSpot)(void* thisptr, fb::ClientPlayer*, eastl::fixed_vector<DWORD *, 8, 0>*, int);
tSendSpot SendSpot = (tSendSpot)0x7D0910; //for autospot

DWORD originalPostPhysicsUpdate = NULL;
DWORD playerWeakPtrs[64];
int spotSize = 0;
void postPhysicsUpdate(DWORD thisPtr, DWORD updateInfo, DWORD input, fb::ClientPlayer *clientPlayer)
{
	fb::ClientGameContext *context = fb::ClientGameContext::Singleton();
	if (!context) return;

	fb::ClientPlayerManager *clPlayerManager = context->m_clientPlayerManager;
	if (!clPlayerManager) return;

	eastl::vector<fb::ClientPlayer *> players = clPlayerManager->m_players;

	eastl::fixed_vector<DWORD *, 8, 0> controllablesToSpot;
	for (unsigned int i = 0; i < players.size(); i++)
	{
		fb::ClientPlayer *player = players.at(i);
		if (!player) continue;

		fb::ClientSoldierEntity *soldier = player->getSoldierEnt();
		if (!soldier) continue;

		fb::ClientControllableEntity *controllable = player->m_controlledControllable;
		if (!controllable)
			controllable = player->m_attachedControllable;

		if (!clientPlayer) continue;

		if (controllable && player->m_teamId != clientPlayer->m_teamId)
		{
			playerWeakPtrs[i] = (DWORD)controllable + 4;
			DWORD *pointerToDword = &playerWeakPtrs[i];
			controllablesToSpot.push_back(pointerToDword);
		}

		if (players.size() <= 16)
			spotSize = 2;
		else if (players.size() <= 32)
			spotSize = 4;
		else if (players.size() <= 48)
			spotSize = 6;
		else if (players.size() <= 64)
			spotSize = 8;

		if (controllablesToSpot.size() == spotSize || i == players.size() - 1)
		{
			SendSpot((void *)thisPtr, clientPlayer, &controllablesToSpot, 1);
			controllablesToSpot.clear();
		}
	}
}

DWORD postPhysicsUpdateRetAddr;
DWORD spottingComponentThisPtr; //fb::ClientSpottingComponent *
DWORD updateInfo; //fb::EntityUpdateInfo *
DWORD input; //db::EntriInput *
fb::ClientPlayer *player;
__declspec(naked) void hkPostPhysicsUpdateSync()
{
	__asm {
		pop postPhysicsUpdateRetAddr
			mov spottingComponentThisPtr, ecx
			push eax
			mov eax, [esp + 0x4]
			mov updateInfo, eax
			mov eax, [esp + 0x8]
			mov input, eax
			mov eax, [esp + 0xC]
			mov player, eax
			pop eax
			pushad
			pushfd
	}

	postPhysicsUpdate(spottingComponentThisPtr, updateInfo, input, player);
	__asm {
		popfd
			popad
			call originalPostPhysicsUpdate
			push postPhysicsUpdateRetAddr
			ret
	}
}
#pragma endregion AutoSpot

unsigned int iAutospot;
void _stdcall AutoSpot()
{
	if (bAutoSpot)
	{
		fb::ClientGameContext* g_pGameContext = fb::ClientGameContext::Singleton();
		if (!POINTERCHK(g_pGameContext)) return;

		fb::ClientPlayerManager* pPlayerManager = g_pGameContext->m_clientPlayerManager;
		if (!POINTERCHK(pPlayerManager) || pPlayerManager->m_players.empty()) return;

		fb::ClientPlayer* pLocalPlayer = pPlayerManager->m_localPlayer;
		if (!POINTERCHK(pLocalPlayer)) return;

		fb::ClientSoldierEntity* pMySoldier = pLocalPlayer->getSoldierEnt();
		if (!POINTERCHK(pMySoldier)) return;

		//if (!isalive(pMySoldier->Alive())) return;

		if (!pMySoldier->isInVehicle())
		{
			if (timeGetTime() < iAutospot + 100) return;

			DWORD *csc = pMySoldier->getComponent<DWORD>("ClientSpottingComponent");
			if (csc && ((DWORD *)*(DWORD *)csc)[40] != (DWORD)hkPostPhysicsUpdateSync)
			{
				DWORD *vtable = (DWORD *)*(DWORD *)csc;
				if (vtable[40] == (DWORD)hkPostPhysicsUpdateSync)
					return; //Already hooked

				originalPostPhysicsUpdate = vtable[40]; //Backup old function
				DWORD *newVtable = new DWORD[64]; //leave some space
				memcpy(newVtable, vtable, 64 * sizeof(DWORD));
				newVtable[40] = (DWORD)hkPostPhysicsUpdateSync;

				DWORD dwOld;
				VirtualProtect(csc, sizeof(DWORD), PAGE_EXECUTE_READWRITE, &dwOld);
				*(DWORD *)csc = (DWORD)newVtable; //Replace Vtable
				VirtualProtect(csc, sizeof(DWORD), dwOld, NULL);

				iAutospot = timeGetTime();
			}
		}
		else
		{
			if (timeGetTime() < iAutospot + 100) return;

			fb::ClientControllableEntity *pCCE = pLocalPlayer->m_attachedControllable;
			if (!POINTERCHK(pCCE)) return;

			if (!POINTERCHK(pLocalPlayer->getEntry())) return;

			fb::ClientVehicleEntity* MyVehicle = reinterpret_cast<fb::ClientVehicleEntity *>(pCCE);
			if (!POINTERCHK(MyVehicle)) return;

			DWORD *csc = MyVehicle->getComponent<DWORD>("ClientSpottingComponent");
			if (csc && ((DWORD *)*(DWORD *)csc)[40] != (DWORD)hkPostPhysicsUpdateSync)
			{
				DWORD *vtable = (DWORD *)*(DWORD *)csc;
				if (vtable[40] == (DWORD)hkPostPhysicsUpdateSync)
					return; //Already hooked

				originalPostPhysicsUpdate = vtable[40]; //Backup old function
				DWORD *newVtable = new DWORD[64]; //leave some space
				memcpy(newVtable, vtable, 64 * sizeof(DWORD));
				newVtable[40] = (DWORD)hkPostPhysicsUpdateSync;

				DWORD dwOld;
				VirtualProtect(csc, sizeof(DWORD), PAGE_EXECUTE_READWRITE, &dwOld);
				*(DWORD *)csc = (DWORD)newVtable; //Replace Vtable
				VirtualProtect(csc, sizeof(DWORD), dwOld, NULL);

				iAutospot = timeGetTime();
			}
		}
	}
}

#pragma region HookRecoil
//Source: http://dumpz.org/398889/
void hookedRecoil(fb::WeaponSway* thisptr, D3DXMATRIX* trans, bool scale)
{
	if (bNoRecoil)
	{
		thisptr->m_currentRecoilDeviation.m_pitch = 0.0f;
		thisptr->m_currentRecoilDeviation.m_yaw = 0.0f;
		thisptr->m_currentRecoilDeviation.m_roll = 0.0f;
		thisptr->m_currentRecoilDeviation.m_transY = 0.0f;

		thisptr->m_DeviationPitch = 0.0f;

		thisptr->m_currentGameplayDeviationScaleFactor = 0.00001f;
		thisptr->m_currentVisualDeviationScaleFactor = 0.00001f;

		thisptr->m_randomAngle = 0.00001f;
		thisptr->m_randomRadius = 0.00001f;

		thisptr->m_SpringPos = 0.0f;
		thisptr->m_SpringRestPos = 0.0f;
		thisptr->m_SpringVelocity = 0.0f;
		thisptr->m_fireShot = false;
		thisptr->m_initialFireShot = 0;
		//thisptr->m_isFiring = true;

		thisptr->m_currentDispersionDeviation.m_pitch = 0.0f;
		thisptr->m_currentDispersionDeviation.m_yaw = 0.0f;
		thisptr->m_currentDispersionDeviation.m_roll = 0.0f;
		thisptr->m_currentDispersionDeviation.m_transY = 0.0f;

		thisptr->m_currentLagDeviation.m_pitch = 0.0f;
		thisptr->m_currentLagDeviation.m_yaw = 0.0f;
		thisptr->m_currentLagDeviation.m_roll = 0.0f;
		thisptr->m_currentLagDeviation.m_transY = 0.0f;
	}

	if (bNoSpread)
		thisptr->m_dispersionAngle = 0.0f; //small crosshair
}

DWORD originalGetRecoil;
DWORD dwRecoilRetAddress;
fb::WeaponSway* recoilThisPtr;
D3DXMATRIX mtx;
D3DXMATRIX* arg1;
__declspec(naked) void hkGetRecoil(void)
{
	__asm
	{
		pop dwRecoilRetAddress
			mov recoilThisPtr, ecx
			push eax
			mov eax, [esp + 0x4]
			mov arg1, eax
			pop eax
			pushad
			pushfd
	}
	D3DXMatrixIdentity(&mtx);
	memcpy(arg1, mtx, 0x40);
	hookedRecoil(recoilThisPtr, arg1, false);
	__asm
	{
		popfd
			popad
			//call originalGetRecoil
			add esp, 0x8
			push dwRecoilRetAddress
			ret
	}
}
void _stdcall HookRecoil(fb::WeaponSway* pWps)
{
	if (bNoRecoil || bNoSpread)
	{
		DWORD *vtable = (DWORD *)*(DWORD *)pWps;
		if (vtable[27] != (DWORD)hkGetRecoil)
		{
			originalGetRecoil = vtable[27]; //Backup old function

			DWORD* newVtable = new DWORD[64]; //leave some space
			memcpy(newVtable, vtable, 64 * sizeof(DWORD));
			newVtable[27] = (DWORD)hkGetRecoil;

			DWORD dwOld;
			VirtualProtect(pWps, sizeof(DWORD), PAGE_EXECUTE_READWRITE, &dwOld);
			*(DWORD *)pWps = (DWORD)newVtable; //Replace Vtable
			VirtualProtect(pWps, sizeof(DWORD), dwOld, NULL);
		}
	}
}
#pragma endregion HookRecoil

void _stdcall PerfectJet()
{
	if (bPerfectJet)
	{
		fb::ClientGameContext* g_pGameContext = fb::ClientGameContext::Singleton();
		if (!POINTERCHK(g_pGameContext)) return;

		fb::ClientPlayerManager* pPlayerManager = g_pGameContext->m_clientPlayerManager;
		if (!POINTERCHK(pPlayerManager) || pPlayerManager->m_players.empty()) return;

		fb::ClientPlayer* pLocalPlayer = pPlayerManager->m_localPlayer;
		if (!POINTERCHK(pLocalPlayer)) return;

		fb::ClientSoldierEntity* pMySoldier = pLocalPlayer->getSoldierEnt();
		if (!POINTERCHK(pMySoldier)) return;

		if (!pMySoldier->IsAlive()) return;

		if (!pMySoldier->isInVehicle()) return;

		fb::ClientControllableEntity *controllable = pLocalPlayer->m_attachedControllable;
		if (!POINTERCHK(controllable)) return;

		fb::ClientVehicleEntity* vehicle = reinterpret_cast<fb::ClientVehicleEntity *>(controllable);
		if (!POINTERCHK(vehicle)) return;

		DWORD fb__velocity = (DWORD)controllable;
		float velocity = 0.0f;
		if (fb__velocity)
		{
			velocity = *(float *)(fb__velocity + 0x98);
			velocity *= 3.6f;
		}

		fb::PhysicsEntity *pPhysEntity = vehicle->m_physicsEntity;
		if (!POINTERCHK(pPhysEntity)) return;

		fb::PhysicsEntityData *pPhysEntityData = pPhysEntity->m_data;
		if (!POINTERCHK(pPhysEntityData)) return;

		// we are in a jet 
		if (strcmp(pPhysEntityData->GetObjectName(), "F18-F") == 0 //US Conquest
|| strcmp(pPhysEntityData->GetObjectName(), "SU-35BM-E") == 0 //RU Conquest
|| strcmp(pPhysEntityData->GetObjectName(), "F35B") == 0) //Senkrechtstarter
		{
			if (velocity < 313 && velocity > 200)
			{
				g_pInputBuffers[fb::ConceptMoveFB] = 1.0f;
				g_pInputBuffers[fb::ConceptMoveForward] = 1.0f;
				if (!GetAsyncKeyState('S'))
					g_pInputBuffers[fb::ConceptSprint] = 1.0f;

			}
			else if (velocity > 313 && velocity > 200)
			{
				g_pInputBuffers[fb::ConceptMoveFB] = 1.0f;
				g_pInputBuffers[fb::ConceptMoveBackward] = 1.0f;
				g_pInputBuffers[fb::ConceptCrawl] = 1.0f;
				g_pInputBuffers[fb::ConceptBrake] = 1.0f;
			}
		}
		else if (strcmp(pPhysEntityData->GetObjectName(), "A-10") == 0 //US Rush
			|| strcmp(pPhysEntityData->GetObjectName(), "SU-25TM") == 0) //RU Rush
		{
			if (velocity < 320 && velocity > 200)
			{
				g_pInputBuffers[fb::ConceptMoveFB] = 1.0f;
				g_pInputBuffers[fb::ConceptMoveForward] = 1.0f;

			}
			else if (velocity > 320 && velocity > 200)
			{
				g_pInputBuffers[fb::ConceptMoveFB] = 1.0f;
				g_pInputBuffers[fb::ConceptMoveBackward] = 1.0f;
				g_pInputBuffers[fb::ConceptCrawl] = 1.0f;
				g_pInputBuffers[fb::ConceptBrake] = 1.0f;
			}
		}
	}
}

void _stdcall AutoStandUp()
{
	if (bAutoStandUp)
	{
		fb::ClientGameContext* g_pGameContext = fb::ClientGameContext::Singleton();
		if (!POINTERCHK(g_pGameContext)) return;

		fb::ClientPlayerManager* pPlayerManager = g_pGameContext->m_clientPlayerManager;
		if (!POINTERCHK(pPlayerManager) || pPlayerManager->m_players.empty()) return;

		fb::ClientPlayer* pLocalPlayer = pPlayerManager->m_localPlayer;
		if (!POINTERCHK(pLocalPlayer)) return;

		fb::ClientSoldierEntity* pMySoldier = pLocalPlayer->getSoldierEnt();
		if (!POINTERCHK(pMySoldier)) return;

		//if (!isalive(pMySoldier->Alive())) return;

		if (pMySoldier->isInVehicle()) return;

		int	interactive = 34272256;
		if (pMySoldier->isDying() == interactive)
		{
			g_pInputBuffers[fb::ConceptJump] = 1.0f;
			g_pInputBuffers[fb::ConceptSelectInventoryItem1] = 1.0f;
		}
	}
}

void _stdcall SoldierWeaponUpgrade()
{
	fb::ClientGameContext* g_pGameContext = fb::ClientGameContext::Singleton();
	if (!POINTERCHK(g_pGameContext)) return;

	fb::ClientPlayerManager* pPlayerManager = g_pGameContext->m_clientPlayerManager;
	if (!POINTERCHK(pPlayerManager) || pPlayerManager->m_players.empty()) return;

	fb::ClientPlayer* pLocalPlayer = pPlayerManager->m_localPlayer;
	if (!POINTERCHK(pLocalPlayer)) return;

	fb::ClientSoldierEntity* pMySoldier = pLocalPlayer->getSoldierEnt();
	if (!POINTERCHK(pMySoldier)) return;

	if (pMySoldier->isInVehicle())
	{
		char* name = GetVehicleName(pLocalPlayer);
		if (GetVehicleValues(name) == 0) return;
	}

	int iWeaponID = GetWeaponID(pMySoldier);
	if (iWeaponID == -1) return;

	fb::ClientSoldierWeapon* MyCSW = pMySoldier->GetCSW();
	//valid checks on Weapons
	if (!POINTERCHK(MyCSW)
		|| !POINTERCHK(MyCSW->m_weapon)
		|| !POINTERCHK(MyCSW->m_predictedFiring)
		|| !POINTERCHK(MyCSW->m_predictedFiring->m_data->m_primaryFire)) return;

	//disable breath sway this needs to be executed always
	fb::ClientSoldierEntity::BreathControlHandler* pBreath = pMySoldier->m_breathControlHandler;
	if (bNoBreath && POINTERCHK(pBreath))
	{
		pBreath->m_breathControlMultiplier = 0;
		pBreath->m_breathControlTimer = 0;
		pBreath->m_breathControlPenaltyMultiplier = 0;
		pBreath->m_breathControlPenaltyTimer = 0;
	}

	//disable sway multiplier on weapons with acogs ... this needs to be executed always
	fb::ClientSoldierWeaponsComponent::ClientWeaponSwayCallbackImpl* pCWSCI = pMySoldier->m_soldierWeaponsComponent->m_weaponSwayCallback;
	if (bNoSway && POINTERCHK(pCWSCI))
	{
		fb::SoldierAimingSimulationData* pSASD = MyCSW->m_authorativeAiming->m_data;
		if (POINTERCHK(pSASD->m_zoomLevels[0]))
		{
			pSASD->m_zoomLevels.At(0)->m_swayPitchMultiplier = 0.0f;
			pSASD->m_zoomLevels.At(0)->m_swayYawMultiplier = 0.0f;
			pSASD->m_zoomLevels.At(0)->m_dispersionMultiplier = 0.0f;
			pSASD->m_zoomLevels.At(0)->m_recoilMultiplier = 0.0f;
			pSASD->m_zoomLevels.At(0)->m_recoilFovMultiplier = 0.0f;

			pSASD->m_zoomLevels.At(0)->m_cameraImpulseMultiplier = 0.0f;


			if (pCWSCI->m_isSupported)
			{
				pSASD->m_zoomLevels.At(0)->m_supportedSwayPitchMultiplier = 0.0f;
				pSASD->m_zoomLevels.At(0)->m_supportedSwayYawMultiplier = 0.0f;
			}
		}
		if (MyCSW->m_authorativeAiming->m_zoomLevel > 0)
		{
			if (POINTERCHK(pSASD->m_zoomLevels[1]))
			{
				pSASD->m_zoomLevels.At(1)->m_swayPitchMultiplier = 0.0f;
				pSASD->m_zoomLevels.At(1)->m_swayYawMultiplier = 0.0f;
				pSASD->m_zoomLevels.At(1)->m_dispersionMultiplier = 0.0f;
				pSASD->m_zoomLevels.At(1)->m_recoilMultiplier = 0.0f;
				pSASD->m_zoomLevels.At(1)->m_recoilFovMultiplier = 0.0f;

				pSASD->m_zoomLevels.At(1)->m_cameraImpulseMultiplier = 0.0f;

				if (pCWSCI->m_isSupported)
				{
					pSASD->m_zoomLevels.At(1)->m_supportedSwayPitchMultiplier = 0.0f;
					pSASD->m_zoomLevels.At(1)->m_supportedSwayYawMultiplier = 0.0f;
				}
			}
		}
	}

	// disable recoil and spread ... this needs to be executed always
	fb::WeaponSway* pWps = pMySoldier->getWeaponSway();
	if (POINTERCHK(pWps)) HookRecoil(pWps);

	fb::WeaponFiring* pWeaponFiring = pMySoldier->getCurrentWeaponFiring();
	if (POINTERCHK(pWeaponFiring))
	{
		pWeaponFiring->m_overheatDropMultiplier = 500;
		pWeaponFiring->m_primaryFire.isOverheated = false;
		pWeaponFiring->m_autoReplenishTime = 0.00001f;
		pWeaponFiring->m_primaryFire.heat = 0.0f;
		pWeaponFiring->m_recoilAngleX = 0.0f;
		pWeaponFiring->m_recoilAngleY = 0.0f;
		pWeaponFiring->m_recoilAngleZ = 0.0f;
	}

	fb::FiringFunctionData* pFFD = pMySoldier->getCurrentWeaponFiringData()->m_primaryFire;
	if (!POINTERCHK(pFFD)) return;

	//weaponmodifier only active if its your mainweapon
	fb::BulletEntityData* pBED;
	if (POINTERCHK(MyCSW)
		&& POINTERCHK(MyCSW->m_weaponModifier.m_weaponProjectileModifier)
		&& POINTERCHK(MyCSW->m_weaponModifier.m_weaponProjectileModifier->m_projectileData))
	{
		pBED = reinterpret_cast<fb::BulletEntityData*>(MyCSW->m_weaponModifier.m_weaponProjectileModifier->m_projectileData);
		if (!POINTERCHK(pBED)) pBED = pFFD->m_shot.m_projectileData;
	}
	else
		pBED = pFFD->m_shot.m_projectileData;
	if (!POINTERCHK(pBED)) return;

	float flBulletspeed = pFFD->m_shot.m_initialSpeed.z;
	float flBulletdamage = pBED->m_endDamage;

	if (flBulletdamage > 2.00 && flBulletspeed > 40.0f)
	{
		if (bInstantBullet && !pBED->m_instantHit)
		{
			pFFD->m_shot.m_initialSpeed.z = 99999.0f;
			pBED->m_instantHit = true;
			pBED->m_timeToLive = 10.0f;
			pBED->m_gravity = 0.0f;
		}
	}
}
void _stdcall VehicleWeaponUpgrade()
{
	fb::ClientGameContext* g_pGameContext = fb::ClientGameContext::Singleton();
	if (!POINTERCHK(g_pGameContext)) return;

	fb::ClientPlayerManager* pPlayerManager = g_pGameContext->m_clientPlayerManager;
	if (!POINTERCHK(pPlayerManager) || pPlayerManager->m_players.empty()) return;

	fb::ClientPlayer* pLocalPlayer = pPlayerManager->m_localPlayer;
	if (!POINTERCHK(pLocalPlayer)) return;

	fb::ClientSoldierEntity* pMySoldier = pLocalPlayer->getSoldierEnt();
	if (!POINTERCHK(pMySoldier)) return;

	if (!pMySoldier->isInVehicle()) return;

	char* name = GetVehicleName(pLocalPlayer);
	if (GetVehicleValues(name) == 0) return;

	int seat = 0;
	if (pLocalPlayer->m_attachedEntryId) seat = pLocalPlayer->m_attachedEntryId;

	bool bSeatHasWeapon = GetVehicleValues(name)->m_SeatHasWeapon[seat];
	bool bOpenSeat = GetVehicleValues(name)->m_OpenSeat[seat];

	if (bSeatHasWeapon)
	{
		fb::WeaponFiring* pWeaponFiring = GetVehicleWeapon(pLocalPlayer);
		if (POINTERCHK(pWeaponFiring))
		{
			if (bNoRecoil)
			{
				pWeaponFiring->m_recoilAngleX = 0.0f;
				pWeaponFiring->m_recoilAngleY = 0.0f;
				pWeaponFiring->m_recoilAngleZ = 0.0f;

			}

			if (bInstantBullet)
			{
				pWeaponFiring->m_data->m_primaryFire->m_shot.m_initialSpeed.z = 99999.0f;
				pWeaponFiring->m_data->m_primaryFire->m_shot.m_projectileData->m_instantHit = true;
				pWeaponFiring->m_data->m_primaryFire->m_shot.m_projectileData->m_timeToLive = 10.0f;
				pWeaponFiring->m_data->m_primaryFire->m_shot.m_projectileData->m_gravity = 0.0f;
			}
		}
	}
	else if (bOpenSeat)
	{
		if (bMagicBullets)
		{
			fb::ClientGameContext* g_pGameContext = fb::ClientGameContext::Singleton();
			if (!POINTERCHK(g_pGameContext)) return;

			fb::ClientPlayerManager* pPlayerManager = g_pGameContext->m_clientPlayerManager;
			if (!POINTERCHK(pPlayerManager) || pPlayerManager->m_players.empty()) return;

			fb::ClientPlayer* pLocalPlayer = pPlayerManager->m_localPlayer;
			if (!POINTERCHK(pLocalPlayer)) return;

			fb::ClientSoldierEntity* pMySoldier = pLocalPlayer->getSoldierEnt();
			if (!POINTERCHK(pMySoldier)) return;

			if (pMySoldier->isInVehicle()) return;

			if (!pMySoldier->IsAlive()) return;

			if (GetWeaponID(pMySoldier) != 0 && GetWeaponID(pMySoldier) != 1) return;

			eastl::vector<fb::ClientPlayer*> pVecCP = pPlayerManager->m_players;
			if (pVecCP.empty()) return;

			int size = pVecCP.size();
			for (int i = 0; i < size; i++)
			{
				fb::ClientPlayer* pClientPlayer = pVecCP.at(i);
				if (!POINTERCHK(pClientPlayer)) continue;

				if (pLocalPlayer->m_teamId == pClientPlayer->m_teamId) continue;

				fb::ClientSoldierEntity* pEnemySoldier = pClientPlayer->getSoldierEnt();
				if (!POINTERCHK(pEnemySoldier)) continue;

				if (!isalive(pEnemySoldier->Alive())) continue;

				int iWeaponID = GetWeaponID(pMySoldier);
				if (iWeaponID == -1) return;

				fb::ClientSoldierWeapon* MyCSW = pMySoldier->GetCSW();
				//valid checks on Weapons
				if (!POINTERCHK(MyCSW)
					|| !POINTERCHK(MyCSW->m_weapon)
					|| !POINTERCHK(MyCSW->m_predictedFiring)
					|| !POINTERCHK(MyCSW->m_predictedFiring->m_data->m_primaryFire)) return;

				fb::FiringFunctionData* pFFD = pMySoldier->getCurrentWeaponFiringData()->m_primaryFire;
				if (!POINTERCHK(pFFD)) return;

				//weaponmodifier only active if its your mainweapon
				fb::BulletEntityData* pBED;
				if (POINTERCHK(MyCSW)
					&& POINTERCHK(MyCSW->m_weaponModifier.m_weaponProjectileModifier)
					&& POINTERCHK(MyCSW->m_weaponModifier.m_weaponProjectileModifier->m_projectileData))
				{
					pBED = reinterpret_cast<fb::BulletEntityData*>(MyCSW->m_weaponModifier.m_weaponProjectileModifier->m_projectileData);
					if (!POINTERCHK(pBED)) pBED = pFFD->m_shot.m_projectileData;
				}
				else
					pBED = pFFD->m_shot.m_projectileData;
				if (!POINTERCHK(pBED)) return;

				float flBulletspeed = pFFD->m_shot.m_initialSpeed.z;
				float flBulletdamage = pBED->m_endDamage;

				if (flBulletdamage > 2.00 && flBulletspeed > 40.0f)
				{
					fb::ClientWeapon* clWeapon = MyCSW->m_weapon;
					if (POINTERCHK(clWeapon))
					{
						__asm
						{
							push ecx
								mov ecx, clWeapon
								push pEnemySoldier
								call GIVEDAMAGE
								pop ecx
						}
					}
				}
			}
		}
	}
}

void _stdcall MagicBullets()
{
	if (bMagicBullets)
	{
		fb::ClientGameContext* g_pGameContext = fb::ClientGameContext::Singleton();
		if (!POINTERCHK(g_pGameContext)) return;

		fb::ClientPlayerManager* pPlayerManager = g_pGameContext->m_clientPlayerManager;
		if (!POINTERCHK(pPlayerManager) || pPlayerManager->m_players.empty()) return;

		fb::ClientPlayer* pLocalPlayer = pPlayerManager->m_localPlayer;
		if (!POINTERCHK(pLocalPlayer)) return;

		fb::ClientSoldierEntity* pMySoldier = pLocalPlayer->getSoldierEnt();
		if (!POINTERCHK(pMySoldier)) return;

		if (pMySoldier->isInVehicle()) return;

		if (!pMySoldier->IsAlive()) return;

		if (GetWeaponID(pMySoldier) != 0 && GetWeaponID(pMySoldier) != 1) return;

		eastl::vector<fb::ClientPlayer*> pVecCP = pPlayerManager->m_players;
		if (pVecCP.empty()) return;

		int size = pVecCP.size();
		for (int i = 0; i < size; i++)
		{
			fb::ClientPlayer* pClientPlayer = pVecCP.at(i);
			if (!POINTERCHK(pClientPlayer)) continue;

			if (pLocalPlayer->m_teamId == pClientPlayer->m_teamId) continue;

			fb::ClientSoldierEntity* pEnemySoldier = pClientPlayer->getSoldierEnt();
			if (!POINTERCHK(pEnemySoldier)) continue;

			if (!isalive(pEnemySoldier->Alive())) continue;

			int iWeaponID = GetWeaponID(pMySoldier);
			if (iWeaponID == -1) return;

			fb::ClientSoldierWeapon* MyCSW = pMySoldier->GetCSW();
			//valid checks on Weapons
			if (!POINTERCHK(MyCSW)
				|| !POINTERCHK(MyCSW->m_weapon)
				|| !POINTERCHK(MyCSW->m_predictedFiring)
				|| !POINTERCHK(MyCSW->m_predictedFiring->m_data->m_primaryFire)) return;

			fb::FiringFunctionData* pFFD = pMySoldier->getCurrentWeaponFiringData()->m_primaryFire;
			if (!POINTERCHK(pFFD)) return;

			//weaponmodifier only active if its your mainweapon
			fb::BulletEntityData* pBED;
			if (POINTERCHK(MyCSW)
				&& POINTERCHK(MyCSW->m_weaponModifier.m_weaponProjectileModifier)
				&& POINTERCHK(MyCSW->m_weaponModifier.m_weaponProjectileModifier->m_projectileData))
			{
				pBED = reinterpret_cast<fb::BulletEntityData*>(MyCSW->m_weaponModifier.m_weaponProjectileModifier->m_projectileData);
				if (!POINTERCHK(pBED)) pBED = pFFD->m_shot.m_projectileData;
			}
			else
				pBED = pFFD->m_shot.m_projectileData;
			if (!POINTERCHK(pBED)) return;

			float flBulletspeed = pFFD->m_shot.m_initialSpeed.z;
			float flBulletdamage = pBED->m_endDamage;

			if (flBulletdamage > 2.00 && flBulletspeed > 40.0f)
			{
				fb::ClientWeapon* clWeapon = MyCSW->m_weapon;
				if (POINTERCHK(clWeapon))
				{
					__asm
					{
						push ecx
							mov ecx, clWeapon
							push pEnemySoldier
							call GIVEDAMAGE
							pop ecx
					}
				}
			}
		}
	}
}

void _stdcall ESP2D()
{
	fb::ClientGameContext* g_pGameContext = fb::ClientGameContext::Singleton();
	if (!POINTERCHK(g_pGameContext)) return;

	fb::ClientPlayerManager* pPlayerManager = g_pGameContext->m_clientPlayerManager;
	if (!POINTERCHK(pPlayerManager) || pPlayerManager->m_players.empty()) return;

	fb::ClientPlayer* pLocalPlayer = pPlayerManager->m_localPlayer;
	if (!POINTERCHK(pLocalPlayer)) return;

	fb::ClientSoldierEntity* pMySoldier = pLocalPlayer->getSoldierEnt();
	if (!POINTERCHK(pMySoldier)) return;

	if (!isalive(pMySoldier->Alive())) return;

	eastl::vector<fb::ClientPlayer*> pVecCP = pPlayerManager->m_players;
	if (pVecCP.empty()) return;

	int size = pVecCP.size();
	for (int i = 0; i < size; i++)
	{
		fb::ClientPlayer* pClientPlayer = pVecCP.at(i);
		if (!POINTERCHK(pClientPlayer)) continue;

		if (pLocalPlayer->m_teamId == pClientPlayer->m_teamId) continue;

		fb::ClientSoldierEntity* pEnemySoldier = pClientPlayer->getSoldierEnt();
		if (!POINTERCHK(pEnemySoldier)) continue;

		//if (!isalive(pEnemySoldier->isAlive())) continue;

		fb::GameRenderer::Singleton()->m_viewParams.view.Update();
		fb::Vec3 vecMySoldierPosition = fb::GameRenderer::Singleton()->m_viewParams.view.m_viewMatrixInverse.trans;

		fb::ClientSoldierReplication* enemyRep = pEnemySoldier->m_replicatedController;
		if (!POINTERCHK(enemyRep)) continue;

		fb::ClientSoldierReplication* myRep = pMySoldier->m_replicatedController;
		if (!POINTERCHK(myRep)) continue;

		fb::FiringFunctionData* pFFD = pMySoldier->getCurrentWeaponFiringData()->m_primaryFire;
		if (!POINTERCHK(pFFD)) continue;

		fb::WeakPtr<fb::ClientSoldierEntity>* corpse = &pClientPlayer->m_corpse;
		if (corpse->GetData()) continue;

		fb::Vec3 vDir = pEnemySoldier->m_replicatedController->m_state.position - vecMySoldierPosition;
		vDir.normalize();

		fb::Vec3 vecaim;
		ProjectToScreen(&pEnemySoldier->m_replicatedController->m_state.position, &vecaim);
		if (vecaim.x <= 2 && vecaim.y <= 2) continue;

		if (pEnemySoldier->isInVehicle())
		{
			fb::Color32 blue = fb::Color32::Blue();

			fb::ClientControllableEntity* pControllable = pClientPlayer->m_attachedControllable;
			if (!POINTERCHK(pControllable)) continue;

			fb::ClientVehicleEntity* pVehicle = reinterpret_cast<fb::ClientVehicleEntity*>(pControllable);
			if (!POINTERCHK(pVehicle)) continue;

			char str[100];
			float dist = GetDistance(pLocalPlayer, pClientPlayer);
			char* name = GetVehicleName(pClientPlayer);

			if (bNames && bDistance)
				sprintf(str, "%s\nDist: [%.fm]", name, dist);

			else if (bNames)
				sprintf(str, "%s", name);

			fb::Vec3 screenPosl, screenPosr;
			fb::Vec3 vPos = pEnemySoldier->m_replicatedController->m_state.position;

			fb::Vec3 vLocalPos = pMySoldier->m_replicatedController->m_state.position;

			float anglex = XAngle(vLocalPos.x, vLocalPos.z, vPos.x, vPos.z, 0);
			float posl[4], posr[4];

			RotatePointAlpha(posl, -0.5, 0, 1.7, 0, 0, 0, -anglex + 90);
			RotatePointAlpha(posr, 0.5, 0, 0, 0, 0, 0, -anglex + 90);
			fb::Vec3 vposl, vposr;

			vposl.x = vPos.x + posl[0];
			vposl.y = vPos.y + posl[2];
			vposl.z = vPos.z + posl[1];
			vposr.x = vPos.x + posr[0];
			vposr.y = vPos.y + posr[2];
			vposr.z = vPos.z + posr[1];

			if (!ProjectToScreen(&vposl, &screenPosl)) continue;
			if (!ProjectToScreen(&vposr, &screenPosr)) continue;

			float w = abs(screenPosr.x - screenPosl.x);
			float h = abs(screenPosl.y - screenPosr.y);
			float x = screenPosr.x;
			float y = screenPosl.y;

			if (bSnaplines)
				DrawSnapLine(vecaim, blue);

			if (bNames || bDistance)
				fb::DebugRenderer2::Singleton()->drawText(x + w + 3, y, blue, str);

			if (bBoxESP)
			{
				fb::LinearTransform trans;
				pVehicle->m_physicsEntity->getTransform(trans);
				fb::AxisAlignedBox box;
				pVehicle->computeBoundingBox(box);
				CalcBox(&box, &trans, blue);
			}
			else
			{
				fb::Color32 color = NULL;

				bool bIsVisible = (bool)!pEnemySoldier->m_isOccluded;
				bIsVisible ? color = fb::Color32::Red() : color = fb::Color32::Yellow();

				char str[100];

				float health = pEnemySoldier->m_health;
				float max = pEnemySoldier->maxHealth();
				float dist = GetDistance(pLocalPlayer, pClientPlayer);
				char* name = pClientPlayer->am_name;

				if (bNames && bDistance)
					sprintf(str, "%s\nDist: [%.fm]", name, dist);
				else if (bNames)
					sprintf(str, "%s", name);
				else if (bDistance)
					sprintf(str, "Dist: [%.fm]", dist);

				fb::Vec3 screenPosl, screenPosr;
				fb::Vec3 vPos = pEnemySoldier->m_replicatedController->m_state.position;

				fb::Vec3 vLocalPos = pMySoldier->m_replicatedController->m_state.position;

				float anglex = XAngle(vLocalPos.x, vLocalPos.z, vPos.x, vPos.z, 0);
				float posl[4], posr[4];

				RotatePointAlpha(posl, -0.5, 0, 1.7, 0, 0, 0, -anglex + 90);
				RotatePointAlpha(posr, 0.5, 0, 0, 0, 0, 0, -anglex + 90);
				fb::Vec3 vposl, vposr;

				vposl.x = vPos.x + posl[0];
				vposl.y = vPos.y + posl[2];
				vposl.z = vPos.z + posl[1];
				vposr.x = vPos.x + posr[0];
				vposr.y = vPos.y + posr[2];
				vposr.z = vPos.z + posr[1];

				if (!ProjectToScreen(&vposl, &screenPosl)) continue;
				if (!ProjectToScreen(&vposr, &screenPosr)) continue;

				float w = abs(screenPosr.x - screenPosl.x);
				float h = abs(screenPosl.y - screenPosr.y);
				float x = screenPosr.x;
				float y = screenPosl.y;

				if (bBoxESP)
					fb::DebugRenderer2::Singleton()->DrawBox2D(x, y, w, h, color);
				if (bHealthbar)
				{
					if (max)
					{
						fb::DebugRenderer2::Singleton()->DrawHealthBar(x, y, w, health, max);
					}
				}
				if (bNames || bDistance)
					fb::DebugRenderer2::Singleton()->drawText(x + w + 3, y, color, str);

				if (bSnaplines)
					DrawSnapLine(vecaim, color);

				//Bone ESP
				if (bBones)
				{
					ConnectBones(pEnemySoldier, fb::Head, fb::Neck, color);
					ConnectBones(pEnemySoldier, fb::Neck, fb::Spine2, color);
					ConnectBones(pEnemySoldier, fb::Spine2, fb::Spine1, color);
					ConnectBones(pEnemySoldier, fb::Spine1, fb::Spine, color);
					ConnectBones(pEnemySoldier, fb::Neck, fb::LeftShoulder, color);
					ConnectBones(pEnemySoldier, fb::Neck, fb::RightShoulder, color);
					ConnectBones(pEnemySoldier, fb::LeftShoulder, fb::LeftElbowRoll, color);
					ConnectBones(pEnemySoldier, fb::RightShoulder, fb::RightElbowRoll, color);
					ConnectBones(pEnemySoldier, fb::LeftElbowRoll, fb::LeftHand, color);
					ConnectBones(pEnemySoldier, fb::RightElbowRoll, fb::RightHand, color);
					ConnectBones(pEnemySoldier, fb::Spine, fb::RightKneeRoll, color);
					ConnectBones(pEnemySoldier, fb::Spine, fb::LeftKneeRoll, color);
					ConnectBones(pEnemySoldier, fb::RightKneeRoll, fb::RightFoot, color);
					ConnectBones(pEnemySoldier, fb::LeftKneeRoll, fb::LeftFoot, color);
				}
			}
		}
		else
		{
			fb::Color32 color = NULL;

			bool bIsVisible = (bool)!pEnemySoldier->m_isOccluded;
			bIsVisible ? color = fb::Color32::Red() : color = fb::Color32::Yellow();

			char str[100];

			float health = pEnemySoldier->m_health;
			float max = pEnemySoldier->maxHealth();
			float dist = GetDistance(pLocalPlayer, pClientPlayer);
			char* name = pClientPlayer->am_name;

			if (bNames && bDistance)
				sprintf(str, "%s\nDist: [%.fm]", name, dist);
			else if (bNames)
				sprintf(str, "%s", name);
			else if (bDistance)
				sprintf(str, "Dist: [%.fm]", dist);

			fb::Vec3 screenPosl, screenPosr;
			fb::Vec3 vPos = pEnemySoldier->m_replicatedController->m_state.position;

			fb::Vec3 vLocalPos = pMySoldier->m_replicatedController->m_state.position;

			float anglex = XAngle(vLocalPos.x, vLocalPos.z, vPos.x, vPos.z, 0);
			float posl[4], posr[4];

			RotatePointAlpha(posl, -0.5, 0, 1.7, 0, 0, 0, -anglex + 90);
			RotatePointAlpha(posr, 0.5, 0, 0, 0, 0, 0, -anglex + 90);
			fb::Vec3 vposl, vposr;

			vposl.x = vPos.x + posl[0];
			vposl.y = vPos.y + posl[2];
			vposl.z = vPos.z + posl[1];
			vposr.x = vPos.x + posr[0];
			vposr.y = vPos.y + posr[2];
			vposr.z = vPos.z + posr[1];

			if (!ProjectToScreen(&vposl, &screenPosl)) continue;
			if (!ProjectToScreen(&vposr, &screenPosr)) continue;

			float w = abs(screenPosr.x - screenPosl.x);
			float h = abs(screenPosl.y - screenPosr.y);
			float x = screenPosr.x;
			float y = screenPosl.y;

			if (bBoxESP)
				fb::DebugRenderer2::Singleton()->DrawBox2D(x, y, w, h, color);
			if (bHealthbar)
			{
				if (max)
				{
					fb::DebugRenderer2::Singleton()->DrawHealthBar(x, y, w, health, max);
				}
			}
			if (bNames || bDistance)
				fb::DebugRenderer2::Singleton()->drawText(x + w + 3, y, color, str);

			if (bSnaplines)
				DrawSnapLine(vecaim, color);

			//Bone ESP
			if (bBones)
			{
				ConnectBones(pEnemySoldier, fb::Head, fb::Neck, color);
				ConnectBones(pEnemySoldier, fb::Neck, fb::Spine2, color);
				ConnectBones(pEnemySoldier, fb::Spine2, fb::Spine1, color);
				ConnectBones(pEnemySoldier, fb::Spine1, fb::Spine, color);
				ConnectBones(pEnemySoldier, fb::Neck, fb::LeftShoulder, color);
				ConnectBones(pEnemySoldier, fb::Neck, fb::RightShoulder, color);
				ConnectBones(pEnemySoldier, fb::LeftShoulder, fb::LeftElbowRoll, color);
				ConnectBones(pEnemySoldier, fb::RightShoulder, fb::RightElbowRoll, color);
				ConnectBones(pEnemySoldier, fb::LeftElbowRoll, fb::LeftHand, color);
				ConnectBones(pEnemySoldier, fb::RightElbowRoll, fb::RightHand, color);
				ConnectBones(pEnemySoldier, fb::Spine, fb::RightKneeRoll, color);
				ConnectBones(pEnemySoldier, fb::Spine, fb::LeftKneeRoll, color);
				ConnectBones(pEnemySoldier, fb::RightKneeRoll, fb::RightFoot, color);
				ConnectBones(pEnemySoldier, fb::LeftKneeRoll, fb::LeftFoot, color);
			}
		}
	}
}

void _stdcall PlayerIteration()
{
	if (bMinimapHack || bForceSquadSpawn)
	{
		fb::ClientGameContext* g_pGameContext = fb::ClientGameContext::Singleton();
		if (!POINTERCHK(g_pGameContext)) return;

		fb::ClientPlayerManager* pPlayerManager = g_pGameContext->m_clientPlayerManager;
		if (!POINTERCHK(pPlayerManager) || pPlayerManager->m_players.empty()) return;

		eastl::vector<fb::ClientPlayer*> pVecCP = pPlayerManager->m_players;
		if (pVecCP.empty()) return;

		int size = pVecCP.size();
		for (int i = 0; i < size; i++)
		{
			fb::ClientPlayer* pClientPlayer = pVecCP.at(i);
			fb::ClientSoldierEntity* pSoldier = pClientPlayer->getSoldierEnt();
			if (!POINTERCHK(pSoldier)) continue;

			if (pSoldier->isInVehicle()) continue;

			if (bForceSquadSpawn)
				pClientPlayer->m_isAllowedToSpawnOn = true;

			if (bMinimapHack)
			{
				fb::ClientSpottingTargetComponent* pCSTC = pSoldier->getComponent<fb::ClientSpottingTargetComponent>("ClientSpottingTargetComponent");
				if (POINTERCHK(pCSTC))
					pCSTC->m_spotType = fb::SpotType_Active;
			}
		}
	}
}
void _stdcall EntityWorld()
{
	if (bMinimapHack || bSpottedExplosive)
	{
		fb::ClientGameContext* g_pGameContext = fb::ClientGameContext::Singleton();
		if (!POINTERCHK(g_pGameContext)) return;

		fb::ClientLevel* g_pLevel = g_pGameContext->m_level;
		if (!POINTERCHK(g_pLevel)) return;

		fb::GameWorld* g_pGameWorld = g_pLevel->m_gameWorld;
		if (!POINTERCHK(g_pGameWorld)) return;

		if (bMinimapHack)
		{
			fb::EntityWorld::EntityCollection vehicle = g_pGameWorld->m_collections.at(ENTITY_CLIENT_VEHICLE);
			if (vehicle.firstSegment)
			{
				for (int i = 0; i < (int)vehicle.firstSegment->m_Collection.size(); i++)
				{
					if (vehicle.firstSegment->m_Collection.size() > 0)
					{
						fb::ClientVehicleEntity* pEntity = reinterpret_cast<fb::ClientVehicleEntity*>(vehicle.firstSegment->m_Collection.at(i));
						if (POINTERCHK(pEntity))
						{
							fb::ClientSpottingTargetComponent* vehicleSpotting = pEntity->getComponent<fb::ClientSpottingTargetComponent>("ClientSpottingTargetComponent");
							if (POINTERCHK(vehicleSpotting))
								vehicleSpotting->m_spotType = fb::SpotType_Active;
						}
					}
				}
			}
		}

		if (bSpottedExplosive)
		{
			fb::EntityWorld::EntityCollection explosive = g_pGameWorld->m_collections.at(ENTITY_CLIENT_EXPLOSIVE);
			if (explosive.firstSegment)
			{
				for (int i = 0; i < (int)explosive.firstSegment->m_Collection.size(); i++)
				{
					if (explosive.firstSegment->m_Collection.size() > 0)
					{
						fb::ClientExplosionPackEntity* pEntity = reinterpret_cast<fb::ClientExplosionPackEntity*>(explosive.firstSegment->m_Collection.at(i));
						if (POINTERCHK(pEntity))
						{
							pEntity->m_isSpotted = 2; // 1 is spotted on map, 2 is spotted map and HUD (3D)
						}
					}
				}
			}
		}

		fb::ClientPlayerManager* pPlayerManager = g_pGameContext->m_clientPlayerManager;
		if (!POINTERCHK(pPlayerManager) || pPlayerManager->m_players.empty()) return;

		fb::ClientPlayer* pLocalPlayer = pPlayerManager->m_localPlayer;
		if (!POINTERCHK(pLocalPlayer)) return;

		fb::EntityWorld::EntityCollection supplybox = g_pGameWorld->m_collections.at(ENTITY_CLIENT_SUPPLYBOX);
		if (supplybox.firstSegment)
		{
			for (int i = 0; i < (int)supplybox.firstSegment->m_Collection.size(); i++)
			{
				if (supplybox.firstSegment->m_Collection.size() > 0)
				{
					fb::ClientSupplySphereEntity* pEntity = reinterpret_cast<fb::ClientSupplySphereEntity*>(supplybox.firstSegment->m_Collection.at(i));
					if (POINTERCHK(pEntity))
					{
						pEntity->m_teamId = pLocalPlayer->m_teamId;
					}
				}
			}
		}
	}
}

void _stdcall FootAimbot()
{
	fb::ClientGameContext* g_pGameContext = fb::ClientGameContext::Singleton();
	if (!POINTERCHK(g_pGameContext))
		return;

	fb::ClientPlayerManager* pPlayerManager = g_pGameContext->m_clientPlayerManager;
	if (!POINTERCHK(pPlayerManager) || pPlayerManager->m_players.empty())
		return;

	fb::ClientPlayer* pLocalPlayer = pPlayerManager->m_localPlayer;
	if (!POINTERCHK(pLocalPlayer))
		return;

	fb::ClientSoldierEntity* pMySoldier = pLocalPlayer->getSoldierEnt();
	if (!POINTERCHK(pMySoldier))
		return;

	if (!pMySoldier->IsAlive()) return;

	int iWeaponID = GetWeaponID(pMySoldier);
	if (iWeaponID != 0 && iWeaponID != 1) return;

	eastl::vector<fb::ClientPlayer*> pVecCP = pPlayerManager->m_players;

	if (pVecCP.empty())
		return;

	int size = pVecCP.size();

	fb::GameRenderer::Singleton()->m_viewParams.view.Update();//matrix not filled by default
	fb::Vec3 Origin = fb::GameRenderer::Singleton()->m_viewParams.view.m_viewMatrixInverse.trans;

	float closestdistanceworld = 9999.0f;
	float closestdistance = 9999.0f;
	fb::ClientPlayer* ClosestClient = NULL;
	fb::ClientSoldierEntity* ClosestSold = NULL;
	fb::Vec3 EnemyAimVec;
	int index = 0;

	for (int i = 0; i < size; i++)
	{
		fb::ClientPlayer* pClientPlayer = pVecCP.at(i);
		if (pMySoldier->m_teamId == pClientPlayer->m_teamId)
			continue;

		fb::ClientSoldierEntity* pEnemySoldier = pClientPlayer->getSoldierEnt();
		if (!POINTERCHK(pEnemySoldier))
			continue;

		if (!isalive(pEnemySoldier->isAlive()))
			continue;

		fb::WeakPtr<fb::ClientSoldierEntity>* corpse = &pClientPlayer->m_corpse;
		if (corpse->GetData()) continue;

		fb::Vec3 Enemyvec;
		if (bAimHead)
		{
			if (!GetBonePos(pEnemySoldier, fb::Head, &Enemyvec)) continue;

		}
		else
		{
			if (!GetBonePos(pEnemySoldier, fb::Hips, &Enemyvec)) continue;
		}

		if (bVisibilityChecks)
		{
			if (!IsVisible(&Enemyvec, pMySoldier)) continue;
		}

		float ScreenY = fb::DxRenderer::Singleton()->m_screenInfo.m_nHeight / 2;
		float ScreenX = fb::DxRenderer::Singleton()->m_screenInfo.m_nWidth / 2;
		fb::Vec3 EnemyScreen;
		ProjectToScreen(&Enemyvec, &EnemyScreen);

		float PosX = EnemyScreen.x > ScreenX ? EnemyScreen.x - ScreenX : ScreenX - EnemyScreen.x;
		float PosY = EnemyScreen.y > ScreenY ? EnemyScreen.y - ScreenY : ScreenY - EnemyScreen.y;

		float flScreenDistance = sqrt(PosX*PosX + PosY*PosY);

		if (flScreenDistance < closestdistance)
		{
			ClosestClient = pClientPlayer;
			ClosestSold = pEnemySoldier;
			closestdistance = flScreenDistance;
			EnemyAimVec = Enemyvec;
			index = i;
		}
	}
	if (!POINTERCHK(ClosestClient))
		return;

	if (!POINTERCHK(ClosestSold))
		return;

	fb::ClientSoldierWeapon* MyCSW = pMySoldier->GetCSW();
	//valid checks on Weapons
	if (!POINTERCHK(MyCSW)
		|| !POINTERCHK(MyCSW->m_weapon)
		|| !POINTERCHK(MyCSW->m_predictedFiring)
		|| !POINTERCHK(MyCSW->m_predictedFiring->m_data->m_primaryFire)) return;

	fb::FiringFunctionData* pFFD = pMySoldier->getCurrentWeaponFiringData()->m_primaryFire;
	if (!POINTERCHK(pFFD)) return;

	//weaponmodifier only active if its your mainweapon
	fb::BulletEntityData* pBED;
	if (POINTERCHK(MyCSW)
		&& POINTERCHK(MyCSW->m_weaponModifier.m_weaponProjectileModifier)
		&& POINTERCHK(MyCSW->m_weaponModifier.m_weaponProjectileModifier->m_projectileData))
	{
		pBED = reinterpret_cast<fb::BulletEntityData*>(MyCSW->m_weaponModifier.m_weaponProjectileModifier->m_projectileData);
		if (!POINTERCHK(pBED)) pBED = pFFD->m_shot.m_projectileData;
	}
	else
		pBED = pFFD->m_shot.m_projectileData;
	if (!POINTERCHK(pBED)) return;

	float flBulletspeed = pFFD->m_shot.m_initialSpeed.z;
	float flBulletGrav = fabs(pBED->m_gravity);

	float flDistance = Origin.DistanceToVector(EnemyAimVec);
	if (ClosestSold->isInVehicle())
	{
		fb::Vec3 myspeed = pMySoldier->linearVelocity();
		fb::Vec3 enemyspeed = getVehicleSpeed(ClosestSold);
		AimCorrection(myspeed, enemyspeed, &EnemyAimVec, flDistance, flBulletspeed, flBulletGrav);
	}
	else
	{
		fb::Vec3 myspeed = pMySoldier->linearVelocity();
		fb::Vec3 enemyspeed = ClosestSold->linearVelocity();
		AimCorrection(myspeed, enemyspeed, &EnemyAimVec, flDistance, flBulletspeed, flBulletGrav);
	}

	fb::Vec3 vDir = EnemyAimVec - Origin;
	vDir.normalize();

	float flYaw = -atan2(vDir.x, vDir.z);  //y
	float flPitch = atan2(vDir.y, vDir.VectorLength2()); //x

	const float MinYaw = 0; // 0 Degrees
	const float MaxYaw = M_PI * 2; // 360 Degrees

	if (flYaw < MinYaw)
		flYaw += MaxYaw;

	if (!pMySoldier->isInVehicle())
	{
		fb::ClientSoldierWeapon* pClientSoldierWeapon = pMySoldier->GetCSW();
		if (POINTERCHK(pClientSoldierWeapon))
		{
			fb::ClientSoldierAimingSimulation* aimer = pClientSoldierWeapon->m_authorativeAiming;
			if (!POINTERCHK(aimer))
				return;

			aimer->m_fpsAimer->m_yaw = flYaw;
			aimer->m_fpsAimer->m_pitch = flPitch;

		}
	}
}

int WINAPI hkPreFrame(float DeltaTime)
{
	_asm pushad
	int returnval = oPreFrameUpdate(DeltaTime);

	bool clicked = GetAsyncKeyState(0x02) & 0x8000;
	if (bAimbot && clicked)
		FootAimbot();

	for (int i = 0; i < 123; i++)
	{
		g_pBorderInputNode->m_inputCache->flInputBuffer[i] += g_pInputBuffers[i];
		g_pInputBuffers[i] = 0.0f;
	}

	_asm popad

	return returnval;
}

signed int __stdcall hkPresent(int a1, int a2, int a3)
{
	__asm pushad;

	MouseMenu();
	//ButtonMenu();

	AutoStandUp();

	SoldierWeaponUpgrade();
	VehicleWeaponUpgrade();

	ESP2D();

	AutoSpot();

	MagicBullets();

	PlayerIteration();
	EntityWorld();

	PerfectJet();

	__asm popad;

	return oPresent(a1, a2, a3);
}

BOOL WINAPI DllMain(HMODULE hModule, DWORD dwReason, LPVOID lpReserved)
{
	if (dwReason == DLL_PROCESS_ATTACH)
	{
		DisableThreadLibraryCalls(hModule);

		CreateThread(NULL, NULL, (LPTHREAD_START_ROUTINE)PBSSThread, NULL, NULL, NULL);

		CloseHandle(CreateThread(NULL, NULL, (LPTHREAD_START_ROUTINE)MouseThread, NULL, NULL, NULL));
		//CloseHandle(CreateThread(NULL, NULL, KeyboardThread, NULL, NULL, NULL));

	

		PresentHook.Init((DWORD**)fb::DxRenderer::Singleton()->pSwapChain);
		oPresent = reinterpret_cast<tPresent>(PresentHook.HookFunction<tPresent>(8, hkPresent));

		PreFrameHook.Init((DWORD**)g_pBorderInputNode);
		oPreFrameUpdate = reinterpret_cast<tPreFrameUpdate>(PreFrameHook.HookFunction<tPreFrameUpdate>(27, hkPreFrame));

		//CreateConsole();
	}

	else if (dwReason == DLL_PROCESS_DETACH)
	{
		if (oPresent)
			PresentHook.UnHookFunction(8);

		if (oPreFrameUpdate)
			PreFrameHook.UnHookFunction(27);
	}

	return true;
}
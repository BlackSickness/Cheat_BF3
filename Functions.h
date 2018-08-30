#include <io.h>
#include <fcntl.h>

#define M_PI 3.14159265359

void CreateConsole()
{
	int hConHandle = 0;
	HANDLE lStdHandle = 0;
	FILE *fp = 0;
	AllocConsole();
	lStdHandle = GetStdHandle(STD_OUTPUT_HANDLE);
	hConHandle = _open_osfhandle(PtrToUlong(lStdHandle), _O_TEXT);
	fp = _fdopen(hConHandle, "w");
	*stdout = *fp;
	setvbuf(stdout, NULL, _IONBF, 0);
}

template<typename T, std::size_t N>
std::size_t array_size(T(&)[N]) {
	return N;
}
bool isalive(int i) {
	if (i == 34271745)
		return true;
	else if (i == 34272001)
		return true;
	else if (i == 34272257)
		return true;
	return false;
}
int GetWeaponID(fb::ClientSoldierEntity* pMySoldier) {
	if (pMySoldier->m_soldierWeaponsComponent != NULL && pMySoldier->m_soldierWeaponsComponent->m_predictedWeaponSwitching != NULL)
		return pMySoldier->m_soldierWeaponsComponent->m_predictedWeaponSwitching->m_currentWeaponId;


	if (pMySoldier->m_soldierWeaponsComponent != NULL && pMySoldier->m_soldierWeaponsComponent->m_replicatedWeaponSwitching != NULL)
		return pMySoldier->m_soldierWeaponsComponent->m_replicatedWeaponSwitching->m_currentWeaponId;


	return NULL;
}

bool ProjectToScreen(fb::Vec3* world, fb::Vec3* out)//xCyniu
{
	fb::GameRenderer* pGameRenderer = fb::GameRenderer::Singleton();
	if (!world || !out || !pGameRenderer)
		return 0;
	fb::LinearTransform *view = &pGameRenderer->m_viewParams.view.m_viewMatrix;
	fb::LinearTransform *projection = &pGameRenderer->m_viewParams.view.m_projectionMatrix;
	return ((bool(__cdecl*)(fb::Vec3*, fb::LinearTransform*, fb::LinearTransform*, fb::Vec3*))0x764A90)(world, view, projection, out);
}

static bool GetBonePos(fb::ClientSoldierEntity* pEnt, int iBone, fb::Vec3 *vOut) { //chevvy
	if (!POINTERCHK(pEnt))
		return false;

	if (!iBone)
		return false;

	if (!POINTERCHK(vOut))
		return false;

	fb::ClientAntAnimatableComponent* pAnt = pEnt->m_animatableComponent[1];

	if (!POINTERCHK(pAnt))
		return false;

	pAnt->m_handler.m_hadVisualUpdate = true;

	fb::Animatable* pAnimatable = pAnt->m_handler.m_animatable;

	if (!POINTERCHK(pAnimatable))
		return false;

	if (pAnimatable->m_updatePoseResultData.m_validTransforms) {
		fb::QuatTransform* pQuat = pAnimatable->m_updatePoseResultData.m_activeWorldTransforms;

		if (!POINTERCHK(pQuat))
			return false;

		fb::Vec3 vTmp = pQuat[iBone].transAndScale;

		vOut->x = vTmp.x;
		vOut->y = vTmp.y;
		vOut->z = vTmp.z;

		return true;
	}

	return false;
}
static float GetDistance(fb::ClientPlayer* pLocal, fb::ClientPlayer* pPlayer) {
	if (!POINTERCHK(pLocal) || !POINTERCHK(pPlayer))
		return 0.0f;

	fb::ClientSoldierEntity* plEnt = pLocal->m_soldier.GetData();

	if (!POINTERCHK(plEnt))
		return 0.0f;

	fb::ClientSoldierEntity* pEnt = pPlayer->m_soldier.GetData();

	if (!POINTERCHK(pEnt))
		return 0.0f;

	return (plEnt->m_replicatedController->m_state.position.DistanceFrom(pEnt->m_replicatedController->m_state.position));
}
fb::WeaponFiring* GetVehicleWeapon(fb::ClientPlayer *Player) {
	if (!Player) return 0;

	fb::ClientVehicleEntity *pVeh = reinterpret_cast<fb::ClientVehicleEntity *>(Player->m_attachedControllable);
	if (!pVeh) return 0;

	fb::ClientEntryComponent *pEntry = pVeh->m_entries.at(Player->m_attachedEntryId);
	if (!pEntry) return 0;

	if (!pEntry->m_weapons.size()) return 0;

	const int activeStance = pEntry->getActiveStance();

	fb::EntryComponent::FiringCallbacks *pActiveFiring = NULL;

	int nWeaponListSize = pEntry->m_weapons.size();
	for (int i = 0; i < nWeaponListSize; i++) {
		fb::EntryComponent::FiringCallbacks *pFiring = pEntry->m_weapons.at(i);
		if (!HIWORD(pFiring)) continue;
		if (!pFiring->m_info) continue;

		if (pFiring->m_info->m_stanceFilterComponent == NULL || (DWORD)pFiring->m_info->m_stanceFilterComponent < 100) {
			fb::EntryComponent::WeaponInfo *Info = reinterpret_cast<fb::EntryComponent::WeaponInfo *>(pFiring->m_info);
			fb::WeaponFiring *WeaponFiring = Info->weaponFiring();
			if (!WeaponFiring) return NULL;
			return WeaponFiring;
		}

		fb::StanceFilterComponentData *pData = (fb::StanceFilterComponentData *)pFiring->m_info->m_stanceFilterComponent->StanceFilterData;
		if (!pData) continue;

		int *pv = pData->m_validStances;
		if (!pv) continue;

		for (int k = 0, kk = pv[-1]; k < kk; k++) {
			if (pv[k] == activeStance) {
				pActiveFiring = pFiring;
				fb::EntryComponent::WeaponInfo *Info = reinterpret_cast<fb::EntryComponent::WeaponInfo *>(pFiring->m_info);
				fb::WeaponFiring *WeaponFiring = Info->weaponFiring();
				if (!WeaponFiring) return NULL;

				return WeaponFiring;
			}
		}
	}

	return NULL;
}

static float Distance2D(float x1, float y1, float x2, float y2) {

	return sqrt((x2 - x1)*(x2 - x1) + (y2 - y1)*(y2 - y1));
}
static float Distance3D(float x1, float y1, float z1, float x2, float y2, float z2) {

	return sqrt((x2 - x1)*(x2 - x1) + (y2 - y1)*(y2 - y1) + (z2 - z1)*(z2 - z1));
}

inline float XAngle(float x1, float y1, float x2, float y2, float myangle) {
	float dl = Distance2D(x1, y1, x2, y2);
	if (dl == 0)dl = 1.0;
	float dl2 = abs(x2 - x1);
	float teta = ((180.0 / M_PI)*acos(dl2 / dl));
	if (x2<x1)teta = 180 - teta;
	if (y2<y1)teta = teta*-1.0;
	teta = teta - myangle;
	if (teta>180.0)teta = (360.0 - teta)*(-1.0);
	if (teta<-180.0)teta = (360.0 + teta);
	return teta;
}
inline float YAngle(float x1, float y1, float z1, float x2, float y2, float z2, float myangle) {

	float dl = Distance3D(x1, y1, z1, x2, y2, z2);
	if (dl == 0)dl = 1;
	float dl2 = abs(z2 - z1);
	float teta = ((180.0 / M_PI)*asin(dl2 / dl));;
	if (z2<z1)teta = teta*-1.0;
	teta = myangle + teta;
	if (teta>180.0)teta = (360.0 - teta)*(-1.0);
	if (teta<-180.0)teta = (360.0 + teta);
	return (-1)*teta;
}

static void RotatePointAlpha(float *outV, float x, float y, float z, float cx, float cy, float cz, float alpha) {
	D3DXMATRIX rot1;
	D3DXVECTOR4 vec;
	vec.x = x - cx;
	vec.z = y - cy;
	vec.y = z - cz;
	vec.w = 1.0;
	D3DXMatrixRotationY(&rot1, alpha*D3DX_PI / 180.0);
	D3DXVec4Transform(&vec, &vec, &rot1);
	outV[0] = vec.x + cx;
	outV[1] = vec.z + cy;
	outV[2] = vec.y + cz;
}

fb::FiringFunctionData* GetPlayerFFD(fb::ClientSoldierEntity* pMySoldier)
{
	if (!POINTERCHK(pMySoldier))
		return NULL;

	fb::WeaponFiringData* WepFiring = pMySoldier->getCurrentWeaponFiringData();
	if (!POINTERCHK(WepFiring))
		return NULL;

	fb::FiringFunctionData* pFFD = WepFiring->m_primaryFire;
	if (!POINTERCHK(pFFD))
		return NULL;

	return pFFD;
}
fb::ClientVehicleEntity* GetVehicle(fb::ClientPlayer* pClientPlayer)
{
	fb::ClientControllableEntity* pControllable = pClientPlayer->m_attachedControllable;
	if (!POINTERCHK(pControllable))
		return NULL;

	fb::ClientVehicleEntity* pVehicle = reinterpret_cast<fb::ClientVehicleEntity*>(pControllable);
	if (!POINTERCHK(pVehicle))
		return NULL;

	return pVehicle;
}
fb::Vec3 getVehicleSpeed(fb::ClientSoldierEntity * soldier)
{
	fb::Vec3 tempvec;
	if (soldier->m_player->m_attachedControllable)
	{
		tempvec = *soldier->m_player->m_attachedControllable->getVehicleSpeed();
	}
	else{
		tempvec.x = 0.0f;
		tempvec.y = 0.0f;
		tempvec.z = 0.0f;
	}
	return tempvec;
}
static bool IsVisible(fb::Vec3* target, fb::ClientSoldierEntity* pMySoldier)
{
	if (!pMySoldier->physics() || !pMySoldier->physics()->m_manager) return false;

	fb::IPhysicsRayCaster* pIRC = pMySoldier->physics()->m_manager->m_rayCaster;
	if (!POINTERCHK(pIRC)) return false;

	fb::RayCastHit pRCH;

	fb::GameRenderer::Singleton()->m_viewParams.view.Update();
	fb::Vec3 MyVec = fb::GameRenderer::Singleton()->m_viewParams.view.m_viewMatrixInverse.trans;

	__declspec(align(16)) fb::Vec3 Me = MyVec;
	__declspec(align(16)) fb::Vec3 enemy = *target;

	return !pIRC->physicsRayQuery("OnGroundState::update", &Me, &enemy, &pRCH, fb::DontCheckWater | fb::DontCheckTerrain | fb::DontCheckRagdoll | fb::DontCheckCharacter | fb::DontCheckPhantoms, NULL); // oder "OnGroundState::update"
}
void AimCorrection(fb::Vec3 MyVelocity, fb::Vec3 EnemyVelocity, fb::Vec3* InVec, float Distance, float Bulletspeed, float Gravity)
{
	//Need to dereference pointer
	*InVec = *InVec + EnemyVelocity * (Distance / fabs(Bulletspeed));
	*InVec = *InVec - MyVelocity * (Distance / fabs(Bulletspeed));
	FLOAT m_grav = fabs(Gravity);
	FLOAT m_dist = Distance / fabs(Bulletspeed);
	InVec->y += 0.5f * m_grav * m_dist * m_dist;
}

struct stMyVehicle
{
	// meine Version
	char* m_Game_Name;
	bool m_SeatHasWeapon[6]; // true -> VehicleWeapon
	bool m_OpenSeat[6]; // true -> Soldierweapon
};
static stMyVehicle VEHICLEDATA[38] = {
	// Jet
	// Conquest
	{ "F18-F", { true }, { false } },
	{ "SU-35BM-E", { true }, { false } },
	{ "F35", { true }, { false } },
	// Rush
	{ "A-10", { true }, { false } },
	{ "SU-25TM", { true }, { false } },

	// Chopper
	// Attack
	{ "AH1Z", { true, true }, { false, false } },
	{ "Mi28", { true, true }, { false, false } },
	// Scout
	{ "AH6", { true, false, false, false }, { false, true, true, false } },
	{ "Z11W", { true, false, false, false }, { false, true, true, false } },
	// Transport
	{ "Venom", { false, true, true, false, false }, { false, false, false, true, true } },
	{ "KA-60", { false, true, true, false, false }, { false, false, false, true, true } },

	// Tanks
	// MBT (Main battle tank)
	{ "M1A2", { true, true, false }, { false, false, false } },
	{ "T90", { true, true, false }, { false, false, false } },
	// Panzerzerstörer
	{ "M1128", { true, true, true, true, true }, { false, false, false, false, false } },
	{ "2S25", { true, true, true, true, true }, { false, false, false, false, false } },
	// Schützenpanzer
	{ "LAV", { true, true, true, true, true, true }, { false, false, false, false, false, false } },
	{ "LAV25", { true, true, true, true, true, true }, { false, false, false, false, false, false } },
	{ "BMP2", { true, true, true, true, true, true }, { false, false, false, false, false, false } },
	{ "BTR", { true, true, true, true, true, true }, { false, false, false, false, false, false } },

	// Anti-Air
	// Mobile
	// US Anti-Air wird nicht aufgeführt, da selber Name wie Schützenpanzer (LAV25)
	{ "9K22", { true }, { false } },
	//Stationary
	{ "Centurion", { true }, { false } },
	{ "Pantsir", { true }, { false } },

	// Jeeps
	// light
	{ "GrowlerITV", { false, true, false }, { false, false, true } },
	{ "VDV", { false, true, false }, { false, false, true } },
	{ "QuadBike", { false, false }, { false, true } },
	{ "KLR650", { false, false }, { false, true } },
	// heavy
	{ "HumveeArmored", { false, true, false, false }, { false, false, false, false } },
	{ "Humvee", { false, true, false, false }, { false, false, false, false } },
	{ "GAZ-3937", { false, true, false, false }, { false, false, false, false } },
	{ "VanModified", { true, false, false, false }, { false, true, true, true } },
	{ "VodnikModified", { false, true, true }, { false, false, false } },
	{ "VodnikPhoenix", { false, true, false, false }, { false, false, false, false } },
	{ "HumveeModified", { false, true, true }, { false, false, false } },

	// Boat
	{ "RHIB", { false, true, false, true }, { false, false, true, true } },

	// Amtrac
	{ "AAV-7A1", { false, true, false, false, false, false }, { false, false, false, false, false, false } },

	// Gunship
	{ "ac130", { false, true, true }, { false, false, false } },

	// Rocket Launchers Mobile
	{ "HIMARS", { false, true }, { false, false } },
	{ "STAR", { false, true }, { false, false } },
};
stMyVehicle* GetVehicleValues(char* szName)
{
	if (szName == NULL)
		return 0;

	for (int i = 0; i < 38; i++)
	{
		stMyVehicle* pVehicleValues = &VEHICLEDATA[i];
		if (strstr(pVehicleValues->m_Game_Name, szName))
			return pVehicleValues;
	}
	return 0;
}
char* GetVehicleName(fb::ClientPlayer* pClientPlayer)
{
	fb::ClientControllableEntity *pCCE = pClientPlayer->m_attachedControllable;
	if (POINTERCHK(pCCE))
	{
		if (POINTERCHK(pClientPlayer->getEntry()))
		{
			fb::ClientVehicleEntity* MyVehicle = reinterpret_cast<fb::ClientVehicleEntity*>(pCCE);
			if (POINTERCHK(MyVehicle))
			{
				fb::PhysicsEntity *pPE = MyVehicle->m_physicsEntity;
				if (POINTERCHK(pPE))
				{
					fb::PhysicsEntityData *pPED = pPE->m_data;
					if (POINTERCHK(pPED))
					{
						return pPED->GetObjectName();
					}
				}
			}
		}
	}
}
void _stdcall Bulletesp()
{
	fb::ClientGameContext* p_gameconext = fb::ClientGameContext::Singleton();
	if (!POINTERCHK(p_gameconext)) return;

	fb::EntityWorld::EntityCollection Entity = p_gameconext->m_level->m_gameWorld->m_collections.at(252);
	if (Entity.firstSegment)
	{
		for (int i = 0; i < (int)Entity.firstSegment->m_Collection.size(); i++)
		{
			if (Entity.firstSegment->m_Collection.size() > 0)
			{
				fb::GameEntity* pEntity = reinterpret_cast< fb::GameEntity* >(Entity.firstSegment->m_Collection.at(i));
				if (!POINTERCHK(pEntity))
					return;

				fb::Vec3* bullet = pEntity->GetEntityOrigin();


				fb::DebugRenderer::Singleton()->DrawSphere(*bullet, .125f, fb::Color32::Green(), true, false);

			}
		}
	}
}
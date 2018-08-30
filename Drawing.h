static fb::Vec3 Vec3Transform(fb::Vec3 In, fb::LinearTransform * pm)
{
	fb::Vec3 Out;

	Out.x = pm->left.x * In.x + pm->up.x * In.y + pm->forward.x * In.z + pm->trans.x;
	Out.y = pm->left.y * In.x + pm->up.y * In.y + pm->forward.y * In.z + pm->trans.y;
	Out.z = pm->left.z * In.x + pm->up.z * In.y + pm->forward.z * In.z + pm->trans.z;

	return Out;
}
void Draw2dLine(fb::Vec3 ScreenPos1, fb::Vec3 ScreenPos2, fb::Color32 Color)
{
	fb::Tuple2<float>pos1 = fb::Tuple2<float>(ScreenPos1.x, ScreenPos1.y);
	fb::Tuple2<float>pos2 = fb::Tuple2<float>(ScreenPos2.x, ScreenPos2.y);
	fb::DebugRenderer2::Singleton()->drawLine2d(&pos1, &pos2, Color);
}
void DrawSnapLine(fb::Vec3 target, fb::Color32 Color)
{
	fb::Vec3 linestart;
	float height = fb::DxRenderer::Singleton()->m_screenInfo.m_nHeight;
	linestart.x = fb::DxRenderer::Singleton()->m_screenInfo.m_nWidth / 2;
	linestart.y = height - (height*.05f);

	Draw2dLine(target, linestart, Color);
}

//uses screencoordinates
void Draw2dLineRect(fb::Vec3 ScreenPos1, fb::Vec3 ScreenPos2, fb::Color32 Color)
{
	fb::Tuple2<float>pos1 = fb::Tuple2<float>(ScreenPos1.x, ScreenPos1.y);
	fb::Tuple2<float>pos2 = fb::Tuple2<float>(ScreenPos2.x, ScreenPos2.y);
	fb::DebugRenderer2::Singleton()->drawLineRect2d(&pos1, &pos2, Color);
}
void CalcBox(fb::AxisAlignedBox* box2, fb::LinearTransform* trans, fb::Color32 color)
{
	__declspec(align(16)) fb::AxisAlignedBox box = *box2;
	fb::Vec3 max, min;
	fb::AxisAlignedBox boxwithtrans;
	boxwithtrans.max = Vec3Transform(box.max, trans);
	boxwithtrans.min = Vec3Transform(box.min, trans);

	ProjectToScreen(&boxwithtrans.max, &max);
	ProjectToScreen(&boxwithtrans.min, &min);
	Draw2dLineRect(min, max, color);
}
void ConnectBones(fb::ClientSoldierEntity* pEnemy, fb::PlayerBones bone1, fb::PlayerBones bone2, fb::Color32 color)
{
	if (!POINTERCHK(pEnemy)) return;

	fb::Vec3 bonevec1, bonevec2, bonescreen1, bonescreen2;
	
	//try everything twice
	if (!GetBonePos(pEnemy, bone1, &bonevec1)) {
		//if (!GetBonePos(pEnemy, bone1, &bonevec1))
			return;
	}
	if (!GetBonePos(pEnemy, bone2, &bonevec2)) {
		//if (!GetBonePos(pEnemy, bone2, &bonevec2))
			return;
	}
	if (!ProjectToScreen(&bonevec1, &bonescreen1)) {
		//if (!ProjectToScreen(&bonevec1, &bonescreen1))
			return;
	}
	if (!ProjectToScreen(&bonevec2, &bonescreen2)) {
		//if (!ProjectToScreen(&bonevec2, &bonescreen2))
			return;
	}

	Draw2dLine(bonescreen1, bonescreen2, color);
}
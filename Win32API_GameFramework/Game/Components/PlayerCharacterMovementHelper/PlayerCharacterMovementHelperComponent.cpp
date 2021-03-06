#include "PlayerCharacterMovementHelperComponent.h"
#include "Framework/Base/GameObject/GameObject.h"
#include "Game/Components/Movement/MovementComponent.h"
#include "Game/GameObject/TileMap/TileMap.h"

CPlayerCharacterMovementHelperComponent::CPlayerCharacterMovementHelperComponent()
{
	Movement = nullptr;
}

void CPlayerCharacterMovementHelperComponent::Start()
{
	super::Start();

	// Owner(PlayerCharacter) 에 추가도니 CMovementComponent 컴포넌트를 얻음
	Movement = Owner->GetComponent<CMovementComponent>();

	FVector mapAreaLT = TileMap->Position;
	FVector mapAreaRB = mapAreaLT + TileMap->GetMapSize();	

	Movement->SetMovableArea(mapAreaLT, mapAreaRB);
}

void CPlayerCharacterMovementHelperComponent::Tick(float dt)
{
	super::Tick(dt);	
	
	UpdateLookDirection();
}

void CPlayerCharacterMovementHelperComponent::SetTileMap(CTileMap* tileMap)
{
	TileMap = tileMap;
}

void CPlayerCharacterMovementHelperComponent::UpdateLookDirection()
{
	if (Movement == nullptr)
		return;

	// 플레이어 캐릭터의 x 속도를 얻음
	float velocityX = Movement->Velocity.X;

	// 플레이어 캐릭터가 이동중이라면
	if (FMath::Abs(velocityX) > 0.01f)
	{
		// 바라보는 방향 설정
		LookDirection = (FMath::Sign(velocityX) == 1) ? EDirection::Right : EDirection::Left;
	}

	// LOG(TEXT("LookDirection = ") << static_cast<int32>(LookDirection));
}

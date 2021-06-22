#pragma once
#include "Framework/Base/Component/Component.h"
#include "Framework/Enum/Direction.h"

class CPlayerCharacterMovementHelperComponent final :
    public CComponent
{
private:
    class CMovementComponent* Movement;

    class CTileMap* TileMap;

    // 플레이어 캐릭터가 바라보는 방향을 나타냄0
    EDirection LookDirection;

public:
    CPlayerCharacterMovementHelperComponent();

public:
    virtual void Start() override;
    virtual void Tick(float dt);

public:
    void SetTileMap(class CTileMap* tileMap);

private:
    // 플레이어 캐릭터가 바라보는 방향을 갱신
    void UpdateLookDirection();

public:
    FORCEINLINE EDirection GetLookDirection() const
    {
        return LookDirection;
    }
};


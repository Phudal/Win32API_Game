#pragma once
#include "Framework/Base/Component/Component.h"
#include "Framework/Enum/Direction.h"

class CPlayerCharacterMovementHelperComponent final :
    public CComponent
{
private:
    class CMovementComponent* Movement;

    class CTileMap* TileMap;

    // �÷��̾� ĳ���Ͱ� �ٶ󺸴� ������ ��Ÿ��0
    EDirection LookDirection;

public:
    CPlayerCharacterMovementHelperComponent();

public:
    virtual void Start() override;
    virtual void Tick(float dt);

public:
    void SetTileMap(class CTileMap* tileMap);

private:
    // �÷��̾� ĳ���Ͱ� �ٶ󺸴� ������ ����
    void UpdateLookDirection();

public:
    FORCEINLINE EDirection GetLookDirection() const
    {
        return LookDirection;
    }
};


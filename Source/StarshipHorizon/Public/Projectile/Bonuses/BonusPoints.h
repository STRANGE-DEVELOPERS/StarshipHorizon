// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Projectile/Bonuses/Bonus.h"
#include "BonusPoints.generated.h"

/**
 * 
 */
UCLASS()
class STARSHIPHORIZON_API ABonusPoints : public ABonus
{
	GENERATED_BODY()

protected:

	virtual void BonusCollected_Implementation() override;

public:

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Bonus")
	int Points;
};

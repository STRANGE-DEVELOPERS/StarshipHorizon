// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "Components/BoxComponent.h"
#include "GameFramework/SpringArmComponent.h"
#include "Camera/CameraComponent.h"
#include "Components/ShootComponent.h"
#include "Sound/SoundBase.h"
#include "PlayerPawn.generated.h"


DECLARE_DYNAMIC_MULTICAST_DELEGATE(FPawnDamagedEvent);


UCLASS()
class STARSHIPHORIZON_API APlayerPawn : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	APlayerPawn();

	

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	virtual float TakeDamage(float Damage, const FDamageEvent &DamageEvent, AController* InstigatedBy, AActor* DamageCauser) override;

	virtual void PossessedBy(AController* NewController) override;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Audio")
	class USoundBase* DestroySound;


	APlayerController* PlayerController;

	FVector2D MoveLimit;

	

private:

	/** called to handle touch move event, moves player to touch move location  */
	void OnTouchMove(ETouchIndex::Type Index, FVector Location);

	/** called to set touch location  */
	void OnTouchPressed(ETouchIndex::Type Index, FVector Location);

	FVector2D TouchLocation;

	bool Touching;

public:	

	UFUNCTION(BlueprintNativeEvent, Category = "Healths")
	bool CanBeDamaged();
	bool CanBeDamaged_Implementation();

	UFUNCTION(BlueprintNativeEvent, Category = "Healths")
	void ExplodePawn();
	void ExplodePawn_Implementation();

	UFUNCTION(BlueprintNativeEvent, Category = "Healths")
	void RecoverPawn();
	void RecoverPawn_Implementation();

	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	//void ReciveAnyDamage(float Damage, const UDamageType* DamageType, AController* InstigatedBy, AActor* DamageCauser);

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Pawn")
	UBoxComponent* PawnCollision;
	
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Pawn")
	UStaticMeshComponent* PawnMesh;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Pawn")
	UCameraComponent* PawnCamera;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Shooting")
	UShootComponent* ShootComponent;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Controls")
	float TouchMoveSensivity;

	UPROPERTY(BlueprintAssignable, Category = "Healths")
	FPawnDamagedEvent PawnDamaged;

	UPROPERTY(BlueprintReadWrite, Category = "Healths")
	bool CanRecieveDamage;
	
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Visual")
	UParticleSystem* DestroyParticle;
};
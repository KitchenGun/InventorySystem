// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"

#include "BaseCharacter.generated.h"

class UInventoryWidget;
class UInventoryComponent;
class USpringArmComponent;
class UCameraComponent;
class ABaseItemActor;
class UItemNameDisplayer;
class UBasicItemDataAsset;

UCLASS()
class INVENTORYSYSTEM_API ABaseCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	ABaseCharacter();

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	UInventoryComponent* InventoryComponent = nullptr;

	UPROPERTY(EditDefaultsOnly, Category= "UI")
	TSubclassOf<UItemNameDisplayer> ItemNameWidgetClass = nullptr;//상호작용에 사용되는 위젯 클래스

	UPROPERTY()
	UItemNameDisplayer* ItemName = nullptr;

	UPROPERTY(EditDefaultsOnly)
	float TraceDistance = 2000.f;

	UPROPERTY(EditDefaultsOnly)
	float CameraDistance = 350.0f;

protected:

	UPROPERTY()
	UCameraComponent* CameraComponent = nullptr;
	
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	void ToggleInventory();//인벤토리 키고 끄기
	
	void MoveRight(float Value);
	void MoveForward(float Value);
	void DropItem(UBasicItemDataAsset* DropItemData);//떨어트린 아이템 생성
	
private:
	
	FHitResult Hit;
	
	bool bIsInventoryActive = false;
	bool bIsPressPickUp = false;
	
	void EnableUIMode(const bool IsEnable);
	void LineTrace();

	void PressPickUp();

	void ReleasePickUp();
	
};
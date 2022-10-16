// Fill out your copyright notice in the Description page of Project Settings.


#include "InventoryWidget.h"


#include "DynamicInventoryGrid.h"
#include "Components/Button.h"

void UInventoryWidget::NativeConstruct()
{
	Super::NativeConstruct();

	bIsFocusable = true;
	
	SortButton->OnClicked.AddDynamic(this, &UInventoryWidget::UInventoryWidget::OnClickSortButton);
}

void UInventoryWidget::OnClickSortButton()
{
	InventoryGridPanel->SortItems();//정렬 버튼 입력시 호출
}

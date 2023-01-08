// Fill out your copyright notice in the Description page of Project Settings.

//#include "InventoryCharacter.h"
#include "Pickup.h"

APickup::APickup()
{
    //TODO: Setup the mesh for the pickup and set the item name, help text and item value
    InteractableMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("PickupMesh"));
    InteractableMesh-> SetSimulatePhysics(true);

    ItemName = FString("Enter an item name here...");
    InteractableHelpText = FString("Press E to pick the item up.");
    Value = 0;
}

void APickup::BeginPlay()
{
    InteractableHelpText = FString::Printf(TEXT("%s: Press E to pick up"), *ItemName));
}

void APickup::Interact_Implementation()
{
    AInventoryCharacter* Character = Cast<AInventoryCHaracter>(UGameplayStatics::GetPlayerCharacter(this, 0 ));

    //TODO: Put code here that places the item into the characters inventory

    OnPickedUp();

    //Glog->Log("Interact() - called from base pickup class (YOU SHOULD NOT BE SEEING THIS)");
}

void APickup::Use_Implementation()
{
    GLog->Log("Use() from base pickup class : YOU SHOULD NOT BE SEEING THIS");
}

void APickup::OnPickedUp()
{
    InteractableMesh->SetVisibility(false);
    InteractableMesh->SetSimulatePhysics(false);
    InteractableMesh->SetCollisionEnabled(ECollisionEnabled::NoCollision);

}

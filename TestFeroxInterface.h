#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"

#include "TestFeroxInterface.generated.h"


/** @brief Struct for Return more values via blueprint interface */
USTRUCT(BlueprintType)
struct FFetoxTestStr
{
	GENERATED_BODY()
	
	/** @brief Constructor to initializes values */
	FFetoxTestStr() :
	LocationTest(FVector(0.f, 0.f, 300.f)),
	ID(5)
	{
	}

	UPROPERTY(BlueprintReadWrite)
	FVector LocationTest;

	UPROPERTY(BlueprintReadWrite)
	int ID;
};


UINTERFACE(MinimalAPI)
class UTestFeroxInterface : public UInterface
{
	GENERATED_BODY()
};

/**
 * Test Ferox inteface class to use in C++ and Blueprints
 */
class TESTFEROX_API ITestFeroxInterface
{
	GENERATED_BODY()

public:
	
	/**@brief Classic interface function with return type */
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "Ferox|Interface")
	USkeletalMeshComponent* GetSkeletalMesh();
	virtual USkeletalMeshComponent* GetSkeletalMesh_Implementation();

	/**@brief Interface with @return FFetoxTestStr more variables, rather then only one*/
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "Ferox|Interface")
	FFetoxTestStr GetFetoxTestStr();
	virtual FFetoxTestStr GetFetoxTestStr_Implementation();
	
	/**@brief Classic interface event  */
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "Ferox|Interface")
	void Get2Mesh(UStaticMeshComponent* SecondInterfaceParameter);
	virtual void Get2Mesh_Implementation( UStaticMeshComponent* SecondInterfaceParameter);
};

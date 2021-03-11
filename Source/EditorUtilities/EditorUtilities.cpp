#include "EditorUtilities.h"

IMPLEMENT_GAME_MODULE(FEditorUtilitiesModule, EditorUtilities);

#define LOCTEXT_NAMESPACE "EditorUtilities"

void FEditorUtilitiesModule::StartupModule()
{
    UE_LOG(LogTemp, Warning, TEXT("EditorUtilities: Log Started"));
}

void FEditorUtilitiesModule::ShutdownModule()
{
    UE_LOG(LogTemp, Warning, TEXT("EditorUtilities: Log Ended"));
}

#undef LOCTEXT_NAMESPACE
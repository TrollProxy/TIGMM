// Greeting.cpp
#include "Greeting.h"
#include <eiface.h>

extern IVEngineServer2* engine;

void Greeting::FireGameEvent(IGameEvent* event)
{
    if (strcmp(event->GetName(), "player_connect") == 0)
    {
        int playerIndex = engine->IndexOfEdict(event->GetEventProperty<int>("index"));
        char welcomeMessage[256];
        snprintf(welcomeMessage, sizeof(welcomeMessage), "Welcome %s to the server!", engine->GetPlayerName(playerIndex));
        SendChatMessage(welcomeMessage, playerIndex);
    }
}

void Greeting::SendChatMessage(const char* message, int playerIndex /*= -1*/)
{
    if (playerIndex == -1)
    {
        engine->ServerCommand(UTIL_VarArgs("say \"%s\"\n", message));
    }
    else
    {
        engine->ClientCommand(engine->GetClientEdict(playerIndex), UTIL_VarArgs("say \"%s\"\n", message));
    }
}

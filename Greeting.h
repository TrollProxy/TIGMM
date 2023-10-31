// Greeting.h
#ifndef _INCLUDE_GREETING_H_
#define _INCLUDE_GREETING_H_

#include "igameevents.h"
#include "ISmmPlugin.h"

class Greeting : public IGameEventListener2
{
public:
    void FireGameEvent(IGameEvent* event) override;
    void SendChatMessage(const char* message, int playerIndex = -1);
};

extern Greeting g_Greeting;

#endif // _INCLUDE_GREETING_H_

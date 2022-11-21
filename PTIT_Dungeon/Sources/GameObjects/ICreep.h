#pragma once
#include "IPState.h"
#include "Tutorial_Map.h"

class ICreep {
public:
	virtual void changeNextState(IPState::STATE nextState) = 0;
	virtual HitBox* getHitBox() = 0;
};
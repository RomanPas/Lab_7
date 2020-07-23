#pragma once

#include "Listener.h"

class Subject {
public:
	virtual ~Subject() {};
	virtual void addListener(Listener* listener) = 0;
	virtual void removeListener(Listener* listener) = 0;
	virtual void notify() = 0;
};
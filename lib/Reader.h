#pragma once

#include "Listener.h"
#include "Subject.h"

#include <string>
#include <list>
#include <vector>

class Reader : public Subject {
public:
	Reader();
	void reading();

	// Subject
	void addListener(Listener* listener) override;
	void removeListener(Listener* listener) override;
	void notify() override;
private:
	std::list<Listener*> listeners_;
	std::vector<std::string> data_;
};
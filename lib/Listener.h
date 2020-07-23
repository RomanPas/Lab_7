#pragma once

#include <vector>
#include <string>

class Listener {
public:
	virtual ~Listener() {};
	virtual void update(const std::vector<std::string>& data) = 0;
};
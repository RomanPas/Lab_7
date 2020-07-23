#pragma once

#include "Listener.h"

#include <iostream>
#include <fstream>
#include <vector>

class Logger : public Listener {
public:
	Logger() = default;
	~Logger();

	// Listener
	void update(const std::vector<std::string>& data) override;

private:
	std::ofstream fout_;
};
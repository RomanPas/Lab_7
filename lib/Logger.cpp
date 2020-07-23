#include "Logger.h"

#include <ctime>

using namespace std;

Logger::~Logger() {
	if (fout_.is_open())
		fout_.close();
}

void Logger::update(const vector<string>& data) {
	if (!fout_.is_open()) {
		fout_ = ofstream("bulk" + std::to_string(time(nullptr)) + ".log");
	}

	auto it = data.begin();
	string result = "bulk: " + *it;

	while (++it != data.end()) {
		result += ", " + *it;

	}
	result += "\n";

	cout << result;
	fout_ << result;
}
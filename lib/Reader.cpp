#include "Reader.h"

#include <vector>
#include <iostream>
#include <streambuf>

using namespace std;

Reader::Reader() {}

void Reader::addListener(Listener* listener) {
	listeners_.push_back(listener);
}

void Reader::removeListener(Listener* listener) {
	listeners_.remove(listener);
}

void Reader::notify() {
	for (const auto& listener : listeners_)
		listener->update(data_);
}

void Reader::reading() {
	size_t count = 0;

	for (string line; getline(cin, line);) {
		if (line.empty() && !data_.empty()) {
			notify();
			data_.clear();
		}
		else if (line == "{") {
			++count;
		}
		else if (line == "}") {
			--count;
			if (count == 0) {
				notify();
				data_.clear();
			}
		}
		else {
			data_.push_back(move(line));
		}
	}
}
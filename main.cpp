#include "lib/Reader.h"
#include "lib/Logger.h"

#include <memory>

using namespace std;

int main()
{
	unique_ptr<Logger> logger = make_unique<Logger>();
	Reader reader;
	reader.addListener(logger.get());
	reader.reading();

	return 0;
}
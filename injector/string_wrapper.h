#ifndef STRING_WRAPPER_H
#define STRING_WRAPPER_H

#include <cstddef>

class string_wrapper {
private:
	char *data;
	size_t size;
	char *buffer;
public:
	string_wrapper(char *data, size_t size);

	void printData();

	const char *getBuffer();

	~string_wrapper();
};

#endif //STRING_WRAPPER_H

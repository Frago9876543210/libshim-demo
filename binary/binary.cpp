#include <cstdio>
#include <cstring>

class string_wrapper {
private:
	char *data;
	size_t size;
	char *buffer;
public:
	string_wrapper(char *data, size_t size) : data(data), size(size) {
		printf("string_wrapper::string_wrapper(\"%s\", %ld)\n", data, size);

		char stack[] = "This data would be copied into heap";
		buffer = new char[1024];
		memcpy(buffer, stack, sizeof(stack));
	}

	void printData() {
		printf("%s\n", data);
	}

	const char *getBuffer() {
		return buffer;
	}

	~string_wrapper() {
		printf("string_wrapper::~string_wrapper()\n");
		delete[] buffer;
	}
};

int main() {
	char data[] = "regular string from this executable";
	string_wrapper string = string_wrapper(data, sizeof(data));
	string.printData();
	printf("binary called string_wrapper::getBuffer(): \"%s\"\n", string.getBuffer());
	return 0;
}

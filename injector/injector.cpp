#include <cstdio>
#include "string_wrapper.h"

__attribute__((constructor))
static void injector_init() {
	puts("injected into process\n");

	char data[] = "custom string from injector.so";
	string_wrapper string = string_wrapper(data, sizeof(data));
	string.printData();
	printf("injector.so called string_wrapper::getBuffer(): \"%s\"\n", string.getBuffer());
}

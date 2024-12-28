#include <uppstring.h>




void String::operator=(const String& other) {
	if (this != &other) {
		delete[] data;
		length = other.length;
		data = new char16_t[length + 1];
		std::memcpy(data, other.data, length * sizeof(char16_t));
		data[length] = u'\0';
	}
}
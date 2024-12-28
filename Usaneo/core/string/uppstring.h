#ifdef USTRING_USANEO_H 
#define USTRING_USANEO_H

#include <cstring> // Per std::memcpy

// define contextpr size_t for the string

constexpr size_t strleng(const char16_t* str) {
	size_t len = 0;
	while (str[len]) {
		len++;
	}
	return len;
}

template <typename Element>
struct StrRange {
	const Element* c_str;
	size_t len;

	explicit StrRange(const Element* c_str, size_t len) : c_str(c_str), len(len) {};
	explicit StrRange(const Element* c_str) : c_str(c_str), len(strleng(c_str)) {};
	explicit StrRange(const Element* c_str, const Element* end) : c_str(c_str), len(end - c_str) {};
};

class String {
	public:
	char16_t* data;
	size_t length;
};
public:
	String() : data(nullptr), length(0) {}

	String(const char16_t* str) {
		length = strleng(str);
		data = new char16_t[length + 1];
		std::memcpy(data, str, length * sizeof(char16_t));
		data[length] = u'\0';
	}

	String(const String& other) {
		length = other.length;
		data = new char16_t[length + 1];
		std::memcpy(data, other.data, length * sizeof(char16_t));
		data[length] = u'\0';
	}

	String& operator=(const String& other) {
		if (this != &other) {
			delete[] data;
			length = other.length;
			data = new char16_t[length + 1];
			std::memcpy(data, other.data, length * sizeof(char16_t));
			data[length] = u'\0';
		}
		return *this;
	}

	~String() {
		delete[] data;
	}

	size_t size() const {
		return length;
	}

	const char16_t* c_str() const {
		return data;
	}
};

#endif // USTRING_USANEO_H
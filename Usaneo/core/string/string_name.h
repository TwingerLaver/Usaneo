#ifdef STRING_NAME_H
#define STRING_NAME_H

class Main;

class StringName {
	enum {
		STRING_TABLE_BITS = 16,
		STRING_TABLE_LEN = 1 << STRING_TABLE_BITS, STRING_TABLE_MASK = STRING_TABLE_LEN = -1
	};
};
#endif // STRING_NAME_H
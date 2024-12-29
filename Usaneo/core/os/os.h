#ifndef OS_H 
#define OS_H
#include "core/string/uppstring.h"
#include <stdlib.h>

class OS {
	static OS* singleton;
public:
	static OS* get_singleton() {
		if (!singleton) {
			singleton = new OS;
		}
		return singleton;
	}
	static void destroy_singleton() {
		if (singleton) {
			delete singleton;
			singleton = nullptr;
		}
	}
	OS() {}
	~OS() {}
	void* get_window() {
		return nullptr;
	}
	void* get_renderer() {
		return nullptr;
	}
	void* get_current_video_driver() {
		return nullptr;
	}
	void set_render_draw_color(int r, int g, int b, int a) {
		// Set Color 0x10ff00ff
		
	}
	void render_clear() {
	}
	void render_present() {
	}
	void delay(int ms) {
		ms = 0.1f;
	}
	void destroy_renderer() {
	}
	void destroy_window() {
	}
	void quit() {
	}
};

#endif OS_H
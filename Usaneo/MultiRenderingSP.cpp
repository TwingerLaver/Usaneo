// Date: 2024-26-12

#include <string>

class MultiRenderingSP {
public:
	MultiRenderingSP() = default;
	~MultiRenderingSP() = default;
	void render() {
		// Render the scene
	}
	void render(const std::string& shaderName) {
		// Render the scene with the specified shader
	}
	void renderPass(const std::string& shaderName, const std::string& textureName, const std::string& materialName) {
		// Render the scene with the specified shader, texture and material
	}

};
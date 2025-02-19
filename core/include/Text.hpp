#ifndef TEXT_H
#define TEXT_H
#include "Component.hpp"
#include <SDL2/SDL_ttf.h>
#include "SDL2/SDL.h"
#include "Timer.hpp"
#include "GameObject.hpp"
#include "GameData.hpp"
#include <memory>
class Text : public Component {
    public: 
    enum TextStyles {SOLID, SHADED, BLENDED};
    Text(GameObject& ass, const std::string& fontFile, int FontSize, TextStyles style, const std::string& text, SDL_Color color);
    void Update(float dt) override;
    void Render() override; 
    bool Is(GameData::Types types) const override;
    void SetText(const std::string& text);
    void SetColor(SDL_Color color);
    void SetStyle(TextStyles style);
    void SetFontSize(int fontSize);
    void SetFontFile(const std::string& fontFile);
    void SetBlink(bool blink, float blinPeriod);

    const GameData::Types Type = GameData::Types::Text;
    private:
    void RemakeTextur();

    std::shared_ptr<TTF_Font> font;
    std::shared_ptr<SDL_Texture> texture;

    std::string text;
    TextStyles style;
    std::string fontFile;
    int fontSize;
    SDL_Color color;
    bool blink;
    bool display;
    float blinkPeriod;
    Timer blinkTime;
};
#endif
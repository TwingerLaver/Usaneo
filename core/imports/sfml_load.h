#include <SFML/Graphics.hpp>

using namespace sf;
namespace sfm {
class SFML_Load {
    public:
    SFML_Load();
    ~SFML_Load();
    void window_init() {
        sf::RenderWindow window(sf::VideoMode(600, 480), "Usaneno Engine");

        while(window.isOpen()) {
            sf::Event evt;
            while(window.pollEvent(evt)){
                if (evt.type == sf::Event::Closed){
                    window.close();
                }
            }
            window.clear();
            window.display();
        }
    }
};
}
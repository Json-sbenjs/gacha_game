#include <SFML/Graphics.hpp>
#include <string>

class NewWindow {
    private:
        std::string namePage;
        sf::VideoMode videoMode;
        sf::RenderWindow window;
    public:
        // construteur
        NewWindow() : videoMode({1920, 1080}), namePage(" ") {}
        NewWindow(std::string name) : videoMode({1920, 1080}), namePage(name) {}
        NewWindow(sf::VideoMode mode, std::string name) : videoMode(mode), namePage(name) {}

        // fonction encapsulant la sfml
        sf::VideoMode getVideoMode() const {
            return videoMode;
        }
        bool windowIsOpen() {
            if (window.isOpen())
                return true;
            return false;
        }
        void setWindow() { window.create(videoMode, namePage);}
        void close() { window.close(); }
        void clear() { window.clear(); }
        void display() { window.display(); }
        std::optional<sf::Event> pollEvent() { return window.pollEvent(); }
};

int main()
{
    NewWindow window("firth window");
    window.setWindow();

    while (window.windowIsOpen())
    {
        while (const std::optional event = window.pollEvent())
        {
            if (event->is<sf::Event::Closed>())
                window.close();
        }
        window.clear();
        window.display();
    }
}

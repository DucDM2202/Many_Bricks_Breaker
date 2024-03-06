#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>

class Ball {
public:
    Ball() : x(0), y(0), dx(2), dy(2), diameter(20), count(0), running(false), touch(false) {}

    void start() {
        running = true;
    }

    void stop() {
        running = false;
    }

    bool isRunning() {
        return running;
    }

    void update(sf::RenderWindow& window) {
        if (running) {
            x += dx;
            y += dy;

            if (x + diameter > window.getSize().x || x < 0) {
                dx = -dx;
                count++;
            }
            if (y + diameter > window.getSize().y || y < 0) {
                dy = -dy;
                count++;
            }
        }
    }

    void draw(sf::RenderWindow& window) {
        sf::CircleShape circle(diameter / 2);
        circle.setPosition(x, y);
        circle.setFillColor(sf::Color::Red);
        window.draw(circle);
    }

    int getBounces() {
        return count;
    }

private:
    int x;
    int y;
    int dx;
    int dy;
    int diameter;

    int count;
    bool running;
    bool touch;
};

int main() {
    sf::RenderWindow window(sf::VideoMode(300, 300), "Bouncing Ball");
    Ball ball;

    
   
    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
            
                
            
        }
    }
}
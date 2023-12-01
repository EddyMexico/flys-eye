/*
 * Coded by EddyMexico
 *
 * */

#include <SFML/Graphics.hpp>
#include <vector>
#include <cmath>

void drawLines(sf::RenderWindow*, int);

int main() {
    sf::RenderWindow window(sf::VideoMode(800, 800), "Fly's eye");
    bool keyPressed = false;
    int vertex = 3;

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }
        }

        /*
         * The user can interact by selecting the number of points calculated
         * < To decrease
         * > To increase */
        if (event.type == sf::Event::KeyPressed && !keyPressed) {
            keyPressed = true;
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Scan::Left))
            {
                if (vertex > 3) vertex--;
            }
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Scan::Right))
            {
                if (vertex < 100) vertex++;
            }
        } else if (event.type == sf::Event::KeyReleased) {
            keyPressed = false;
        }

        drawLines(&window, vertex);
        window.display();
    }
    return 0;
}

void drawLines(sf::RenderWindow* window, int vertex) {
    float radio = 200.0f;
    std::vector<sf::Vector2f> points;

    for (int i = 0; i < vertex; ++i) {
        float angle = 2 * M_PI * i / vertex;
        float x = radio * std::cos(angle) + 400;
        float y = radio * std::sin(angle) + 400;
        points.push_back(sf::Vector2f(x, y));
    }

    window->clear();
    sf::VertexArray lines(sf::Lines);

    for (int i = 0; i < vertex; ++i) {
        for (int j = i + 1; j < vertex; ++j) {
            // Skip lines connecting opposite points when vertex is odd
            if (vertex % 2 != 0 || (std::abs(i - j) != vertex / 2)) {
                lines.append(sf::Vertex(points[i], sf::Color::Red));
                lines.append(sf::Vertex(points[j], sf::Color::Blue));
            }
        }
    }

    window->draw(lines);
}
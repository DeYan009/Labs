#include <SFML/Graphics.hpp>
#include <vector>
#include <cstdlib>
#include <ctime>

const int WINDOW_WIDTH = 800;
const int WINDOW_HEIGHT = 600;
const float BALL_RADIUS = 25.0f;
const float BALL_SPEED = 25.0f;
const int PIPE_WIDTH = 80;
const int PIPE_GAP = 100;
const float PIPE_SPEED = 3.0f;

class Ball {
public:
    sf::CircleShape shape;

    Ball(float x, float y) {
        shape.setRadius(BALL_RADIUS);
        shape.setPosition(x, y);
        shape.setFillColor(sf::Color(255, 165, 0));
    }

    void moveUp() {
        shape.move(0, -BALL_SPEED);
        if (shape.getPosition().y < 0) shape.setPosition(shape.getPosition().x, 0);
    }

    void moveDown() {
        shape.move(0, BALL_SPEED);
        if (shape.getPosition().y + BALL_RADIUS*2 > WINDOW_HEIGHT)
            shape.setPosition(shape.getPosition().x, WINDOW_HEIGHT - BALL_RADIUS*2);
    }

    void moveLeft() {
        shape.move(-BALL_SPEED * 2, 0);
        if (shape.getPosition().x < 0) shape.setPosition(0, shape.getPosition().y);
    }

    void moveRight() {
        shape.move(BALL_SPEED * 2, 0);
        if (shape.getPosition().x + BALL_RADIUS*2 > WINDOW_WIDTH)
            shape.setPosition(WINDOW_WIDTH - BALL_RADIUS*2, shape.getPosition().y);
    }

    sf::FloatRect getBounds() const {
        return shape.getGlobalBounds();
    }
};

class Pipe {
public:
    sf::RectangleShape top, bottom;
    bool passed = false;

    Pipe(float x) {
        int topHeight = 100 + rand() % 300;

        top.setSize(sf::Vector2f(PIPE_WIDTH, topHeight));
        top.setPosition(x, 0);
        top.setFillColor(sf::Color(0, 180, 0));

        bottom.setSize(sf::Vector2f(PIPE_WIDTH, WINDOW_HEIGHT - topHeight - PIPE_GAP));
        bottom.setPosition(x, topHeight + PIPE_GAP);
        bottom.setFillColor(sf::Color(0, 180, 0));
    }

    void update() {
        top.move(-PIPE_SPEED, 0);
        bottom.move(-PIPE_SPEED, 0);
    }

    bool isOffScreen() const {
        return top.getPosition().x + PIPE_WIDTH < 0;
    }

    sf::FloatRect getTopBounds() const { return top.getGlobalBounds(); }
    sf::FloatRect getBottomBounds() const { return bottom.getGlobalBounds(); }
};

int main() {
    srand(time(0));
    sf::RenderWindow window(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), "Simple Ball Game");
    window.setFramerateLimit(60);

    Ball ball(WINDOW_WIDTH/4, WINDOW_HEIGHT/2);
    std::vector<Pipe> pipes;
    int pipeTimer = 0;
    int score = 0;
    bool gameOver = false;

    sf::Font font;
    if (!font.loadFromFile("C:/Windows/Fonts/arial.ttf")) {
        return 1;
    }

    sf::Text scoreText;
    scoreText.setFont(font);
    scoreText.setString("Score: 0");
    scoreText.setCharacterSize(30);
    scoreText.setFillColor(sf::Color::White);
    scoreText.setPosition(10, 10);

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();

            if (event.type == sf::Event::KeyPressed && !gameOver) {
                if (event.key.code == sf::Keyboard::W) ball.moveUp();
                if (event.key.code == sf::Keyboard::S) ball.moveDown();
                if (event.key.code == sf::Keyboard::A) ball.moveLeft();
                if (event.key.code == sf::Keyboard::D) ball.moveRight();
            }

            if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Space && gameOver) {
                gameOver = false;
                ball.shape.setPosition(WINDOW_WIDTH/4, WINDOW_HEIGHT/2);
                pipes.clear();
                score = 0;
            }
        }

        if (!gameOver) {
            if (pipeTimer++ > 100) {
                pipes.emplace_back(WINDOW_WIDTH);
                pipeTimer = 0;
            }

            for (auto& pipe : pipes) {
                pipe.update();

                if (ball.getBounds().intersects(pipe.getTopBounds()) || 
                    ball.getBounds().intersects(pipe.getBottomBounds())) {
                    gameOver = true;
                }

                if (!pipe.passed && pipe.top.getPosition().x + PIPE_WIDTH < ball.shape.getPosition().x) {
                    pipe.passed = true;
                    score++;
                    scoreText.setString("Score: " + std::to_string(score));
                }
            }

            pipes.erase(std::remove_if(pipes.begin(), pipes.end(), 
                [](const Pipe& p) { return p.isOffScreen(); }), pipes.end());
        }

        window.clear(sf::Color(135, 206, 235));

        for (const auto& pipe : pipes) {
            window.draw(pipe.top);
            window.draw(pipe.bottom);
        }

        window.draw(ball.shape);

        window.draw(scoreText);

        if (gameOver) {
            sf::Text gameOverText;
            gameOverText.setFont(font);
            gameOverText.setString("Game Over!\nPress SPACE to restart");
            gameOverText.setCharacterSize(40);
            gameOverText.setFillColor(sf::Color::Red);
            gameOverText.setPosition(WINDOW_WIDTH/2 - 150, WINDOW_HEIGHT/2 - 50);
            window.draw(gameOverText);
        }

        window.display();
    }

    return 0;
}

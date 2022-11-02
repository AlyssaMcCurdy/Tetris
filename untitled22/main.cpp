#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
using namespace sf;
using namespace std;

int main() {
    const int window_width = 375;
    const int window_height = 700;
    sf::RenderWindow window(sf::VideoMode(window_width, window_height), "TETRIS");
    sf::RectangleShape player(sf::Vector2f(40.0f, 40.0f));
    player.setPosition(168,20);
    sf::RectangleShape player2(sf::Vector2f(20.0f, 80.0f));
    player2.setPosition(168, 40);
    sf::RectangleShape border1(sf::Vector2f(window_width,20));
    border1.setPosition(1,1);
    sf::RectangleShape border2(sf::Vector2f(window_width,20));
    border2.setPosition(1,window_height-border2.getSize().y);
    sf::RectangleShape border3(sf::Vector2f(20,window_height));
    border3.setPosition(1,1);
    sf::RectangleShape border4(sf::Vector2f(20,window_height));
    border4.setPosition(window_width-border4.getSize().x,1);
    //Texture t;
    //t.loadFromFile("C:/SFML/dababy.png");
    //Sprite s(t);
    //s.setScale(0.05f,0.10f);
   // sf::Music music;
   // music.openFromFile("C:/SFML/letsgo.wav");
   // music.play();
    //music.setLoop(true);


    while (window.isOpen()) {
        sf::Event event;
        player.move(0,0.1);
        while(window.pollEvent(event)) {
            switch(event.type){
                case sf::Event::Closed:
                    window.close();
                    break;
                case sf::Event::KeyPressed:
                    if(event.key.code == sf::Keyboard::Escape){
                        window.close();
                    }
                    if (event.key.code == sf::Keyboard::D){
                        player.move(50.0,0.0);
                        //s.move(50.0,0.0);
                    }
                    else if (event.key.code == sf::Keyboard::A){
                        player.move(-50.0,0.0);
                        //s.move(-50.0,0.0);
                    }
                    else if (event.key.code == sf::Keyboard::S){
                        //s.move(0.0,50.0);
                    }
                    else if (event.key.code == sf::Keyboard::W){
                        //s.move(0.0,-50.0);
                    }
                    break;
            }
        }


        if (player.getPosition().x < border1.getSize().y){
            player.setPosition(border1.getSize().y,player.getPosition().y);
        }
        else if(player.getPosition().y <border3.getSize().x){
            player.setPosition(player.getPosition().x,border3.getSize().x);
        }
        else if (player.getPosition().x + player.getGlobalBounds().width > window_width-border4.getSize().x){
            player.setPosition(window_width-border4.getSize().x - player.getGlobalBounds().width,player.getPosition().y);
        }
        else if (player.getPosition().y + player.getGlobalBounds().height > window_height - border2.getSize().y){
            player.setPosition(player.getPosition().x,(window_height - border2.getSize().y) - player.getGlobalBounds().height);
            player.move(0,0.0);
        }



        //if (s.getPosition().x < border1.getSize().y){
        //    s.setPosition(border1.getSize().y,s.getPosition().y);
        //}
        //if(s.getPosition().y <border3.getSize().x){
        //    s.setPosition(s.getPosition().x,border3.getSize().x);
        //}
        //if (s.getPosition().x + s.getGlobalBounds().width > window_width-border4.getSize().x){
        //    s.setPosition(window_width-border4.getSize().x - s.getGlobalBounds().width,s.getPosition().y);
        //}
       // if (s.getPosition().y + s.getGlobalBounds().height > window_height - border2.getSize().y){
       //     s.setPosition(s.getPosition().x,(window_height - border2.getSize().y) - s.getGlobalBounds().height);
       // }


        window.clear();
        player.setFillColor(sf::Color::Yellow);
        player2.setFillColor(sf::Color::Blue);
        border1.setFillColor(sf::Color::Red);
        border2.setFillColor(sf::Color::Red);
        border3.setFillColor(sf::Color::Red);
        border4.setFillColor(sf::Color::Red);
        window.draw(border1);
        window.draw(border2);
        window.draw(border3);
        window.draw(border4);
        window.draw(player);
        player.getPosition();


        if (player.getPosition().y + player.getGlobalBounds().height == window_height - border2.getSize().y) {
            window.draw(player2);
            player2.move(0,0.1);
            sf::Event event2;
            while(window.pollEvent(event2)) {
                switch(event2.type){
                    case sf::Event::Closed:
                        window.close();
                        break;
                    case sf::Event::KeyPressed:
                        if(event2.key.code == sf::Keyboard::Escape){
                            window.close();
                        }
                        if (event2.key.code == sf::Keyboard::D){
                            player2.move(50.0,0.0);
                            //s.move(50.0,0.0);
                        }
                        else if (event2.key.code == sf::Keyboard::A){
                            player2.move(-50.0,0.0);
                            //s.move(-50.0,0.0);
                        }
                        else if (event2.key.code == sf::Keyboard::S){
                            //s.move(0.0,50.0);
                        }
                        else if (event2.key.code == sf::Keyboard::W){
                            //s.move(0.0,-50.0);
                        }
                        break;
                }
            }
        }
        //window.draw(s);
        window.display();

    }

        return 0;
}
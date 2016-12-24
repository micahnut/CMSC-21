#include <SFML/Graphics.hpp>
#include <iostream>
#include <conio.h>

using namespace std;

class Game{
public:
    Game();
    void run();
private:
    void processEvents();
    void update(sf::Time);
    void render();
    void menu();
    void help();
private:
    sf::RenderWindow mWindow;
    sf::Texture mTexture,nTexture,oTexture,bTexture,xTexture,yTexture,zTexture,MenuTexture,tHelp1,tHelp2;
    sf::Sprite mPlayer,nPlayer,oPlayer,bBackground,xPlayer,yPlayer,zPlayer,MenuSprite,sHelp1,sHelp2;
    sf::Vector2i source;
    bool stance;
    float PlayerSpeed, stanceSpeed;
    float frameCounter, switchFrame;

};

int main(){
    Game game;
    game.run();
}

Game::Game():mWindow(sf::VideoMode(1000, 642), "Avengers"),mTexture(),mPlayer(),nPlayer(),oPlayer(),source(0,1){
    if (!bTexture.loadFromFile("arena_1.png")){
        cout<<"Error loading file."<<endl;
    }
    bBackground.setTexture(bTexture);

    if (!MenuTexture.loadFromFile("menu.png")){
        cout<<"Error loading file."<<endl;
    }
    MenuSprite.setTexture(MenuTexture);

    if (!tHelp1.loadFromFile("help_1.png")){
        cout<<"Error loading file."<<endl;
    }
    sHelp1.setTexture(tHelp1);

    if (!tHelp2.loadFromFile("help_2.png")){
        cout<<"Error loading file."<<endl;
    }
    sHelp2.setTexture(tHelp2);

    if (!mTexture.loadFromFile("sprite_07.png")){
        cout<<"Error loading file."<<endl;
    }
    mPlayer.setTexture(mTexture);
    mPlayer.setPosition(600.f, 50.f);

    if (!nTexture.loadFromFile("sprite_08.png")){
        cout<<"Error loading file."<<endl;
    }
    nPlayer.setTexture(nTexture);
    nPlayer.setPosition(680.f, 240.f);

    if (!oTexture.loadFromFile("sprite_09.png")){
        cout<<"Error loading file."<<endl;
    }
    oPlayer.setTexture(oTexture);
    oPlayer.setPosition(800.f, 450.f);

    if (!xTexture.loadFromFile("sprite_01.png")){
        cout<<"Error loading file."<<endl;
    }
    xPlayer.setTexture(xTexture);
    xPlayer.setPosition(10.f, 400.f);

    if (!yTexture.loadFromFile("sprite_03.png")){
        cout<<"Error loading file."<<endl;
    }
    yPlayer.setTexture(yTexture);
    yPlayer.setPosition(0.f, 200.f);

    if (!zTexture.loadFromFile("sprite_05.png")){
        cout<<"Error loading file."<<endl;
    }
    zPlayer.setTexture(zTexture);
    zPlayer.setPosition(230.f, 30.f);

    stance = true;
    PlayerSpeed = 100.0;
    frameCounter = 0;
    switchFrame = 100;
    stanceSpeed = 300.0;
}

void Game::menu(){
    sf::Event event;
    mWindow.clear();
    mWindow.draw(MenuSprite);
    mWindow.display();
    while(mWindow.isOpen()){
        while(mWindow.pollEvent(event)){
            switch(event.type){
                case sf::Event::MouseButtonPressed:
                    sf::Vector2i position = sf::Mouse::getPosition(mWindow);
                    if(position.x>=800&&position.y>=420&&position.x<=1000&&position.y<=500){
                        help();
                        menu();
                        return;
                    }
                    if(position.x>=650&&position.y>=290&&position.x<=990&&position.y<=350)
                        return;
                    if(position.x>=800&&position.y>=530&&position.x<=1000&&position.y<=600){
                        mWindow.close();
                        return;
                    }
                    break;
            }
        }
    }
}

void Game::help(){
    sf::Event event, event2;
    mWindow.clear();
    mWindow.draw(sHelp1);
    mWindow.display();
    while(mWindow.isOpen()){
        while(mWindow.pollEvent(event)){
            switch(event.type){
                case sf::Event::MouseButtonPressed:
                    sf::Vector2i position = sf::Mouse::getPosition(mWindow);
                    if(position.x>=850&&position.y>=600&&position.x<=970&&position.y<=630){
                        mWindow.draw(sHelp2);
                        mWindow.display();
                        //
                        while(mWindow.isOpen()){
                            while(mWindow.pollEvent(event2)){
                                switch(event2.type){
                                    case sf::Event::MouseButtonPressed:
                                        sf::Vector2i position2 = sf::Mouse::getPosition(mWindow);
                                        if(position2.x>=850&&position2.y>=600&&position2.x<=970&&position2.y<=630){
                                            return;
                                        }
                                }
                            }
                        }
                        //
                    }
            }
        }
    }
}


void Game::run(){
    sf::Clock clock;
    menu();
    while (mWindow.isOpen()){
        sf::Time deltaTime = clock.restart();
        processEvents();
        update(deltaTime);
        render();
    }
}

void Game::processEvents(){
    sf::Event event;
    while (mWindow.pollEvent(event)){
        if(event.type==sf::Event::Closed)
            mWindow.close();
    }
}

void Game::update(sf::Time deltaTime){
    int max;
    sf::Vector2f movement(0.f, 0.f);
    mPlayer.setTextureRect(sf::IntRect(source.x*223,source.y*0,199,250));
    nPlayer.setTextureRect(sf::IntRect(source.x*205,source.y*0,190,219));
    oPlayer.setTextureRect(sf::IntRect(source.x*166,source.y*0,166,220));
    xPlayer.setTextureRect(sf::IntRect(source.x*181,source.y*0,170,250));
    yPlayer.setTextureRect(sf::IntRect(source.x*270,source.y*0,270,350));
    zPlayer.setTextureRect(sf::IntRect(source.x*135,source.y*0,125,268));

    if(stance){
        if(frameCounter >= switchFrame){
            frameCounter = 0;
            source.x++;
            max = 3;
            if(source.x>=max){
                source.x = 0;
            }

        }
    }
    frameCounter += stanceSpeed * deltaTime.asSeconds();
    mPlayer.move(movement * deltaTime.asSeconds());
    nPlayer.move(movement * deltaTime.asSeconds());
    oPlayer.move(movement * deltaTime.asSeconds());
    xPlayer.move(movement * deltaTime.asSeconds());
    yPlayer.move(movement * deltaTime.asSeconds());
    zPlayer.move(movement * deltaTime.asSeconds());
}

void Game::render(){
    mWindow.clear();
    mWindow.draw(bBackground);
    mWindow.draw(mPlayer);
    mWindow.draw(nPlayer);
    mWindow.draw(oPlayer);
    mWindow.draw(xPlayer);
    mWindow.draw(yPlayer);
    mWindow.draw(zPlayer);
    mWindow.display();
}

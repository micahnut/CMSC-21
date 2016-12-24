#include <SFML/Graphics.hpp>
#include <iostream>

using namespace std;

class Game{
public:
    Game();
    void run();
private:
    void processEvents();
    void update(sf::Time);
    void render();
    //void handlePlayerInput(sf::Keyboard::Key, bool);
private:
    sf::RenderWindow mWindow;
    sf::Texture mTexture,nTexture,oTexture,bTexture,xTexture,yTexture,zTexture;
    sf::Sprite mPlayer,nPlayer,oPlayer,bBackground,xPlayer,yPlayer,zPlayer;
    sf::Vector2i source;
    bool /*mIsMovingUp, mIsMovingDown, mIsMovingLeft, mIsMovingRight, punch,*/ stance;
    float PlayerSpeed, stanceSpeed;
    float frameCounter, switchFrame;
    //enum directions {UP, RIGHT, DOWN, LEFT};
};

int main(){
    Game game;
    game.run();
}

Game::Game():mWindow(sf::VideoMode(1000, 642), "SFML Application"),mTexture(),mPlayer(),nPlayer(),oPlayer(),source(0,1){
    if (!bTexture.loadFromFile("arena_1.png")){
        cout<<"Error loading file."<<endl;
    }
    bBackground.setTexture(bTexture);

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

    //mIsMovingUp = mIsMovingDown = mIsMovingLeft = mIsMovingRight = false;
    stance = true;
    PlayerSpeed = 100.0;
    frameCounter = 0;
    switchFrame = 100;
    stanceSpeed = 300.0;
}

void Game::run(){
    sf::Clock clock;
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
        /*
        switch(event.type){
            case sf::Event::KeyPressed:
                handlePlayerInput(event.key.code, true);
                break;
            case sf::Event::KeyReleased:
                handlePlayerInput(event.key.code, false);
                break;
            case sf::Event::Closed:
                mWindow.close();
                break;
        }
        */
        if(event.type==sf::Event::Closed)
            mWindow.close();
    }
}
/*
void Game::handlePlayerInput(sf::Keyboard::Key key, bool isPressed){
    if(!isPressed){
        source.x = 0;
        source.y = 1;
    }
    if(key == sf::Keyboard::W)
        mIsMovingUp = isPressed;
    if(key == sf::Keyboard::S)
        mIsMovingDown = isPressed;
    if(key == sf::Keyboard::A){
        mIsMovingLeft = isPressed;
        if(isPressed){
            source.y = 3;
            source.x = 0;
        }
    }
    if(key == sf::Keyboard::D){
        mIsMovingRight = isPressed;
        if(isPressed){
            source.y = 3;
            source.x = 0;
        }
    }
    if(key == sf::Keyboard::P){
        punch = isPressed;
        if(isPressed){
            source.x = 0;
            source.y = 2;
        }
    }
}
*/
void Game::update(sf::Time deltaTime){
    int max;
    sf::Vector2f movement(0.f, 0.f);
    mPlayer.setTextureRect(sf::IntRect(source.x*223,source.y*0,199,250));
    nPlayer.setTextureRect(sf::IntRect(source.x*205,source.y*0,190,219));
    oPlayer.setTextureRect(sf::IntRect(source.x*166,source.y*0,166,220));
    xPlayer.setTextureRect(sf::IntRect(source.x*181,source.y*0,170,250));
    yPlayer.setTextureRect(sf::IntRect(source.x*270,source.y*0,270,350));
    zPlayer.setTextureRect(sf::IntRect(source.x*135,source.y*0,125,268));
    /*
    if(mIsMovingUp)
        movement.y -= PlayerSpeed;
    if(mIsMovingDown)
        movement.y += PlayerSpeed;
    if(mIsMovingLeft)
        movement.x -= PlayerSpeed;
    if(mIsMovingRight){
        movement.x += PlayerSpeed;
    }
    */
    if(stance){
        if(frameCounter >= switchFrame){
            frameCounter = 0;
            source.x++;
            /*
            if(mIsMovingRight)
                max = 4;*/
            //else
                max = 3;
            if(source.x>=max){
                source.x = 0;
            }

        }
    }/*
    if(punch){
        if(frameCounter >= switchFrame){
            frameCounter = 0;
            source.x++;
            if(source.x>=2){
                source.x = 0;
            }
        }
    }*/
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

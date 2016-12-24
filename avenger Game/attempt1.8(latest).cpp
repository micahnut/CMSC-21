#include <SFML/Graphics.hpp>
#include <iostream>
#include <conio.h>
#include <time.h>
#include <sstream>

using namespace std;

class Team{
    private:
        int life;
    public:
        Team();
        int hpMinus(){
            srand((unsigned int)time(NULL));
            life-=rand()%25+1;
            return life;
        }
        int getLife(){return life;}
};

Team::Team(){
    life=300;
}

class Game{
public:
    Game();
    int attackstyle;
    void run();
    int mChoice,nChoice,oChoice,pChoice,qChoice,rChoice,      sChoice,tChoice,uChoice,vChoice,xChoice,yChoice;//para check sa print
    int Choice1,Choice2,Choice3;//para kung kinsa ang napilian
private:
    void processEvents();
    void update(sf::Time);
    void render();
    void menu();
    void help();
    void choose();
    void setcharacterchoice();
    void setenemy();
    void attack();
private:
    sf::RenderWindow mWindow;
    sf::Texture mTexture,nTexture,oTexture,pTexture,qTexture,rTexture,sTexture,tTexture,uTexture,vTexture,xTexture,yTexture,MenuTexture,bTexture,tHelp1,tHelp2,tChoose,tStats,tAttackchoice,tLightning,tFireball;
    sf::Sprite mPlayer,nPlayer,oPlayer,pPlayer,qPlayer,rPlayer,sPlayer,tPlayer,uPlayer,vPlayer,xPlayer,yPlayer,MenuSprite,bBackground,sHelp1,sHelp2,sChoose,sStats,sAttackchoice,sLightning,sFireball;
    sf::Vector2i source;
    sf::Font font;
    sf::Text text1,text2;
    bool stance;
    float PlayerSpeed, stanceSpeed;
    float frameCounter, switchFrame;
    Team team1,team2;
    int playing,flagers;
};

int main(){
    srand((unsigned int)time(NULL));
    Game game;
    game.mChoice=game.nChoice=game.oChoice=game.pChoice=game.qChoice=game.rChoice=game.sChoice=game.tChoice=game.uChoice=game.vChoice=game.xChoice=game.yChoice=0;
    game.run();
}

Game::Game():mWindow(sf::VideoMode(1000, 642), "Avengers"),mTexture(),mPlayer(),nPlayer(),oPlayer(),source(0,1){
    if (!bTexture.loadFromFile("arena_1.png"))
        cout<<"Error loading file."<<endl;
    if (!MenuTexture.loadFromFile("menu.png"))
        cout<<"Error loading file."<<endl;
    if (!tHelp1.loadFromFile("help_1.png"))
        cout<<"Error loading file."<<endl;
    if (!tHelp2.loadFromFile("help_2.png"))
        cout<<"Error loading file."<<endl;
    if (!tChoose.loadFromFile("choose.png"))
        cout<<"Error loading file."<<endl;
    if (!tStats.loadFromFile("stats.png"))
        cout<<"Error loading file."<<endl;
    if (!tAttackchoice.loadFromFile("attackchoice.png"))
        cout<<"Error loading file."<<endl;
    if (!tLightning.loadFromFile("lightning.png"))
        cout<<"Error loading file."<<endl;
    if (!tFireball.loadFromFile("fire.png"))
        cout<<"Error loading file."<<endl;
    bBackground.setTexture(bTexture);
    MenuSprite.setTexture(MenuTexture);
    sHelp1.setTexture(tHelp1);
    sHelp2.setTexture(tHelp2);
    sChoose.setTexture(tChoose);
    sStats.setTexture(tStats);
    sAttackchoice.setTexture(tAttackchoice);
    sLightning.setTexture(tLightning);
    sFireball.setTexture(tFireball);
;    //hero choose
    if (!mTexture.loadFromFile("sprite_01.png"))
        cout<<"Error loading file."<<endl;
    if (!nTexture.loadFromFile("sprite_02.png"))
        cout<<"Error loading file."<<endl;
    if (!oTexture.loadFromFile("sprite_03.png"))
        cout<<"Error loading file."<<endl;
    if (!pTexture.loadFromFile("sprite_04.png"))
        cout<<"Error loading file."<<endl;
    if (!qTexture.loadFromFile("sprite_05.png"))
        cout<<"Error loading file."<<endl;
    if (!rTexture.loadFromFile("sprite_06.png"))
        cout<<"Error loading file."<<endl;
    //enemies
    if (!sTexture.loadFromFile("sprite_07.png"))
        cout<<"Error loading file."<<endl;
    if (!tTexture.loadFromFile("sprite_08.png"))
        cout<<"Error loading file."<<endl;
    if (!uTexture.loadFromFile("sprite_09.png"))
        cout<<"Error loading file."<<endl;
    if (!vTexture.loadFromFile("sprite_10.png"))
        cout<<"Error loading file."<<endl;
    if (!xTexture.loadFromFile("sprite_11.png"))
        cout<<"Error loading file."<<endl;
    if (!yTexture.loadFromFile("sprite_12.png"))
        cout<<"Error loading file."<<endl;

    if(!font.loadFromFile("font/arialbd.ttf.ttf")){
        cout<<"Error loading file."<<endl;
    }
    mPlayer.setTexture(mTexture);
    nPlayer.setTexture(nTexture);
    oPlayer.setTexture(oTexture);
    pPlayer.setTexture(pTexture);
    qPlayer.setTexture(qTexture);
    rPlayer.setTexture(rTexture);
    sPlayer.setTexture(sTexture);
    tPlayer.setTexture(tTexture);
    uPlayer.setTexture(uTexture);
    vPlayer.setTexture(vTexture);
    xPlayer.setTexture(xTexture);
    yPlayer.setTexture(yTexture);

    text1.setFont(font);
    text1.setColor(sf::Color::White);
    text1.setCharacterSize(20);
    text1.setPosition(165,105);

    text2.setFont(font);
    text2.setColor(sf::Color::White);
    text2.setCharacterSize(20);
    text2.setPosition(952,105);

    //set values
    stance = true;
    PlayerSpeed = 100.0;
    frameCounter = 0;
    switchFrame = 100;
    stanceSpeed = 100.0;
    playing = 1;
    attackstyle=0;
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
                    }
            }
        }
    }
}

void Game::run(){
    sf::Clock clock;
    menu();
    setcharacterchoice();
    setenemy();
    while (mWindow.isOpen()){
        sf::Time deltaTime = clock.restart();
        processEvents();
        update(deltaTime);
        render();
    }
}

void Game::setcharacterchoice(){
    int counter=0;
    sf::Event event;
    mWindow.clear();
    mWindow.draw(sChoose);
    mWindow.display();
    while(mWindow.isOpen()){
        while(mWindow.pollEvent(event)){
            switch(event.type){
                case sf::Event::MouseButtonPressed:
                    sf::Vector2i position = sf::Mouse::getPosition(mWindow);
                    if(position.x>=810&&position.y>=410&&position.x<=890&&position.y<=520){
                        if(counter==1)
                            Choice1=1;
                        else if(counter==2)
                            Choice2=1;
                        else
                            Choice3=1;

                        mChoice=1;
                        counter++;
                    }
                    else if(position.x>=480&&position.y>=415&&position.x<=580&&position.y<=600){
                        if(counter==1)
                            Choice1=2;
                        else if(counter==2)
                            Choice2=2;
                        else
                            Choice3=2;

                        nChoice=1;
                        counter++;
                    }
                    else if(position.x>=780&&position.y>=100&&position.x<=940&&position.y<=250){
                        if(counter==1)
                            Choice1=3;
                        else if(counter==2)
                            Choice2=3;
                        else
                            Choice3=3;

                        oChoice=1;
                        counter++;
                    }
                    else if(position.x>=440&&position.y>=160&&position.x<=600&&position.y<=380){
                        if(counter==1)
                            Choice1=4;
                        else if(counter==2)
                            Choice2=4;
                        else
                            Choice3=4;

                        pChoice=1;
                        counter++;
                    }
                    else if(position.x>=120&&position.y>=380&&position.x<=160&&position.y<=550){
                        if(counter==1)
                            Choice1=5;
                        else if(counter==2)
                            Choice2=5;
                        else
                            Choice3=5;

                        qChoice=1;
                        counter++;
                    }
                    else if(position.x>=60&&position.y>=110&&position.x<=230&&position.y<=240){
                        if(counter==1)
                            Choice1=6;
                        else if(counter==2)
                            Choice2=6;
                        else
                            Choice3=6;

                        rChoice=1;
                        counter++;
                    }
                if(counter==3)
                    return;
            }
        }
    }
}

void Game::setenemy(){
    int gen1=0, gen2=0, gen3=0,counter=0;

    gen1=rand()%6+1;
    //cout<<gen1<<endl;
    if(gen1==1)
        sChoice=1;
    else if(gen1==2)
        tChoice=1;
    else if(gen1==3)
        uChoice=1;
    else if(gen1==4)
        vChoice=1;
    else if(gen1==5)
        xChoice=1;
    else if(gen1==6)
        yChoice=1;

    do{
        gen2=rand()%6+1;
    }while(gen1==gen2);

    if(gen2==1)
        sChoice=2;
    else if(gen2==2)
        tChoice=2;
    else if(gen2==3)
        uChoice=2;
    else if(gen2==4)
        vChoice=2;
    else if(gen2==5)
        xChoice=2;
    else if(gen2==6)
        yChoice=2;

    do{
        gen3=rand()%6+1;
    }while(gen1==gen3 || gen2==gen3 );
    if(gen3==1)
        sChoice=3;
    else if(gen3==2)
        tChoice=3;
    else if(gen3==3)
        uChoice=3;
    else if(gen3==4)
        vChoice=3;
    else if(gen3==5)
        xChoice=3;
    else if(gen3==6)
        yChoice=3;

}

void Game::processEvents(){
    sf::Event event;
    mWindow.clear();
    render();
    int hp1,hp2;
    while (mWindow.pollEvent(event)){
       if(playing==1){
            mWindow.clear();
            render();
            mWindow.draw(sAttackchoice);
            mWindow.display();
            //cout<<"stop1"<<endl;
            hp2 = team2.hpMinus();
            //cout<<"hp:stop1 "<<hp2<<endl;
            while(mWindow.isOpen()){
                while(mWindow.pollEvent(event)){
                    switch(event.type){
                        case sf::Event::MouseButtonPressed:
                            sf::Vector2i position = sf::Mouse::getPosition(mWindow);
                            if(position.x>=100&&position.y>=540&&position.x<=310&&position.y<=610){
                                attackstyle=1;
                                flagers=1;
                                return;
                            }
                            if(position.x>=670&&position.y>=540&&position.x<=860&&position.y<=600){
                                cout<<"stop1b"<<endl;
                                attackstyle=2;
                                flagers=1;
                                return;
                            }
                    }
                    playing=2;
                }
            }
       }
       else if(playing==2){
            hp1 = team1.hpMinus();
            playing=1;
            return;
       }
       break;
    }
    return;
}

void Game::update(sf::Time deltaTime){
    int max,counter=1;
    sf::Vector2f movement(0.f, 0.f);
    std::stringstream hp1,hp2;

    hp1<<team1.getLife();
    text1.setString(hp1.str().c_str());
    hp2<<team2.getLife();
    text2.setString(hp2.str().c_str());

    mPlayer.setTextureRect(sf::IntRect(source.x*181,source.y*0,170,250));
    nPlayer.setTextureRect(sf::IntRect(source.x*270,source.y*0,270,350));
    oPlayer.setTextureRect(sf::IntRect(source.x*200,source.y*0,200,210));
    pPlayer.setTextureRect(sf::IntRect(source.x*400,source.y*0,380,350));
    qPlayer.setTextureRect(sf::IntRect(source.x*135,source.y*0,125,268));
    rPlayer.setTextureRect(sf::IntRect(source.x*140,source.y*0,140,250));

    sPlayer.setTextureRect(sf::IntRect(source.x*223,source.y*0,199,250));
    tPlayer.setTextureRect(sf::IntRect(source.x*205,source.y*0,190,219));
    uPlayer.setTextureRect(sf::IntRect(source.x*166,source.y*0,166,220));
    vPlayer.setTextureRect(sf::IntRect(source.x*166,source.y*0,155,220));
    xPlayer.setTextureRect(sf::IntRect(source.x*214,source.y*0,210,220));
    yPlayer.setTextureRect(sf::IntRect(source.x*125,source.y*0,110,220));

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

    sLightning.setTextureRect(sf::IntRect(source.x*205, source.y*0,205,200));
    if(attackstyle==1){
        if(frameCounter >=switchFrame){
                frameCounter=0;
                source.x++;
                max=5;
                if(source.x>=max){
                    source.x = 0;
                }
        }
    }

    sFireball.setTextureRect(sf::IntRect(source.x*0, source.y*18,80,18));
    if(attackstyle==2){
        if(frameCounter >=switchFrame){
                frameCounter=0;
                source.y++;
                max=23;
                if(source.y>=max){
                    source.y = 0;
                }
        }
    }
    //player
    if(1==Choice1)
        mPlayer.setPosition(10.f, 400.f);
    else if(2==Choice1)
        nPlayer.setPosition(10.f, 400.f);
    else if(3==Choice1)
        oPlayer.setPosition(10.f, 400.f);
    else if(4==Choice1)
        pPlayer.setPosition(10.f, 400.f);
    else if(5==Choice1)
        qPlayer.setPosition(10.f, 400.f);
    else if(6==Choice1)
        rPlayer.setPosition(10.f, 400.f);

    if(1==Choice2)
        mPlayer.setPosition(130.f, 200.f);
    else if(2==Choice2)
        nPlayer.setPosition(130.f, 200.f);
    else if(3==Choice2)
        oPlayer.setPosition(130.f, 200.f);
    else if(4==Choice2)
        pPlayer.setPosition(130.f, 200.f);
    else if(5==Choice2)
        qPlayer.setPosition(130.f, 200.f);
    else if(6==Choice2)
        rPlayer.setPosition(130.f, 200.f);

    if(1==Choice3)
        mPlayer.setPosition(230.f, 30.f);
    else if(2==Choice3)
        nPlayer.setPosition(230.f, 30.f);
    else if(3==Choice3)
        oPlayer.setPosition(230.f, 30.f);
    else if(4==Choice3)
        pPlayer.setPosition(230.f, 30.f);
    else if(5==Choice3)
        qPlayer.setPosition(230.f, 30.f);
    else if(6==Choice3)
        rPlayer.setPosition(230.f, 30.f);

    //enemies
    if(sChoice==1)
        sPlayer.setPosition(600.f, 50.f);
    else if(tChoice==1)
        tPlayer.setPosition(600.f, 50.f);
    else if(uChoice==1)
        uPlayer.setPosition(600.f, 50.f);
    else if(vChoice==1)
        vPlayer.setPosition(600.f, 50.f);
    else if(xChoice==1)
        xPlayer.setPosition(600.f, 50.f);
    else if(yChoice==1)
        yPlayer.setPosition(600.f, 50.f);

    if(sChoice==2)
        sPlayer.setPosition(680.f, 240.f);
    else if(tChoice==2)
        tPlayer.setPosition(680.f, 240.f);
    else if(uChoice==2)
        uPlayer.setPosition(680.f, 240.f);
    else if(vChoice==2)
        vPlayer.setPosition(680.f, 240.f);
    else if(xChoice==2)
        xPlayer.setPosition(680.f, 240.f);
    else if(yChoice==2)
        yPlayer.setPosition(680.f, 240.f);

    if(sChoice==3)
        sPlayer.setPosition(800.f, 450.f);
    else if(tChoice==3)
        tPlayer.setPosition(800.f, 450.f);
    else if(uChoice==3)
        uPlayer.setPosition(800.f, 450.f);
    else if(vChoice==3)
        vPlayer.setPosition(800.f, 450.f);
    else if(xChoice==3)
        xPlayer.setPosition(800.f, 450.f);
    else if(yChoice==3)
        yPlayer.setPosition(800.f, 450.f);


    sLightning.setPosition(350.f,200.f);
    //movement
    frameCounter += stanceSpeed * deltaTime.asSeconds();

    if(mChoice)
        mPlayer.move(movement * deltaTime.asSeconds());
    if(nChoice)
        nPlayer.move(movement * deltaTime.asSeconds());
    if(oChoice)
        oPlayer.move(movement * deltaTime.asSeconds());
    if(pChoice)
        pPlayer.move(movement * deltaTime.asSeconds());
    if(qChoice)
        qPlayer.move(movement * deltaTime.asSeconds());
    if(rChoice)
        rPlayer.move(movement * deltaTime.asSeconds());

    if(sChoice)
        sPlayer.move(movement * deltaTime.asSeconds());
    if(tChoice)
        tPlayer.move(movement * deltaTime.asSeconds());
    if(uChoice)
        uPlayer.move(movement * deltaTime.asSeconds());
    if(vChoice)
        vPlayer.move(movement * deltaTime.asSeconds());
    if(xChoice)
        xPlayer.move(movement * deltaTime.asSeconds());
    if(yChoice)
        yPlayer.move(movement * deltaTime.asSeconds());

    sLightning.move(movement * deltaTime.asSeconds());
    sFireball.move(movement * deltaTime.asSeconds());

    cout<<sChoice<<tChoice<<uChoice<<vChoice<<xChoice<<yChoice<<endl;

}

void Game::render(){
    //mWindow.clear();
    mWindow.draw(bBackground);

    if(mChoice)
        mWindow.draw(mPlayer);
    if(nChoice)
        mWindow.draw(nPlayer);
    if(oChoice)
        mWindow.draw(oPlayer);
    if(pChoice)
        mWindow.draw(pPlayer);
    if(qChoice)
        mWindow.draw(qPlayer);
    if(rChoice)
        mWindow.draw(rPlayer);

    if(sChoice)
        mWindow.draw(sPlayer);
    if(tChoice)
        mWindow.draw(tPlayer);
    if(uChoice)
        mWindow.draw(uPlayer);
    if(vChoice)
        mWindow.draw(vPlayer);
    if(xChoice)
        mWindow.draw(xPlayer);
    if(yChoice)
        mWindow.draw(yPlayer);

    if(playing==1 && flagers==1){
        cout<<"hoy"<<endl;
        if(attackstyle==1)
            mWindow.draw(sLightning);
        else if(attackstyle==2)
            mWindow.draw(sFireball);
        flagers=0;
    }

    mWindow.draw(sStats);
    mWindow.draw(text1);
    mWindow.draw(text2);

    mWindow.display();
}

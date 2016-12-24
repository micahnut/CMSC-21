#include <iostream>
#include <string>
#include <ctime>
#include <cstdlib>
#include <conio.h>

using  namespace std;

class Hero{
	private:
		string alias;
		int life;

	public:
		Hero();
		void setHeroStats(int);
		string HeroName();
		int getHealth();
		void showStats();
};

class Villain{
	private:
		string alias;
		int life;

	public:
		Villain();
		void setVillainStats(int);
		string VillainName();
		int getVHealth();
		void showVillainStats();
};

void battle(Hero,Hero,Hero,Villain,Villain,Villain);

 Hero::Hero(){
 	life = 100;
 	alias = "UNKNOWN";
 }

 void Hero::setHeroStats(int n){
			 if(n == 1){
				alias = "EMMA FROST";
				life=100;}

			if(n == 2){
				alias = "SCARLET WITCH";
				life=100;}

			if(n == 3){
				alias = "MEDUSA";
				life=100;}

			if(n == 4){
				alias = "DR. STRANGE";
				life=100;}

			if(n == 5){
				alias = "VISION";
				life=100;}

			if(n == 6){
				alias = "CLOAK";
 				life=100;}
}

 string Hero::HeroName(){
 	return alias;
}

int Hero::getHealth(){
	return life;
}

void Hero::showStats(){
	cout << "Hero Name: "<<alias<<endl;
	cout << "Health: "<<life<<endl;
	cout <<"\n";
}

Villain::Villain(){
 	life = 150;
 	alias = "UNKNOWN";
 }

 void Villain::setVillainStats(int n){
 			if(n == 1){
				alias = "SELENE";
				life=125;}

			if(n == 2){
				alias = "UMAR";
				life=125;}

			if(n == 3){
				alias = "MORGAN LE FAY";
				life=125;}

			if(n == 4){
				alias = "DORMAMMU";
				life=125;}

			if(n == 5){
				alias = "BASTION";
				life=125;}

			if(n == 6){
				alias = "HYDRO-MAN";
				life=125;}
 }

 string Villain::VillainName(){
 	return alias;
}

int Villain::getVHealth(){
	return life;
}

void Villain::showVillainStats(){
	cout << "Villain Name: "<<alias<<endl;
	cout << "Health: "<<life<<endl;
	cout <<"\n";
}

 void battle(Hero h1 ,Hero h2,Hero h3,Villain v1,Villain v2,Villain v3){
 	int rounds=0, choice=0, brawl=0, blast=0, vill=0, hero=0, evasion=0, vchoose=0, vchoice=0;

	int h1Life = h1.getHealth();
	int h2Life = h2.getHealth();
	int h3Life = h3.getHealth();
	int v1Life = v1.getVHealth();
	int v2Life = v2.getVHealth();
	int v3Life = v3.getVHealth();

	srand((unsigned int)time(NULL));

	do{
        if(h1Life <= 0 && h2Life <= 0 && h3Life <= 0)
                break;

	    cout << "\nCHOOSE THE HERO YOU WANT TO ATTACK: 1 - " << h1.HeroName() << " 2 - " << h2.HeroName() << " 3 - " << h3.HeroName() << endl;
        do{
            cin >> hero;
            if (hero < 1 || hero > 3)
                cout << "\nNOT ON THE MENU! CHOOSE AGAIN: \t";
            else if ((hero == 1 && h1Life <= 0) || (hero == 2 && h2Life <= 0) || (hero == 3 && h3Life <= 0))
				cout << "\nHERO ALREADY DOWN.";
        }while ((hero < 1 || hero > 3) || (hero == 1 && h1Life <= 0) || (hero == 2 && h2Life <= 0) || (hero == 3 && h3Life <= 0));

	    cout << "\nCHOOSE THE VILLAIN YOU WANT TO HIT: \t1 - " << v1.VillainName() << " 2 - " << v2.VillainName() << " 3 - " << v3.VillainName() << endl;
        do{
            cin >> vill;
            if (vill < 1 || vill > 3)
                cout << "\nNOT ON THE MENU! CHOOSE AGAIN: \t";
            else if ((vill == 1 && v1Life <= 0) || (vill == 2 && v2Life <= 0) || (vill == 3 && v3Life <= 0))
				cout << "\nVILLAIN ALREADY DOWN.";
        }while ((vill < 1 || vill > 3) || (vill == 1 && v1Life <= 0) || (vill == 2 && v2Life <= 0) || (vill == 3 && v3Life <= 0));

        cout << "\nCHOOSE YOUR ATTACK: 1 - Range Attack     2 - Physical Attack" << endl;

        do{
            cin >> choice;
            if (choice < 1 || choice > 3)
                cout << "\nNOT ON THE MENU! CHOOSE AGAIN: \t";
        }while (choice < 1 || choice > 2);

        if (vill == 1 && v1Life > 0){
            //YOUR TURN
            if (choice == 1){
                blast = rand()%21+5;
                evasion = rand()%5+1;

                if(evasion == 1)
                    cout << v1.VillainName() << " EVADED!" << endl;
                else{
                    v1Life -= blast;
                }
            }

            else{
                brawl = rand()%16+5;
                evasion = rand()%5+1;

                if(evasion == 1)
                    cout << v1.VillainName() << " EVADED!" << endl;
                else{
                    v1Life -= brawl;
                }
            }
            if (evasion != 1 && choice == 1)
                cout << "DAMAGE DONE: " << blast << endl;
            else if  (evasion != 1 && choice == 2)
                cout << "DAMAGE DONE: " << brawl << endl;
           cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~";
            cout << "\n" << h1.HeroName() << "'S HEALTH: " << h1Life << endl;
            cout << h2.HeroName() << "'S HEALTH: " << h2Life << endl;
            cout << h3.HeroName() << "'S HEALTH: " << h3Life << endl;
            cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
			cout << v1.VillainName() << "'S HEALTH: " << v1Life << endl;
			cout << v2.VillainName() << "'S HEALTH: " << v2Life << endl;
			cout << v3.VillainName() << "'S HEALTH: " << v3Life << endl;
			cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
        }

        else if (vill == 2 && v2Life > 0){
            if (choice == 1){
                blast = rand()%21+5;
                evasion = rand()%5+1;

                if(evasion == 1)
                    cout << v2.VillainName() << " EVADED!" << endl;
                else{
                    v2Life -= blast;
                }
            }

            else{
                brawl = rand()%16+5;
                evasion = rand()%5+1;

                if(evasion == 1)
                    cout << v2.VillainName() << " EVADED!" << endl;
                else{
                    v2Life -= brawl;
                }
            }
            if (evasion != 1 && choice == 1)
                cout << "DAMAGE DONE: " << blast << endl;
            else if  (evasion != 1 && choice == 2)
                cout << "DAMAGE DONE: " << brawl << endl;
           cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~";
            cout << "\n" << h1.HeroName() << "'S HEALTH: " << h1Life << endl;
            cout << h2.HeroName() << "'S HEALTH: " << h2Life << endl;
            cout << h3.HeroName() << "'S HEALTH: " << h3Life << endl;
            cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
			cout << v1.VillainName() << "'S HEALTH: " << v1Life << endl;
			cout << v2.VillainName() << "'S HEALTH: " << v2Life << endl;
			cout << v3.VillainName() << "'S HEALTH: " << v3Life << endl;
			cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
        }

        else if (vill == 3 && v3Life > 0){
            if (choice == 1){
                blast = rand()%21+5;
                evasion = rand()%5+1;

                if(evasion == 1)
                    cout << v3.VillainName() << " EVADED!" << endl;
                else{
                    v3Life -= blast;
                }
            }

            else{
                brawl = rand()%16+5;
                evasion = rand()%5+1;

                if(evasion == 1)
                    cout << v1.VillainName() << " EVADED!" << endl;
                else{
                    v3Life -= brawl;
                }
            }
            if (evasion != 1 && choice == 1)
                cout << "DAMAGE DONE: " << blast << endl;
            else if  (evasion != 1 && choice == 2)
                cout << "DAMAGE DONE: " << brawl << endl;
           cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~";
            cout << "\n" << h1.HeroName() << "'S HEALTH: " << h1Life << endl;
            cout << h2.HeroName() << "'S HEALTH: " << h2Life << endl;
            cout << h3.HeroName() << "'S HEALTH: " << h3Life << endl;
            cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
			cout << v1.VillainName() << "'S HEALTH: " << v1Life << endl;
			cout << v2.VillainName() << "'S HEALTH: " << v2Life << endl;
			cout << v3.VillainName() << "'S HEALTH: " << v3Life << endl;
			cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
        }

        if(v1Life <= 0 && v2Life <= 0 && v3Life <= 0)
            break;
        do{
            vchoose = rand()%3+1;
        }while((vchoose == 1 && h1Life <= 0) || (vchoose == 2 && h2Life <= 0) || (vchoose == 3 && h3Life <= 0));
        vchoice = rand()%2+1;

        if(vchoose == 1 && h1Life > 0){
            if (vchoice == 1){
                blast = rand()%21+5;
                evasion = rand()%4+1;

                if(evasion == 1)
                    cout << h1.HeroName() << " EVADED!" << endl;
                else{
                    h1Life -= blast;
                }
            }

            else{
                brawl = rand()%16+5;
                evasion = rand()%4+1;

                if(evasion == 1)
                    cout << h1.HeroName() << " EVADED!" << endl;
                else{
                    h1Life -= brawl;
                }
            }
            if (evasion != 1 && vchoice == 1)
                cout << "DAMAGE DONE: " << blast << endl;
            else if  (evasion != 1 && vchoice == 2)
                cout << "DAMAGE DONE: " << brawl << endl;
           cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~";
            cout << "\n" << h1.HeroName() << "'S HEALTH: " << h1Life << endl;
            cout << h2.HeroName() << "'S HEALTH: " << h2Life << endl;
            cout << h3.HeroName() << "'S HEALTH: " << h3Life << endl;
            cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
			cout << v1.VillainName() << "'S HEALTH: " << v1Life << endl;
			cout << v2.VillainName() << "'S HEALTH: " << v2Life << endl;
			cout << v3.VillainName() << "'S HEALTH: " << v3Life << endl;
			cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
        }

        else if(vchoose == 2 && h2Life > 0){
            if (vchoice == 1){
                blast = rand()%21+5;
                evasion = rand()%4+1;

                if(evasion == 1)
                    cout << h2.HeroName() << " EVADED!" << endl;
                else{
                    h2Life -= blast;
                }
            }

            else{
                brawl = rand()%16+5;
                evasion = rand()%4+1;

                if(evasion == 1)
                    cout << h2.HeroName() << " EVADED!" << endl;
                else{
                    h2Life -= brawl;
                }
            }
            if (evasion != 1 && vchoice == 1)
                cout << "DAMAGE DONE: " << blast << endl;
            else if  (evasion != 1 && vchoice == 2)
                cout << "DAMAGE DONE: " << brawl << endl;
           cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~";
            cout << "\n" << h1.HeroName() << "'S HEALTH: " << h1Life << endl;
            cout << h2.HeroName() << "'S HEALTH: " << h2Life << endl;
            cout << h3.HeroName() << "'S HEALTH: " << h3Life << endl;
            cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;;
			cout << v1.VillainName() << "'S HEALTH: " << v1Life << endl;
			cout << v2.VillainName() << "'S HEALTH: " << v2Life << endl;
			cout << v3.VillainName() << "'S HEALTH: " << v3Life << endl;
			cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
        }

        else if(vchoose == 3 && h3Life > 0){
            if (vchoice == 1){
                blast = rand()%21+5;
                evasion = rand()%4+1;

                if(evasion == 1)
                    cout << h3.HeroName() << " EVADED!" << endl;
                else{
                    h3Life -= blast;
                }
            }

            else{
                brawl = rand()%16+5;
                evasion = rand()%4+1;

                if(evasion == 1)
                    cout << h3.HeroName() << " EVADED!" << endl;
                else{
                    h3Life -= brawl;
                }
            }
            if (evasion != 1 && vchoice == 1)
                cout << "DAMAGE DONE: " << blast << endl;
            else if  (evasion != 1 && vchoice == 2)
                cout << "DAMAGE DONE: " << brawl << endl;
            cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~";
            cout << "\n" << h1.HeroName() << "'S HEALTH: " << h1Life << endl;
            cout << h2.HeroName() << "'S HEALTH: " << h2Life << endl;
            cout << h3.HeroName() << "'S HEALTH: " << h3Life << endl;
            cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
			cout << v1.VillainName() << "'S HEALTH: " << v1Life << endl;
			cout << v2.VillainName() << "'S HEALTH: " << v2Life << endl;
			cout << v3.VillainName() << "'S HEALTH: " << v3Life << endl;
			cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
        }
    }while((h1Life > 0 || h2Life > 0 || h3Life > 0) && (v1Life > 0 || v2Life > 0 || v3Life > 0));

	if(h1Life > 0 || h2Life > 0 || h3Life > 0)
		cout << "\n" << h1.HeroName() << ", " << h2.HeroName() << " AND " << h3.HeroName() << " ARE TRIUMPHANT." << endl;
	else
		cout << "\n" << h1.HeroName() << ", " << h2.HeroName() << " AND " << h3.HeroName() << " ARE DOWN." << endl;
}

int main(){
	int mainchoice;
	int v1 = 0, v2 = 0, v3 = 0, winner = 1;
	int rounds=0, choice=0, brawl=0, blast=0, villdodge=0, herododge=0, vchance=0, wins=0;

	srand((unsigned int)time(NULL));

	do{
        cout << "\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n\t\tAVENGERS ALLIANCE\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
        cout << " 1 - START \n 2 - HELP \n 3 - EXIT" << endl;

        do{
            cin >> mainchoice;
            if (mainchoice < 1 || mainchoice >> 3)
                cout << "WARNING: NOT ON THE MENU\n";
        }while(mainchoice < 1 || mainchoice > 3);

        if(mainchoice==1){
            int h1 = 0, h2 = 0, h3 = 0, winner;
            cout << "\n CHOOSE YOUR HEROES:\n 1 - EMMA FROST\n 2 - SCARLET WITCH\n 3 - MEDUSA\n 4 - DR. STRANGE\n 5 - VISION\n 6 - CLOAK\n" << endl;

            do{
                while ((h1 <= 0 || h1 >= 7) && h2 ==0 && h3 == 0){
                    cout<<"WHO IS YOUR 1ST HERO?\n";
                    cin >> h1;
                    if(h1 < 1 || h1 > 6)
                        cout << "WARNING: NOT ON THE MENU\n";
                }

                while ((h1 != 0 && (h2 <= 0 || h2 >= 7) && h3 == 0) || h1 == h2){
                    cout<<"WHO IS YOUR 2ND HERO?\n";
                    cin >> h2;
                    if(h2 < 1 || h2 > 6)
                        cout << "\nWARNING: NOT ON THE MENU\n";
                    else if(h2 == h1)
                        cout << "\nALREADY PART OF YOUR TEAM\n";
                }

                while ((h1 != 0 && h2 !=0 && (h3 <= 0 || h3 >= 7)) || h1 == h3 || h2 == h3){
                    cout<<"WHO IS YOUR 3RD HERO?\n";
                    cin >> h3;
                    if(h3 < 1 || h3 > 6)
                        cout << "\nWARNING: NOT ON THE MENU\n";
                    else if(h2 == h3 || h3 == h1)
                        cout << "\nALREADY PART OF YOUR TEAM\n";
                }
            } while (h1 == 0 && h2 == 0 && h3 == 0);

            Hero hero1;
            Hero hero2;
            Hero hero3;

            v1 = rand()%6+1;

            do{
                v2 = rand()%6+1;
            }while(v2 == v1);

            do{
                v3 = rand()%6+1;
            }while(v3 == v1 || v3 == v2);

            Villain villain1;
            Villain villain2;
            Villain villain3;

            hero1.setHeroStats(h1);
            hero2.setHeroStats(h2);
            hero3.setHeroStats(h3);

            villain1.setVillainStats(v1);
            villain2.setVillainStats(v2);
            villain3.setVillainStats(v3);

            hero1.showStats();
            hero2.showStats();
            hero3.showStats();

            villain1.showVillainStats();
            villain2.showVillainStats();
            villain3.showVillainStats();

            battle(hero1,hero2,hero3,villain1,villain2,villain3); //FIGHT FUNCTION;
            getch();
        }

        else if(mainchoice==2){
                //HELP
                cout << "yeah \n";
                getch();
        }

        else if(mainchoice==3){
                cout << "\nSHUTTING DOWN DEFENDERS...\n" << endl;
         }
	}while(mainchoice!=3);

	return 0;
}

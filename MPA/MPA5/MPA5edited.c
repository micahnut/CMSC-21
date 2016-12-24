//I declare, upon my honor, that I made this MP by myself and Hanika.
#include <stdio.h>
#include <time.h>
#include <stdlib.h>

typedef struct {
	int weapon,hp,mana,shield;
	
}bantugan;

void weapon(bantugan *);
void shield(bantugan *);
void mirror(int);

int main(){
	int choice1=1,choice2=1,attack,UseShield,damage=0,counterD=0,mirror1=0,mirror2=0,flag1=0;
	bantugan p1,p2;
	
	srand((unsigned int)time(NULL)); 
	
	p1.hp=10;
	p2.hp=10;
	p1.mana=10;
	p2.mana=10;
	p1.weapon=rand()%3+1;
	p2.weapon=rand()%3+1;
	p1.shield=rand()%3+1;
	p2.shield=rand()%3+1;
	
	do{
		printf("\n Player 1");
        
        printf("\n Health : %d \t Manna: %d \n",p1.hp,p1.mana);
        weapon(p1.weapon); //displays the weapon of Player 1
        shield(p1.shield); //displays the kind of shield of Player 1

        if(p1.mana>=6)
            printf(" Kiss of the Jade Palapa: Available\n");
        else
            printf(" Kiss of the Jade Palapa: Not Available\n");
        //The Kiss of the Jade Palapa can only be available if the player has 6 or more unit points of manna.

        if(mirror2!=1 && mirror1!=1){
            mirror1=rand()%20+1;
        } //randomly generate the Bai-a-Labi's Blink, with 1/20 probability
		    mirror(mirror1); //displays whether the Bai-a-Labi's Blink is available for Player 1 to use or not
        
        printf("\n Player 2");


        printf("\n Health : %i \t Manna: %i \n",p2.hp,p2.mana);
        weapon(p2.weapon); //displays the weapon of Player 2
        shield(p2.weapon); //displays the kind of shield of Player 2

        if(p2.mana>=6)
            printf(" Kiss of the Jade Palapa: Available\n");
        else
            printf(" Kiss of the Jade Palapa: Not Available\n");
        //The Kiss of the Jade Palapa can only be available if the player has 6 or more unit points of manna.

        if(mirror1!=1 && mirror2!=1){
            mirror2=rand()%20+1;
        } //randomly generate the Bai-a-Labi's Blink, with 1/20 probability
        	mirror(mirror2); //displays whether the Bai-a-Labi's Blink is available for Player 2 to use or not
	
		printf("\n Player 1's turn\n \tChoose your offense.\n\t1.Melee Attack\n\t2.Kiss of the Jade Palapa\n");
        
        if(p1.mana<6){
            do{
                printf("\n You have no manna left. You can only use Melee Attack. Press 1.\n");
                scanf("%d", &attack);
            }while(attack!=1);
              }
        else{
            do{
                printf("\n Melee Attack or Kiss of the Jade Palapa? Press 1 or 2.\n");
                scanf("%d",&attack);           
            }while(attack!=1 && attack!=2);
        }//If Player 1 has less than 6 manna points, he/she can only use Melee Attack.

        if(attack==1){
            printf("\n Player 1 has chosen Melee Attack!\n");
            UseShield = rand()% 3 + 1; //randomly generates whether the other player could use the shield, with 1/3 probability

            if(UseShield==1){
                printf(" Wrong Timing! Player 2 used his shield\n");
                if(p2.shield == p1.weapon){
                    damage = 0;
                    counterD=0;
                }//If the weapon used by Player 1 is of the same kind as the shield used by Player 2, no damage is done.
                else if(p2.shield > p1.weapon){
                    damage =0;
                    counterD = p1.weapon;
                }
                else if(p1.weapon - p2.shield == 1){
                    damage= p1.weapon - 1;
                    counterD = 0;
                }  
                else{
                    damage = p1.weapon;
                    counterD =0;
                }    
            }    
            else{
                printf(" Right Timing! No defense was used by Player 2.\n");
                damage = p1.weapon;
                counterD=0;
            }//Damage is at its maximum if Player 2 uses no shield.
        }
        else if(attack==2){
            printf("\n Player 1 has chosen Kiss of the Jade Palapa.\n");
            p1.mana -=6;

            if(mirror2==1){
                printf(" Player 2 repelled Player 1's spell using Bai-a-Labi's Blink!\n");
                damage=0;
                counterD=0;
                mirror2=0;                
            }//The spell can only be repelled if Player 2 has the Bai-a-Labi's Blink.
            else{
                printf(" Player 2 was not able to repel Player 1's spell\n ");
                damage=4;
                counterD=0;
            }
        }
        p1.hp -= counterD;
        p2.hp -= damage;	
        
        
        printf("\n Player 2's turn\n \tChoose your offense.\n\t1.Melee Attack\n\t2.Kiss of the Jade Palapa\n");
        attack=0;
        if(p2.mana<6){
            do{
                printf("\n You have no manna left. You can only use Melee Attack. Press 1.\n");
                scanf("%d", &attack);
            }while(attack!=1);
        }
        else{
            do{
                printf("\n Melee Attack or Kiss of the Jade Palapa? Press 1 or 2.\n");
                scanf("%d",&attack);           
            }while(attack!=1 && attack!=2);
        }//If Player 2 has less than 6 manna points, he/she can only use Melee Attack.

        if(attack==1){
            printf("\n Player 2 has chosen Melee Attack!\n");
            UseShield = rand()% 3 + 1; //randomly generates whether the other player could use the shield, with 1/3 probability

            if(UseShield==1){
                printf(" Wrong Timing! Player 1 used his sheild\n");
                if(p1.shield == p2.weapon){
                    damage = 0;
                    counterD=0;
                }//If the weapon used by Player 2 is of the same kind as the shield used by Player 1, no damage is done.
                else if(p1.shield > p2.weapon){
                    damage =0;
                    counterD = p2.weapon;
                } 
                else if(p2.weapon - p1.shield == 1){
                    damage = p2.weapon - 1;
                    counterD = 0;
                }  
                else{
                    damage = p2.weapon;
                    counterD = 0;
                }    
            }    
            else{
                printf(" Right Timing! No defense was used by Player 1.\n");
                damage = p2.weapon;
                counterD =0;
            }//Damage is at its maximum if Player 1 uses no shield.
         }
         else if(attack==2){
            printf("\n Player 2 has chosen Kiss of the Jade Palapa\n");
            p2.mana -=6;

            if(mirror1==1){
                printf(" Player 1 repelled Player 2's spell using Bai-a-Labi's Blink!\n");
                damage=0;
                counterD=0;
                mirror1=0;                
            }//The spell can only be repelled if Player 1 has the Bai-a-Labi's Blink.
            else{
                printf(" Player 1 was not able to repel Player 2's spell\n ");
                damage=4;
                counterD=0;
            }

        }
        p1.hp-=damage;
        p2.hp-=counterD;

        p1.mana += 2;
            if(p1.mana>10)
                p1.mana=10;

        p2.mana += 2;
            if(p2.mana>10)
                p2.mana=10;
	}while(p1.hp>0 && p2.hp>0);
	
	return 0;
}



void weapon(bantugan *weapon){
    if(weapon==1)
        printf(" Weapon : Wooden Spear\n");
    else if(weapon==2)
        printf(" Weapon : Silver Axe\n");
    else
        printf(" Weapon : Diamond Scythe\n");
}

void shield(bantugan *shield){ 
    if(shield==1)
        printf(" Shield : Wooden Shield\n");
    else if(shield==2)
        printf(" Shield : Silver Shield\n");
    else
        printf(" Shield : Diamond Shield\n");
}

void mirror(int mirror){
    
    if(mirror==1)
        printf(" Bai-a-Labi's Blink: Available\n");
       
    else
        printf(" Bai-a-Labi's Blink: Not Available\n");
}

#include <iostream>
#include <string>
#include <chrono>

class Sel {
    public:
    class clssSel {
        public:
            int SelfspdAdd;
            int SelfdmgAdd;
            int SelfpwrAdd;
            class tactician{
                public:
                    int spdAdd=1;
                    int dmgAdd=2;
                    int pwrAdd=3;
            };
            class assassin {
                public:
                    int spdAdd=4;
                    int dmgAdd=5;
                    int pwrAdd=6;
            };
            class frdmFgter {
                public:
                    int spdAdd=7;
                    int dmgAdd=8;
                    int pwrAdd=9;

            };

            void askForClass() {
                std::string clss;
                std::cout <<"Enter class";
                srand(time(NULL));

                int RC = (rand() % 3) + 1;
                if (RC == 1) {
                    clss = "tactician";
                }
                else if (RC == 2){
                    clss = "assassin";
                }
                else if (RC == 3){
                    clss = "frdmFgter";
                }

                if (clss == "tactician"){
                    tactician valuet;
                        SelfspdAdd = valuet.spdAdd;
                        SelfpwrAdd = valuet.pwrAdd;
                        SelfdmgAdd= valuet.dmgAdd;
                }
                else if (clss == "assassin"){
                    assassin valuea;
                        SelfspdAdd = valuea.spdAdd;
                        SelfpwrAdd = valuea.pwrAdd;
                        SelfdmgAdd= valuea.dmgAdd;
                        assassin self;
                        std::cout << self.spdAdd;
                        std::cout << self.dmgAdd;
                        std::cout << self.pwrAdd;
                }
                else if (clss == "frdmFgter"){
                    frdmFgter valuef;
                        SelfspdAdd = valuef.spdAdd;
                        SelfpwrAdd = valuef.pwrAdd;
                        SelfdmgAdd= valuef.dmgAdd;
                }

        }

    };
    class weaponSel{
    public:
            int SelfSpd;
            int SelfPwr;
            int SelfDmg;
            class sword{
            	public:
					int spd=1;
					int pwr=2;
					int dmg=3;

            };
            class knife{
            	public:
					int spd=4;
					int pwr=5;
					int dmg=6;
            };
            class axe{
            	public:
					int spd=7;
					int pwr=8;
					int dmg=9;

            };
            void askForWeapon(){
                int dice;
                std::string wpn;
                srand(time(NULL));
                dice = (rand() % 3) + 1;
                if (dice == 1){
                    wpn = "sword";
                }
                else if (dice == 2){
                    wpn = "knife";
                }
                else if (dice == 3){
                    wpn = "axe";
                }
                ///start of wpn data collection
                if (wpn == "sword"){
                    sword values;
                        SelfSpd = values.spd;
                        SelfDmg = values.dmg;
                        SelfPwr = values.pwr;

                }
                if (wpn == "knife"){
                    knife valuek;
                        SelfSpd = valuek.spd;
                        SelfDmg = valuek.dmg;
                        SelfPwr = valuek.pwr;
                }
                if (wpn == "sword"){
                    sword values;
                        SelfSpd = values.spd;
                        SelfDmg = values.dmg;
                        SelfPwr = values.pwr;
                }
            }

    };
    void fullSel(){
    	weaponSel wpn;
			wpn.askForWeapon();
    	clssSel cls;
			cls.askForClass();
    }

};


int main(){
    // This test checks to see if a class will be chosen automatically based on a roll or not.
    // should be configurable in game I GUESS?????
    Sel pc;
    	pc.fullSel();
    Sel c1;
        c1.fullSel();
}
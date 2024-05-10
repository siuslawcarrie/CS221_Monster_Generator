#include <iostream>
#include <ctime>
#include <random>
#include <iomanip>

using namespace std;

const int RAND_MIN = 1;//random number minimum
const int WIDTH = 20;//width for setw display

//FUNCTION PROTOTYPE
int random(int low, int high);//random number generator

//PROGRAM
int main() {
    //VARIABLES
    int num_monsters = 0, health = 0, magic = 0, attack = 0, defense = 0;//number of monsters, monster's health, magic, attack, defense max random
    int rand_health = 0, rand_magic = 0, rand_attack = 0, rand_defense = 0;//variables for random numbers
    string monster_name = " ";//monster name
//DISPLAY
    cout <<"Welcome to the Monster Generator! Please enter a monster type: "<<endl;
    getline(cin, monster_name);// user to enter monster name/type
    cout<<"How many "<<monster_name<<"s do you want to generate? ";//ask user for number of monsters
    cin>>num_monsters;//number of monsters
    cout<<"Now enter a value for each of these: monster health, monster magic power, ";//display
    cout<<"monster attack power, monster defense power (4 integers): "<<endl;
    cin>>health >> magic >>attack>>defense;//user entry, max random
    cout << "You entered monster health: "<<health<<", monster magic power: "<<magic<<", monster attack power: "<<attack<<", monster defense power: "<<defense<<endl;
    /***FOR TESTING****/
//    monster_name ="My Monster";
//    num_monsters = 5;
//    health = 13;
//    magic = 14;
//    attack = 8;
//    defense = 5;

    srand(time(NULL));


    cout <<left<<setw(WIDTH) <<monster_name << setw(WIDTH) << "Health" << setw(WIDTH) <<"Magic" << setw(WIDTH) <<"Attack"<< setw(WIDTH)<<"Defense"<<endl;
    for(int x = 1; x <=num_monsters; x++) {
        rand_health = random(RAND_MIN, health);
        rand_magic = random(RAND_MIN, magic);
        rand_attack = random(RAND_MIN, attack);
        rand_defense = random(RAND_MIN, defense);
            cout<<left <<setw(WIDTH) <<x << setw(WIDTH)<< rand_health << setw(WIDTH)<< rand_magic << setw(WIDTH) << rand_attack << setw(WIDTH) << rand_defense <<  endl;

    }

    return 0;
}

int random(int low, int high) {
    return low + rand() % (high - low + 1);
}
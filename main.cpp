/* Carrie Bailey
 * CS 221 Spring 2024
 *Week 4, Exercise #6
 * Description: Write a random monster generator (see Random Numbers for information about how to generate random numbers). First, ask the user to enter the maximum values they want for health points, magic points, attack power, and defense. Next, ask the user to enter the type of monster (such as Goblin, Troll, Orc, etc.) and how many of that type to generate. Your program should generate random values between 1 and the user's selected max for each stat.*/

#include <iostream>
#include <ctime>
#include <random>
#include <iomanip>
#include <cctype>
#include <cstdio>
#include <algorithm>
#include <string>

using namespace std;

//constants
const int RAND_MIN = 1;//random number minimum
const int WIDTH = 20;//width for setw display

//FUNCTION PROTOTYPES
int random(int low, int high);//random number generator
bool isString(const string s);//string validation
int validation_integer(int min, int max);
int monster_number();//get and validate number of monsters
int value();
string validation_string();

//PROGRAM
int main() {
    //VARIABLES
    int num_monsters = 0, health = 0, magic = 0, attack = 0, defense = 0;//number of monsters, monster's health, magic, attack, defense max random
    int rand_health = 0, rand_magic = 0, rand_attack = 0, rand_defense = 0;//variables for random numbers
    string monster_name, monster_type = " ";//monster name
//DISPLAY
    cout << "Welcome to the Monster Generator! Please enter a monster type: " << endl;
    monster_name = validation_string();
    num_monsters = monster_number();//validate monster number
    cout << "Please enter a max power for health: "<<endl;
    cin>>health;
    cout<<"and magic: "<<endl;
    cin>>magic;
    cout<<"now max attack: "<<endl;
    cin>>attack;
    cout<<"and max defense: ";
    cin>>defense;
    cout << "You entered monster health: " << health << ", monster magic power: " << magic << ", monster attack power: "
         << attack << ", monster defense power: " << defense << endl;
    /***FOR TESTING****/
//    monster_name ="My Monster";
//    num_monsters = 5;
//    health = 13;
//    magic = 14;
//    attack = 8;
//    defense = 5;

    srand(time(NULL));//seed random number

//display headers
    cout << left << setw(WIDTH) << monster_name << setw(WIDTH) << "Health" << setw(WIDTH) << "Magic" << setw(WIDTH)
         << "Attack" << setw(WIDTH) << "Defense" << endl;
    //display columns
    for (int x = 1; x <= num_monsters; x++) {
        rand_health = random(RAND_MIN, health);
        rand_magic = random(RAND_MIN, magic);
        rand_attack = random(RAND_MIN, attack);
        rand_defense = random(RAND_MIN, defense);
        cout << left << setw(WIDTH) << x << setw(WIDTH) << rand_health << setw(WIDTH) << rand_magic << setw(WIDTH)
             << rand_attack << setw(WIDTH) << rand_defense << endl;

    }

    return 0;
}


//function to get and validate # of monsters
int monster_number() {
    cout << "How many monsters do you want to generate? ";//ask user for number of monsters
    int min = 1, max = 9999;
    return validation_integer(min, max);
}
//    //function to get and validate magic, health, attack, defense max
//    int emp_id_func() {
//        cout << "Enter employee's ID:";
//        int min = 1, max = 9999;
//        return validation_integer(min, max);

//int value(){
//    for (int x = 1; x<=4; x++){
//        int value;
//        int min = 1, max = 9999;
//        int count = 1;
//        cout<<"Enter value "<<count<<":";
//        cin>>value;
//        count ++;
//
//    return validation_integer(min, max);
//}
    //function to validate integers
    int validation_integer(int min, int max) {
        int number;
        cin >> number;
        while (!cin or (number < min) or (number > max)) {
// Explain error not entering an integer
            cout << "I'm sorry that's not a valid entry. Please enter a number between " << min << " and " << max
                 << ": ";
// Clear input stream
            cin.clear();
// Discard previous input
            cin.ignore(123, '\n');
            cin >> number;
            cout << endl;
        }
        return number;
    }

string validation_string() {
    string entered_string;
bool valid = false;//valid labeling this as not correct
    while (!valid){//valid now true
        bool is_alpha = true;
        cin >> entered_string;
        int i=0;
        while (is_alpha and i<entered_string.length()){

            is_alpha = isalpha(entered_string [i]);
           i++;
        }
        if (!cin or !is_alpha){
            cout<<"Sorry, that is not a valid entry. Please try again: "<<endl;
            cin.clear();
// Discard previous input
            cin.ignore(123, '\n');
            cout << endl;
        }
        else{
            valid = true;
        }
    }
return entered_string;
    /* isalpha example */

//    int main ()
//    {
//        int i=0;
//        char str[]="C++";
//        while (str[i])
//        {
//            if (isalpha(str[i])) printf ("character %c is alphabetic\n",str[i]);
//            else printf ("character %c is not alphabetic\n",str[i]);
//            i++;
//        }
//        return 0;
//    }

    while (!cin) {
        bool contains_non_alpha
                = find_if(entered_string.begin(), entered_string.end(),
                               [](char c) { return !std::isalpha(c); }) != entered_string.end();

// Explain error not entering an integer
        cout << "I'm sorry that's not a valid entry. Please try again. "<<endl;
// Clear input stream
        cin.clear();
// Discard previous input
        cin.ignore(123, '\n');
        cin >> entered_string;
        cout << endl;
    }
    return entered_string;
}

//function to validate monster name
//    string validation_string(string passed_string) //function to validate integers
//    {
//        string entered_string;
//        isString;
//        cin >> entered_string;
////    isString(entered_string);
//        if (!isString) {
//// Explain error not entering a string
//            cout << "I'm sorry that's not a valid entry. Please try again. ";
//// Clear input stream
//            cin.clear();
//// Discard previous input
//            cin.ignore(123, '\n');
//            cin >> entered_string;
//            cout << endl;
//        }
//        return passed_string;
//    }
//
//    //validate string
//    bool isString(const string s) {
//        for (const char c: s) {
//            if (!isalpha(c) and !isspace(c)) {
//                return false;
//            }
//        }
//    }
        //generate random numbers
        int random(int low, int high) {
            return low + rand() % (high - low + 1);
        }






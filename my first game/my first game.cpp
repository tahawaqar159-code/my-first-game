#include <iostream>
using namespace std;

void herostats(int damage , int health , int speed , string name )
{
	cout << " my character stats are :" << endl;
	cout << " name : "<< name << endl;
	cout << " damage : " << damage << endl;
	cout << " health : " << health << endl;
	cout << " speed : " << speed << endl;
	cout << endl;
}
void enemystats (int damage, int health, int speed, string name)
{
	cout << " my character stats are :" << endl;
	cout << " name : " << name << endl;
	cout << " damage : " << damage << endl;
	cout << " health : " << health << endl;
	cout << " speed : " << speed << endl;
	cout << endl;
}
int main()
{
	herostats(50, 100, 30, "Hero");
	enemystats(70, 80, 40, "Villain");
	return 0;
}

#include <iostream>
#include <string>
#include <cstdlib>

using namespace std;

struct seat {
    string name;
    string lName;
    int seatNum;
    int destination;
    bool window;
    seat* prev;
    seat* next;
};

int main(){

struct seat* ptrSeat = (struct seat*)malloc(sizeof(struct seat));

	/*struct Seat* newNode
		= (struct Seat*)malloc(sizeof(struct Seat));*/

return 0;
}

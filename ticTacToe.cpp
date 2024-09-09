#include<bits/stdc++.h>
using namespace std; 
#define max(a, b) (a < b ? b : a) 
#define min(a, b) ((a > b) ? b : a) 
#define mod 1e9 + 7 
#define FOR(a, c) for (int(a) = 0; (a) < (c); (a)++) 
#define FORL(a, b, c) for (int(a) = (b); (a) <= (c); (a)++) 
#define FORR(a, b, c) for (int(a) = (b); (a) >= (c); (a)--) 
#define INF 1000000000000000003 
typedef long long  ll; 
typedef vector<int> vi; 
typedef pair<int, int> pi; 
#define F first 
#define S second 
#define PB push_back 
#define POB pop_back 
#define MP make_pair
#define fastread()   (ios_base:: sync_with_stdio(false),cin.tie(NULL));
#include <ctime>


void drawBoard(char *spaces);
void playerMove(char *spaces, char player);
void compMove(char *spaces, char computer);
bool checkWinner(char *spaces, char player, char winner);
bool checkTie(char *spaces);


int main() {
	char spaces[9] = {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '};
	char player = 'X';
	char computer = 'O';
	bool running = true;

	drawBoard(spaces);
	while(running){
		playerMove(spaces, player);
		//drawBoard(spaces);
		if(checkWinner(spaces, player, computer)){
		    running = false;
		    break;
		}
		else if(checkTie(spaces)){
		    running  = false;
		    break;
		}
		compMove(spaces, computer);
		drawBoard(spaces);
		if(checkWinner(spaces, player, computer)){
		    running = false;
		    break;
		}
		else if(checkTie(spaces)){
		    running  = false;
		    break;
		}
	}
	cout << "Thanks for playing!!";
	return 0;
}

void drawBoard(char *spaces){
	cout << '\n';
	cout << "     |     |     " << '\n';
	cout << "  " <<  spaces[0] << "  |  " << spaces[1] << "  |  " << spaces[2] << '\n';
	cout << "_____|_____|_____" << '\n';
	cout << "     |     |     " << '\n';
	cout << "  " <<  spaces[3] << "  |  " << spaces[4] << "  |  " << spaces[5] << '\n';
	cout << "_____|_____|_____" << '\n';
	cout << "     |     |     " << '\n';
	cout << "  " <<  spaces[6] << "  |  " << spaces[7] << "  |  " << spaces[8] << '\n';
	cout << "     |     |     " << '\n';
	
	cout << '\n';
}

void playerMove(char *spaces, char player){
	int number;
	do{
		cout << "Enter a spot to place a marker (1-9): ";
		cin >> number;
		number--;
		if(spaces[number] == ' '){
			spaces[number] = player;
			break;
		}
	}while(!number > 0 || !number < 8);
}


void compMove(char *spaces, char computer){
    int number;
    srand(time(0));
    while(true){
        number = rand() % 9;
        if(spaces[number] == ' '){
            spaces[number] = computer;
            break;
        }
    }
}

bool checkWinner(char *spaces, char player, char winner){
    if(spaces[0] != ' ' && spaces[0] == spaces[1] && spaces[1] == spaces[2]){
        spaces[0] == player ? cout << "YOU WON!\n" : cout << "YOU LOSE!\n";
    }
    else if(spaces[3] != ' ' && spaces[3] == spaces[4] && spaces[4] == spaces[5]){
        spaces[0] == player ? cout << "YOU WON!\n" : cout << "YOU LOSE!\n";
    }
    else if(spaces[6] != ' ' && spaces[6] == spaces[7] && spaces[7] == spaces[8]){
        spaces[0] == player ? cout << "YOU WON!\n" : cout << "YOU LOSE!\n";
    }
    else if(spaces[0] != ' ' && spaces[0] == spaces[3] && spaces[3] == spaces[6]){
        spaces[0] == player ? cout << "YOU WON!\n" : cout << "YOU LOSE!\n";
    }
    else if(spaces[1] != ' ' && spaces[1] == spaces[4] && spaces[4] == spaces[7]){
        spaces[0] == player ? cout << "YOU WON!\n" : cout << "YOU LOSE!\n";
    }
    else if(spaces[2] != ' ' && spaces[2] == spaces[5] && spaces[5] == spaces[8]){
        spaces[0] == player ? cout << "YOU WON!\n" : cout << "YOU LOSE!\n";
    }
    else if(spaces[0] != ' ' && spaces[0] == spaces[4] && spaces[4] == spaces[8]){
        spaces[0] == player ? cout << "YOU WON!\n" : cout << "YOU LOSE!\n";
    }
    else if(spaces[2] != ' ' && spaces[2] == spaces[4] && spaces[4] == spaces[6]){
        spaces[0] == player ? cout << "YOU WON!\n" : cout << "YOU LOSE!\n";
    }
    else{
        return false;
    }
	return true;
	
}

bool checkTie(char *spaces){
    for(int i=0;i<9;i++){
        if(spaces[i] == ' '){
            return false;
        }
    }
    cout << "It's A Tie\n";
	return 0;
}

#include <iostream>
using namespace std;

const int dx[] = {1, 1, -1 ,-1 , -2, 2, -2 , 2};
const int dy[] = {-2, 2, -2, 2, 1, 1, -1 , -1};
const int DIM = 8;

class State{
private:
	int board[DIM][DIM];
	int x, y;
public:
	bool isvalid(int newx, int newy);
	bool isover();
	bool isvisited(int x, int y){return board[x][y];}
	State();
	int getx(){return x;}
	int gety(){return y;}
	void mark(int movex , int movey);
    void mark(int movex, int movey, int val);
	void print();


};
void State::print(){
	for (int i = 0;i < 8; i++){
		for (int j = 0; j < 8; j++){
			cout << board[i][j] << " ";
		}
		cout << endl;
	}
}
bool State::isvalid(int newx, int newy){
	if ((newx >= 0 and newx < DIM) and (newy >= 0 and newy < DIM))
		return true;
	return false;

}
bool State::isover(){
	for (int i = 0; i < DIM ; i++){
		for (int j = 0; j < DIM; j++){
			if (board[i][j] == 0)
				return false;
		}
	}
	return true;
}
State::State(){
	for (int i = 0; i < DIM; i++){
		for (int j = 0; j < DIM; j++){
			board[i][j] = 0;
		}
	}
	board[0][0] = 1;
	x = 0;
	y = 0;
}
void State::mark(int movex, int movey){
	board[movex][movey] = board[x][y] + 1;
	x = movex;
	y = movey;
}
void State::mark(int movex, int movey, int val){
	board[movex][movey] = val;
	x = movex;
	y = movey;

}





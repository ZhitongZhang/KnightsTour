#include "states.h"
#include <queue>

class Tree{
private: 
	State curr;
	int iterations;
public:
	Tree();
	void bfs();
	void dfs();
	void dodfs();
	void clear();
	bool backtrack(int currx, int curry, int currmove);
	void dobacktrack();//prints the backtrack results
};
Tree::Tree(){
	iterations = 0;
}
void Tree::clear(){
	State replace;
	curr = replace;
	iterations = 0;
}
void Tree::dodfs(){
	dfs();
	curr.print();
	cout << iterations << " amount of iterations\n";
}
void Tree::dfs(){ 
	if (curr.isover())
		return; // when all 64 cells are fill
	int newx, newy;
	for (int i = 0 ; i < 8 ; i++){
		int newx = curr.getx() + dx[i];
		int newy = curr.gety() + dy[i];
		if (curr.isvalid(newx,newy) and curr.isvisited(newx,newy) == false){
			curr.mark(newx,newy);
			iterations++;
			this->dfs(); //calls recursively and returns when leaf is reached
		}

	}
}
void Tree::dobacktrack(){
	backtrack(0,0,1);
	curr.print();
	cout << iterations << " amount of iterations\n";
}
bool Tree::backtrack(int currx, int curry, int currmove){ //first call of currmove should be 1
	if (currmove = DIM * DIM) //base case
		return true;
	for (int i = 0; i < 8 ; i++){
		iterations++;
		int nextx = curr.getx() + dx[i];
		int nexty = curr.gety() + dy[i];
		if (curr.isvalid(nextx,nexty)){
			curr.mark(nextx,nexty,currmove);
			if (backtrack(nextx,nexty,currmove + 1))
				return true;
			else
				curr.mark(nextx,nexty,0); // this is the backtracking aspect
		}
	}
	return false;

}

void Tree::bfs(){ //always find shortest path (time complexity is insane)
	queue <State> the_queue;
	the_queue.push(curr); //this is the root state (init state)
	while (the_queue.empty() == false){ 
		State currstate = the_queue.front();
		int x = currstate.getx();
		int y = currstate.gety();
		the_queue.pop();
		if (currstate.isover() == true){
			cout << "worked!" <<endl; 
			return;
		}
		for (int i = 0; i < 8; i++){ //where the branching happens 
			iterations++;
			int newx = x + dx[i];
			int newy = y + dy[i];
			if (currstate.isvalid(newx,newy) and currstate.isvisited(newx,newy) == false){
		
				curr.mark(newx,newy);
				currstate.mark(newx,newy);
				the_queue.push(currstate);
			}
		}
	}
	curr.print();
	cout << iterations << " number of iterations\n";

}


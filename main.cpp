#include "knighttree.h"

int main(){
	Tree knight;
	knight.dodfs();
	knight.clear(); //clear to reset the state and iteration counter; 
	knight.dobacktrack();
	knight.clear();
	knight.bfs();

	return 0; 
}

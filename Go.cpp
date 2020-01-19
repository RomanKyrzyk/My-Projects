#include <iostream>
#include <iomanip>
#include <string>
#include <cstring>
#include <cctype>
#include <cmath>
#include <cstdlib>
#include <ctime>


const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;

void shapen(int xcoord,int ycoord,int board[19][19],int temp[19][19]);

using namespace std;

 int main() {
 	int cycle=0,over=0,error=0,xcoord=0,ycoord=0,comp=0,c1,c2;
 	const int EMP=0;
 	const int BLK=1,WHI=2;
 	string input;
 	int board[19][19];
 	for (int x1=0;x1<19;x1++){
 		for (int x2=0;x2<19;x2++)
 			board[x1][x2]=0;
	 }
	int temp[19][19];
	for (int x3=0;x3<19;x3++){
 		for (int x4=0;x4<19;x4++)
 			temp[x3][x4]=0;
	 }


 	while (!over){
 		c1=19;
 		c2=1;
 		for (int c3=0;c3<19;c3++){
 			for (int c4=0;c4<19;c4++){
 				cout << '|' << board[c4][(c3+1)*-1+19]; 
			 }
			 cout << "|"<<endl;
		 }
 		if (error==1){
 			cout << "Incorrect Input\n";
 			error=0;
		 }
		if (error==2){
 			cout << "Too many characters inputted\n";
 			error=0;
		 }
		 /*if (cycle==0){
		 	board[0][1]=1;
		 	board[1][3]=1;
		 	board[2][1]=1;
		 	board[1][1]=2;
		 	board[1][2]=2;
		 	board[0][2]=1;
		 	board[2][2]=1;
		 }*/
		cout << "Input the X-coordinates, then Y-coordinates of where you want to place the stones\n";
		cout << ">>";
 		getline(cin,input);
 		if (((input[0]<'0')||(input[0]>'1'))||(static_cast<int>(input[2]!=32))||(input[1]<'0')||(input[1]>'9')||(input[4]<'0')||(input[4]>'9')||
		 ((input[3]<'0')||(input[3]>'9'))||(input.empty())) {
 			error=1;
 			continue;
		 }
		if(input.length()>5) {
			error=2;
			continue;
		}

		xcoord=static_cast<int>(((input[0]-48))*10);
		xcoord=xcoord+static_cast<int>((input[1]-48)-1);
		ycoord=static_cast<int>(((input[3]-48))*10);
		ycoord=ycoord+static_cast<int>((input[4]-48)-1);
		cout << xcoord << " " << ycoord << endl;
		if(board[xcoord][ycoord]==EMP){
			if (cycle%2==0){
				board[xcoord][ycoord]=BLK;
				if ((board[xcoord][ycoord+1]==WHI||ycoord==18)&&(board[xcoord+1][ycoord]==WHI||xcoord==18)&&(board[xcoord-1][ycoord]==WHI||xcoord==0)&&
				(board[xcoord][ycoord-1]==WHI||ycoord==0)){
					board[xcoord][ycoord]=EMP;
				}
				if ((board[xcoord][ycoord+1]==WHI)&&(board[xcoord][ycoord+2]==BLK||ycoord==17)&&(board[xcoord-1][ycoord+1]==BLK||xcoord==0||ycoord==19)&&
				(board[xcoord+1][ycoord+1]==BLK||xcoord==18||ycoord==18)){
					board[xcoord][ycoord+1]=EMP;
				}
				if ((board[xcoord][ycoord-1]==WHI)&&(board[xcoord][ycoord-2]==BLK||ycoord==1)&&(board[xcoord-1][ycoord-1]==BLK||xcoord==0||ycoord==0)&&
				(board[xcoord+1][ycoord-1]==BLK||xcoord==18||ycoord==0)){
					board[xcoord][ycoord-1]=EMP;
				}
				if ((board[xcoord+1][ycoord]==WHI)&&(board[xcoord+2][ycoord]==BLK||xcoord==17)&&(board[xcoord+1][ycoord+1]==BLK||xcoord==18||ycoord==18)&&
				(board[xcoord+1][ycoord-1]==BLK||xcoord==18||ycoord==0)){
					board[xcoord+1][ycoord]=EMP;
				}
				if ((board[xcoord-1][ycoord]==WHI)&&(board[xcoord-2][ycoord]==BLK||xcoord==1)&&(board[xcoord-1][ycoord+1]==BLK||xcoord==0||ycoord==18)&&
				(board[xcoord-1][ycoord-1]==BLK||xcoord==0||ycoord==0)){
					board[xcoord-1][ycoord]=EMP;
				}
				shapen(xcoord,ycoord,board,temp);

		}


			if (cycle%2==1){
				board[xcoord][ycoord]=WHI;
				if ((board[xcoord][ycoord+1]==BLK||ycoord==18)&&(board[xcoord+1][ycoord]==BLK||xcoord==18)&&(board[xcoord-1][ycoord]==BLK||xcoord==0)&&
				(board[xcoord][ycoord-1]==BLK||ycoord==0)){
					board[xcoord][ycoord]=EMP;
				}
				if ((board[xcoord][ycoord+1]==BLK)&&(board[xcoord][ycoord+2]==WHI||ycoord==17)&&(board[xcoord-1][ycoord+1]==WHI||xcoord==0||ycoord==19)&&
				(board[xcoord+1][ycoord+1]==WHI||xcoord==18||ycoord==18)){
					board[xcoord][ycoord+1]=EMP;
				}

				if ((board[xcoord][ycoord-1]==BLK)&&(board[xcoord][ycoord-2]==WHI||ycoord==1)&&(board[xcoord-1][ycoord-1]==WHI||xcoord==0||ycoord==0)&&
				(board[xcoord+1][ycoord-1]==WHI||xcoord==18||ycoord==0)){
					board[xcoord][ycoord-1]=EMP;
				}
				if ((board[xcoord+1][ycoord]==BLK)&&(board[xcoord+2][ycoord]==WHI||xcoord==17)&&(board[xcoord+1][ycoord+1]==WHI||xcoord==18||ycoord==18)&&
				(board[xcoord+1][ycoord-1]==WHI||xcoord==18||ycoord==0)){
					board[xcoord+1][ycoord]=EMP;
				}
				if ((board[xcoord-1][ycoord]==BLK)&&(board[xcoord-2][ycoord]==WHI||xcoord==1)&&(board[xcoord-1][ycoord+1]==WHI||xcoord==0||ycoord==18)&&
				(board[xcoord-1][ycoord-1]==WHI||xcoord==0||ycoord==0)){
					board[xcoord-1][ycoord]=EMP;
				}
			}
		}

 		cycle++;
	}
 	return 0;
 }
 void shapen(int xcoord,int ycoord,int board[19][19],int temp[19][19]) {
 	const int WHI=2,BLK=1,EMP=0;
 	int ycoordo,xcoordo,routen;
 	string route;
 	if (route.empty()){
 		int ycoordo=ycoord,xcoordo=xcoord;
	 }
 	board[xcoord][ycoord]=1;
 	if ((board[xcoord][ycoord+1]==WHI)&&(board[xcoord][ycoord+2]!=EMP)&&(board[xcoord+1][ycoord+1]!=EMP)&&(board[xcoord-1][ycoord+1]!=EMP)){
					temp[xcoord][ycoord+1]=1;
					if ((board[xcoord-1][ycoord+1])&&(board[xcoord+1][ycoord+1])&&(board[xcoord][ycoord+2])) {
						shapen(xcoord,ycoord,board,temp);

						shapen(xcoord,ycoord,board,temp);
						shapen(xcoord,ycoord,board,temp);
					}
					if (board[xcoord][ycoord+2]==WHI){
						ycoord++;
						shapen(xcoord,ycoord,board,temp);
					}
					if ((board[xcoord][ycoord+1]==WHI||ycoord==18)&&(board[xcoord][ycoord+2]==BLK||ycoord==17)&&(board[xcoord-1][ycoord+1]==BLK||xcoord==0||ycoord==19)&&
					(board[xcoord+1][ycoord+1]==BLK||xcoord==18||ycoord==18)){
					for (int x12=0;x12<19;x12++){
						for (int x13=0;x13<19;x13++){
							if (temp[x13][x12]==1){
							board[x13][x12]=EMP;
							temp[x13][x12]=0;
							}
						}
					}
					}
					if (board[xcoord+1][ycoord+1]==WHI){
						ycoord++;
						shapen(xcoord,ycoord,board,temp);
					}

		}
}



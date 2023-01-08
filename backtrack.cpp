#include <iostream>
using namespace std;

void printmatrix(int** sol , int n){
  for (int i = 0; i < n; i++){
    for (int j= 0; j < n; j++){
      cout << sol[i][j] << " ";
    }
    cout << endl;
  }
  
}

bool is_safe(int **sol , int n, int x, int y){
   if((x<n) && (x>=0) && (y<n) && (y>=0) && (sol[x][y]==-1) ){
    return 1;
   }
   return 0;
}

bool KTutil(int x , int y ,int n ,int move , int x_move[] , int y_move[] ,int **sol){
        int next_x ,next_y ;
        if(move==n*n){
          return 1;
        }

        for (int i = 0; i < 8; i++){
           next_x =x+x_move[i];
           next_y =y+y_move[i];
           if(is_safe(sol , n, next_x,next_y)){
                sol[next_x][next_y] = move;
                if(KTutil(next_x,next_y,n,move+1,x_move,y_move,sol)==1){
                  return 1;
                }else{
                  sol[next_x][next_y] = -1;
                }
           }
          }
        return 0;
        
}
int KTsolve(int n){
  int **sol, move=1;
  sol = new int*[n];
  for (int i = 0; i < n; i++){
     sol[i] = new int[n];
  }
  for (int i = 0; i < n; i++){
    for (int j = 0; j<n; j++){
      sol[i][j] = -1;
    }
    
  }
  
  int x_move[8] = {2,2,-2,-2,1,-1,1,-1};
  int y_move[8] = {1,-1,1,-1,2,2,-2,-2};
  sol[0][0] = 0;
  if(KTutil(0,0,n,1,x_move,y_move,sol)== 0){
    cout << "Solution doesn't exist";
    return 0;
  }else{
    printmatrix(sol,n);
   }
  return 1;
}



int main(){
   KTsolve(8);
   return 0;
}
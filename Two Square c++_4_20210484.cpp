#include <iostream>

#include <unistd.h>

#include <cmath>

#include <stdio.h>

#include <iomanip>

#include <stdlib.h>

#include<bits/stdc++.h>

using namespace std;

int turn =0 ;

char matrix[4][4] ={'1','2','3','4','5','6','7','8','9','A','B','C','D','E','F','G'};//creating a matrix

void print_matrix(){ //printing the matrix and its frame

    system("cls");

    cout<<"-----+-----+----"<<endl ;


        for(int i =0 ;i<4 ;i++){
                cout<<"|  ";

            for(int j=0 ;j<4 ; j++){

                cout<<matrix[i][j]<<"  ";

            }
            cout<<"|";
            cout<<endl ;


        }

    cout<<"-----+-----+----"<<endl ;


    }

void player1_turn(){ //player1 turn

    char player1;

    cout<<"please player1 choose a location---> " ;

    cin>>player1;

    for(int i =0 ;i<4 ;i++){

            for(int j=0 ;j<4 ; j++){

                 if (matrix[i][j]==player1){

                    if(turn==1){

                        matrix[i][j]='X';
                        print_matrix();
                    }

                    else if(turn==2){

                            if(matrix[i][j-1]=='X'||matrix[i][j+1]=='X'||matrix[i-1][j]=='X'||matrix[i+1][j]=='X'){

                                matrix[i][j]='X';

                                print_matrix();

                            }
                            else{

                                cout<<"WRONG LOCATION--play in a rectangle!"<<endl<<endl ;
                                player1_turn();
                            }


                        }

                    }

                 }

            }


}


void player2_turn(){//player2 turn

    char player2;

    int check = 0;

    cout<<"please player2 choose a location---> " ;

    cin>>player2;

    for(int i =0 ;i<4 ;i++){

            for(int j=0 ;j<4 ; j++){

                 if (matrix[i][j]==player2){

                    if(turn==3){

                        matrix[i][j]='X';
                        print_matrix();
                    }

                    else if(turn==0){

                            if(matrix[i][j-1]=='X'||matrix[i][j+1]=='X'||matrix[i-1][j]=='X'||matrix[i+1][j]=='X'){

                                matrix[i][j]='X';

                                print_matrix();

                            }
                            else{

                                cout<<"WRONG LOCATION--play in a rectangle"<<endl<<endl ;
                                player2_turn();
                            }


                        }

                    }

                 }

            }


}

void winner(){ //check winner

        int x=0 ;

        for(int i =0 ;i<4 ;i++){

            for(int j=0 ;j<4 ; j++){

                if(matrix[i][j]!='X'){

                    x+=1;
                }

            }
        }


        if((x==2)&&(turn==0||turn==1)){

           cout<<("TOW SQUAR GAME,Congratulation Player1 Wins!!");
           exit(0);

        }
        else if((x==2)&&(turn==2||turn==3)){

            cout<<("TOW SQUAR GAME,Congratulation Player2 Wins!!");

            exit(0);
        }



}







int main(){

    while(true){

        if (turn==0||turn==1 ){ //check player1 turn


            turn+=1 ;

            print_matrix();

            player1_turn();

            winner();

         }

        else if(turn==2||turn==3||turn==4){//check player2 turn

            turn+=1 ;
            if (turn==4){

                turn=0;
            }

            print_matrix();

            player2_turn();

            winner();

        }
    }




    return 0 ;
}

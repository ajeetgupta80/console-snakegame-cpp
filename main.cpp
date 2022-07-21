#include<iostream>
#include<conio.h>
#include<time.h>

using namespace std;
bool gameOver;
const int width = 20;
const int height = 20;
int x,y,fruitx, fruity, score;
enum eDirection{stop =0, LEFT ,RIGHT ,UP , DOWN};

// makeing a variable of enum 
eDirection dir;


void setup()
{
    
    srand(time(NULL));
    gameOver = false;
    dir = stop;
    // intial position of the snake in the center
    x = width /2;
    y= height /2; 
    // placing the fruit on the random place on the map 
    fruitx = rand() % width;
    fruity = rand() % height;
    score = 0;

}
void draw()
{
    
    system("cls");
    // top wall .....................
    for(int i=0; i<width+2; ++i)
      cout<<"~";
    cout<<endl;

    // side walls .....................
    for(int i=0; i<height; ++i)
    {
        for(int j=0; j<height; ++j)
        {
            if(j==0)
            cout<<":";

    // printing snake head and fruit...............
         if(i==y && j==x)
          cout<<"0";
          else if(i==fruity && j==fruitx)
          cout<<"f";
          else
          cout<<" ";

            if(j==width-1)
            cout<<":";
        }
        cout<<endl;
    }



    // bottom wall..................
    for(int i=0; i<width+2; ++i)
    cout<<"~";
    cout<<endl;


}
void input()
{
    if(_kbhit()) 
    {
        switch (_getch())
        {
        case 'a':
            dir = LEFT;
            break;
        case 'd':
            dir = RIGHT;
            break;
        case 'w':
            dir = UP;
            break;
        case 's':
            dir = DOWN;
            break;
        case 'x':
            gameOver = true;
            break;
        
        
        }
    }

}
void logic()
{
    switch (dir)
    {
    case LEFT:
        x--;
        break;
    case RIGHT:
        x++;
        break;
    case UP:
        y--;
        break;
    case DOWN:
        y++;
        break;
    }
// when snake head crashes in wall gameOver
if(x>width || x<0 || y>height || y<0)
   gameOver=true;


}


int main()
{
  
    setup();
    while(!gameOver)
    {
    cout<<"WELCOME TO CONSOLE SNAKE";
        
        draw();
        input();
        logic();
        
    }
    cout<<"   _________   "<<endl;
    cout<<"~~~|GAMEOVER|~~~"<<endl;
    cout<<"                  "<<endl;
    cout<<"                  ";
   
    
  




}
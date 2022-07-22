#include<iostream>
#include<conio.h>
#include<windows.h>
#include<time.h>

using namespace std;
bool gameOver;
const int width = 20;
const int height = 20;
int x,y,fruitx, fruity, score;
// making snake tail..........
int tailX[100], tailY[100];
int ntail;

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
    cout<<score;

}
void draw()
{
    
    system("cls");
    cout<<"WELCOME TO CONSOLE SNAKE"<<endl;
    // top wall .....................
    for(int i=0; i<width+2; ++i)
      cout<<"~";
    cout<<endl;

    // side walls .....................
    for(int i=0; i<height; ++i) // its y cordinates
    {
        for(int j=0; j<height; ++j) // its x cordinates
        {
            if(j==0)
            cout<<":";

    // printing snake head and fruit...............
         if(i==y && j==x)
          cout<<"0";
          else if(i==fruity && j==fruitx)
          cout<<"f";
          else
          {
            bool print = false;
            for(int k=0; k<ntail; k++)
            {
                if(tailX[k] == j && tailY[k] == i)
                {
                    cout<<"o";
                    print = true;


                }
               
            }
             if(!print)
                 cout<<" ";
          }
         

            if(j==width-1)
            cout<<":";
        }
        cout<<endl;
    }



    // bottom wall..................
    for(int i=0; i<width+2; ++i)
    cout<<"~";
    cout<<endl;
    cout<<"Score:"<<score<<endl;
    


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
    // adding the tail to the snake head .............
    int prevx = tailX[0];
    int prevy = tailY[0];
     int prev2x, prev2y;
    //  snake tail head 
     tailX[0]=x;
     tailY[0]=y;
    for(int i=1; i< ntail; i++)
    {
        prev2x = tailX[i];
        prev2y = tailY[i];
        tailX[i] = prevx;
        tailY[i] = prevy;
        prevx = prev2x;
        prevy = prev2y;
    }

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

// snake eating himself and gameover
for(int i=0; i<ntail; i++)
{
    if(tailX[i]==x && tailY[i]==y)
    {
        gameOver = true;
    }
}

//   when snake head in fruit cordinate it will eat and hence snake 
// will increase 
if (x == fruitx && y==fruity)
{
    score +=10;
    fruitx = rand() % width;
    fruity = rand() % height;
    ntail++;

   
}



}


int main()
{
  
    setup();
    while(!gameOver)
    {
    
        
        draw();
        input();
        logic();
        // if(score<40)
        //  Sleep(15);
        // if(score>40)
        // Sleep(10);
        // if(score>80)
        Sleep(20);
        
        
    }
    cout<<"   _________   "<<endl;
    cout<<"~~~|GAMEOVER|~~~"<<endl;
    cout<<"                  "<<endl;
    cout<<"                  ";
   
    
  




}
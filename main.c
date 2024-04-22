#include <stdlib.h>
#include <stdio.h>
#include <pthread.h>
#include <unistd.h>
#include <strings.h>

int stor;
int x;
int a;
int locationx;
int y;
int coins;
_Bool killed;
pthread_t test;
_Bool inair=0;
_Bool running = 1;
int length;
int lengthstorage;
_Bool alldone;
_Bool done;
int location = 561;
int hp = 100;
int b;
int calc;
int calculation;
int maxhp=100;
int room2[999] = {
    1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,8, // length = 56
    1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,8,
    1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,8,
    1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,8,
    1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,8,
    1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,8,
    1,0,0,0,0,0,0,0,0,0,0,0,102,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,8,
    1,0,0,0,0,0,0,0,0,0,0,2,2,2,2,2,2,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,8,
    100,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,8,
    100,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,8,
    100,0,0,0,0,0,0,0,0,0,0,0,0,0,0,-1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1000,8,//561 & 613
    2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,9,//671
};
int map[999] = {
    1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,101,8, // length = 56
    1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,101,8,
    1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,101,8,
    1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,101,8,
    1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,101,8,
    1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,101,8,
    1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,101,8,
    1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,101,8,
    1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,101,8,
    1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,101,8,
    1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,10,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,101,8,//561 & 613
    2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,99,9,//671
    /*0,12*/
};
int room3[999] =  {
    1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,8,
    1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,8,
    1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,8,
    1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,8,
    1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,8,
    1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,8,
    1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,8,
    1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,8,
    1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,8,
    1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,8,
    1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,8,
    1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,8,
    1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,8,
    1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,8,
    1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,8,
    1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,8,
    1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,8,
    1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,8,
    1,99,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,8,
    2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,99,9,
};
void draw();
void move_cursor() {
    printf("\033[%d;%dH", y, x);
    fflush(stdout);
}
void text(){
    y=14;
    x=0;
    move_cursor();
}
void hurt(){
    x=0;
    y=13;
    move_cursor();
    printf("\033[0;32m%d/\033[0;37m%d ",hp,maxhp);
}
int get();
void *gravity()
{
    while(running==1){
        while(inair==1){
            calc=location+length;
            
            if(map[calc]==0)
            {
                location=calc;
                x=(location%length)*2;
                y=location/length+1;
                move_cursor();
            }
                

            sleep(1);
        }
    }
}
int main()
{

getchar();

    pthread_create(&test,NULL,gravity,NULL);
    
    draw();
    hurt();
while (running == 1){
    if(hp<=0)
    {
        location=561;
        hp=maxhp/2;
        hurt();
    }
    x=(location%length)*2;
    y=location/length+1;
    locationx=x;
    move_cursor();
    if(killed=1){
        printf("  ");
    }
    map[location] = 0;
    killed=0;
    switch(get())
    {
        case 1:
            if(inair==0)
                calculation=location-length*3;
            
        break;
        case 2:
            calculation=location+length;
            if(map[calculation]==10)
            {
            killed=1;
            map[calculation]=0;
            coins+=1;

            }
        break;
        case 3:
            calculation=location+1;
        
        break;
        case 4:
            calculation=location-1;
        
            break;
    }
    if(map[calculation]==0)
        location=calculation;
    else if(map[calculation]==10){  
        hp-=10;
        hurt();
    }
    else if(map[calculation]==101)                                                                          //PORTALS START HERE
    {
        while(a != 671)
        {
            map[a]=room2[a];
            a++;
        }
        draw();
        location=561;
    }
 /*   else if(map[calculation]==102){                           WORK HEREERERERERERERERRERE
        while(a != 399)
        {
            map[a]=room3[a];
            a++;
        }
        draw();
        location=361;
    }*/
        else if(map[calculation]==100){
        location=613;
    }
    else if(map[calculation]==1000){
        location=561;
    }                                                                                                   //PORTALS END HERE
    else if (map[calculation]==-1){                                                                     //NPC INTERACTIONS START HERE
       text();
       printf("AHHHHHHH\n");
       getchar();
       printf("WHERES MY BODY!!!!!\n");
       getchar();
       printf("nah im just screwing with you i was born this way\n");
       getchar();
       printf("mommy says im special\n");
    }
    calculation=location+length;                                                                            //NPC INTERACTIONS END HERE
    if(map[calculation]<=0)
        inair=1;
    else
        inair=0;
}
    return 0;
}
void draw()
{

   system("clear");
   // pthread_create(&test2,NULL,movement,NULL);
alldone=0;
done=0;
map[location]=-3;
    for (int i = 0; i < 100; i++)//HEIGHT
    {
       
        for (int i = 0; i < 100; i++)//LENGTH
        {
            if (running==1)                                                                                 //FIX THIS IF YOU NEED TO
            {
                    length++;
                if (map[b] >= 50&&map[b]<=98){
                    stor = map[b];
                        map[b] = -1;
                        
                }
                if(map[b] >= 1000){
                    stor=map[b];
                    map[b] = 1000;
                }
                    
                switch(map[b]){                  //object printing from here
                    case -1:
                    printf("🧑 ");
                    if(stor!=0){
                        map[b] = stor;
                    }
                    break;
                    case 0:
                    printf("  ");               //space
                    break;
                    case 1:
                    printf("| ");               //wall |
                    break;
                    case 2:
                    printf("==");               //roof ==
                    break;
                    case 3:
                    printf("  ");               //invisible killing mines
                    break;
                    case 4:
                    printf("\\ ");               //backslash  
                    break;
                    case 8:
                    printf("\n");
                    done=1;
                    lengthstorage=length;
                    length=0;
                    break;
                    case 9:
                    done=1;
                    alldone=1;
                    break;
                    case 10:
                    //monsterx=b*2;
                    printf("👾 ");
                    break;
                    case 99:
                    printf("%d!", b);
                    break;
                    default:
                    printf("??");
                }
                                                        //to here
            }
            if(done==1){
                i=100;
            }
            b++;
        }
        done=0;
         if(alldone==1){
            i=100;
        }
    }
    b = 0;
length=lengthstorage;
}
int get()
{
                                                            //omars code for input
        system("/bin/stty -echo raw");
        char ch = fgetc(stdin);
        if(ch == '\033')
        {
            fgetc(stdin);

            system("/usr/bin/env stty cooked -echo");
            switch(fgetc(stdin))
            {
                case 'A':
                return 1;
                break;
    
                case 'B':
                 return 2;
                break;
    
                case 'C':
                return 3;
                break;
    
                case 'D':
                return 4;
                break;

                
            }
        }
        else if(ch== 'i'){
            text();
            printf("Moneys: %d", coins);
            getchar();
        }
        else if(ch == 'r'){
            system("clear");
            draw();
        }
    

}
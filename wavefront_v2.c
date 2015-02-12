/*
 * wavefront_v2.c
 *
 * Created: 2/9/2015 1:10:02 PM
 *  Author: xuez
 */ 


//#include "capi324v221.h"
#include <stdlib.h>
#include <stdio.h>




//all possible goal point and step solutions
int x0y0[4][4] = {{0,99,99,5},{1,2,3,4},{2,99,99,5},{3,99,7,6}};
int x0y3[4][4] = {{5,99,99,0},{4,3,2,1},{5,99,99,2},{6,99,4,3}};
int x1y0[4][4] = {{1,99,99,4},{0,1,2,3},{1,99,99,4},{2,99,6,5}};
int x1y1[4][4] = {{2,99,99,3},{1,0,1,2},{2,99,99,3},{3,99,5,4}};
int x1y2[4][4] = {{3,99,99,2},{2,1,0,1},{3,99,99,2},{4,99,4,3}};
int x1y3[4][4] = {{4,99,99,1},{3,2,1,0},{4,99,99,1},{5,99,3,2}};
int x2y0[4][4] = {{2,99,99,5},{1,2,3,4},{0,99,99,5},{1,99,7,6}};
int x2y3[4][4] = {{5,99,99,2},{4,3,2,1},{5,99,99,0},{6,99,2,1}};
int x3y0[4][4] = {{3,99,99,6},{2,3,4,5},{1,99,99,6},{0,99,8,7}};
int x3y2[4][4] = {{7,99,99,4},{6,5,4,3},{7,99,99,2},{8,99,0,1}};
int x3y3[4][4] = {{6,99,99,3},{5,4,3,2},{6,99,99,1},{7,99,1,0}};
int ori_map[4][4] = {{0,99,99,0},{0,0,0,0},{0,99,99,0},{0,99,0,0}};
int step_map[11][4][4] = {{{0,99,99,5},{1,2,3,4},{2,99,99,5},{3,99,7,6}},{{5,99,99,0},{4,3,2,1},{5,99,99,2},{6,99,4,3}},{{1,99,99,4},{0,1,2,3},{1,99,99,4},{2,99,6,5}},{{2,99,99,3},{1,0,1,2},{2,99,99,3},{3,99,5,4}},
							{{3,99,99,2},{2,1,0,1},{3,99,99,2},{4,99,4,3}},{{4,99,99,1},{3,2,1,0},{4,99,99,1},{5,99,3,2}},{{2,99,99,5},{1,2,3,4},{0,99,99,5},{1,99,7,6}},{{5,99,99,2},{4,3,2,1},{5,99,99,0},{6,99,2,1}},
								{{3,99,99,6},{2,3,4,5},{1,99,99,6},{0,99,8,7}},{{7,99,99,4},{6,5,4,3},{7,99,99,2},{8,99,0,1}},{{6,99,99,3},{5,4,3,2},{6,99,99,1},{7,99,1,0}}}; //all possible step map for each goal point

//global varibale
char sensors; 


//functions
	
void main(){
	
	//initial
	//ATTINY_open();
	//LCD_open();
	//STEPPER_open();

//	sensors = ATTINY_get_sensors();
	
	
	int goal_pos[4][4];
	int index = 0;
	int x_pos; int y_pos;
	int keepgoing = 1;
	int dirc_map[4][4];//the map pull out from the step_map for particular goal_pos
	
	for(int i=0;i<4;i++){
		for(int j=0;j<4;j++){
			if((i==0 && j==1)||(i==0&&j==2)||(i==2&&j==1)||(i==2&&j==2)||(i==3&&j==1)){
				goal_pos[i][j] = 99;
				//index++;
			}
      else {
        goal_pos[i][j] = index;
        index++;
      }
		}
	}//end for
//test goal_pos	
  for(int i=0;i<4;i++){
    for(int j=0;j<4;j++){
      printf("the index is %d\n",goal_pos[i][j]);
    }
  }
	//LCD_clear();
	//LCD_printf("Hello");
	//TMRSRVC_delay(2000);
	//LCD_clear();
	/*
	while(keepgoing){
		if(ATTINY_get_SW_state(ATTINY_SW3)){
			x_pos++;
			LCD_printf("x:%d\n",x_pos);
		}
		if(ATTINY_get_SW_state(ATTINY_SW4)){
			y_pos++;
			LCD_printf("y:%d\n",y_pos);
		}
		if(ATTINY_get_SW_state(ATTINY_SW5)){
			keepgoing = 0;//end while
		}
	}//end while
	*/
  scanf("%d",&x_pos);
  printf("x_pos:%d\n",x_pos);
  scanf("%d",&y_pos);
  printf("y_pos:%d\n",y_pos);

	index = goal_pos[x_pos][y_pos];
  printf("the index is %d\n",index);
	//LCD_clear();
	//LCD_printf("index:%d\n",index);
	//TMRSRVC_delay(2000);
	//LCD_clear();
	for(int i=0;i<4;i++){
		for(int j=0;j<4;j++){
			dirc_map[i][j] = step_map[index][i][j];
			//LCD_printf("%d",dirc_map[i][j]);
      printf("%d,",dirc_map[i][j]);
		}
		//LCD_printf("\n");
    printf("\n");
	}

  int x_start;
  int y_start;

  scanf(" %d\n",&x_start);
  printf("start x is :%d\n",x_start);
  scanf(" %d\n",&y_start);
  printf("start y is :%d\n",y_start);

	int start_index;
  start_index = dirc_map[x_start][y_start];
  printf("start index %d\n",start_index);


	char move_dirc[10];
  int x_step;
  int y_step;
  int up,left,right,down;
  x_step = x_start;
  y_step = y_start;
  for(int i=0;i<start_index;i++){
    /*
    if((dirc_map[x_step][y_step]-dirc_map[x_step-1][y_step]==1)&&((x_step-1)>=0)){
      move_dirc[i] = 'N';
      x_step = x_step;
      y_step = y_step-1;
    }
    if((dirc_map[x_step][y_step]-dirc_map[x_step+1][y_step]==1)&&((x_step+1)<=3)){
      move_dirc[i] = 'S';
      x_step = x_step+1;
      y_step = y_step;
      }
     if((dirc_map[x_step][y_step]-dirc_map[x_step][y_step-1]==1)&&((y_step-1)>=0)){
       move_dirc[i] = 'W';
       x_step = x_step;
       y_step = y_step-1;
     }
     if((dirc_map[x_step][y_step]-dirc_map[x_step][y_step+1]==1)&&((y_step+1)<=3)){
       move_dirc[i] = 'E';
       x_step = x_step;
       y_step = y_step+1;
      }
     */
    printf("current pos is %d %d\n",x_step, y_step);
    if((x_step-1) < 0){
      up = 99;
    }else{
      up = dirc_map[x_step-1][y_step];
    }
    if((y_step-1) < 0){
      left = 99;
    }else {
      left = dirc_map[x_step][y_step-1];
    }
    if((y_step+1)>3){
      right = 99;
    }else{
      right = dirc_map[x_step][y_step+1];
    }
    if((x_step+1)>3){
      down = 99;
    }else {
      down = dirc_map[x_step+1][y_step];
    }
    if((up < left) && (up < right) && (up < down)){
      move_dirc[i] = 'N';
      x_step = x_step-1;
      y_step = y_step;
      printf("the next pos is %d, %d\n",x_step,y_step);
    }
    if((down < up) && (down < left) && (down < right)){
      move_dirc[i] = 'S';
      x_step = x_step+1;
      y_step = y_step;
      printf("the next pos is %d, %d\n",x_step,y_step);
    }
    if((left < up ) && (left < right) && (left < down)){
      move_dirc[i] = 'W';
      x_step = x_step;
      y_step = y_step-1;
      printf("the next pos is %d, %d\n",x_step,y_step);
    }
    if((right < up) && (right < left) && (right < down)){
      move_dirc[i] = 'E';
      x_step = x_step;
      y_step = y_step+1;
      printf("the next pos is %d, %d\n",x_step,y_step);
    }
  }//end for loop
  printf("the direction is %s\n",move_dirc);
       
	
	
	
}//end main



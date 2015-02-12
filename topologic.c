#include <stdio.h>
#include <stdlib.h>


int top_map[4][4] = {{11,15,15,11},{8,5,5,2},{10,15,15,10},{14,13,5,6}};




struct movespace {
  int avispace;//NSWE
};


void main(void){
  struct movespace gotocell[16];
  gotocell[0].avispace = 0b1111;
  gotocell[1].avispace = 0b0111;
  gotocell[2].avispace = 0b1110;
  gotocell[3].avispace = 0b0110;
  gotocell[4].avispace = 0b1011;
  gotocell[5].avispace = 0b0011;
  gotocell[6].avispace = 0b1010;
  gotocell[7].avispace = 0b0010;
  gotocell[8].avispace = 0b1101;
  gotocell[9].avispace = 0b0101;
  gotocell[10].avispace = 0b1100;
  gotocell[11].avispace = 0b0100;
  gotocell[12].avispace = 0b1001;
  gotocell[13].avispace = 0b0001;
  gotocell[14].avispace = 0b1000;
  gotocell[15].avispace = 0b0000;
  /*  print for test
  for(int i=0;i<16;i++){
      printf("avaiable space is ");
      printf("%d\n",gotocell[i].avispace);
  }
  */

  int currentCell;
  int avi_map[4][4];//the map shows which cell can be reached
  for(int i=0;i<4;i++){
   for(int j=0;j<4;j++){
     currentCell = top_map[i][j];
     if((gotocell[currentCell].avispace & 0b1111) != 0b0000){
       avi_map[i][j] = 50;
     }
     else {
       avi_map[i][j] = 99;
     }
   }
  }//end for
  
  
  // print for test
  for(int i=0;i<4;i++){
    for(int j=0;j<4;j++){
      printf("%d,",avi_map[i][j]);
     }
     printf("\n");
  }
  


  int x_end;
  int y_end;
  int dirc_map[4][4];
  int currentAvispace;

  //initial dirc_map
  for(int i=0;i<4;i++){
    for(int j=0;j<4;j++){
      dirc_map[i][j] = avi_map[i][j];
    }
  }


  printf("end x:");
  scanf("%d\n",&x_end);
  printf("end x is:%d\n",x_end);
  printf("end y:");
  scanf("%d\n",&y_end);
  printf("end y is:%d\n",y_end);
  printf("end point is %d, %d\n",x_end,y_end);
  dirc_map[x_end][y_end] = 0;
 if(avi_map[x_end][y_end] != 99){
  for(int i=x_end;i<4;i++){
    for(int j=y_end;j<4;j++){
      /*
      if(avi_map[i][j] == 99){
        printf("please enter a valuable end point\n");
        goto end;
      }
      */
     // else {
        currentCell = top_map[i][j];
        currentAvispace = gotocell[currentCell].avispace;
        if((currentAvispace & 0b0001) == 0b0001){//check right
          if(dirc_map[i][j+1] >= 50){
            dirc_map[i][j+1] = dirc_map[i][j] + 1;
            printf("the current value is: %d, %d, %d\n",i,j+1,dirc_map[i][j+1]);
          }else {
            dirc_map[i][j+1] = dirc_map[i][j+1];
            printf("the current value is: %d, %d, %d\n",i,j+1,dirc_map[i][j+1]);
          }
        }
        if((currentAvispace & 0b0100) == 0b0100){//check down
          if(dirc_map[i+1][j] >= 50){
            dirc_map[i+1][j] = dirc_map[i][j] + 1;
            printf("the current value is: %d, %d, %d\n",i+1,j,dirc_map[i+1][j]);
          }else {
            dirc_map[i+1][j] = dirc_map[i+1][j];
            printf("the current value is: %d, %d, %d\n",i+1,j,dirc_map[i+1][j]);
          }
        }
        if((currentAvispace & 0b1000) == 0b1000){//check up
          if(dirc_map[i-1][j] >= 50){
            dirc_map[i-1][j] = dirc_map[i][j] + 1;
            printf("the current value is: %d, %d, %d\n",i-1,j,dirc_map[i-1][j]);
          }else {
            dirc_map[i-1][j] = dirc_map[i-1][j];
            printf("the current value is: %d, %d, %d\n",i-1,j,dirc_map[i-1][j]);
          }
        }
        if((currentAvispace & 0b0010) == 0b0010){//check left
          if(dirc_map[i][j-1] >= 50){
            dirc_map[i][j-1] = dirc_map[i][j] + 1;
            printf("the current value is: %d, %d, %d\n",i,j-1,dirc_map[i][j-1]);
          }else {
            dirc_map[i][j-1] = dirc_map[i][j-1];
            printf("the current value is: %d, %d, %d\n",i,j-1,dirc_map[i][j-1]);
          }
        }
     // }//end else
    }
 }//end for
}
  
  //start from 33
  for(int i=3;i>=0;i--){
    for(int j=3;j>=0;j--){
       currentCell = top_map[i][j];
       currentAvispace = gotocell[currentCell].avispace;
       if((currentAvispace & 0b0001) == 0b0001){//check right
          if(dirc_map[i][j+1] >= 50){
            dirc_map[i][j+1] = dirc_map[i][j] + 1;
          }else {
            dirc_map[i][j+1] = dirc_map[i][j+1];
          }
        }
        if((currentAvispace & 0b0100) == 0b0100){//check down
          if(dirc_map[i+1][j] >= 50){
            dirc_map[i+1][j] = dirc_map[i][j] + 1;
          }else {
            dirc_map[i+1][j] = dirc_map[i+1][j];
          }
        }
        if((currentAvispace & 0b1000) == 0b1000){//check up
          if(dirc_map[i-1][j] >= 50){
            dirc_map[i-1][j] = dirc_map[i][j] + 1;
          }else {
            dirc_map[i-1][j] = dirc_map[i-1][j];
          }
        }
        if((currentAvispace & 0b0010) == 0b0010){//check left
          if(dirc_map[i][j-1] >= 50){
            dirc_map[i][j-1] = dirc_map[i][j] + 1;
          }else {
            dirc_map[i][j-1] = dirc_map[i][j-1];
          }
        }
    }
  }//end for
  
  // start fron 00
  for(int i=0;i<4;i++){
    for(int j=0;j<4;j++){
       currentCell = top_map[i][j];
       currentAvispace = gotocell[currentCell].avispace;
       if((currentAvispace & 0b0001) == 0b0001){//check right
          if(dirc_map[i][j+1] >= 50){
            dirc_map[i][j+1] = dirc_map[i][j] + 1;
          }else {
            dirc_map[i][j+1] = dirc_map[i][j+1];
          }
        }
        if((currentAvispace & 0b0100) == 0b0100){//check down
          if(dirc_map[i+1][j] >= 50){
            dirc_map[i+1][j] = dirc_map[i][j] + 1;
          }else {
            dirc_map[i+1][j] = dirc_map[i+1][j];
          }
        }
        if((currentAvispace & 0b1000) == 0b1000){//check up
          if(dirc_map[i-1][j] >= 50){
            dirc_map[i-1][j] = dirc_map[i][j] + 1;
          }else {
            dirc_map[i-1][j] = dirc_map[i-1][j];
          }
        }
        if((currentAvispace & 0b0010) == 0b0010){//check left
          if(dirc_map[i][j-1] >= 50){
            dirc_map[i][j-1] = dirc_map[i][j] + 1;
          }else {
            dirc_map[i][j-1] = dirc_map[i][j-1];
          }
        }

    }
  }//end for
  
   //start from 33
  for(int i=3;i>=0;i--){
    for(int j=3;j>=0;j--){
       currentCell = top_map[i][j];
       currentAvispace = gotocell[currentCell].avispace;
       if((currentAvispace & 0b0001) == 0b0001){//check right
          if(dirc_map[i][j+1] >= 50){
            dirc_map[i][j+1] = dirc_map[i][j] + 1;
          }else {
            dirc_map[i][j+1] = dirc_map[i][j+1];
          }
        }
        if((currentAvispace & 0b0100) == 0b0100){//check down
          if(dirc_map[i+1][j] >= 50){
            dirc_map[i+1][j] = dirc_map[i][j] + 1;
          }else {
            dirc_map[i+1][j] = dirc_map[i+1][j];
          }
        }
        if((currentAvispace & 0b1000) == 0b1000){//check up
          if(dirc_map[i-1][j] >= 50){
            dirc_map[i-1][j] = dirc_map[i][j] + 1;
          }else {
            dirc_map[i-1][j] = dirc_map[i-1][j];
          }
        }
        if((currentAvispace & 0b0010) == 0b0010){//check left
          if(dirc_map[i][j-1] >= 50){
            dirc_map[i][j-1] = dirc_map[i][j] + 1;
          }else {
            dirc_map[i][j-1] = dirc_map[i][j-1];
          }
        }
    }
  }//end for
  




  //print the final dirc map
  for(int i=0;i<4;i++){
   for(int j=0;j<4;j++){
    printf("%d,",dirc_map[i][j]);
   }
   printf("\n");
  }







}//end main



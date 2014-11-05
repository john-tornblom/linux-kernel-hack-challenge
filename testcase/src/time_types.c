#include <stdint.h>
#include "time_types.h"


static int32_t array2[1000];
static int32_t array4[130];
static int32_t array5[13000];
static int32_t arrayP[8000];
static int32_t arrayP3[8000];
static int32_t arrayP5[8000];


void Time_Init(void){
  for (int32_t i = 0; i < 1000; i=i+1){
    array2[i]=i;
  }
  for (int32_t i = 0; i < 130; i=i+1){
    array4[i]=i*2;
  }
  for (int32_t i = 0; i < 13000; i=i+1){
    array5[i]=i*2;
  }
  for (int32_t i = 0; i < 8000; i=i+1){
    arrayP[i]=i;
    arrayP3[i]=i;
    arrayP5[i]=i;
  }
}/*Time_Init*/


// ******************************************************************
// Description: Time consuming function type 1
// Something typical; a small array sorting
// ******************************************************************

void Time_Type1(void){

  int32_t size = 10;
  int32_t a;
  int32_t b;

  int32_t array_to_sort[size];

  for (int32_t i = 0; i < size; i++){
    array_to_sort[i]=size-i;
  }
  
  for (int32_t i = 0; i < size; i++){
    for (int32_t j = 0; j < size-1; j++){
      
      a=array_to_sort[j];
      b=array_to_sort[j+1];
      
      if (b<a){
      array_to_sort[j]=b;
      array_to_sort[j+1]=a;
      }

    }
  }

}/*Time_Type1*/


// ******************************************************************
// Description: Time consuming function type 2
// Memory manipulations
// ******************************************************************

void Time_Type2(void){
  int32_t size = 1000;

  for (int32_t i = 0; i < size; i=i+10){
    array2[i]=i;
  }

  for (int32_t i = 1; i < size; i+=10){
    array2[i]=array2[i-1];
  }

}/*Time_Type2*/


// ******************************************************************
// Description: Time consuming function type 3
// Float calculations
// ******************************************************************

void Time_Type3(void){
  static double d1= 156.1415915;
  static float  f1= 0.4165315656;
  for (int32_t i = 0; i < 10; i++){
    d1 = d1 +(((d1*56.489*d1)-(d1/45.165))/(2+15*d1))/(5000*d1*d1);
    f1 = f1 +(((f1*56.489*f1)-(f1/45.165))/(2+15*f1))/(5000*f1*f1);
  }

}/*Time_Type3*/


// ******************************************************************
// Description: Time consuming function type 4
// Cache investigation; not using L2
// ******************************************************************

void Time_Type4(void){
  for (int32_t i = 10; i < 130; i=i+1){
    array4[i/10]=array4[i]=array4[i-1]+array4[i-2]+array4[i-3]+array4[i-4];
  }

}/*Time_Type4*/


// ******************************************************************
// Description: Time consuming function type 5
// Cache investigation; probably using L2, if present
// ******************************************************************

void Time_Type5(void){
  for (int32_t i = 1000; i < 13000; i=i+100){
    array5[i/1000]=array5[i]+array5[i-100]+array5[i-200]+array5[i-300]+array5[i-400];
  }

}/*Time_Type5*/
void Time_TypeP2(void) {

  /* Low data cache usage */
  for (int32_t i = 0; i < 10; i = i + 1) {
    Time_Type1();
  }
  /* High data cache usage (4kB)*/
  for (int32_t i = 0; i < 8; i = i + 1) {
    for (int32_t j = 0; j < 1000; j = j + 3) {
      arrayP[j] = arrayP[j] + 1;
    }
  }
  /* Low, again */
  for (int32_t i = 0; i < 10; i = i + 1) {
    Time_Type1();
  }
}/*Time_TypeP2*/

void Time_TypeP3(void) {

  /* High data cache usage (4kB)*/
  for (int32_t i = 0; i < 8; i = i + 1) {
    for (int32_t j = 0; j < 1000; j = j + 3) {
      arrayP3[j] = arrayP3[j] + 1;
    }
  }
}/*Time_TypeP3*/

void Time_TypeP4(void) {
  /* Low */
  for (int32_t i = 0; i < 10; i = i + 1) {
    Time_Type1();
  }
}/*Time_TypeP4*/

void Time_TypeP5(void) {

  /* High data cache usage (4kB)*/
  for (int32_t i = 0; i < 8; i = i + 1) {
    for (int32_t j = 0; j < 1000; j = j + 3) {
      arrayP5[j] = arrayP5[j] + 1;
    }
  }
}/*Time_TypeP5*/

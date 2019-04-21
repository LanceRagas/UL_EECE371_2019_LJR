int state = 0;
// when flag == 0, no traffic/ pedestrian light is being used.
int tl_flag = 0;
int pl_flag = 0;
int tl_1 = 0;
int tl_2 = 0;
int pl_1 = 0;
int pl_2 = 0;
int s_1 = 0;
int s_2 = 0;
int btn_1 = 0;
int btn_2 = 0;

void setup() {

}

void tl_switcher(){
  if (tl_1 == 1) {
    tl_1 = 0;
    tl_2 = 1;
  }
  else {
    tl_1 = 0;
    tl_2 = 1;
  }
}

void loop() {

  if (s_1 == 1 && tl_flag == 0){
    tl_flag = 1;
    tl_1 = 1;
    int count = 0;
    for (int i = 0; i <= 140; i++){
      if (btn_2 == 1 && pl_flag ==0){
        pl_flag = 1;
        pl_2 = 1;
      }
      
      if (i == 100){
        tl_1 = 2;
      }
      count = count + 1;
      if (count == 40){
        pl_flag = 1;
        pl_2 = 0;
      }
      delay(500);
    }
    tl_2 = 0;
  }
  
  if (s_2 == 1 && tl_flag == 0){
    tl_flag = 1;
    tl_2 = 1;
    int count = 0;
    for (int i = 0; i <= 140; i++){
      if (btn_1 == 1 && pl_flag ==0){
        pl_flag = 1;
        pl_1 = 1;
      }
      
      if (i == 100){
        tl_2 = 2;
      }
      count = count + 1;
      if (count == 40){
        pl_flag = 1;
        pl_1 = 0;
      }
      delay(500);
    }
    tl_2 = 0;
  }
}

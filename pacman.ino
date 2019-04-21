
int ghost_mov_arr = [[1,15],[1,14],[0,14],[0,13],[1,13],[1,12],[0,12]];

namespace LCD{
  void write(int x, int y, byte c) {}
  void clear() {}
  void update() {}
  void init() {}
}

int pac_arr[2];
int ghost_arr[2];

void setup() {
  Serial.begin(9600);
  
}

void pac_write(int x, int y){
  LCD::write(x,y,0);
}

void ghost_write(int x, int y){
  LCD::write(x,y,1);
}

void set_food(){
  int arr[5][2];
  for (int i = 0; i < 5; i++){
    arr[i][random(0,1), random(1,14)];
  }
  for (int i = 0; i < 5; i++){
    LCD::write(arr[i][1], arr[i][2], 2);
  }
  return arr;
}

void blank_write(int x, int y){
  LCD::write(x, y, 3);
}

// define where they are first, then check if on same spot (pacman ate ghost), then update screen
void loop() {
  Serial.print("Welcome to Pacman game! To play, type 'begin'!");
  on = Serial.read();
  pac_write(0, 0);
  ghost_write(0, 15);
  int arr[5][2] = set_food(); 
  LCD::init();
  LCD::clear();
  int count = 0;
  while (on == "begin"){
    
    Serial.println("w is for up, s is for down, a is for left, d is for down");
  
    // Read in serial, check to see if pac move request does not go off screen
  
    request = Serial.read()
    if (request == "s"){
      if (pac_arr[1] + 1 <= 1){
        pac_arr[1] = pac_arr[1] + 1;
      }
    }
    if (request == "w"){
      if (pac_arr[1] - 1 >= 0){
        pac_arr[1] = pac_arr[1] - 1;
      }
    }
    if (request == "a"){
      if (pac_arr[0] - 1 >= 0){
        pac_arr[0] = pac_arr[0] - 1;
      }
    }
    if (request == "d"){
      if (pac_arr[0] + 1 <= 15){
        pac_arr[0] = pac_arr[0] + 1;
      }
    }
    LCD::clear();
    if (pac_arr[0] == ghost_mov_arr[count][0] && pac_arr[1] == ghost_mov_arr[count][1]){
      pac_write(pac_arr[0], pac_arr[1]);
      on = "end";
    }
    else{
      pac_write(pac_arr[0], pac_arr[1]);
      ghost_write(ghost_mov_arr[count][0], ghost_mov_arr[count][1]);
    }
    LCD::update();
    
    
    count = count + 1;
  }
}  

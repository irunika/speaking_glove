int fingers[] = {A0, A1, A2, A3, A4};
int fingerValues[] = {205, 400, 300, 350, 200};


void setup() {
  Serial.begin(115200);
  pinMode(0, OUTPUT);
  pinMode(1, OUTPUT);

}

void loop() {
    scanFingers();
}


int findSol(int arr[]){
  int ans[4][5] = { {1,0,0,0,0}, {1,1,1,1,1}, {0,1,1,1,1}, {1,0,0,1,1} };

  for(int i=0; i<4; i++){
    bool isMatching=false;
    
    for(int j=0; j<5; j++){
      if(ans[i][j] != arr[j]){
        isMatching = false;
        break;
      }
      else{
        isMatching = true;
      }
    }

    if(isMatching) return i;
  }
  
}

void scanFingers(){
  int temp[5] = {};
  String values = "";
  String output = "";
  for (int i=0 ; i<5; i++){
    int finger = analogRead(fingers[i]);
    values.concat(finger);
    values.concat(" ");

    if(finger<fingerValues[i]) temp[i] = 1;
    else temp[i] = 0;
    output.concat(temp[i]);
  }

  int ans[] = {};
  int sol = findSol(temp);
  switch(sol){
    case 0:
      ans[0] = 0; ans[1] = 0;
//      output.concat("00");
     case 1:
      ans[0] = 0; ans[1] = 1;
//      output.concat("01");
     case 2:
      ans[0] = 1; ans[1] = 0;
//      output.concat("10");
     case 3:
      ans[0] = 1; ans[1] = 1;
//      output.concat("11");
  }


//  digitalWrite(0, ans[0]);
//  digitalWrite(1, ans[1]);

//  Serial.println(values);
//  Serial.println(output);
  Serial.println(output);
  
//  Serial.println();

}


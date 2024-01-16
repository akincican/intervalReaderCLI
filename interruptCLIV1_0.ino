const int MAX_SENSORS = 20;

int sensorPins[MAX_SENSORS];
int numSensors;
int captureCounter=0;
bool isFirstTime=true;
int hitCounter=0;



bool buttonClicked = false;

bool isFirstClick =true;
int* tempArray;
int** dynamicMatrix;
const int button = 2;
int timeStamps[MAX_SENSORS] = {0};
const int led = 15;

void handleInterrupt1();
  void handleInterrupt2();
  void handleInterrupt3();
  void handleInterrupt4();
  void handleInterrupt5();
  void handleInterrupt6();
  void handleInterrupt7();
  void handleInterrupt8();
  void handleInterrupt9();
  void handleInterrupt10();
  void handleInterrupt11();
  void handleInterrupt12();
  void handleInterrupt13();
  void handleInterrupt14();
  void handleInterrupt15();
  void handleInterrupt16();
  void handleInterrupt17();
  void handleInterrupt18();
  void handleInterrupt19();
  void handleInterrupt20();
  
  void (*voidFunctions[])() = { handleInterrupt1, handleInterrupt2, handleInterrupt3,
                                handleInterrupt4, handleInterrupt5, handleInterrupt6,
                                handleInterrupt7, handleInterrupt8, handleInterrupt9,
                                handleInterrupt10, handleInterrupt11, handleInterrupt12,
                                handleInterrupt13, handleInterrupt14, handleInterrupt15,
                                handleInterrupt16, handleInterrupt17, handleInterrupt18,
                                handleInterrupt19, handleInterrupt20};


  void IRAM_ATTR  handleInterrupt1(){
      detachInterrupt(digitalPinToInterrupt(sensorPins[0]));
      timeStamps[0]= micros();
      captureCounter++;
    }
    void IRAM_ATTR handleInterrupt2(){
      detachInterrupt(digitalPinToInterrupt(sensorPins[1]));
      timeStamps[1]= micros();
      captureCounter++;
    }
    void IRAM_ATTR handleInterrupt3(){
      detachInterrupt(digitalPinToInterrupt(sensorPins[2]));
      timeStamps[2]= micros();
      captureCounter++;
    }
    void IRAM_ATTR  handleInterrupt4(){
      detachInterrupt(digitalPinToInterrupt(sensorPins[3]));
      timeStamps[3]= micros();
      captureCounter++;
    }
    void IRAM_ATTR  handleInterrupt5(){
      detachInterrupt(digitalPinToInterrupt(sensorPins[4]));
      timeStamps[4]= micros();
      captureCounter++;
    }
    void IRAM_ATTR  handleInterrupt6(){
      detachInterrupt(digitalPinToInterrupt(sensorPins[5]));
      timeStamps[5]= micros();
      captureCounter++;
    }
    void IRAM_ATTR  handleInterrupt7(){
      detachInterrupt(digitalPinToInterrupt(sensorPins[6]));
      timeStamps[6]= micros();
      captureCounter++;
    }
    void IRAM_ATTR  handleInterrupt8(){
      detachInterrupt(digitalPinToInterrupt(sensorPins[7]));
      timeStamps[7]= micros();
      captureCounter++;
    }
    void IRAM_ATTR  handleInterrupt9(){
      detachInterrupt(digitalPinToInterrupt(sensorPins[8]));
      timeStamps[8]= micros();
      captureCounter++;
    }
    void IRAM_ATTR  handleInterrupt10(){
      detachInterrupt(digitalPinToInterrupt(sensorPins[9]));
      timeStamps[9]= micros();
      captureCounter++;
    }

    void IRAM_ATTR  handleInterrupt11(){
      detachInterrupt(digitalPinToInterrupt(sensorPins[10]));
      timeStamps[10]= micros();
      captureCounter++;
    }
    void IRAM_ATTR handleInterrupt12(){
      detachInterrupt(digitalPinToInterrupt(sensorPins[11]));
      timeStamps[11]= micros();
      captureCounter++;
    }
    void IRAM_ATTR handleInterrupt13(){
      detachInterrupt(digitalPinToInterrupt(sensorPins[12]));
      timeStamps[12]= micros();
      captureCounter++;
    }
    void IRAM_ATTR  handleInterrupt14(){
      detachInterrupt(digitalPinToInterrupt(sensorPins[13]));
      timeStamps[13]= micros();
      captureCounter++;
    }
    void IRAM_ATTR  handleInterrupt15(){
      detachInterrupt(digitalPinToInterrupt(sensorPins[14]));
      timeStamps[14]= micros();
      captureCounter++;
    }
    void IRAM_ATTR  handleInterrupt16(){
      detachInterrupt(digitalPinToInterrupt(sensorPins[15]));
      timeStamps[15]= micros();
      captureCounter++;
    }
    void IRAM_ATTR  handleInterrupt17(){
      detachInterrupt(digitalPinToInterrupt(sensorPins[16]));
      timeStamps[16]= micros();
      captureCounter++;
    }
    void IRAM_ATTR  handleInterrupt18(){
      detachInterrupt(digitalPinToInterrupt(sensorPins[17]));
      timeStamps[17]= micros();
      captureCounter++;
    }
    void IRAM_ATTR  handleInterrupt19(){
      detachInterrupt(digitalPinToInterrupt(sensorPins[18]));
      timeStamps[18]= micros();
      captureCounter++;
    }
    void IRAM_ATTR  handleInterrupt20(){
      detachInterrupt(digitalPinToInterrupt(sensorPins[19]));
      timeStamps[19]= micros();
      captureCounter++;
  }







int findMin(const int arr[], int size) {
    if (size <= 0) {
        // Handle invalid array size
        Serial.print("invalid array size can");
        
        return 0;  // You can choose another value or throw an exception based on your requirements
  }

    int minVal = arr[0];  // Assume the first element is the smallest

    for (int i = 1; i < size; ++i) {
        if (arr[i] < minVal) {
            minVal = arr[i];  // Update minVal if a smaller value is found
    }
  }

    return minVal;
}

void clearSerialMonitor() {
  for (int i = 0; i < 50; ++i) {
    Serial.println();  // Print newline characters to clear the screen
  }
}



void subtractValueFromArray(int arr[], int size, int value) {
    for (int i = 0; i < size; ++i) {
        arr[i] -= value;
    }
}
void printArray(const int arr[], int size) {
    
    Serial.println("---------");
    for (int i = 0; i < size; ++i) {
      
        Serial.print("sensor ");
        Serial.print(i+1);
        Serial.print(":   ");
        Serial.print(arr[i]);
        Serial.println(" ");
    }
    Serial.println("---------");
    Serial.println("");
      Serial.println("");
}

void userListener(){
  clearSerialMonitor();
  Serial.println("Enter the number of sensors (2 to 20):");          // Prompt the user to enter the number of sensors (1 to 10)
  while (!Serial.available()) {}
    numSensors = Serial.parseInt();

    
  if (numSensors < 2 || numSensors > MAX_SENSORS) {                                          // Validate the entered number of sensors
    Serial.println("Invalid number of sensors. Please enter a number between 2 and 20.");
    ESP.restart();
  }  
  for (int i = 0; i < numSensors; ++i) {                                // Prompt the user to enter the pin numbers
    Serial.print("Enter pin number for Sensor ");
    Serial.print(i + 1);
    Serial.println(":");
    while (Serial.available()) {
      Serial.read();
    }
    while (!Serial.available()) {}
      sensorPins[i] = Serial.parseInt();
    }

    clearSerialMonitor();
    Serial.println("Entered sensor pin numbers:");
    for (int i = 0; i < numSensors; ++i) {
        Serial.print("Sensor ");
        Serial.print(i + 1);
        Serial.print(" Pin: ");
        Serial.println(sensorPins[i]);
    }
    Serial.println("-------- ");
    Serial.println("please press button before hit");
}
void matrixPrinter(int** matrix, int rows, int cols) {
    
  Serial.print('\t');
      for(int i =0; i< cols; i++){
          Serial.print("sensor");
          Serial.print(i+1);
          Serial.print('\t');


      }

  Serial.println();
      for (int i = 0; i < rows; ++i) {
          Serial.print("HIT");
          Serial.print(i+1);
          Serial.print('\t');
          
          
          for (int j = 0; j < cols; ++j) {
              
              Serial.print(matrix[i][j]);
              Serial.print('\t'); // Add a tab for formatting
          }
          Serial.println(); // Move to the next row
      }
}
void fillMatrixWithZeros(int** dynamicMatrix, int numRows, int numCols) {
    for (int i = 0; i < numRows; ++i) {
        for (int j = 0; j < numCols; ++j) {
            dynamicMatrix[i][j] = 0;
        }
    }
}
void writeArrayToRow(int** matrix, const int arr[], int numRows, int numCols, int rowIndex) {
    for (int j = 0; j < numCols; ++j) {
        matrix[rowIndex][j] = arr[j];
    }
}










void setup() {


  pinMode(button, INPUT);
  pinMode(led, OUTPUT);
  digitalWrite(led, LOW);

    // Your setup code here
    Serial.begin(115200);
    delay(1000);
    numSensors = 4;
    sensorPins[0] = 4;
    sensorPins[1] = 5;
    sensorPins[2] = 18;
    sensorPins[3] = 19;                      // Prompt the user to enter pin numbers for each sensor

    
   
    // Print the entered pin numbers for confirmation
    
}

void loop() {
    // Access sensor values using sensorPins[0], sensorPins[1], ..., sensorPins[numSensors - 1]
  while(isFirstTime){
    dynamicMatrix = new int*[numSensors];
    for (int i = 0; i < numSensors; ++i) {
      dynamicMatrix[i] = new int[numSensors];
    }
    fillMatrixWithZeros(dynamicMatrix,numSensors,numSensors);
    isFirstTime =false;
    tempArray = new int[numSensors];
    for(int i =0; i<numSensors; i++){
      tempArray[i]=0;
    }


  }
  
  if(Serial.available()){

    String userInput = Serial.readString();



    if(userInput.equals("reset")){
        reset();      
    }
    if(userInput.equals("restart")){
        restart();      
    }
    if(userInput.equals("ready")){
      if(isFirstClick){
      isFirstClick =false;
    }
     digitalWrite(led, HIGH);
 //     delay(200);
      for(int i =0 ;i< numSensors; i++){
      timeStamps[i]=0;
 //     Serial.print("pin ");
   //   Serial.print(sensorPins[i]);
   //   Serial.println(" attached");
      attachInterrupt(digitalPinToInterrupt(sensorPins[i]),voidFunctions[i] , HIGH);
      
    }
      Serial.print("wait");




      
    }
  }

  if(buttonClicked){
    if(isFirstClick){
      isFirstClick =false;
        clearSerialMonitor();
    }
      delay(200);
      buttonClicked = false;
      for(int i =0 ;i< numSensors; i++){
      timeStamps[i]=0;
 //     Serial.print("pin ");
   //   Serial.print(sensorPins[i]);
   //   Serial.println(" attached");
      attachInterrupt(digitalPinToInterrupt(sensorPins[i]),voidFunctions[i] , HIGH);
      
    }
    clearSerialMonitor();
      Serial.println(" READY FOR SIGNALS");
      digitalWrite(led, HIGH);
      
  }

  if(captureCounter==numSensors){
 //     Serial.println(captureCounter);
    captureCounter=0;
    buttonClicked=false;

    hitCounter++;
    /*
    Serial.print("captureCounter");
    Serial.println(captureCounter);
    Serial.print("numSensors");
    Serial.println(numSensors);
    Serial.print("hitCounter");
    Serial.println(hitCounter);
    */
    for(int i =0;i<numSensors ; i++){
        tempArray[i]=timeStamps[i];
        timeStamps[i]=0;
    }
    int min = findMin(tempArray, numSensors);

 //   Serial.print("minVal: ");
 //   Serial.println(min);
 //   printArray(tempArray, numSensors);
    subtractValueFromArray(tempArray, numSensors, min);
    


  



    writeArrayToRow(dynamicMatrix,tempArray,numSensors,numSensors,hitCounter-1);

     
    clearSerialMonitor();

    Serial.print("results of hit ");
    Serial.print(hitCounter);
    Serial.println(": ");
    printArray(tempArray,numSensors);
    digitalWrite(led, LOW);
    
        


    if(hitCounter==numSensors){
      clearSerialMonitor();
      Serial.println("The experiment is over, here are the results:");
      Serial.println("------------------------------");
      matrixPrinter(dynamicMatrix,numSensors,numSensors);
      Serial.println("------------------------------");
      Serial.println("please press any key for restart");
      while (Serial.available()) {
        Serial.read();
      }
      while (!Serial.available()) {}
      ESP.restart();
    }else{
        Serial.println("please press button before hit");


    } 
  }


}

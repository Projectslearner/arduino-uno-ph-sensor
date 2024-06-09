/*
    Project name : pH sensor
    Modified Date: 09-06-2024
    Code by : Projectslearner
    Website : https://projectslearner.com/learn/arduino-uno-ph-sensor
*/

float calibration_value = 21.34;
int phval = 0; 
unsigned long int avgval; 
int buffer_arr[10], temp;

void setup() 
{
  Serial.begin(9600); // Initialize serial communication
  delay(2000); // Wait for the serial monitor to open
  Serial.println("Hi Projectslearner fam...");
}

void loop() 
{
  for(int i = 0; i < 10; i++) 
  {
    buffer_arr[i] = analogRead(A1);
    delay(30);
  }

  // Sort the buffer array
  for(int i = 0; i < 9; i++) {
    for(int j = i + 1; j < 10; j++) {
      if(buffer_arr[i] > buffer_arr[j]) {
        temp = buffer_arr[i];
        buffer_arr[i] = buffer_arr[j];
        buffer_arr[j] = temp;
      }
    }
  }

  // Average the middle 6 readings
  avgval = 0;
  for(int i = 2; i < 8; i++)
    avgval += buffer_arr[i];

  float volt = (float)avgval * 5.0 / 1024 / 6;
  float ph_act = -5.70 * volt + calibration_value;

  // Print the pH value to the serial monitor
  Serial.print("pH Value: ");
  Serial.println(ph_act);

  delay(1000);
}

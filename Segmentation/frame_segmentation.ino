#include "frame_array.h"  // your 64x64 uint8_t frame data

uint8_t output[64][64];

void setup() {
  Serial.begin(9600);
  delay(1000); // Wait for Serial Monitor to open

  // 1. Calculate mean
  uint32_t sum = 0;
  for (int i = 0; i < 64; i++) {
    for (int j = 0; j < 64; j++) {
      sum += frame[i][j];
    }
  }
  float mean = sum / 4096.0; // 64 x 64

  // 2. Optional: Calculate standard deviation (for smarter thresholding)
  float std_sum = 0;
  for (int i = 0; i < 64; i++) {
    for (int j = 0; j < 64; j++) {
      float diff = frame[i][j] - mean;
      std_sum += diff * diff;
    }
  }
  float stddev = sqrt(std_sum / 4096.0);

  // 3. Use adaptive threshold
  uint8_t threshold = (uint8_t)(mean + 0.5 * stddev);  // or just use `mean`

  // 4. Apply threshold
  for (int i = 0; i < 64; i++) {
    for (int j = 0; j < 64; j++) {
      output[i][j] = (frame[i][j] > threshold) ? 255 : 0;
    }
  }

  // 5. Send to PC
  Serial.println("Processed Frame (0/255):");
  for (int i = 0; i < 64; i++) {
    for (int j = 0; j < 64; j++) {
      Serial.print(output[i][j]);
      Serial.print(',');
    }
    Serial.println();
  }
}

void loop() {
  // Nothing here
}

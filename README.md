# 🎥 Video Segmentation & Compression on STM32F412

This project demonstrates real-time **video segmentation** and **compression** on the STM32F412 Nucleo-144 board, making it suitable for mobile and edge computing applications.

---

## 👨‍💻 Team Members
- **Satyam Sharma** – B22CS047  
- **Suhani Yadav** – B22CS051

---

## 📌 Objectives
- Convert grayscale video frames to a format compatible with STM32 microcontrollers.
- Perform image segmentation using adaptive thresholding.
- Apply Run-Length Encoding (RLE) for frame compression.
- Transmit processed data from STM32 to a PC via serial communication.

---

## 🧠 Techniques Used

### ✅ Frame Preparation
- Input video frames are resized to **64x64** pixels and converted to grayscale.
- Frames are stored in the STM32 as a 2D `uint8_t` array in a header file `frame_array.h`.

### ✅ Adaptive Thresholding (Segmentation)
- Mean and standard deviation of pixel intensities are calculated.
- Threshold = `mean + 0.5 * stddev`.
- Pixels > threshold → 255; else → 0 (binary segmentation).

### ✅ Run-Length Encoding (Compression)
- Compresses the frame by replacing runs of the same pixel with `[value, count]`.
- Efficient for binary or low-variation grayscale images.

---

## 🔌 Serial Communication
- Baud Rate: **115200**
- Port: **COM23** (adjust as needed)
- Output is sent via UART to a Python script on the PC that stores the result.

---

## 📁 File Structure

├── frame_array.h # Grayscale 64x64 frame data ├── segmentation.ino # STM32 sketch for adaptive thresholding ├── compression_rle.ino # STM32 sketch for RLE compression ├── read_serial.py # Python script to receive serial data ├── README.md # Project documentation



---

## 🛠️ How to Use

### ▶ STM32 Side
1. Flash `segmentation.ino` or `compression_rle.ino` to STM32F412 using Arduino IDE.
2. Ensure the frame data is stored in `frame_array.h`.

### ▶ PC Side
1. Connect to the STM32 via COM port.
2. Run the Python script to receive and save the data:

python read_serial.py
🔗 Links
📽️ Working Demo Video:
👉 Click to Watch

💻 GitHub Repository:
https://github.com/your-username/video-segmentation-compression-stm32

✅ Future Enhancements
Integrate with a real-time camera module like OV7670.

Display received images directly on the PC.

Implement more advanced compression like Huffman or DCT.

Process video streams instead of static frames.


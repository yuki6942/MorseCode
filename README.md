# Morse Code Translator in C

This is a simple Morse code translator written in C.  
It can convert **text to Morse code** and **Morse code to text**.

## 💡 Features

- Translate letters (A–Z) and numbers (0–9)
- Supports both directions:
  - **Text → Morse**
  - **Morse → Text**
- Simple console interface
- Uses standard C (no external libraries)

## 🛠 How It Works

- A mapping table connects each character to its Morse code equivalent.
- For **text input**, each character is matched to its Morse code.
- For **Morse input**, the Morse symbols are matched back to characters.
- Words are separated by `/` in Morse (or three spaces, depending on style).

## ▶️ How to Compile & Run

```bash
gcc morse.c -o morse
./morse

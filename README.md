# Encryption and Decryption Program

## Overview

This program provides an interactive menu-driven interface for encrypting and decrypting textual messages using multi-layer encryption. Users can configure encryption keys, key phrases, and choose from various encryption methods to secure their messages.

---

## Features

- **Input Validation**:
  - Ensures all keys, phrases, and inputs are valid and secure.
  - Prevents invalid inputs from causing errors.
- **Multiple Encryption Techniques**:
  - **Layer 1**: Shifts characters in the message.
    - Fixed shift by 13.
    - Dynamic shift based on user-provided keys.
  - **Layer 2**: Encodes messages using a key phrase.
  - **Chain Encryption**: Combines both layers for enhanced security.
- **Decryption**:
  - Reverses encryption to restore the original message.
- **Interactive Menu**:
  - Easy-to-use interface for managing encryption and decryption.

---

## How It Works

### Layer 1: Character Shifting

- **Method 1**: Shifts each character in the message by 13 positions in the alphabet.
- **Method 2**: Dynamically shifts characters based on two user-provided keys.

### Layer 2: Key Phrase Encryption

- Uses a key phrase to generate a decoding key.
- Shifts characters based on the key's letters.

### Chain Encryption

- Combines Layer 1 and Layer 2 encryption for additional security.

---

## Usage

### Menu Options

1. **Set Encryption Key 1**: Define the first key for Layer 1 encryption.
2. **Set Encryption Key 2**: Define the second key for Layer 1 encryption.
3. **Set Key Phrase**: Define a key phrase for Layer 2 encryption.
4. **Select Encryption Method**:
   - Choose from Layer 1, Layer 2, or Chain Encryption.
   - For Layer 1, decide between "Shift by 13" or "Shift by mixed keys."
5. **Encrypt Message**:
   - Input a message and encrypt it using the selected method.
6. **Decrypt Message**:
   - Input an encrypted message and decrypt it to retrieve the original text.
7. **Exit Program**: Quit the application.

---

### Sample Workflow

1. Run the program.
2. Set `Encryption Key 1` and `Encryption Key 2`.
3. Set a `Key Phrase`.
4. Select the encryption method:
   - Choose Layer 1, Layer 2, or Chain Encryption.
   - For Layer 1, select "Shift by 13" or "Shift by mixed keys."
5. Enter a message to encrypt and view the encrypted result.
6. Input the encrypted message to decrypt it back to its original form.

---

## Input Validation

The program ensures:

- Encryption keys contain only valid characters (letters and spaces).
- Key phrases are composed of valid characters (letters, digits, and spaces).
- Numeric inputs for menu options and encryption methods are within valid ranges.

---

## Compilation

To compile the program:

```bash
g++ -std=c++17 -o encryption_program encryption_program.cpp
```

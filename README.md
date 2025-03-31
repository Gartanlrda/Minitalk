# Minitalk

## Overview
Minitalk is a project from the 42 curriculum that implements a simple client-server messaging system using UNIX signals. The client sends a message to the server by encoding it in binary, and the server decodes and prints it in the terminal.

## Features
- Uses `SIGUSR1` and `SIGUSR2` signals for communication.
- Sends messages from the client to the server using binary encoding.
- Handles signal interruptions and ensures correct message delivery.
- Supports sending full ASCII messages.

## How It Works
- The client converts each character of the message into its binary representation.
- It sends bits one by one to the server using `SIGUSR1` (for bit 0) and `SIGUSR2` (for bit 1).
- The server catches the signals and reconstructs the message character by character.

## Notes
- The project adheres to the 42 norm and does not use external libraries beyond standard system calls.
- Error handling ensures invalid PIDs or incorrect arguments are managed gracefully.

## License
This project is developed as part of my education at 42 and follows the school's policies regarding open-source sharing.

## Contact
For any questions or suggestions, feel free to open an issue or reach out!

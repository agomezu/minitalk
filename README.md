# Minitalk

Minitalk is a simple client-server communication system that uses UNIX signals for transmitting data.

## Overview

The project includes two programs: a server and a client. The server receives and displays messages sent by the client. The client sends a message to the server as a command-line argument.

The communication between the client and server is achieved solely through UNIX signals. Specifically, the client sends each bit of the message to the server using either a `SIGUSR1` or `SIGUSR2` signal, representing '0' and '1' respectively. The server assembles the bits into characters and prints the resulting message.

## Prerequisites

- A Unix-like operating system
- GCC compiler
- Make

## Installation

Clone the repository and navigate to the directory:

```bash
git clone https://github.com/agomezu/minitalk.git
cd minitalk
```

Compile the programs using Make:

```bash
make all
```

This will create two executables, `server` and `client`.

## Usage

First, start the server

```bash
./server
```


The server will display its process ID (PID) upon starting.

Next, in a separate terminal window, send a message from the client to the server:

```bash
./client <PID> "Your message here"
```


Replace `<PID>` with the PID displayed by the server, and `"Your message here"` with the message you want to send.

The server will display the received message.


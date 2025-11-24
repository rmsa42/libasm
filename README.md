# Libasm
This is a learning ASM (NASM x86_64) project.

## Table of Contents
1. [Overview](#overview)
2. [Project Structure](#project-structure)
3. [How to Use](#how-to-use)

## Overview
Libasm is a small library of functions written in NASM x86_64. It's purpose is to learn how to write NASM for x86_64

## Project Structure
- `Makefile/`: Projetc build tool

## How to Use
1. Clone the repository.
2. Compile the library: `make`. 
3. Link the library to your program: `gcc example.c -L. -lasm`.

#pragma once
#include <time.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

#define CODE_SIZE 8


void createCode(char[]);

int checkCode(char[], char[]);

int changeCode(char[], char[]);
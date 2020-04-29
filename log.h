#include <iostream>
#include <stdio.h>

using namespace std;

#define SEE(fmt, ...)   printf("[%d]: " fmt "\n" , __LINE__, ##__VA_ARGS__)
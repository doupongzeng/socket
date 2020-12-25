#include <iostream>
#include <stdio.h>
#include <time.h>
#include <chrono>

using namespace std;

#define SEE(fmt, ...)   printf("[%d]: " fmt "\n" , __LINE__, ##__VA_ARGS__)


string TimeNow(){
    auto t = chrono::system_clock::now();
    time_t now = chrono::system_clock::to_time_t(t);
    struct tm* t_n =  gmtime(&now);
    auto hour = to_string(t_n->tm_hour);
    auto min = to_string(t_n->tm_min);
    auto sec = to_string(t_n->tm_sec);
    string s;
    s = hour + ":" + min + ":" + sec;
    return s;
}
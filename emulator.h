#ifndef __emulator__
#define __emulator__
#include <bits/stdc++.h>
using namespace std;

string cutLast(string line);
string cutSpaces(string line);
int getVal(string line);
int changePCjmp(int i, string line);
void parseStore(string line);
void parseLoad(string line);
void parseBranch(string line);
void parseJump(string line);
void parseCall(string line);
void parseReturn();
void parseLine(string line);
void compileCode();
void scanCode();
void readFile(string name);
void runFile(string name);
void TestCases();
void UserCases();
void interaction();
void reset();

#endif
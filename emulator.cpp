#include "emulator.h"
using namespace std;

bool debugging;
map<string,int> functions; //function addresses
vector<string> lines; //code
map<string, int> registers; //registers
char st[20004]; //memory stack

int main(){
    interaction();
}
void reset(){
    lines.clear();
    functions.clear();
    registers.clear();
    registers["SP"] = 20004;
    debugging = false;
}
void interaction(){
    cout << "Hi!" << endl;
    cout << "This is Assembly Emulator." << endl;
    char ans;
    while(true){
        cout << "Do you want to run tests? Y/n" << endl;
        cin >> ans;
        if(ans == 'Y' || ans == 'y' || ans == 'N' || ans == 'n'){
            if(ans == 'Y' || ans == 'y')
                TestCases();
            while(true){
                cout << "Do you want to try to run your assembly code? Y/n" << endl;
                cin >> ans;
                if(ans == 'Y' || ans == 'y' || ans == 'N' || ans == 'n'){
                    if(ans == 'Y' || ans == 'y')
                        UserCases();
                    break;
                }else{
                   cout << "Please enter relevant symbol." << endl;
                }
            }
            cout << "Thank you! Bye bye ;)" << endl;
            break;
        }else{
            cout << "Please enter relevant symbol." << endl;
        }
    }
}
void TestCases(){
    int counter = 0;
    cout << "Every test case has its original c version. You can check it in 'Tests' folder." << endl;
    cout << "Most of them are similar to handout examples." << endl;
    cout << "STARTING TESTING:" << endl;
    cout << "------------------SIMPLE VARIABLES------------------" << endl;
    runFile("Tests/SimpleVariables/SimpleVariables1.txt");
    cout << "TEST 1: CHECKING 'i == 7'" << endl;
    if(*((int*)(st + 19996)) == 7){
        counter++;
        cout << "SUCCESS!" << endl;
    }else{
        cout << "FAILED" << endl;
    }
    runFile("Tests/SimpleVariables/SimpleVariables2.txt");
    cout << "TEST 2: CHECKING 'ch == 'A''" << endl;
    if(st[19999] == 'A'){
        counter++;
        cout << "SUCCESS!" << endl;
    }else{
        cout << "FAILED" << endl;
    }
    cout << "------------------TYPE CONVERSIONS------------------" << endl;
    runFile("Tests/TypeConversions/TypeConversions1.txt");
    cout << "TEST 3: CHECKING 'ch == 'A' && i = 65'" << endl;
    if(*((int*)(st + 19995)) == 65 && st[19999] == 'A'){
        counter++;
        cout << "SUCCESS!" << endl;
    }else{
        cout << "FAILED" << endl;
    }
    runFile("Tests/TypeConversions/TypeConversions2.txt");
    cout << "TEST 4: CHECKING 'ch == 1 && i = 1025'" << endl;
    if(*((int*)(st + 19995)) == 1025 && st[19999] == 1){
        counter++;
        cout << "SUCCESS!" << endl;
    }else{
        cout << "FAILED" << endl;
    }
    cout << "------------------CONTROL STRUCTURES------------------" << endl;
    runFile("Tests/ControlStructures/ControlStructures1.txt");
    cout << "TEST 5: CHECKING 'i == 10'" << endl;
    if(*((int*)(st + 19996)) == 10){
        counter++;
        cout << "SUCCESS!" << endl;
    }else{
        cout << "FAILED" << endl;
    }
    runFile("Tests/ControlStructures/ControlStructures2.txt");
    cout << "TEST 6: CHECKING 'ch == 'K' && i = 10'" << endl;
    if(*((int*)(st + 19995)) == 10 && st[19999] == 'K'){
        counter++;
        cout << "SUCCESS!" << endl;
    }else{
        cout << "FAILED" << endl;
    }
    runFile("Tests/ControlStructures/ControlStructures3.txt");
    cout << "TEST 7: CHECKING 'ch == 'n' && i = 10'" << endl;
    if(*((int*)(st + 19995)) == 10 && st[19999] == 'n'){
        counter++;
        cout << "SUCCESS!" << endl;
    }else{
        cout << "FAILED" << endl;
    }
    cout << "------------------STRUCTURES------------------" << endl;
    runFile("Tests/Structures/Structures1.txt");
    cout << "TEST 8: CHECKING 'x.a == 40000 && x.f = -25536'" << endl;
    if(*((short*)(st + 19998)) == -25536 && *((int*)(st + 19990)) == 40000){
        counter++;
        cout << "SUCCESS!" << endl;
    }else{
        cout << "FAILED" << endl;
    }
    runFile("Tests/Structures/Structures2.txt");
    cout << "TEST 9: CHECKING 'arr[15] = 7'" << endl;
    if(*((int*)(st + 19960)) == 7){
        counter++;
        cout << "SUCCESS!" << endl;
    }else{
        cout << "FAILED" << endl;
    }
    runFile("Tests/Structures/Structures3.txt");
    cout << "TEST 10: CHECKING 'a[i].f = 10'" << endl;
    if(*((short*)(st + 19604)) == 10){
        counter++;
        cout << "SUCCESS!" << endl;
    }else{
        cout << "FAILED" << endl;
    }
    cout << "------------------CALLING FUNCTIONS------------------" << endl;
    runFile("Tests/CallingFunctions/CallingFunctions1.txt");
    cout << "TEST 11: CHECKING 'Add(2, 3) + 1 == 6'" << endl;
    if(*((int*)(st + 19996)) == 6){
        counter++;
        cout << "SUCCESS!" << endl;
    }else{
        cout << "FAILED" << endl;
    }
    runFile("Tests/CallingFunctions/CallingFunctions2.txt");
    cout << "TEST 12: CHECKING 'local.denominator = 1 && param.denominator = 2'" << endl;
    if(*((int*)(st + 19988)) == 2 && *((int*)(st + 19976)) == 1){
        counter++;
        cout << "SUCCESS!" << endl;
    }else{
        cout << "FAILED" << endl;
    }
    cout << "------------------RECURSION------------------" << endl;
    runFile("Tests/Recursion/Recursion1.txt");
    cout << "TEST 13: CHECKING 'fibonacci(5) == 5 && fibonacci(10) == 55'" << endl;
    if(*((int*)(st + 19996)) == 55 && *((int*)(st + 19992)) == 5){
        counter++;
        cout << "SUCCESS!" << endl;
    }else{
        cout << "FAILED" << endl;
    }
    runFile("Tests/Recursion/Recursion2.txt");
    cout << "TEST 14: CHECKING 'factorial(10) == 720'" << endl;
    if(*((int*)(st + 19996)) == 720){
        counter++;
        cout << "SUCCESS!" << endl;
    }else{
        cout << "FAILED" << endl;
    }
    runFile("Tests/Recursion/Recursion3.txt");
    cout << "TEST 15: CHECKING 'fastPow(5, 6) == 15625'" << endl;
    if(*((int*)(st + 19996)) == 15625){
        counter++;
        cout << "SUCCESS!" << endl;
    }else{
        cout << "FAILED" << endl;
    }
    cout << "PASSED " << counter << "/15 TESTS." << endl;
}
void runFile(string name){
    reset();
    readFile(name);
    scanCode();
    compileCode();
}
string cutLast(string line){
    string ans = "";
    for(int i = 0; i < line.length() - 1; i++)
        ans += line[i];
    return ans;
}
void readFile(string name){
    ifstream file;
    file.open(name);
    string line;
    lines.push_back("Call<main>");
    while(getline(file,line))
        lines.push_back(cutLast(cutSpaces(line)));
    lines[lines.size() - 1] += 'T';
}
void UserCases(){
    reset();
    cout << "Use 'Handout 12' to write relevant assembly code." << endl;
    cout << "When you will finish your input please enter special symbol: '$'" << endl;
    cout << "Please enter the code:" << endl;
    string speacialSymbol = "$";
    string line;
    lines.push_back("Call<main>");
    while(true){
        getline(cin, line);
        if(line == speacialSymbol)
            break;
        lines.push_back(cutSpaces(line));
    }
    debugging = true;
    cout << "Now you are in debugging mode." << endl;
    cout << "Instruction lines are numbered from 1, because it makes easier to follow jumps." << endl;
    cout << "You will see every step what emulator does." << endl;
    scanCode();
    compileCode();
    cout << "Your code compiled successfully!" << endl;
}

void scanCode(){
    for(int i = 0; i < lines.size(); i++){
        if(lines[i][lines[i].length() - 1] == ':'){
            string func = "";
            for(int j = 0; j < lines[i].length() - 1; j++)
                func += lines[i][j];
            functions[func] = i;
        }
    }
}

void compileCode(){
    registers["PC"] = -1;
    while(true){
        registers["PC"]++;
        int ind = registers["PC"];
        if(ind == 1)
            break;
        parseLine(lines[ind]);
    }
}

string cutSpaces(string line){
    string ans = "";
    for(int i = 0; i < line.length(); i++)
        if(line[i] != 32)
            ans += line[i];
    return ans;
}
void parseLine(string line){
    if(line == "RET")
        parseReturn();
    else if(line[0] == 'R' || line[0] == 'S' || line[0] == 'P')
        parseLoad(line);
    else if(line[0] ==  'M')
        parseStore(line);
    else if(line[0] == 'C')
        parseCall(line);
    else if(line[0] == 'B')
        parseBranch(line);
    else
        parseJump(line);  
}
void parseReturn(){
    registers["PC"] = getVal("M[SP]");
    registers["SP"] += 4;
    if(debugging)
        cout << "jumped on instruction number: " << registers["PC"] << endl;
}
int changePCjmp(int i, string line){
    int oldI = i;
    while(line[i] < '0' || line[i] > '9')
        i++;
    string jmpPC = "";
    for(int j = i; j < line.length(); j++)
        jmpPC += line[j];
    int numJmp = getVal(jmpPC);
    numJmp /= 4;
    jmpPC = "";
    for(int j = oldI; j < i; j++)
        jmpPC += line[j];
    jmpPC += to_string(numJmp);
    int newPC = getVal(jmpPC);
    newPC--;
    return newPC;
}
void parseBranch(string line){
    int i = 3;
    string left = "";
    string right = "";
    while (line[i] != ','){
        left += line[i];
        i++;
    }
    i++;
    while (line[i] != ','){
        right += line[i];
        i++;
    }
    i++;
    int newPC = changePCjmp(i, line);
    int leftVal = getVal(left);
    int rightVal = getVal(right);
    if(line[1] == 'L'){
        if(line[2] == 'T'){
            if(leftVal < rightVal)
                registers["PC"] = newPC;
        }else{
            if(leftVal <= rightVal)
                registers["PC"] = newPC;
        }
    }else if(line[1] == 'G'){
        if(line[2] == 'T'){
            if(leftVal > rightVal)
                registers["PC"] = newPC;
        }else{
            if(leftVal >= rightVal)
                registers["PC"] = newPC;
        }
    }else if(line[1] == 'E'){
        if(leftVal == rightVal)
            registers["PC"] = newPC;
    }else{
        if(leftVal != rightVal)
            registers["PC"] = newPC;
    }
}
void parseJump(string line){
    int newPC = changePCjmp(3, line);
    registers["PC"] = newPC;
    if(debugging)
        cout << "jumped on instruction number: " << registers["PC"] << endl;
}
void parseCall(string line){
    string func = "";
    for(int i = 5; i < line.length() - 1; i++)
        func += line[i];
    registers["SP"] -= 4;
    parseStore("M[SP]=PC");
    registers["PC"] = functions[func];
    if(debugging)
        cout << "called " << func << endl;
}

void parseStore(string line){
    int i;
    string registerTo = "";
    for(i = 2; i < line.length(); i++){
        if(line[i] == ']')
            break;
        registerTo += line[i];
    }
    i += 2;
    string loadFrom = "";
    for(int j = i; j < line.length(); j++)
        loadFrom += line[j];
    int toInd = getVal(registerTo);
    int num = getVal(loadFrom);
    //case: .1 || .2
    if(line[i] == '.'){
        i++;
        if(line[i] == '1'){
            *((unsigned char*)(st + toInd)) = (unsigned char)num;
            num = (unsigned char)num;
        }else{
            *((short*)(st + toInd)) = (short)num;
            num = short(num);
        }
    }else{
        *((int *)(st + toInd)) = num;
    }
    if(debugging)
        if(toInd != 20000)
            cout << "stored " << num << " on index " << toInd << endl;
}

void parseLoad(string line){
    int i;
    string registerTo = "";
    for(i = 0; i < line.length(); i++){
        if(line[i] == '=')
            break;
        registerTo += line[i];
    }
    i++;
    string loadFrom = "";
    for(int j = i; j < line.length(); j++)
        loadFrom += line[j];
    registers[registerTo] = getVal(loadFrom);
    if(debugging)
        cout << "loaded " << registers[registerTo] << " in " << registerTo << endl;
}

int getVal(string line){
    //case: .1 || .2
    if(line[0] == '.'){
        string newLine = "";
        for(int i = 2; i < line.length(); i++)
            newLine += line[i];
        int num = getVal(newLine);
        if(line[1] == '1')
            return (unsigned char)num;
        return (short)num;
    }
    //case: M[]
    if(line[0] == 'M'){
        string newLine = "";
        for(int i = 2; i < line.length() - 1; i++)
            newLine += line[i];
        int num = getVal(newLine);
        return *((int*)(st + num));
    }
    //case: x + y
    int i;
    for(i = 0; i < line.length(); i++)
        if(line[i] == '+' || line[i] == '-' || line[i] == '*' || line[i] == '/')
            break;
    if(i != line.length()){
        string r = "";
        string l = "";
        for(int j = 0; j < i; j++)
            r += line[j];
        for(int j = i + 1; j < line.length(); j++)
            l += line[j];
        int numR = getVal(r);
        int numL = getVal(l);
        if(line[i] == '+')
            return numR + numL;
        if(line[i] == '-')
            return numR - numL;
        if(line[i] == '*')
            return numR * numL;
        return numR / numL;
    }
    if(line[0] == 'R' || line[0] == 'S' || line[0] == 'P')
        return registers[line];
    int num = 0;
    for(i = 0; i < line.length(); i++){
        if(line[0] == '-')
            continue;
        num *= 10;
        num += line[i] - '0';
    }
    if(line[0] == '-')
        num *= (-1);
    return num;
}

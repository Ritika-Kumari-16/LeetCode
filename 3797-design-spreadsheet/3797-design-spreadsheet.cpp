#include<bits/stdc++.h>
using namespace std;
bool isStringDigit(string str){
    for(auto it:str){
        if(!isdigit(it)) return false;
    }
    return true;
}
class Spreadsheet {
public:
vector<vector<int>>spsheet;
    Spreadsheet(int rows) {
        spsheet= vector<vector<int>>(rows,vector<int>(26,0));
    }
    
    void setCell(string cell, int value) {
        int colno= cell[0]-'A';
        int rowno= stoi(cell.substr(1));
        spsheet[rowno-1][colno]=value;
    }
    
    void resetCell(string cell) {
        int colno= cell[0]-'A';
        int rowno= stoi(cell.substr(1));
        spsheet[rowno-1][colno]=0;
    }
    
    int getValue(string formula) {
        string cell1;
        string cell2;
        int val1=0;
        int val2=0;
        int i=1;
        while(i<formula.size() && formula[i]!='+'){
            cell1+=formula[i];
            i++;
        }
        i++;
        while(i<formula.size()){
            cell2+=formula[i];
            i++;
        }
        if(isStringDigit(cell1)){
            val1= stoi(cell1);
        }
        else{
            int colno= cell1[0]-'A';
            int rowno= stoi(cell1.substr(1));
            val1=spsheet[rowno-1][colno];
        }
        if(isStringDigit(cell2)){
            val2=stoi(cell2);
        }
        else{
            int colno= cell2[0]-'A';
            int rowno= stoi(cell2.substr(1));
            val2=spsheet[rowno-1][colno];
        }
        return val1+val2;
    }
};

/**
 * Your Spreadsheet object will be instantiated and called as such:
 * Spreadsheet* obj = new Spreadsheet(rows);
 * obj->setCell(cell,value);
 * obj->resetCell(cell);
 * int param_3 = obj->getValue(formula);
 */
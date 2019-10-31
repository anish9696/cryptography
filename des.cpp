#include<iostream>
#include<map>
#include<string.h>
#include<bits/stdc++.h>
using namespace std;
typedef map<char,string> hex1;
typedef map<string,char> bin1;

string permute(string k, int* arr, int n){
    string per="";
    for(int i=0; i<n ; i++){
        per+= k[arr[i]-1];
    }
    return per;
}
string shift_left(string k, int shifts){
    string s="";
    for(int i=0; i<shifts; i++){
        for(int j=1; j<28; j++){
            s+= k[j];
        }
        s+= k[0];
        k= s;
        s="";
    }
    return k;
}
string bin2hex(string s)
    {
        bin1 binmap;
    binmap.insert(pair<string,char>("0000",'0'));
    binmap.insert(pair<string,char>("0001",'1'));
    binmap.insert(pair<string,char>("0010",'2'));
    binmap.insert(pair<string,char>("0011",'3'));
    binmap.insert(pair<string,char>("0100",'4'));
    binmap.insert(pair<string,char>("0101",'5'));
    binmap.insert(pair<string,char>("0110",'6'));
    binmap.insert(pair<string,char>("0111",'7'));
    binmap.insert(pair<string,char>("1000",'8'));
    binmap.insert(pair<string,char>("1001",'9'));
    binmap.insert(pair<string,char>("1010",'A'));
    binmap.insert(pair<string,char>("1011",'B'));
    binmap.insert(pair<string,char>("1100",'C'));
    binmap.insert(pair<string,char>("1101",'D'));
    binmap.insert(pair<string,char>("1110",'E'));
    binmap.insert(pair<string,char>("1111",'F'));
        string hex="";
    for(int i=0; i<s.length(); i+=4){
        string ch="";
        ch+= s[i];
        ch+= s[i+1];
        ch+= s[i+2];
        ch+= s[i+3];
        hex+= binmap[ch];
    }
    return hex;
    }
int main()
{
    hex1 hexmap;
    hexmap.insert(pair<char,string>('0',"0000"));
    hexmap.insert(pair<char,string>('1',"0001"));
    hexmap.insert(pair<char,string>('2',"0010"));
    hexmap.insert(pair<char,string>('3',"0011"));
    hexmap.insert(pair<char,string>('4',"0100"));
    hexmap.insert(pair<char,string>('5',"0101"));
    hexmap.insert(pair<char,string>('6',"0110"));
    hexmap.insert(pair<char,string>('7',"0111"));
    hexmap.insert(pair<char,string>('8',"1000"));
    hexmap.insert(pair<char,string>('9',"1001"));
    hexmap.insert(pair<char,string>('A',"1010"));
    hexmap.insert(pair<char,string>('B',"1011"));
    hexmap.insert(pair<char,string>('C',"1100"));
    hexmap.insert(pair<char,string>('D',"1101"));
    hexmap.insert(pair<char,string>('E',"1110"));
    hexmap.insert(pair<char,string>('F',"1111"));

    string pt, key;
    pt= "123456ABCD132536";
    key= "AABB09182736CCDD";
    string newkey;
    for(int i=0;i<key.length();i++)
    {
        newkey=newkey+hexmap[key[i]];
    }
     int keyp[56]=
    {    57,49,41,33,25,17,9,
        1,58,50,42,34,26,18,
        10,2,59,51,43,35,27,
        19,11,3,60,52,44,36,
        63,55,47,39,31,23,15,
        7,62,54,46,38,30,22,
        14,6,61,53,45,37,29,
        21,13,5,28,20,12,4
    };
    int shift_table[16]=
    {    1, 1, 2, 2,
        2, 2, 2, 2,
        1, 2, 2, 2,
        2, 2, 2, 1
    };
    int key_comp[48]=
    {    14,17,11,24,1,5,
        3,28,15,6,21,10,
        23,19,12,4,26,8,
        16,7,27,20,13,2,
        41,52,31,37,47,55,
        30,40,51,45,33,48,
        44,49,39,56,34,53,
        46,42,50,36,29,32
    };
    newkey=permute(newkey,keyp,56);
    string left= newkey.substr(0, 28);
    vector <string> rkp;
    string right=newkey.substr(28,56);
    vector <string> roundke;
    for(int i=0; i<16; i++){
        //Shifting
        left= shift_left(left, shift_table[i]);
        right= shift_left(right, shift_table[i]);
        string combine=left+right;
        string roundkey=permute(combine,key_comp,48);
        rkp.push_back(roundkey);
        roundke.push_back(bin2hex(roundkey));
    }
    for (int i=0; i<rkp.size(); i++)
        cout << rkp[i] << "\n";
    for (int i=0; i<roundke.size(); i++)
        cout << roundke[i] << "\n";
    return 0;
}



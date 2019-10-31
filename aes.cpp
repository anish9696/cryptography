#include<bits/stdc++.h>
#include<iostream>
using namespace std;
typedef map<char,string> hex1;
typedef map<string,char> bin1;
string hex2bin(string s)
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
    string newkey;
    for(int i=0;i<s.length();i++)
    {
        newkey=newkey+hexmap[s[i]];
    }
    return newkey;
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

string xor_(string a, string b){
    string ans= "";
    for(int i=0; i<a.size(); i++){
        if(a[i]==b[i]){
            ans+= "0";
        }else{
            ans+= "1";
        }
    }
    return ans;
}

string rot(string s)
{
    string ch="";
    string temp=s.substr(0,8);
    string temp2=s.substr(8,24);

    ch=temp2+temp;
    return ch;

}
int mapping(char ch)
{
    int temp;
    switch(ch)
    {
    case '0':
        temp=0;
        break;
    case '1':
        temp=1;
        break;
    case '2':
        temp=2;
        break;
    case '3':
        temp=3;
        break;
    case '4':
        temp=4;
        break;
    case '5':
        temp=5;
        break;
    case '6':
        temp=6;
        break;
    case '7':
        temp=7;
        break;
    case '8':
        temp=8;
        break;
    case '9':
        temp=9;
        break;
    case 'A':
        temp=10;
        break;
    case 'B':
        temp=11;
        break;
    case 'C':
        temp=12;
        break;
    case 'D':
        temp=13;
        break;
    case 'E':
        temp=14;
        break;
    case 'F':
        temp=15;
        break;
    }
    return temp;
}

string sub(string s,string subbyte[16][16])
{
    char ch1;
    char ch2;
    string key="";
    for(int i=0;i<s.length();i+=2)
    {
        ch1=s.at(i);
        ch2=s.at(i+1);
        int row=mapping(ch1);
        int col=mapping(ch2);
        key=key+subbyte[row][col];
    }
    return key;
}

string tvalue(string s,string rcon)
{
    string x="";
    string y="";
    x=hex2bin(s);
    y=hex2bin(rcon);
    string z="";
    z=xor_(x,y);
    z=bin2hex(z);
    return z;
}

string keyexpansion(string bitkey,string tval)
{
    vector <string> ch;
    string temp;
    for(int i=0;i<bitkey.length();i+=32)
    {
        temp=bitkey.substr(i,32);
        ch.push_back(temp);
    }
    string tempx;
    tempx=xor_(tval,ch[0]);
    string newbitkey=tempx;
    tempx=xor_(tempx,ch[1]);
    newbitkey=newbitkey+tempx;
    tempx=xor_(tempx,ch[2]);
    newbitkey=newbitkey+tempx;
    tempx=xor_(tempx,ch[3]);
    newbitkey=newbitkey+tempx;
  return newbitkey;
}

void show(string bitkey)
{
    vector <string> tch;
        string temp;
    for(int i=0;i<bitkey.length();i+=32)
    {
        temp=bitkey.substr(i,32);
        temp=bin2hex(temp);
        tch.push_back(temp);
    }
    for(int i=0;i<4;i++)
    {
        cout<<"word"<<i<<"   "<<tch[i]<<setw(15);
    }
}
int main()
{
    string key;
    key="2475A2B33475568831E2120013AA5487";
    string subbyte[16][16]={{"63","7C","77","7B","F2","6B","6F","C5","30","01","67","2B","FE","D7","AB","76"},
                            {"CA","82","C9","7D","FA","59","47","F0","AD","D4","A2","AF","9C","A4","72","C0"},
                            {"B7","FD","93","26","36","3F","F7","CC","34","A5","E5","F1","71","D8","31","15"},
                            {"04","C7","23","C3","18","96","05","9A","07","12","80","E2","EB","27","B2","75"},
                            {"09","83","2C","1A","1B","6E","5A","A0","52","3B","D6","B3","29","E3","2F","84"},
                            {"53","D1","00","ED","20","FC","B1","5B","6A","CB","BE","39","4A","4C","58","CF"},
                            {"D0","EF","AA","FB","43","4D","33","85","45","F9","01","4F","50","3C","9F","A8"},
                            {"51","A3","40","8F","92","9D","38","F5","BC","B6","DA","21","10","FF","F3","D2"},
                            {"CD","0C","13","EC","5F","97","44","17","C4","A7","7E","3D","64","5D","19","73"},
                            {"60","81","4F","DC","22","2A","90","88","46","EE","B8","14","DE","5E","0B","DB"},
                            {"E0","32","3A","0A","49","06","24","5C","C2","D3","AC","62","91","95","E4","79"},
                            {"E7","CB","37","6D","8D","D5","4E","A9","6C","56","F4","EA","65","7A","AE","08"},
                            {"BA","78","25","2E","1C","A6","B4","C6","E8","DD","74","1F","4B","BD","8B","8A"},
                            {"70","3E","B5","66","48","03","F6","0E","61","35","57","B9","86","C1","1D","9E"},
                            {"E1","F8","98","11","69","D9","8E","94","9B","1E","87","E9","CE","55","28","DF"},
                            {"8C","A1","89","0D","BF","E6","42","68","41","99","2D","0F","B0","54","BB","16"}};
    string rcon[10]={"01000000",
                     "02000000",
                     "04000000",
                     "08000000",
                     "10000000",
                     "20000000",
                     "40000000",
                     "80000000",
                     "1B000000",
                     "36000000"};

    string bitkey;
    bitkey=hex2bin(key);
    for(int i=0;i<10;i++)
    {
        vector <string> ch;
        string tempo;
        for(int j=0;j<bitkey.length();j+=32)
        {
            tempo=bitkey.substr(j,32);
            ch.push_back(tempo);
        }
    show(bitkey);
    int x=3;
    string tval;
    string rval;
    string sval;
    string thexval;
    rval=bin2hex(rot(ch[x]));
    sval=sub(rval,subbyte);
    tval=tvalue(sval,rcon[i]);
    thexval=hex2bin(tval);
    cout<<endl;
    cout<<"T value "<<tval<<endl;
    cout<<endl;
    cout<<endl;
    string word;
    word=keyexpansion(bitkey,thexval);
    bitkey=word;
    }
    show(bitkey);
}

#include <iostream>
#include <ctime>
#include <cstdlib>
//#include <values.h>
#include <vector>
#include <bits/stdc++.h>
#include <float.h>
#include <climits>
#include <fstream>
#include <cstring>
#include <conio.h>
#include <windows.h>

using namespace std;

ifstream fin("profile_save.txt");
ifstream p_in("powers.txt");

const float DO=261.63, RE=293.66, MIb=311.13, FA=349.23, SIb=233.08;

void grave_1()
{
    Beep(DO, 999.99);
    Sleep(20);
    Beep(DO, 500);
    Beep(RE, 500);
    Beep(MIb,700);
    Beep(RE, 500);
    Beep(MIb, 500);
    Beep(FA, 999.99);
}

void grave_2()
{
    Beep(DO, 999.99);
    Sleep(20);
    Beep(DO, 500);
    Beep(RE, 500);
    Beep(MIb,700);
    Beep(RE, 500);
    Beep(SIb, 500);
    Beep(DO, 999.99);
}

int timp()
{
    time_t rawtime;
    struct tm * timeinfo;
    char buffer [80];
    int tm[6], tr, ore, minute, secunde;
    time (&rawtime);
    timeinfo = localtime (&rawtime);
    strftime (buffer,80,"%X",timeinfo);
    tm[0]=(int)buffer[0]-48;
    tm[1]=(int)buffer[1]-48;
    tm[2]=(int)buffer[3]-48;
    tm[3]=(int)buffer[4]-48;
    tm[4]=(int)buffer[6]-48;
    tm[5]=(int)buffer[7]-48;
    tr=tm[5]+10*tm[4]+100*tm[3]+1000*tm[2]+10000*tm[1]+100000*tm[0];
    ore=tm[1]+10*tm[0];
    minute=tm[3]+10*tm[2];
    secunde=tm[5]+10*tm[4];
    minute+=ore*60;
    secunde+=minute*60;
    return secunde;
}

bool identic(char* s, char* r)
{
    bool ok=true;
    int l=min(strlen(s), strlen(r));
    for(int t=0;t<l&&ok;t++){
        if(r[t]!=s[t]) ok=false;
    }
    return ok;
}

void log()
{
    int i=0;
    char username[21], curentusername[21], pass[21], curentpass[21], a;
    start:
    cout<<"Introduceti numele de utilizator :";
    cin>>curentusername;
    cout<<endl<<"Introduceti parola :";
    while(!GetAsyncKeyState(VK_SPACE)){
        a=getch();
        if(GetAsyncKeyState(VK_SPACE)) break;
        curentpass[i]=a;
        cout<<'*'<<'\a';
        i++;
    }
    cout<<endl;
    fin>>username>>pass;
    if(identic(username, curentusername)&&identic(pass, curentpass)) SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10),cout<<"Corect";
    else{
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12),cout<<"Gresit",Sleep(1000), system("cls");
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
        goto start;
    }
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
    Sleep(1000);
    fin.close();
    system("cls");
}

void create_profil()
{
    int i=0;
    char username[21], pass[21], a;
    cout<<"Introduceti numele de utilizator :";
    cin>>username;
    cout<<endl<<"Introduceti parola :";
    while(!GetAsyncKeyState(VK_SPACE)){
        a=getch();
        if(GetAsyncKeyState(VK_SPACE)) break;
        pass[i]=a;
        cout<<'*';
        i++;
    }
    cout<<endl;
    ofstream fout("profile_save.txt");
    fout<<username<<endl<<endl<<pass;
    cout<<"Contul a fost creat. Poti incepe !";
    Sleep(1000);
    fout.close();
    system("cls");
}

void change_profile()
{
    system("cls");
    int i=0;
    char username[21], pass[21], a;
    cout<<"Introduceti numele de utilizator :";
    cin>>username;
    cout<<endl<<"Introduceti parola :";
    while(!GetAsyncKeyState(VK_SPACE)){
        a=getch();
        if(GetAsyncKeyState(VK_SPACE)) break;
        pass[i]=a;
        cout<<'*'<<'\a';
        i++;
    }
    ofstream pr_out("profile_save.txt");
    pr_out<<username<<endl<<endl<<pass;
    pr_out.close();
    cout<<endl<<"Modificare reusita !"<<endl;
    Sleep(1000);
    system("cls");
}

// beatboss
bool c_casa=false;
bool win_boss=false;
bool c_win_boss=false;
bool casa=false;

// culoare
int color=2;
bool c_color=false;

// speed
int speed=100;

// functii
bool foc=false;
bool electro=false;
bool vant=false;

// de cumparat
bool c_foc=false;
bool c_electro=false;
bool c_vant=false;
bool c_tinta=false;
bool c_speed1=false;
bool c_speed2=false;

// grafica, hp, time
int i1=9, i2=30, i3=9;
string shp="          ";
int hpb1=100, hpb2=100;
int time_s=1, time_sp=1;
char c=(char)219, persb='T', persr='X';
string sol, s1, s2, s3;
int bani;

// profil
ifstream bani_in("bani.txt");

void inceput()
{
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
    cout<<"Pentru a va deplasa, apasati sageata stanga sau dreapta."<<endl;
    Sleep(500);
    cout<<"Pentru a-l lovi pe adversar, doar cand intre tine si el este UN SPATIU, apasati 'ENTER'."<<endl;
    Sleep(500);
    cout<<"Daca nu exista nici un spatiu, vei fi lovit."<<endl;
    Sleep(500);
    cout<<"Pentru a arunca un shuriken, apasati 'SPACE'."<<endl;
    Sleep(500);
    cout<<"Pentru a folosi o lovitura speciala, activati numlock."<<endl;
    Sleep(500);
    cout<<"Acestea sunt |din tastatura numerica|:"<<endl;
    Sleep(500);
    cout<<"5 - fulger"<<endl, Sleep(300);
    cout<<"4 - foc"<<endl, Sleep(300);
    cout<<"6 - vant"<<endl<<endl, Sleep(300);
    cout<<"ATENTIE !!!"<<endl;
    cout<<"Pentru a arunca un shuricken, trebuie sa aveti 5 miscari ( Bara vere deschis )."<<endl, Sleep(500);
    cout<<"Pentru a folosi loviturile speciale, trebuie sa aveti 10 miscari ( Bara verde deschis )."<<endl, Sleep(500);
    system("pause");
    system("cls");
}

void hpb()
{
    if(hpb1<=40) SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
    else if(hpb1<=70) SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
    else SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10);
    for(int i=1;i<=hpb1/10;i++) cout<<(char)219;
}

void hpr()
{
    if(hpb2<=40) SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
    else if(hpb2<=70) SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
    else SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10);
    for(int i=1;i<=hpb2/10;i++) cout<<(char)219;
}

void hp_s()
{
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
    cout<<"Shuriken :";
    if(time_s==1) SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
    else if(time_s==2) SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
    else if(time_s==3) SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 6);
    else if(time_s==4) SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 6);
    else SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10);
    if (time_s<=5)
        for(int i=1;i<=time_s;i++)
            cout<<(char)219;
    else for(int i=1;i<=5;i++) cout<<(char)219;
    cout<<endl<<endl;
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
}

void hp_sp()
{
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
    cout<<"Special :";
    if(time_sp<=2) SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
    else if(time_sp<=4) SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 6);
    else if(time_sp<=6) SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 6);
    else if(time_sp<=8) SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
    else if(time_sp==9) SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 2);
    else SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10);
    if (time_sp<=10)
        for(int i=1;i<=time_sp;i++) cout<<(char)219;
    else for(int i=1;i<=10;i++) cout<<(char)219;
    cout<<endl<<endl;
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
}

void initial()
{
    int x=1, y=1, z=1, p=1;
    for(x;x<=50;x++) sol+=c;
    for(y;y<=i1;y++) s1+=' ';
    for(z;z<=i2;z++) s2+=' ';
    for(p;p<=i3;p++) s3+=' ';
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
    cout<<s1<<persb<<s2;
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
    cout<<persr<<s3;
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
    cout<<endl<<sol<<endl;
}

void shuriken()
{
    int x=1, y=1, z=1, p=1;
    for(x;x<=50;x++) sol+=c;
    for(y;y<=i1;y++) s1+=' ';
    for(z;z<=i2;z++) s2+=' ';
    for(p;p<=i3;p++) s3+=' ';
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
    cout<<s1<<persb;
    for(int a=1;a<=i2;a++){
        cout<<" ";
        cout<<'*'<<'\b';
        Sleep(10);
    }
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
    cout<<persr<<s3;
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
    cout<<endl<<sol<<endl;
}

void finnal()
{
    hpb();
    cout<<shp;
    hpr();
    cout<<endl<<endl;
    hp_s();
    hp_sp();
    initial();
    sol="", s1="", s2="", s3="";
}

void zap()
{
    int x=1, y=1, z=1, p=1;
    for(x;x<=50;x++) sol+=c;
    for(y;y<=i1;y++) s1+=' ';
    for(z;z<=i2;z++) s2+=' ';
    for(p;p<=i3;p++) s3+=' ';
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
    cout<<s1<<persb;
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11);
    for(int a=1;a<=i2;a++){
        cout<<'-';
        Sleep(5);
    }
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
    cout<<persr<<s3;
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
    cout<<endl<<sol<<endl;
    Sleep(100);
    system("cls");
    sol="", s1="", s2="", s3="";
    finnal();
}

void zap_rau()
{
    int x=1, y=1, z=1, p=1;
    for(x;x<=50;x++) sol+=c;
    for(y;y<=i1;y++) s1+=' ';
    for(z;z<=i2;z++) s2+=' ';
    for(p;p<=i3;p++) s3+=' ';
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
    cout<<s1<<persb;
    cout<<s2;
    for(int a=i2-1;a>1;a--){
        cout<<'\b';
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11);
        cout<<'-'<<'\b';
        Sleep(20);
    }
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
    cout<<s2<<persr;
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
    cout<<endl<<sol<<endl;
    Sleep(1000);
}

void shuriken_rau()
{
    int x=1, y=1, z=1, p=1;
    for(x;x<=50;x++) sol+=c;
    for(y;y<=i1;y++) s1+=' ';
    for(z;z<=i2;z++) s2+=' ';
    for(p;p<=i3;p++) s3+=' ';
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
    cout<<s1<<persb;
    cout<<s2;
    for(int a=i2;a>1;a--){
        cout<<'\b';
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
        cout<<'*'<<'\b';
        Sleep(20);
    }
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
    cout<<s2<<persr;
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
    cout<<endl<<sol<<endl;
    Sleep(1000);
}

void fire()
{
    int x=1, y=1, z=1, p=1;
    for(x;x<=50;x++) sol+=c;
    for(y;y<=i1;y++) s1+=' ';
    for(z;z<=i2;z++) s2+=' ';
    for(p;p<=i3;p++) s3+=' ';
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
    cout<<s1;
    int ci2=i2;
    for(int a=1;a<=i2;a++){
        cout<<" ";
        cout<<persb<<'\b';
        Sleep(5);
    }
    cout<<persb<<' ';
    i2=1, i1=i1+ci2;
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
    cout<<persr<<s3;
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
    cout<<endl<<sol<<endl;
}

void fire_rau()
{
    int x=1, y=1, z=1, p=1;
    for(x;x<=50;x++) sol+=c;
    for(y;y<=i1;y++) s1+=' ';
    for(z;z<=i2;z++) s2+=' ';
    for(p;p<=i3;p++) s3+=' ';
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
    cout<<s1<<persb<<s2;
    int ci2=i2;
    for(int a=i2;a>0;a--){
        cout<<'\b';
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
        cout<<persr<<'\b';
        Sleep(5);
    }
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
    cout<<' '<<persr;
    i2=1;
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
    cout<<endl<<sol<<endl;
}

void wind()
{
    int x=1, y=1, z=1, p=1;
    for(x;x<=50;x++) sol+=c;
    for(y;y<=i1;y++) s1+=' ';
    for(z;z<=i2;z++) s2+=' ';
    for(p;p<=i3;p++) s3+=' ';
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
    cout<<s1<<persb<<s2;
    for(int i=1;i<=20;i++){
        cout<<' ';
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
        cout<<persr;
        Sleep(50);
        cout<<'\b';
    }
    cout<<persr;
    i2+=20;
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
    cout<<endl<<sol<<endl;
}

void antrenament_basic()
{
    char instr;
    inceput();
    start:
    i1=9, i2=30, i3=9;
    string shp="          ";
    hpb1=100, hpb2=100;
    time_s=1, time_sp=1;
    c=(char)219, persb=(char)1, persr=(char)2;
    s1="", s2="", s3="";
    finnal();
    while(hpb1>0&&hpb2>0){
        if(GetAsyncKeyState(VK_RIGHT)&&i2!=0){                    // in dreapta
            Sleep(100);
            i1++;
            i2--;
            system("cls");
            time_s++;
            time_sp++;
            finnal();
        }
        else if(GetAsyncKeyState(VK_LEFT)&&i1!=0){               // in stanga
            Sleep(100);
            i1--;
            i2++;
            time_s++;
            time_sp++;
            system("cls");
            finnal();
        }
        else if(GetAsyncKeyState(VK_RETURN)&&i2==1){          // damage
            Sleep(100);
            hpb2=hpb2-10;
            time_s++;
            time_sp++;
            system("cls");
            finnal();
        }
        else if(GetAsyncKeyState(VK_SPACE)&&time_s>=5){     // shuriken
            Sleep(100);
            system("cls");
            hpb2-=10;
            time_s=1;
            time_sp++;
            hpb();
            cout<<shp;
            hpr();
            cout<<endl<<endl;
            hp_s();
            hp_sp();
            shuriken();
            sol="", s1="", s2="", s3="";
        }
        else if(GetAsyncKeyState(VK_NUMPAD4)&&time_sp>=10){    // bandit - 4(NumLock)
            Sleep(100);
            system("cls");
            time_sp=1;
            hpb2-=20;
            hpb();
            cout<<shp;
            hpr();
            cout<<endl<<endl;
            hp_s();
            hp_sp();
            fire();
            sol="", s1="", s2="", s3="";
        }
        else if(GetAsyncKeyState(VK_NUMPAD5)&&time_sp>=10){    // zap - 5(NumLock)
            Sleep(100);
            system("cls");
            time_sp=1;
            hpb2-=30;
            hpb();
            cout<<shp;
            hpr();
            cout<<endl<<endl;
            hp_s();
            hp_sp();
            zap();
            sol="", s1="", s2="", s3="";
        }
        else if(GetAsyncKeyState(VK_NUMPAD6)&&time_sp>=10&&i1+1+i2+2<=50){// wind - 6(NumLock)
            Sleep(100);
            system("cls");
            time_sp=1;
            hpb2-=20;
            hpb();
            cout<<shp;
            hpr();
            cout<<endl<<endl;
            hp_s();
            hp_sp();
            wind();
            sol="", s1="", s2="", s3="";
        }
        if(i2==0){
            Sleep(1000);
            hpb1-=10;
            shp+=' ';
            system("cls");
            finnal();
        }
    }
    Sleep(500);
    if(hpb2<=0) persr=' ';
    else if(hpb1<=0) persb=' ';
    system("cls");
    finnal();
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
    cout<<endl<<endl<<"Game Over!"<<endl;
    Sleep(500);
    if(hpb1<=0){
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
        cout<<"You lost!"<<endl<<endl;
    }
    else {
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10);
        cout<<"You won!"<<endl<<endl;
        bani+=10;
    }
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
    cout<<"If you want to remach, press twice 'SPACE' ."<<endl<<endl;
    cout<<"Else, press another key."<<endl;
    system("pause");
    if (GetAsyncKeyState(VK_SPACE)){
        system("cls");
        goto start;
    }
    else system("cls");
}

void train()
{
    char instr;
    i1=9, i2=30, i3=9;
    string shp="          ";
    hpb1=100, hpb2=100;
    time_s=1, time_sp=1;
    c=(char)219, persb=(char)1, persr=(char)2;
    s1="", s2="", s3="";
    finnal();
    while(hpb1>0&&hpb2>0){
        if(GetAsyncKeyState(VK_RIGHT)&&i2!=0){                    // in dreapta
            Sleep(speed);
            i1++;
            i2--;
            system("cls");
            time_s++;
            time_sp++;
            finnal();
        }
        else if(GetAsyncKeyState(VK_LEFT)&&i1!=0){               // in stanga
            Sleep(speed);
            i1--;
            i2++;
            time_s++;
            time_sp++;
            system("cls");
            finnal();
        }
        else if(GetAsyncKeyState(VK_RETURN)&&i2==1){          // damage
            Sleep(speed);
            hpb2=hpb2-10;
            time_s++;
            time_sp++;
            system("cls");
            finnal();
        }
        else if(GetAsyncKeyState(VK_SPACE)&&time_s>=5){     // shuriken
            Sleep(speed);
            system("cls");
            hpb2-=10;
            time_s=1;
            time_sp++;
            hpb();
            cout<<shp;
            hpr();
            cout<<endl<<endl;
            hp_s();
            hp_sp();
            shuriken();
            sol="", s1="", s2="", s3="";
        }
        else if(GetAsyncKeyState(VK_NUMPAD4)&&time_sp>=10&&foc){    // bandit - 4(NumLock)
            Sleep(speed);
            system("cls");
            time_sp=1;
            hpb2-=20;
            hpb();
            cout<<shp;
            hpr();
            cout<<endl<<endl;
            hp_s();
            hp_sp();
            fire();
            sol="", s1="", s2="", s3="";
        }
        else if(GetAsyncKeyState(VK_NUMPAD5)&&time_sp>=10&&electro){    // zap - 5(NumLock)
            Sleep(speed);
            system("cls");
            time_sp=1;
            hpb2-=30;
            hpb();
            cout<<shp;
            hpr();
            cout<<endl<<endl;
            hp_s();
            hp_sp();
            zap();
            sol="", s1="", s2="", s3="";
        }
        else if(GetAsyncKeyState(VK_NUMPAD6)&&time_sp>=10&&i1+1+i2+2<=50&&vant){// wind - 6(NumLock)
            Sleep(speed);
            system("cls");
            time_sp=1;
            hpb2-=20;
            hpb();
            cout<<shp;
            hpr();
            cout<<endl<<endl;
            hp_s();
            hp_sp();
            wind();
            sol="", s1="", s2="", s3="";
        }
        if(i2==0){
            Sleep(1000);
            hpb1-=10;
            shp+=' ';
            system("cls");
            finnal();
        }
    }
    Sleep(5*speed);
    if(hpb2<=0) persr=' ';
    else if(hpb1<=0) persb=' ';
    system("cls");
    finnal();
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
    cout<<endl<<endl<<"Game Over!"<<endl;
    Sleep(500);
    if(hpb1<=0){
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
        cout<<"You lost!"<<endl<<endl;
        grave_2();
    }
    else {
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10);
        cout<<"You won!"<<endl<<endl;
        bani+=10;
        grave_1();
    }
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
    system("pause");
    system("cls");
}

void battle_1()
{
    char instr;
    start:
    i1=9, i2=30, i3=9;
    string shp="          ";
    hpb1=100, hpb2=100;
    time_s=0, time_sp=0;
    c=(char)219, persb=(char)1, persr=(char)2;
    s1="", s2="", s3="";
    finnal();
    while(hpb1>0&&hpb2>0){
        // miscari bun
        if(GetAsyncKeyState(VK_RIGHT)&&i2!=0){                    // in dreapta
            Sleep(speed);
            i1++;
            i2--;
            system("cls");
            time_s++;
            time_sp++;
            finnal();
        }
        else if(GetAsyncKeyState(VK_LEFT)&&i1!=0){               // in stanga
            Sleep(speed);
            i1--;
            i2++;
            time_s++;
            time_sp++;
            system("cls");
            finnal();
        }
        else if(GetAsyncKeyState(VK_RETURN)&&i2==1){          // damage
            Sleep(speed);
            hpb2=hpb2-10;
            time_s++;
            time_sp++;
            system("cls");
            finnal();
        }
        else if(GetAsyncKeyState(VK_SPACE)&&time_s>=5){     // shuriken
            Sleep(speed);
            system("cls");
            hpb2-=10;
            time_s=1;
            time_sp++;
            hpb();
            cout<<shp;
            hpr();
            cout<<endl<<endl;
            hp_s();
            hp_sp();
            shuriken();
            sol="", s1="", s2="", s3="";
        }
        else if(GetAsyncKeyState(VK_NUMPAD4)&&time_sp>=10&&foc){    // bandit - 4(NumLock)
            Sleep(speed);
            system("cls");
            time_sp=1;
            hpb2-=20;
            hpb();
            cout<<shp;
            hpr();
            cout<<endl<<endl;
            hp_s();
            hp_sp();
            fire();
            sol="", s1="", s2="", s3="";
        }
        else if(GetAsyncKeyState(VK_NUMPAD5)&&time_sp>=10&&electro){    // zap - 5(NumLock)
            Sleep(speed);
            system("cls");
            time_sp=1;
            hpb2-=30;
            hpb();
            cout<<shp;
            hpr();
            cout<<endl<<endl;
            hp_s();
            hp_sp();
            zap();
            sol="", s1="", s2="", s3="";
        }
        else if(GetAsyncKeyState(VK_NUMPAD6)&&time_sp>=10&&i1+1+i2+2<=50&&vant){// wind - 6(NumLock)
            Sleep(speed);
            system("cls");
            time_sp=1;
            hpb2-=20;
            hpb();
            cout<<shp;
            hpr();
            cout<<endl<<endl;
            hp_s();
            hp_sp();
            wind();
            sol="", s1="", s2="", s3="";
        }
        if(i2==0){
            Sleep(1000);
            hpb1-=10;
            shp+=' ';
            system("cls");
            finnal();
        }
        // miscari rau
        if(i1+i2+2>=50);
        else{
        if(i2<=40&&i2>=20){
            Sleep(100);
            i2--;
            system("cls");
            finnal();
        }
        if(i2==15||i2==10){
            system("cls");
            Sleep(100);
            hpb1-=10;
            hpb();
            cout<<shp;
            hpr();
            cout<<endl<<endl;
            hp_s();
            hp_sp();
            shuriken_rau();
            sol="", s1="", s2="", s3="";
        }
        }
    }
    Sleep(5*speed);
    if(hpb2<=0) persr=' ';
    else if(hpb1<=0) persb=' ';
    system("cls");
    finnal();
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
    cout<<endl<<endl<<"Game Over!"<<endl;
    Sleep(500);
    if(hpb1<=0){
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
        cout<<"You lost!"<<endl<<endl;
        grave_2();
    }
    else {
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10);
        cout<<"You won!"<<endl<<endl;
        bani+=40;
        grave_1();
    }
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
    cout<<"If you want to remach, press twice 'SPACE' ."<<endl<<endl;
    cout<<"Else, press another key."<<endl;
    system("pause");
    if (GetAsyncKeyState(VK_SPACE)){
        system("cls");
        battle_1();
    }
}

void battle_2()
{
    char instr;
    start:
    i1=9, i2=30, i3=9;
    string shp="          ";
    hpb1=100, hpb2=100;
    time_s=0, time_sp=0;
    c=(char)219, persb=(char)1, persr=(char)2;
    s1="", s2="", s3="";
    finnal();
    while(hpb1>0&&hpb2>0){
        // miscari bun
        if(GetAsyncKeyState(VK_RIGHT)&&i2!=0){                    // in dreapta
            Sleep(speed);
            i1++;
            i2--;
            system("cls");
            time_s++;
            time_sp++;
            finnal();
        }
        else if(GetAsyncKeyState(VK_LEFT)&&i1!=0){               // in stanga
            Sleep(speed);
            i1--;
            i2++;
            time_s++;
            time_sp++;
            system("cls");
            finnal();
        }
        else if(GetAsyncKeyState(VK_RETURN)&&i2==1){          // damage
            Sleep(speed);
            hpb2=hpb2-10;
            time_s++;
            time_sp++;
            system("cls");
            finnal();
        }
        else if(GetAsyncKeyState(VK_SPACE)&&time_s>=5){     // shuriken
            Sleep(speed);
            system("cls");
            hpb2-=10;
            time_s=1;
            time_sp++;
            hpb();
            cout<<shp;
            hpr();
            cout<<endl<<endl;
            hp_s();
            hp_sp();
            shuriken();
            sol="", s1="", s2="", s3="";
        }
        else if(GetAsyncKeyState(VK_NUMPAD4)&&time_sp>=10&&foc){    // bandit - 4(NumLock)
            Sleep(speed);
            system("cls");
            time_sp=1;
            hpb2-=20;
            hpb();
            cout<<shp;
            hpr();
            cout<<endl<<endl;
            hp_s();
            hp_sp();
            fire();
            sol="", s1="", s2="", s3="";
        }
        else if(GetAsyncKeyState(VK_NUMPAD5)&&time_sp>=10&&electro){    // zap - 5(NumLock)
            Sleep(speed);
            system("cls");
            time_sp=1;
            hpb2-=30;
            hpb();
            cout<<shp;
            hpr();
            cout<<endl<<endl;
            hp_s();
            hp_sp();
            zap();
            sol="", s1="", s2="", s3="";
        }
        else if(GetAsyncKeyState(VK_NUMPAD6)&&time_sp>=10&&i1+1+i2+2<=50&&vant){// wind - 6(NumLock)
            Sleep(speed);
            system("cls");
            time_sp=1;
            hpb2-=20;
            hpb();
            cout<<shp;
            hpr();
            cout<<endl<<endl;
            hp_s();
            hp_sp();
            wind();
            sol="", s1="", s2="", s3="";
        }
        if(i2==0){
            Sleep(1000);
            hpb1-=10;
            shp+=' ';
            system("cls");
            finnal();
        }
        // miscari rau
        if(i1+i2+2>=50);
        else{
        if(i2<=40&&i2>=10){
            Sleep(100);
            i2--;
            system("cls");
            finnal();
        }
        if(i2==8||i2==4||i2==2||i2==1){
            system("cls");
            Sleep(100);
            hpb1-=10;
            hpb();
            cout<<shp;
            hpr();
            cout<<endl<<endl;
            hp_s();
            hp_sp();
            shuriken_rau();
            sol="", s1="", s2="", s3="";
        }
        }
    }
    Sleep(5*speed);
    if(hpb2<=0) persr=' ';
    else if(hpb1<=0) persb=' ';
    system("cls");
    finnal();
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
    cout<<endl<<endl<<"Game Over!"<<endl;
    Sleep(500);
    if(hpb1<=0){
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
        cout<<"You lost!"<<endl<<endl;
        grave_2();
    }
    else {
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10);
        cout<<"You won!"<<endl<<endl;
        bani+=50;
        grave_1();
    }
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
    cout<<"If you want to remach, press twice 'SPACE' ."<<endl<<endl;
    cout<<"Else, press another key."<<endl;
    system("pause");
    if (GetAsyncKeyState(VK_SPACE)){
        system("cls");
        battle_2();
    }
}

void battle_3()
{
    char instr;
    start:
    i1=9, i2=30, i3=9;
    string shp="          ";
    hpb1=100, hpb2=100;
    time_s=0, time_sp=0;
    c=(char)219, persb=(char)1, persr=(char)2;
    s1="", s2="", s3="";
    finnal();
    while(hpb1>0&&hpb2>0){
        // miscari bun
        if(GetAsyncKeyState(VK_RIGHT)&&i2!=0){                    // in dreapta
            Sleep(speed);
            i1++;
            i2--;
            system("cls");
            time_s++;
            time_sp++;
            finnal();
        }
        else if(GetAsyncKeyState(VK_LEFT)&&i1!=0){               // in stanga
            Sleep(speed);
            i1--;
            i2++;
            time_s++;
            time_sp++;
            system("cls");
            finnal();
        }
        else if(GetAsyncKeyState(VK_RETURN)&&i2==1){          // damage
            Sleep(speed);
            hpb2=hpb2-10;
            time_s++;
            time_sp++;
            system("cls");
            finnal();
        }
        else if(GetAsyncKeyState(VK_SPACE)&&time_s>=5){     // shuriken
            Sleep(speed);
            system("cls");
            hpb2-=10;
            time_s=1;
            time_sp++;
            hpb();
            cout<<shp;
            hpr();
            cout<<endl<<endl;
            hp_s();
            hp_sp();
            shuriken();
            sol="", s1="", s2="", s3="";
        }
        else if(GetAsyncKeyState(VK_NUMPAD4)&&time_sp>=10&&foc){    // bandit - 4(NumLock)
            Sleep(speed);
            system("cls");
            time_sp=1;
            hpb2-=20;
            hpb();
            cout<<shp;
            hpr();
            cout<<endl<<endl;
            hp_s();
            hp_sp();
            fire();
            sol="", s1="", s2="", s3="";
        }
        else if(GetAsyncKeyState(VK_NUMPAD5)&&time_sp>=10&&electro){    // zap - 5(NumLock)
            Sleep(speed);
            system("cls");
            time_sp=1;
            hpb2-=30;
            hpb();
            cout<<shp;
            hpr();
            cout<<endl<<endl;
            hp_s();
            hp_sp();
            zap();
            sol="", s1="", s2="", s3="";
        }
        else if(GetAsyncKeyState(VK_NUMPAD6)&&time_sp>=10&&i1+1+i2+2<=50&&vant){// wind - 6(NumLock)
            Sleep(speed);
            system("cls");
            time_sp=1;
            hpb2-=20;
            hpb();
            cout<<shp;
            hpr();
            cout<<endl<<endl;
            hp_s();
            hp_sp();
            wind();
            sol="", s1="", s2="", s3="";
        }
        if(i2==0){
            Sleep(1000);
            hpb1-=10;
            shp+=' ';
            system("cls");
            finnal();
        }
        // miscari rau
        if(i1+i2+2>=50);
        else{
        if(i2<=40&&i2>=30){
            Sleep(100);
            i2--;
            system("cls");
            finnal();
        }
        if(i2==1){
            Sleep(speed);
            i2++;
            system("cls");
            finnal();
        }
        if(i2==15||i2==10){
            system("cls");
            Sleep(speed);
            hpb1-=10;
            hpb();
            cout<<shp;
            hpr();
            cout<<endl<<endl;
            hp_s();
            hp_sp();
            shuriken_rau();
            sol="", s1="", s2="", s3="";
        }
        if(i2==20){
            system("cls");
            Sleep(speed);
            hpb1-=30;
            hpb();
            cout<<shp;
            hpr();
            cout<<endl<<endl;
            hp_s();
            hp_sp();
            zap_rau();
            sol="", s1="", s2="", s3="";
        }
        }
    }
    Sleep(5*speed);
    if(hpb2<=0) persr=' ';
    else if(hpb1<=0) persb=' ';
    system("cls");
    finnal();
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
    cout<<endl<<endl<<"Game Over!"<<endl;
    Sleep(500);
    if(hpb1<=0){
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
        cout<<"You lost!"<<endl<<endl;
        grave_2();
    }
    else {
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10);
        cout<<"You won!"<<endl<<endl;
        bani+=50;
        grave_1();
    }
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
    cout<<"If you want to remach, press twice 'SPACE' ."<<endl<<endl;
    cout<<"Else, press another key."<<endl;
    system("pause");
    if (GetAsyncKeyState(VK_SPACE)){
        system("cls");
        battle_3();
    }
}

void battle_4()
{
    bool ok=true;
    char instr;
    i1=9, i2=30, i3=9;
    string shp="          ";
    hpb1=100, hpb2=100;
    time_s=0, time_sp=0;
    c=(char)219, persb=(char)1, persr=(char)2;
    s1="", s2="", s3="";
    finnal();
    while(hpb1>0&&hpb2>0){
        // miscari bun
        if(GetAsyncKeyState(VK_RIGHT)&&i2!=0){                    // in dreapta
            Sleep(speed);
            i1++;
            i2--;
            system("cls");
            time_s++;
            time_sp++;
            finnal();
        }
        else if(GetAsyncKeyState(VK_LEFT)&&i1!=0){               // in stanga
            Sleep(speed);
            i1--;
            i2++;
            time_s++;
            time_sp++;
            system("cls");
            finnal();
        }
        else if(GetAsyncKeyState(VK_RETURN)&&i2==1){          // damage
            Sleep(speed);
            hpb2=hpb2-10;
            time_s++;
            time_sp++;
            system("cls");
            finnal();
        }
        else if(GetAsyncKeyState(VK_SPACE)&&time_s>=5){     // shuriken
            Sleep(speed);
            system("cls");
            hpb2-=10;
            time_s=1;
            time_sp++;
            hpb();
            cout<<shp;
            hpr();
            cout<<endl<<endl;
            hp_s();
            hp_sp();
            shuriken();
            sol="", s1="", s2="", s3="";
        }
        else if(GetAsyncKeyState(VK_NUMPAD4)&&time_sp>=10&&foc){    // bandit - 4(NumLock)
            Sleep(speed);
            system("cls");
            time_sp=1;
            hpb2-=20;
            hpb();
            cout<<shp;
            hpr();
            cout<<endl<<endl;
            hp_s();
            hp_sp();
            fire();
            sol="", s1="", s2="", s3="";
        }
        else if(GetAsyncKeyState(VK_NUMPAD5)&&time_sp>=10&&electro){    // zap - 5(NumLock)
            Sleep(speed);
            system("cls");
            time_sp=1;
            hpb2-=30;
            hpb();
            cout<<shp;
            hpr();
            cout<<endl<<endl;
            hp_s();
            hp_sp();
            zap();
            sol="", s1="", s2="", s3="";
        }
        else if(GetAsyncKeyState(VK_NUMPAD6)&&time_sp>=10&&i1+1+i2+2<=50&&vant){// wind - 6(NumLock)
            Sleep(speed);
            system("cls");
            time_sp=1;
            hpb2-=20;
            hpb();
            cout<<shp;
            hpr();
            cout<<endl<<endl;
            hp_s();
            hp_sp();
            wind();
            sol="", s1="", s2="", s3="";
        }
        if(i2==0){
            Sleep(1000);
            hpb1-=10;
            shp+=' ';
            system("cls");
            finnal();
        }
        // miscari rau
        if(i1+i2+2>=50);
        else{
        if(ok){
            ok=false;
            system("cls");
            Sleep(100);
            hpb1-=20;
            hpb();
            cout<<shp;
            hpr();
            cout<<endl<<endl;
            hp_s();
            hp_sp();
            fire_rau();
            sol="", s1="", s2="", s3="";
        }
        if(i2==1){
            Sleep(100);
            i2++;
            system("cls");
            finnal();
        }
        else if(i2<=20){
            Sleep(100);
            i2++;
            system("cls");
            finnal();
        }
        if(i2<=40&&i2>=30){
            Sleep(100);
            i2--;
            system("cls");
            finnal();
        }
        if(i2==15||i2==10){
            system("cls");
            Sleep(100);
            hpb1-=10;
            hpb();
            cout<<shp;
            hpr();
            cout<<endl<<endl;
            hp_s();
            hp_sp();
            shuriken_rau();
            sol="", s1="", s2="", s3="";
        }
        if(i2==20){
            system("cls");
            Sleep(100);
            hpb1-=30;
            hpb();
            cout<<shp;
            hpr();
            cout<<endl<<endl;
            hp_s();
            hp_sp();
            zap_rau();
            sol="", s1="", s2="", s3="";
        }
        }
    }
    Sleep(5*speed);
    if(hpb2<=0) persr=' ';
    else if(hpb1<=0) persb=' ';
    system("cls");
    finnal();
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
    cout<<endl<<endl<<"Game Over!"<<endl;
    Sleep(500);
    if(hpb1<=0){
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
        cout<<"You lost!"<<endl<<endl;
        grave_2();
    }
    else {
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10);
        cout<<"You won!"<<endl<<endl;
        bani+=60;
        grave_1();
    }
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
    cout<<"If you want to remach, press twice 'SPACE' ."<<endl<<endl;
    cout<<"Else, press another key."<<endl;
    system("pause");
    if (GetAsyncKeyState(VK_SPACE)){
        system("cls");
        battle_4();
    }
}

void battle_fgreu()
{
    bool ok=true;
    bool miscari=true;
    char instr;
    start:
    i1=9, i2=30, i3=9;
    string shp="          ";
    hpb1=100, hpb2=100;
    time_s=0, time_sp=0;
    c=(char)219, persb=(char)1, persr=(char)2;
    s1="", s2="", s3="";
    finnal();
    while(hpb1>0&&hpb2>0){
        // miscari bun
        if(GetAsyncKeyState(VK_RIGHT)&&i2!=0){                    // in dreapta
            Sleep(speed);
            i1++;
            i2--;
            system("cls");
            time_s++;
            time_sp++;
            finnal();
        }
        else if(GetAsyncKeyState(VK_LEFT)&&i1!=0){               // in stanga
            Sleep(100);
            i1--;
            i2++;
            time_s++;
            time_sp++;
            system("cls");
            finnal();
        }
        else if(GetAsyncKeyState(VK_RETURN)&&i2==1){          // damage
            Sleep(speed);
            hpb2=hpb2-10;
            time_s++;
            time_sp++;
            system("cls");
            finnal();
        }
        else if(GetAsyncKeyState(VK_SPACE)&&time_s>=5){     // shuriken
            Sleep(speed);
            system("cls");
            hpb2-=10;
            time_s=1;
            time_sp++;
            hpb();
            cout<<shp;
            hpr();
            cout<<endl<<endl;
            hp_s();
            hp_sp();
            shuriken();
            sol="", s1="", s2="", s3="";
        }
        else if(GetAsyncKeyState(VK_NUMPAD4)&&time_sp>=10&&foc){    // bandit - 4(NumLock)
            Sleep(speed);
            system("cls");
            time_sp=1;
            hpb2-=20;
            hpb();
            cout<<shp;
            hpr();
            cout<<endl<<endl;
            hp_s();
            hp_sp();
            fire();
            sol="", s1="", s2="", s3="";
        }
        else if(GetAsyncKeyState(VK_NUMPAD5)&&time_sp>=10&&electro){    // zap - 5(NumLock)
            Sleep(speed);
            system("cls");
            time_sp=1;
            hpb2-=30;
            hpb();
            cout<<shp;
            hpr();
            cout<<endl<<endl;
            hp_s();
            hp_sp();
            zap();
            sol="", s1="", s2="", s3="";
        }
        else if(GetAsyncKeyState(VK_NUMPAD6)&&time_sp>=10&&i1+1+i2+2<=50&&vant){// wind - 6(NumLock)
            Sleep(speed);
            system("cls");
            time_sp=1;
            hpb2-=20;
            hpb();
            cout<<shp;
            hpr();
            cout<<endl<<endl;
            hp_s();
            hp_sp();
            wind();
            sol="", s1="", s2="", s3="";
        }
        if(i2==0){
            Sleep(1000);
            hpb1-=10;
            shp+=' ';
            system("cls");
            finnal();
        }
        // miscari rau
        if(i1+i2+2>=50);
        else{
        if(ok){
            ok=false;
            system("cls");
            Sleep(100);
            hpb1-=20;
            hpb();
            cout<<shp;
            hpr();
            cout<<endl<<endl;
            hp_s();
            hp_sp();
            fire_rau();
            sol="", s1="", s2="", s3="";
        }
        /*if(i2<=5){
            Sleep(100);
            i2--;
            system("cls");
            finnal();
        }*/
        if(i2==8||i2==6){
            system("cls");
            Sleep(100);
            hpb1-=15;
            hpb();
            cout<<shp;
            hpr();
            cout<<endl<<endl;
            hp_s();
            hp_sp();
            shuriken_rau();
            sol="", s1="", s2="", s3="";
        }
        if(i2>=1&&miscari){
            if(i2==30) miscari=false;
            Sleep(100);
            i2++;
            system("cls");
            finnal();
        }
        /*if(i2<=30&&(!miscari)){
            Sleep(100);
            i2++;
            system("cls");
            finnal();
        }*/
        else if(i2==15||i2==25||i2==35||i2==45||i2==30){
            system("cls");
            Sleep(100);
            hpb1-=10;
            hpb();
            cout<<shp;
            hpr();
            cout<<endl<<endl;
            hp_s();
            hp_sp();
            shuriken_rau();
            sol="", s1="", s2="", s3="";
        }
        if(i2==20){
            system("cls");
            Sleep(100);
            hpb1-=30;
            hpb();
            cout<<shp;
            hpr();
            cout<<endl<<endl;
            hp_s();
            hp_sp();
            zap_rau();
            sol="", s1="", s2="", s3="";
        }
        }
    }
    Sleep(5*speed);
    if(hpb2<=0) persr=' ';
    else if(hpb1<=0) persb=' ';
    system("cls");
    finnal();
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
    cout<<endl<<endl<<"Game Over!"<<endl;
    Sleep(500);
    if(hpb1<=0){
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
        cout<<"You lost!"<<endl<<endl;
        grave_2();
    }
    else {
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10);
        cout<<"You won!"<<endl<<endl;
        bani+=80;
        grave_1();
    }
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
    cout<<"If you want to remach, press twice 'SPACE' ."<<endl<<endl;
    cout<<"Else, press another key."<<endl;
    system("pause");
    if (GetAsyncKeyState(VK_SPACE)){
        system("cls");
        battle_fgreu();
    }
}

void battle_mediu()
{

    char instr;
    start:
    i1=9, i2=30, i3=9;
    string shp="          ";
    hpb1=100, hpb2=100;
    time_s=0, time_sp=0;
    c=(char)219, persb=(char)1, persr=(char)2;
    s1="", s2="", s3="";
    finnal();
    while(hpb1>0&&hpb2>0){
        // miscari bun
        if(GetAsyncKeyState(VK_RIGHT)&&i2!=0){                    // in dreapta
            Sleep(speed);
            i1++;
            i2--;
            system("cls");
            time_s++;
            time_sp++;
            finnal();
        }
        else if(GetAsyncKeyState(VK_LEFT)&&i1!=0){               // in stanga
            Sleep(speed);
            i1--;
            i2++;
            time_s++;
            time_sp++;
            system("cls");
            finnal();
        }
        else if(GetAsyncKeyState(VK_RETURN)&&i2==1){          // damage
            Sleep(speed);
            hpb2=hpb2-10;
            time_s++;
            time_sp++;
            system("cls");
            finnal();
        }
        else if(GetAsyncKeyState(VK_RETURN)&&i2!=1){          // damage
            Sleep(speed);
            hpb2=hpb2+10;
            system("cls");
            finnal();
        }
        else if(GetAsyncKeyState(VK_SPACE)&&time_s>=5){     // shuriken
            Sleep(speed);
            system("cls");
            hpb2-=10;
            time_s=1;
            time_sp++;
            hpb();
            cout<<shp;
            hpr();
            cout<<endl<<endl;
            hp_s();
            hp_sp();
            shuriken();
            sol="", s1="", s2="", s3="";
        }
        else if(GetAsyncKeyState(VK_NUMPAD4)&&time_sp>=10&&foc){    // bandit - 4(NumLock)
            Sleep(speed);
            system("cls");
            time_sp=1;
            hpb2-=20;
            hpb();
            cout<<shp;
            hpr();
            cout<<endl<<endl;
            hp_s();
            hp_sp();
            fire();
            sol="", s1="", s2="", s3="";
        }
        else if(GetAsyncKeyState(VK_NUMPAD5)&&time_sp>=10&&electro){    // zap - 5(NumLock)
            Sleep(speed);
            system("cls");
            time_sp=1;
            hpb2-=30;
            hpb();
            cout<<shp;
            hpr();
            cout<<endl<<endl;
            hp_s();
            hp_sp();
            zap();
            sol="", s1="", s2="", s3="";
        }
        else if(GetAsyncKeyState(VK_NUMPAD6)&&time_sp>=10&&i1+1+i2+2<=50&&vant){// wind - 6(NumLock)
            Sleep(speed);
            system("cls");
            time_sp=1;
            hpb2-=20;
            hpb();
            cout<<shp;
            hpr();
            cout<<endl<<endl;
            hp_s();
            hp_sp();
            wind();
            sol="", s1="", s2="", s3="";
        }
        if(i2==0){
            Sleep(1000);
            hpb1-=10;
            shp+=' ';
            system("cls");
            finnal();
        }
        // miscari rau
        if(i1+i2+2>=50);
        else{
        if(i2%2==0&&i2!=20&&i2!=30&&i2!=40&&i2!=10&&i2!=50){
            system("cls");
            Sleep(100);
            hpb1-=15;
            hpb();
            cout<<shp;
            hpr();
            cout<<endl<<endl;
            hp_s();
            hp_sp();
            shuriken_rau();
            sol="", s1="", s2="", s3="";
        }
        }
    }
    Sleep(5*speed);
    if(hpb2<=0) persr=' ';
    else if(hpb1<=0) persb=' ';
    system("cls");
    finnal();
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
    cout<<endl<<endl<<"Game Over!"<<endl;
    Sleep(500);
    if(hpb1<=0){
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
        cout<<"You lost!"<<endl<<endl;
        grave_2();
    }
    else {
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10);
        cout<<"You won!"<<endl<<endl;
        grave_1();
        bani+=60;
    }
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
    cout<<"If you want to remach, press twice 'SPACE' ."<<endl<<endl;
    cout<<"Else, press another key."<<endl;
    system("pause");
    if (GetAsyncKeyState(VK_SPACE)){
        system("cls");
        battle_mediu();
    }
}

void battle_boss()
{
    grave_1();
    Sleep(1000);
    grave_2();
    start:
    i1=9, i2=30, i3=9;
    string shp="          ";
    hpb1=100, hpb2=100;
    time_s=0, time_sp=0;
    c=(char)219, persb=(char)1, persr='$';
    s1="", s2="", s3="";
    finnal();

    while(hpb1>0&&hpb2>0){
        // miscari bun
        if(GetAsyncKeyState(VK_RIGHT)&&i2!=0){                    // in dreapta
            Sleep(speed);
            i1++;
            i2--;
            system("cls");
            time_s++;
            time_sp++;
            finnal();
        }
        else if(GetAsyncKeyState(VK_LEFT)&&i1!=0){               // in stanga
            Sleep(speed);
            i1--;
            i2++;
            time_s++;
            time_sp++;
            system("cls");
            finnal();
        }
        else if(GetAsyncKeyState(VK_RETURN)&&i2==1){          // damage
            Sleep(speed);
            hpb2=hpb2-10;
            time_s++;
            time_sp++;
            system("cls");
            finnal();
        }
        else if(GetAsyncKeyState(VK_RETURN)&&i2!=1){          // heal
            Sleep(speed);
            hpb2=hpb2+10;
            system("cls");
            finnal();
        }
        else if(GetAsyncKeyState(VK_SPACE)&&time_s>=5){     // shuriken
            Sleep(speed);
            system("cls");
            hpb2-=10;
            time_s=1;
            time_sp++;
            hpb();
            cout<<shp;
            hpr();
            cout<<endl<<endl;
            hp_s();
            hp_sp();
            shuriken();
            sol="", s1="", s2="", s3="";
        }
        else if(GetAsyncKeyState(VK_NUMPAD4)&&time_sp>=10&&foc){    // bandit - 4(NumLock)
            Sleep(speed);
            system("cls");
            time_sp=1;
            hpb2-=20;
            hpb();
            cout<<shp;
            hpr();
            cout<<endl<<endl;
            hp_s();
            hp_sp();
            fire();
            sol="", s1="", s2="", s3="";
        }
        else if(GetAsyncKeyState(VK_NUMPAD5)&&time_sp>=10&&electro){    // zap - 5(NumLock)
            Sleep(speed);
            system("cls");
            time_sp=1;
            hpb2-=30;
            hpb();
            cout<<shp;
            hpr();
            cout<<endl<<endl;
            hp_s();
            hp_sp();
            zap();
            sol="", s1="", s2="", s3="";
        }
        else if(GetAsyncKeyState(VK_NUMPAD6)&&time_sp>=10&&i1+1+i2+2<=50&&vant){// wind - 6(NumLock)
            Sleep(speed);
            system("cls");
            time_sp=1;
            hpb2-=20;
            hpb();
            cout<<shp;
            hpr();
            cout<<endl<<endl;
            hp_s();
            hp_sp();
            wind();
            sol="", s1="", s2="", s3="";
        }
        if(i2==0){
            Sleep(1000);
            hpb1-=10;
            shp+=' ';
            system("cls");
            finnal();
        }
        // miscari rau
        if(i1+i2+2>=50);
        else{
        if(hpb1<30){
            system("cls");
            Sleep(100);
            hpb1-=20;
            hpb();
            cout<<shp;
            hpr();
            cout<<endl<<endl;
            hp_s();
            hp_sp();
            fire_rau();
            sol="", s1="", s2="", s3="";
        }
        else if(i2<=5){
            Sleep(100);
            i2--;
            system("cls");
            finnal();
        }
        else if(i2==9||i2==6){
            system("cls");
            Sleep(100);
            hpb1-=15;
            hpb();
            cout<<shp;
            hpr();
            cout<<endl<<endl;
            hp_s();
            hp_sp();
            shuriken_rau();
            sol="", s1="", s2="", s3="";
        }
        if(i2<20&&i2>=10){
            Sleep(100);
            i2--;
            system("cls");
            finnal();
        }
        if(i2>20){
            Sleep(100);
            i2--;
            system("cls");
            finnal();
        }
        if(i2==15||i2==25||i2==35){
            system("cls");
            Sleep(100);
            hpb1-=10;
            hpb();
            cout<<shp;
            hpr();
            cout<<endl<<endl;
            hp_s();
            hp_sp();
            shuriken_rau();
            sol="", s1="", s2="", s3="";
        }
        if(i2==20||i2==30){
            system("cls");
            Sleep(100);
            hpb1-=30;
            hpb();
            cout<<shp;
            hpr();
            cout<<endl<<endl;
            hp_s();
            hp_sp();
            zap_rau();
            sol="", s1="", s2="", s3="";
        }
        }
    }
    Sleep(5*speed);
    if(hpb2<=0) persr=' ';
    else if(hpb1<=0) persb=' ';
    system("cls");
    finnal();
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
    cout<<endl<<endl<<"Game Over!"<<endl;
    Sleep(500);
    if(hpb1<=0){
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
        cout<<"You lost!"<<endl<<endl;
        grave_2();
    }
    else {
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10);
        cout<<"You won!"<<endl<<endl;
        grave_1();
        cout<<"Felicitari !"<<endl<<endl;
        Sleep(1000);
        cout<<"Acum te poti muta in castelul lui !"<<endl<<endl;
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
        bani+=120;
        win_boss=true;
        c_win_boss=true;
    }
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
    cout<<"If you want to remach, press twice 'SPACE' ."<<endl<<endl;
    cout<<"Else, press another key."<<endl;
    system("pause");
    if (GetAsyncKeyState(VK_SPACE)){
        system("cls");
        battle_boss();
    }
}

void castelb()                                                                   //functie afisare castelul tau
{
     cout<<"          ##  ##           ##  ##                                     "<<endl;
     cout<<"          ######           ######                                     "<<endl;
     cout<<"          ######   *****   ######                                     "<<endl;
   //cout<<"          ######   * ☺ *   ######                                     "<<endl;
     cout<<"          ######   * "<<(char)1<<" *   ######                         "<<endl;
     cout<<"          ###########*###########                                     "<<endl;
     cout<<"   **     ##########*|*##########     **                              "<<endl;
     cout<<"  ****    ##### | #*|||*# | #####    ****                             "<<endl;
     cout<<" ******   #####-+-#*|||*#-+-#####   ******                            "<<endl;
     cout<<"  ****    ##### | #*|||*# | #####    ****                             "<<endl;
     cout<<"   **     #########=====#########     **                              "<<endl;
     cout<<"   ||     ....... #=====# .......     ||                              "<<endl;
     cout<<"   ||     ....... #=====# .......     ||                              "<<endl;
     cout<<"   ||     ....... #=====# .......     ||                              "<<endl;
}

void templu()                                                                   //functie afisare templul celor buni
{
     cout<<"                   (   (  (  (  )  )  )  )                                "<<endl;
     cout<<"                   <<<<<<<<<<<<>>>>>>>>>>>                               "<<endl;
     cout<<"                  <<<<<<<<<<<<||>>>>>>>>>>>>                              "<<endl;
     cout<<"                 <<<<<<<<<<<<|__|>>>>>>>>>>>>                             "<<endl;
     cout<<"   ##           <<<<<<<<<<<<|____|>>>>>>>>>>>>          ##                "<<endl;
     cout<<"  ####         <<<<<<<<<<<<@______@>>>>>>>>>>>>        ####               "<<endl;
     cout<<" ######       <<<<<<<<<<<<|#|----|#|>>>>>>>>>>>>      ######              "<<endl;
     cout<<"  ####       <<<<<<<<<<<<|##||==||##|>>>>>>>>>>>>      ####               "<<endl;
     cout<<"   ##       <<<<<<<<<<<<|###||==||###|>>>>>>>>>>>>      ##                "<<endl;
     cout<<"   ||      <<<<<<<<<<<<|####||==||####|>>>>>>>>>>>>     ||                "<<endl;
     cout<<"   ||     ###############____________###############    ||                "<<endl;
     cout<<"   ||     ############__________________############    ||                "<<endl;
     cout<<"   ||     #########_________________________########    ||                "<<endl;
}

// MINIGAME 1

bool target=false;
int x=15, n=3, m=3;
int q=rand()%x+1, w=rand()%x+1;
int points=0, nivel=0;
int time1;

// MINIGAME 2           LABIRINT

char o=(char)196, v=(char)179, b=(char)1, r=(char)2, s=' ', d='$', t=(char)27;

void shop()
{
    cout<<"1.Foc (450 bani)"<<endl<<endl;
    cout<<"2.Fulger (500 bani)"<<endl<<endl;
    cout<<"3.Vant (400 bani)"<<endl<<endl;
    cout<<"+ Tinta (la minigame 1, 200 bani)"<<endl<<endl;
    cout<<'v'<<' '<<"Speed Boost 1 (200 bani)"<<endl<<endl;
    cout<<'V'<<' '<<"Speed Boost 2 (350 bani)"<<endl<<endl;
    cout<<"c Culoarea de fond (50 bani)"<<endl<<endl;
    cout<<"C Casa (1000 bani)"<<endl<<endl;
    cout<<"Exit"<<endl<<endl;
    char f;
    cin>>f;
    if(f=='1'){
        cout<<"Vreti sa cumparati puterea focului cu 450 de bani (da sau nu) ?"<<endl;
        string a;
        cin>>a;
        if(a=="da"&&bani>=450) cout<<"Acum aveti puterea focului !"<<endl, foc=true, bani-=450, c_foc=true;
        Sleep(1500);
        system("cls");
        shop();
    }
    else if(f=='2'){
        cout<<"Vreti sa cumparati puterea fulgerului cu 500 de bani (da sau nu) ?"<<endl;
        string a;
        cin>>a;
        if(a=="da"&&bani>=500) cout<<"Acum aveti puterea fulgerului !"<<endl, electro=true, bani-=500, c_electro=true;
        Sleep(1500);
        system("cls");
        shop();
    }
    else if(f=='3'){
        cout<<"Vreti sa cumparati puterea vantului cu 400 de bani (da sau nu) ?"<<endl;
        string a;
        cin>>a;
        if(a=="da"&&bani>=400) cout<<"Acum aveti puterea vantului !"<<endl, vant=true, bani-=400, c_vant=true;
        Sleep(1500);
        system("cls");
        shop();
    }
    else if(f=='+'){
        cout<<"Vreti sa cumparati tinta cu 200 de bani (da sau nu) ?"<<endl<<endl;
        cout<<"( TINTA reprezinta liniile negre de la minigame 1 )"<<endl;
        string a;
        cin>>a;
        if(a=="da"&&bani>=200) cout<<"Acum aveti tinta !"<<endl, target=true, bani-=200, c_tinta=true;
        Sleep(1500);
        system("cls");
        shop();
    }
    else if(f=='v'){
        cout<<"Vreti sa fiti de doua ori mai rapid cu 200 de bani (da sau nu) ?"<<endl<<endl;
        Sleep(1000);
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
        cout<<"ATENTIE !!!"<<endl;
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
        cout<<"Cu aceasta putere, va veti putea controla mai greu."<<endl<<endl;
        Sleep(1000);
        string a;
        cin>>a;
        if(a=="da"&&bani>=200) cout<<"Acum sunteti de doua ori mai rapid !"<<endl, speed=50, bani-=200, c_speed1=true;
        Sleep(1500);
        system("cls");
        shop();
    }
    else if(f=='V'){
        cout<<"Vreti sa fiti de patru ori mai rapid cu 350 de bani (da sau nu) ?"<<endl<<endl;
        Sleep(1000);
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
        cout<<"ATENTIE !!!"<<endl;
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
        cout<<"Cu aceasta putere, va veti putea controla mult mai greu."<<endl<<endl;
        Sleep(1000);
        string a;
        cin>>a;
        if(a=="da"&&bani>=350) cout<<"Acum sunteti de patru ori mai rapid !"<<endl, speed=0, bani-=350, c_speed2=true;
        Sleep(1500);
        system("cls");
        shop();
    }
    else if(f=='c'&&bani>=50){
        system("cls");
        c_color=true;
        cout<<"Acum puteti schimba culoarea din Manager"<<endl, bani-=50;
        system("pause");
        system("cls");
        shop();
    }
    else if(f=='C'&&bani>=1000){
        system("cls");
        c_casa=true, casa=true;
        cout<<"Acum aveti casa"<<endl, bani-=1000;
        system("pause");
        system("cls");
        shop();
    }
    else system("cls");
}

void castig()
{
    char instr;
    start:
    i1=9, i2=30, i3=9;
    string shp="          ";
    hpb1=100, hpb2=100;
    time_s=0, time_sp=0;
    c=(char)219, persb=(char)1, persr=(char)2;
    s1="", s2="", s3="";
    finnal();
    while(i2>1){
        Sleep(100);
        i1++;
        i2--;
        system("cls");
        time_s++;
        time_sp++;
        finnal();
    }
    while(hpb2>0){
        Sleep(100);
        hpb2=hpb2-10;
        time_s++;
        time_sp++;
        system("cls");
        finnal();
    }
    persr=' ';
    system("cls");
    finnal();
}

void revenire()
{
    char instr;
    start:
    i1=9, i2=30, i3=9;
    string shp="          ";
    hpb1=100, hpb2=0;
    time_s=0, time_sp=0;
    c=(char)219, persb=' ', persr=' ';
    s1="", s2="", s3="";
    finnal();
    while(hpb2<30){
        Sleep(1000);
        hpb2=hpb2+10;
        if(hpb2!=0) persr=(char)2;
        system("cls");
        finnal();
    }
    Sleep(2000);
    while(i1+1+i2+1<=50){
        Sleep(100);
        i2++;
        system("cls");
        finnal();
    }
    Sleep(1000);
    persr=' ';
    system("cls");
    finnal();
}

void story_minig1()
{
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
    cout<<"Dupa ce ati invins atitia inamici ..."<<endl;
    Sleep(2000);
    system("cls");
    castig();
    grave_1();
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
    system("cls");
    cout<<"Totusi unii au scapat ..."<<endl;
    Sleep(2000);
    system("cls");
    revenire();
    grave_2();
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
    system("cls");
    cout<<"Prinde-tii si aduce-tii inapoi !"<<endl<<endl;
    Sleep(1000);
    cout<<"( Acum nu va mai pot face nimic )"<<endl<<endl;
    system("pause");
    system("cls");
}

void story_minig2()
{
    cout<<"Plimbandu-va prin sala de antrenament, ati descoperit o camera secreta ."<<endl<<endl;
    Sleep(3000);
    cout<<"Arata ca un fel de labirint ..."<<endl<<endl;
    grave_1();
    system("pause");
    system("cls");
    cout<<"Cu cat ajungeti mai repede la sageata, cu atat primiti mai multi bani."<<endl<<endl;
    cout<<"Pentru a colecta banii ($), apasati ENTER."<<endl<<endl;
    cout<<"Daca sunteti la un pas de cei rai ("<<(char)2<<"), acestia vor veni dupa tine."<<endl<<endl;
    cout<<"Daca sunteti lipit de un inamic sau daca depasiti limita de timp, veti pierde."<<endl<<endl;
    cout<<"Insa, daca treceti foarte repede pe langa acestia, nu vor avea timp sa se miste."<<endl<<endl;
    system("pause");
    system("cls");
}

void puncte()
{
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
    cout<<"Puncte : ";
    for(int i=1;i<=points;i++){
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
        if(i%10==0) points-=10, nivel++;
        cout<<(char)219;
    }
    cout<<endl<<endl;
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
    cout<<"Nivel : "<<nivel;
    cout<<endl<<endl;
}

void tinta()
{
    puncte();
    char a[x+1][2*x+1];
    for(int i=1;i<=x;i++){
        for(int j=1;j<=2*x;j++){
            a[i][j]=(char)219;
        }
    }
    a[q][w]=(char)2;
    for(int i=1;i<=x;i++){
        for(int j=1;j<=2*x;j++){
            if(nivel<2||target){
            if(q==n&&m==w) SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15), a[i][j]=(char)1, cout<<a[i][j];
            else if(i==n&&j==m) SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15), a[i][j]=(char)1, cout<<a[i][j];
            else if (i==q&&j==w) SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15), cout<<a[i][j];
            else if(i==n^j==m) SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0), cout<<a[i][j];
            else SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color), cout<<a[i][j];
            }
            else{
            if(q==n&&m==w) SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15), a[i][j]=(char)1, cout<<a[i][j];
            else if(i==n&&j==m) SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15), a[i][j]=(char)1, cout<<a[i][j];
            else if (i==q&&j==w) SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15), cout<<a[i][j];
            else SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color), cout<<a[i][j];
            }
        }
        cout<<endl;
    }
}

void minigame_free()
{
    nivel=0, points=0;
    tinta();
    start:
    if(q==n&&m==w){
        Sleep(speed);
        q=rand()%x+1;
        w=rand()%x+1;
        points++;
        system("cls");
        tinta();
        goto start;
    }
    else if(GetAsyncKeyState(VK_LEFT)&&m>=1){
        Sleep(speed);
        m--;
        system("cls");
        tinta();
        goto start;
    }
    else if(GetAsyncKeyState(VK_RIGHT)&&m<=2*x){
        Sleep(speed);
        m++;
        system("cls");
        tinta();
        goto start;
    }
    else if(GetAsyncKeyState(VK_UP)&&n>=1){
        Sleep(speed);
        n--;
        system("cls");
        tinta();
        goto start;
    }
    else if(GetAsyncKeyState(VK_DOWN)&&n<=x){
        Sleep(speed);
        n++;
        system("cls");
        tinta();
        goto start;
    }
    else if(GetAsyncKeyState(VK_SPACE)){
        Sleep(speed);
        system("cls");
        bani+=(nivel*10+points)*3;
    }
    else goto start;
    system("cls");
}

void tinta1()
{
    char a[x+1][2*x+1];
    for(int i=1;i<=x;i++){
        for(int j=1;j<=2*x;j++){
            a[i][j]=(char)219;
        }
    }
    a[q][w]=(char)2;
    for(int i=1;i<=x;i++){
        for(int j=1;j<=2*x;j++){
            if(target){
            if(q==n&&m==w) SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15), a[i][j]=(char)1, cout<<a[i][j];
            else if(i==n&&j==m) SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15), a[i][j]=(char)1, cout<<a[i][j];
            else if (i==q&&j==w) SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15), cout<<a[i][j];
            else if(i==n^j==m) SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0), cout<<a[i][j];
            else SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color), cout<<a[i][j];
            }
            else{
            if(q==n&&m==w) SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15), a[i][j]=(char)1, cout<<a[i][j];
            else if(i==n&&j==m) SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15), a[i][j]=(char)1, cout<<a[i][j];
            else if (i==q&&j==w) SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15), cout<<a[i][j];
            else SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color), cout<<a[i][j];
            }
        }
        cout<<endl;
    }
}

void minigame_time()
{
    nivel=0, points=0;
    time1=timp();
    start:
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
    cout<<"Bani : "<<bani<<endl<<endl;
    cout<<"Timp : "<<timp()-time1<<endl<<endl;
    tinta1();
    controls:
    if(q==n&&m==w){
        Sleep(speed);
        q=rand()%x+1;
        w=rand()%x+1;
        if(timp()-time1<=0) bani+=10;
        else if(timp()-time1<=1) bani+=6;
        else if(timp()-time1<=2) bani+=5;
        else if(timp()-time1<=3) bani+=3;
        else if(timp()-time1<=4) bani+=2;
        else if(timp()-time1<=5) bani+=1;
        time1=timp();
        system("cls");
        goto start;
    }
    else if(GetAsyncKeyState(VK_LEFT)&&m>=1){
        Sleep(speed);
        m--;
        system("cls");
        goto start;
    }
    else if(GetAsyncKeyState(VK_RIGHT)&&m<=2*x){
        Sleep(speed);
        m++;
        system("cls");
        goto start;
    }
    else if(GetAsyncKeyState(VK_UP)&&n>=1){
        Sleep(speed);
        n--;
        system("cls");
        goto start;
    }
    else if(GetAsyncKeyState(VK_DOWN)&&n<=x){
        Sleep(speed);
        n++;
        system("cls");
        goto start;
    }
    else if(GetAsyncKeyState(VK_SPACE)){
        Sleep(speed);
        system("cls");
    }
    else goto controls;
    system("cls");
}

void labirint_1()
{
    start:
    int timp1=timp();
    int line=1, column=1;
    char h[11][25]={ o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o,
                     v, b, s, s, s, s, s, s, s, s, s, s, s, s, s, s, s, s, s, s, d, s, r, s, v,
                     v, o, o, o, o, o, o, s, s, s, o, o, o, o, o, o, o, o, o, o, o, o, o, o, v,
                     v, s, s, s, s, s, v, s, s, s, v, s, s, s, s, s, s, s, s, s, v, s, r, s, v,
                     v, o, o, o, o, o, o, s, s, s, o, o, o, o, o, o, o, o, o, o, o, s, s, s, v,
                     v, r, s, d, s, s, s, s, s, s, s, s, s, s, s, s, s, s, s, s, s, s, s, s, v,
                     v, o, o, o, o, o, o, s, r, s, o, o, o, o, o, o, o, o, o, o, o, s, s, s, v,
                     v, s, s, s, s, s, v, o, o, o, v, s, s, s, s, s, s, s, s, s, v, s, s, s, v,
                     v, o, o, o, o, o, o, s, s, s, o, o, o, o, o, o, o, o, o, o, o, s, s, s, v,
                     v, t, s, s, s, s, s, s, s, s, s, s, s, s, s, s, s, s, s, s, s, s, s, s, v,
                     o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o};
    inceput:
    system("cls");
    cout<<"Bani : "<<bani<<endl<<endl;
    cout<<"Timp : "<<timp()-timp1<<endl<<endl;
    for(int i=0;i<11;i++){
        for(int j=0;j<25;j++) cout<<h[i][j];
        cout<<endl;
    }
    controls:
    if(GetAsyncKeyState(VK_RIGHT)&&h[line][column+1]==' ')
    {
        Sleep(speed);
        system("cls");
        char aux=h[line][column];
        h[line][column]=h[line][column+1];
        h[line][column+1]=aux;
        column++;
        goto inceput;
    }
    else if(GetAsyncKeyState(VK_LEFT)&&h[line][column-1]==' ')
    {
        Sleep(speed);
        system("cls");
        char aux=h[line][column];
        h[line][column]=h[line][column-1];
        h[line][column-1]=aux;
        column--;
        goto inceput;
    }
    else if(GetAsyncKeyState(VK_DOWN)&&h[line+1][column]==' ')
    {
        Sleep(speed);
        system("cls");
        char aux=h[line][column];
        h[line][column]=h[line+1][column];
        h[line+1][column]=aux;
        line++;
        goto inceput;
    }
    else if(GetAsyncKeyState(VK_UP)&&h[line-1][column]==' ')
    {
        Sleep(speed);
        system("cls");
        char aux=h[line][column];
        h[line][column]=h[line-1][column];
        h[line-1][column]=aux;
        line--;
        goto inceput;
    }
    else if(GetAsyncKeyState(VK_RETURN)&&(h[line][column+1]==d||h[line][column-1]==d||h[line-1][column]==d||h[line+1][column]==d))
    {
        Sleep(speed);
        system("cls");
        if(h[line][column+1]==d){
            bani+=10;
            h[line][column+1]=' ';
        }
        else if(h[line][column-1]==d){
            bani+=10;
            h[line][column-1]=' ';
        }
        else if(h[line+1][column]==d){
            bani+=10;
            h[line+1][column]=' ';
        }
        else if(h[line-1][column]==d){
            bani+=10;
            h[line-1][column]=' ';
        }
        goto inceput;
    }
    else if(h[line][column+2]==r||h[line][column-2]==r||h[line-2][column]==r||h[line+2][column]==r)
    {
        system("cls");
        if(h[line][column+2]==r){
            h[line][column+1]=r;
            h[line][column+2]=' ';
        }
        else if(h[line][column-2]==r){
            h[line][column-1]=r;
            h[line][column-2]=' ';
        }
        else if(h[line+2][column]==r){
            h[line+1][column]=r;
            h[line+2][column]=' ';
        }
        else if(h[line-2][column]==r){
            h[line-1][column]=r;
            h[line-2][column]=' ';
        }
        goto inceput;
    }
    else if(GetAsyncKeyState(VK_RETURN)&&h[line][column-1]==t)
    {
        Sleep(100);
        cout<<endl<<endl;
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10);
        cout<<"You won!"<<endl;
        if(timp()-timp1<=5) bani+=20;
        else if(timp()-timp1<=10) bani+=15;
        else if(timp()-timp1<=15) bani+=10;
        else if(timp()-timp1<=20) bani+=5;
        system("pause");
        if(GetAsyncKeyState(VK_RETURN)) {
            system("cls");
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
            goto start;
        }
    }
    else if(h[line][column+1]==r||h[line][column-1]==r||h[line-1][column]==r||h[line+1][column]==r||timp()-timp1>25)
    {
        Sleep(100);
        cout<<endl<<endl;
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
        cout<<"You lost!"<<endl;
        Sleep(1000);
        system("pause");
        if(GetAsyncKeyState(VK_RETURN)) {
            system("cls");
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
            goto start;
        }
    }
    else goto controls;
    system("cls");
}

// POWER MANAGER

void pow_manager()
{
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
    cout<<"Puteri :"<<endl<<endl;
    Sleep(20*speed);
    cout<<"1.Foc :";
    if(foc) cout<<"ACTIVATED"<<endl<<endl;
    else cout<<"DISABLED"<<endl<<endl;
    Sleep(3*speed);
    cout<<"2.Electro :";
    if(electro) cout<<"ACTIVATED"<<endl<<endl;
    else cout<<"DISABLED"<<endl<<endl;
    Sleep(3*speed);
    cout<<"3.Vant :";
    if(vant) cout<<"ACTIVATED"<<endl<<endl;
    else cout<<"DISABLED"<<endl<<endl;
    Sleep(3*speed);
    cout<<"+ Tinta :";
    if(target) cout<<"ACTIVATED"<<endl<<endl;
    else cout<<"DISABLED"<<endl<<endl;
    Sleep(3*speed);
    cout<<"v Speed Boost 1 :";
    if(speed==50) cout<<"ACTIVATED"<<endl<<endl;
    else cout<<"DISABLED"<<endl<<endl;
    Sleep(3*speed);
    cout<<"V Speed Boost 2 :";
    if(speed==0) cout<<"ACTIVATED"<<endl<<endl;
    else cout<<"DISABLED"<<endl<<endl;
    Sleep(3*speed);
    cout<<"Altele :"<<endl<<endl;
    cout<<"L.Locatie : ";
    if(casa) cout<<"Casa"<<endl<<endl;
    else if(c_win_boss)cout<<"Castel"<<endl<<endl;
    else cout<<"Templu"<<endl<<endl;
    cout<<"C.Culoare : ";
    switch (color)
    {
        case 0:cout<<"Negru"<<endl<<endl; break;
        case 1:cout<<"Albastru Inchis"<<endl<<endl; break;
        case 2:cout<<"Verde Inchis"<<endl<<endl; break;
        case 3:cout<<"Turqoise Inchis"<<endl<<endl; break;
        case 4:cout<<"Rosu Inchis"<<endl<<endl; break;
        case 5:cout<<"Mov (Inchis)"<<endl<<endl; break;
        case 6:cout<<"Galben Inchis"<<endl<<endl; break;
        case 7:cout<<"Alb Inchis"<<endl<<endl; break;
        case 8:cout<<"Gri"<<endl<<endl; break;
        case 9:cout<<"Albastru Deschis"<<endl<<endl; break;
        case 10:cout<<"Verde Deschis"<<endl<<endl; break;
        case 11:cout<<"Turqoise Deschis (Aqa)"<<endl<<endl; break;
        case 12:cout<<"Rosu Deschis"<<endl<<endl; break;
        case 13:cout<<"Roz"<<endl<<endl; break;
        case 14:cout<<"Galben Deschis"<<endl<<endl; break;
        case 15:cout<<"Alb Deschis"<<endl<<endl; break;
    }
    char f;
    cin>>f;
    if(f=='1'&&foc==false&&c_foc){
        cout<<"Vreti sa activati puterea focului (da sau nu) ?"<<endl;
        string a;
        cin>>a;
        if(a=="da") cout<<"Acum aveti puterea focului !"<<endl, foc=true, c_foc=true;
        Sleep(1500);
        system("cls");
        pow_manager();
    }
    else if(f=='1'&&foc==true&&c_foc){
        cout<<"Vreti sa dezactivati puterea focului (da sau nu) ?"<<endl;
        string a;
        cin>>a;
        if(a=="da") cout<<"Acum nu mai aveti puterea focului !"<<endl, foc=false, c_foc=true;
        Sleep(1500);
        system("cls");
        pow_manager();
    }
    else if(f=='2'&&electro==false&&c_electro){
        cout<<"Vreti sa activati puterea focului (da sau nu) ?"<<endl;
        string a;
        cin>>a;
        if(a=="da") cout<<"Acum aveti puterea electricitatii !"<<endl, electro=true, c_electro=true;
        Sleep(1500);
        system("cls");
        pow_manager();
    }
    else if(f=='2'&&electro==true&&c_electro){
        cout<<"Vreti sa dezactivati puterea focului (da sau nu) ?"<<endl;
        string a;
        cin>>a;
        if(a=="da") cout<<"Acum nu mai aveti puterea electricitatii !"<<endl, electro=false, c_electro=true;
        Sleep(1500);
        system("cls");
        pow_manager();
    }
    else if(f=='3'&&vant==false&&c_vant){
        cout<<"Vreti sa activati puterea vantului (da sau nu) ?"<<endl;
        string a;
        cin>>a;
        if(a=="da") cout<<"Acum aveti puterea vantului !"<<endl, vant=true, c_vant=true;
        Sleep(1500);
        system("cls");
        pow_manager();
    }
    else if(f=='3'&&vant==true&&c_vant){
        cout<<"Vreti sa dezactivati puterea vantului (da sau nu) ?"<<endl;
        string a;
        cin>>a;
        if(a=="da") cout<<"Acum nu mai aveti puterea vantului !"<<endl, vant=false, c_vant=true;
        Sleep(1500);
        system("cls");
        pow_manager();
    }
    else if(f=='+'&&target==false&&c_tinta){
        cout<<"Vreti sa activati tinta (da sau nu) ?"<<endl;
        string a;
        cin>>a;
        if(a=="da") cout<<"Acum aveti tinta !"<<endl, target=true, c_tinta=true;
        Sleep(1500);
        system("cls");
        pow_manager();
    }
    else if(f=='+'&&target==true&&c_tinta){
        cout<<"Vreti sa dezactivati tinta (da sau nu) ?"<<endl;
        string a;
        cin>>a;
        if(a=="da") cout<<"Acum nu mai aveti tinta !"<<endl, target=false, c_tinta=true;
        Sleep(1500);
        system("cls");
        pow_manager();
    }
    else if(f=='v'&&(speed==100||speed==0)&&c_speed1){
        cout<<"Vreti sa activati Speed Boost 1 (da sau nu) ?"<<endl<<endl;
        Sleep(1000);
        string a;
        cin>>a;
        if(a=="da") cout<<"Acum aveti Speed Boost 1 !"<<endl, speed=50, c_speed1=true;
        Sleep(1500);
        system("cls");
        pow_manager();
    }
    else if(f=='v'&&(speed==50)&&c_speed1){
        cout<<"Vreti sa dezactivati Speed Boost 1 (da sau nu) ?"<<endl<<endl;
        Sleep(1000);
        string a;
        cin>>a;
        if(a=="da") cout<<"Acum nu mai aveti Speed Boost 1 !"<<endl, speed=100, c_speed1=true;
        Sleep(1500);
        system("cls");
        pow_manager();
    }
    else if(f=='V'&&(speed==100||speed==50)&&c_speed2){
        cout<<"Vreti sa activati Speed Boost 2 (da sau nu) ?"<<endl<<endl;
        Sleep(1000);
        string a;
        cin>>a;
        if(a=="da") cout<<"Acum aveti Speed Boost 2 !"<<endl, speed=0, c_speed2=true;
        Sleep(1500);
        system("cls");
        pow_manager();
    }
    else if(f=='V'&&(speed==0)&&c_speed2){
        cout<<"Vreti sa dezactivati Speed Boost 2 (da sau nu) ?"<<endl<<endl;
        Sleep(1000);
        string a;
        cin>>a;
        if(a=="da") cout<<"Acum nu mai aveti Speed Boost 2 !"<<endl, speed=100, c_speed2=true;
        Sleep(1500);
        system("cls");
        pow_manager();
    }
    else if(f=='C'&&c_color){
        system("cls");
        cout<<"Culori Inchise :"<<endl<<endl;
        cout<<"0.Negru"<<endl;
        cout<<"1.Albastru"<<endl;
        cout<<"2.Verde"<<endl;
        cout<<"3.Turqoise"<<endl;
        cout<<"4.Rosu"<<endl;
        cout<<"5.Mov"<<endl;
        cout<<"6.Galben"<<endl;
        cout<<"7.Alb"<<endl;
        cout<<"8.Gri"<<endl<<endl;
        cout<<"Culori Deschise"<<endl<<endl;
        cout<<"9.Albastru"<<endl;
        cout<<"10.Verde"<<endl;
        cout<<"11.Aqa (Turqoise)"<<endl;
        cout<<"12.Rosu"<<endl;
        cout<<"13.Roz"<<endl;
        cout<<"14.Galben"<<endl;
        cout<<"15.Alb"<<endl<<endl;
        cout<<"Exit"<<endl<<endl;
        int alc;
        cin>>alc;
        color=alc;
        cout<<"Exemplu : ";
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
        for(int iu=1;iu<=5;iu++) cout<<(char)219;
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
        cout<<endl;
        system("pause");
        system("cls");
        pow_manager();
    }
    else if(f=='L'&&c_win_boss&&win_boss){
        if(c_casa&&!casa){
        cout<<"Doriti sa mergeti la casa (da sau nu) ?"<<endl<<endl;
        string a1;
        cin>>a1;
        if(a1=="da") win_boss=false, c_win_boss=true;
        }
        else if(c_casa&&casa){
        cout<<"Doriti sa mergeti la castel (da sau nu) ?"<<endl<<endl;
        string a1;
        cin>>a1;
        if(a1=="da") win_boss=false, c_win_boss=true;
        }
        else if(c_win_boss&&win_boss){
        cout<<"Doriti sa mergeti la templu (da sau nu) ?"<<endl<<endl;
        string a1;
        cin>>a1;
        if(a1=="da") win_boss=false, c_win_boss=true;
        }
        else if(c_win_boss&&!win_boss){
        cout<<"Doriti sa mergeti la castel (da sau nu) ?"<<endl<<endl;
        string a2;
        cin>>a2;
        if(a2=="da") win_boss=true, c_win_boss=true;
        }
        system("cls");
        pow_manager();
    }
    else system("cls");
}

void casuta()
{
    char c=196;
    int n=7, m=16;
    // ACOPERIS
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
    for(int i = 1 ; i <= n - 1 ; i ++) cout << " ";
    cout<<(char)218;
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
    for(int i=1; i<=m-2;i++) cout << c ;
    cout<<(char)191;
    cout<<endl;

    for(int i = 2 ; i <= n - 1 ; i ++)
    {
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
        for(int j = 1 ; j <= n - i; j ++)
            cout << " ";
        cout << (char)218;

        for(int j = 1 ; j <= 2 * i - 3 ; j ++)
            cout << ' ';
        cout << (char)191;
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
        for(int j=1;j<=m-2;j++) cout<<' ';
        cout << (char)191 << endl;
    }
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
    for(int i = 1 ; i <= 2*(n-1)+1 ; i ++){
            cout << c ;
    }
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
    for(int i=1;i<=m-1;i++) cout<<c;
    cout<<endl;
    // MAIN


    for(int r=1;r<=n-2;r++)
    {
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
    cout<<(char)179;
    for(int i=1;i<=2*n-3;i++) cout<<' ';
    cout<<(char)179;
    for(int i=1;i<=m-2;i++) cout<<' ';
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
    cout<<(char)179;
    cout<<endl;
    }
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
    for(int i=1;i<=n-1;i++) cout<<c;
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
    cout<<c;
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
    for(int i=1;i<=n-1;i++) cout<<c;
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
    for(int i=1;i<=m-2;i++) cout<<c;
    cout<<c;
    cout<<endl;
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
}

void meniu()
{
    cout<<"Bani :";
    cout<<bani<<endl<<endl;
    if (casa) casuta();
    else if(win_boss) castelb();
    else templu();
    string s="";
    for(int i=1;i<=10;i++) s+=" ";
    cout<<endl;
    cout<<s<<"1.";
    cout<<"Battle"<<endl<<endl;
    cout<<s<<"2.";
    cout<<"Training"<<endl<<endl;
    cout<<s<<"3.";
    cout<<"Shop"<<endl<<endl;
    cout<<s<<"4.";
    cout<<"Minigame"<<endl<<endl;
    cout<<s<<"5.";
    cout<<"Power Manager"<<endl<<endl;
    cout<<s<<"6.";
    cout<<"Profile Change"<<endl<<endl;
    int fila;
    cin>>fila;
    if(fila==1){
        system("cls");
        cout<<"Alege nivelul :"<<endl<<endl, Sleep(2000);
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10), cout<<"1.Foarte usor"<<endl<<endl, Sleep(300);
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10), cout<<"2.Usor"<<endl<<endl, Sleep(300);
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14), cout<<"3.Mediu"<<endl<<endl, Sleep(300);
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14), cout<<"4.Mediu"<<endl<<endl, Sleep(300);
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12), cout<<"5.Greu"<<endl<<endl, Sleep(300);
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12), cout<<"6.Foarte Greu"<<endl<<endl, Sleep(300);
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12), cout<<"7.BOSSUL"<<endl<<endl, Sleep(300);
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15), cout<<"8.Exit"<<endl<<endl, Sleep(300);
        int level;
        cin>>level;
        switch(level)
        {
            case 1:system("cls"), battle_1(); break;
            case 2:system("cls"), battle_2(); break;
            case 3:system("cls"), battle_3(); break;
            case 4:system("cls"), battle_mediu(); break;
            case 5:system("cls"), battle_4(); break;
            case 6:system("cls"), battle_fgreu(); break;
            case 7:system("cls"), battle_boss(); break;
        }
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
        system("cls");
        meniu();
    }
    else if(fila==2){
        system("cls");
        train();
        meniu();
    }
    else if(fila==3){
        system("cls");
        shop();
        meniu();
    }
    else if(fila==4){
        system("cls");
        cout<<"1.Catch the bad boy"<<endl<<endl;
        cout<<"2.Labirinth"<<endl<<endl;
        int m;
        cin>>m;
        system("cls");
        if(m==1){
            cout<<"Do you want to watch the story (da sau nu) ?"<<endl<<endl;
            string y;
            cin>>y;
            if(y=="da") story_minig1();
            cout<<"1.Free Mode"<<endl;
            cout<<"( smal rewards, but sure )"<<endl<<endl;
            cout<<"2.Time Mode"<<endl;
            cout<<"( big rewars if you are fast, else nothing )"<<endl<<endl;
            int a;
            cin>>a;
            if(a==1){
                system("cls");
                minigame_free();
            }
            else if(a==2){
                system("cls");
                cout<<"Reguli :"<<endl<<endl;
                cout<<"0 secunde  "<<(char)26<<"  10 bani"<<endl;
                cout<<"1 secunde  "<<(char)26<<"  6 bani"<<endl;
                cout<<"2 secunde  "<<(char)26<<"  5 bani"<<endl;
                cout<<"3 secunde  "<<(char)26<<"  3 bani"<<endl;
                cout<<"4 secunde  "<<(char)26<<"  2 bani"<<endl;
                cout<<"5 secunde  "<<(char)26<<"  1 bani"<<endl<<endl;
                cout<<"Deci jucati ( da sau nu ) ?"<<endl<<endl;
                string afi;
                cin>>afi;
                if(afi=="da"){
                    system("cls");
                    minigame_time();
                }
                else system("cls"),meniu();
            }
        }
        else if(m==2){
            cout<<"Do you want to watch the story (da sau nu) ?"<<endl<<endl;
            string z;
            cin>>z;
            if(z=="da") story_minig2();
            cout<<"Limita de timp : 25 secunde"<<endl<<endl;
            system("pause");
            system("cls");
            labirint_1();
        }
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
        system("cls");
        meniu();
    }
    else if(fila==5){
        system("cls");
        pow_manager();
        meniu();
    }
    else if(fila==6){
        change_profile();
        meniu();
    }
    else {
        cout<<"Do you want to exit the game (da sau nu) ?"<<endl<<endl;
        string x;
        cin>>x;
        if(x=="da") cout<<endl<<"Good Bye!", Sleep(2000);
        else system("cls"), meniu();
    }
}

int main()
{
    string a,e;
    char y;
    bool bun;
    cout<<"Ai deja un cont (da sau nu) ?"<<endl;
    string logare;
    cin>>logare;
    if(logare=="da"||logare=="DA"||logare=="Da") {
        int f, z, w;           // fire zap wind
        system("cls");
        log();
        bani_in>>bani;
        p_in>>f>>z>>w;
        if(f!=0)
        foc=true, c_foc=true;
        if(z!=0)
        electro=true, c_electro=true;
        if(w!=0)
        vant=true, c_vant=true;
        meniu();
        ofstream bani_out("bani.txt");
        bani_out<<bani;
        bani_out.close();
        ofstream p_out("powers.txt");
        p_out<<foc<<' '<<electro<<' '<<vant;
        p_out.close();

    }
    else{
    cout<<"Penru a continua, ai nevoie de un cont."<<endl;
    Sleep(1000);
    create_profil();
    cout<<"Va prezentam sala de antrenament, pe interior."<<endl<<endl;
    Sleep(2000);
    antrenament_basic();
    cout<<"Acestea sunt echipele :"<<endl<<endl;                          //alegere caracter si echipa
    Sleep(1000);
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
    cout<<"Echipa de foc ."<<endl<<endl;
    Sleep(1000);
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 3);
    cout<<"Echipa de fulger ."<<endl<<endl;
    Sleep(1000);
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 9);
    cout<<"Echipa de vant"<<endl<<endl;
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);//system("color fc");
    Sleep(3000);
    system("cls");
    cout<<"Alege-ti echipa (foc, fulger, vant) :";
    cin>>e;
    system("CLS");
    if(e=="foc")                                                                //dupa alegerea echipei de foc
    {
     SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
     cout<<"FELICITARI PENTRU ALEGEREA FACUTA !"<<endl<<"Ai intrat in echipa de foc .";
     Sleep(2000), bun=true, foc=true, c_foc=true;
    }
    if(e=="fulger")                                                                //dupa alegerea echipei de apa
    {SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 3);
     cout<<"FELICITARI PENTRU ALEGEREA FACUTA !"<<endl<<"Ai intrat in echipa de fulger .";
     Sleep(2000), bun=true, electro=true, c_electro=true;
    }
    if(e=="vant")                                                             //dupa alegerea echipei de pamant
    {SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 9);
     cout<<"FELICITARI PENTRU ALEGEREA FACUTA !"<<endl<<"Ai intrat in echipa de vant .";
     Sleep(2000), bun=true, vant=true, c_vant=true;
    }
    system("CLS");
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
    cout<<"Misiunea ta este de a invinge dusmanul numarul unu al nostru ."
    <<endl<<endl<<"Acesta se numeste BOSSUL si este maestrul distrugerii ."
    <<endl<<endl<<"Nimeni pana acum nu a reusit sa il invinga ,dar tu o poti face ..."<<endl<<endl;
     system("pause");
     cout<<"Pentru inceput va trebui sa il cunosti pe BOSSUL ...";
     Sleep(4000);
     system("CLS");
     grave_1();
     cout<<"##  ##           ##  ##                                               "<<endl;
     cout<<"######   *****   ######                                               "<<endl;
     cout<<"######   *BOS*   ######                                               "<<endl;
     cout<<"######   *SUL*   ######                                               "<<endl;
     cout<<"###########*###########                                               "<<endl;
     cout<<"##########*|*##########                                               "<<endl;
     cout<<"##### | #*|||*# | #####      **   **                                  "<<endl;
     cout<<"#####-+-#*|||*#-+-#####     **** ****                                 "<<endl;
     cout<<"##### | #*|||*# | #####      **   **                                  "<<endl;
     cout<<"#########=====#########      ||   ||                                  "<<endl;
     cout<<"....... #=====# .......      || $ ||                                  "<<endl;
     cout<<"....... #=====# .......                                               "<<endl;
     cout<<"....... #=====# .......                                               "<<endl;
     cout<<"                                                                      "<<endl;
     cout<<"In stanga se afla castelul lui BOSSUL ,iar in                         "<<endl;
     cout<<"          dreapta este BOSSUL ($).                                    "<<endl;
     grave_2();
     system("pause");
     system("CLS");
     cout<<"Esti sigur ca esti pregatit pentru o asemenea aventura (da sau nu) ?"<<endl;
     string aleg;
     cin>>aleg;
     if(aleg=="da"){
            cout<<"Succes!";
            system("cls");
            cout<<"Asa arata sala de antrenament pe exterior !"<<endl<<endl;
            bani=50;
            meniu();
            ofstream bani_out("bani.txt");
            bani_out<<bani;
            ofstream p_out("powers.txt");
            p_out<<c_foc<<' '<<c_electro<<' '<<c_vant;
            p_out.close();
            bani_out.close();
            return 0;
     }
     else {cout<<"Atunci nu esti demn de noi !";Sleep(5000);return 0;}
    }
}


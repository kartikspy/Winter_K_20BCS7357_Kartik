#include <bits/stdc++.h>
using namespace std;

void reverse(string s,int n){
    for(int i=0; i<n/2; i++){
        char ch=s[i];
        s[i]=s[n-1-i];
        s[n-1-i]=ch;
    }
    for (int k=0; k<n; k++){
        cout<<s[k]<<" ";
    }
    cout<<endl;
}
int stringlength(string s)
{
    int t=0;
     while(s[t]!='\0')
        t++;
    return t;
}

void StringConcat(string s, string s1){
    int n=0;
    while(s[n]!='\0'){
        n++;
    }
    int j=0;
    while(s1[j]!='\0'){
        s[n]=s1[j];
        n++;
        j++;
    }
     s[n]='\0';
     int i=0;
   while(s[i]!='\0'){
        cout<<s[i];
        i++;
    }
    cout<<endl;
}

void Copy(string s, string cp){
    int a=0;
    while(s[a]!='\0'){
        cp[a]=s[a];
        a++;
    }
    int i=0;
    while(cp[i]!='\0'){
        cout<<cp[i];
        i++;
    }
}

int main(){
    string s="Kartik";
    string s1="Kishore";
// ------------------------String Length--------------------------------------------------------- //
    cout<<stringlength(s)<<endl;
//-------------------------String Concatenate-----------------------------------------------------// 
     StringConcat(s,s1);
//----------------------- String Reverse ---------------------------------------------------------//
     reverse(s1,stringlength(s1));

//-----------------------String Copy ------------------------------------------------------------//
     string cp="";
     Copy(s,cp);
}

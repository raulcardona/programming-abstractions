//I think this is a simpler code for solving this dial pad problem 

#include <iostream>
#include <string>
#include <stdlib.h>
#include "vector.h"
#include "set.h"
#include "strlib.h"
Set<string> newFunction(string str, int index);
string returnMnemonicString(char ch);

int main(){
    string str = getLine("Enter a word: ");
   for(string s :newFunction(str, 0)){
      cout << s << " ";
   }
return 0;
}

Set<string> newFunction(string str, int index){
  Set<string> result;
  if(index == str.length()){
      result+= "";
  }else{
      string stri = returnMnemonicString(str[index]);
      for(int i = 0; i < stri.length(); i++){
          char ch = stri[i];
          for(string s:newFunction(str, index+1)){
          result += ch+s;
          }
      }
  }
return result;
}

string returnMnemonicString(char ch){
    switch(ch){
    case '2': return "ABC"; break;
    case '3': return "DEF"; break;
    case '4': return "GHI";  break;
    case '5': return "JKL"; break;
    case '6': return "MNO"; break;
    case '7': return "PQRS"; break;
    case '8': return "TUV"; break;
    case '9': return "WXYZ"; break;
   }
return 0;
}


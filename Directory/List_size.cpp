#include <iostream>
#include <dirent.h>
#include <fstream>
#include <cstring>
#include <sstream>
#define SSTR( x ) static_cast< std::ostringstream & >( std::ostringstream() << std::dec << x ).str()
using namespace std;
string dir,direccion2,joinstrings,direccion1_2="/";
const char* c;
 

void list_dir(string dir)
  {
    DIR * directorio;
    struct dirent* elemento;
    string elem;
    if (directorio = opendir(dir.c_str()))
    {
        FILE *pf;
        pf=fopen("dir.json","w");
        if ((pf=fopen("dir.json","w"))!=NULL)
          {
            fputs("{\"files\":[\n",pf);
            while (elemento =readdir(directorio))
              {
                elem = elemento -> d_name;
                if (elem !="."&& elem!="..") 
                  {
                    direccion2=elem;
                    joinstrings=dir+direccion1_2+direccion2;
                    c = joinstrings.c_str();
                    ifstream ifs(c);
                    ifs.seekg(0, ios::end);

                    char elemchar[elem.size() + 1];
                    strcpy(elemchar, elem.c_str());
              
                    int i = ifs.tellg() ;
                    std:: string s2=SSTR( i );
                    char s2char[s2.size() + 1];
                    strcpy(s2char, s2.c_str());
                    
                    fputs ("  {\"name\":\"",pf);
                    fputs(elemchar,pf);
                    fputs (",\"size\":",pf);
                    fputs (s2char,pf);
                    fputs("},\n",pf);
                  }
              }
              fputs("]}",pf);
              
          }
   
    }
    else cout<<"This document don't exist\n";
    closedir(directorio);
  } 

int main (int argc, char *argv [])
{
  
  dir=argv[1];
  list_dir(dir);
  
  return -1;
   
}

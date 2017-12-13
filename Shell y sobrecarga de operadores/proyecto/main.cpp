#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>
#include <string.h>
#include <assert.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <windows.h>
#include <stdio.h>
 #include <cstdlib>

#include <conio.h>
#include <iostream.h>


#define MAXARGS 10
using namespace std;
#include <windows.h>
#include "myfecha.h"
#include "Expresion.h"
#include "Polinomio.h"


struct cmd {
  int type;         
};

struct execcmd {
  int type;             
  char *argv[MAXARGS];   
};

struct redircmd {
  int type;          
  struct cmd *cmd;   
  char *file;   
  int mode;     
  int fd;          
};

struct pipecmd {
  int type;          // |
  struct cmd *left;  // left side of pipe
  struct cmd *right; // right side of pipe
};

int fork1(void);  // Fork but exits on failure.
struct cmd *parsecmd(char*);

// Execute cmd.  Never returns.
void
runcmd(struct cmd *cmd)
{
  int p[2], r;
  struct execcmd *ecmd;
  struct pipecmd *pcmd;
  struct redircmd *rcmd;

  if(cmd == 0)
    exit(0);
  
  switch(cmd->type){
  default:
    fprintf(stderr, "unknown runcmd\n");
    exit(-1);

  case ' ':
    ecmd = (struct execcmd*)cmd;
    if(ecmd->argv[0] == 0)
      exit(0);
    
    execvp(ecmd->argv[0],ecmd->argv);

    break;

  case '>':
  	break;
  case '<':
    rcmd = (struct redircmd*)cmd;

    close(rcmd->fd);
    open(rcmd->file,rcmd->mode);
    
    runcmd(rcmd->cmd);
    break;


  }//end switch()
  exit(0);/**/
}//end runcmd()

int
getcmd(char *buf, int nbuf)
{
  
  if (isatty(fileno(stdin)))
    fprintf(stdout, "$ ");
  memset(buf, 0, nbuf);
  fgets(buf, nbuf, stdin);
  if(buf[0] == 0) // EOF
    return -1;
  return 0;
  if(buf[0]=='s'&&buf[1]=='a'&&buf[2]=='l'&&buf[3]=='i'&&buf[4]=='r'){return -1;}
}//end getcmd()

int
main(int argc, char** argv)
{
  static char buf[100];
  int fd, r;
  int count=101;
  int countvar=0;
  string var[100];
  string valvar[100];
  int valnvar[100];
  string nomvar[100];
  int countnomvar=0;
  
  string polino[100];
  int countvarp=0;
  string varp[100];
  string valvarp[100][100];
  int countpass=0;
  int valnvarp[100][100];
  int countnumvarp[100];
  
  STARTUPINFO si;
  PROCESS_INFORMATION pi;
  // Read and run input commands.
  while(getcmd(buf, sizeof(buf))>= 0){
                    
                   
                    
                    while(buf[count--]!=';');
                    if(count<0){printf("\n%s\n",buf);}
                    count=100;
                   
//declarar variables

for(int i=0;i<100;i++){int r=i+1;
if(buf[i]=='='&&buf[r]!='['){
for(int j=0;j<i;j++){var[countvar]=var[countvar]+buf[j];}int o=i+1;


while(buf[o]=='1'||buf[o]=='2'||buf[o]=='3'||buf[o]=='4'||buf[o]=='5'||buf[o]=='6'||buf[o]=='7'||buf[o]=='8'||buf[o]=='9'||buf[o]=='0'){o++;};
for(int j=i+1;j<o;j++){valvar[countvar]=valvar[countvar]+buf[j];}

valnvar[countvar]=atoi(valvar[countvar].c_str());
i=100;
countvar++;
}     
}
//declarar variables end 

//declarar polinomios general
for(int i=0;i<100;i++){int o=i+1;
if(buf[i]=='='&&buf[o]=='['){
for(int j=0;j<i;j++){varp[countpass]=varp[countpass]+buf[j];}
o++;


do{
int p=o;
int m=o;
while(buf[m]=='1'||buf[m]=='2'||buf[m]=='3'||buf[m]=='4'||buf[m]=='5'||buf[m]=='6'||buf[m]=='7'||buf[m]=='8'||buf[m]=='9'||buf[m]=='0'){m++;};    
    
for(int j=o;j<m;j++){valvarp[countpass][countvarp]=valvarp[countpass][countvarp]+buf[j];}
valnvarp[countpass][countvarp]=atoi(valvarp[countpass][countvarp].c_str());
countvarp++;
o=m+1;
countnumvarp[countpass]=countvarp;   
    }
while(buf[o]=='1'||buf[o]=='2'||buf[o]=='3'||buf[o]=='4'||buf[o]=='5'||buf[o]=='6'||buf[o]=='7'||buf[o]=='8'||buf[o]=='9'||buf[o]=='0'&&buf[o]!=']');

i=100;
countpass++;
countvarp=0;

}     
}

//suma de racionales
for(int i=0;i<100;i++){
int v1,v2;
if(buf[i]=='+'){
for(int j=0;j<i;j++){nomvar[countnomvar]=nomvar[countnomvar]+buf[j];}countnomvar++;
for(int j=i+1;j<strlen(buf)-1;j++){nomvar[countnomvar]=nomvar[countnomvar]+buf[j];}countnomvar--;
for(int j=0;j<100;j++){if(nomvar[countnomvar]==var[j]){v1=j;}}countnomvar++;
for(int j=0;j<100;j++){string v=var[j]; if(nomvar[countnomvar]==v){v2=j;}}
i=100;
cout<<valnvar[v1]+valnvar[v2]<<endl<<endl;
for(int j=0;j<100;j++){nomvar[j]="";}countnomvar=0;
}        
}
//fin suma de racionales


//resta racionales
for(int i=0;i<100;i++){
int v1,v2;
if(buf[i]=='-'){
for(int j=0;j<i;j++){nomvar[countnomvar]=nomvar[countnomvar]+buf[j];}countnomvar++;
for(int j=i+1;j<strlen(buf)-1;j++){nomvar[countnomvar]=nomvar[countnomvar]+buf[j];}countnomvar--;
for(int j=0;j<100;j++){if(nomvar[countnomvar]==var[j]){v1=j;}}countnomvar++;
for(int j=0;j<100;j++){string v=var[j]; if(nomvar[countnomvar]==v){v2=j;}}
i=100;
cout<<valnvar[v1]-valnvar[v2]<<endl<<endl;
for(int j=0;j<100;j++){nomvar[j]="";}countnomvar=0;
}        
}
//resta racionales end


//suma de polinomios
for(int i=0;i<100;i++){
int v1,v2;
if(buf[i]=='+'){
for(int j=0;j<i;j++){nomvar[countnomvar]=nomvar[countnomvar]+buf[j];}countnomvar++;
for(int j=i+1;j<strlen(buf)-1;j++){nomvar[countnomvar]=nomvar[countnomvar]+buf[j];}countnomvar--;

for(int j=0;j<100;j++){if(nomvar[countnomvar]==varp[j]){v1=j;}}countnomvar++;
for(int j=0;j<100;j++){if(nomvar[countnomvar]==varp[j]){v2=j;}}
i=100;

Rac *unRacPt=new Rac[countnumvarp[v1]];
for(int j=0;j<countnumvarp[v1];j++){
  *(unRacPt+j)=Rac(valnvarp[v1][j],1);	       }
int e=countnumvarp[v1]-1;
Polinomio Polinomio1(e,unRacPt); 

Rac *unRacPt1=new Rac[countnumvarp[v2]];
for(int j=0;j<countnumvarp[v2];j++){
  *(unRacPt1+j)=Rac(valnvarp[v2][j],1);}  
e=countnumvarp[v2]-1;
Polinomio Polinomio2(e,unRacPt1); 
Polinomio Polinomio3=Polinomio1+Polinomio2;
cout<<Polinomio3<<endl;

for(int j=0;j<100;j++){nomvar[j]="";}countnomvar=0;
}        
}
//suma de polinomios end


//resta de polinomios
for(int i=0;i<100;i++){
int v1,v2;int o=i+1;
if(buf[i]=='-'){
for(int j=0;j<i;j++){nomvar[countnomvar]=nomvar[countnomvar]+buf[j];}countnomvar++;
for(int j=i+1;j<strlen(buf)-1;j++){nomvar[countnomvar]=nomvar[countnomvar]+buf[j];}countnomvar--;

for(int j=0;j<100;j++){if(nomvar[countnomvar]==varp[j]){v1=j;}}countnomvar++;
for(int j=0;j<100;j++){if(nomvar[countnomvar]==varp[j]){v2=j;}}
i=100;

Rac *unRacPt=new Rac[countnumvarp[v1]];
for(int j=0;j<countnumvarp[v1];j++){
  *(unRacPt+j)=Rac(valnvarp[v1][j],1);	       }
int e=countnumvarp[v1]-1;
Polinomio Polinomio1(e,unRacPt); 

Rac *unRacPt1=new Rac[countnumvarp[v2]];
for(int j=0;j<countnumvarp[v2];j++){
  *(unRacPt1+j)=Rac(valnvarp[v2][j],1);}  
e=countnumvarp[v2]-1;
Polinomio Polinomio2(e,unRacPt1); 
Polinomio Polinomio3=Polinomio1-Polinomio2;
cout<<Polinomio3<<endl;

for(int j=0;j<100;j++){nomvar[j]="";}countnomvar=0;
}        
}
//resta de polinomios end


if(buf[0]=='c'&&buf[1]=='l'&&buf[2]=='c'){system("cls");}
if(buf[0]=='m'&&buf[1]=='o'&&buf[2]=='s'&&buf[3]=='t'&&buf[4]=='r'&&buf[5]=='a'&&buf[6]=='r'){ for(int j=0;j<countpass;j++){cout<<varp[j]<<" = [ ";
                                                                     for(int i=0;i<countnumvarp[j];i++){cout<<valnvarp[j][i]<<" ";} cout<<"] "<<endl;}cout<<endl;}

    if(buf[0] == 'c' && buf[1] == 'd' && buf[2] == ' '){
     
      buf[strlen(buf)-1] = 0;  // chop \n
      if(chdir(buf+3) < 0)
        fprintf(stderr, "cannot cd %s\n", buf+3);
      continue;
    }


if(buf[0]=='n'&&buf[1]=='o'&&buf[2]=='t'&&buf[3]=='e'&&buf[4]=='p'&&buf[5]=='a'&&buf[6]=='d'){
ZeroMemory(&si,sizeof(si));
si.cb=sizeof(si);
ZeroMemory(&pi,sizeof(pi));
if(!CreateProcess("C:/Windows/notepad.exe","notepad.exe C:/Users/Sala2/Documents/pro/ejemplo.txt",0,0,0,0,0,0,&si,&pi)){
printf("hsy slgun problema");     
WaitForSingleObject(pi.hProcess,INFINITE);}}
//agragar codigo

  }
  exit(0);
}


struct cmd*
execcmd(void)
{
  struct execcmd *cmd;

  cmd = (struct execcmd *)malloc(sizeof(*cmd));
  memset(cmd, 0, sizeof(*cmd));
  cmd->type = ' ';
  return (struct cmd*)cmd;
}

struct cmd*
redircmd(struct cmd *subcmd, char *file, int type)
{
  struct redircmd *cmd;

  cmd = (struct redircmd *)malloc(sizeof(*cmd));
  memset(cmd, 0, sizeof(*cmd));
  cmd->type = type;
  cmd->cmd = subcmd;
  cmd->file = file;
  cmd->mode = (type == '<') ?  O_RDONLY : O_WRONLY|O_CREAT|O_TRUNC;
  cmd->fd = (type == '<') ? 0 : 1;
  return (struct cmd*)cmd;
}

struct cmd*
pipecmd(struct cmd *left, struct cmd *right)
{
  struct pipecmd *cmd;

  cmd = (struct pipecmd *)malloc(sizeof(*cmd));
  memset(cmd, 0, sizeof(*cmd));
  cmd->type = '|';
  cmd->left = left;
  cmd->right = right;
  return (struct cmd*)cmd;
}

// Parsing

char whitespace[] = " \t\r\n\v";
char symbols[] = "<|>";

int
gettoken(char **ps, char *es, char **q, char **eq)
{
  char *s;
  int ret;
  
  s = *ps;
  while(s < es && strchr(whitespace, *s))
    s++;
  if(q)
    *q = s;
  ret = *s;
  switch(*s){
  case 0:
    break;
  case '|':
  case '<':
    s++;
    break;
  case '>':
    s++;
    break;
  default:
    ret = 'a';
    while(s < es && !strchr(whitespace, *s) && !strchr(symbols, *s))
      s++;
    break;
  }
  if(eq)
    *eq = s;
  
  while(s < es && strchr(whitespace, *s))
    s++;
  *ps = s;
  return ret;
}

int
peek(char **ps, char *es, char *toks)
{
  char *s;
  
  s = *ps;
  while(s < es && strchr(whitespace, *s))
    s++;
  *ps = s;
  return *s && strchr(toks, *s);
}

struct cmd *parseline(char**, char*);
struct cmd *parsepipe(char**, char*);
struct cmd *parseexec(char**, char*);

// make a copy of the characters in the input buffer, starting from s through es.
// null-terminate the copy to make it a string.
char 
*mkcopy(char *s, char *es)
{
  int n = es - s;
  char *c = (char*)malloc(n+1);
  assert(c);
  strncpy(c, s, n);
  c[n] = 0;
  return c;
}

struct cmd*
parsecmd(char *s)
{
  char *es;
  struct cmd *cmd;

  es = s + strlen(s);
  cmd = parseline(&s, es);
  peek(&s, es, "");
  if(s != es){
    fprintf(stderr, "leftovers: %s\n", s);
    exit(-1);
  }
  return cmd;
}

struct cmd*
parseline(char **ps, char *es)
{
  struct cmd *cmd;
  cmd = parsepipe(ps, es);
  return cmd;
}

struct cmd*
parsepipe(char **ps, char *es)
{
  struct cmd *cmd;

  cmd = parseexec(ps, es);
  if(peek(ps, es, "|")){
    gettoken(ps, es, 0, 0);
    cmd = pipecmd(cmd, parsepipe(ps, es));
  }
  return cmd;
}

struct cmd*
parseredirs(struct cmd *cmd, char **ps, char *es)
{
  int tok;
  char *q, *eq;

  while(peek(ps, es, "<>")){
    tok = gettoken(ps, es, 0, 0);
    if(gettoken(ps, es, &q, &eq) != 'a') {
      fprintf(stderr, "missing file for redirection\n");
      exit(-1);
    }
    switch(tok){
    case '<':
      cmd = redircmd(cmd, mkcopy(q, eq), '<');
      break;
    case '>':
      cmd = redircmd(cmd, mkcopy(q, eq), '>');
      break;
    }
  }
  return cmd;
}

struct cmd*
parseexec(char **ps, char *es)
{
  char *q, *eq;
  int tok, argc;
  struct execcmd *cmd;
  struct cmd *ret;
  
  ret = execcmd();
  cmd = (struct execcmd*)ret;

  argc = 0;
  ret = parseredirs(ret, ps, es);
  while(!peek(ps, es, "|")){
    if((tok=gettoken(ps, es, &q, &eq)) == 0)
      break;
    if(tok != 'a') {
      fprintf(stderr, "syntax error\n");
      exit(-1);
    }
    cmd->argv[argc] = mkcopy(q, eq);
    argc++;
    if(argc >= MAXARGS) {
      fprintf(stderr, "too many args\n");
      exit(-1);
    }
    ret = parseredirs(ret, ps, es);
  }
  cmd->argv[argc] = 0;
  return ret;
}


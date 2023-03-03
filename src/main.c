#include <stdio.h>
#include <stdlib.h>
// #include <storage.h>
// #include <explanation.h>


void program_initialization(){
  load_chapters();
  welcome();
  chapters();
  help();
}

void program_exit(){
  printf("Thank you for joining us today in bash tutor
\n \n --- Hope to see you soon! -- \n");
  exit(EXIT_SUCCESS);
}

void welcome()
{
  printf("Welcome to \n\
.-. .-')     ('-.      .-')    ('-. .-. .-') _               .-') _                _  .-')   \n\
\  ( OO )   ( OO ).-. ( OO ). ( OO )  /(  OO) )             (  OO) )              ( \( -O )  \n\ 
 ;-----.\   / . --. /(_)---\_),--. ,--./     '._ ,--. ,--.  /     '._  .-'),-----. ,------.  \n\ 
 | .-.  |   | \-.  \ /    _ | |  | |  ||'--...__)|  | |  |  |'--...__)( OO'  .-.  '|   /`. ' \n\
 | '-' /_).-'-'  |  |\  :` `. |   .|  |'--.  .--'|  | | .-')'--.  .--'/   |  | |  ||  /  | | \n\ 
 | .-. `.  \| |_.'  | '..`''.)|       |   |  |   |  |_|( OO )  |  |   \_) |  |\|  ||  |_.' | \n\
 | |  \  |  |  .-.  |.-._)   \|  .-.  |   |  |   |  | | `-' /  |  |     \ |  | |  ||  .  '.' \n\
 | '--'  /  |  | |  |\       /|  | |  |   |  |  ('  '-'(_.-'   |  |      `'  '-'  '|  |\  \  \n\
 `------'   `--' `--' `-----' `--' `--'   `--'    `-----'      `--'        `-----' `--' '--' \n\
")
}

void chapters(){
    printf("                                        \n\
Chapter List                                        \n\
------------                                        \n\
1) Basic Terminal Keyboard Shortcuts                \n\
2) File and Directory Commands                      \n\
3) Special Characters                               \n\
------------                                        \n\
Enter \"@j N\" or \"@jump N\" to jump to Chapter N  \n\
");
  }

void help(){
  printf("                                        \n\
  Here are the bashtutor commands:                    \n\
  -----                                               \n\
  @h, @help           print this message              \n\
  @q, @quit, Ctrl-C   quit and exit bashtutor         \n\
  -----                                               \n\
  @e, @explain        print current explanation again \n\
  @n, @next           jump to next explanation        \n\
  @p, @previous       jump to previous explanation    \n\
  @j xxx, @jump xxx   jump to explanation xxx         \n\n\
  ");
}

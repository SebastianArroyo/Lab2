#include "p7.h"

void elim_rep(char *cad, int dim){
    int k=0;
    char *no_rep = new char[dim+1];
    no_rep[0]='\0';
    for(int i=0;cad[i]!='\0';i++){
        for(k=0;no_rep[k]!=cad[i] && no_rep[k]!='\0';k++);
        if(no_rep[k]=='\0'){
            no_rep[k]=cad[i];
            cout << cad[i];
        }
    }
    cout << endl;
    delete[] no_rep;
}

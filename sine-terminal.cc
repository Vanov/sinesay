#include <iostream>
#include <sys/ioctl.h>
#include <unistd.h>
#include <cmath>

std::string filler;
int w,h,wdf;
double num_eq;

void update_winsize(){
    struct winsize size;
    ioctl(STDOUT_FILENO,TIOCGWINSZ,&size);
    w=size.ws_col, wdf=size.ws_col/filler.length(), h=size.ws_row;
}

class fill {
   public:
    int max=filler.length();
    int cur=0;
    char charstr(std::string str){
        cur++;
        if(cur>=max) cur=0;
        return str[cur];
    }
};

int main(int argc, char* argv[]){
    try{
        if(argv[1]==""){
            return 0;
            throw 1;
        } else {
            filler=argv[1];
        }
    }
    catch(bool err){
        std::cout << "Program must have an alphanumerical parameter.";
    }
    fill fillet;
    //for(double i=0; true; i=i+.02){
    for(double i=0; true; i=i+.1){
        update_winsize();
        double sine=sin(i);
        double sineup=(sine*w+w)/2;
        for(int ct=0; ct<=sineup; ct++){
            std::cout << fillet.charstr(filler);;
        } std::cout << std::endl;
        usleep(60000);
    }
}

#include <iostream>
#include <sys/ioctl.h>
#include <unistd.h>
#include <cmath>

std::string filler="KasperSuger.";
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

int main(){
    fill fillet;
    for(double i=0; true; i=i+.02){
        update_winsize();
        double sine=sin(i);
        double sineup=(sine*w+w)/2;
        for(int ct=0; ct<=sineup; ct++){
            std::cout << fillet.charstr(filler);//filler;
        } std::cout << std::endl;
        usleep(60000);
    }
}

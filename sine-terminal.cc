#include <iostream>
#include <sys/ioctl.h>
#include <unistd.h>
#include <cmath>

std::string filler;
int w,h,wdf, update_speed;
double num_eq, speed;

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
        if(not(argv[1])){
            std::cout << "Program must have an alphanumerical parameter." << std::endl;
            return 0;
        } else filler=argv[1];
    fill fillet;
    speed=.1;
    update_speed=60000;
    for(double i=0; true; i=i+speed){
        update_winsize();
        double sine=sin(i);
        double sineup=(sine*w+w)/2;
        for(int ct=0; ct<=sineup; ct++){
            std::cout << fillet.charstr(filler);;
        } std::cout << std::endl;
        usleep(update_speed);
    }
}

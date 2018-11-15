#include "main.h"

int main(){
    Init init;
    Menu menu;
    init.awal();
    if (init.isBos()){
        menu.bos();
    }
    else {
        menu.karyawan();
    }
    system("pause");
    return 0;
}

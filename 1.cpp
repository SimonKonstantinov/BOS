/* Показывает информацию  о дисках, и обладает возможностью отключать  usb  накопители
Пример запроса  из терминала
./1 /4
./1 /1
./1 /2
./1 /3
*/


#include <iostream>
#include <stdio.h>
#include <stdio.h>
#include <locale.h>
#include <string.h>
#include <fstream>
#include <stdlib.h>
#include <sys/utsname.h>
#include <stdio.h>
#include <errno.h>

using namespace std;

int main(int argc, char *argv[])
{
    for (int i = 1; i < argc; i++) {

        if (argc > 1 && strcmp(argv[1], "/?") == 0) {
            cout << "/1 - список:" << '\n';
            cout << "/2 - информация о usb-storage:" << '\n';
            cout << "/3 - информация об устройствах:" << '\n';
            cout << "/4- отключение usb: " << '\n';
            cout << "/system информация о системе" << '\n';
        }
        if (argc > 1 && strcmp(argv[1], "/2") == 0) {
            cout << "информация о usb-storage:" << '\n';
            string storage;
            ifstream file("/proc/scsi/usb-storage/2/proc/scsi");
            while (getline(file, storage)) {
                cout << storage << endl;
            }
        }

        if (argc > 1 && strcmp(argv[1], "/3") == 0) {
            cout << "информация об устройствах:" << '\n';
            string storage1;
            ifstream file("/proc/scsi/scsi");
            while (getline(file, storage1)) {
                cout << storage1 << endl;
            }
        }

        if (argc > 1 && strcmp(argv[1], "/1") == 0) {
            cout << "список:" << '\n';
            ifstream file("/proc/partitions");
            string storage2;
            while (getline(file, storage2)) {
                cout << storage2 << endl;
            }
        }



         if(argc>1 && strcmp(argv[1], "/4")==0){


             system(" udisksctl umount-b /dev/sdb1");
             system(" udisksctl power-off -b /dev/sdb");

    }




        if (argc > 1 && strcmp(argv[1], "/system") == 0) {
            struct utsname buf;
            if (uname(&buf) == 0)
            {
                printf("OS name: %s\n", buf.sysname);
                printf("OS version: %s\n", buf.version);
                printf("OS release: %s\n", buf.release);
                printf("Arch: %s\n", buf.machine);
            }
            else
            {
                perror("Error");
            }
        }

    }

    return 0;
}

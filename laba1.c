#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <string.h>

int main() {
    // Создание каталогов
    mkdir("a_0", 0755);
    mkdir("a_2", 0755);
    mkdir("a_2/b_0", 0755);
    mkdir("a_2/b_2", 0755);
    mkdir("a_0/b_3", 0755);
    mkdir("a_0/b_3/c_3", 0755);

    symlink("a_1", "a_0");
    
    char* dogText = "dog";
    int dogFile = open("a_0/b_1.txt", O_CREAT | O_WRONLY, 0644);
    write(dogFile, dogText, strlen(dogText));
    close(dogFile);


    // Создание файла g.bin с 500 байтами случайных данных
    int c0File = open("a_2/b_2/c_0.bin", O_CREAT | O_WRONLY, 0644);
    char ZeroData[909];
    
    int zero_fd = open("/dev/zero", O_RDONLY);
    ssize_t filling = read(zero_fd, ZeroData, sizeof(ZeroData));
    write(c0File, ZeroData, sizeof(ZeroData));
    close(c0File);
    close(zero_fd);
 
    symlink("a_2/b_2/c_1.bin", "a_2/b_2/c_0.bin");

    link("a_2/b_2/c_2.bin", "a_0/b_3/c_0.bin");

    return 0;
}


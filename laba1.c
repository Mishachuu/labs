#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <string.h>

int main() {
    // Создание каталогов
    mkdir("a", 0755);

    char* catText = "catts";
    int catFile = open("a/cat.txt", O_CREAT | O_WRONLY, 0644);
    write(catFile, catText, strlen(catText));
    close(catFile);

    // Создание пустого файла dog.txt
    int dogFile = open("a/c/dog.txt", O_CREAT, 0644);
    close(dogFile);


    // Создание файла g.bin с 500 байтами случайных данных
    int gFile = open("a/g.bin", O_CREAT | O_WRONLY, 0644);
    char randomData[500];
    
    int urandom_fd = open("/dev/urandom", O_RDONLY);
    ssize_t filling = read(urandom_fd, randomData, sizeof(randomData));
    write(gFile, randomData, sizeof(randomData));
    close(gFile);
    close(urandom_fd);

    return 0;
}


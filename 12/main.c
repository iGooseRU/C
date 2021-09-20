#include <stdio.h>
#include <io.h>


int main(int argc, char** argv) {
    FILE* folder = fopen("Info.txt","w"); /// Создание файла
    for (int i = 1; i < argc; i++) {
        mkdir(argv[i]); /// Создание папки
        fprintf(folder, "%s\n", argv[i]); /// Запись подпапок в Info.txt
    }
    fclose(folder);
    return 0;

}
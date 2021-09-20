#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define ui unsigned int

union arch_head { /// шапка архива
    char buf[8];

    struct {

        ui archive_size; /// размер архива
    } arch_data;
};

union file_header { /// шапка файла
    char buf[8];

    struct {
        ui name_size; /// размер названия
        ui file_size; /// размер содержимого
    } file_data;
};

void copy(FILE *from, FILE *to) {
    int s;

    while ((s = getc(from)) != EOF) { /// пока не конец файла считываем байт в архив
        putc(s, to);
    }
}

ui get_size(char *name) {
    /// пробегается по файлу и выводит размер
    FILE *file = fopen(name, "rb");
    fseek(file, 0, SEEK_END);
    ui file_size = ftell(file); /// возвращает значение указателя в файле

    fclose(file);
    return file_size;
}

void create(char *archive_name, int argc, char *argv[]) {
    FILE *file;
   for (int i = 4; i < argc; i++){
        file = fopen(argv[i], "rb");
        if (file == NULL){
            printf("File not found");
            exit (-4);
        }
        fclose(file);
    }
    FILE *arch_file = fopen(archive_name, "wb");
    union arch_head arc_header; /// создание "шапки" архива (тип архива и размер)

    arc_header.arch_data.archive_size = 8; /// размер равен 8 байт

    for (int i = 4; i < argc; i++) {
        arc_header.arch_data.archive_size += get_size(argv[i]) + 8 + strlen(argv[i]);
    } /// добавим к архиву размер названия и шапку + содержимое

    fwrite(arc_header.buf, sizeof(char), 8, arch_file); /// записли шапку в архив

    for (int i = 4; i < argc; i++) { /// получаем размер содержимого и размер названия
        union file_header file_head;
        file_head.file_data.file_size = get_size(argv[i]);
        file_head.file_data.name_size = strlen(argv[i]);

        fwrite(file_head.buf, sizeof(char), 8, arch_file); /// запись шапки файла
        fwrite(argv[i], sizeof(char), strlen(argv[i]), arch_file); /// запись названия файла
        /// второй - длина объекта. третий параметр - кол-во объектов. Записываем из первого параметра
        FILE *file;
        file = fopen(argv[i], "rb");

        copy(file, arch_file);

        fclose(file);
        remove(argv[i]);
    }
    fclose(arch_file);
}

void list(char *arch_name) { /// выводит названия файлов
    FILE *arch_file = fopen(arch_name, "rb");

    union arch_head arc_header; /// получает шапку архива
    fread(arc_header.buf, sizeof(char), 8, arch_file);

    while (ftell(arch_file) < arc_header.arch_data.archive_size) { /// пока не конец архива
        union file_header file_head; /// получаем шапку файла
        fread(file_head.buf, sizeof(char), 8, arch_file); /// считываем шапку

        /// выделяем место для названия и получаем
        char *file_name = malloc((file_head.file_data.name_size) * sizeof(char));
        fread(file_name, sizeof(char), file_head.file_data.name_size, arch_file);

        /// выводим названия файлов
        printf("%s\n", file_name);
        fseek(arch_file, file_head.file_data.file_size, SEEK_CUR); /// указатель на текущую позицию

        free(file_name);
    }

    fclose(arch_file);
}

void extract(char *arch_name) {
    FILE *arch_file = fopen(arch_name, "rb");

    union arch_head arc_header;
    fread(arc_header.buf, sizeof(char), 8, arch_file); /// получаем шапку архива

    while (ftell(arch_file) < arc_header.arch_data.archive_size) { /// пока не конец архива
        union file_header file_head; /// получаем шапку файла
        fread(file_head.buf, sizeof(char), 8, arch_file);

        /// выделяем место для названия и получаем его
        char *file_name = malloc((file_head.file_data.name_size) * sizeof(char));
        fread(file_name, sizeof(char), file_head.file_data.name_size, arch_file);

        FILE *output_file = fopen(file_name, "wb"); /// создаем аутпут файл

        for (ui i = 0; i < file_head.file_data.file_size; i++) {
            int c = getc(arch_file); /// берем байт из архива и засовываем в файл
            putc(c, output_file);
        }

        fclose(output_file);
        free(file_name);
    }
    fclose(arch_file);
}

int main(int argc, char *argv[]) {
    printf("Number of arguments: %d\n", argc);
    if (argv[1][2] != 'f') {
        printf ("Format is wrong. Use --file instead %s", argv[1]);
        return -1;
    }
    if (argv[2][0] == '-' && argv[2][1] == '-') {
        printf ("Format is wrong. Add archive name %s", argv[2]);
        return -2;
    }
    char *arch_name = argv[2];  /// получаем название архива
    if (argv[3][2] == 'c') { /// проверка аргумента
        if (argc <= 4) {
            printf ("Add file(s) name(s)");
            return -3;
        }
        create(arch_name, argc, argv);  /// создание архива
    }
    else if (argv[3][2] == 'e') { /// распаковка
        extract(arch_name);
        remove(arch_name);
    } else {
        printf("files in archive %s are:\n", arch_name); /// вывод названия файла
        list(arch_name);
    }
    return 0;
}
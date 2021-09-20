#include <stdio.h>
#include <string.h>
#include <locale.h>
#include <stdlib.h>

#define ID3_MAX_SIZE 128

typedef struct ID3TAG {
    char signature[3];
    char name[30];
    char artist[30];
    char album[30];
    char year[4];
    char description[30];
    unsigned short genre;
} ID3TAG;
// возвращает кол-во байт на 128 меньше от общего размера файла
long file_offset(FILE* fp) {
    fseek(fp, 0, SEEK_END); // устанавливает указатель на 0 байт от конца
    return ftell(fp) - ID3_MAX_SIZE; // устанавливает указатель на 128 байт от конца
}

int main(int argc, char* argv[]) {
    setlocale(LC_ALL, "Rus");
    FILE* inf = NULL; // изначальный mp3 файл
    FILE* ouf = NULL; // изменённый mp3 файл
    char* mp3_name; // название mp3 файла
    char* tag; // название тэга
    char* val; // значение тэга, на которое меняем
    ID3TAG* TAGS = NULL;

    // если 11 первых символов argv[1] == 11 первым символам '--filepath=',
    // то strncmp () вернёт 0
    if (!strncmp(argv[1],"--filepath=",11)) {
        // ссылка на следующий эл-т после '='
        mp3_name = strpbrk(argv[1], "=") + 1;
        // если файл не открывается, то вывести сообщение об ошибке
        if ((inf = fopen(mp3_name,"rb")) == NULL) {
            printf("Не получилось открыть файл %s на чтение.\n", mp3_name);
            return 0;
        }
    }
    else {
        printf("Команда --filepath= не распознана.\n");
        return 0;
    }


    char* temp = (char*) malloc(sizeof(char) * ID3_MAX_SIZE); // здесь временно будет храниться вся информация из mp3 файла
    memset(temp, 0, ID3_MAX_SIZE); // весь массив (все байты) заполняются 0
    fseek(inf, file_offset(inf), SEEK_SET); // устанавливает индикатор на 0 байт от  конца
    fread(temp, 1, ID3_MAX_SIZE, inf); // считываем в temp[] 1 раз 128 байт из inf
    TAGS = (ID3TAG*)(temp); // копируем тэги

    // --show
    if(!strcmp("--show", argv[2])) {
        printf("\nНазвание песни:     %s\n",TAGS->name);
        printf("Исполнитель:        %s\n",TAGS->artist);
        printf("Альбом:             %s\n",TAGS->album);
        printf("Год:                %s\n",TAGS->year);
        printf("Описание:           %s\n",TAGS->description);
        printf("Жанр:               %d\n\n",TAGS->genre);
    }
        // --get
    else if (!strncmp("--get=", argv[2], 6)) {
        tag = strpbrk(argv[2], "=") + 1;
        if ( !strcmp(tag, "name") )
            printf("Название песни:     %s\n",TAGS->name);

        else if ( !strcmp(tag, "artist") )
            printf("Исполнитель:        %s\n",TAGS->artist);

        else if ( !strcmp("album", tag) )
            printf("Альбом:             %s\n",TAGS->album);

        else if ( !strcmp("year", tag) )
            printf("Год:                %s\n",TAGS->year);

        else if ( !strcmp("description", tag))
            printf("Описание:           %s\n",TAGS->description);

        else if ( !strcmp("genre", tag) )
            printf("Жанр:               %d\n\n",TAGS->genre);
        else {
            printf("Неизвестный тэг.\n");
            return 0;
        }
    }
        // --set
    else if (!strncmp("--set=", argv[2], 6)) {
        // Название тэга
        tag = strpbrk(argv[2], "=") + 1;
        if (!strncmp("--value=", argv[3], 8)) {
            val = strpbrk(argv[3], "=") + 1;
            if ( !strcmp(tag, "name") )
                memcpy(TAGS->name, val, 30);

            else if ( !strcmp(tag, "artist") )
                memcpy(TAGS->artist, val, 30);

            else if ( !strcmp(tag, "album") )
                memcpy(TAGS->album, val, 30);

            else if ( !strcmp(tag, "year") )
                memcpy(TAGS->year, val, 4);

            else if ( !strcmp(tag, "description") )
                memcpy(TAGS->description, val, 30);
        }
        else {
            printf("Ошибка с командой --value=\n");
            return 0;
        }
    }

    else {
        printf("Неизвестное выражение: %s\n", argv[2]);
        return 0;
    }

    // закрытие изначального mp3 файла
    fclose(inf);

    if ((ouf = fopen(mp3_name,"wb+")) == NULL) {
        printf("Не получилось открыть файл %s на запись.\n", mp3_name);
        return 0;
    }

    // в temp2[] будут временно хранится изменённые тэги
    char* temp2 =(char*) malloc(sizeof(char) * ID3_MAX_SIZE);
    // весь массив (все байты) заполняются 0
    memset(temp2, 0, ID3_MAX_SIZE);
    // записываем изменённые тэги
    temp2 = (char*)TAGS;
    fseek(ouf, file_offset(ouf), SEEK_SET);
    // записываем 128 байт из temp2[] 1 раз в ouf
    fwrite(temp2, 1, ID3_MAX_SIZE, ouf);
    free(temp2);
    fclose(ouf);

    return 0;
}
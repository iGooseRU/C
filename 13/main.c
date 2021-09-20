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
// ���������� ���-�� ���� �� 128 ������ �� ������ ������� �����
long file_offset(FILE* fp) {
    fseek(fp, 0, SEEK_END); // ������������� ��������� �� 0 ���� �� �����
    return ftell(fp) - ID3_MAX_SIZE; // ������������� ��������� �� 128 ���� �� �����
}

int main(int argc, char* argv[]) {
    setlocale(LC_ALL, "Rus");
    FILE* inf = NULL; // ����������� mp3 ����
    FILE* ouf = NULL; // ��������� mp3 ����
    char* mp3_name; // �������� mp3 �����
    char* tag; // �������� ����
    char* val; // �������� ����, �� ������� ������
    ID3TAG* TAGS = NULL;

    // ���� 11 ������ �������� argv[1] == 11 ������ �������� '--filepath=',
    // �� strncmp () ����� 0
    if (!strncmp(argv[1],"--filepath=",11)) {
        // ������ �� ��������� ��-� ����� '='
        mp3_name = strpbrk(argv[1], "=") + 1;
        // ���� ���� �� �����������, �� ������� ��������� �� ������
        if ((inf = fopen(mp3_name,"rb")) == NULL) {
            printf("�� ���������� ������� ���� %s �� ������.\n", mp3_name);
            return 0;
        }
    }
    else {
        printf("������� --filepath= �� ����������.\n");
        return 0;
    }


    char* temp = (char*) malloc(sizeof(char) * ID3_MAX_SIZE); // ����� �������� ����� ��������� ��� ���������� �� mp3 �����
    memset(temp, 0, ID3_MAX_SIZE); // ���� ������ (��� �����) ����������� 0
    fseek(inf, file_offset(inf), SEEK_SET); // ������������� ��������� �� 0 ���� ��  �����
    fread(temp, 1, ID3_MAX_SIZE, inf); // ��������� � temp[] 1 ��� 128 ���� �� inf
    TAGS = (ID3TAG*)(temp); // �������� ����

    // --show
    if(!strcmp("--show", argv[2])) {
        printf("\n�������� �����:     %s\n",TAGS->name);
        printf("�����������:        %s\n",TAGS->artist);
        printf("������:             %s\n",TAGS->album);
        printf("���:                %s\n",TAGS->year);
        printf("��������:           %s\n",TAGS->description);
        printf("����:               %d\n\n",TAGS->genre);
    }
        // --get
    else if (!strncmp("--get=", argv[2], 6)) {
        tag = strpbrk(argv[2], "=") + 1;
        if ( !strcmp(tag, "name") )
            printf("�������� �����:     %s\n",TAGS->name);

        else if ( !strcmp(tag, "artist") )
            printf("�����������:        %s\n",TAGS->artist);

        else if ( !strcmp("album", tag) )
            printf("������:             %s\n",TAGS->album);

        else if ( !strcmp("year", tag) )
            printf("���:                %s\n",TAGS->year);

        else if ( !strcmp("description", tag))
            printf("��������:           %s\n",TAGS->description);

        else if ( !strcmp("genre", tag) )
            printf("����:               %d\n\n",TAGS->genre);
        else {
            printf("����������� ���.\n");
            return 0;
        }
    }
        // --set
    else if (!strncmp("--set=", argv[2], 6)) {
        // �������� ����
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
            printf("������ � �������� --value=\n");
            return 0;
        }
    }

    else {
        printf("����������� ���������: %s\n", argv[2]);
        return 0;
    }

    // �������� ������������ mp3 �����
    fclose(inf);

    if ((ouf = fopen(mp3_name,"wb+")) == NULL) {
        printf("�� ���������� ������� ���� %s �� ������.\n", mp3_name);
        return 0;
    }

    // � temp2[] ����� �������� �������� ��������� ����
    char* temp2 =(char*) malloc(sizeof(char) * ID3_MAX_SIZE);
    // ���� ������ (��� �����) ����������� 0
    memset(temp2, 0, ID3_MAX_SIZE);
    // ���������� ��������� ����
    temp2 = (char*)TAGS;
    fseek(ouf, file_offset(ouf), SEEK_SET);
    // ���������� 128 ���� �� temp2[] 1 ��� � ouf
    fwrite(temp2, 1, ID3_MAX_SIZE, ouf);
    free(temp2);
    fclose(ouf);

    return 0;
}
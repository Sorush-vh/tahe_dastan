#include <sys/types.h>
#include <dirent.h>
#include <sys/stat.h>
#include <stdio.h>
#include <stdarg.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
#include "conio.c"
#include "conio2.h"

#define ORDERSIZE 700
#define ARGSIZE 500
#define LINE_LENGTH 500
#define FILESIZE 5000
#define NO_UNDO "#zx12p13"

struct orders
{
    char *full_input;
    char *order_head;
    char *file_name;
    char *str_input;
    char *file_name2;
    int position[2];
    int num;
    char dir;
    int size;
    int checkc;
    int find_specials[4];
    int grep_specials[2];

    struct orders *next;
    struct orders *prev;
    char *undo_content;
};

char *greps[20];

char output[FILESIZE] = {0};
char second_input[200] = {0};
char arman[200] = {0};
char trash[100];
char trashz[100];
char trash4[100];

void store_backup(struct orders *address, int order_code);
struct orders *prep_new_command(struct orders *address);
int read_command(struct orders *address);
int read_head(struct orders *address);
int read_word(int n, char *hold, char *target);
int fill_arg(struct orders *address, int arg_code);
FILE *make_directory(char *file_stats);
int isDirectoryExists(const char *path);
void insert_file(char *message, int linez, int n, char *file_name);
void parse_text(char *text);
void cat(char *file_name);
int read_before(int linez, int n, char *file_name, char *makan, char *holdprime);
void read_after(int linez, int n, char *file_name, char *makan, char *holdprime, FILE *file_ad);
void remove_str(char *file_name, int linez, int n, int size, char dir);
void copy_clipboard(char *file_name, int linez, int n, int size, char dir);
void cut_to_clipboard(char *file_name, int linez, int n, int size, char dir);
void paste_from_clipboard(char *file_name, int linez, int n);
void paste_for_real(char *target);
void copy_for_real(char *target);
int find(char *file_name, char *pattern, int all, int count, int at, int byword);
void put_content_in_string(char *file_name, char *hold);
int check_match(int start, char *source, char *target, int n, int check);
void check_wildcard(char *text);
int read_wildcard(char *source, char end, int start);
int word_count(int index, char *source);
void replace(char *file_name, char *pattern, char *alt, int at, int all);
int find_line(char *data, int char_num);
int find_char(char *data, int char_num);
void grep(char *pattern, int c, int l, int num);
void put_line_in_string(int n, char *store, char *file_name);
void set_greps();
void indent(char *file_name);
int find_whitespace_size(int char_num, char *temp);
int find_starting_whitespaces(char *temp);
void compare_files(char *file1, char *file2);
int checklines(char *hold1, char *hold2);
void telltree(char *dir_address, int tree, int tab_count);
void insert_str(char *message, int start, char *makan);
void remove_empty_stuff(char *hold);
void add_indentation(char *hold);
int closing_line(int char_num, char *hold);
int is_reg_file(char *fname);
void execute_command(struct orders *address, int arg_code);
void remove_from_str(int start, int size, char dir, char *hold);
void trim_start(char *text);
int check_for_arman(struct orders *address);
void set_screen();
void revert_str(char *target);
int find_written_lines();
void print_lines(int lines);
void write_line_numbers(int lines);
void set_bottom_screen();
void save();
int set_save_stage();
void allert(char *message);
void put_out_notif();
void prepare_to_get_input();
void openfile(char *filename);
int is_insert_order(char *input);
void insert_order_protocol(char *input, struct orders *address);
int mode_change(char *input);
void work_with_input(char *input, struct orders *address);
void saveas(char *filename);
void normal_order_keyset(char c,struct orders *address);

    // edite insert
    int ans[2];
int mode = 2;
// normal visual insert
char current_file[50] = {0};
char type_input[FILESIZE * 5] = {0};
char notification[ARGSIZE] = {0};

int main(void)
{
    strcpy(type_input, "salam\nlol\npipi\n");
    set_greps();
    struct orders *firstOrd = (struct orders *)malloc(sizeof(struct orders));
    firstOrd->full_input = (char *)malloc(sizeof(char) * ORDERSIZE);
    firstOrd->str_input = (char *)malloc(sizeof(char) * ARGSIZE);
    firstOrd->file_name = (char *)malloc(sizeof(char) * ARGSIZE);
    firstOrd->order_head = (char *)malloc(sizeof(char) * ARGSIZE);

    firstOrd->undo_content = (char *)malloc(sizeof(char) * FILESIZE);
    firstOrd->num = 1;
    firstOrd->prev = 0;
    firstOrd->next = 0;

    char *input = (char *)malloc(sizeof(char) * ORDERSIZE);
    struct orders *address = (struct orders *)malloc(sizeof(struct orders));
    address = firstOrd;
    int code;
    char c;
make_directory("/root/gg.txt");
    while (1)
    {
        set_screen();
        gotoxy(22, 30);
        textcolor(YELLOW);
        textbackground(BLACK);
        if(mode==2){
        gets(input);
        work_with_input(input,address);
        continue;
        }
        if(mode==0){
           c= getch();
           normal_order_keyset( c,address);
           continue;
        }



        // strcat(type_input, input);
        // strcat(type_input, "\n");
        // strcpy(address->full_input, input);
        // openfile("root/file2.txt");
        // textbackground(BLACK);



        // code = read_command(address);
        // store_backup(address, code / 10);
        // execute_command(address, code / 10);
        // if (code % 10)
        // {
        //     address = prep_new_command(address);
        //     strcpy(address->full_input, second_input);
        //     strcpy(address->str_input, output);
        //     code = read_command(address);
        //     store_backup(address, code / 10);
        //     execute_command(address, code / 10);
        //     memset(second_input, 0, strlen(second_input));
        //     memset(trash, 0, strlen(trash));
        //     memset(output, 0, strlen(output));
        // }
        // // printf("*%s*\n",address->order_head);

        // address = prep_new_command(address);
        // memset(input, 0, strlen(input));
        // memset(output, 0, strlen(output));
    }
    return 0;
}
// debuge find:    printf("%d",find("root/file1.txt",dastan,0,0,2,0)); bayad tuye at bealave un dastane beshe
void work_with_input(char *input, struct orders *address)
{
    if (is_insert_order(input))
        insert_order_protocol(input, address);
    else if (!mode_change(input)){
        strcat(type_input, input);
        strcat(type_input, "\n");
    }
}

void normal_order_keyset(char c,struct orders *address){
    char input[ORDERSIZE];
    if(c=='u'){
        save();
        sprintf(input,":undo -file %s -size 1",current_file);
        work_with_input(input,address);
        memset(type_input,0,strlen(type_input));
        put_content_in_string(current_file,type_input);
    }
    if(c=='='){
        save();
        sprintf(input,":auto-indent -file %s",current_file);
                printf("%s",current_file);
        gets(trash4);
        work_with_input(input,address);
        memset(type_input,0,strlen(type_input));
        put_content_in_string(current_file,type_input);
    }
    if(c=='i'){
        sprintf(input,"->insert");
        work_with_input(input,address);
    }
        if(c=='v'){
        sprintf(input,"->visual");
        work_with_input(input,address);
    }
    
}

void insert_order_protocol(char *input, struct orders *address)
{
    strcpy(address->full_input,input);
    int code = read_command(address);
    store_backup(address, code / 10);
    execute_command(address, code / 10);
    if(output[0]  && (code!=15 && code!=16)){
        openfile("\0");
        memset(type_input,0,strlen(type_input));
        strcat(type_input, output);
    }
    if (code % 10)
    {
        memset(output, 0, strlen(output));
        address = prep_new_command(address);
        strcpy(address->full_input, second_input);
        strcpy(address->str_input, output);
        code = read_command(address);
        store_backup(address, code / 10);
        execute_command(address, code / 10);
            if(output[0]  && (code!=15 && code!=16)){
        openfile("\0");
        memset(type_input,0,strlen(type_input));
        strcat(type_input, output);
    }

        memset(second_input, 0, strlen(second_input));
        memset(trash, 0, strlen(trash));
        memset(output, 0, strlen(output));
    }
    address = prep_new_command(address);
    memset(input, 0, strlen(input));
    memset(output, 0, strlen(output));
}

int is_insert_order(char *input)
{
    if (input[0] == ':')
        return 1;
    else
        return 0;
}

int mode_change(char *input)
{
    if (!strcmp(input, "->visual")){
        mode = 1;
        return 1;
    }
    if (!strcmp(input, "->insert")){
        mode = 2;
        return 1;
    }
    if (!strcmp(input, "->normal")){
        mode = 0;
        return 1;
    }
    return 0;
}

void write_line_numbers(int lines)
{
    textbackground(WHITE);
    textcolor(GREEN);
    char hold[5] = {0};
    for (int i = 0; i < lines; i++)
    {
        memset(hold, 4, 4);
        gotoxy(0, i);
        sprintf(hold, "%2d \n", i);
        cputs(hold);
    }
}

void set_bottom_screen()
{
    gotoxy(1, 29);
    textcolor(WHITE);
    textbackground(CYAN);
    if (mode == 0)
        cprintf("   NORMAL   ");
    if (mode == 1)
        cprintf("   VISUAL   ");
    if (mode == 2)
        cprintf("   INSERT   ");
    textbackground(GRAY_BRUSH);
    if (current_file[0] == '\0')
        cprintf("  NEW FILE  ");
    else
        cprintf("%s", current_file);

    if (set_save_stage() == 1)
        printf(" (+) ");
    else
        printf(" (-) ");
    put_out_notif();
    prepare_to_get_input();
}

void prepare_to_get_input()
{
    gotoxy(4, 30);
    delline();
    textcolor(WHITE);
    textbackground(CYAN);
    printf("  enter command:");
    textbackground(BLACK);
    textcolor(BLACK);
    printf("  ");
    textcolor(YELLOW);
}

void set_screen()
{
    textbackground(BLACK);
    clrscr();
    int line_count = find_written_lines();
    write_line_numbers(line_count);
    set_bottom_screen();
    print_lines(line_count);
}

int set_save_stage()
{
    char hold[FILESIZE] = {0};
    FILE *file_ad = fopen(current_file, "r");
    fclose(file_ad);
    if (file_ad)
    {
        put_content_in_string(current_file, hold);
        if (!strcmp(type_input, hold))
            return 1;
    }
    return 0;
}

void allert(char *message)
{
    strcpy(notification, message);
}

void put_out_notif()
{
    gotoxy(2, 28);
    textcolor(WHITE);
    textbackground(CYAN);
    printf("%s", notification);
}

void save()
{
    char name[50] = {0};
    char msg[50] = {0};
    if (!current_file[0])
    {
        strcpy(msg, "please write a name for your file");
        // safe refresh she va dastur sabt nashe tu dastan
        allert(msg);
        set_screen();
        prepare_to_get_input();
        gets(name);

        FILE* file_ad = fopen(name, "w");
        fputs(type_input, file_ad);
        fclose(file_ad);
        rewind(file_ad);
        strcpy(msg, "success");
        allert(msg);
        textbackground(BLACK);
        strcpy(current_file, name);
        return;
    }
    else
    {
         FILE* file_ad=fopen(current_file, "w");
        fputs(type_input, file_ad);
        fclose(file_ad);
        rewind(file_ad);
        strcpy(msg, "success");
        allert(msg);
        textbackground(BLACK);
    }
}
// tu ja fili
void saveas(char *filename)
{
    memset(current_file,0,strlen(current_file));
    strcpy(current_file,filename);
    save();
}

void openfile(char *filename)
{
    FILE *file_ad = fopen(filename, "r");
    char msg[50] = {0};
    if (!file_ad && filename[0])
    {
        strcpy(msg, "error: unable to open file");
        allert(msg);
        set_screen();
        return;
    }
    else if(file_ad)
    {
        fclose(file_ad);
        save();

        memset(current_file, 0, strlen(current_file));
        strcpy(current_file, filename);

        memset(type_input, 0, strlen(type_input));
        put_content_in_string(filename, type_input);
        

        sprintf(msg, "%s opened", filename);
        allert(msg);

        return;
    }
    else
    {
        save();
        memset(current_file, 0, strlen(current_file));
        memset(type_input, 0, strlen(type_input));
        sprintf(msg, "new file opened");
        allert(msg);
    }
    
}

int read_line_from_end(char *hold, char *target, int n)
{
    int count = 0;
    int i = 0, j = 0, check = 0;
    int length = strlen(hold);
    char temp[500] = {0};
    while (1)
    {
        if (hold[length - i - 1] == '\n' || (count == n && i == length - 1))
            count++;
        if (count == n + 1)
        {
            if (i == length - 1)
            {
                temp[j] = hold[0];
                j++;
                check = 1;
            }
            while (1)
            {
                if (hold[length - i + j - check] == '\n' || hold[length - i + j] == '\0')
                {
                    memset(target, 0, strlen(target));
                    strcpy(target, temp);
                    return 0;
                }
                temp[j] = hold[length - i + j - check];
                j++;
            }
        }
        if (i == length - 1)
            return n;
        i++;
    }
}

int find_written_lines()
{
    int shift = 24;
    char output[LINE_LENGTH];
    char temp[LINE_LENGTH] = {0};
    for (int i = 0; i < 25; i++)
    {
        if (!read_line_from_end(type_input, temp, i))
        {
            gotoxy(10, 0);
            memset(temp, 0, strlen(temp));
            memset(output, 0, strlen(output));
        }
        else
        {
            shift = i;
            break;
        };
    }
    return shift;
}

void print_lines(int lines)
{
    char temp[LINE_LENGTH] = {0};
    textbackground(WHITE);
    textcolor(GREEN);
    for (int i = 0; i < lines; i++)
    {
        gotoxy(4, lines - i);
        read_line_from_end(type_input, temp, i);
        printf("%s", temp);
        memset(temp, 0, strlen(temp));
    }
}

void reset_greps()
{
    for (int i = 0; i < 20; i++)
    {
        memset(greps[i], 0, strlen(greps[i]));
    }
}

void set_greps()
{
    for (int i = 0; i < 20; i++)
    {
        greps[i] = (char *)malloc(sizeof(char) * ARGSIZE);
    }
}

struct orders *prep_new_command(struct orders *address)
{
    address->next = (struct orders *)malloc(sizeof(struct orders));

    address->next->full_input = (char *)malloc(sizeof(char) * ORDERSIZE);
    address->next->str_input = (char *)malloc(sizeof(char) * ARGSIZE);
    address->next->file_name = (char *)malloc(sizeof(char) * ARGSIZE);
    address->next->order_head = (char *)malloc(sizeof(char) * ARGSIZE);

    address->next->num = address->num + 1;
    address->next->prev = address;
    address->next->next = 0;
    address->next->undo_content = (char *)malloc(sizeof(char) * FILESIZE);
    return address->next;
}

void revert_str(char *target)
{
    char temp[400] = {0};
    strcpy(temp, target);
    memset(target, 0, strlen(target));
    int length = strlen(temp);

    for (int i = 0; i < length; i++)
    {
        target[i] = temp[length - i - 1];
    }
}

// filecreate:1    insert:5  cat:1 remove:5
int read_command(struct orders *address)
{
    int errors[7] = {0};
    const int order_code = read_head(address);

    if (!order_code)
    {
        printf("invalid command\n");
        return 0;
        // file str pos size dir
    }

    int armz = check_for_arman(address);
    if (armz)
    {
        memset(address->full_input, 0, strlen(address->full_input));
        strcpy(address->full_input, arman);
    }

    // c(0) l(1)
    if (order_code == 10)
    {
        char temp[ARGSIZE] = {0};
        for (int i = 0; i < 20; i++)
        {
            if (read_word(i, address->full_input, temp))
            {
                // specs:
                if (checklines("-c", temp))
                {
                    address->grep_specials[0] = 1;
                    memset(temp, 0, strlen(temp));
                }

                if (checklines("-l", temp))
                {
                    address->grep_specials[1] = 1;
                    memset(temp, 0, strlen(temp));
                }

                // files:
                if (checklines("-files", temp))
                {
                    int shift = 0;
                    while (1)
                    {
                        memset(temp, 0, strlen(temp));
                        if (read_word(i + 1 + shift, address->full_input, temp))
                        {
                            strcpy(greps[shift], temp);
                            address->size = shift + 1;
                        }
                        else
                            break;
                        shift++;
                    }
                }
                memset(temp, 0, strlen(temp));
            }
        }
    }

    if (order_code == 9)
    {
        for (int i = 0; i < 20; i++)
        {
            address->file_name2 = (char *)malloc(sizeof(char) * ARGSIZE);
            char temp[ARGSIZE] = {0};
            if (read_word(i, address->full_input, temp))
            {
                if (checklines("-str2", temp))
                {
                    memset(temp, 0, strlen(temp));
                    if (read_word(i + 1, address->full_input, temp))
                    {
                        char hold[ARGSIZE] = {0};
                        strcpy(hold, temp);

                        if (temp[0] == '"')
                        {
                            int buff = 1;
                            while (1)
                            {
                                memset(temp, 0, strlen(temp));
                                read_word(i + 1 + buff, address->full_input, temp);
                                strcat(hold, " ");
                                strcat(hold, temp);

                                if (temp[strlen(temp) - 1] == '"' && temp[strlen(temp) - 2] != 92)
                                    break;
                                buff++;
                            }
                        }
                        strcpy(address->file_name2, hold);
                        break;
                    }
                }
                memset(temp, 0, strlen(temp));
            }
        }
    }

    if (order_code == 8 || order_code == 9)
    {
        char temp[ARGSIZE] = {0};
        // at (0)
        for (int i = 0; i < 20; i++)
        {
            if (read_word(i, address->full_input, temp))
            {
                if (checklines("-at", temp))
                {
                    memset(temp, 0, strlen(temp));
                    if (read_word(i + 1, address->full_input, temp))
                    {
                        sscanf(temp, "%d", &address->find_specials[0]);
                        break;
                    }
                }
                memset(temp, 0, strlen(temp));
            }
        }
        // all (1)
        for (int i = 0; i < 20; i++)
        {
            if (read_word(i, address->full_input, temp))
            {
                if (checklines("-all", temp))
                {
                    address->find_specials[1] = 1;
                }
                memset(temp, 0, strlen(temp));
            }
        }
        // byword 2
        for (int i = 0; i < 20; i++)
        {
            if (read_word(i, address->full_input, temp))
            {
                if (checklines("-byword", temp))
                {
                    address->find_specials[2] = 1;
                }
                memset(temp, 0, strlen(temp));
            }
        }
        // count 3
        for (int i = 0; i < 20; i++)
        {
            if (read_word(i, address->full_input, temp))
            {
                if (checklines("-count", temp))
                {
                    address->find_specials[3] = 1;
                }
                memset(temp, 0, strlen(temp));
            }
        }
    }

    // tree compare grep
    if (order_code != 14 && order_code != 10 && order_code != 13 && order_code != 15)
        errors[1] = !(fill_arg(address, 1));

    if (order_code == 2 || order_code == 8 || order_code == 10 || order_code == 9)
        errors[2] = !(fill_arg(address, 2));

    if (order_code == 2 || order_code == 4 || order_code == 5 || order_code == 6 || order_code == 7)
        errors[3] = !(fill_arg(address, 3));

    if (order_code == 4 || order_code == 5 || order_code == 6 || order_code == 11)
        errors[4] = !(fill_arg(address, 4));

    if (order_code == 4 || order_code == 5 || order_code == 6)
        errors[5] = !(fill_arg(address, 5));

    if (order_code == 13)
    {
        errors[6] = !(fill_arg(address, 13));
    }
    if(errors[1] && order_code==4) strcpy(address->file_name,current_file);
    return order_code * 10 + armz;
}

void store_backup(struct orders *address, int order_code)
{
    char temp[FILESIZE] = {0};
    if ((order_code == 2 || order_code == 4 || order_code == 6 || order_code == 7 || order_code == 9 || order_code == 12) && address->prev)
    {
        put_content_in_string(address->file_name, temp);
        strcpy(address->undo_content, temp);
    }
    else
        strcpy(address->undo_content, NO_UNDO);
}

void execute_command(struct orders *address, int arg_code)
{

    if (arg_code == 1)
    {
        make_directory(address->file_name);
    }

    if (arg_code == 2)
    {
        printf("&&&%d\n%d\n", address->position[0], address->position[1]);

        insert_file(address->str_input, address->position[0], address->position[1], address->file_name);
    }

    if (arg_code == 3)
    {
        cat(address->file_name);
    }

    if (arg_code == 4)
    {
        remove_str(address->file_name, address->position[0], address->position[1], address->size, address->dir);
    }

    if (arg_code == 5)
    {
        copy_clipboard(address->file_name, address->position[0], address->position[1], address->size, address->dir);
    }

    if (arg_code == 6)
    {
        cut_to_clipboard(address->file_name, address->position[0], address->position[1], address->size, address->dir);
    }

    if (arg_code == 7)
    {
        paste_from_clipboard(address->file_name, address->position[0], address->position[1]);
    }

    if (arg_code == 8)
    {
        ans[0] = find(address->file_name, address->str_input, address->find_specials[1], address->find_specials[3], address->find_specials[0], address->find_specials[2]);
        if (ans[0] != -1)
        {
            printf("%d", ans[0]);
            sprintf(trashz, "%d", ans[0]);
            strcat(output, trashz);
            memset(trashz, 0, strlen(trashz));
        }
        printf("\n");
        sprintf(trashz, "\n");
        strcat(output, trashz);
        memset(trashz, 0, strlen(trashz));
    }

    if (arg_code == 9)
    {
        replace(address->file_name, address->str_input, address->file_name2, address->find_specials[0], address->find_specials[1]);
    }

    if (arg_code == 10)
    {
        grep(address->str_input, address->grep_specials[0], address->grep_specials[1], address->size);
        reset_greps();
    }

    if (arg_code == 11)
    {
        int n = address->size, count = 0;
        if (n < 1)
        {
            sprintf(output, "invalid size for undoing this file\n");
            return;
        }

        while (1)
        {
            if (!checklines(NO_UNDO, address->undo_content))
                count++;
            if (count == n)
            {
                FILE *file_ad = fopen(address->file_name, "r");
                if (!file_ad)
                {
                    perror("fopen");
                    return;
                }
                fclose(file_ad);
                fopen(address->file_name, "w");
                fputs(address->undo_content, file_ad);
                fclose(file_ad);
                rewind(file_ad);
                while (1)
                {
                    if (address->next)
                        address = address->next;
                    else
                        break;
                }
                return;
            }
            if (!address->prev)
            {
                sprintf(output, "invalid size for undoing this file\n");
                return;
            }
            address = address->prev;
        }
    }

    if (arg_code == 12)
    {
        indent(address->file_name);
    }

    if (arg_code == 13)
    {
        compare_files(address->file_name, address->file_name2);
    }

    if (arg_code == 14)
    {
        char temp[50] = {0};
        read_word(1, address->full_input, temp);
        int a;
        sscanf(temp, "%d", &a);
        memset(temp, 0, strlen(temp));
        strcpy(temp, "./root");
        if (a == -1)
            a = 500;
        telltree(temp, a, 0);
    }

    if (arg_code == 15)
    {
        save();
    }

    if (arg_code == 16)
    {
        saveas(address->file_name);
    }

    if (arg_code == 17)
    {
        openfile(address->file_name);
    }
}

int read_head(struct orders *address)
{
    if (!read_word(0, address->full_input, address->order_head))
        return 0;
    else
    {
        if (checklines(":createfile", address->order_head))
            return 1;
        else if (checklines(":insertstr", address->order_head))
            return 2;
        else if (checklines(":cat", address->order_head))
            return 3;
        else if (checklines(":removestr", address->order_head))
            return 4;
        else if (checklines(":copystr", address->order_head))
            return 5;
        else if (checklines(":cutstr", address->order_head))
            return 6;
        else if (checklines(":pastestr", address->order_head))
            return 7;
        else if (checklines(":find", address->order_head))
            return 8;
        else if (checklines(":replace", address->order_head))
            return 9;
        else if (checklines(":grep", address->order_head))
            return 10;
        else if (checklines(":undo", address->order_head))
            return 11;
        else if (checklines(":auto-indent", address->order_head))
            return 12;
        else if (checklines(":compare", address->order_head))
            return 13;
        else if (checklines(":tree", address->order_head))
            return 14;
        else if (checklines(":save", address->order_head))
            return 15;
        else if (checklines(":saveas", address->order_head))
            return 16;
        else if (checklines(":open", address->order_head))
            return 17;
        else
            return 0;
    }
}

int read_word(int n, char *hold, char *target)
{
    int j = 0, check = 0;
    int count = 0;
    for (int i = 0; i < strlen(hold); i++)
    {
        if (count == n)
        {
            check = 1;
            while (1)
            {
                if (hold[i] == ' ' || hold[i] == '\n' || hold[i] == '\0')
                    break;
                target[j] = hold[i];
                i++;
                j++;
            }
        }
        if (check)
            break;
        if (hold[i] == ' ')
            count++;
    }
    if (!check)
        return 0;
    else
        return 1;
}

// file str pos size dir
int fill_arg(struct orders *address, int arg_code)
{
    char temp[ARGSIZE] = {0};
    if (arg_code == 13)
    {
        address->file_name2 = (char *)malloc(sizeof(char) * ARGSIZE);
        for (int i = 0; i < 20; i++)
        {
            if (read_word(i, address->full_input, temp))
            {
                if (checklines("-file2", temp))
                {

                    memset(temp, 0, strlen(temp));
                    if (read_word(i + 1, address->full_input, temp))
                    {
                        strcpy(address->file_name2, temp);
                        break;
                    }
                }
                memset(temp, 0, strlen(temp));
            }
        }

        for (int i = 0; i < 20; i++)
        {
            if (read_word(i, address->full_input, temp))
            {
                if (checklines("-file", temp))
                {

                    memset(temp, 0, strlen(temp));
                    if (read_word(i + 1, address->full_input, temp))
                    {
                        strcpy(address->file_name, temp);
                        return 1;
                    }
                }
                memset(temp, 0, strlen(temp));
            }
        }
    }

    if (arg_code == 1)
    {
        for (int i = 0; i < 20; i++)
        {
            if (read_word(i, address->full_input, temp))
            {
                if (checklines("-file", temp))
                {

                    memset(temp, 0, strlen(temp));
                    if (read_word(i + 1, address->full_input, temp))
                    {
                        strcpy(address->file_name, temp);
                        return 1;
                    }
                }
                memset(temp, 0, strlen(temp));
            }
        }
        return 0;
    }

    if (arg_code == 2)
    {
        for (int i = 0; i < 20; i++)
        {
            if (read_word(i, address->full_input, temp))
            {
                if (checklines("-str", temp))
                {
                    memset(temp, 0, strlen(temp));
                    if (read_word(i + 1, address->full_input, temp))
                    {
                        char hold[ARGSIZE] = {0};
                        strcpy(hold, temp);

                        if (temp[0] == '"')
                        {
                            int buff = 1;
                            while (1)
                            {
                                memset(temp, 0, strlen(temp));
                                read_word(i + 1 + buff, address->full_input, temp);
                                strcat(hold, " ");
                                strcat(hold, temp);
                                if (temp[strlen(temp) - 1] == '"' && temp[strlen(temp) - 2] != 92)
                                    break;
                                buff++;
                            }
                        }
                        strcpy(address->str_input, hold);
                        return 1;
                    }
                }
                memset(temp, 0, strlen(temp));
            }
        }
        return 0;
    }

    if (arg_code == 3)
    {
        for (int i = 0; i < 20; i++)
        {
            if (read_word(i, address->full_input, temp))
            {
                if (checklines("-pos", temp))
                {
                    memset(temp, 0, strlen(temp));
                    if (read_word(i + 1, address->full_input, temp))
                    {
                        if (sscanf(temp, "%d:%d", &address->position[0], &address->position[1]) == 2)
                            return 1;
                        else
                            return 0;
                    }
                }
                memset(temp, 0, strlen(temp));
            }
        }
        return 0;
    }

    if (arg_code == 4)
    {
        for (int i = 0; i < 20; i++)
        {
            if (read_word(i, address->full_input, temp))
            {
                if (checklines("-size", temp))
                {
                    memset(temp, 0, strlen(temp));
                    if (read_word(i + 1, address->full_input, temp))
                    {
                        if (sscanf(temp, "%d", &address->size) == 1)
                            return 1;
                        else
                            return 0;
                    }
                }
                memset(temp, 0, strlen(temp));
            }
        }
        return 0;
    }

    if (arg_code == 5)
    {
        for (int i = 0; i < 20; i++)
        {
            if (read_word(i, address->full_input, temp))
            {
                if (checklines("-f", temp) || checklines("-b", temp))
                {
                    if (sscanf(temp, "-%c", &address->dir) == 1)
                        return 1;
                    else
                        return 0;
                }
                memset(temp, 0, strlen(temp));
            }
        }
        return 0;
    }
}

int check_for_arman(struct orders *address)
{
    char temp[ARGSIZE] = {0};
    for (int i = 0; i < 20; i++)
    {
        if (read_word(i, address->full_input, temp))
        {
            if (checklines("=D", temp))
            {
                memset(temp, 0, strlen(temp));
                for (int j = 0; j < i; j++)
                {
                    read_word(j, address->full_input, trash);
                    strcat(arman, trash);
                    strcat(arman, " ");
                    memset(trash, 0, strlen(trash));
                }
                for (int j = i + 1; j < 30; j++)
                {
                    read_word(j, address->full_input, trash);
                    strcat(second_input, trash);
                    strcat(second_input, " ");
                    memset(trash, 0, strlen(trash));
                }
                return 1;
            }
            memset(temp, 0, strlen(temp));
        }
    }
    return 0;
}

FILE *make_directory(char *file_stats)
{
    FILE *address;
    int count = 0;
    char c;
    char hold[ARGSIZE] = {'\0'};
    int i = 1;
    while (1)
    {
        while (1)
        {
            c = file_stats[i];
            if (c == 47)
            {
                count++;
                break;
            }
            hold[i - 1] = c;
            i++;
            if (i == strlen(file_stats))
            {
                count++;
                break;
            }
        }
        if (count == 1)
        {
            if (strcmp("root", hold) || file_stats[0] != 47)
            {
                sprintf(output, "Error: not started from root");
                return 0;
            }
        }
        if (!isDirectoryExists(hold) && i != strlen(file_stats))
        {
            CreateDirectory(hold, NULL);
        }
        if (i == strlen(file_stats))
        {
            address = (FILE *)fopen(hold, "w");
            if (!address)
                perror("fopen");
            return address;
        }
        hold[i - 1] = c;
        i++;
    }
}

int isDirectoryExists(const char *path)
{
    struct stat stats;

    stat(path, &stats);

    // Check for file existence
    if (S_ISDIR(stats.st_mode))
        return 1;

    return 0;
}

void parse_text(char *text)
{
    char hold[ARGSIZE] = {'\0'};
    trim_start(text);
    strcpy(hold, text);

    int i0 = strlen(text);
    int j = 0;
    int i = 0;
    memset(text, 0, strlen(text));
    while (1)
    {
        if (!hold[i])
            break;
        if (hold[i] != 92)
            text[j] = hold[i];
        else
        {

            if (hold[i + 1] == 92 && hold[i + 2] == 'n')
            {
                i++;
                text[j] = hold[i];
                j++;
                i++;
                text[j] = hold[i];
            }
            else if (hold[i + 1] == 'n')
            {
                text[j] = '\n';
                i++;
            }
            else if (hold[i + 1] == 34 || hold[i + 1] == '*')
                j--;
            else
                text[j] = hold[i];
        }
        i++;
        j++;
    }
}

void trim_start(char *text)
{
    if (text[0] == '"')
    {
        char temp[ARGSIZE] = {0};
        for (int i = 1; i < strlen(text) - 1; i++)
        {
            temp[i - 1] = text[i];
        }
        memset(text, 0, strlen(text));
        strcpy(text, temp);
    }
}

int read_before(int linez, int n, char *file_name, char *makan, char *holdprime)
{
    int val = 1;
    FILE *file_ad = fopen(file_name, "r");
    char c;
    char hold[ARGSIZE] = {'\0'};
    for (int i = 0; i < linez - 1; i++)
    {
        fgets(hold, LINE_LENGTH, file_ad);
        strcat(makan, hold);
        memset(hold, 0, strlen(hold));
    }
    memset(hold, 0, strlen(hold));
    int i0 = strlen(makan);
    int check = 1;
    fgets(holdprime, LINE_LENGTH, file_ad);
    for (int i = 0; i < n; i++)
    {
        c = holdprime[i];
        if (holdprime[i] == '\0' || holdprime[i] == '\n')
        {
            val = 0;
            for (int j = i; j < n; j++)
            {
                hold[j] = ' ';
            }
            check = 0;
        }
        if (!check)
            break;
        hold[i] = holdprime[i];
    }
    strcat(makan, hold);
    return val;
}

void read_after(int linez, int n, char *file_name, char *makan, char *holdprime, FILE *file_ad)
{
    int j = 0;
    int check = 1;
    char hold[ARGSIZE] = {'\0'};
    memset(hold, 0, strlen(hold));
    if (holdprime[n] == '\n' || holdprime[n] == '\0')
        check = 0;

    for (int i = n; i < LINE_LENGTH; i++)
    {
        if (check == 0)
        {
            hold[0] = '\n';
            break;
        }
        hold[i - n] = holdprime[i];
        if (holdprime[i] == '\n')
            break;
    }
    strcat(makan, hold);
    memset(hold, 0, strlen(hold));
    while (1)
    {
        fgets(hold, LINE_LENGTH, file_ad);
        strcat(makan, hold);
        if (feof(file_ad))
            break;
        memset(hold, 0, strlen(hold));
    }
    fclose(file_ad);
}

void insert_file(char *message, int linez, int n, char *file_name)
{
    char c;
    char holdprime[ARGSIZE] = {'\0'};
    char *before = (char *)malloc(sizeof(char) * LINE_LENGTH);
    char *after = (char *)malloc(sizeof(char) * LINE_LENGTH);
    strcpy(before, "\0");
    strcpy(after, "\0");
    FILE *file_ad = fopen(file_name, "r");
    if (!file_ad)
    {
        perror("fopen");
        return;
    }
    fclose(file_ad);

    if (!read_before(linez, n, file_name, before, holdprime))
    {
        sprintf(output, "error: line %d does not have character %d", linez, n);
        return;
    }
    parse_text(message);
    read_after(linez, n, file_name, after, holdprime, file_ad);

    FILE *ff = fopen(file_name, "w");
    fputs(before, ff);
    fputs(message, ff);
    fputs(after, ff);
    fclose(ff);
}

void insert_str(char *message, int start, char *makan)
{
    char c;
    char before[FILESIZE] = {0};
    char after[FILESIZE] = {0};
    memset(before, 0, strlen(before));
    memset(after, 0, strlen(after));

    for (int i = 0; i < start; i++)
    {
        before[i] = makan[i];
    }

    int i0 = strlen(makan);

    for (int i = start; i < i0; i++)
    {
        after[i - start] = makan[i];
    }
    memset(makan, 0, strlen(makan));
    strcat(makan, before);
    strcat(makan, message);
    strcat(makan, after);
}

void cat(char *file_name)
{
    char *hold = (char *)malloc(sizeof(char) * FILESIZE);
    memset(hold, 0, strlen(hold));
    put_content_in_string(file_name, hold);
    sprintf(output, "%s\n", hold);
    strcat(output, hold);
}

void remove_str(char *file_name, int linez, int n, int size, char dir)
{
    char c;
    char holdprime[ARGSIZE] = {'\0'};

    char *before = (char *)malloc(sizeof(char) * LINE_LENGTH);
    char *ultimate_before = (char *)malloc(sizeof(char) * LINE_LENGTH);

    char *after = (char *)malloc(sizeof(char) * LINE_LENGTH);
    char *ultimate_after = (char *)malloc(sizeof(char) * LINE_LENGTH);

    memset(before, 0, strlen(before));
    memset(after, 0, strlen(after));

    FILE *file_ad = fopen(file_name, "r");
    if (!file_ad)
    {
        perror("fopen");
        return;
    }
    fclose(file_ad);
    if (!read_before(linez, n, file_name, before, holdprime))
    {
        sprintf(output, "error: line %d does not have character %d", linez, n);
        return;
    }
    read_after(linez, n, file_name, after, holdprime, file_ad);
    memset(ultimate_after, 0, strlen(after));
    memset(ultimate_before, 0, strlen(before));

    if (dir == 'f')
    {
        int finish = strlen(after);

        for (int i = size; i < finish; i++)
        {
            ultimate_after[i - size] = after[i];
            if (!after[i + 1] || after[i + 1] == EOF)
            {
                ultimate_after[i + 1] = EOF;
                break;
            }
        }
        strcpy(ultimate_before, before);
    }

    else if (dir == 'b')
    {
        int finish = strlen(before);
        for (int i = 0; i < finish - size; i++)
        {
            ultimate_before[i] = before[i];
        }
        strcpy(ultimate_after, after);
    }
    else
    {
        sprintf(output, "invalid direction");
        return;
    }
    // printf("%s%s", ultimate_before, ultimate_after);
    fclose(file_ad);
    fopen(file_name, "w");
    fputs(ultimate_before, file_ad);
    fputs(ultimate_after, file_ad);
    fclose(file_ad);
}

void copy_for_real(char *target)
{
    OpenClipboard(0);
    EmptyClipboard();
    size_t lol = 1 + strlen(target);
    HGLOBAL h = GlobalAlloc(GMEM_MOVEABLE, lol);
    memcpy(GlobalLock(h), target, lol);
    GlobalUnlock(h);
    SetClipboardData(CF_TEXT, h);
    CloseClipboard();
}

void paste_for_real(char *target)
{
    // Try opening the clipboard
    if (!OpenClipboard(NULL))
        sprintf(output, "error\n");

    // Get handle of clipboard object for ANSI text
    HANDLE hData = GetClipboardData(CF_TEXT);
    if (hData == NULL)
        sprintf(output, "error\n");

    // Lock the handle to get the actual text pointer
    char *pszText = (char *)(GlobalLock(hData));
    if (pszText == NULL)
        sprintf(output, "error\n");

    // Save text in a string class instance
    strcpy(target, pszText);

    // Release the lock
    GlobalUnlock(hData);

    // Release the clipboard
    CloseClipboard();
}

void copy_clipboard(char *file_name, int linez, int n, int size, char dir)
{
    char c;
    char holdprime[ARGSIZE] = {'\0'};
    char clipz[ARGSIZE] = {'\0'};

    char *before = (char *)malloc(sizeof(char) * LINE_LENGTH);
    char *after = (char *)malloc(sizeof(char) * LINE_LENGTH);

    memset(before, 0, strlen(before));
    memset(after, 0, strlen(after));

    FILE *file_ad = fopen(file_name, "r");
    if (!file_ad)
    {
        perror("fopen");
        return;
    }
    fclose(file_ad);
    if (!read_before(linez, n, file_name, before, holdprime))
    {
        sprintf(output, "error: line %d does not have character %d", linez, n);
        return;
    }
    read_after(linez, n, file_name, after, holdprime, file_ad);

    if (dir == 'f')
    {
        for (int i = 0; i < size; i++)
        {
            clipz[i] = after[i];
            if (!after[i + 1] || after[i + 1] == EOF)
            {
                clipz[i + 1] = EOF;
                break;
            }
        }
    }
    else if (dir == 'b')
    {
        int finish = strlen(before);
        for (int i = finish; i > finish - size; i--)
        {
            clipz[finish - i] = before[i - 1];
        }

        int i0 = strlen(clipz);
        char hold[ARGSIZE] = {'\0'};
        strcpy(hold, clipz);
        memset(clipz, 0, strlen(clipz));
        for (int i = 0; i < i0; i++)
        {
            clipz[i] = hold[i0 - i - 1];
        }
    }
    else
    {
        sprintf(output, "invalid direction");
        return;
    }
    copy_for_real(clipz);
}

void cut_to_clipboard(char *file_name, int linez, int n, int size, char dir)
{
    copy_clipboard(file_name, linez, n, size, dir);
    remove_str(file_name, linez, n, size, dir);
}

void paste_from_clipboard(char *file_name, int linez, int n)
{
    char clipz[ARGSIZE] = {'\0'};
    paste_for_real(clipz);
    insert_file(clipz, linez, n, file_name);
}

void put_content_in_string(char *file_name, char *hold)
{
    memset(hold, 0, strlen(hold));
    FILE *file_ad = fopen(file_name, "r");
    if (!file_ad)
    {
        perror("fopen");
        return;
    }
    int i = 0;
    char c;
    while (1)
    {
        c = fgetc(file_ad);
        if (c == EOF || c == '\0')
            break;
        hold[i] = c;
        i++;
    }
    fclose(file_ad);
    rewind(file_ad);
}

void check_wildcard(char *text)
{
    int length = strlen(text);
    int check = 0;
    int count = 0;
    for (int i = 0; i < length; i++)
    {
        if (text[i] == '*')
        {
            if (i == 0 || text[i - 1] != 92)
            {
                text[i] = 5;
            }
        }
    }
}

int check_match(int start, char *source, char *target, int n, int check)
{
    if ((int)target[check] == 5)
    {
        char end;
        if (strlen(target) - 1 == check)
            end = '\0';
        else
            end = target[check + 1];
        int shift = read_wildcard(source, end, start + n);

        if (!shift)
            return 0;
        else
        {
            n += shift;
        }
    }
    else if (target[check] != source[start + n])
        return 0;
    if (check == strlen(target) - 1)
        return n + 1;
    else
        return check_match(start, source, target, n + 1, check + 1);
}

// ino dorsost konii
int read_wildcard(char *source, char end, int start)
{
    int i = 0;
    if (!end)
    {
        // ino dorsost konii
        while (source[start + i] != EOF && source[start + i] != ' ' && source[start + i] != '\0')
        {
            i++;
        }
        return i;
    }
    while (1)
    {
        // dorost kardane space be sharte space nabudan
        if (source[start + i] == EOF || source[start + i] == ' ' || source[start + i] == '\0' || source[start + i] == '\n')
        {
            return 0;
        }
        if (source[start + i + 1] == end)
        {
            return i;
        }
        i++;
    }
}

int word_count(int index, char *source)
{
    int count = 0;
    int skip = 0;
    for (int i = 0; i < index; i++)
    {
        if (source[i] == ' ' || source[i] == '\n')
        {
            count++;
            while (1)
            {
                if (source[i + 1 + skip] == ' ' || source[i + 1 + skip] == '\n')
                    skip++;
                else
                    break;
            }
            i += skip;
            skip = 0;
        }
    }
    return count;
}

// age naresid -1
int find(char *file_name, char *pattern, int all, int count, int at, int byword)
{
    // modez: count at byword all
    // count : tedad
    // all: hameash print she(ya tu 0 ya tu byword)
    // at: mige ru chandomi
    // byword: jaye char, kalame mige

    // se ta ba ham nist
    // all va at nist
    //
    char *hold = (char *)malloc(sizeof(char) * FILESIZE);
    char temp[ARGSIZE] = {0};
    memset(hold, 0, strlen(hold));
    int length = strlen(pattern), i = 0;

    check_wildcard(pattern);

    parse_text(pattern);
    put_content_in_string(file_name, hold);

    int i0 = strlen(hold);
    int ans;
    int countt = 0;
    // printf("%c\n",pattern[0]);
    // al va at
    // count ba hame
    for (int i = 0; i < i0; i++)
    {
        ans = check_match(i, hold, pattern, 0, 0);
        if (ans)
        {
            if (!all && count && !at && !byword)
            {
                countt++;
            }
            else if (!count)
            {
                if (!all && !at && !byword)
                    return i;
                else if (!all && !at && byword)
                    return word_count(i, hold);
                else if (all && !at && !byword)
                {
                    // printf("%d, ", i);
                    sprintf(trashz, "%d, ", i);
                    strcat(output, trashz);
                    memset(trashz, 0, strlen(trashz));
                }
                else if (all && !at && byword)
                {
                    // printf("%d, ", word_count(i, hold));
                    sprintf(trashz, "%d, ", word_count(i, hold));
                    strcat(output, trashz);
                    memset(trashz, 0, strlen(trashz));
                }
                else if (!all && byword && at)
                {
                    countt++;
                    if (countt == at)
                        return word_count(i, hold);
                }
                else if (!all && !byword && at)
                {
                    countt++;
                    if (countt == at)
                        return i;
                }
                else
                {
                    sprintf(output, "invalid mode\n");
                    return -1;
                }
            }
        }
    }
    if (!all && count && !at && !byword)
        return countt;
    return -1;
}

int find_line(char *data, int char_num)
{
    int count = 1;
    for (int i = 0; i < char_num; i++)
    {
        if (data[i] == '\n')
            count++;
    }
    return count;
}

int find_char(char *data, int char_num)
{
    int i = 0;
    int j = char_num;
    // 12345lol
    while (1)
    {
        if (data[j - 1] == '\n' || j == 0)
            return i;
        i++;
        j--;
    }
}

void replace(char *file_name, char *pattern, char *alt, int at, int all)
{
    if (at && all)
    {
        sprintf(output, "invalid arguement format\n");
        return;
    }
    FILE *file_ad = fopen(file_name, "r");
    if (!file_ad)
    {
        perror("fopen");
        return;
    }
    fclose(file_ad);
    char *hold = (char *)malloc(sizeof(char) * FILESIZE);
    memset(hold, 0, strlen(hold));
    int length = strlen(pattern), i = 0;

    check_wildcard(pattern);

    parse_text(alt);
    parse_text(pattern);
    put_content_in_string(file_name, hold);

    int i0 = strlen(hold);
    int ans, line, char_num;
    int countt = 0;
    // printf("%c\n",pattern[0]);
    // al va at
    // count ba hame

    for (int i = 0; i < i0; i++)
    {
        ans = check_match(i, hold, pattern, 0, 0);
        if (ans)
        {
            if (!at && !all)
            {
                line = find_line(hold, i);
                char_num = find_char(hold, i);
                // sprintf(output,"%d", char_num);
                rewind(file_ad);
                remove_str(file_name, line, char_num, ans, 'f');
                rewind(file_ad);
                insert_file(alt, line, char_num, file_name);
                return;
            }
            else if (all)
            {
                line = find_line(hold, i);
                char_num = find_char(hold, i);
                rewind(file_ad);
                remove_str(file_name, line, char_num, ans, 'f');
                rewind(file_ad);
                insert_file(alt, line, char_num, file_name);
            }
            else
            {
                countt++;
                if (countt == at)
                {
                    line = find_line(hold, i);
                    char_num = find_char(hold, i);
                    // printf("%d\n%d", char_num, ans);
                    rewind(file_ad);
                    remove_str(file_name, line, char_num, ans, 'f');
                    rewind(file_ad);
                    insert_file(alt, line, char_num, file_name);
                    return;
                }
            }
        }
    }
    if (at && countt < at)
        printf("error: invalid arguement\n");
}

void put_line_in_string(int n, char *store, char *file_name)
{
    FILE *file_ad = fopen(file_name, "r");
    if (!file_ad)
    {
        perror("fopen");
        return;
    }
    fclose(file_ad);
    rewind(file_ad);
    fopen(file_name, "r");
    for (int i = 1; i < n + 1; i++)
    {
        memset(store, 0, strlen(store));
        fgets(store, LINE_LENGTH, file_ad);
    }
    fclose(file_ad);
}

// star ro dorost kone
void grep(char *pattern, int c, int l, int num)
{
    int lol = 1;
    char *file_name = (char *)malloc(sizeof(char) * ARGSIZE);
    char *hold = (char *)malloc(sizeof(char) * FILESIZE);
    char *temp = (char *)malloc(sizeof(char) * LINE_LENGTH);
    int countt = 0;
    for (int i = 0; i < num; i++)
    {
        memset(file_name, 0, strlen(file_name));
        file_name = greps[i];

        memset(hold, 0, strlen(hold));
        int length = strlen(pattern), i = 0;

        check_wildcard(pattern);

        trim_start(pattern);
        parse_text(pattern);

        put_content_in_string(file_name, hold);

        int i0 = strlen(hold);
        int ans, line, char_num;

        for (int i = 0; i < i0; i++)
        {

            ans = check_match(i, hold, pattern, 0, 0);
            if (ans)
            {

                if (!c && !l)
                {
                    line = find_line(hold, i);
                    put_line_in_string(line, temp, file_name);
                    // printf("%s:%s", file_name, temp);
                    sprintf(trashz, "%s:%s", file_name, temp);
                    strcat(output, trashz);
                    memset(trashz, 0, strlen(trashz));
                    char_num = find_char(hold, i);
                    i += (strlen(temp) - char_num);
                    memset(temp, 0, strlen(temp));
                }
                if (c)
                {
                    countt++;
                    line = find_line(hold, i);
                    put_line_in_string(line, temp, file_name);
                    char_num = find_char(hold, i);
                    i += (strlen(temp) - char_num);
                    memset(temp, 0, strlen(temp));
                }
                if (l && lol)
                {
                    // printf("%s\n", file_name);
                    sprintf(trashz, "%s\n", file_name);
                    strcat(output, trashz);
                    memset(trashz, 0, strlen(trashz));
                    lol = 0;
                }
            }
        }
        lol = 1;
    }
    if (c)
    {
        // printf("%d\n", countt);
        sprintf(trashz, "%d/n", countt);
        strcat(output, trashz);
        memset(trashz, 0, strlen(trashz));
    }
    reset_greps();
}

int find_whitespace_size(int char_num, char *temp)
{
    int j = 0;
    int i = char_num - 1;
    while (1)
    {
        if (i < 0 || temp[i] != ' ')
            break;
        i--;
        j++;
    }
    return j;
}

int find_starting_whitespaces(char *temp)
{
    int i = 0;
    while (1)
    {
        if (temp[i] != ' ')
            return i;
        i++;
    }
}

void remove_empty_stuff(char *hold)
{
    char temp[FILESIZE] = {0};
    int i0 = strlen(hold);
    int check = 0;
    int j = 0;
    for (int i = 0; i < i0; i++)
    {
        if (hold[i] != '\n' && hold[i] != ' ')
        {
            check = 1;
            temp[j] = hold[i];
            j++;
        }
        else if (hold[i] == ' ' && check)
        {
            temp[j] = hold[i];
            j++;
        }
        else if (hold[i] == '\n' && check)
        {
            temp[j] = hold[i];
            j++;
            check = 0;
        }
    }
    memset(hold, 0, strlen(hold));
    strcpy(hold, temp);
}

void add_indentation(char *hold)
{
    char temp[FILESIZE] = {0};
    char Stab[5] = "    ";
    int openz = 0, j = 0, check = 0;
    int i0 = strlen(hold);
    int real_shift;

    for (int i = 0; i < i0; i++, j++)
    {
        temp[j] = hold[i];
        if (hold[i] == '{')
            openz++;
        if (hold[i] == '}')
            openz--;
        if (hold[i] == '\n')
        {
            if (closing_line(i + 1, hold))
                real_shift = openz - 1;
            else
                real_shift = openz;
            if (openz > 0)
                for (int i = 0; i < real_shift; i++)
                {
                    insert_str(Stab, j + 1, temp);
                    j += 4;
                }
        }
    }
    memset(hold, 0, i0);
    strcpy(hold, temp);
}

int closing_line(int char_num, char *hold)
{
    int i = 0;
    while (1)
    {
        if (hold[char_num + i] == '}')
            return 1;
        if (hold[char_num + i] == '\n' || hold[char_num + i] == '\0' || hold[char_num + i] == EOF)
            return 0;
        i++;
    }
}

void remove_from_str(int start, int size, char dir, char *hold)
{
    char before[FILESIZE] = {0};
    char after[FILESIZE] = {0};
    char ult_before[FILESIZE] = {0};
    char ult_after[FILESIZE] = {0};
    for (int i = 0; i < start; i++)
    {
        before[i] = hold[i];
    }
    for (int i = start; i < strlen(hold); i++)
    {
        before[i - start] = hold[i];
    }

    if (dir == 'f')
    {
        for (int i = size; i < strlen(after); i++)
        {
            ult_after[i - size] = after[i];
        }
        strcpy(ult_before, before);
    }

    if (dir == 'b')
    {
        int finish = strlen(before);
        for (int i = 0; i < finish - size; i++)
        {
            ult_before[i] = before[i];
        }
        strcpy(ult_after, after);
    }
    // printf("\n%s **\n",ult_before);
    memset(hold, 0, strlen(hold));
    strcat(hold, ult_before);
    strcat(hold, ult_after);
}

void indent(char *file_name)
{
    FILE *file_ad = fopen(file_name, "r");
    if (!file_ad)
    {
        perror("fopen");
        return;
    }
    fclose(file_ad);

    char hold[FILESIZE] = {0};
    put_content_in_string(file_name, hold);

    char Sinter[5] = "\n";
    char Sspace[5] = " ";

    int i = 0;
    while (1)
    {
        if (hold[i] == '\0' || hold[i] == EOF)
            break;
        if (hold[i] == '}')
        {
            insert_str(Sinter, i + 1, hold);
            insert_str(Sinter, i, hold);
            i++;
        }
        if (hold[i] == '{')
        {
            int ff = (hold[i - 1] == ' ');
            insert_str(Sinter, i + 1, hold);
            if (!ff)
                insert_str(Sspace, i, hold);
            if (!ff)
                i++;
        }
        i++;
    }
    remove_empty_stuff(hold);
    add_indentation(hold);
    rewind(file_ad);
    fopen(file_name, "w");
    fputs(hold, file_ad);
    fclose(file_ad);
}

int checklines(char *hold1, char *hold2)
{
    if (strlen(hold1) != strlen(hold2))
        return 0;
    int i0 = strlen(hold2);
    for (int i = 0; i < i0; i++)
    {
        if (hold1[i] != hold2[i])
            return 0;
    }
    return 1;
}

void compare_files(char *file1, char *file2)
{
    char *hold1 = (char *)malloc(sizeof(char) * FILESIZE);
    char *hold2 = (char *)malloc(sizeof(char) * FILESIZE);

    FILE *file_ad1 = fopen(file1, "r");
    if (!file_ad1)
    {
        perror("fopen");
        return;
    }
    FILE *file_ad2 = fopen(file2, "r");
    if (!file_ad2)
    {
        perror("fopen");
        return;
    }
    fclose(file_ad1);
    fclose(file_ad2);
    put_content_in_string(file1, hold1);
    put_content_in_string(file2, hold2);
    rewind(file_ad1);
    rewind(file_ad2);

    int line1 = find_line(hold1, strlen(hold1) - 1);
    int line2 = find_line(hold2, strlen(hold2) - 1);

    int is1less = line1 < line2;
    int limit;
    if (is1less)
        limit = line1;
    else
        limit = line2;

    memset(hold1, 0, strlen(hold1));
    memset(hold2, 0, strlen(hold2));

    for (int i = 1; i < limit + 1; i++)
    {
        rewind(file_ad1);
        rewind(file_ad2);
        put_line_in_string(i, hold1, file1);
        put_line_in_string(i, hold2, file2);

        if (hold2[strlen(hold2) - 1] != '\n')
            strcat(hold2, "\n");
        if (hold1[strlen(hold1) - 1] != '\n')
            strcat(hold1, "\n");
        if (!checklines(hold1, hold2))
        {
            // printf("==================line %d:==================\n%s:%s%s:%s\n", i, file1, hold1, file2, hold2);
            sprintf(trashz, "==================line %d:==================\n%s:%s%s:%s\n", i, file1, hold1, file2, hold2);
            strcat(output, trashz);
            memset(trashz, 0, strlen(trashz));
        }
        memset(hold1, 0, strlen(hold1));
        memset(hold2, 0, strlen(hold2));
    }
    int rest;
    if (is1less)
        rest = line2 - limit;
    else
        rest = line1 - limit;

    // printf("================== #%d to #%d: ==================\n", limit + 1, ((line2 > line1) * (line2) + (line1 > line2) * line1));
    sprintf(trashz, "================== #%d to #%d: ==================\n", limit + 1, ((line2 > line1) * (line2) + (line1 > line2) * line1));
    strcat(output, trashz);
    memset(trashz, 0, strlen(trashz));
    for (int i = limit + 1; i < (line2 > line1) * (line2) + (line1 > line2) * line1 + 1; i++)
    {
        rewind(file_ad1);
        rewind(file_ad2);
        if (is1less)
        {
            put_line_in_string(i, hold2, file2);
            // printf("%s", hold2);
            sprintf(trashz, "%s", hold2);
            memset(hold2, 0, strlen(hold2));
            strcat(output, trashz);
            memset(trashz, 0, strlen(trashz));
        }
        else
        {
            put_line_in_string(i, hold1, file1);
            // printf("%s", hold1);
            sprintf(trashz, "%s", hold1);
            memset(hold1, 0, strlen(hold1));
            strcat(output, trashz);
            memset(trashz, 0, strlen(trashz));
        }
    }
    // printf("\n");
    sprintf(trashz, "\n");
    strcat(output, trashz);
    memset(trashz, 0, strlen(trashz));
}

int is_reg_file(char *fname)
{
    for (int i = 0; i < strlen(fname); i++)
    {
        if (fname[i] == '.')
            return 1;
    }
    return 0;
}

void telltree(char *dir_address, int tree, int tab_count)
{
    char hold_name[ARGSIZE] = {0};
    char print[ARGSIZE] = {0};
    char Stab[5] = "====";
    DIR *directory;
    struct dirent *entry;
    directory = opendir(dir_address);
    if (directory == NULL)
    {
        return;
    }
    while ((entry = readdir(directory)) != NULL)
    {
        if (!(checklines(entry->d_name, ".")) && !(checklines(entry->d_name, "..")))
        {
            // printf out properly if is a file
            if (is_reg_file(entry->d_name))
            {
                for (int i = 0; i < tab_count; i++)
                {
                    strcat(print, Stab);
                }
                strcat(print, dir_address);
                strcat(print, "/");
                strcat(print, entry->d_name);
                // printf("%s\n", print);
                sprintf(trashz, "%s\n", print);
                strcat(output, trashz);
                memset(trashz, 0, strlen(trashz));
                memset(print, 0, strlen(print));
            }
            // prepare to go in the next dir
            else if (tree == 0)
            {
                for (int i = 0; i < tab_count; i++)
                {
                    strcat(print, Stab);
                }
                strcat(print, dir_address);
                strcat(print, "/");
                strcat(print, entry->d_name);

                // printf("%s\n", print);
                sprintf(trashz, "%s\n", print);
                strcat(output, trashz);
                memset(trashz, 0, strlen(trashz));
                memset(print, 0, strlen(print));
            }
            else
            {
                for (int i = 0; i < tab_count; i++)
                {
                    strcat(print, Stab);
                }
                strcat(print, dir_address);
                strcat(print, "/");
                strcat(print, entry->d_name);

                // printf("%s:\n", print);
                sprintf(trashz, "%s\n", print);
                strcat(output, trashz);
                memset(trashz, 0, strlen(trashz));

                strcat(hold_name, dir_address);
                strcat(hold_name, "/");
                strcat(hold_name, entry->d_name);
                telltree(hold_name, tree - 1, tab_count + 1);
                memset(print, 0, strlen(print));
                memset(hold_name, 0, strlen(hold_name));
            }
        }
    }
    closedir(directory);
}

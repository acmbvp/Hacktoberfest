/* Implementation of fifo by Array */
/* Data Structures Using C by UDIT AGARWAL */
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define MAX 50
struct stfifo {
    int buffer[MAX];
    int head;
    int tail;
};

void menu();
void show(struct stfifo *fifo);
int  push(struct stfifo *fifo, int element);
int  pop(struct stfifo *fifo, int *element);
void flush(struct stfifo *fifo);
void clrscr(void);

int main() {
    int             element;
    char            ch;
    struct stfifo *fifo = (struct stfifo *)malloc(sizeof(struct stfifo));

    flush(fifo);
    clrscr();
    menu();
    do {
        printf("Option = ? (5 show menu) ");
        ch = getchar();
        switch (ch) {
            case '1':
                do {
                    printf("Input Element: (-1 to end) ");
                    scanf("%d", &element);
                    if (element != -1) {
                        if (push(fifo, element) == -1) {
                            printf("Buffer is full!\n\n\n");
                        }
                    }
                } while (element != -1);
                break;

            case '2':
                if (pop(fifo, &element) == -1) {
                    printf("Buffer is empty\n\n");
                } else {
                    printf("First element in the fifo = %d\n\n\n", element);
                }
                break;

            case '3':
                show(fifo);
                break;

            case '4':
                flush(fifo);
                break;

            case '5':
                menu();
                break;

            case '6':
                clrscr();
                break;

            case '7':
                break;
        }
    } while (ch != '7');
    return EXIT_SUCCESS;
}

void menu() {

    printf(" ***** MENU **** \n\n");
    printf(" 1 - Push elements\n");
    printf(" 2 - Pop element\n");
    printf(" 3 - Show Stack\n");
    printf(" 4 - Flush fifo\n");
    printf(" 5 - Show menu\n");
    printf(" 6 - Clear Screen\n");
    printf(" 7 - Exit\n\n");
}

void clrscr(void) {
    fprintf(stdout, "\033[2J\033[0;0f");
    fflush(stdout);
}

void flush(struct stfifo *fifo) {
    memset(fifo->buffer, -1, MAX);
    fifo->head = 0;
    fifo->tail = 0;
}

int isFull(struct stfifo *fifo) {
    return ((fifo->head + 1) % MAX) == fifo->tail;
}

void show(struct stfifo *fifo) {
    int i;
    if (fifo->tail != fifo->head) {
        printf("Stack is:\n");
        for (i = fifo->tail; i != fifo->head; i++) {
            printf("%d -> %d\n", i, fifo->buffer[i]);
        }
    } else
        printf ("The fifo is empty\n\n");
}

int push(struct stfifo *fifo, int element) {
    int ret = -1;
    if (!isFull(fifo)) {
        fifo->buffer[fifo->head] = element;

        fifo->head = (fifo->head + 1) % MAX;
        ret         = 0;
    }
    return ret;
}

int pop(struct stfifo *fifo, int *element) {
    int ret = -1;
    if (fifo->tail != fifo->head) {
        *element = fifo->buffer[fifo->tail];

        fifo->tail = (fifo->tail + 1) % MAX;
        ret         = 0;
    }
    return ret;
}

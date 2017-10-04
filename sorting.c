#include<stdio.h>
#include<stdlib.h>
#include<time.h>

void print_list(int * list, int length) {
    
    char intstring[3*(length-1) + 1];
    int i, num;
    
    for (i = 0; i < length; i++) {
        intstring[3*i] = list[i] + 48;  // add 48 to get ascii value
        if (i < length-1) {
            intstring[3*i + 1] = ',';
            intstring[3*i + 2] = ' ';
        }
    }
    
    intstring[3*(length-1) + 1] = '\0';
    printf("%s\n", intstring);
    
}

void swap(int * list, int idx1, int idx2) {
        int temp = list[idx1];
        list[idx1] = list[idx2];
        list[idx2] = temp;
    
}

int * insertion_sort(int * list, int length) {
    
    int i, j, temp;
    
    for (i = 0; i < length; i++) {
        for (j = 0; j < length; j++) {
            if (list[i] < list[j])
                swap(list, i, j);
        }
    }
    
    return list;
}

int * selection_sort(int * list, int length) {
    
    int i, j, temp;
    for (i = 0; i < length; i++) {
        for (j = i+1; j < length; j++) {
            if (list[j] < list[i])
                swap(list, i, j);
        }
    }
    return list;
}

int main(int argc, char * argv[]) {
    
    int i, length;
    int * intlist;

    if (argc < 2) {
        length = 10;
        time_t t;
        intlist = (int*) malloc(length * sizeof(int));
        srand((unsigned) time(&t));
        
        for (i = 0; i < length; i++) {
            intlist[i] = rand() % 10;
        }
    }
    else {
        length = argc - 1;
        intlist = (int*) malloc(length * sizeof(int));
        for (i = 1; i < length + 1; i++) {
            intlist[i-1] = atoi(argv[i]);
        }
    }
    
    print_list(intlist, length);
    print_list(insertion_sort(intlist, length), length);
    print_list(selection_sort(intlist, length), length);

    free(intlist);
    
    return 0;
}

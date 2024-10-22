// part3_struct_book.c
//
// This program was written by T11C,
// on 22/10/2024
//
// This program demonstrates how to use pointers and structs


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct book {
    char title[100];
    char author[100];
    int year;
};

void modify_book(struct book *book_ptr);

int main() {
    struct book book;

    strcpy(book.title, "To Kill a Mockingbird");
    strcpy(book.author, "Harper Lee");
    book.year = 1960;

    printf("Before modification:\n");
    printf("Title: %s, Author: %s, Year: %d\n", book.title, book.author, book.year);

    modify_book(&book);

    printf("After modification:\n");
    printf("Title: %s, Author: %s, Year: %d\n", book.title, book.author, book.year);

    return 0;
}

void modify_book(struct book *book_ptr) {
    strcpy(book_ptr->title, "The Great Gatsby");
    strcpy(book_ptr->author, "F. Scott Fitzgerald");
    book_ptr->year = 1925;
}
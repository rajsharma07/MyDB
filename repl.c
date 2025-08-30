#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
    char *buffer;
    size_t buffer_size;
    size_t input_length;
} InputBuffer;

InputBuffer* create_input_buffer(){
    InputBuffer *inputBuffer = (InputBuffer *) malloc(sizeof(InputBuffer));
    inputBuffer->buffer = NULL;
    inputBuffer->buffer_size = 0;
    inputBuffer->input_length = 0;
    return inputBuffer;
}

void printPrompt(){
    printf("MYDB> ");
}

void read_input(InputBuffer *inputBuffer){
    size_t byte_read = getline(&inputBuffer->buffer, &inputBuffer->buffer_size, stdin);
    if(byte_read <= 0){
        exit(EXIT_FAILURE);
    }
    inputBuffer->buffer[byte_read - 1] = '\0';
    inputBuffer->input_length = byte_read - 1;
}

void close_input_buffer(InputBuffer *inputBuffer){
    free(inputBuffer->buffer);
    free(inputBuffer);
}

int main(){

    InputBuffer *inputBuffer = create_input_buffer();

    while(true){
        printPrompt();
        read_input(inputBuffer);
        if(strcmp(inputBuffer->buffer, ".exit") == 0){
            close_input_buffer(inputBuffer);
            exit(EXIT_SUCCESS);
        }else{
            printf("Invalid command : %s\n", inputBuffer->buffer);
        }
    }
}
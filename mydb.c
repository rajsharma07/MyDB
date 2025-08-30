#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
    char *buffer;
    size_t buffer_size;
    size_t input_length;
} InputBuffer;

typedef enum{
    STATEMENT_INSERT,
    STATEMENT_UNRECOGNIZED
} StatementType;

typedef struct{
    StatementType type;
} Statement;

typedef enum{
    META_COMMAND_SUCCESS,
    META_COMMAND_UNRECOGNIZED
} MetaCommandResult;

typedef enum{
    PREPARE_SUCCESS,
    PREPARE_UNRECOGNIZED_STATEMENT
} PrepareResult;

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

MetaCommandResult do_meta_command(InputBuffer *inputBuffer){
    if(strcmp(inputBuffer->buffer, ".exit") == 0){
        exit(EXIT_SUCCESS);
    }
    else{
        return META_COMMAND_UNRECOGNIZED;
    }
}

PrepareResult prepare_statement(InputBuffer* inputBuffer, Statement* statement){
    if(strncmp(inputBuffer->buffer, "insert", 6) == 0){
        statement->type = STATEMENT_INSERT;
        return PREPARE_SUCCESS;
    }
    return PREPARE_UNRECOGNIZED_STATEMENT;
}

void execute_statement(Statement* statement){
    switch (statement->type)
    {
    case STATEMENT_INSERT:
        printf("Executing insert statement\n");
        break;
    
    default:
        break;
    }
}

int main(){

    InputBuffer *inputBuffer = create_input_buffer();

    while(true){
        printPrompt();
        read_input(inputBuffer);
        if(inputBuffer->buffer[0] == '.'){
            switch (do_meta_command(inputBuffer))
            {
            case META_COMMAND_SUCCESS:
                continue;
            case META_COMMAND_UNRECOGNIZED:
                printf("Unrecognized command: %s\n", inputBuffer->buffer);
                continue;
            }
        }else{
            Statement statement;
            switch (prepare_statement(inputBuffer, &statement))
            {
            case PREPARE_SUCCESS:
                /* code */
                break;
            case PREPARE_UNRECOGNIZED_STATEMENT:
                printf("Unrecognized statement: %s\n", inputBuffer->buffer);
                continue;
            }
            execute_statement(&statement);
            
        }
    }
}
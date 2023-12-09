#include<assert.h>
#include<stdio.h>
#include<stdlib.h>

typedef enum {
    INST_PUSH,
    INST_ADD,
    INST_PRINT,
    INST_END,
} Inst_type;

typedef struct {
    Inst_type type;
    int operand;
} Inst;

#define STACK_CAPACITY 1024
int stack[STACK_CAPACITY];
size_t stack_size = 0;

void stack_push(int value){
    assert(stack_size < STACK_CAPACITY);
    stack[stack_size++] = value;
}

int stack_pop(void){
    assert(stack_size > 0);
    return stack[--stack_size];
}

void execute_instruction(Inst instruction) {
    switch(instruction.type){
        case INST_PUSH:
            stack_push(instruction.operand);
            break;
        case INST_ADD: {
            int a = stack_pop();
            int b = stack_pop();
            stack_push(a + b);
        } break;
        case INST_PRINT:
            printf("%d\n", stack_pop());
            break;
        case INST_END:
            exit(0);
        default:
            assert(0 && "Invalid instruction");
    }
}

int main(){
    printf("=== [STACK BASED VIRTUAL MACHINE IN C] ===\n");

    Inst instruction;
    int choice;

    do {
        printf("+ Operations +\n");
        printf("  [1]: Push \n");
        printf("  [2]: Add \n");
        printf("  [3]: Print \n");
        printf("  [0]: End \n");

        printf("Choose operation: ");
        scanf("%d", &choice);

        if (choice == 1) {
            instruction.type = INST_PUSH;
            printf("Operand: ");
            scanf("%d", &instruction.operand);
        } else if (choice == 2) {
            instruction.type = INST_ADD;
        } else if (choice == 3) {
            instruction.type = INST_PRINT;
        } else if (choice == 0) {
            instruction.type = INST_END;
        } else {
            printf("Invalid operation. Please choose a valid operation.\n");
            continue;
        }

        execute_instruction(instruction);
    } while (1);

    return 0;
}
